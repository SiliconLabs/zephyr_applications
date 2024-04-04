/***************************************************************************//**
 * @file thermometer.h
 * @brief thermometer header file.
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

#ifndef _HEALTH_THERMOMETER_H_
#define _HEALTH_THERMOMETER_H_
/// Possible values of the Temperature Type characteristic (UUID: 2A1D)
enum sl_bt_ht_temperature_type {
  SL_BT_HT_TEMPERATURE_TYPE_ARMPIT = 0,
  SL_BT_HT_TEMPERATURE_TYPE_BODY,
  SL_BT_HT_TEMPERATURE_TYPE_EAR,
  SL_BT_HT_TEMPERATURE_TYPE_FINGER,
  SL_BT_HT_TEMPERATURE_TYPE_GASTRO_INTESTINAL_TRACT,
  SL_BT_HT_TEMPERATURE_TYPE_MOUTH,
  SL_BT_HT_TEMPERATURE_TYPE_RECTUM,
  SL_BT_HT_TEMPERATURE_TYPE_TOE,
  SL_BT_HT_TEMPERATURE_TYPE_TYMPANUM,
};

/**************************************************************************//**
 * Initialize The health thermometer service.
 * @param NULL
 *****************************************************************************/
void health_thermometer_init();

/**************************************************************************//**
 * Send Temperature Measurement characteristic indication to the client.
 * @param[in] connection Connection handle of the client.
 * @param[in] temperature Temperature value in millidegree.
 * @param[in] fahrenheit Value is given in Fahrenheit (true) or Celsius (false).
 *****************************************************************************/
void health_thermometer_indicate_temp(struct bt_conn *connection,
                                      double temperature,
                                      bool fahrenheit);

// client configuration changed callback
void temperature_measurement_ccc_changed(const struct bt_gatt_attr *attr,
                                         uint16_t value);
void intermediate_temperature_ccc_changed(const struct bt_gatt_attr *attr,
                                          uint16_t value);
void measurement_interval_ccc_changed(const struct bt_gatt_attr *attr,
                                      uint16_t value);

void temperature_measurement_indicate_cb(struct bt_conn *conn,
                                         struct bt_gatt_indicate_params *params,
                                         uint8_t err);
void temperature_measurement_indicate_destroy(
  struct bt_gatt_indicate_params *params);

#endif /* _HEALTH_THERMOMETER_H_ */
