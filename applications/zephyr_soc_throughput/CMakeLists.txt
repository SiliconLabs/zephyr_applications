# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(zephyr_soc_throughput_peripheral)

target_sources(app PRIVATE src/main.c)
target_sources(app PRIVATE src/app.c)
target_sources(app PRIVATE src/peripheral/throughput_peripheral.c)
target_sources(app PRIVATE src/central/throughput_central.c)
target_sources(app PRIVATE src/central/throughput_central_interface.c)
target_sources(app PRIVATE src/throughput_gattdb.c)
target_sources(app PRIVATE src/cli_command_table.c)
target_sources(app PRIVATE src/throughput_ui_log.c)
target_sources(app PRIVATE src/throughput_ui_common.c)
target_sources(app PRIVATE src/bt_event.c)

target_include_directories(app PRIVATE src)
target_include_directories(app PRIVATE src/central)
target_include_directories(app PRIVATE src/peripheral)
