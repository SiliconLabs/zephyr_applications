/***************************************************************************//**
 * @file app.c
 * @brief zephyr application source file.
 *******************************************************************************
 * # License
 * <b>Copyright 2023 Silicon Laboratories Inc. www.silabs.com</b>
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
#include <stddef.h>
#include <string.h>
#include <errno.h>

#include <zephyr/kernel.h>
#include <zephyr/types.h>
#include <zephyr/drivers/gpio.h>

#include <zephyr/logging/log.h>
#include <zephyr/shell/shell.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gatt.h>

#include "throughput_types.h"
#include "throughput_peripheral.h"
#include "throughput_central.h"

LOG_MODULE_REGISTER(app, 3);

// -----------------------------------------------------------------------------
//                       Local Variables
// -----------------------------------------------------------------------------
static const struct gpio_dt_spec btn = GPIO_DT_SPEC_GET(DT_ALIAS(sw0), gpios);
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);

static struct gpio_callback gpio_cb;

// Desired role for throughput
throughput_role_t global_desired_role;

/// Current role for throughput
throughput_role_t role;

/// Current button state for testing
uint8_t button_previous = 0;

/// Mask first button release
bool mask_release = false;

/// Current button state for testing
throughput_notification_t throughput_test_type = BT_GATT_CCC_NOTIFY;

/// Current state of buttons
volatile uint8_t button_current;

/// Change of buttons
uint8_t button_change = 0;

/// Timer for button press handling
struct k_timer button_timer;

/// Timer rised for short press
bool button_timer_rised = false;

#define K_EVENT_APP_TEST_ON  (1 << 0)
#define K_EVENT_APP_TEST_OFF (1 << 1)
K_EVENT_DEFINE(my_event);

// -----------------------------------------------------------------------------
//                       Static function declaration
// -----------------------------------------------------------------------------
void app_test(bool start);
static void bt_ready(int err);
static int button_init(gpio_callback_handler_t handler,
                       const struct gpio_dt_spec *button);
static int led_init(void);
static void button_callback(const struct device *gpiob,
                            struct gpio_callback *cb,
                            uint32_t pins);
void app_button_timer_callback(struct k_timer *timer);
void app_handle_button_press(void);
void app_set_test_type(throughput_notification_t test_type);

static void enable_new_throughput_role(throughput_role_t new_role);
static int set_role_request_and_disable_current_role(
  throughput_role_t role_request);
static void set_role(throughput_role_t new_role);
static void handle_cli_switch_command(throughput_role_t role_request);

/***************************************************************************//**
 * Application initialization function.
 ******************************************************************************/
void app_init(void)
{
  int err;

  err = button_init(button_callback, &btn);
  if (err) {
    LOG_ERR("Button init failed (err %d)", err);
  }
  k_timer_init(&button_timer, app_button_timer_callback, 0);

  err = led_init();
  if (err) {
    LOG_ERR("LED init failed (err %d)", err);
  }

  /* Initialize the Bluetooth Subsystem */
  err = bt_enable(bt_ready);
  if (err) {
    LOG_ERR("Bluetooth init failed (err %d)", err);
  }

  if (gpio_pin_get(btn.port, btn.pin)) {
    // Enable throughput test in Central mode if button is pressed
    LOG_INF("Button is pressed on start: Central mode set.");
    set_role(THROUGHPUT_ROLE_CENTRAL);

    throughput_central_enable();
    // Mask first button release
    mask_release = true;
  } else {
    // Enable throughput test in Peripheral mode
    LOG_INF("Peripheral mode set.");
    set_role(THROUGHPUT_ROLE_PERIPHERAL);

    throughput_peripheral_enable();
  }
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  // Mask first button release
  if (mask_release && button_change && !button_current) {
    button_change = 0;
    mask_release = false;
  }

  // Identify button change
  button_change = (button_current ^ button_previous);

  // There is a button change
  if (button_change) {
    // Handle button press during operation
    app_handle_button_press();
  }

  // Save current button states
  button_previous = button_current;

  // uint32_t events = k_event_wait(&my_event, 0xFFF, false, K_MSEC(5));
  uint32_t events = k_event_wait(&my_event, 0xFFF, false, K_NO_WAIT);
  if (events & K_EVENT_APP_TEST_ON) {
    k_event_clear(&my_event, K_EVENT_APP_TEST_ON);
    app_test(true);
  }

  if (events & K_EVENT_APP_TEST_OFF) {
    app_test(false);
  }

  throughput_peripheral_step();

  throughput_central_step();

  k_yield();
}

// -----------------------------------------------------------------------------
//                       Local Function Definition
// -----------------------------------------------------------------------------

/**************************************************************************//**
 * Start or stop the test
 * @param[in] start true if start is required
 *****************************************************************************/
void app_test(bool start)
{
  int err;
  if (start) {
    // Start test
    LOG_INF("[TEST MODE] %s",
            throughput_test_type
            == BT_GATT_CCC_NOTIFY ? "NOTIFICATION" : "INDICATION");
    LOG_INF("Starting test...");
    if (role == THROUGHPUT_ROLE_PERIPHERAL) {
      err = throughput_peripheral_start(throughput_test_type);
      if (err != 0) {
        LOG_WRN("Failed to start test.");
      }
    } else {
      err = throughput_central_set_type(throughput_test_type);
      if (err != 0) {
        LOG_WRN("Failed to set test type.");
      } else {
        err = throughput_central_start();
        if (err != 0) {
          LOG_WRN("Failed to start test.");
        }
      }
    }
  } else {
    // Stop
    LOG_INF("Stopping test...");
    if (role == THROUGHPUT_ROLE_PERIPHERAL) {
      err = throughput_peripheral_stop();
      if (err != 0) {
        LOG_WRN("Failed to stop test.");
      } else {
        LOG_INF("Test Stopped.");
      }
    } else {
      err = throughput_central_stop();
      if (err != 0) {
        LOG_WRN("Failed to stop test.");
      } else {
        LOG_INF("Test Stopped.");
      }
    }
  }
}

/**************************************************************************//**
*  BLE initialization callback.
******************************************************************************/
static void bt_ready(int err)
{
  if (err) {
    LOG_ERR("Bluetooth initialized failed (err %d)", err);
    return;
  }
  LOG_INF("Bluetooth initialized successful");
}

/**************************************************************************//**
*  Button initialization.
******************************************************************************/
static int button_init(gpio_callback_handler_t handler,
                       const struct gpio_dt_spec *button)
{
  int ret;

  if (!gpio_is_ready_dt(button)) {
    LOG_ERR("Error: button GPIO device %s is not ready",
            button->port->name);
    return -ENODEV;
  }

  ret = gpio_pin_configure_dt(button, GPIO_INPUT);
  if (ret != 0) {
    LOG_ERR("Error %d: can't configure button on GPIO %s pin %d",
            ret, button->port->name, button->pin);
    return ret;
  }

  gpio_init_callback(&gpio_cb, handler, BIT(button->pin));
  gpio_add_callback(button->port, &gpio_cb);
  ret = gpio_pin_interrupt_configure_dt(button, GPIO_INT_EDGE_BOTH);
  if (ret != 0) {
    LOG_ERR("Error %d: can't configure button interrupt on "
            "GPIO %s pin %d", ret, button->port->name, button->pin);
    return ret;
  }
  return 0;
}

/**************************************************************************//**
*  LED initialization.
******************************************************************************/
static int led_init(void)
{
  int ret;

  if (!gpio_is_ready_dt(&led)) {
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
 * Handle buttons during operation
 *****************************************************************************/
void app_handle_button_press()
{
  if (button_current) {
    button_timer_rised = false;
    k_timer_start(&button_timer, K_MSEC(1000), K_MSEC(0));
  } else {
    k_timer_stop(&button_timer);
    if (button_timer_rised) {
      app_test(false);
      // k_event_set(&my_event, K_EVENT_APP_TEST_OFF);
    } else {
      if (throughput_test_type == BT_GATT_CCC_NOTIFY) {
        throughput_test_type = BT_GATT_CCC_INDICATE;
      } else {
        throughput_test_type = BT_GATT_CCC_NOTIFY;
      }
      app_set_test_type(throughput_test_type);
    }
  }
}

/**************************************************************************//**
 *
 *****************************************************************************/
static void enable_new_throughput_role(throughput_role_t new_role)
{
  switch (new_role) {
    case THROUGHPUT_ROLE_CENTRAL:
      set_role(new_role);
      throughput_central_enable();
      break;

    case THROUGHPUT_ROLE_PERIPHERAL:
      set_role(new_role);
      throughput_peripheral_enable();
      break;
  }
}

static int set_role_request_and_disable_current_role(
  throughput_role_t role_request)
{
  int err = 0;

  // If state is not disconnected, we have to make sure, it will be disconnected
  switch (role) {
    case THROUGHPUT_ROLE_CENTRAL:
      err = throughput_central_disable();
      break;

    case THROUGHPUT_ROLE_PERIPHERAL:
      err = throughput_peripheral_disable();
      break;

    default:
      // Set the current role and desired role to the same role
      set_role(role);
      err = 1;
      break;
  }

  if (err == 0) {
    global_desired_role = role_request;
  }

  return err;
}

static void set_role(throughput_role_t new_role)
{
  role = new_role;
  // Make sure the global, desired role will change
  global_desired_role = role;
}

static void handle_cli_switch_command(throughput_role_t role_request)
{
  int err = 0;

  if (role != role_request) {
    err = set_role_request_and_disable_current_role(role_request);
  } else {
    LOG_WRN("Already in that state.");
  }

  if (err != 0) {
    LOG_WRN("There was an error during state change. STATUS: %d", err);
  }
}

/**************************************************************************//**
 * CLI command to switch from current state to central
 *****************************************************************************/
void cli_switch_to_central(const struct shell *sh, size_t argc, char **argv)
{
  ARG_UNUSED(sh);
  ARG_UNUSED(argc);
  ARG_UNUSED(argv);
  handle_cli_switch_command(THROUGHPUT_ROLE_CENTRAL);
}

/**************************************************************************//**
 * CLI command to switch from current state to peripheral
 *****************************************************************************/
void cli_switch_to_peripheral(const struct shell *sh, size_t argc, char **argv)
{
  ARG_UNUSED(sh);
  ARG_UNUSED(argc);
  ARG_UNUSED(argv);
  handle_cli_switch_command(THROUGHPUT_ROLE_PERIPHERAL);
}

/**************************************************************************//**
 * Timer callback
 *****************************************************************************/
void app_button_timer_callback(struct k_timer *timer)
{
  (void) timer;
  button_timer_rised = true;
  // app_test(true);
  k_event_set(&my_event, K_EVENT_APP_TEST_ON);
}

/**************************************************************************//**
*  Button callback.
******************************************************************************/
static void button_callback(const struct device *gpiob,
                            struct gpio_callback *cb,
                            uint32_t pins)
{
  button_current = gpio_pin_get(btn.port, btn.pin);
}

/**************************************************************************//**
 * Set test type
 * @param[in] test_type type of the test:
 *  - sl_bt_gatt_notification or
 *  - sl_bt_gatt_indication
 *****************************************************************************/
void app_set_test_type(throughput_notification_t test_type)
{
  throughput_test_type = test_type;

  if (throughput_test_type == BT_GATT_CCC_INDICATE) {
    gpio_pin_set(led.port, led.pin, 1);
  } else {
    gpio_pin_set(led.port, led.pin, 0);
  }
}

/**************************************************************************//**
 * Callback to handle state change.
 * @param[in] state current state
 *****************************************************************************/
void throughput_central_on_state_change(throughput_state_t state)
{
  if (state == THROUGHPUT_STATE_UNINITALIZED) {
    enable_new_throughput_role(THROUGHPUT_ROLE_PERIPHERAL);
  }
}

/**************************************************************************//**
 * Callback to handle state change.
 * @param[in] state current state
 *****************************************************************************/
void throughput_peripheral_on_state_change(throughput_state_t state)
{
  if (state == THROUGHPUT_STATE_UNINITALIZED) {
    enable_new_throughput_role(THROUGHPUT_ROLE_CENTRAL);
  }
}
