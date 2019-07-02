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
  ZHTG = SAFE_RANGE,
  RALT,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
          JP_ZHTG, KC_1, KC_2, KC_3, KC_4, KC_5,        KC_6, KC_7, KC_8, KC_9, KC_0, JP_MINS, JP_CIRC, JP_YEN, KC_BSPC,
          KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,               KC_Y, KC_U, KC_I, KC_O, KC_P, JP_AT, JP_LBRC, KC_ENT,
          KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,                KC_H, KC_J, KC_K, KC_L, JP_SCLN, JP_COLN, JP_RBRC,
          KC_LSFT,       KC_Z, KC_X, KC_C, KC_V, KC_B,               KC_N, KC_M, KC_COMM, KC_DOT, JP_SLSH, JP_BSLS, KC_RSFT,
          KC_LCTL, KC_LGUI, KC_LALT, KC_MHEN, KC_SPC, KC_SPC,    KC_SPC, KC_SPC, JP_HENK, JP_KANA, RALT, KC_APP, KC_RCTL,
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
    case RALT:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("RALT");
      } else {
        // when keycode QMKBEST is released
      }
      break;
  } 
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
