/***************************************************************************//**
 * @file bthome_v2.h
 * @brief zephyr bthome v2 header file.
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef _BTHOME_V2_H
#define _BTHOME_V2_H

#define TEMPERTAURE_OBJ_ID              0x02
#define HUMIDITY_OBJ_ID                 0x03
#define ILLUM_OBJ_ID                    0x05
#define ROTATION_OBJ_ID                 0x3F
#define ACCELERATION_OBJ_ID             0x51
#define PRESSURE_OBJ_ID                 0x04

/**
 * @brief Set device name function
 *
 * @param device_name Device name
 * @param length Length of device name
 */
void bthome_v2_set_device_name(const char *device_name, uint8_t length);

/**
 * @brief Set the encryption key in BTHome v2 format
 *
 * @param key Encryption key
 * @return uint8_t Status of the function
 */
uint8_t bthome_v2_set_key(uint8_t const * const key);

/**
 * @brief Add the measurement float value to the advertising package.
 *
 * @param value Sensor value
 * @param obj_id Object ID
 * @param broadcast_enabled Enabled/disbale broadcast
 */
void bthome_v2_add_measurement_float_value(float value,
                                           uint8_t obj_id,
                                           bool broadcast_enabled);

/**
 * @brief Build advertising package according to BTHome v2 format
 *
 * @param obj_id  Object ID
 */
void bthome_v2_build_packet(uint8_t obj_id);

/**
 * @brief Update the advertising package.
 *
 * @param obj_id Object ID
 */
void bthome_v2_update_data(uint8_t obj_id);

#endif /* _BTHOME_V2_H*/
