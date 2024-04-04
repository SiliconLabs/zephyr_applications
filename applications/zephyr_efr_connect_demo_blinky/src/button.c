/***************************************************************************//**
 * @file app.h
 * @brief zephyr button source file.
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
#include "button.h"

LOG_MODULE_REGISTER(button);

// -----------------------------------------------------------------------------
//                       Local Variables
// -----------------------------------------------------------------------------
static struct gpio_callback gpio_cb;

/**************************************************************************//**
*  Button initialization.
******************************************************************************/
int button_init(gpio_callback_handler_t handler, struct gpio_dt_spec button)
{
  int ret;

  if (!gpio_is_ready_dt(&button)) {
    LOG_ERR("Error: button GPIO device %s is not ready",
            button.port->name);
    return -ENODEV;
  }

  ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
  if (ret != 0) {
    LOG_ERR("Error %d: can't configure button on GPIO %s pin %d",
            ret, button.port->name, button.pin);
    return ret;
  }

  gpio_init_callback(&gpio_cb, handler, BIT(button.pin));
  gpio_add_callback(button.port, &gpio_cb);
  ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
  if (ret != 0) {
    LOG_ERR("Error %d: can't configure button interrupt on "
            "GPIO %s pin %d", ret, button.port->name, button.pin);
    return ret;
  }
  return 0;
}
