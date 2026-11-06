/* The record at lbl_80408378, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_80408378_H
#define GAME_RECORDS_LBL_80408378_H

#include "dolphin/types.h"

typedef struct Work80408378 Work80408378;

struct Work80408378 {
    /* 0x00 */ u32 field_0;
    /* 0x04 */ u32 field_4;
    /* 0x08 */ u8 field_8;
    /* 0x09 */ u8 pad_09[0x3];
    /* 0x0C */ u32 field_C;
    /* 0x10 */ u8 pad_10[0x18];
    /* 0x28 */ u32 field_28;
    /* 0x2C */ u8 pad_2C[0x10];
    /* 0x3C */ u32 field_3C;
    /* 0x40 */ u32 field_40;
    /* 0x44 */ u8 field_44;
    /* 0x45 */ u8 pad_45[0xC];
    /* 0x51 */ u8 field_51;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work80408378, field_0) == 0x0, "Work80408378");
_Static_assert(__builtin_offsetof(Work80408378, field_4) == 0x4, "Work80408378");
_Static_assert(__builtin_offsetof(Work80408378, field_8) == 0x8, "Work80408378");
_Static_assert(__builtin_offsetof(Work80408378, field_C) == 0xC, "Work80408378");
_Static_assert(__builtin_offsetof(Work80408378, field_28) == 0x28, "Work80408378");
_Static_assert(__builtin_offsetof(Work80408378, field_3C) == 0x3C, "Work80408378");
_Static_assert(__builtin_offsetof(Work80408378, field_40) == 0x40, "Work80408378");
_Static_assert(__builtin_offsetof(Work80408378, field_44) == 0x44, "Work80408378");
_Static_assert(__builtin_offsetof(Work80408378, field_51) == 0x51, "Work80408378");
#endif

#endif
