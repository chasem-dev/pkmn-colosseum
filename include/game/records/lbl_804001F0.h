/* The record at lbl_804001F0, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_804001F0_H
#define GAME_RECORDS_LBL_804001F0_H

#include "dolphin/types.h"

typedef struct Work804001F0 Work804001F0;

struct Work804001F0 {
    /* 0x00 */ u8 pad_00[0x4];
    /* 0x04 */ u32 field_4;
    /* 0x08 */ u8 pad_08[0x4];
    /* 0x0C */ u32 field_C;
    /* 0x10 */ u8 pad_10[0x4];
    /* 0x14 */ u32 field_14;
    /* 0x18 */ u8 pad_18[0xC];
    /* 0x24 */ u32 field_24;
    /* 0x28 */ u32 field_28;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work804001F0, field_4) == 0x4, "Work804001F0");
_Static_assert(__builtin_offsetof(Work804001F0, field_C) == 0xC, "Work804001F0");
_Static_assert(__builtin_offsetof(Work804001F0, field_14) == 0x14, "Work804001F0");
_Static_assert(__builtin_offsetof(Work804001F0, field_24) == 0x24, "Work804001F0");
_Static_assert(__builtin_offsetof(Work804001F0, field_28) == 0x28, "Work804001F0");
#endif

#endif
