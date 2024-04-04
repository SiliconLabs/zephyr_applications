/***************************************************************************//**
 * @file
 * @brief User Interface for throughput test peripheral role.
 *******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
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
 ******************************************************************************/
#ifndef THROUGHPUT_PERIPHERAL_H
#define THROUGHPUT_PERIPHERAL_H

/***********************************************************************************************//**
 * @addtogroup throughput_peripheral
 * @{
 **************************************************************************************************/

#include "throughput_peripheral_config.h"
#include "throughput_types.h"
#include "throughput_common.h"

/*******************************************************************************
 ****************************  PUBLIC DEFINITIONS  *****************************
 ******************************************************************************/
#define THROUGHPUT_PERIPHERAL_CHARACTERISTICS_ALL         0x07

/*******************************************************************************
 ****************************   PUBLIC STRUCTURES  *****************************
 ******************************************************************************/

/// Bitfield for holding characteristic discovery status and result
typedef struct {
  uint8_t indication : 1;
  uint8_t notification : 1;
  uint8_t transmission_on : 1;
} throughput_peripheral_characteristic_t;

/// Union for checking characteristic discovery status and result
typedef union {
  throughput_peripheral_characteristic_t characteristic;
  uint8_t all;
} throughput_peripheral_characteristic_found_t;

/// Bitfield for holding throughput information service ccc
typedef struct {
  uint8_t connection_phy : 1;
  uint8_t connection_interval : 1;
  uint8_t responder_latency : 1;
  uint8_t supervision_timeout : 1;
  uint8_t pdu_size : 1;
  uint8_t mtu_size : 1;
} throughput_information_service_ccc_t;

/// Union for checking throughput information service ccc
typedef union {
  throughput_information_service_ccc_t notify;
  uint8_t all;
} throughput_information_service_ccc_enable_t;

/*******************************************************************************
 ****************************   PUBLIC FUNCTIONS   *****************************
 ******************************************************************************/

/**************************************************************************//**
 * Enables the transmission.
 *****************************************************************************/
void throughput_peripheral_enable(void);

/**************************************************************************//**
 * Disables the transmission.
 *****************************************************************************/
int throughput_peripheral_disable(void);

/**************************************************************************//**
 * Starts the the transmission.
 * @param[in] type type of the test (notification or indication)
 * @return status of the operation
 *****************************************************************************/
int throughput_peripheral_start(throughput_notification_t type);

/**************************************************************************//**
 * Stops the transmission.
 * @return status of the operation
 *****************************************************************************/
int throughput_peripheral_stop(void);

/**************************************************************************//**
 * Process step for throughput peripheral.
 *****************************************************************************/
void throughput_peripheral_step(void);

/*******************************************************************************
 ******************************   CALLBACKS    *********************************
 ******************************************************************************/

/**************************************************************************//**
 * Callback to handle role settings.
 * @param[in] role the role can be only THROUGHPUT_ROLE_PERIPHERAL
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_role_set(throughput_role_t role);

/**************************************************************************//**
 * Callback to handle state change.
 * @param[in] state current state
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_state_change(throughput_state_t state);

/**************************************************************************//**
 * Callback to handle mode change.
 * @param[in] mode current mode
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_mode_change(throughput_mode_t mode);

/**************************************************************************//**
 * Callback to handle transmission start event.
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_start(void);

/**************************************************************************//**
 * Callback to handle transmission finished event.
 * @param[in] throughput throughput value in bits/second (bps)
 * @param[in] count data volume transmitted, in bytes
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_finish(throughput_value_t throughput,
                                     throughput_count_t count);

/**************************************************************************//**
 * Callback to handle reception finished event.
 * @param[in] throughput throughput value in bits/second (bps)
 * @param[in] count data volume received, in bytes
 * @param[in] lost number of packets lost
 * @param[in] error number of wrong packets
 * @param[in] time total measurement time
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_finish_reception(throughput_value_t throughput,
                                               throughput_count_t count,
                                               throughput_count_t lost,
                                               throughput_count_t error,
                                               throughput_time_t time);

/**************************************************************************//**
 * Callback to handle TX power changed event.
 * @param[in] power TX power in dBm
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_power_change(throughput_tx_power_t power);

/**************************************************************************//**
 * Callback to handle RSSI changed event.
 * @param[in] rssi RSSI value
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_rssi_change(throughput_rssi_t rssi);

/**************************************************************************//**
 * Callback to handle phy changed event.
 * @param[in] phy PHY that is in use
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_phy_change(throughput_phy_t phy);

/**************************************************************************//**
 * Callback to handle connection settings changes.
 * @param[in] interval connection interval
 * @param[in] pdu PDU size in bytes
 * @param[in] mtu MTU size in bytes
 * @param[in] data data size in bytes
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_connection_settings_change(
  throughput_time_t interval,
  throughput_pdu_size_t pdu,
  throughput_mtu_size_t mtu,
  throughput_data_size_t data);

/**************************************************************************//**
 * Callback to handle notification changed event.
 * @param[in] notification notification status
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_notification_change(
  throughput_notification_t notification);

/**************************************************************************//**
 * Callback to handle indication changed event.
 * @param[in] indication indication status
 * @note To be implemented in user code.
 *****************************************************************************/
void throughput_peripheral_on_indication_change(
  throughput_notification_t indication);

/** @} (end addtogroup throughput_peripheral) */
#endif // THROUGHPUT_PERIPHERAL_H
