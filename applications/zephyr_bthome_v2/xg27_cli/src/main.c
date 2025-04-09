/***************************************************************************//**
 * @file app.c
 * @brief zephyr application source file.
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
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
#include <stdlib.h>
#include <string.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/logging/log.h>
#include "zephyr/shell/shell.h"
#include <zephyr/drivers/sensor.h>
#include <mbedtls/ccm.h>
#include "bthome_v2.h"

LOG_MODULE_REGISTER(app);

// ******************************************************************************
//                          Macros
// ******************************************************************************
#define CONVERT_SENSOR_VALUE(val1,          \
                             val2) (((val1) \
                                     + ((double)(val2) / (1000000))))

#define READ_TEMPERATURE                0x00
#define READ_HUMIDITY                   0x01
#define READ_ILLU                       0x02
#define READ_ROTATION                   0x03
#define READ_ACCELERATION               0x04
#define READ_DEFAULT                    0x05

#define BROADCAST_INTERVAL_MS_DEFAULT   1000
#define DEVICE_NAME_MAX_LENGTH          8

// ******************************************************************************
//                          Static Variables Declarations
// ******************************************************************************
static uint8_t device_name[8] = "ZPBTxG27";
static uint8_t key[] = "12345678123456781234567812345678";
static bool broadcast_enabled;
static uint16_t broadcast_interval = BROADCAST_INTERVAL_MS_DEFAULT;
static uint8_t device_name_len;

static volatile bool should_update;
static volatile uint8_t sensor_read = READ_TEMPERATURE;
static struct k_timer broadcast_timer;

static const struct device *const  si7021_sensor = DEVICE_DT_GET_ANY(
  silabs_si7006);
static const struct device *const  si7210_sensor = DEVICE_DT_GET_ANY(
  silabs_si7210);
static const struct device *const  veml6035_sensor = DEVICE_DT_GET_ANY(
  vishay_veml7700);
static const struct device *const  icm20689_sensor = DEVICE_DT_GET_ANY(
  invensense_icm20689);

// ******************************************************************************
//                          Static Function Prototypes
// ******************************************************************************
static void app_get_sensor_data(void);
static void app_init(void);

/***************************************************************************//**
 *  Shell set device name.
 ******************************************************************************/
void cli_set_device_name(const struct shell *sh,
                         size_t argc,
                         char **argv)
{
  ARG_UNUSED(argc);

  memset(device_name, 0, sizeof(device_name));
  device_name_len =
    (strlen(argv[1])
     > DEVICE_NAME_MAX_LENGTH) ? DEVICE_NAME_MAX_LENGTH : strlen(
      argv[1]);
  memcpy(device_name, argv[1], device_name_len);
  bthome_v2_set_device_name(device_name, device_name_len);

  shell_print(sh, "Set the device name key successfully.");
}

/***************************************************************************//**
 *  Shell enable / disable broadcast.
 ******************************************************************************/
void cli_set_boardcast(const struct shell *sh,
                       size_t argc,
                       char **argv)
{
  ARG_UNUSED(argc);

  broadcast_enabled = atoi(argv[1]);

  shell_print(sh, "Boardcast : %s",
              (broadcast_enabled) ? "ENABLED" : "DISABLED");

  if (broadcast_enabled) {
    k_timer_start(&broadcast_timer, K_MSEC(broadcast_interval),
                  K_MSEC(broadcast_interval));
    should_update = true;
  } else {
    k_timer_stop(&broadcast_timer);
  }
}

/***************************************************************************//**
 *  Shell set encryption key.
 ******************************************************************************/
void cli_set_encryption_key(const struct shell *sh,
                            size_t argc,
                            char **argv)
{
  ARG_UNUSED(argc);
  int ret;

  ret = bthome_v2_set_key((uint8_t *)argv[1]);
  if (ret) {
    LOG_ERR("Faild to set the encrytion key. [ERROR]: %d", ret);
  }
  shell_print(sh, "Set the encryption key successfully.");
}

/***************************************************************************//**
 *  Shell set broadcast invertal .
 ******************************************************************************/
void cli_set_boardcast_interval_ms(const struct shell *sh,
                                   size_t argc,
                                   char **argv)
{
  ARG_UNUSED(argc);

  broadcast_interval = atoi(argv[1]);
  k_timer_start(&broadcast_timer, K_MSEC(broadcast_interval),
                K_MSEC(broadcast_interval));

  shell_print(sh, "Boardcast interval [ms]: %d\n", broadcast_interval);
}

// ******************************************************************************
//                          Static Function Declarations
// ******************************************************************************

/***************************************************************************//**
 *  Application broadcast timer handle.
 ******************************************************************************/
static void app_broadcast_timer_handle(struct k_timer *timer_id)
{
  ARG_UNUSED(timer_id);

  switch (sensor_read) {
    case READ_TEMPERATURE:
      sensor_read = READ_HUMIDITY;
      break;
    case READ_HUMIDITY:
      sensor_read = READ_ILLU;
      break;
    case READ_ILLU:
      sensor_read = READ_ROTATION;
      break;
    case READ_ROTATION:
      sensor_read = READ_ACCELERATION;
      break;
    case READ_ACCELERATION:
      sensor_read = READ_TEMPERATURE;
      break;
    default:
      break;
  }
  should_update = true;
}

/***************************************************************************//**
 *  Application read sensor data.
 ******************************************************************************/
static void app_get_sensor_data(void)
{
  struct sensor_value sensor_val, icm_val[3];

  if (should_update && broadcast_enabled) {
    switch (sensor_read) {
      case READ_TEMPERATURE:
        sensor_sample_fetch(si7021_sensor);
        sensor_channel_get(si7021_sensor, SENSOR_CHAN_AMBIENT_TEMP,
                           &sensor_val);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_VALUE(
                                                sensor_val.val1,
                                                sensor_val.val2),
                                              TEMPERTAURE_OBJ_ID,
                                              broadcast_enabled);
        LOG_INF("[Si7021]: Temperature: %.2lf °C",
                CONVERT_SENSOR_VALUE(sensor_val.val1, sensor_val.val2));
        break;
      case READ_HUMIDITY:
        sensor_channel_get(si7021_sensor, SENSOR_CHAN_HUMIDITY, &sensor_val);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_VALUE(
                                                sensor_val.val1,
                                                sensor_val.val2),
                                              HUMIDITY_OBJ_ID,
                                              broadcast_enabled);
        LOG_INF("[Si7021]: Relative humidity: %.2lf %%",
                CONVERT_SENSOR_VALUE(sensor_val.val1, sensor_val.val2));
        break;
      case READ_ILLU:
        sensor_sample_fetch(veml6035_sensor);
        sensor_channel_get(veml6035_sensor, SENSOR_CHAN_LIGHT, &sensor_val);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_VALUE(
                                                sensor_val.val1,
                                                sensor_val.val2),
                                              ILLUM_OBJ_ID,
                                              broadcast_enabled);
        LOG_INF("[VEML6035]: Ambient Light: %.2lf lux",
                CONVERT_SENSOR_VALUE(sensor_val.val1, sensor_val.val2));
        break;
      case READ_ROTATION:
        sensor_sample_fetch_chan(icm20689_sensor, SENSOR_CHAN_GYRO_XYZ);
        sensor_channel_get(icm20689_sensor, SENSOR_CHAN_GYRO_XYZ, icm_val);

        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_VALUE(
                                                icm_val[0].val1,
                                                icm_val[0].val2),
                                              ROTATION_OBJ_ID,
                                              broadcast_enabled);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_VALUE(
                                                icm_val[1].val1,
                                                icm_val[1].val2),
                                              ROTATION_OBJ_ID,
                                              broadcast_enabled);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_VALUE(
                                                icm_val[2].val1,
                                                icm_val[2].val2),
                                              ROTATION_OBJ_ID,
                                              broadcast_enabled);
        LOG_INF("[ICM20689]: Orientation : X: %.2lf °   Y: %.2lf °   Z: %.2lf°",
                CONVERT_SENSOR_VALUE(icm_val[0].val1, icm_val[0].val2),
                CONVERT_SENSOR_VALUE(icm_val[1].val1, icm_val[1].val2),
                CONVERT_SENSOR_VALUE(icm_val[2].val1, icm_val[2].val2));
        break;
      case READ_ACCELERATION: {
        sensor_sample_fetch_chan(icm20689_sensor, SENSOR_CHAN_ACCEL_XYZ);
        sensor_channel_get(icm20689_sensor, SENSOR_CHAN_ACCEL_XYZ, icm_val);

        double accel_x = CONVERT_SENSOR_VALUE(icm_val[0].val1, icm_val[0].val2);
        bthome_v2_add_measurement_float_value((accel_x > 0) ? accel_x : 0,
                                              ACCELERATION_OBJ_ID,
                                              broadcast_enabled);
        double accel_y = CONVERT_SENSOR_VALUE(icm_val[1].val1, icm_val[1].val2);
        bthome_v2_add_measurement_float_value((accel_y > 0) ? accel_y : 0,
                                              ACCELERATION_OBJ_ID,
                                              broadcast_enabled);
        double accel_z = CONVERT_SENSOR_VALUE(icm_val[2].val1, icm_val[2].val2);
        bthome_v2_add_measurement_float_value((accel_z > 0) ? accel_z : 0,
                                              ACCELERATION_OBJ_ID,
                                              broadcast_enabled);
        LOG_INF(
          "[ICM20689]: Acceleration : X: %.2lf m/s2   Y: %.2lf m/s2    Z: %.2lf m/s2",
          (accel_x > 0) ? accel_x : 0,
          (accel_y > 0) ? accel_y : 0,
          (accel_z > 0) ? accel_z : 0);
      }
      break;
      default:
        break;
    }
    should_update = false;
  }
}

/***************************************************************************//**
 *  Application initialization.
 ******************************************************************************/
static void app_init(void)
{
  if ((si7021_sensor == NULL) || (si7210_sensor == NULL)
      || (veml6035_sensor == NULL) || (icm20689_sensor == NULL)) {
    LOG_ERR("Device not found!");
    return;
  }

  if (!device_is_ready(si7021_sensor) || !device_is_ready(si7210_sensor)
      || !device_is_ready(veml6035_sensor)
      || !device_is_ready(icm20689_sensor)) {
    LOG_ERR("Devices are not ready!");
    return;
  }

  LOG_INF("Application initialization done.\n");
}

/***************************************************************************//**
 *  Main function.
 ******************************************************************************/
int main(void)
{
  int ret;

  app_init();
  ret = bt_enable(NULL);
  if (ret) {
    LOG_INF("Bluetooth init failed. ERR: %d", ret);
    return 0;
  }

  bthome_v2_set_key(key);
  bthome_v2_set_device_name(device_name, sizeof(device_name));

  k_timer_init(&broadcast_timer, app_broadcast_timer_handle, NULL);

  while (1) {
    app_get_sensor_data();
    k_sleep(K_MSEC(1));
  }
  return 0;
}
