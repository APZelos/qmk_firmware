/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers { _BASE = 0, _SYM, _NUM, _NAV, _FUN };

// Aliases for readability

#define SYM OSL(_SYM)
#define NUM OSL(_NUM)
#define NAV OSL(_NAV)
#define FUN OSL(_FUNCTION)

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_ENT MT(MOD_RCTL, KC_ENT)
#define OS_RSFT OSM(MOD_RSFT)

#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT MT(MOD_LALT, KC_ENT)


// Custom keycodes
#define KC_LCBT LSFT(KC_LBRC)
#define KC_RCBT RSFT(KC_RBRC)
// #define KC_DQT  KC_RSFT(KC_QUOT)
#define KC_UNDR LSFT(KC_MINS)
// #define KC_PIPE KC_LSFT(KC_BSLS)

#define KC_EXCL LSFT(KC_1)
// #define KC_AT   KC_LSFT(KC_2)
// #define KC_HASH KC_LSFT(KC_3)
// #define KC_DLR  KC_LSFT(KC_4)
// #define KC_PERC KC_LSFT(KC_5)
// #define KC_CIRC KC_LSFT(KC_6)
// #define KC_AMPR KC_LSFT(KC_7)
// #define KC_ASTR KC_LSFT(KC_8)
// #define KC_PLUS KC_LSFT(KC_EQL)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
// ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
// | TAB    | Q      | W      | E      | R      | T      |                                      | Y      | U      | I      | O      | P      | BACKSPC|
     KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
// | ESC    | A      | S      | D      | F      | G      |                                      | H      | J      | K      | L      | ; :    | ENTER  |
     CTL_ESC, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, CTL_ENT,
// |--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------|
// | L SHIFT| Z      | X      | C      | V      | B      |        |        |  |        |        | N      | M      | , <    | . >    | / ?    | R SHIFT|
     KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______, _______,    _______, _______, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
// `--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------------------------'
//                            | ALT    | L CND  | NUM LR | SAPCE  | NAV LR |  |        | SYM LR | R SHIFT| R CMD  | ALT    |
                                KC_RALT, KC_LGUI, NUM    , KC_SPC , NAV    ,    _______, SYM    , OS_RSFT, KC_RGUI, KC_LALT
//                            `--------------------------------------------'  `--------------------------------------------'
    ),

    [_SYM] = LAYOUT(
/* ,-----------------------------------------------------.                                      ,-----------------------------------------------------. */
// | TAB    |        | @      | {      | }      |        |                                      |        | ` ~    | \      | #      |        | BACKSPC|
     _______, _______, KC_AT  , KC_LCBT, KC_RCBT, _______,                                        _______, KC_GRV , KC_BSLS, KC_HASH, _______, _______,
/* |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------| */
// | ESC    |        | _      | (      | )      |        |                                      |        | ' "    | |      | &      |        | ENTER  |
     _______, _______, KC_UNDR, KC_LPRN, KC_RPRN, _______,                                        _______, KC_QUOT, KC_PIPE, KC_AMPR, _______, _______,
/* |--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------| */
// | L SHIFT|        | $      | [      | ]      |        |        |        |  |        |        |        | "      | !      | ^      | \ |    | R SHIFT|
     _______, _______, KC_DLR , KC_LBRC, KC_RBRC, _______, _______, _______,    _______, _______, _______, KC_DQT , KC_EXCL, KC_CIRC, KC_BSLS, _______,
/* `--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------' */
//                            | ALT    | L CND  | NUM LR | SAPCE  | NAV LR |  |        | SYM LR | R SHIFT| R CMD  | ALT    |
                                _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
/*                            `--------------------------------------------'  `--------------------------------------------'                            */
    ),

    [_NUM] = LAYOUT(
/* ,-----------------------------------------------------.                                      ,-----------------------------------------------------. */
// | TAB    |        | %      | / ?    | *      |        |                                      |        | 7 &    | 8 *    | 9 (    |        | BACKSPC|
     _______, _______, KC_PERC, KC_SLSH, KC_ASTR, _______,                                        _______, KC_7   , KC_8   , KC_9   , _______, _______,
/* |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------| */
// | ESC    |        | -      | +      | = +    |        |                                      |        | 4 $    | 5 %    | 6 ^    |        | ENTER  |
     _______, _______, KC_MINS, KC_PLUS, KC_EQL , _______,                                        _______, KC_4   , KC_5   , KC_6   , _______, _______,
/* |--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------| */
// | L SHIFT|        |        |        | 0      |        |        |        |  |        |        |        | 1  !   | 2 @    | 3 #    |        | R SHIFT|
     _______, _______, _______, _______, KC_0   , _______, _______, _______,    _______, _______, _______, KC_1   , KC_2   , KC_3   , _______, _______,
/* `--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------' */
//                            | ALT    | L CND  | NUM LR | SAPCE  | NAV LR |  |        | SYM LR | R SHIFT| R CMD  | ALT    |
                                _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
/*                            `--------------------------------------------'  `--------------------------------------------'                            */
    ),


    [_NAV] = LAYOUT(
/* ,-----------------------------------------------------.                                      ,-----------------------------------------------------. */
// | TAB    |        |        |        |        |        |                                      | HOME   | PG DOWN| PG UP  | END    |        | BACKSPC|
     _______, _______, _______, _______, _______, _______,                                        KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
/* |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------| */
// | ESC    |        |        |        |        |        |                                      | AR LEFT| AR DOWN| AR UP  | AR RGHT|        | ENTER  |
     _______, _______, _______, _______, _______, _______,                                        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
/* |--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------| */
// | L SHIFT|        |        |        |        |        |        |        |  |        |        |        |        |        |        |        | R SHIFT|
     _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
/* `--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------' */
//                            | ALT    | L CND  | NUM LR | SAPCE  | NAV LR |  |        | SYM LR | R SHIFT| R CMD  | ALT    |
                                _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
/*                            `--------------------------------------------'  `--------------------------------------------'                            */
    ),

    [_FUN] = LAYOUT(
/* ,-----------------------------------------------------.                                      ,-----------------------------------------------------. */
// | TAB    |  F1    | F2     | F3     | F4     | F5     |                                      | F6     | F7     | F8     | F9     | F10    | BACKSPC|
     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
/* |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------| */
// | ESC    |        |        |        |        |        |                                      |        |        |        |        |        | ENTER  |
     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
/* |--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------| */
// | L SHIFT|        |        |        |        |        |        |        |  |        |        |        |        |        |        |        | R SHIFT|
     _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
/* `--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------' */
//                            | ALT    | L CND  | NUM LR | SAPCE  | NAV LR |  |        | SYM LR | R SHIFT| R CMD  | ALT    |
                                _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
/*                            `--------------------------------------------'  `--------------------------------------------'                            */
    ),
};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [4] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif
