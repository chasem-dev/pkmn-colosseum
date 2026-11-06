/* The record at lbl_803A6748, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_803A6748_H
#define GAME_RECORDS_LBL_803A6748_H

#include "dolphin/types.h"

typedef struct Work803A6748 Work803A6748;

struct Work803A6748 {
    /* 0x00 */ u8 pad_00[0x8];
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ u8 pad_10[0x4];
    /* 0x14 */ f32 field_14;
    /* 0x18 */ f32 field_18;
    /* 0x1C */ u8 pad_1C[0x28];
    /* 0x44 */ f32 field_44;
    /* 0x48 */ u8 pad_48[0x50];
    /* 0x98 */ u32 field_98;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work803A6748, field_8) == 0x8, "Work803A6748");
_Static_assert(__builtin_offsetof(Work803A6748, field_C) == 0xC, "Work803A6748");
_Static_assert(__builtin_offsetof(Work803A6748, field_14) == 0x14, "Work803A6748");
_Static_assert(__builtin_offsetof(Work803A6748, field_18) == 0x18, "Work803A6748");
_Static_assert(__builtin_offsetof(Work803A6748, field_44) == 0x44, "Work803A6748");
_Static_assert(__builtin_offsetof(Work803A6748, field_98) == 0x98, "Work803A6748");
#endif

#endif
