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
  _NAV
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
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   -  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * | Lock |      |  Esc | Bspc |  Tab |             |Enter |Space |Delete|      |      |
 * `-----------------------------------------------------------------------------------'
 */

  [_QWERTY] = LAYOUT(
    NAV_Q,   KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,       KC_H,    HOME_J,  HOME_K,  HOME_L,  NAV_QT,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    LOCK,    KC_CAPS, KC_ESC,  LOWER,   KC_TAB,     ENT_NUM, RAISE,   KC_DEL,  XXXXXXX, KC_MUTE), 
 
 /* Lower 
 * ,-----------------------------------------------------------------------------------. 
 * |   §  |   !  |  \"  |   #  |   ¤  |             |   /  |   +  |   =  |   ?  |   Å  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |   |  |   %  |   &  |   *  |   \  |             |   {  |   (  |   )  |   }  |   Ø  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |   ^  |  ..  |   '  |   ~  |   `  |             |   <  |   [  |   ]  |   >  |   Æ  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
  [_LOWER] = LAYOUT(
    DK_SECT, DK_EXLM, DK_DQUO, DK_HASH, DK_CURR,    DK_SLSH,    DK_PLUS,    DK_EQL,  DK_QUES, DK_ARNG,
    DK_PIPE, DK_PERC, DK_AMPR, DK_ASTR, DK_BSLS,    DK_LCBR,    DK_LPRN,    DK_RPRN, DK_RCBR, DK_OSTR,
    DK_CIRC, DK_DIAE, DK_ACUT, DK_TILD, DK_GRV,     DK_LABK,    DK_LBRC,    DK_RBRC, DK_RABK, DK_AE,
    _______, _______, _______, _______, _______,    _______,    _______,    KC_VOLD, KC_VOLU, KC_MPLY
  ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |  F11 |  F12 |  F13 |  F14 |  F15 |             |      |      |      |      |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_RAISE] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,     _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, KC_ESC,     _______, _______, _______, _______, _______
  ),


/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      |   7  |   8  |   9  |      |             |      |   7  |   8  |   9  |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      |   4  |   5  |   6  |      |             |      |   4  |   5  |   6  |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |   0  |   1  |   2  |   3  |      |             |      |   1  |   2  |   3  |   0  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_NUM] = LAYOUT(
    XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,    XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,
    XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,    XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,
    KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX,    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_0,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),
  
/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |      | Left | Down |  Up  |Right |             | MS-L | MS-D | MS-U | MS-R |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      | MS-L | MS-D | MS-U | MS-R |             | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      |      |      |      |      |             | Home | Pg Dn| Pg Up| End  |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      |      |      |      |      |             | Btn1 | Btn2 | Btn3 |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_NAV] = LAYOUT(
    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, _______, _______, _______, _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
    _______, _______, _______, _______, _______,    KC_BTN1, KC_BTN2, KC_BTN3, _______, _______
  )
}; 

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
    return false;
}
