/***************************************************************************//**
 * @file throughput_central_config.h
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
#ifndef THROUGHPUT_CENTRAL_CONFIG_H
#define THROUGHPUT_CENTRAL_CONFIG_H

#include "throughput_types.h"

// <<< Use Configuration Wizard in Context Menu >>>

// <h> Mode settings

// <o THROUGHPUT_CENTRAL_TEST_TYPE> Default test
//   <sl_bt_gatt_notification=> Notification
//   <sl_bt_gatt_indication=> Indication
// <i> Default: sl_bt_gatt_notification
#define THROUGHPUT_CENTRAL_TEST_TYPE                  0

// <o THROUGHPUT_CENTRAL_MODE_DEFAULT> Default mode
//   <THROUGHPUT_MODE_CONTINUOUS=> Continuous mode
//   <THROUGHPUT_MODE_FIXED_LENGTH=> Fixed data size
//   <THROUGHPUT_MODE_FIXED_TIME=> Fixed time
// <i> Default: THROUGHPUT_MODE_CONTINUOUS
#define THROUGHPUT_CENTRAL_MODE_DEFAULT \
  THROUGHPUT_MODE_CONTINUOUS

// <o THROUGHPUT_CENTRAL_FIXED_DATA_SIZE> Data size in bytes
// <i> Default: 100000
#define THROUGHPUT_CENTRAL_FIXED_DATA_SIZE               100000

// <o THROUGHPUT_CENTRAL_FIXED_TIME> Time in ms
// <i> Default: 10000
#define THROUGHPUT_CENTRAL_FIXED_TIME                    10000

// </h>

// <h> Data and PHY settings

// <o THROUGHPUT_CENTRAL_MTU_SIZE> Default MTU size <23-250>
// <i> Default: 247
#define THROUGHPUT_CENTRAL_MTU_SIZE                   247

// </h>

// <h> Connection settings

// <o THROUGHPUT_CENTRAL_CONNECTION_INTERVAL_MIN> Minimum connection interval
//   (in 1.25 ms steps) <6-3200>
// <i> Default: 80
#define THROUGHPUT_CENTRAL_CONNECTION_INTERVAL_MIN                       32

// <o THROUGHPUT_CENTRAL_CONNECTION_INTERVAL_MAX> Maximum connection interval
//   (in 1.25 ms steps) <6-3200>
// <i> Default: 80
#define THROUGHPUT_CENTRAL_CONNECTION_INTERVAL_MAX                       32

// <o THROUGHPUT_CENTRAL_CONNECTION_RESPONDER_LATENCY> Responder latency (in
//   connection intervals) <0-500>
// <i> Default: 0
#define THROUGHPUT_CENTRAL_CONNECTION_RESPONDER_LATENCY                  0

// <o THROUGHPUT_CENTRAL_CONNECTION_TIMEOUT> Supervision timeout (in 10 ms
//   steps) <0-3200>
// <i> Default: 1000
#define THROUGHPUT_CENTRAL_CONNECTION_TIMEOUT                            1000

// </h>

// <h> Power settings

// <o THROUGHPUT_CENTRAL_TX_POWER> TX power limit set by the component (in dBm)
// <i> Default: 10, however maximum value depends on system settings
#define THROUGHPUT_CENTRAL_TX_POWER                           10

// <q THROUGHPUT_CENTRAL_POWER_CONTROL_ENABLE> Adaptive power control
// <i> Default: 0
#define THROUGHPUT_CENTRAL_POWER_CONTROL_ENABLE               0

// <q THROUGHPUT_CENTRAL_SLEEP_ENABLE> Enable deep sleep
// <i> Default: 0
#define THROUGHPUT_CENTRAL_SLEEP_ENABLE                       0

// </h>

// <e THROUGHPUT_CENTRAL_ALLOWLIST_ENABLE> Allowlist
// <i> Default: 0
#define THROUGHPUT_CENTRAL_ALLOWLIST_ENABLE                   0

// <e THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_1_ENABLE> Slot 1
// <i> Default: 0
#define THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_1_ENABLE            0

// <s.17 THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_1> MAC Addess
// <i> Default: "00:00:00:00:00:00"
#define THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_1 \
  "00:00:00:00:00:00"

// </e>

// <e THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_2_ENABLE> Slot 2
// <i> Default: 0
#define THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_2_ENABLE            0

// <s.17 THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_2> MAC Addess
// <i> Default: "00:00:00:00:00:00"
#define THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_2 \
  "00:00:00:00:00:00"

// </e>

// <e THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_3_ENABLE> Slot 3
// <i> Default: 0
#define THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_3_ENABLE            0

// <s.17 THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_3> MAC Addess
// <i> Default: "00:00:00:00:00:00"
#define THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_3 \
  "00:00:00:00:00:00"

// </e>

// <e THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_4_ENABLE> Slot 4
// <i> Default: 0
#define THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_4_ENABLE            0

// <s.17 THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_4> MAC Addess
// <i> Default: "00:00:00:00:00:00"
#define THROUGHPUT_CENTRAL_ALLOWLIST_SLOT_4 \
  "00:00:00:00:00:00"

// </e>

// </e>

// <<< end of configuration section >>>

#endif // THROUGHPUT_CENTRAL_CONFIG_H
