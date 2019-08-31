/* Copyright 2019 %YOUR_NAME%
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keymap_jp.h"
#include "rev1.h"
// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MACRO_LSW1 = SAFE_RANGE, 
  LSW2, LSW3, LSW4, LSW5, LSW6, LSW7, LSW8, LSW9, LSW10, LSW11, LSW12, LSW13, LSW14, LSW15, LSW16, LSW17, LSW18, LSW19, LSW20, LSW21, LSW22, LSW23, LSW24, LSW25, LSW26, LSW27, LSW28, LSW29, LSW30, LSW31, LSW32,
  RSW1, RSW2, RSW3, RSW4, RSW5, RSW6, RSW7, RSW8, RSW9, RSW10, RSW11, RSW12, RSW13, RSW14, RSW15, RSW16, RSW17, RSW18, RSW19, RSW20, RSW21, RSW22, RSW23, RSW24, RSW25, RSW26, RSW27, RSW28, RSW29, RSW30, RSW31, RSW32, RSW33, RSW34, RSW35, RSW36, RSW37, RSW38
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
          MACRO_LSW1, LSW2, LSW3, LSW4, LSW5, LSW6,               RSW1, RSW2, RSW3, RSW4, RSW5, RSW6, RSW7, RSW8, RSW9,
          LSW7, LSW8, LSW9, LSW10, LSW11, LSW12,               RSW10, RSW11, RSW12, RSW13, RSW14, RSW15, RSW16, RSW17, 
          LSW13, LSW14, LSW15, LSW16, LSW17, LSW18,            RSW18, RSW19, RSW20, RSW21, RSW22, RSW23, RSW24, 
          LSW19, LSW20, LSW21, LSW22, LSW23, LSW24,               RSW25, RSW26, RSW27, RSW28, RSW29, RSW30, RSW31, 
          LSW25, LSW26, LSW27, LSW28, LSW30, LSW31,    RSW32, RSW33, RSW34, RSW35, RSW36, RSW37, RSW38,
          \
          KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
          KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
          KC_P4,   KC_P5,   KC_P6,
          KC_P1,   KC_P2,   KC_P3,   KC_PENT,
          KC_P0,   KC_NO,   KC_PDOT
        )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MACRO_LSW1:
      if (record->event.pressed)
        SEND_STRING("LSW1"SS_TAP(X_ENTER));
      break;
    case LSW2:
      if (record->event.pressed)
        SEND_STRING("LSW2\n");
      break;
    case LSW3:
      if (record->event.pressed)
        SEND_STRING("LSW3\n");
      break;
    case LSW4:
      if (record->event.pressed)
        SEND_STRING("LSW4\n");
      break;
    case LSW5:
      if (record->event.pressed)
        SEND_STRING("LSW5\n");
      break;
    case LSW6:
      if (record->event.pressed)
        SEND_STRING("LSW6\n");
      break;
    case LSW7:
      if (record->event.pressed)
        SEND_STRING("LSW7\n");
      break;
    case LSW8:
      if (record->event.pressed)
        SEND_STRING("LSW8\n");
      break;
    case LSW9:
      if (record->event.pressed)
        SEND_STRING("LSW9\n");
      break;
    case LSW10:
      if (record->event.pressed)
        SEND_STRING("LSW10\n");
      break;
    case LSW11:
      if (record->event.pressed)
        SEND_STRING("LSW11\n");
      break;
    case LSW12:
      if (record->event.pressed)
        SEND_STRING("LSW12\n");
      break;
    case LSW13:
      if (record->event.pressed) {
        register_code(KC_CAPS);
        SEND_STRING("LSW13\n");
      } else {
        unregister_code(KC_CAPS);
      }
      break;
    case LSW14:
      if (record->event.pressed)
        SEND_STRING("LSW14\n");
      break;
    case LSW15:
      if (record->event.pressed)
        SEND_STRING("LSW15\n");
      break;
    case LSW16:
      if (record->event.pressed)
        SEND_STRING("LSW16\n");
      break;
    case LSW17:
      if (record->event.pressed)
        SEND_STRING("LSW17\n");
      break;
    case LSW18:
      if (record->event.pressed)
        SEND_STRING("LSW18\n");
      break;
    case LSW19:
      if (record->event.pressed)
        SEND_STRING("LSW19\n");
      break;
    case LSW20:
      if (record->event.pressed)
        SEND_STRING("LSW20\n");
      break;
    case LSW21:
      if (record->event.pressed)
        SEND_STRING("LSW21\n");
      break;
    case LSW22:
      if (record->event.pressed)
        SEND_STRING("LSW22\n");
      break;
    case LSW23:
      if (record->event.pressed)
        SEND_STRING("LSW23\n");
      break;
    case LSW24:
      if (record->event.pressed)
        SEND_STRING("LSW24\n");
      break;
    case LSW25:
      if (record->event.pressed)
        SEND_STRING("LSW25\n");
      break;
    case LSW26:
      if (record->event.pressed)
        SEND_STRING("LSW26\n");
      break;
    case LSW27:
      if (record->event.pressed)
        SEND_STRING("LSW27\n");
      break;
    case LSW28:
      if (record->event.pressed)
        SEND_STRING("LSW28\n");
      break;
    case LSW29:
      if (record->event.pressed)
        SEND_STRING("LSW29\n");
      break;
    case LSW30:
      if (record->event.pressed)
        SEND_STRING("LSW30\n");
      break;
    case LSW31:
      if (record->event.pressed)
        SEND_STRING("LSW31\n");
      break;
    case LSW32:
      if (record->event.pressed)
        SEND_STRING("LSW32\n");
      break;
    case RSW1:
      if (record->event.pressed)
        SEND_STRING("RSW1\n");
      break;
    case RSW2:
      if (record->event.pressed)
        SEND_STRING("RSW2\n");
      break;
    case RSW3:
      if (record->event.pressed)
        SEND_STRING("RSW3\n");
      break;
    case RSW4:
      if (record->event.pressed)
        SEND_STRING("RSW4\n");
      break;
    case RSW5:
      if (record->event.pressed)
        SEND_STRING("RSW5\n");
      break;
    case RSW6:
      if (record->event.pressed)
        SEND_STRING("RSW6\n");
      break;
    case RSW7:
      if (record->event.pressed)
        SEND_STRING("RSW7\n");
      break;
    case RSW8:
      if (record->event.pressed)
        SEND_STRING("RSW8\n");
      break;
    case RSW9:
      if (record->event.pressed)
        SEND_STRING("RSW9\n");
      break;
    case RSW10:
      if (record->event.pressed)
        SEND_STRING("RSW10\n");
      break;
    case RSW11:
      if (record->event.pressed)
        SEND_STRING("RSW11\n");
      break;
    case RSW12:
      if (record->event.pressed)
        SEND_STRING("RSW12\n");
      break;
    case RSW13:
      if (record->event.pressed)
        SEND_STRING("RSW13\n");
      break;
    case RSW14:
      if (record->event.pressed)
        SEND_STRING("RSW14\n");
      break;
    case RSW15:
      if (record->event.pressed)
        SEND_STRING("RSW15\n");
      break;
    case RSW16:
      if (record->event.pressed)
        SEND_STRING("RSW16\n");
      break;
    case RSW17:
      if (record->event.pressed)
        SEND_STRING("RSW17\n");
      break;
    case RSW18:
      if (record->event.pressed)
        SEND_STRING("RSW18\n");
      break;
    case RSW19:
      if (record->event.pressed)
        SEND_STRING("RSW19\n");
      break;
    case RSW20:
      if (record->event.pressed)
        SEND_STRING("RSW20\n");
      break;
    case RSW21:
      if (record->event.pressed)
        SEND_STRING("RSW21\n");
      break;
    case RSW22:
      if (record->event.pressed)
        SEND_STRING("RSW22\n");
      break;
    case RSW23:
      if (record->event.pressed)
        SEND_STRING("RSW23\n");
      break;
    case RSW24:
      if (record->event.pressed)
        SEND_STRING("RSW24\n");
      break;
    case RSW25:
      if (record->event.pressed)
        SEND_STRING("RSW25\n");
      break;
    case RSW26:
      if (record->event.pressed)
        SEND_STRING("RSW26\n");
      break;
    case RSW27:
      if (record->event.pressed)
        SEND_STRING("RSW27\n");
      break;
    case RSW28:
      if (record->event.pressed)
        SEND_STRING("RSW28\n");
      break;
    case RSW29:
      if (record->event.pressed)
        SEND_STRING("RSW29\n");
      break;
    case RSW30:
      if (record->event.pressed)
        SEND_STRING("RSW30\n");
      break;
    case RSW31:
      if (record->event.pressed)
        SEND_STRING("RSW31\n");
      break;
    case RSW32:
      if (record->event.pressed)
        SEND_STRING("RSW32\n");
      break;
    case RSW33:
      if (record->event.pressed)
        SEND_STRING("RSW33\n");
      break;
    case RSW34:
      if (record->event.pressed)
        SEND_STRING("RSW34\n");
      break;
    case RSW35:
      if (record->event.pressed)
        SEND_STRING("RSW35\n");
      break;
    case RSW36:
      if (record->event.pressed)
        SEND_STRING("RSW36\n");
      break;
    case RSW37:
      if (record->event.pressed)
        SEND_STRING("RSW37\n");
      break;
    case RSW38:
      if (record->event.pressed)
        SEND_STRING("RSW38\n");
      break;
  } 
  return true;
}

void matrix_init_user(void) {
    eeconfig_init();
}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
