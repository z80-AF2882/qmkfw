#ifndef DMX_H
#define DMX_H

#define DMX_LONG_PRESS 300

#define DMX_REC_INDEX_NONE 0xFF

#define DMX_LED(n) ((n) ? 72 : 18)

extern uint8_t dmx_rec_index;
extern uint8_t dmx_empty_flag;

bool dmx_process_record(uint16_t keycode, keyrecord_t *record);

#endif
