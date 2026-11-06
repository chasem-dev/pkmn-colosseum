/* The record at lbl_803A6A60, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_803A6A60_H
#define GAME_RECORDS_LBL_803A6A60_H

#include "dolphin/types.h"

typedef struct Work803A6A60 Work803A6A60;

struct Work803A6A60 {
    /* 0x00 */ s8 field_0;
    /* 0x01 */ s8 field_1;
    /* 0x02 */ u8 pad_02[0x6];
    /* 0x08 */ f32 field_8;
    /* 0x0C */ u8 pad_0C[0xC];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ u8 pad_28[0x8];
    /* 0x30 */ f32 field_30;
    /* 0x34 */ f32 field_34;
    /* 0x38 */ u8 pad_38[0x8];
    /* 0x40 */ f32 field_40;
    /* 0x44 */ u32 field_44;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work803A6A60, field_0) == 0x0, "Work803A6A60");
_Static_assert(__builtin_offsetof(Work803A6A60, field_1) == 0x1, "Work803A6A60");
_Static_assert(__builtin_offsetof(Work803A6A60, field_8) == 0x8, "Work803A6A60");
_Static_assert(__builtin_offsetof(Work803A6A60, field_18) == 0x18, "Work803A6A60");
_Static_assert(__builtin_offsetof(Work803A6A60, field_1C) == 0x1C, "Work803A6A60");
_Static_assert(__builtin_offsetof(Work803A6A60, field_20) == 0x20, "Work803A6A60");
_Static_assert(__builtin_offsetof(Work803A6A60, field_24) == 0x24, "Work803A6A60");
_Static_assert(__builtin_offsetof(Work803A6A60, field_30) == 0x30, "Work803A6A60");
_Static_assert(__builtin_offsetof(Work803A6A60, field_34) == 0x34, "Work803A6A60");
_Static_assert(__builtin_offsetof(Work803A6A60, field_40) == 0x40, "Work803A6A60");
_Static_assert(__builtin_offsetof(Work803A6A60, field_44) == 0x44, "Work803A6A60");
#endif

#endif
