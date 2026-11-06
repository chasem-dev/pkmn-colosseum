/* The record at lbl_8047AD88, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_8047AD88_H
#define GAME_RECORDS_LBL_8047AD88_H

#include "dolphin/types.h"

typedef struct Work8047AD88 Work8047AD88;

struct Work8047AD88 {
    /* 0x00 */ u16 field_0;
    /* 0x02 */ u16 field_2;
    /* 0x04 */ u8 pad_04[0x4];
    /* 0x08 */ u32 field_8;
    /* 0x0C */ u32 field_C;
    /* 0x10 */ u32 field_10;
    /* 0x14 */ u32 field_14;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work8047AD88, field_0) == 0x0, "Work8047AD88");
_Static_assert(__builtin_offsetof(Work8047AD88, field_2) == 0x2, "Work8047AD88");
_Static_assert(__builtin_offsetof(Work8047AD88, field_8) == 0x8, "Work8047AD88");
_Static_assert(__builtin_offsetof(Work8047AD88, field_C) == 0xC, "Work8047AD88");
_Static_assert(__builtin_offsetof(Work8047AD88, field_10) == 0x10, "Work8047AD88");
_Static_assert(__builtin_offsetof(Work8047AD88, field_14) == 0x14, "Work8047AD88");
#endif

#endif
