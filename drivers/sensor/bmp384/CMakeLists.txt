#
# Copyright (c) 2020 Facebook, Inc. and its affiliates
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_library()
zephyr_library_property(ALLOW_EMPTY TRUE)

zephyr_library_sources_ifdef(CONFIG_BMP384 bmp384.c bmp384_i2c.c)
