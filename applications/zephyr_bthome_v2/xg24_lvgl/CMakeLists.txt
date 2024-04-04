# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
# set(CMAKE_OBJECT_PATH_MAX 300)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(xg24_sensors_lgvl)

target_sources(app PRIVATE src/main.c)
target_sources(app PRIVATE src/application_ui/ui_events.c)
target_sources(app PRIVATE src/application_ui/ui_helpers.c)
target_sources(app PRIVATE src/application_ui/ui.c)
target_sources(app PRIVATE src/application_ui/components/ui_comp_hook.c)
target_sources(app PRIVATE src/application_ui/images/ui_img_25_78_png.c)
target_sources(app PRIVATE src/application_ui/images/ui_img_25_png.c)
target_sources(app PRIVATE src/application_ui/images/ui_img_30_60_png.c)
target_sources(app PRIVATE src/application_ui/images/ui_img_35_67_png.c)
target_sources(app PRIVATE src/application_ui/images/ui_img_1597985048.c)
target_sources(app PRIVATE src/application_ui/screens/ui_ApplicationScreen.c)
target_sources(app PRIVATE src/application_ui/screens/ui_BootScreen.c)
target_sources(app PRIVATE src/application_ui/screens/ui_SettingScreen.c)
target_include_directories(app PRIVATE ./
                                       src/application_ui)
target_sources(app PRIVATE src/bthome_v2.c)
