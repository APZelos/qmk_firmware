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

enum my_keycodes {
  UNDER = SAFE_RANGE
};

#define SYM OSL(_SYM)
#define NUM OSL(_NUM)
#define NAV OSL(_NAV)
#define FUN OSL(_FUNCTION)

// Custom keycodes
#define KC_LCBT LSFT(KC_LBRC)
#define KC_RCBT RSFT(KC_RBRC)
#define KC_UNDR LSFT(KC_MINS)
#define KC_EXCL LSFT(KC_1)

#define OS_RSFT OSM(MOD_RSFT)

// HOME ROW MODS
// Left-hand home row mods
#define GUI_S LGUI_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

#define GUI_UND LGUI_T(UNDER)
#define ALT_LPR LALT_T(KC_LPRN)
#define CTL_RPR LCTL_T(KC_RPRN)

#define GUI_MNS LGUI_T(KC_MINS)
#define ALT_PLS LALT_T(KC_PLUS)
#define CTL_EQL LCTL_T(KC_EQL)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define ALT_K LALT_T(KC_K)
#define GUI_L RGUI_T(KC_L)

#define CTL_QOT RCTL_T(KC_QUOT)
#define ALT_PPE LALT_T(KC_PIPE)
#define GUI_AMP RGUI_T(KC_AMPR)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_MINS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_MINS);
                return false;
            }
            break;

        case LGUI_T(UNDER):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;

        case LALT_T(KC_PLUS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PLUS);
                return false;
            }
            break;

        case LALT_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;

        case LCTL_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;

        case LALT_T(KC_PIPE):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PIPE);
                return false;
            }
            break;

        case RGUI_T(KC_AMPR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_AMPR);
                return false;
            }
            break;

    }
    return true;
}

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
// ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
// |        | Q      | W      | E      | R      | T      |                                      | Y      | U      | I      | O      | P      |        |
     _______, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
// |        | A      | S      | D      | F      | G      |                                      | H      | J      | K      | L      | ; :    |        |
     _______, KC_A   , GUI_S  , ALT_D  , CTL_F  , KC_G   ,                                        KC_H   , CTL_J  , ALT_K  , GUI_L  , KC_SCLN, _______,
// |--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------|
// |        | Z      | X      | C      | V      | B      |        |        |  |        |        | N      | M      | , <    | . >    | / ?    |        |
     _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______, _______,    _______, _______, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______,
// `--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------------------------'
//                            |        |        | NUM LR | SAPCE  |        |  |        | SYM LR | R SHIFT|        |        |
                                _______, _______, NUM    , KC_SPC , _______,    _______, SYM    , OS_RSFT, _______, _______
//                            `--------------------------------------------'  `--------------------------------------------'
    ),

    [_SYM] = LAYOUT(
/* ,-----------------------------------------------------.                                      ,-----------------------------------------------------. */
// |        | TAB    | @      | {      | }      |        |                                      |        | ` ~    | \      | #      | BACKSPC|        |
     _______, KC_TAB , KC_AT  , KC_LCBT, KC_RCBT, _______,                                        _______, KC_GRV , KC_BSLS, KC_HASH, KC_BSPC, _______,
/* |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------| */
// |        | ESC    | _      | (      | )      |        |                                      |        | ' "    | |      | &      | ENTER  |        |
     _______, KC_ESC , GUI_UND, ALT_LPR, CTL_RPR, _______,                                        _______, CTL_QOT, ALT_PPE, GUI_AMP, KC_ENT , _______,
/* |--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------| */
// |        |        | $      | [      | ]      |        |        |        |  |        |        |        | "      | !      | ^      |        |        |
     _______, _______, KC_DLR , KC_LBRC, KC_RBRC, _______, _______, _______,    _______, _______, _______, KC_DQT , KC_EXCL, KC_CIRC, _______, _______,
/* `------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------' */
//                            | ALT    | L CND  | NAV LR | SAPCE  | NAV LR |  |        | SYM LR | R SHIFT| R CMD  | ALT    |
                                _______, _______, NAV    , _______, _______,    _______, _______, _______, _______, _______
/*                            `--------------------------------------------'  `--------------------------------------------'                            */
    ),

    [_NUM] = LAYOUT(
/* ,-----------------------------------------------------.                                      ,-----------------------------------------------------. */
// |        | TAB    | %      | / ?    | *      |        |                                      |        | 7 &    | 8 *    | 9 (    | BACKSPC|        |
     _______, KC_TAB , KC_PERC, KC_SLSH, KC_ASTR, _______,                                        _______, KC_7   , KC_8   , KC_9   , KC_BSPC, _______,
/* |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------| */
// |        | ESC    | -      | +      | = +    |        |                                      |        | 4 $    | 5 %    | 6 ^    | ENTER  |        |
     _______, KC_ESC , GUI_MNS, ALT_PLS, CTL_EQL, _______,                                        _______, KC_4   , KC_5   , KC_6   , KC_ENT , _______,
/* |--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------| */
// |        |        |        |        | 0      |        |        |        |  |        |        |        | 1  !   | 2 @    | 3 #    |        |        |
     _______, _______, _______, _______, KC_0   , _______, _______, _______,    _______, _______, _______, KC_1   , KC_2   , KC_3   , _______, _______,
/* `--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------' */
//                            | ALT    | L CND  | NAV LR | SAPCE  | NAV LR |  |        | SYM LR | R SHIFT| R CMD  | ALT    |
                                _______, _______, NAV    , _______, _______,    _______, _______, _______, _______, _______
/*                            `--------------------------------------------'  `--------------------------------------------'                            */
    ),


    [_NAV] = LAYOUT(
/* ,-----------------------------------------------------.                                      ,-----------------------------------------------------. */
// |        | TAB    |        |        |        |        |                                      | HOME   | PG DOWN| PG UP  | END    | BACKSPC|        |
     _______, KC_TAB , _______, _______, _______, _______,                                        KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_BSPC, _______,
/* |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------| */
// |        | ESC    |        |        |        |        |                                      | AR LEFT| AR DOWN| AR UP  | AR RGHT| ENTER  |        |
     _______, KC_ESC , KC_LGUI, KC_LALT, KC_LCTL, _______,                                        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT, _______,
/* |--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------| */
// |        |        |        |        |        |        |        |        |  |        |        |        |        |        |        |        |        |
     _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
/* `--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------' */
//                            | ALT    | L CND  | NUM LR | SAPCE  | NAV LR |  |        | N/A    | R SHIFT| R CMD  | ALT    |
                                _______, _______, _______, _______, _______,    _______, KC_NO  , _______, _______, _______
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

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */
