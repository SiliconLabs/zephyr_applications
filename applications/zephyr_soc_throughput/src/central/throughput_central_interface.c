/***************************************************************************//**
 * @file throughput_central_interface.c
 * @brief
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
#include "throughput_central_interface.h"
#include "throughput_types.h"

static void refresh_timer_callback(struct k_timer *timer);

/// Time storage variable
static uint32_t time_start = 0;

/// RSSI refresh timer
// struct k_timer refresh_timer;
static K_TIMER_DEFINE(refresh_timer, refresh_timer_callback, NULL);

static void refresh_timer_callback(struct k_timer *timer)
{
  (void)timer;
}

/**************************************************************************//**
 * ASCII graphics for indicating wait status
 *****************************************************************************/
void waiting_indication(void)
{
  // Do nothing
}

/**************************************************************************//**
 * Start timer
 *****************************************************************************/
void timer_start()
{
  time_start = k_uptime_get_32();
}

/**************************************************************************//**
 * Timer end. The return value of this function shall be the time passed
 * form the timer_start() call in seconds.
 *****************************************************************************/
float timer_end()
{
  return (float)(k_uptime_get_32() - time_start) / 1000;
}

/**************************************************************************//**
 * Start RSSI refresh timer
 *****************************************************************************/
void timer_refresh_rssi_start(void)
{
  // k_timer_init(&refresh_timer, refresh_timer_callback, NULL);
  // Start refresh timer
  k_timer_start(&refresh_timer,
                K_MSEC(THROUGHPUT_CENTRAL_REFRESH_TIMER_PERIOD),
                K_MSEC(THROUGHPUT_CENTRAL_REFRESH_TIMER_PERIOD));
}

/**************************************************************************//**
 * Stop RSSI refresh timer
 *****************************************************************************/
void timer_refresh_rssi_stop(void)
{
  // Stop refresh timer
  k_timer_stop(&refresh_timer);
}
