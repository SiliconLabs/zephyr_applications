# # SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(zephyr_mikrobus_demo)

target_sources(app PRIVATE src/main.c)
target_sources(app PRIVATE src/app.c)
target_sources(app PRIVATE fonts/font5x7.c)
target_sources(app PRIVATE fonts/font8x8.c)
target_sources(app PRIVATE fonts/font10x16.c)
target_sources(app PRIVATE fonts/font15x24.c)
target_sources(app PRIVATE fonts/font20x32.c)

target_include_directories(app PRIVATE ./)

