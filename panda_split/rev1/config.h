#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0001
#define MANUFACTURER    yswallow
#define PRODUCT         Satsuma JP SMD rev1
#define DESCRIPTION     Split JIS keyboard

#define MATRIX_ROWS 7
#define MATRIX_SLAVE_ADDRESS { 0x40, 0x42, 0x48, 0x4A, 0x4C, 0x44, 0x46 }
