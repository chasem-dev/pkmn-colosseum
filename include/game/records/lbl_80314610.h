/* The record at lbl_80314610, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_80314610_H
#define GAME_RECORDS_LBL_80314610_H

#include "dolphin/types.h"

typedef struct Work80314610 Work80314610;

struct Work80314610 {
    /* 0x00 */ u8 pad_00[0x24];
    /* 0x24 */ u32 field_24;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work80314610, field_24) == 0x24, "Work80314610");
#endif

#endif
