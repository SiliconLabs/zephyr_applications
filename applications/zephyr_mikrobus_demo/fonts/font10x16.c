/***************************************************************************//**
 * @file font10x16.c
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
#include <zephyr/kernel.h>
#include <zephyr/types.h>
#include <zephyr/display/cfb.h>

#define CFB_FONTS_FIRST_CHAR  32
#define CFB_FONTS_LAST_CHAR   126

const uint8_t cfb_font10x16[95][20] = {
  /*   */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* ! */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1b,
    0x38, 0x18,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* " */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x38, 0x00,
    0x08, 0x00,
    0x00, 0x00,
    0x38, 0x00,
    0x08, 0x00,
    0x00, 0x00,
  },

  /* # */
  {
    0x00, 0x00,
    0x00, 0x02,
    0x40, 0x1e,
    0xe0, 0x07,
    0x78, 0x02,
    0x40, 0x1e,
    0xe0, 0x07,
    0x78, 0x02,
    0x40, 0x00,
    0x00, 0x00,
  },

  /* $ */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x70, 0x10,
    0x88, 0x10,
    0xfe, 0x7f,
    0x08, 0x11,
    0x08, 0x0e,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* % */
  {
    0x00, 0x00,
    0x70, 0x00,
    0x88, 0x10,
    0x88, 0x0c,
    0x70, 0x03,
    0xc0, 0x0e,
    0x30, 0x11,
    0x08, 0x11,
    0x00, 0x0e,
    0x00, 0x00,
  },

  /* & */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x0e,
    0x70, 0x19,
    0x88, 0x10,
    0xc8, 0x13,
    0x70, 0x0c,
    0x00, 0x1f,
    0x00, 0x10,
    0x00, 0x00,
  },

  /* ' */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x38, 0x00,
    0x08, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* ( */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xc0, 0x0f,
    0x70, 0x38,
    0x18, 0x60,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* ) */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x18, 0x60,
    0x70, 0x38,
    0xc0, 0x0f,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* * */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x10, 0x00,
    0x90, 0x00,
    0xd0, 0x00,
    0x3c, 0x00,
    0xd0, 0x00,
    0x90, 0x00,
    0x10, 0x00,
  },

  /* + */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
    0xe0, 0x0f,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
  },

  /* , */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x38,
    0x00, 0x18,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* - */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x02,
    0x00, 0x02,
    0x00, 0x02,
    0x00, 0x02,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* . */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x18,
    0x00, 0x18,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* / */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x10,
    0x00, 0x0c,
    0x00, 0x03,
    0xc0, 0x00,
    0x30, 0x00,
    0x08, 0x00,
    0x00, 0x00,
  },

  /* 0 */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xe0, 0x07,
    0x38, 0x1c,
    0x08, 0x10,
    0x08, 0x10,
    0x38, 0x1c,
    0xe0, 0x07,
    0x00, 0x00,
  },

  /* 1 */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x20, 0x00,
    0x10, 0x00,
    0xf8, 0x1f,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* 2 */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x10, 0x10,
    0x08, 0x1c,
    0x08, 0x16,
    0x08, 0x13,
    0x98, 0x11,
    0x70, 0x10,
    0x00, 0x00,
  },

  /* 3 */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x10, 0x10,
    0x08, 0x10,
    0x88, 0x10,
    0x88, 0x10,
    0x58, 0x19,
    0x70, 0x0f,
    0x00, 0x00,
  },

  /* 4 */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x06,
    0x80, 0x05,
    0x60, 0x04,
    0x10, 0x04,
    0xf8, 0x1f,
    0x00, 0x04,
    0x00, 0x00,
  },

  /* 5 */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x10,
    0x88, 0x10,
    0x88, 0x10,
    0x88, 0x10,
    0x88, 0x19,
    0x08, 0x0f,
    0x00, 0x00,
  },

  /* 6 */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xc0, 0x07,
    0x70, 0x19,
    0x98, 0x10,
    0x88, 0x10,
    0x88, 0x19,
    0x08, 0x0f,
    0x00, 0x00,
  },

  /* 7 */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x08, 0x00,
    0x08, 0x10,
    0x08, 0x0e,
    0x88, 0x03,
    0x68, 0x00,
    0x18, 0x00,
    0x00, 0x00,
  },

  /* 8 */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x70, 0x0e,
    0xd8, 0x19,
    0x88, 0x10,
    0x88, 0x10,
    0x58, 0x19,
    0x70, 0x0e,
    0x00, 0x00,
  },

  /* 9 */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf0, 0x10,
    0x98, 0x11,
    0x08, 0x11,
    0x08, 0x19,
    0x98, 0x0e,
    0xe0, 0x03,
    0x00, 0x00,
  },

  /* : */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x60, 0x18,
    0x60, 0x18,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* ; */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x60, 0x38,
    0x60, 0x18,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* < */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x01,
    0x80, 0x02,
    0x80, 0x02,
    0x40, 0x04,
    0x40, 0x04,
    0x20, 0x08,
    0x00, 0x00,
  },

  /* = */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x80, 0x02,
    0x80, 0x02,
    0x80, 0x02,
    0x80, 0x02,
    0x80, 0x02,
    0x80, 0x02,
    0x00, 0x00,
  },

  /* > */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x20, 0x08,
    0x40, 0x04,
    0x40, 0x04,
    0x80, 0x02,
    0x80, 0x02,
    0x00, 0x01,
    0x00, 0x00,
  },

  /* ? */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x18, 0x00,
    0x08, 0x00,
    0x08, 0x1a,
    0x88, 0x19,
    0xd8, 0x00,
    0x70, 0x00,
    0x00, 0x00,
  },

  /* @ */
  {
    0x00, 0x00,
    0xc0, 0x0f,
    0x30, 0x18,
    0x88, 0x23,
    0x48, 0x24,
    0x48, 0x24,
    0xc8, 0x23,
    0x10, 0x24,
    0xe0, 0x03,
    0x00, 0x00,
  },

  /* A */
  {
    0x00, 0x00,
    0x00, 0x10,
    0x00, 0x0e,
    0xc0, 0x03,
    0x38, 0x02,
    0x38, 0x02,
    0xc0, 0x03,
    0x00, 0x0e,
    0x00, 0x10,
    0x00, 0x00,
  },

  /* B */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1f,
    0x88, 0x10,
    0x88, 0x10,
    0x88, 0x10,
    0x58, 0x19,
    0x70, 0x0f,
    0x00, 0x00,
  },

  /* C */
  {
    0x00, 0x00,
    0x00, 0x00,
    0xe0, 0x07,
    0x30, 0x0c,
    0x18, 0x18,
    0x08, 0x10,
    0x08, 0x10,
    0x18, 0x10,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* D */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1f,
    0x08, 0x10,
    0x08, 0x10,
    0x18, 0x18,
    0x30, 0x0c,
    0xe0, 0x07,
    0x00, 0x00,
  },

  /* E */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1f,
    0x88, 0x10,
    0x88, 0x10,
    0x88, 0x10,
    0x88, 0x10,
    0x88, 0x10,
    0x00, 0x00,
  },

  /* F */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1f,
    0x88, 0x00,
    0x88, 0x00,
    0x88, 0x00,
    0x88, 0x00,
    0x88, 0x00,
    0x00, 0x00,
  },

  /* G */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xe0, 0x07,
    0x30, 0x0c,
    0x18, 0x10,
    0x88, 0x10,
    0x88, 0x10,
    0x88, 0x1f,
    0x00, 0x00,
  },

  /* H */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1f,
    0x80, 0x00,
    0x80, 0x00,
    0x80, 0x00,
    0x80, 0x00,
    0xf8, 0x1f,
    0x00, 0x00,
  },

  /* I */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x08, 0x10,
    0x08, 0x10,
    0xf8, 0x1f,
    0x08, 0x10,
    0x08, 0x10,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* J */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x10,
    0x00, 0x10,
    0x00, 0x10,
    0x00, 0x18,
    0xf8, 0x0f,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* K */
  {
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1f,
    0x00, 0x01,
    0x80, 0x00,
    0x40, 0x03,
    0x30, 0x06,
    0x18, 0x18,
    0x08, 0x10,
    0x00, 0x00,
  },

  /* L */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1f,
    0x00, 0x10,
    0x00, 0x10,
    0x00, 0x10,
    0x00, 0x10,
    0x00, 0x10,
    0x00, 0x00,
  },

  /* M */
  {
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1f,
    0x70, 0x00,
    0x80, 0x07,
    0x00, 0x1c,
    0x80, 0x03,
    0x70, 0x00,
    0xf8, 0x1f,
    0x00, 0x00,
  },

  /* N */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1f,
    0x30, 0x00,
    0xc0, 0x00,
    0x00, 0x03,
    0x00, 0x0c,
    0xf8, 0x1f,
    0x00, 0x00,
  },

  /* O */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xe0, 0x07,
    0x38, 0x1c,
    0x08, 0x10,
    0x08, 0x10,
    0x38, 0x1c,
    0xe0, 0x07,
    0x00, 0x00,
  },

  /* P */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1f,
    0x08, 0x01,
    0x08, 0x01,
    0x08, 0x01,
    0x98, 0x01,
    0xf0, 0x00,
    0x00, 0x00,
  },

  /* Q */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xe0, 0x07,
    0x38, 0x1c,
    0x08, 0x10,
    0x08, 0x10,
    0x38, 0x6c,
    0xe0, 0xc7,
    0x00, 0x00,
  },

  /* R */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x1f,
    0x08, 0x01,
    0x08, 0x01,
    0x08, 0x03,
    0x98, 0x07,
    0xf0, 0x18,
    0x00, 0x10,
  },

  /* S */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x70, 0x10,
    0xd8, 0x10,
    0x88, 0x10,
    0x88, 0x11,
    0x08, 0x19,
    0x18, 0x0e,
    0x00, 0x00,
  },

  /* T */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x08, 0x00,
    0x08, 0x00,
    0x08, 0x00,
    0xf8, 0x1f,
    0x08, 0x00,
    0x08, 0x00,
    0x08, 0x00,
    0x00, 0x00,
  },

  /* U */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x0f,
    0x00, 0x18,
    0x00, 0x10,
    0x00, 0x10,
    0x00, 0x18,
    0xf8, 0x0f,
    0x00, 0x00,
  },

  /* V */
  {
    0x00, 0x00,
    0x08, 0x00,
    0x70, 0x00,
    0x80, 0x03,
    0x00, 0x1c,
    0x00, 0x1c,
    0x80, 0x03,
    0x70, 0x00,
    0x08, 0x00,
    0x00, 0x00,
  },

  /* W */
  {
    0x00, 0x00,
    0x78, 0x00,
    0xc0, 0x1f,
    0x00, 0x0e,
    0xc0, 0x01,
    0x80, 0x01,
    0x00, 0x06,
    0x80, 0x1f,
    0x78, 0x00,
    0x00, 0x00,
  },

  /* X */
  {
    0x00, 0x00,
    0x08, 0x10,
    0x18, 0x08,
    0x60, 0x06,
    0xc0, 0x01,
    0xc0, 0x03,
    0x60, 0x06,
    0x18, 0x18,
    0x08, 0x10,
    0x00, 0x00,
  },

  /* Y */
  {
    0x00, 0x00,
    0x08, 0x00,
    0x38, 0x00,
    0xe0, 0x00,
    0x00, 0x1f,
    0xc0, 0x00,
    0x30, 0x00,
    0x08, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* Z */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x08, 0x18,
    0x08, 0x1e,
    0x08, 0x13,
    0xc8, 0x10,
    0x78, 0x10,
    0x18, 0x10,
    0x00, 0x00,
  },

  /* [ */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xf8, 0x7f,
    0x08, 0x40,
    0x08, 0x40,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* \ */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x08, 0x00,
    0x30, 0x00,
    0xc0, 0x00,
    0x00, 0x03,
    0x00, 0x0c,
    0x00, 0x10,
    0x00, 0x00,
  },

  /* ] */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x08, 0x40,
    0x08, 0x40,
    0xf8, 0x7f,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* ^ */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x01,
    0xc0, 0x00,
    0x38, 0x00,
    0x38, 0x00,
    0xc0, 0x00,
    0x00, 0x01,
    0x00, 0x00,
  },

  /* _ */
  {
    0x00, 0x40,
    0x00, 0x40,
    0x00, 0x40,
    0x00, 0x40,
    0x00, 0x40,
    0x00, 0x40,
    0x00, 0x40,
    0x00, 0x40,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* ` */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x04, 0x00,
    0x0c, 0x00,
    0x08, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* a */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x0e,
    0x20, 0x13,
    0x20, 0x11,
    0x20, 0x11,
    0x60, 0x09,
    0xc0, 0x1f,
    0x00, 0x00,
  },

  /* b */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xfc, 0x1f,
    0x40, 0x08,
    0x20, 0x10,
    0x20, 0x10,
    0x60, 0x18,
    0xc0, 0x0f,
    0x00, 0x00,
  },

  /* c */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x80, 0x07,
    0xc0, 0x08,
    0x20, 0x10,
    0x20, 0x10,
    0x20, 0x10,
    0x20, 0x10,
    0x00, 0x00,
  },

  /* d */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xc0, 0x0f,
    0x60, 0x18,
    0x20, 0x10,
    0x20, 0x10,
    0x40, 0x08,
    0xfc, 0x1f,
    0x00, 0x00,
  },

  /* e */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x80, 0x07,
    0x60, 0x09,
    0x20, 0x11,
    0x20, 0x11,
    0x60, 0x11,
    0xc0, 0x19,
    0x00, 0x00,
  },

  /* f */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x20, 0x00,
    0x20, 0x00,
    0xf8, 0x1f,
    0x24, 0x00,
    0x24, 0x00,
    0x24, 0x00,
    0x00, 0x00,
  },

  /* g */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xc0, 0x7d,
    0x20, 0x9a,
    0x20, 0x8a,
    0x20, 0x8a,
    0x20, 0x8a,
    0xe0, 0xc9,
    0x20, 0x70,
  },

  /* h */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xfc, 0x1f,
    0x40, 0x00,
    0x20, 0x00,
    0x20, 0x00,
    0x60, 0x00,
    0xc0, 0x1f,
    0x00, 0x00,
  },

  /* i */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x10,
    0x20, 0x10,
    0x20, 0x10,
    0xec, 0x1f,
    0x00, 0x10,
    0x00, 0x10,
    0x00, 0x00,
  },

  /* j */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x80,
    0x20, 0x80,
    0x20, 0x80,
    0x20, 0xc0,
    0xec, 0x7f,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* k */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xfc, 0x1f,
    0x00, 0x02,
    0x00, 0x03,
    0x80, 0x06,
    0x40, 0x0c,
    0x20, 0x18,
    0x00, 0x10,
  },

  /* l */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x10,
    0x04, 0x10,
    0x04, 0x10,
    0xfc, 0x1f,
    0x00, 0x10,
    0x00, 0x10,
    0x00, 0x00,
  },

  /* m */
  {
    0x00, 0x00,
    0x00, 0x00,
    0xe0, 0x1f,
    0x40, 0x00,
    0x20, 0x00,
    0xc0, 0x1f,
    0x20, 0x00,
    0x20, 0x00,
    0xc0, 0x1f,
    0x00, 0x00,
  },

  /* n */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xe0, 0x1f,
    0x40, 0x00,
    0x20, 0x00,
    0x20, 0x00,
    0x60, 0x00,
    0xc0, 0x1f,
    0x00, 0x00,
  },

  /* o */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x80, 0x07,
    0x60, 0x18,
    0x20, 0x10,
    0x20, 0x10,
    0x60, 0x18,
    0x80, 0x07,
    0x00, 0x00,
  },

  /* p */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xe0, 0xff,
    0x40, 0x08,
    0x20, 0x10,
    0x20, 0x10,
    0x60, 0x18,
    0xc0, 0x0f,
    0x00, 0x00,
  },

  /* q */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xc0, 0x0f,
    0x60, 0x18,
    0x20, 0x10,
    0x20, 0x10,
    0x40, 0x08,
    0xe0, 0xff,
    0x00, 0x00,
  },

  /* r */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xe0, 0x1f,
    0x40, 0x00,
    0x20, 0x00,
    0x20, 0x00,
    0x20, 0x00,
    0x00, 0x00,
  },

  /* s */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xc0, 0x10,
    0x20, 0x11,
    0x20, 0x11,
    0x20, 0x13,
    0x20, 0x12,
    0x60, 0x0e,
    0x00, 0x00,
  },

  /* t */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x10, 0x00,
    0x10, 0x00,
    0xfc, 0x07,
    0x10, 0x08,
    0x10, 0x08,
    0x10, 0x08,
    0x00, 0x00,
  },

  /* u */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xe0, 0x0f,
    0x00, 0x18,
    0x00, 0x10,
    0x00, 0x10,
    0x00, 0x08,
    0xe0, 0x1f,
    0x00, 0x00,
  },

  /* v */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x60, 0x00,
    0xc0, 0x03,
    0x00, 0x1c,
    0x00, 0x1c,
    0xc0, 0x03,
    0x60, 0x00,
    0x00, 0x00,
  },

  /* w */
  {
    0xe0, 0x03,
    0x00, 0x1c,
    0x00, 0x07,
    0xe0, 0x00,
    0xe0, 0x00,
    0x00, 0x0f,
    0x00, 0x1c,
    0xe0, 0x03,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* x */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x20, 0x10,
    0x60, 0x0c,
    0x80, 0x07,
    0x80, 0x07,
    0x60, 0x0c,
    0x20, 0x10,
    0x00, 0x00,
  },

  /* y */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x60, 0x80,
    0xc0, 0x83,
    0x00, 0x7c,
    0x00, 0x1c,
    0xc0, 0x03,
    0x60, 0x00,
    0x00, 0x00,
  },

  /* z */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x20, 0x18,
    0x20, 0x1c,
    0x20, 0x16,
    0x20, 0x11,
    0xe0, 0x10,
    0x60, 0x10,
    0x00, 0x00,
  },

  /* { */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x01,
    0x00, 0x01,
    0xf0, 0x3e,
    0x08, 0x40,
    0x08, 0x40,
    0x00, 0x00,
  },

  /* | */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0xfc, 0xff,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* } */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x08, 0x40,
    0x08, 0x40,
    0xf0, 0x3e,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x00,
    0x00, 0x00,
  },

  /* ~ */
  {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x80, 0x00,
    0x80, 0x00,
    0x80, 0x00,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x00,
  },
};

FONT_ENTRY_DEFINE(font10x16, 10, 16,
                  CFB_FONT_MONO_VPACKED,
                  cfb_font10x16,
                  CFB_FONTS_FIRST_CHAR,
                  CFB_FONTS_LAST_CHAR
                  );
