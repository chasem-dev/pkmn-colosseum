/* The PDA's state, lbl_803A6818, as its code reads it. Offsets are the console's; the port's tools check them on every build with a compiler for it. A name that says nothing is a field whose purpose isn't known yet. */
#ifndef GAME_PDA_STATE_H
#define GAME_PDA_STATE_H

#include "dolphin/types.h"

typedef struct PdaState PdaState;

struct PdaState {
    /* 0x00 */ u8 pad_00[0x14];
    /* 0x14 */ s32 phase;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 state;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 nextPhase;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ u8 pad_2C[0x10];
    /* 0x3C */ f32 easeRate;
    /* 0x40 */ u8 pad_40[0xC];
    /* 0x4C */ f32 easeA;
    /* 0x50 */ f32 easeATarget;
    /* 0x54 */ f32 easeB;
    /* 0x58 */ f32 easeBTarget;
    /* 0x5C */ f32 easeC;
    /* 0x60 */ f32 easeCTarget;
    /* 0x64 */ f32 field_64;
    /* 0x68 */ u8 pad_68[0x4];
    /* 0x6C */ f32 field_6C[3];
    /* 0x78 */ s32 field_78;
    /* 0x7C */ u8 pad_7C[0x24];
    /* 0xA0 */ void* owner;
    /* 0xA4 */ u8 pad_A4[0x68];
    /* 0x10C */ void* cameraRes;
    /* 0x110 */ void* animRes;
    /* 0x114 */ void* camera;
    /* 0x118 */ u8 pad_118[0x24];
    /* 0x13C */ f32 perspective[4];
    /* 0x14C */ u8 pad_14C[0x8];
    /* 0x154 */ s32 field_154;
    /* 0x158 */ s8 field_158;
    /* 0x159 */ s8 field_159;
    /* 0x15A */ s8 field_15A;
    /* 0x15B */ s8 field_15B;
    /* 0x15C */ s8 field_15C;
    /* 0x15D */ s8 field_15D;
    /* 0x15E */ s8 field_15E;
    /* 0x15F */ s8 field_15F;
    /* 0x160 */ s8 field_160;
    /* 0x161 */ u8 pad_161[0x3];
    /* 0x164 */ u8 field_164;
    /* 0x165 */ u8 pad_165[0x13];
    /* 0x178 */ u8 field_178;
    /* 0x179 */ u8 pad_179[0x13];
    /* 0x18C */ u8 field_18C;
    /* 0x18D */ u8 pad_18D[0x13];
    /* 0x1A0 */ u8 field_1A0;
    /* 0x1A1 */ u8 pad_1A1[0x13];
    /* 0x1B4 */ u8 field_1B4;
    /* 0x1B5 */ u8 pad_1B5[0x13];
    /* 0x1C8 */ s8 field_1C8;
    /* 0x1C9 */ s8 field_1C9;
    /* 0x1CA */ u8 pad_1CA[0x2];
    /* 0x1CC */ f32 field_1CC[4];
    /* 0x1DC */ f32 field_1DC;
    /* 0x1E0 */ f32 field_1E0;
    /* 0x1E4 */ s32 field_1E4;
    /* 0x1E8 */ u8 pad_1E8[0x60];
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(PdaState, phase) == 0x14, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_18) == 0x18, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, state) == 0x1C, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_20) == 0x20, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, nextPhase) == 0x24, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_28) == 0x28, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, easeRate) == 0x3C, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, easeA) == 0x4C, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, easeATarget) == 0x50, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, easeB) == 0x54, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, easeBTarget) == 0x58, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, easeC) == 0x5C, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, easeCTarget) == 0x60, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_64) == 0x64, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_6C) == 0x6C, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_78) == 0x78, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, owner) == 0xA0, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, cameraRes) == 0x10C, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, animRes) == 0x110, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, camera) == 0x114, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, perspective) == 0x13C, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_154) == 0x154, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_158) == 0x158, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_159) == 0x159, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_15A) == 0x15A, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_15B) == 0x15B, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_15C) == 0x15C, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_15D) == 0x15D, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_15E) == 0x15E, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_15F) == 0x15F, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_160) == 0x160, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_164) == 0x164, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_178) == 0x178, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_18C) == 0x18C, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_1A0) == 0x1A0, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_1B4) == 0x1B4, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_1C8) == 0x1C8, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_1C9) == 0x1C9, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_1CC) == 0x1CC, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_1DC) == 0x1DC, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_1E0) == 0x1E0, "PdaState");
_Static_assert(__builtin_offsetof(PdaState, field_1E4) == 0x1E4, "PdaState");
_Static_assert(sizeof(PdaState) == 0x248, "PdaState");
#endif

#endif
