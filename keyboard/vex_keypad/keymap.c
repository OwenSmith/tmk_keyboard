/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "keymap.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer
 *  +-------+-------+-------+-------+
 *  |Esc|  7|  8|  9|  0|MIN|EQL|<--|
 *  |BSL|  1|  2|  3|  4|  5|  6|  I|
 *  |TAB|TAB|  Q|  W|  E|  R|  T|  J|
 *  |SFT|SFT|  A|  S|  D|  F|  G|ENT|
 *  |CTL|ALT|  Z|  X|  C|  V|  B|  M|
 *  +-------------------------------+
 *  |Fn3|Fn2|Fn1|SPC|Fn0| (Thumbs)
 *  |   |   |   |   |   | (not connected)
 *  +-------------------+
     */
    KEYMAP(
        ESC,   7,     8,     9,     0,     MINS,  EQL,   BSPC, \
        BSLS,  1,     2,     3,     4,     5,     6,     I,    \
        TAB,   TAB,   Q,     W,     E,     R,     T,     J,    \
        LSFT,  LSFT,  A,     S,     D,     F,     G,     ENT,  \
        LCTL,  LALT,  Z,     X,     C,     V,     B,     M,    \
        FN3,   FN2,   FN1,   SPC,   FN0, \
        NO,    NO,    NO,    NO,    NO),
    /* 1: Cursors (Fn0)
 *  +-------------------------------+
 *  |Esc| F7| F8| F9|F10|F11|F12|<--|
 *  |   | F1| F2| F3| F4| F5| F6|   |
 *  |TAB|TAB|   | UP|   |PUP|HOM|   |
 *  |SFT|SFT|RGT| DN|LFT|PDN|END|ENT|
 *  |CTL|ALT|   |   |   |   |   |   |
 *  +-------------------------------+
 *  |Fn3|Fn2|Fn1|Spc|Fn0| (Thumbs)
 *  |   |   |   |   |   | (not connected)
 *  +-------------------+
     */
    KEYMAP(
        TRNS,  F7,    F8,    F9,    F10,   F11,   F12,   TRNS,\
        NO,    F1,    F2,    F3,    F4,    F5,    F6,    NO,  \
        TRNS,  TRNS,  NO,    UP,    NO,    PGUP,  HOME,  NO,  \
        TRNS,  TRNS,  RGHT,  DOWN,  LEFT,  PGDN,  END,   TRNS,\
        TRNS,  TRNS,  NO,    NO,    NO,    NO,    NO,    NO,  \
        TRNS,  TRNS,  TRNS,  TRNS,  TRNS, \
        NO,    NO,    NO,    NO,    NO),
    /* 2: Mouse (Fn1)
 *  +-------------------------------+
 *  |Esc|   |AC0|AC1|AC2|   |   |<--|
 *  |   |   |MB4|MMB|MB5|   |MUT|   |
 *  |TAB|TAB|RMB| UP|LMB|SUP|VO+|   |
 *  |SFT|SFT|RGT| DN|LFT|SDN|VO-|ENT|
 *  |CTL|ALT|WHL|   |WHR|   |   |   |
 *  +-------------------------------+
 *  |Fn3|Fn2|Fn1|Spc|Fn0| (Thumbs)
 *  |   |   |   |   |   | (not connected)
 *  +-------------------+
     */
    KEYMAP(
        TRNS,  NO,    ACL0,  ACL1,  ACL2,  NO,    NO,    TRNS,\
        NO,    NO,    BTN4,  BTN3,  BTN5,  NO,    MUTE,  NO,  \
        TRNS,  TRNS,  BTN2,  MS_U,  BTN1,  WH_U,  VOLU,  NO,  \
        TRNS,  TRNS,  MS_L,  MS_D,  MS_R,  WH_D,  VOLD,  TRNS,\
        TRNS,  TRNS,  WH_L,  NO,    WH_R,  NO,    NO,    NO,  \
        TRNS,  TRNS,  TRNS,  TRNS,  TRNS, \
        NO,    NO,    NO,    NO,    NO),
    /* 3: Mouse+Cursors (Fn1+Fn0) */
    KEYMAP(
        TRNS,  NO,    NO,    NO,    NO,    NO,    NO,    TRNS,\
        NO,    NO,    NO,    NO,    NO,    NO,    NO,    NO,  \
        TRNS,  TRNS,  NO,    NO,    NO,    NO,    NO,    NO,  \
        TRNS,  TRNS,  NO,    NO,    NO,    NO,    NO,    TRNS,\
        TRNS,  TRNS,  NO,    NO,    NO,    NO,    NO,    NO,  \
        TRNS,  TRNS,  TRNS,  TRNS,  TRNS, \
        NO,    NO,    NO,    NO,    NO),
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_MOMENTARY(2),
    [2] = ACTION_LAYER_MOMENTARY(1),
    [3] = ACTION_LAYER_MOMENTARY(2),
};

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    return (action_t){ .code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]) };
}
