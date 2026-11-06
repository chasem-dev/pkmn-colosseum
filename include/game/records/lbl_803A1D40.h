/* The record at lbl_803A1D40, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_803A1D40_H
#define GAME_RECORDS_LBL_803A1D40_H

#include "dolphin/types.h"

typedef struct Work803A1D40 Work803A1D40;

struct Work803A1D40 {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 field_1;
    /* 0x02 */ u8 field_2;
    /* 0x03 */ u8 field_3;
    /* 0x04 */ u8 field_4;
    /* 0x05 */ u8 pad_05[0x1];
    /* 0x06 */ u8 field_6;
    /* 0x07 */ u8 pad_07[0x1];
    /* 0x08 */ s32 field_8;
    /* 0x0C */ void* field_C;
    /* 0x10 */ u8 field_10;
    /* 0x11 */ u8 field_11;
    /* 0x12 */ u16 field_12;
    /* 0x14 */ u8 field_14;
    /* 0x15 */ u8 field_15;
    /* 0x16 */ u8 pad_16[0x2];
    /* 0x18 */ u32 field_18;
    /* 0x1C */ u32 field_1C;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work803A1D40, field_0) == 0x0, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_1) == 0x1, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_2) == 0x2, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_3) == 0x3, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_4) == 0x4, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_6) == 0x6, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_8) == 0x8, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_C) == 0xC, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_10) == 0x10, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_11) == 0x11, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_12) == 0x12, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_14) == 0x14, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_15) == 0x15, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_18) == 0x18, "Work803A1D40");
_Static_assert(__builtin_offsetof(Work803A1D40, field_1C) == 0x1C, "Work803A1D40");
#endif

#endif
