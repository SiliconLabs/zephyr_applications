/***************************************************************************//**
 * @file app.c
 * @brief zephyr mikrobus demo source file.
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
#include <zephyr/device.h>
#include <zephyr/display/cfb.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/logging/log.h>
#include "app.h"

#define DISPLAY_DRIVER       "solomon_ssd1306fb"
#define SELECTED_FONT_INDEX  3

LOG_MODULE_REGISTER(app, 3);

static const struct device *display;
static const struct device *sensor;
static struct cfb_position line_start_pos = {
  .x = 0,
  .y = 10,
};
static struct cfb_position line_end_pos = {
  .x = 96,
  .y = 10,
};

static void app_sensor_init(void);
static void app_oled_init(void);
static void app_oled_update(float magnetic_value);

/***************************************************************************//**
 * OLED update application.
 ******************************************************************************/
static void app_oled_update(float magnetic_value)
{
  static char temp[10];

  cfb_framebuffer_clear(display, false);
  cfb_print(display, "Mikrobus Demo", 15, 0);

  cfb_draw_line(display, &line_start_pos, &line_end_pos);

  cfb_print(display, "Magnetic: ", 0, 15);
  snprintf(temp, sizeof(temp), "%.2f mT", magnetic_value);
  cfb_print(display, temp, 45, 15);

  if (abs(magnetic_value) > CONFIG_SI7210_MAGNETIC_THRESHOLD) {
    LOG_INF("Detected a magnetic object nearby.");
    cfb_print(display, "< Magnetic Object >", 0, 27);
  }

  cfb_framebuffer_finalize(display);
}

/***************************************************************************//**
 * OLED initialization function.
 ******************************************************************************/
static void app_oled_init(void)
{
  display = DEVICE_DT_GET_ONE(sinowealth_sh1106);

  if (NULL == display) {
    LOG_ERR("Mikroe OLED W Cick is not found.");
    return;
  }
  if (!device_is_ready(display)) {
    LOG_ERR("Mikroe OLED W Click is not ready!");
  }
  if (display_set_pixel_format(display, PIXEL_FORMAT_MONO10) != 0) {
    LOG_ERR("Failed to set required pixel format");
    return;
  }
  LOG_INF("Binding to %s", DISPLAY_DRIVER);
  if (cfb_framebuffer_init(display)) {
    LOG_ERR("Framebuffer initialization failed!");
    return;
  }

  cfb_framebuffer_clear(display, true);
  display_blanking_off(display);

  cfb_framebuffer_set_font(display, SELECTED_FONT_INDEX);

  LOG_INF("Mikroe OLED W Click initialized successfully.");
  cfb_framebuffer_invert(display);
}

/***************************************************************************//**
 * Sensor initialization function.
 ******************************************************************************/
static void app_sensor_init(void)
{
  sensor = DEVICE_DT_GET_ANY(silabs_si7210);

  if (NULL == sensor) {
    LOG_ERR("Si7210 sensor is not found.");
    return;
  }

  if (!device_is_ready(display)) {
    LOG_ERR("Si7210 sensor is not ready!");
  }

  LOG_INF("Si7210 sensor initialized successfully.");
  LOG_INF("Magnetic induction threshold: %d mT",
          CONFIG_SI7210_MAGNETIC_THRESHOLD);
}

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  app_oled_init();
  app_sensor_init();
}

/***************************************************************************//**
 * Application ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  struct sensor_value magnetic;
  float f_magnetic;

  while (1) {
    sensor_sample_fetch(sensor);
    sensor_channel_get(sensor, SENSOR_CHAN_MAGN_Z, &magnetic);

    f_magnetic = magnetic.val1 + magnetic.val2 / 1000000;
    LOG_INF("Magnetic: %.2f mT", f_magnetic);

    app_oled_update(f_magnetic);
    k_sleep(K_MSEC(1000));
  }
}
