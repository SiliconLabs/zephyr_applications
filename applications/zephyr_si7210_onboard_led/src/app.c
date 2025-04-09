/***************************************************************************//**
 * @file app.c
 * @brief zephyr si7210 hall effect magnetic sensor source file.
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

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/gpio.h>
#include <stdio.h>
#include "app.h"

LOG_MODULE_REGISTER(app, 3);
#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct device *const dev = DEVICE_DT_GET_ANY(silabs_si7210);

/***************************************************************************//**
 * Application initialization function.
 ******************************************************************************/
void app_init(void)
{
  uint8_t ret;

  if (dev == NULL) {
    /* No such node, or the node does not have status "okay". */
    LOG_ERR("Si7210 Hall-effect sensor is not found.");
    return;
  }

  if (!gpio_is_ready_dt(&led)) {
    LOG_ERR("LED device \"%s\" is not ready; "
            "check the driver initialization logs for errors.",
            dev->name);
    return;
  }

  if (!device_is_ready(dev)) {
    LOG_ERR("Sensor device \"%s\" is not ready; "
            "check the driver initialization logs for errors.",
            dev->name);
    return;
  }

  ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
  if (ret < 0) {
    return;
  }

  LOG_INF("Found device \"%s\", getting sensor data ...", dev->name);
  LOG_INF("Magnectic induction threshold: %d mT",
          CONFIG_SI7210_MAGNETIC_THRESHOLD);
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  struct sensor_value magnetic;
  double f_magnetic;

  sensor_sample_fetch(dev);
  sensor_channel_get(dev, SENSOR_CHAN_MAGN_Z, &magnetic);

  f_magnetic = magnetic.val1 + (double)(magnetic.val2) / 1000000;

  LOG_INF("Magnetic value: %.2lf mT", f_magnetic);

  if (abs(f_magnetic) > CONFIG_SI7210_MAGNETIC_THRESHOLD) {
    if (!gpio_pin_get(led.port, led.pin)) {
      gpio_pin_set(led.port, led.pin, true);
      LOG_INF("Turn ON LED.");
    } else {
    }
  } else {
    if (gpio_pin_get(led.port, led.pin)) {
      gpio_pin_set(led.port, led.pin, false);
      LOG_INF("Turn OFF LED.");
    } else {
    }
  }

  k_sleep(K_MSEC(1000));
}
