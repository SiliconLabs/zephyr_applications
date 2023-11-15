/***************************************************************************//**
 * @file led.c
 * @brief zephyr led source file.
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
#include "led.h"

LOG_MODULE_REGISTER(led);

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);

/**************************************************************************//**
*  LED initialization.
******************************************************************************/
int led_init(void)
{
  int ret;

  bool led_ok = gpio_is_ready_dt(&led);
  if (!led_ok) {
    LOG_ERR("Error: LED on GPIO %s pin %d is not ready",
            led.port->name, led.pin);
    return -ENODEV;
  }

  ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
  if (ret < 0) {
    LOG_ERR("Error %d: failed to configure GPIO %s pin %d",
            ret, led.port->name, led.pin);
  }
  return ret;
}

/**************************************************************************//**
*  LED initialization.
******************************************************************************/
int led_control(uint8_t led_state)
{
  LOG_INF("Turn %s LED", led_state ? "on" : "off");
  return gpio_pin_set(led.port, led.pin, led_state);
}
