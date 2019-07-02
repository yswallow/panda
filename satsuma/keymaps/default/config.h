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

#define DEBUG_MATRIX_SCAN_RATE

// Command settings
#define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))
#define MAGIC_KEY_EEPROM F
#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS false
#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM true
#define MAGIC_KEY_LAYER0 Q
#define MAGIC_KEY_LAYER1 A
#define MAGIC_KEY_LAYER0_ALT1 DELETE

// Bootmagic settings
#define BOOTMAGIC_KEY_DEFAULT_LAYER_1 KC_A
#define BOOTMAGIC_KEY_DEFAULT_LAYER_0 KC_Q

