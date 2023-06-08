/* Copyright 2022 Caleb Lightfoot
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
#include "keymap_danish.h"


enum lesovoz_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUM,
  _NAV,
  _ADJUST
};

#define LOWER LT(_LOWER, KC_BSPC)
#define RAISE LT(_RAISE, KC_SPC)
#define ENT_NUM LT(_NUM, KC_ENT)

#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define NAV_QT LT(_NAV, DK_QUOT)
#define NAV_Q  LT(_NAV, DK_Q)

// Lock (Pop-OS)
#define LOCK G(KC_ESC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   -  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Lock |      |  Esc | Bspc |  Tab |             |Enter |Space |Delete|      |      |
 * `-----------------------------------------------------------------------------------'
 */

  [_QWERTY] = LAYOUT(
      NAV_Q,   KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,       KC_H,    HOME_J,  HOME_K,  HOME_L,  NAV_QT,
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
      LOCK,    XXXXXXX, KC_ESC,  LOWER,   KC_TAB,     ENT_NUM, RAISE,   KC_DEL,  XXXXXXX, KC_MUTE
),

  [_LOWER] = LAYOUT(
  	  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
  	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_ENT,
  	  KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,
  	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS )
};
