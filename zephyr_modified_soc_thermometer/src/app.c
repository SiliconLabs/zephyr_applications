/***************************************************************************//**
 * @file app.c
 * @brief zephyr application source file.
 *******************************************************************************
 * # License
 * <b>Copyright 2022 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided \'as-is\', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 *******************************************************************************
 * # EXPERIMENTAL QUALITY
 * This code has not been formally tested and is provided as-is. It is not
 * suitable for production environments. In addition, this code will not be
 * maintained and there may be no bug maintenance planned for these resources.
 * Silicon Labs may update projects from time to time.
 ******************************************************************************/
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gatt.h>
#include "app.h"
#include "health_thermo_service.h"
#include "health_thermo_service_config.h"

LOG_MODULE_REGISTER(app, 3);

/***************************************************************************//**
 * Definition.
 ******************************************************************************/
#define BUTTON0         DT_ALIAS(sw0)
#define DEVICE_NAME     "Zephyr SoC Thermometer"
#define DEVICE_NAME_LEN (sizeof(DEVICE_NAME) - 1)

/***************************************************************************//**
 * Static variable declaration.
 ******************************************************************************/
static bool app_btn0_press = false;
static struct gpio_callback btn0_callback;
static double current_temperature = 0;
static struct k_timer app_indicate_timer;
static const struct gpio_dt_spec btn0 = GPIO_DT_SPEC_GET(BUTTON0, gpios);
static const struct device *const dev = DEVICE_DT_GET_ANY(silabs_si7210);
// /* BLE connection */
struct bt_conn *ble_conn = NULL;
static const struct bt_data ad[] = {
  BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
  BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),
};

/***************************************************************************//**
 * Static application function declaration.
 ******************************************************************************/
static int button0_init();
static void bt_ready(int err);
static void connected(struct bt_conn *connected, uint8_t err);
static void disconnected(struct bt_conn *disconn, uint8_t reason);
static void btn0_callback_handler(const struct device *port,
                                  struct gpio_callback *cb,
                                  gpio_port_pins_t pins);
static void app_indicate_timer_handler(struct k_timer *timer_id);

BT_CONN_CB_DEFINE(conn_callbacks) = {
  .connected = connected,
  .disconnected = disconnected,
};

/***************************************************************************//**
 * Static Application function definition.
 ******************************************************************************/
static int button0_init()
{
  int ret = 0;

  if (!gpio_is_ready_dt(&btn0)) {
    LOG_ERR("Button 0 is not ready. ");
    return ret;
  }

  ret = gpio_pin_configure_dt(&btn0, GPIO_INPUT);
  if (ret != 0) {
    LOG_ERR("Error %d: can't configure button on GPIO %s pin %d",
            ret, btn0.port->name, btn0.pin);
    return ret;
  }

  gpio_init_callback(&btn0_callback, btn0_callback_handler, BIT(btn0.pin));
  gpio_add_callback(btn0.port, &btn0_callback);
  ret = gpio_pin_interrupt_configure_dt(&btn0, GPIO_INT_EDGE_BOTH);
  if (ret != 0) {
    LOG_ERR("Error %d: can't configure button to interrupt on %s pin %d",
            ret, btn0.port->name, btn0.pin);
    return ret;
  }
  return 0;
}

static void btn0_callback_handler(const struct device *port,
                                  struct gpio_callback *cb,
                                  gpio_port_pins_t pins)
{
  app_btn0_press = (bool)gpio_pin_get_dt(&btn0) ? true : false;
  printk("button state: %d", app_btn0_press);
}

static void app_indicate_timer_handler(struct k_timer *timer_id)
{
  health_thermometer_indicate_temp(ble_conn, current_temperature, false);
}

void temperature_measurement_ccc_changed(const struct bt_gatt_attr *attr,
                                         uint16_t value)
{
  printk("Temperature measurement indication changed\n");
  if (value == BT_GATT_CCC_INDICATE) {
    // Start timer used for periodic indications.
    k_timer_start(&app_indicate_timer,
                  K_MSEC(1000),
                  K_MSEC(SL_BT_HT_MEASUREMENT_INTERVAL_SEC));
  } else {
    k_timer_stop(&app_indicate_timer);
  }
}

void temperature_measurement_indicate_cb(struct bt_conn *conn,
                                         struct bt_gatt_indicate_params *params,
                                         uint8_t err)
{
  LOG_INF("Indication %s, Temperature value: %g C\n",
          err != 0U ? "fail" : "success",
          current_temperature);
}

/***************************************************************************//**
 * BLE Connection - Related funtions.
 ******************************************************************************/
static void bt_ready(int err)
{
  if (err) {
    LOG_ERR("bluetooth Initialization failed: %d.\n", err);
    return;
  }

  LOG_INF("Bluetooth initialized");

  /* Start advertising */
  err = bt_le_adv_start(BT_LE_ADV_CONN_NAME, ad, ARRAY_SIZE(ad), NULL, 0);
  if (err) {
    LOG_ERR("Advertising failed to start (err %d)", err);
    return;
  }

  LOG_INF("Configuration mode: waiting connections...");
}

static void connected(struct bt_conn *connected, uint8_t err)
{
  if (err) {
    LOG_ERR("Connection failed (err %u)", err);
  } else {
    LOG_INF("Connected");
    if (!ble_conn) {
      ble_conn = bt_conn_ref(connected);
    }
  }
}

static void disconnected(struct bt_conn *disconn, uint8_t reason)
{
  if (ble_conn) {
    bt_conn_unref(ble_conn);
    ble_conn = NULL;
  }

  LOG_INF("Disconnected (reason %u)", reason);
}

/***************************************************************************//**
 * Application initialization function.
 ******************************************************************************/
void app_init(void)
{
  int ret = 0;

  LOG_INF("Zephyr Application - Bluetooth SoC Thermometer.\n");

  if (dev == NULL) {
    /* No such node, or the node does not have status "okay". */
    LOG_ERR("Object sensor is Null.");
    return;
  }

  ret = button0_init();
  if (ret) {
    LOG_ERR("Button0 Initialization failed: %d.\n", ret);
    return;
  }

  if (!device_is_ready(dev)) {
    LOG_ERR("Sensor device \"%s\" is not ready; "
            "check the driver initialization logs for errors.",
            dev->name);
    return;
  }

  /* Initialize the Bluetooth Subsystem */
  ret = bt_enable(bt_ready);
  if (ret) {
    LOG_ERR("bluetooth Initialization failed: %d.\n", ret);
    return;
  }

  // Initialize the periodic indicate timer
  k_timer_init(&app_indicate_timer, app_indicate_timer_handler, NULL);

  // Initialized the health thermometer service
  health_thermometer_init();

  LOG_INF("Application initialization is done.\n");
  LOG_INF("Waiting for connection...\n");
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  struct sensor_value sensor_value;

  sensor_sample_fetch(dev);
  sensor_channel_get(dev, SENSOR_CHAN_AMBIENT_TEMP, &sensor_value);

  if (app_btn0_press) {
    // if button pressed, overwrite temperature with -20 C
    current_temperature = -20;
  } else {
    current_temperature = sensor_value_to_double(&sensor_value);
  }

  k_sleep(K_MSEC(500));
}
