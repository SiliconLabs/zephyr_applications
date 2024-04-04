#include <stdlib.h>

#include "zephyr/shell/shell.h"

// Provide function declarations
void cli_throughput_central_stop(const struct shell *sh,
                                 size_t argc,
                                 char **argv);
void cli_throughput_central_start(const struct shell *sh,
                                  size_t argc,
                                  char **argv);
void cli_throughput_central_status(const struct shell *sh,
                                   size_t argc,
                                   char **argv);
void cli_throughput_central_mode_set(const struct shell *sh,
                                     size_t argc,
                                     char **argv);
void cli_throughput_central_mode_get(const struct shell *sh,
                                     size_t argc,
                                     char **argv);
void cli_throughput_central_tx_power_set(const struct shell *sh,
                                         size_t argc,
                                         char **argv);
void cli_throughput_central_tx_power_get(const struct shell *sh,
                                         size_t argc,
                                         char **argv);
void cli_throughput_central_data_set(const struct shell *sh,
                                     size_t argc,
                                     char **argv);
void cli_throughput_central_data_get(const struct shell *sh,
                                     size_t argc,
                                     char **argv);
void cli_throughput_central_phy_scan_set(const struct shell *sh,
                                         size_t argc,
                                         char **argv);
void cli_throughput_central_phy_conn_set(const struct shell *sh,
                                         size_t argc,
                                         char **argv);
void cli_throughput_central_phy_get(const struct shell *sh,
                                    size_t argc,
                                    char **argv);
void cli_throughput_central_connection_set(const struct shell *sh,
                                           size_t argc,
                                           char **argv);
void cli_throughput_central_connection_get(const struct shell *sh,
                                           size_t argc,
                                           char **argv);
void cli_throughput_central_allowlist_add(const struct shell *sh,
                                          size_t argc,
                                          char **argv);
void cli_throughput_central_allowlist_clear(const struct shell *sh,
                                            size_t argc,
                                            char **argv);
void cli_throughput_central_allowlist_get(const struct shell *sh,
                                          size_t argc,
                                          char **argv);
void cli_throughput_peripheral_stop(const struct shell *sh,
                                    size_t argc,
                                    char **argv);
void cli_throughput_peripheral_start(const struct shell *sh,
                                     size_t argc,
                                     char **argv);
void cli_throughput_peripheral_status(const struct shell *sh,
                                      size_t argc,
                                      char **argv);
void cli_throughput_peripheral_mode_set(const struct shell *sh,
                                        size_t argc,
                                        char **argv);
void cli_throughput_peripheral_mode_get(const struct shell *sh,
                                        size_t argc,
                                        char **argv);
void cli_throughput_peripheral_tx_power_set(const struct shell *sh,
                                            size_t argc,
                                            char **argv);
void cli_throughput_peripheral_tx_power_get(const struct shell *sh,
                                            size_t argc,
                                            char **argv);
void cli_throughput_peripheral_data_set(const struct shell *sh,
                                        size_t argc,
                                        char **argv);
void cli_throughput_peripheral_data_get(const struct shell *sh,
                                        size_t argc,
                                        char **argv);
void cli_switch_to_central(const struct shell *sh, size_t argc, char **argv);
void cli_switch_to_peripheral(const struct shell *sh, size_t argc, char **argv);

SHELL_STATIC_SUBCMD_SET_CREATE(sub_throughput_peripheral,
                               SHELL_CMD_ARG(start, NULL,
                                             "Starts transmission\n"
                                             "Type: 1: notification, 2: indication",
                                             cli_throughput_peripheral_start, 2,
                                             0),
                               SHELL_CMD(stop, NULL, "Stops transmission",
                                         cli_throughput_peripheral_stop),
                               SHELL_CMD(status, NULL, "Prints current status",
                                         cli_throughput_peripheral_status),
                               SHELL_CMD_ARG(mode_set, NULL,
                                             "Set transmission mode\n"
                                             "Mode: 0:Continous, 1:Fixed size, 2: Fixed time\n"
                                             "Value to set (in case of fixed time/size)",
                                             cli_throughput_peripheral_mode_set,
                                             3, 0),
                               SHELL_CMD(mode_get, NULL,
                                         "Get transmission mode, 0:Continous, 1:Fixed size, 2: Fixed time",
                                         cli_throughput_peripheral_mode_get),
                               SHELL_CMD_ARG(tx_power_set, NULL,
                                             "Set power in dBm\n"
                                             "Enable adaptive power control",
                                             cli_throughput_peripheral_tx_power_set,
                                             4, 0),
                               SHELL_CMD(tx_power_get, NULL,
                                         "Read power settings",
                                         cli_throughput_peripheral_tx_power_get),
                               SHELL_CMD_ARG(data_set, NULL,
                                             "Set data sizes\n"
                                             "Maximum MTU size\n"
                                             "Indication transfer size\n"
                                             "Notification transfer size",
                                             cli_throughput_peripheral_data_set,
                                             4, 0),
                               SHELL_CMD(data_get, NULL,
                                         "Read data settings",
                                         cli_throughput_peripheral_data_get),
                               SHELL_SUBCMD_SET_END
                               );

SHELL_STATIC_SUBCMD_SET_CREATE(sub_throughput_central,
                               SHELL_CMD_ARG(start, NULL,
                                             "Starts remote transmission\n"
                                             "Type: 1: notification, 2: indication",
                                             cli_throughput_peripheral_start, 2,
                                             0),
                               SHELL_CMD(stop, NULL,
                                         "Stops remote transmission",
                                         cli_throughput_peripheral_stop),
                               SHELL_CMD(status, NULL, "Prints current status",
                                         cli_throughput_peripheral_status),
                               SHELL_CMD_ARG(mode_set, NULL,
                                             "Set reception mode\n"
                                             "Mode: 0:Continous, 1:Fixed size, 2: Fixed time\n"
                                             "Value to set (in case of fixed time/size)",
                                             cli_throughput_peripheral_mode_set,
                                             2, 0),
                               SHELL_CMD(mode_get, NULL,
                                         "Get reception mode, 0:Continous, 1:Fixed size, 2: Fixed time",
                                         cli_throughput_peripheral_mode_get),
                               SHELL_CMD_ARG(tx_power_set, NULL,
                                             "Set power in dBm\n"
                                             "Enable adaptive power control",
                                             cli_throughput_central_tx_power_set,
                                             2, 0),
                               SHELL_CMD(tx_power_get, NULL,
                                         "Read power settings",
                                         cli_throughput_central_tx_power_get),
                               SHELL_CMD_ARG(data_set, NULL,
                                             "Set data sizes\n"
                                             "Maximum MTU size\n",
                                             cli_throughput_central_data_set, 2,
                                             0),
                               SHELL_CMD(data_get, NULL,
                                         "Read data settings",
                                         cli_throughput_central_data_get),
                               SHELL_CMD_ARG(phy_scan_set, NULL,
                                             "Set PHY used for scanning\n"
                                             "Scan PHY, 1:1M 4:Coded PHY, 5:1M and Coded\n",
                                             cli_throughput_central_phy_scan_set,
                                             2, 0),
                               SHELL_CMD_ARG(phy_conn_set, NULL,
                                             "Set PHY used for the connection, 1:1M 2:2M 4:Coded 125k, 8:Coded 500k PHY\n"
                                             "Connection PHY\n",
                                             cli_throughput_central_phy_conn_set,
                                             2, 0),
                               SHELL_CMD(phy_get, NULL,
                                         "Read PHY settings for scan and connection, 1:1M 2:2M 4:Coded 125k, 8:Coded 500k PHY",
                                         cli_throughput_central_phy_get),
                               SHELL_CMD_ARG(connection_set, NULL,
                                             "Set connection settings\n"
                                             "Minimum connection interval (in 1.25 ms steps)\n"
                                             "Maximum connection interval (in 1.25 ms steps)\n"
                                             "Responder latency (in connection intervals)\n"
                                             "Supervision timeout (in 10 ms steps)",
                                             cli_throughput_central_connection_set,
                                             2, 0),
                               SHELL_CMD(connection_get, NULL,
                                         "Read connection settings",
                                         cli_throughput_central_connection_get),
                               SHELL_CMD_ARG(allowlist_add, NULL,
                                             "Add address to allowlist\n"
                                             "Bluetooth address in 'XX:XX:XX:XX:XX:XX' format\n",
                                             cli_throughput_central_allowlist_add,
                                             2, 0),
                               SHELL_CMD(allowlist_clear, NULL,
                                         "Clear allowlist",
                                         cli_throughput_central_allowlist_clear),
                               SHELL_CMD(allowlist_get, NULL,
                                         "Read allowlist table",
                                         cli_throughput_central_allowlist_get),
                               SHELL_SUBCMD_SET_END
                               );

SHELL_CMD_REGISTER(throughput_peripheral,
                   &sub_throughput_peripheral,
                   "Throughput Peripheral",
                   NULL);
SHELL_CMD_REGISTER(throughput_central,
                   &sub_throughput_central,
                   "Throughput Central",
                   NULL);
SHELL_CMD_REGISTER(switch_to_central,
                   NULL,
                   "Switch to central",
                   cli_switch_to_central);
SHELL_CMD_REGISTER(switch_to_peripheral,
                   NULL,
                   "Switch to peripheral",
                   cli_switch_to_peripheral);

// /* Creating subcommands (level 1 command) array for command "demo". */
// SHELL_STATIC_SUBCMD_SET_CREATE(sub_demo,
//         SHELL_CMD(params, NULL, "Print params command.", cmd_demo_params),
//         SHELL_CMD(ping,   NULL, "Ping command.", cmd_demo_ping),
//         SHELL_SUBCMD_SET_END
// );
// /* Creating root (level 0) command "demo" */
// SHELL_CMD_REGISTER(demo, &sub_demo, "Demo commands", NULL);
