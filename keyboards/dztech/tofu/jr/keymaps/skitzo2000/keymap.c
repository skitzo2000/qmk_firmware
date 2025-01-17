/* Copyright 2023 Paul Norton Goldfish.paul@gmail.com>
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
/*  This is Skitzo2000's spin on the Tofu Jr qmk config */
#include QMK_KEYBOARD_H

enum custom_keycodes {
    PRNTSCREEN = SAFE_RANGE,
    NAME,
    GOOD_MORNING,
    HAPPY_MONDAY,
    HAPPY_FRIDAY,
    SHRUGS,
    TBLFLIP,
};

//  Skitzo2000's Custom Colors
#define ORANGE_RGB        120, 26, 0
#define DARKORANGE_RGB    60, 13, 0
#define BLUE_RGB          0, 26, 255
#define DARKBLUE_RGB      0, 60, 120
//  GMMK 2 65 Default Function Layer colors
#define FUNCTION_KEYS     RGB_GREEN
#define ARROW_KEYS        ORANGE_RGB
#define MISC_KEYS         RGB_YELLOW
#define RESET_KEY         RGB_RED
#define RGB_KEYS          RGB_PURPLE
#define MEDIA_KEYS        RGB_GOLD
//  Skitzo2000's custom keys
#define TO_KEYS           BLUE_RGB

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PRNTSCREEN:
        if (record->event.pressed) {
            SEND_STRING(SS_RGUI(SS_RSFT("s")));
        } else {

        }
        break;
    case NAME:
        if (record->event.pressed) {
            SEND_STRING("Paul Norton");
        } else {

        }
        break;
    case GOOD_MORNING:
        if (record->event.pressed) {
            SEND_STRING("Good Morning ");
        } else {

        }
        break;
    case HAPPY_MONDAY:
        if (record->event.pressed) {
            SEND_STRING("Happy Monday ");
        } else {

        }
        break;
    case HAPPY_FRIDAY:
        if (record->event.pressed) {
            SEND_STRING("Happy Friday ");
        } else {

        }
    case SHRUGS:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT("sf"));
        } else {

        }
        break;
    case TBLFLIP:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT("tf"));
        } else {

        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(
        QK_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_MPLY,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
        KC_LCTL,  KC_LGUI, KC_LALT,                            KC_SPC,           KC_RALT, MO(3), KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,          _______, _______, _______,          _______, _______, _______
    ),
    [2] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,          _______, _______, _______,          _______, _______, _______
    ),
    [3] = LAYOUT_65_ansi(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, PRNTSCREEN, KC_SCRL, KC_PAUS, QK_BOOT, KC_PGDN,
        KC_CAPS, RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______,         EE_CLR,  KC_MUTE,
        KC_LSFT, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,          KC_VOLU, KC_HOME,
        _______, _______, _______,                            _______,          MO(4), _______, _______,          KC_MPRV, KC_VOLD, KC_MNXT
    ),
    [4] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, TBLFLIP, _______, _______, _______, _______, PRNTSCREEN, _______, _______, _______, _______,
        _______, _______, SHRUGS, _______, HAPPY_FRIDAY, GOOD_MORNING, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, NAME, HAPPY_MONDAY, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,          _______, _______, _______,          _______, _______, _______
    ),
};