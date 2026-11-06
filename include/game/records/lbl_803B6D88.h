/* The record at lbl_803B6D88, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_803B6D88_H
#define GAME_RECORDS_LBL_803B6D88_H

#include "dolphin/types.h"

typedef struct Work803B6D88 Work803B6D88;

struct Work803B6D88 {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ u8 pad_04[0x3C];
    /* 0x40 */ u32 field_40;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work803B6D88, field_0) == 0x0, "Work803B6D88");
_Static_assert(__builtin_offsetof(Work803B6D88, field_40) == 0x40, "Work803B6D88");
#endif

#endif
