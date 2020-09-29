/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EMACS,
    _CONTROL
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define EMACS  MO(_EMACS)
#define LT_SPC LT(_CONTROL, KC_SPC)

#define TG_IME  A(KC_GRV)
#define KC_CENT C(KC_ENT)
#define KC_BOT  C(KC_HOME)
#define KC_EOT  C(KC_END)
#define KC_SFWD (KC_F3)
#define KC_SBWD S(KC_F3)
#define KC_OTRW A(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    EMACS,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
                                            KC_LCTL,  LOWER,    LT_SPC,   RAISE,    KC_LALT
  ),
  
  [_LOWER] = LAYOUT_reviung41(
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_PGUP,  KC_PGDN,  KC_DEL,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LPRN,            KC_RPRN,  KC_UNDS,  KC_PLUS,  KC_HOME,  KC_UP,    KC_END,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LCBR,            KC_RCBR,  KC_PIPE,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,
                                            _______,  _______,  KC_ENT,   _______,  _______
  ),
  
  [_RAISE] = LAYOUT_reviung41(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_INS,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_MINS,  KC_EQL,   XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,            KC_RBRC,  KC_BSLS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,  _______,  KC_BSPC,  _______,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,              KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    XXXXXXX,  RGB_MOD,  RGB_SAI,  RGB_HUI,  RGB_VAI,  RGB_TOG,            KC_MUTE,  KC_VOLU,  KC_BRIU,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  RGB_RMOD, RGB_SAD,  RGB_HUD,  RGB_VAD,  XXXXXXX,            XXXXXXX,  KC_VOLD,  KC_BRID,  XXXXXXX,  XXXXXXX,  RESET,
                                            _______,  _______,  XXXXXXX,  _______,  _______
  ),
  
  [_EMACS] = LAYOUT_reviung41(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_END,   KC_SBWD,  XXXXXXX,            XXXXXXX,  XXXXXXX,  KC_TAB,   KC_OTRW,  KC_UP,    TG_IME,
    XXXXXXX,  KC_HOME,  KC_SFWD,  KC_DEL,   KC_RGHT,  XXXXXXX,            KC_BSPC,  KC_CENT,  XXXXXXX,  KC_PGUP,  KC_PGDN,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,            KC_DOWN,  KC_ENT,   KC_BOT,   KC_EOT,   XXXXXXX,  XXXXXXX,
                                            _______,  _______,  XXXXXXX,  _______,  _______
  ),
  
  [_CONTROL] = LAYOUT_reviung41(
    KC_TAB,   _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                            KC_RALT,  KC_LGUI,  XXXXXXX,  KC_APP,   KC_RCTL
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

