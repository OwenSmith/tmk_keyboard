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
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];

/*
 * Layout:
 *  Row-Col Row=OUT(F) Col=IN(BD)
 *  +-------------------------------+
 *  |   |   |   |   |   |   |   |   |
 *  |   |   |   |   |   |   |   |   |
 *  |   |   |   |   |   |   |   |   |
 *  |   |   |   |   |   |   |   |   |
 *  |   |   |   |   |   |   |   |   |
 *  +-------------------------------+
 *  |   |   |   |   |   | (Thumbs)
 *  |   |   |   |   |   | (NotConnected)
 *  +-------------------+
 * READ
 * B0,D0->PCB5 (Col4,Col9)
 * B1,D1->PCB4 (Col3,Col8)
 * B2,D2->PCB3 (Col2,Col7)
 * B3,D3->PCB2 (Col1,Col6)
 * B7,C6->PCB1 (Col0,Col5)
 * WRITE
 * F0,F1,F4,F5,F6 -> PCB0 (Row0,Row1,Row2,Row3,Row4)
 */
#define KEYMAP( \
    K00, K05, K10, K15, K20, K25, K30, K35, \
    K01, K06, K11, K16, K21, K26, K31, K36, \
    K02, K07, K12, K17, K22, K27, K32, K37, \
    K03, K08, K13, K18, K23, K28, K33, K38, \
    K04, K09, K14, K19, K24, K29, K34, K39, \
                                            \
    K40, K41, K42, K43, K44,                \
    K45, K46, K47, K48, K49                 \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09, }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_##K38, KC_##K39, }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47, KC_##K48, KC_##K49, }, \
}
//    PCB1      PCB2      PCB3      PCB4      PCB5      PCB1      PCB2      PCB3      PCB4      PCB5
#endif
