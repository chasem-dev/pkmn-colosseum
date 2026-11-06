/* The record at lbl_80266F68, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_80266F68_H
#define GAME_RECORDS_LBL_80266F68_H

#include "dolphin/types.h"

typedef struct Work80266F68 Work80266F68;

struct Work80266F68 {
    /* 0x00 */ u16 field_0;
    /* 0x02 */ u16 field_2;
    /* 0x04 */ u8 pad_04[0xE];
    /* 0x12 */ u16 field_12;
    /* 0x14 */ u16 field_14;
    /* 0x16 */ u16 field_16;
    /* 0x18 */ u8 pad_18[0xE];
    /* 0x26 */ u16 field_26;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work80266F68, field_0) == 0x0, "Work80266F68");
_Static_assert(__builtin_offsetof(Work80266F68, field_2) == 0x2, "Work80266F68");
_Static_assert(__builtin_offsetof(Work80266F68, field_12) == 0x12, "Work80266F68");
_Static_assert(__builtin_offsetof(Work80266F68, field_14) == 0x14, "Work80266F68");
_Static_assert(__builtin_offsetof(Work80266F68, field_16) == 0x16, "Work80266F68");
_Static_assert(__builtin_offsetof(Work80266F68, field_26) == 0x26, "Work80266F68");
#endif

#endif
