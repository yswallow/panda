/*
Copyright 2019 %YOUR_NAME%

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
/*
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    yswallow
#define PRODUCT         panda_split
#define DESCRIPTION     A custom keyboard
*/
//#define CATERINA_BOOTLOADER
/* key matrix size */
//#define MATRIX_ROWS 4
#define MATRIX_COLS 16

//#define MATRIX_SLAVE_ADDRESS { 0x40, 0x42, 0x44, 0x46 }

#define MATRIX_INIT_TIMEOUT 0x00FF //[ms]
#define MATRIX_SCAN_TIMEOUT 10 //[ms]
/* COL2ROW, ROW2COL*/
//#define DIODE_DIRECTION COL2ROW
#define QMK_LED C7


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5
