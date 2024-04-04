# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
# set(CMAKE_OBJECT_PATH_MAX 300)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(xg27_cli)

target_sources(app PRIVATE src/main.c)
target_sources(app PRIVATE src/cli_command_table.c)
target_sources(app PRIVATE src/bthome_v2.c)
target_sources(app PRIVATE src/main.c)


