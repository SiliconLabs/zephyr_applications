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
#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/byteorder.h>
#include "led.h"
#include "button.h"

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>

LOG_MODULE_REGISTER(app, 3);

#define DEVICE_NAME           "Blinky Example"
#define DEVICE_NAME_LEN       (sizeof(DEVICE_NAME) - 1)

// -----------------------------------------------------------------------------
//                       Local Variables
// -----------------------------------------------------------------------------

static const struct gpio_dt_spec btn = GPIO_DT_SPEC_GET(DT_ALIAS(sw0), gpios);
static uint8_t btn_state;

static uint8_t led_state = 0;

/* Adevertisement data */
static const struct bt_data ad[] = {
  BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
  BT_DATA(BT_DATA_NAME_COMPLETE, DEVICE_NAME, DEVICE_NAME_LEN)
};

/* BLE connection */
static struct bt_conn *ble_conn;

/* Notification state */
static volatile bool notify_enable;

/* Blinky Example Service  */
static struct bt_uuid_128 blinky_example_service_uuid = BT_UUID_INIT_128(
  BT_UUID_128_ENCODE(0xde8a5aac, 0xa99b, 0xc315, 0x0c80, 0x60d4cbb51224));

/* LED Control characteristic */
static struct bt_uuid_128 led_char_uuid = BT_UUID_INIT_128(
  BT_UUID_128_ENCODE(0x5b026510, 0x4088, 0xc297, 0x46d8, 0xbe6c736a087a));

/* Report Button characteristic */
static struct bt_uuid_128 button_char_uuid = BT_UUID_INIT_128(
  BT_UUID_128_ENCODE(0x61a885a4, 0x41c3, 0x60d0, 0x9a53, 0x6d652a70d29c));

// -----------------------------------------------------------------------------
//                       Local Function
// -----------------------------------------------------------------------------
static void bt_ready(int err);
static void connected(struct bt_conn *connected, uint8_t err);
static void disconnected(struct bt_conn *disconn, uint8_t reason);
static void notification_status_handle(const struct bt_gatt_attr *attr,
                                       uint16_t value);
static ssize_t app_ble_write_cb(struct bt_conn *conn,
                                const struct bt_gatt_attr *attr,
                                const void *buf, uint16_t len,
                                uint16_t offset, uint8_t flags);
static ssize_t app_ble_read_cb(struct bt_conn *conn,
                               const struct bt_gatt_attr *attr,
                               void *buf, uint16_t len,
                               uint16_t offset);
static void button_callback(const struct device *gpiob,
                            struct gpio_callback *cb,
                            uint32_t pins);

// -----------------------------------------------------------------------------
//                       Marcos
// -----------------------------------------------------------------------------

BT_GATT_SERVICE_DEFINE(blinky_example_svc,
                       BT_GATT_PRIMARY_SERVICE(&blinky_example_service_uuid),
                       BT_GATT_CHARACTERISTIC(&led_char_uuid.uuid,
                                              BT_GATT_CHRC_READ
                                              | BT_GATT_CHRC_WRITE_WITHOUT_RESP,
                                              BT_GATT_PERM_WRITE
                                              | BT_GATT_PERM_READ,
                                              app_ble_read_cb, app_ble_write_cb,
                                              (void *)1),
                       BT_GATT_CHARACTERISTIC(&button_char_uuid.uuid,
                                              BT_GATT_CHRC_READ
                                              | BT_GATT_CHRC_NOTIFY,
                                              BT_GATT_PERM_READ,
                                              app_ble_read_cb, NULL, (void *)1),
                       BT_GATT_CCC(notification_status_handle,
                                   BT_GATT_PERM_READ | BT_GATT_PERM_WRITE), );

BT_CONN_CB_DEFINE(conn_callbacks) = {
  .connected = connected,
  .disconnected = disconnected,
};

/***************************************************************************//**
 * Application initialization function.
 ******************************************************************************/
void app_init(void)
{
  int err;

  err = button_init(button_callback, btn);
  if (err) {
    LOG_ERR("Button init failed (err %d)", err);
  }

  err = led_init();
  if (err) {
    LOG_ERR("LED init failed (err %d)", err);
  }

  /* Initialize the Bluetooth Subsystem */
  err = bt_enable(bt_ready);
  if (err) {
    LOG_ERR("Bluetooth init failed (err %d)", err);
  }
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  int err;

  btn_state = (uint8_t)gpio_pin_get(btn.port, btn.pin);
  if (ble_conn) {
    if (notify_enable) {
      err = bt_gatt_notify(NULL, &blinky_example_svc.attrs[4],
                           &btn_state, sizeof(btn_state));
      if (err) {
        LOG_ERR("Notify error: %d", err);
      }
    }
  }
  k_sleep(K_MSEC(50));
}

// -----------------------------------------------------------------------------
//                       Local Function Definition
// -----------------------------------------------------------------------------

/**************************************************************************//**
*  BLE initialization callback.
******************************************************************************/
static void bt_ready(int err)
{
  if (err) {
    LOG_ERR("Bluetooth init failed (err %d)", err);
    return;
  }
  LOG_INF("Bluetooth initialized");

  /* Start advertising */
  err = bt_le_adv_start(BT_LE_ADV_CONN, ad, ARRAY_SIZE(ad), NULL, 0);
  if (err) {
    LOG_ERR("Advertising failed to start (err %d)", err);
    return;
  }

  LOG_INF("Configuration mode: waiting connections...");
}

/**************************************************************************//**
*  BLE connected callback.
******************************************************************************/
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

/**************************************************************************//**
*  BLE disconnected callback.
******************************************************************************/
static void disconnected(struct bt_conn *disconn, uint8_t reason)
{
  if (ble_conn) {
    bt_conn_unref(ble_conn);
    ble_conn = NULL;
  }

  LOG_INF("Disconnected (reason %u)", reason);
}

/**************************************************************************//**
*  BLE notification status change handler.
******************************************************************************/
static void notification_status_handle(const struct bt_gatt_attr *attr,
                                       uint16_t value)
{
  ARG_UNUSED(attr);
  notify_enable = (value == BT_GATT_CCC_NOTIFY);
  LOG_INF("Notification %s", notify_enable ? "enabled" : "disabled");
}

/**************************************************************************//**
*  LED characteristic write callback.
******************************************************************************/
static ssize_t app_ble_write_cb(struct bt_conn *conn,
                                const struct bt_gatt_attr *attr,
                                const void *buf,
                                uint16_t len,
                                uint16_t offset,
                                uint8_t flags)
{
  if (attr == &blinky_example_svc.attrs[2]) {
    led_state = *(uint8_t *)buf;
    led_control(led_state);
  }

  return 0;
}

/**************************************************************************//**
*  LED characteristic read callback.
******************************************************************************/
static ssize_t app_ble_read_cb(struct bt_conn *conn,
                               const struct bt_gatt_attr *attr,
                               void *buf, uint16_t len,
                               uint16_t offset)
{
  if (attr == &blinky_example_svc.attrs[2]) {
    return bt_gatt_attr_read(conn, attr, buf, len, offset, &led_state,
                             sizeof(led_state));
  } else if (attr == &blinky_example_svc.attrs[4]) {
    return bt_gatt_attr_read(conn, attr, buf, len, offset, &btn_state,
                             sizeof(btn_state));
  }
  return 0;
}

/**************************************************************************//**
*  Button callback.
******************************************************************************/
static void button_callback(const struct device *gpiob,
                            struct gpio_callback *cb,
                            uint32_t pins)
{
}
