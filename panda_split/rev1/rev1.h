#pragma once

#include "quantum.h"

#define LAYOUT( \
        L01, L02, L03, L04, L05, L06,   R01, R02, R03, R04, R05, R06, R07, R08, R09, \
        L07, L08, L09, L10, L11, L12,        R10, R11, R12, R13, R14, R15, R16, R17, \
        L13, L14, L15, L16, L17, L18,        R18, R19, R20, R21, R22, R23, R24,      \
        L19, L20, L21, L22, L23, L24,             R25, R26, R27, R28, R29, R30, R31, \
        L25, L26, L27, L28, L30, L31,             R32, R33, R34, R35, R36, R37, R38, \
        \
        K01, K02, K03, K04, \
        K05, K06, K07, K08, \
        K09, K10, K11,      \
        K12, K13, K14, K15, \
        K16, K17, K18 \
) \
{ \
    { L12, L11, L06, L05, L16, L15, L14, L13, L09, L03, L02, L08, L01, L07, L04, L10 }, \
    { L30, L31, KC_NO, KC_NO, L28, L27, L25, L26, L19, L20, L21, L24, L18, L23, L17, L22 }, \
    { R09, R16, R15, R10, R11, R12, R13, R14, R06, R05, R04, R03, R02, R01, R07, R08 }, \
    { R28, R35, R27, R34, R33, R26, R25, R32, R19, R18, R20, R21, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, R31, R38, R37, R30, R36, R29, R23, R22, R17, R24, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K08, K07, KC_NO, KC_NO, KC_NO, KC_NO, K06, K05, K01, KC_NO, K02, K03, K04, KC_NO, KC_NO, KC_NO }, \
    { K15, K14, K18, K17, K16, K13, KC_NO, K12, K09, K10, K11, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
}
