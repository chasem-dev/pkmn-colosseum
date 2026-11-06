/* MSG_TASK_WORK, the name the game's symbols give it, as gs_msg.c reads it. Offsets are the console's; the port's tools check them on every build with a compiler for it. A name that says nothing is a field whose purpose isn't known yet. */
#ifndef GAME_GS_MSG_WORK_H
#define GAME_GS_MSG_WORK_H

#include "dolphin/types.h"

typedef struct MSG_TASK_WORK MSG_TASK_WORK;

struct MSG_TASK_WORK {
    /* 0x00 */ u8 pad_00[0x4];
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 field_0C;
    /* 0x10 */ f32 field_10;
    /* 0x14 */ f32 field_14;
    /* 0x18 */ s16 rectWidth;
    /* 0x1A */ s16 rectHeight;
    /* 0x1C */ u32 flags;
    /* 0x20 */ u16 font;
    /* 0x22 */ u8 field_22;
    /* 0x23 */ u8 field_23;
    /* 0x24 */ s32 color;
    /* 0x28 */ u8* field_28;
    /* 0x2C */ u8* field_2C;
    /* 0x30 */ u8* cursor;
    /* 0x34 */ u8 pad_34[0xC];
    /* 0x40 */ s8 depth;
    /* 0x41 */ u8 pad_41[0x1];
    /* 0x42 */ s8 field_42;
    /* 0x43 */ u8 pad_43[0x1];
    /* 0x44 */ s8 field_44;
    /* 0x45 */ u8 pad_45[0x7];
    /* 0x4C */ f32 field_4C;
    /* 0x50 */ f32 field_50;
    /* 0x54 */ u8* field_54;
    /* 0x58 */ u8 pad_58[0x4];
    /* 0x5C */ f32 field_5C;
    /* 0x60 */ f32 field_60;
    /* 0x64 */ f32 field_64;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, x) == 0x4, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, y) == 0x8, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_0C) == 0xC, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_10) == 0x10, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_14) == 0x14, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, rectWidth) == 0x18, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, rectHeight) == 0x1A, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, flags) == 0x1C, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, font) == 0x20, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_22) == 0x22, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_23) == 0x23, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, color) == 0x24, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_28) == 0x28, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_2C) == 0x2C, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, cursor) == 0x30, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, depth) == 0x40, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_42) == 0x42, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_44) == 0x44, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_4C) == 0x4C, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_50) == 0x50, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_54) == 0x54, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_5C) == 0x5C, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_60) == 0x60, "MSG_TASK_WORK");
_Static_assert(__builtin_offsetof(MSG_TASK_WORK, field_64) == 0x64, "MSG_TASK_WORK");
_Static_assert(sizeof(MSG_TASK_WORK) == 0x68, "MSG_TASK_WORK");
#endif

#endif
