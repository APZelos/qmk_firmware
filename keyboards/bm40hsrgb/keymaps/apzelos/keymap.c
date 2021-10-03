/* Copyright 2020 tominabox1
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

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum tap_dance {
  TD_RESET
};

void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    // Reset the keyboard if you tap the key more than three times
    reset_keyboard();
    reset_tap_dance(state);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset)
};

#define LOWER OSL(_LOWER)
#define RAISE OSL(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_planck_mit(
      KC_TAB,           KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
      LCTL_T(KC_ESC),   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  LCTL_T(KC_ENT),
      KC_LSFT,          KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
      TD(TD_RESET),     KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,        KC_SPC,         RAISE,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
  ),

  [_LOWER] = LAYOUT_planck_mit(
      KC_GRV,           KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
      _______,          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_4,     KC_5,     KC_6,     KC_PMNS,  _______,
      _______,          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_1,     KC_2,     KC_3,     KC_PPLS,  _______,
      KC_NO,            _______,  _______,  _______,  _______,      _______,        ADJUST,   KC_P0,    KC_PDOT,  KC_PEQL,  KC_MPLY
  ),

  [_RAISE] = LAYOUT_planck_mit(
      KC_NO,            KC_NO,    KC_NO,    KC_LCBR,  KC_RCBR,  KC_NO,    KC_NO,    KC_GRV,   KC_AMPR,  KC_UNDS,  KC_NO,    _______,
      _______,          KC_NO,    KC_NO,    KC_LPRN,  KC_RPRN,  KC_NO,    KC_NO,    KC_QUOT,  KC_PIPE,  KC_PMNS,  KC_NO,    _______,
      _______,          KC_NO,    KC_NO,    KC_LBRC,  KC_RBRC,  KC_NO,    KC_NO,    KC_DQUO,  KC_PEQL,  KC_NO,    KC_BSLS,  _______,
      KC_NO,            _______,  _______,  _______,  ADJUST,       _______,        _______,  KC_NO,    KC_NO,    KC_NO,    KC_NO
  ),

  [_ADJUST] = LAYOUT_planck_mit(
      KC_F1,            KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
      _______,          KC_NO,    KC_NO,    RGB_MOD,  RGB_TOG,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,    _______,
      _______,          KC_NO,    KC_NO,    RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  KC_NO,    KC_NO,    _______,
      KC_NO,            _______,   _______, _______,  _______,      _______,        _______,  KC_NO,    KC_NO,    KC_NO,    KC_NO
  )

};
