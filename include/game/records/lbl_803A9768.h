/* The record at lbl_803A9768, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_803A9768_H
#define GAME_RECORDS_LBL_803A9768_H

#include "dolphin/types.h"

typedef struct Work803A9768 Work803A9768;

struct Work803A9768 {
    /* 0x00 */ u32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ u8 pad_08[0x270];
    /* 0x278 */ u32 field_278;
    /* 0x27C */ f32 field_27C;
    /* 0x280 */ f32 field_280;
    /* 0x284 */ f32 field_284;
    /* 0x288 */ f32 field_288;
    /* 0x28C */ f32 field_28C;
    /* 0x290 */ f32 field_290;
    /* 0x294 */ f32 field_294;
    /* 0x298 */ f32 field_298;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work803A9768, field_0) == 0x0, "Work803A9768");
_Static_assert(__builtin_offsetof(Work803A9768, field_4) == 0x4, "Work803A9768");
_Static_assert(__builtin_offsetof(Work803A9768, field_278) == 0x278, "Work803A9768");
_Static_assert(__builtin_offsetof(Work803A9768, field_27C) == 0x27C, "Work803A9768");
_Static_assert(__builtin_offsetof(Work803A9768, field_280) == 0x280, "Work803A9768");
_Static_assert(__builtin_offsetof(Work803A9768, field_284) == 0x284, "Work803A9768");
_Static_assert(__builtin_offsetof(Work803A9768, field_288) == 0x288, "Work803A9768");
_Static_assert(__builtin_offsetof(Work803A9768, field_28C) == 0x28C, "Work803A9768");
_Static_assert(__builtin_offsetof(Work803A9768, field_290) == 0x290, "Work803A9768");
_Static_assert(__builtin_offsetof(Work803A9768, field_294) == 0x294, "Work803A9768");
_Static_assert(__builtin_offsetof(Work803A9768, field_298) == 0x298, "Work803A9768");
#endif

#endif
