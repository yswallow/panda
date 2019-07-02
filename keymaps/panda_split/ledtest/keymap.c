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
#include "keymap_jp.h"
#include "panda.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

#define _EUCALYN 0
#define _QWERTY 1
#define _EUCALYN_J 2
#define _QWERTY_J 3
//#define _TRANS 4
#define _LOWER 8
#define _RAISE 9
#define _LOWER_J 10
#define _RAISE_J 11
#define _ARROW 12
#define _MOUSE 13
#define _ADJUST 16

#define KC_____ KC_TRNS
#define KC_RESET RESET
#define KC_B_BK LALT(KC_LEFT) //ブラウザバック
#define KC_ADJUST MO(_ADJUST)
#define KC_S_ADJ  LT(_ADJUST, KC_SPC)
#define ____ KC_TRNS
#define KC_MOUSE MO(_MOUSE)
#define KC_ARROW MO(_ARROW)
#define KC_DF TO(_TRANS)
#define KC_CTL_L LM(_TRANS, KC_LCTL)
#define KC_REDO LCTL(KC_Z)
#define KC_FDEL S(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_EUCALYN] = LAYOUT( \
        KC_P7, KC_P8, KC_P9, KC_NLCK, KC_DELETE,
        KC_P4, KC_P5, KC_P6, KC_TAB, KC_BSPACE,
        KC_P1, KC_P2, KC_P3, KC_LSFT, LCTL(KC_W),
        KC_P0, KC_PDOT, KC_ENT, KC_ESC, KC_LCTL
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

uint8_t panda_scan_count = 0;

void matrix_init_user(void) {
    panda_led_init(PANDA_BLINK_LED_ADDRESS, PANDA_BLINK_LED_PORT, PANDA_BLINK_LED_PIN_NUMBER);
    panda_led_set( PANDA_BLINK_LED_ADDRESS, PANDA_BLINK_LED_PORT, PANDA_BLINK_LED_PIN_NUMBER, true);
}

void matrix_scan_user(void) {
    panda_scan_count++;
    if(panda_scan_count==20) {
        panda_led_set( PANDA_BLINK_LED_ADDRESS, PANDA_BLINK_LED_PORT, PANDA_BLINK_LED_PIN_NUMBER, true);
        //SEND_STRING("SCAN\r\n");
    } else if(panda_scan_count==25) {
        panda_led_set( PANDA_BLINK_LED_ADDRESS, PANDA_BLINK_LED_PORT, PANDA_BLINK_LED_PIN_NUMBER, false);
        panda_scan_count = 0;
    }
}

void led_set_user(uint8_t usb_led) {
    
}
