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
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include <lvgl_input_device.h>
#include <zephyr/input/input_resistive_touchscreen_4wire.h>

#include "ui.h"
#include "bthome_v2.h"

LOG_MODULE_REGISTER(app);
// ****************************************************************************
//                          Macros
// ****************************************************************************
#define CONVERT_SENSOR_FLOAT_VALUE(val1,          \
                                   val2) (((val1) \
                                           + ((double)(val2) / (1000000))))

#define READ_TEMPERATURE                0x00
#define READ_HUMIDITY                   0x01
#define READ_ILLU                       0x02
#define READ_ROTATION                   0x03
#define READ_ACCELERATION               0x04
#define READ_PRESSURE                   0x05
#define READ_MAGNETIC                   0x06
#define READ_DEFAULT                    0x07

#define TIMER_INTERVAL_DEFAULT_MS       2000

// ****************************************************************************
//                          Static Variables Declarations
// ****************************************************************************
static uint8_t device_name[8] = "ZPBTxG24";
static uint8_t key[] = "12345678123456781234567812345678";
static volatile bool should_update;
static volatile bool load_main_screen;
static volatile uint8_t sensor_read = READ_ACCELERATION;
static volatile uint32_t broadcast_time_count = 0;
static struct k_timer broadcast_timer;

static const struct device *const  si7021_sensor = DEVICE_DT_GET_ANY(
  silabs_si7006);
static const struct device *const  si7210_sensor = DEVICE_DT_GET_ANY(
  silabs_si7210);
static const struct device *const  veml6035_sensor = DEVICE_DT_GET_ANY(
  vishay_veml7700);
static const struct device *const  icm20689_sensor = DEVICE_DT_GET_ANY(
  invensense_icm20689);
static const struct device *const  bmp384_sensor = DEVICE_DT_GET_ANY(
  bosch_bmp384);

// ****************************************************************************
//                          Static Variables Declarations
// ****************************************************************************
static void app_get_sensor_data(void);
static void app_init(void);

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
      sensor_read = READ_MAGNETIC;
      break;
    case READ_MAGNETIC:
      sensor_read = READ_PRESSURE;
      break;
    case READ_PRESSURE:
      sensor_read = READ_ROTATION;
      break;
    case READ_ROTATION:
      sensor_read = READ_ACCELERATION;
      break;
    case READ_ACCELERATION:
      sensor_read = READ_TEMPERATURE;
      break;
  }

  if (broadcast_enabled) {
    broadcast_time_count += (broadcast_interval) / 1000;
    broadcast_time_count =
      (broadcast_time_count > 99999) ? 0 : broadcast_time_count;
  }

  if (!load_main_screen) {
    lv_disp_load_scr(ui_ApplicationScreen);
    load_main_screen = true;
  }
  should_update = true;
}

/***************************************************************************//**
 *  Application get sensor data.
 ******************************************************************************/
static void app_get_sensor_data(void)
{
  char buffer[10];
  struct sensor_value sensor_val, icm_val[3];

  if (should_update) {
    switch (sensor_read) {
      case READ_TEMPERATURE:
        sensor_sample_fetch(si7021_sensor);
        sensor_channel_get(si7021_sensor, SENSOR_CHAN_AMBIENT_TEMP,
                           &sensor_val);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_FLOAT_VALUE(
                                                sensor_val.val1,
                                                sensor_val.val2),
                                              TEMPERTAURE_OBJ_ID,
                                              broadcast_enabled);
        memset(buffer, 0, 10);
        sprintf(buffer, "%.2lf",
                CONVERT_SENSOR_FLOAT_VALUE(sensor_val.val1, sensor_val.val2));
        lv_label_set_text(ui_labelTempValue, buffer);
        break;
      case READ_HUMIDITY:
        sensor_channel_get(si7021_sensor, SENSOR_CHAN_HUMIDITY, &sensor_val);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_FLOAT_VALUE(
                                                sensor_val.val1,
                                                sensor_val.val2),
                                              HUMIDITY_OBJ_ID,
                                              broadcast_enabled);
        memset(buffer, 0, 10);
        sprintf(buffer, "%.2lf",
                CONVERT_SENSOR_FLOAT_VALUE(sensor_val.val1, sensor_val.val2));
        lv_label_set_text(ui_labelhumidityValue, buffer);
        break;
      case READ_ILLU:
        sensor_sample_fetch(veml6035_sensor);
        sensor_channel_get(veml6035_sensor, SENSOR_CHAN_LIGHT, &sensor_val);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_FLOAT_VALUE(
                                                sensor_val.val1,
                                                sensor_val.val2),
                                              ILLUM_OBJ_ID,
                                              broadcast_enabled);
        memset(buffer, 0, 10);
        sprintf(buffer, "%.2lf",
                CONVERT_SENSOR_FLOAT_VALUE(sensor_val.val1, sensor_val.val2));
        lv_label_set_text(ui_labelVEMLAmbientLightValue, buffer);
        break;
      case READ_MAGNETIC:
        sensor_sample_fetch(si7210_sensor);
        sensor_channel_get(si7210_sensor, SENSOR_CHAN_MAGN_Z, &sensor_val);
        memset(buffer, 0, 10);
        sprintf(buffer, "%.2lf",
                CONVERT_SENSOR_FLOAT_VALUE(sensor_val.val1, sensor_val.val2));
        lv_label_set_text(ui_labelsi7210HallEffectValue, buffer);
        break;
      case READ_PRESSURE:
        sensor_sample_fetch_chan(bmp384_sensor, SENSOR_CHAN_PRESS);
        sensor_channel_get(bmp384_sensor, SENSOR_CHAN_PRESS, &sensor_val);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_FLOAT_VALUE(
                                                sensor_val.val1,
                                                sensor_val.val2),
                                              PRESSURE_OBJ_ID,
                                              broadcast_enabled);
        memset(buffer, 0, 10);
        sprintf(buffer, "%.2lf",
                CONVERT_SENSOR_FLOAT_VALUE(sensor_val.val1, sensor_val.val2));
        lv_label_set_text(ui_labelBMP384Value, buffer);
        break;
      case READ_ROTATION:
        sensor_sample_fetch_chan(icm20689_sensor, SENSOR_CHAN_GYRO_XYZ);
        sensor_channel_get(icm20689_sensor, SENSOR_CHAN_GYRO_XYZ, icm_val);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_FLOAT_VALUE(
                                                icm_val[0].val1,
                                                icm_val[0].val2),
                                              ROTATION_OBJ_ID,
                                              broadcast_enabled);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_FLOAT_VALUE(
                                                icm_val[1].val1,
                                                icm_val[1].val2),
                                              ROTATION_OBJ_ID,
                                              broadcast_enabled);
        bthome_v2_add_measurement_float_value(CONVERT_SENSOR_FLOAT_VALUE(
                                                icm_val[2].val1,
                                                icm_val[2].val2),
                                              ROTATION_OBJ_ID,
                                              broadcast_enabled);
        memset(buffer, 0, 10);
        sprintf(buffer, "%.2lf",
                CONVERT_SENSOR_FLOAT_VALUE(icm_val[0].val1, icm_val[0].val2));
        lv_label_set_text(ui_labelorientXvalue, buffer);
        memset(buffer, 0, 10);
        sprintf(buffer, "%.2lf",
                CONVERT_SENSOR_FLOAT_VALUE(icm_val[1].val1, icm_val[1].val2));
        lv_label_set_text(ui_labelorientYvalue, buffer);
        memset(buffer, 0, 10);
        sprintf(buffer, "%.2lf",
                CONVERT_SENSOR_FLOAT_VALUE(icm_val[2].val1, icm_val[2].val2));
        lv_label_set_text(ui_labelorientZvalue, buffer);
        break;
      case READ_ACCELERATION: {
        double acc_data;
        sensor_sample_fetch_chan(icm20689_sensor, SENSOR_CHAN_ACCEL_XYZ);
        sensor_channel_get(icm20689_sensor, SENSOR_CHAN_ACCEL_XYZ, icm_val);
        acc_data = CONVERT_SENSOR_FLOAT_VALUE(icm_val[0].val1, icm_val[0].val2);
        bthome_v2_add_measurement_float_value((acc_data > 0) ? acc_data : 0,
                                              ACCELERATION_OBJ_ID,
                                              broadcast_enabled);
        memset(buffer, 0, 10);
        sprintf(buffer, "%.2lf", (acc_data > 0) ? acc_data : 0);
        lv_label_set_text(ui_labelg1Value, buffer);
        acc_data = CONVERT_SENSOR_FLOAT_VALUE(icm_val[1].val1, icm_val[1].val2);
        bthome_v2_add_measurement_float_value((acc_data > 0) ? acc_data : 0,
                                              ACCELERATION_OBJ_ID,
                                              broadcast_enabled);
        memset(buffer, 0, 10);
        sprintf(buffer, "%.2lf", (acc_data > 0) ? acc_data : 0);
        lv_label_set_text(ui_labelg2Value, buffer);
        acc_data = CONVERT_SENSOR_FLOAT_VALUE(icm_val[2].val1, icm_val[2].val2);
        bthome_v2_add_measurement_float_value((acc_data > 0) ? acc_data : 0,
                                              ACCELERATION_OBJ_ID,
                                              broadcast_enabled);
        memset(buffer, 0, 10);
        sprintf(buffer, "%.2lf", (acc_data > 0) ? acc_data : 0);
        lv_label_set_text(ui_labelg3Value, buffer);
      }
      break;
      default:
        break;
    }
    should_update = false;
    if (broadcast_enabled) {
      memset(buffer, 0, 10);
      sprintf(buffer, "%d", broadcast_time_count);
      lv_label_set_text(ui_labelsecond, buffer);
      if (lv_obj_has_flag(ui_labelsecond, LV_OBJ_FLAG_HIDDEN)) {
        lv_obj_clear_flag(ui_labelsecond, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(ui_labelsecago, "sec ago");
        lv_obj_set_x(ui_labelsecago, 136);
        lv_obj_set_y(ui_labelsecago, 108);
        lv_obj_set_style_text_color(ui_labelsecago,
                                    lv_color_hex(0x000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      }
    }
  }
}

/***************************************************************************//**
 *  Application BTHome device configuration.
 ******************************************************************************/
static void app_bthome_configure_device(void)
{
  uint16_t temp;
  const char *text;

  if (config_broadcast_interval) {
    temp = atoi(lv_textarea_get_text(ui_txtboardcastperiod));
    broadcast_interval = temp;
    k_timer_start(&broadcast_timer, K_MSEC(broadcast_interval),
                  K_MSEC(broadcast_interval));
    config_broadcast_interval = false;
  } else if (config_device_name) {
    text = lv_textarea_get_text(ui_txtdevicename);
    bthome_v2_set_device_name(text, strlen(text));
    config_device_name = false;
  } else if (config_encryption_key) {
    text = lv_textarea_get_text(ui_txtencryptkey);
    bthome_v2_set_key(text);
    config_encryption_key = false;
  }
  if (!broadcast_enabled) {
    broadcast_time_count = 0;
    if (!lv_obj_has_flag(ui_labelsecond, LV_OBJ_FLAG_HIDDEN)) {
      lv_obj_add_flag(ui_labelsecond, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(ui_labelsecago, "Disabled");
      lv_obj_set_x(ui_labelsecago, 119);
      lv_obj_set_y(ui_labelsecago, 108);
      lv_obj_set_style_text_color(ui_labelsecago,
                                  lv_color_hex(0xFF0000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    }
  }
}

/***************************************************************************//**
 *  Application Init.
 ******************************************************************************/
static void app_init(void)
{
  if ((si7021_sensor == NULL) || (si7210_sensor == NULL)
      || (veml6035_sensor == NULL) || (icm20689_sensor == NULL)
      || (bmp384_sensor == NULL)) {
    LOG_ERR("Device not found!");
    return;
  }

  if (!device_is_ready(si7021_sensor) || !device_is_ready(si7210_sensor)
      || !device_is_ready(veml6035_sensor)
      || !device_is_ready(icm20689_sensor) || !device_is_ready(bmp384_sensor)) {
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
  const struct device *display_dev;

  display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
  if (!device_is_ready(display_dev)) {
    LOG_ERR("Device not ready, aborting test");
    return 0;
  }

  display_blanking_off(display_dev);

  app_init();
  ui_init();

  ret = bt_enable(NULL);
  if (ret) {
    printk("Bluetooth init failed (err %d)\n", ret);
    return 0;
  }

  bthome_v2_set_device_name(device_name, sizeof(device_name));
  bthome_v2_set_key(key);

  k_timer_init(&broadcast_timer, app_broadcast_timer_handle, NULL);
  k_timer_start(&broadcast_timer, K_MSEC(broadcast_interval),
                K_MSEC(broadcast_interval));

  while (1) {
    app_get_sensor_data();
    if (lv_scr_act() == ui_SettingScreen) {
      app_bthome_configure_device();
    }
    lv_task_handler();
    k_sleep(K_MSEC(1));
  }
  return 0;
}
