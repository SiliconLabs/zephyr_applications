
/***************************************************************************//**
 * @file cli_command_table.c
 * @brief zephyr CLI command source file.
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
#include <stdlib.h>
#include "zephyr/shell/shell.h"

void cli_set_device_name(const struct shell *sh,
                         size_t argc,
                         char **argv);
void cli_set_encryption_key(const struct shell *sh,
                            size_t argc,
                            char **argv);
void cli_set_boardcast(const struct shell *sh,
                       size_t argc,
                       char **argv);
void cli_set_boardcast_interval_ms(const struct shell *sh,
                                   size_t argc,
                                   char **argv);

SHELL_STATIC_SUBCMD_SET_CREATE(sub_xg27_bthome,
                               SHELL_CMD_ARG(set_device_name, NULL,
                                             "Set the device name\n"
                                             "Note: The device should has less than 9 characters, otherwise it will be truncated.",
                                             cli_set_device_name, 2, 0),
                               SHELL_CMD_ARG(set_encryption_key, NULL,
                                             "Set encryption key\n"
                                             "Note: The encrytion key should has 32 characters.",
                                             cli_set_encryption_key, 2, 0),
                               SHELL_CMD_ARG(set_broadcast, NULL,
                                             "Enable/Disable broadcast\n"
                                             "Enable: 1, Disable: 0",
                                             cli_set_boardcast, 2, 0),
                               SHELL_CMD_ARG(set_broadcast_interval, NULL,
                                             "Set broadcast interval [ms]",
                                             cli_set_boardcast_interval_ms, 2,
                                             0),
                               SHELL_SUBCMD_SET_END);

SHELL_CMD_REGISTER(xg27_bthome,
                   &sub_xg27_bthome,
                   "BTHome v2 - xG27 Dev Kit sensor",
                   NULL);
