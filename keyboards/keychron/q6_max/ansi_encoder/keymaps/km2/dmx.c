#include QMK_KEYBOARD_H
#include "keymap.h"
#include "dmx.h"

uint8_t dmx_empty_flag = 0xFF;
uint8_t dmx_rec_index = DMX_REC_INDEX_NONE;

uint16_t dmx_keydown_time = 0;

void dynamic_macro_record_start_user(int8_t direction) {
    uprintf("DM[%d] Record start\n", direction);
}

void dynamic_macro_play_user(int8_t direction) {
    uprintf("DM[%d] Play\n", direction);
}

void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record) {
    uprintf("DM[%d] Record key: %d\n", direction, record->event.key.col * 100 + record->event.key.row);
}

void dynamic_macro_record_end_user(int8_t direction) {
    uprintf("DM[%d] Record end\n", direction);
}

bool dynamic_macro_valid_key_user(uint16_t keycode, keyrecord_t *record) {
    uprintf("DM[*] Is valid key: %d\n", keycode);
    if (keycode == DMX_B1 || keycode == DMX_B2) {
        return false;
    }
    return true;
}

bool dmx_process_record(uint16_t keycode, keyrecord_t *record) {
    uint8_t index = keycode - DMX_B1;
    if (dmx_rec_index != DMX_REC_INDEX_NONE) {
        if (record->event.pressed) {
            return false;
        }
        if (dmx_rec_index != index) {
            uprintf("DMX ignoring dmx key %d\n", index);
            return false;
        }
        uprintf("DMX stop recording \n");
        dmx_rec_index = DMX_REC_INDEX_NONE;
        dynamic_macro_stop_recording();
        return false;
    }

    if (record->event.pressed) {
        uprintf("DMX registered %d\n", index);
        dmx_keydown_time = record->event.time;
        return false;
    }

    if ((record->event.time - dmx_keydown_time) > DMX_LONG_PRESS) {
        uprintf("DMX record %d\n", index);
        dmx_rec_index = index;
        process_dynamic_macro(index? QK_DYNAMIC_MACRO_RECORD_START_2 : QK_DYNAMIC_MACRO_RECORD_START_1, record);
        return false;
    }

    uprintf("DMX play %d\n", index);
    process_dynamic_macro(index? QK_DYNAMIC_MACRO_PLAY_2 : QK_DYNAMIC_MACRO_PLAY_1, record);
    return false;
}
