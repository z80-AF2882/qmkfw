/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum custom_keycodes {
    MY_DBG1 = SAFE_RANGE,
    MY_DBG2,
    MY_DBG3,
    MY_DBG4,
};


enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_109_ansi(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  KC_SIRI,  RGB_MOD,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MAC_FN] = LAYOUT_109_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [WIN_BASE] = LAYOUT_109_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_CTANA, RGB_MOD,  MY_DBG1,  MY_DBG2,  MY_DBG3,  MY_DBG4,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [WIN_FN] = LAYOUT_109_ansi(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,    _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______)
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE


// #define DM_LED1 18
// #define DM_LED2 19

// int8_t dm_dir = -1;
// bool dm_recording = false;

// void dynamic_macro_record_start_user(int8_t direction) {
// #ifdef CONSOLE_ENABLE
//     uprintf("DM[%d] Record start\n", direction);
// #endif
//     dm_dir = direction;
//     dm_recording = true;
// }

// void dynamic_macro_play_user(int8_t direction) {
// #ifdef CONSOLE_ENABLE
//     uprintf("DM[%d] Play\n", direction);
// #endif
// }

// void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record) {
// #ifdef CONSOLE_ENABLE
//     uprintf("DM[%d] Record key: %d\n", direction, record->event.key.col * 100 + record->event.key.row);
// #endif
// }

// void dynamic_macro_record_end_user(int8_t direction) {
// #ifdef CONSOLE_ENABLE
//     uprintf("DM[%d] Record end\n", direction);
// #endif
//     dm_recording = false;
// }

// bool dynamic_macro_valid_key_user(uint16_t keycode, keyrecord_t *record) {
// #ifdef CONSOLE_ENABLE
//     uprintf("DM[*] Is valid key: %d\n", keycode);
// #endif

//     if (keycode == DM_RPS1 || keycode == DM_RPS2) {
// #ifdef CONSOLE_ENABLE
//         uprintf("DM[*] Invalid key\n");
// #endif
//         return false;
//     }
//     return true;
// }

uint8_t my_init_counter;

void my_debug_rgb_matrix(void) {
    uprintf("rgb_matrix_config EEPROM\n");
    uprintf("rgb_matrix_config.enable = %d\n", rgb_matrix_config.enable);
    uprintf("rgb_matrix_config.mode = %d\n", rgb_matrix_config.mode);
    uprintf("rgb_matrix_config.hsv.h = %d\n", rgb_matrix_config.hsv.h);
    uprintf("rgb_matrix_config.hsv.s = %d\n", rgb_matrix_config.hsv.s);
    uprintf("rgb_matrix_config.hsv.v = %d\n", rgb_matrix_config.hsv.v);
    uprintf("rgb_matrix_config.speed = %d\n", rgb_matrix_config.speed);
    uprintf("rgb_matrix_config.flags = %d\n", rgb_matrix_config.flags);
    uprintf("RGB_MATRIX_LED_COUNT = %d\n", RGB_MATRIX_LED_COUNT);
    uprintf("RGB_MATRIX_EFFECT_MAX = %d\n", RGB_MATRIX_EFFECT_MAX);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("VV: %s %s\n", __DATE__, __TIME__);
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

        if (record->event.pressed) {
            switch (keycode) {
                case MY_DBG1:
                    uprintf("MY_DBG1 pressed\n");
                    rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect);
                    return false;
                case MY_DBG2:
                    uprintf("MY_DBG2 pressed\n");
                    my_debug_rgb_matrix();
                    return false;
                case MY_DBG3:
                    my_init_counter += 20;
                    return false;
                case MY_DBG4:
                    my_init_counter -= 20;
                    return false;
            }
        }
//     // not needed these are used for various shitty keychron features
//     // if (!process_record_keychron_common(keycode, record)) {
//     //     return false;
//     // }

//     if (!record->event.pressed) {
//         switch (keycode) {
//             case KC_F12:
//                 uprintf("F12 pressed\n");
//                 rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect);
//                 return false;
//             case DM_RPS1:
//                 if (!dm_recording) {
// #ifdef CONSOLE_ENABLE
//                     uprintf("DM: Start recording\n");
// #endif
//                     process_dynamic_macro(QK_DYNAMIC_MACRO_RECORD_START_1, record);
//                 } else {
//                     dynamic_macro_stop_recording();
//                 }
//                 return false;
//             case DM_RPS2:
//                 if (!dm_recording) {
// #ifdef CONSOLE_ENABLE
//                     uprintf("DM: Start recording\n");
// #endif
//                     process_dynamic_macro(QK_DYNAMIC_MACRO_RECORD_START_2, record);
//                 } else {
//                     dynamic_macro_stop_recording();
//                 }
//                 return false;
//         }
//     }

    return true;
}


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // if (dm_recording && dm_dir == 1) {
    //     RGB_MATRIX_INDICATOR_SET_COLOR(DM_LED1, 255, 0, 0);
    // } else {
    //     RGB_MATRIX_INDICATOR_SET_COLOR(DM_LED1, 0, 255, 0);
    // }
    // if (dm_recording && dm_dir == 2) {
    //     RGB_MATRIX_INDICATOR_SET_COLOR(DM_LED2, 255, 0, 0);
    // } else {
    //     RGB_MATRIX_INDICATOR_SET_COLOR(DM_LED2, 0, 255, 0);
    // }
    return false;
}


void keyboard_post_init_user(void) {
    // rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect);
    rgb_matrix_enable_noeeprom(); // Enables RGB, without saving settings
    rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}


