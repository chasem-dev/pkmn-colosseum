/* The record at lbl_803FB380, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_803FB380_H
#define GAME_RECORDS_LBL_803FB380_H

#include "dolphin/types.h"

typedef struct Work803FB380 Work803FB380;

struct Work803FB380 {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 pad_01[0x1];
    /* 0x02 */ s8 field_2;
    /* 0x03 */ s8 field_3;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ u32 field_8;
    /* 0x0C */ u32 field_C;
    /* 0x10 */ u32 field_10;
    /* 0x14 */ u32 field_14;
    /* 0x18 */ u16 field_18;
    /* 0x1A */ s8 field_1A;
    /* 0x1B */ u8 pad_1B[0x1];
    /* 0x1C */ s32 field_1C;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work803FB380, field_0) == 0x0, "Work803FB380");
_Static_assert(__builtin_offsetof(Work803FB380, field_2) == 0x2, "Work803FB380");
_Static_assert(__builtin_offsetof(Work803FB380, field_3) == 0x3, "Work803FB380");
_Static_assert(__builtin_offsetof(Work803FB380, field_4) == 0x4, "Work803FB380");
_Static_assert(__builtin_offsetof(Work803FB380, field_8) == 0x8, "Work803FB380");
_Static_assert(__builtin_offsetof(Work803FB380, field_C) == 0xC, "Work803FB380");
_Static_assert(__builtin_offsetof(Work803FB380, field_10) == 0x10, "Work803FB380");
_Static_assert(__builtin_offsetof(Work803FB380, field_14) == 0x14, "Work803FB380");
_Static_assert(__builtin_offsetof(Work803FB380, field_18) == 0x18, "Work803FB380");
_Static_assert(__builtin_offsetof(Work803FB380, field_1A) == 0x1A, "Work803FB380");
_Static_assert(__builtin_offsetof(Work803FB380, field_1C) == 0x1C, "Work803FB380");
#endif

#endif
