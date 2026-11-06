/* The record at lbl_803A654C, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_803A654C_H
#define GAME_RECORDS_LBL_803A654C_H

#include "dolphin/types.h"

typedef struct Work803A654C Work803A654C;

struct Work803A654C {
    /* 0x00 */ u8 pad_00[0x4];
    /* 0x04 */ f32 field_4;
    /* 0x08 */ f32 field_8;
    /* 0x0C */ f32 field_C;
    /* 0x10 */ f32 field_10;
    /* 0x14 */ u8 pad_14[0x8];
    /* 0x1C */ f32 field_1C;
    /* 0x20 */ f32 field_20;
    /* 0x24 */ f32 field_24;
    /* 0x28 */ f32 field_28;
    /* 0x2C */ u8 pad_2C[0x8];
    /* 0x34 */ f32 field_34;
    /* 0x38 */ f32 field_38;
    /* 0x3C */ f32 field_3C;
    /* 0x40 */ f32 field_40;
    /* 0x44 */ u8 pad_44[0x8];
    /* 0x4C */ f32 field_4C;
    /* 0x50 */ f32 field_50;
    /* 0x54 */ f32 field_54;
    /* 0x58 */ f32 field_58;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work803A654C, field_4) == 0x4, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_8) == 0x8, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_C) == 0xC, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_10) == 0x10, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_1C) == 0x1C, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_20) == 0x20, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_24) == 0x24, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_28) == 0x28, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_34) == 0x34, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_38) == 0x38, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_3C) == 0x3C, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_40) == 0x40, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_4C) == 0x4C, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_50) == 0x50, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_54) == 0x54, "Work803A654C");
_Static_assert(__builtin_offsetof(Work803A654C, field_58) == 0x58, "Work803A654C");
#endif

#endif
