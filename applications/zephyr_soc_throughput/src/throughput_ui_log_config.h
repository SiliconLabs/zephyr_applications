/***************************************************************************//**
 * @file throughput_ui_log_config.h
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
 *******************************************************************************
 * # EXPERIMENTAL QUALITY
 * This code has not been formally tested and is provided as-is. It is not
 * suitable for production environments. In addition, this code will not be
 * maintained and there may be no bug maintenance planned for these resources.
 * Silicon Labs may update projects from time to time.
 ******************************************************************************/
#ifndef THROUGHPUT_UI_LOG_CONFIG_H
#define THROUGHPUT_UI_LOG_CONFIG_H

/***********************************************************************************************//**
 * @addtogroup throughput_ui
 * @{
 **************************************************************************************************/

// <<< Use Configuration Wizard in Context Menu >>>

// <e THROUGHPUT_UI_LOG_ENABLE> Enable logging
// <i> Enables UI logging.
#define THROUGHPUT_UI_LOG_ENABLE          CONFIG_THROUGHPUT_UI_LOG_ENABLE

// <e THROUGHPUT_UI_LOG_REFRESH_ALL> Print entire display
// <i> Enables printing all rows (entire display) on update method. By disabling
//   this, rows are printed on parameter update.
#define THROUGHPUT_UI_LOG_REFRESH_ALL     CONFIG_THROUGHPUT_UI_LOG_REFRESH_ALL

// <q THROUGHPUT_UI_LOG_BOX_ENABLE> Draw box
// <i> Enables drawing a box around the display area.
#define THROUGHPUT_UI_LOG_BOX_ENABLE      CONFIG_THROUGHPUT_UI_LOG_BOX_ENABLE

// </e>

// </e>

// <<< end of configuration section >>>

/** @} (end addtogroup throughput_ui) */
#endif // THROUGHPUT_UI_LOG_CONFIG_H
