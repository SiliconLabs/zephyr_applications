/***************************************************************************//**
 * @file thermometer.c
 * @brief thermometer source file.
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
#include <zephyr/sys/byteorder.h>
#include <zephyr/bluetooth/gatt.h>
#include "health_thermo_service.h"
#include "health_thermo_service_config.h"

/**************************************************************************//**
 * static variable declaration
 *****************************************************************************/
static int measurement_interval = 1;
static int temperature_type = SL_BT_HT_TEMPERATURE_TYPE_BODY;
static struct bt_gatt_indicate_params indicate_params;

/**************************************************************************//**
 * static function definition.
 *****************************************************************************/
// parse temperature into buffer to send
static void temperature_measurement_val_to_buf(double value,
                                               bool fahrenheit,
                                               uint8_t *buffer);

// characteristic properties callback
static ssize_t measure_interval_read_cb(struct bt_conn *conn,
                                        const struct bt_gatt_attr *attr,
                                        void *buf, uint16_t len,
                                        uint16_t offset);
static ssize_t temperture_type_read_cb(struct bt_conn *conn,
                                       const struct bt_gatt_attr *attr,
                                       void *buf, uint16_t len,
                                       uint16_t offset);

/**************************************************************************//**
 * Health Thermometer Service Declaration
 *****************************************************************************/
BT_GATT_SERVICE_DEFINE(hts_svc,
                       BT_GATT_PRIMARY_SERVICE(BT_UUID_HTS),
                       BT_GATT_CHARACTERISTIC(BT_UUID_HTS_MEASUREMENT,
                                              BT_GATT_CHRC_INDICATE,
                                              BT_GATT_PERM_NONE,
                                              NULL,
                                              NULL,
                                              NULL),
                       BT_GATT_CCC(temperature_measurement_ccc_changed,
                                   BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
                       BT_GATT_CHARACTERISTIC(BT_UUID_HTS_TEMP_TYP,
                                              BT_GATT_CHRC_READ,
                                              BT_GATT_PERM_READ,
                                              temperture_type_read_cb,
                                              NULL,
                                              &temperature_type),
                       BT_GATT_CHARACTERISTIC(BT_UUID_HTS_TEMP_INT,
                                              BT_GATT_CHRC_NOTIFY,
                                              BT_GATT_PERM_NONE,
                                              NULL,
                                              NULL,
                                              NULL),
                       BT_GATT_CCC(intermediate_temperature_ccc_changed,
                                   BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
                       BT_GATT_CHARACTERISTIC(BT_UUID_HTS_INTERVAL,
                                              BT_GATT_CHRC_READ,
                                              BT_GATT_PERM_READ,
                                              measure_interval_read_cb,
                                              NULL,
                                              &measurement_interval),
                       BT_GATT_CCC(measurement_interval_ccc_changed,
                                   BT_GATT_PERM_READ | BT_GATT_PERM_WRITE)
                       );

/**************************************************************************//**
 * Health thermometer indicate temperature function.
 *****************************************************************************/
void health_thermometer_indicate_temp(struct bt_conn *connection,
                                      double temperature,
                                      bool fahrenheit)
{
  static uint8_t htm[5];

  if (connection != NULL) {
    temperature_measurement_val_to_buf(temperature, fahrenheit, htm);
    indicate_params.attr = &hts_svc.attrs[2];
    indicate_params.destroy = temperature_measurement_indicate_destroy;
    indicate_params.func = temperature_measurement_indicate_cb;
    indicate_params.data = &htm;
    indicate_params.len = sizeof(htm);
    bt_gatt_indicate(connection, &indicate_params);
  }
}

void health_thermometer_init()
{
  temperature_type = SL_BT_HT_TEMPERATURE_TYPE_BODY;
  measurement_interval = SL_BT_HT_MEASUREMENT_INTERVAL_SEC / 1000;
}

/**************************************************************************//**
 * Private function definitions
 *****************************************************************************/
static void temperature_measurement_val_to_buf(double value,
                                               bool fahrenheit,
                                               uint8_t *buffer)
{
  static uint32_t mantissa;
  static uint8_t exponent;

  mantissa = (uint32_t)(value * 100);
  exponent = (uint8_t)-2;

  buffer[0] = fahrenheit ? 1 : 0; /* temperature in celsius */
  sys_put_le24(mantissa, (uint8_t *)&buffer[1]);
  buffer[4] = exponent;
}

/**************************************************************************//**
*  measurement interval characteristic read callback.
******************************************************************************/
static ssize_t measure_interval_read_cb(struct bt_conn *conn,
                                        const struct bt_gatt_attr *attr,
                                        void *buf, uint16_t len,
                                        uint16_t offset)
{
  return bt_gatt_attr_read(conn, attr, buf, len, offset, attr->user_data,
                           sizeof(measurement_interval));
}

/**************************************************************************//**
*  measurement interval characteristic read callback.
******************************************************************************/
static ssize_t temperture_type_read_cb(struct bt_conn *conn,
                                       const struct bt_gatt_attr *attr,
                                       void *buf, uint16_t len,
                                       uint16_t offset)
{
  return bt_gatt_attr_read(conn, attr, buf, len, offset, attr->user_data,
                           sizeof(temperature_type));
}

__weak void temperature_measurement_ccc_changed(const struct bt_gatt_attr *attr,
                                                uint16_t value)
{
  (void) attr;
  (void) value;
}

__weak void intermediate_temperature_ccc_changed(
  const struct bt_gatt_attr *attr,
  uint16_t value)
{
  (void) attr;
  (void) value;
}

__weak void measurement_interval_ccc_changed(const struct bt_gatt_attr *attr,
                                             uint16_t value)
{
  (void) attr;
  (void) value;
}

__weak void temperature_measurement_indicate_cb(struct bt_conn *conn,
                                                struct bt_gatt_indicate_params *params,
                                                uint8_t err)
{
  (void) conn;
  (void) params;
  (void) err;
}

__weak void temperature_measurement_indicate_destroy(
  struct bt_gatt_indicate_params *params)
{
  (void) params;
}
