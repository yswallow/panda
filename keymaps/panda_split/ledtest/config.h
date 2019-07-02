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

#pragma once

// place overrides here
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

#undef MATRIX_ROWS
#define MATRIX_ROWS 2
#undef MATRIX_SLAVE_ADDRESS
#define MATRIX_SLAVE_ADDRESS { 0x48, 0x4A }

#define PANDA_LED_ENABLE
#define NUMLOCK_LED_ADDRESS 0x4A
#define NUMLOCK_LED_PORT 0 // 0->A, 1->B
#define NUMLOCK_LED_PIN_NUMBER 7 //A7
//#define CAPSLOCK_LED_ADDRESS
//#define SCROLLLOCK_LED_ADDRESS

#define PANDA_BLINK_LED_ADDRESS 0x4E
#define PANDA_BLINK_LED_PORT 1
#define PANDA_BLINK_LED_PIN_NUMBER 0


/* Mousekey config */
#define MOUSEKEY_DELAY             100
#define MOUSEKEY_INTERVAL          50
#define MOUSEKEY_MAX_SPEED         10
#define MOUSEKEY_TIME_TO_MAX       10
#define MOUSEKEY_WHEEL_MAX_SPEED   6
#define MOUSEKEY_WHEEL_TIME_TO_MAX 30

#define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))
#define MAGIC_KEY_EEPROM F
#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS false
#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM true
#define MAGIC_KEY_LAYER0 E
#define MAGIC_KEY_LAYER1 Q
#define MAGIC_KEY_LAYER2 J
#define MAGIC_KEY_LAYER3 N
#define MAGIC_KEY_LAYER0_ALT1 DELETE

#define LAYOUT( \
            A01, A02, A03, A04, A05, \
            A06, A07, A08, A09, A10, \
            A11, A12, A13, A14, A15, \
            A16, A17, A18, A19, A20 \
) \
{ \
            {   A03, A04, A05, A02, A01, KC_NO, KC_NO, KC_NO,      A11, A12, A13, A14, A15, KC_NO, KC_NO, KC_NO }, \
            {   A10, A09, A08, A07, A06, KC_NO, KC_NO, KC_NO,      A16, A17, A18, A19, A20, KC_NO, KC_NO, KC_NO } \
}
