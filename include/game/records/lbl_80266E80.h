/* The record at lbl_80266E80, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_80266E80_H
#define GAME_RECORDS_LBL_80266E80_H

#include "dolphin/types.h"

typedef struct Work80266E80 Work80266E80;

struct Work80266E80 {
    /* 0x00 */ u32 field_0;
    /* 0x04 */ u32 field_4;
    /* 0x08 */ u32 field_8;
    /* 0x0C */ u32 field_C;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work80266E80, field_0) == 0x0, "Work80266E80");
_Static_assert(__builtin_offsetof(Work80266E80, field_4) == 0x4, "Work80266E80");
_Static_assert(__builtin_offsetof(Work80266E80, field_8) == 0x8, "Work80266E80");
_Static_assert(__builtin_offsetof(Work80266E80, field_C) == 0xC, "Work80266E80");
#endif

#endif
