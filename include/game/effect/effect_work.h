/* The work records of the visual effects (effect_visual.c), as their code reads them. Offsets are the console's; the port's tools check them on every build with a compiler for it. */
#ifndef GAME_EFFECT_WORK_H
#define GAME_EFFECT_WORK_H

#include "dolphin/types.h"

typedef struct FilterKey FilterKey;
typedef struct FilterWork FilterWork;
typedef struct EffectValueKey EffectValueKey;
typedef struct EnvMapWork EnvMapWork;
typedef struct BlurWork BlurWork;

struct FilterKey {
    /* 0x00 */ u8 start[4];
    /* 0x04 */ u8 end[4];
    /* 0x08 */ u32 frames;
    /* 0x0C */ u16 handle;
    /* 0x0E */ u8 pad_0E[0x2];
    /* 0x10 */ u8* next;
};

struct FilterWork {
    /* 0x00 */ void* model;
    /* 0x04 */ void* materials[17];
    /* 0x48 */ u32 materialCount;
    /* 0x4C */ u8 perMaterial;
    /* 0x4D */ u8 pad_4D[0x1];
    /* 0x4E */ u8 resetPE;
    /* 0x4F */ u8 keepModulation;
    /* 0x50 */ u8* keys;
    /* 0x54 */ u8* current;
    /* 0x58 */ u32 elapsed;
};

struct EffectValueKey {
    /* 0x00 */ f32 start;
    /* 0x04 */ f32 end;
    /* 0x08 */ u32 frames;
    /* 0x0C */ u16 handle;
    /* 0x0E */ u8 pad_0E[0x2];
    /* 0x10 */ u8* next;
};

struct EnvMapWork {
    /* 0x00 */ void* model;
    /* 0x04 */ void* texture;
    /* 0x08 */ void* matrix;
    /* 0x0C */ u8* keys;
    /* 0x10 */ u8* current;
    /* 0x14 */ u32 elapsed;
};

struct BlurWork {
    /* 0x00 */ void* model;
    /* 0x04 */ void** materials;
    /* 0x08 */ s32 materialCount;
    /* 0x0C */ void* texture;
    /* 0x10 */ s32 capture;
    /* 0x14 */ u8* keys;
    /* 0x18 */ u8* current;
    /* 0x1C */ u32 elapsed;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(FilterKey, start) == 0x0, "FilterKey");
_Static_assert(__builtin_offsetof(FilterKey, end) == 0x4, "FilterKey");
_Static_assert(__builtin_offsetof(FilterKey, frames) == 0x8, "FilterKey");
_Static_assert(__builtin_offsetof(FilterKey, handle) == 0xC, "FilterKey");
_Static_assert(__builtin_offsetof(FilterKey, next) == 0x10, "FilterKey");
_Static_assert(__builtin_offsetof(FilterWork, model) == 0x0, "FilterWork");
_Static_assert(__builtin_offsetof(FilterWork, materials) == 0x4, "FilterWork");
_Static_assert(__builtin_offsetof(FilterWork, materialCount) == 0x48, "FilterWork");
_Static_assert(__builtin_offsetof(FilterWork, perMaterial) == 0x4C, "FilterWork");
_Static_assert(__builtin_offsetof(FilterWork, resetPE) == 0x4E, "FilterWork");
_Static_assert(__builtin_offsetof(FilterWork, keepModulation) == 0x4F, "FilterWork");
_Static_assert(__builtin_offsetof(FilterWork, keys) == 0x50, "FilterWork");
_Static_assert(__builtin_offsetof(FilterWork, current) == 0x54, "FilterWork");
_Static_assert(__builtin_offsetof(FilterWork, elapsed) == 0x58, "FilterWork");
_Static_assert(__builtin_offsetof(EffectValueKey, start) == 0x0, "EffectValueKey");
_Static_assert(__builtin_offsetof(EffectValueKey, end) == 0x4, "EffectValueKey");
_Static_assert(__builtin_offsetof(EffectValueKey, frames) == 0x8, "EffectValueKey");
_Static_assert(__builtin_offsetof(EffectValueKey, handle) == 0xC, "EffectValueKey");
_Static_assert(__builtin_offsetof(EffectValueKey, next) == 0x10, "EffectValueKey");
_Static_assert(__builtin_offsetof(EnvMapWork, model) == 0x0, "EnvMapWork");
_Static_assert(__builtin_offsetof(EnvMapWork, texture) == 0x4, "EnvMapWork");
_Static_assert(__builtin_offsetof(EnvMapWork, matrix) == 0x8, "EnvMapWork");
_Static_assert(__builtin_offsetof(EnvMapWork, keys) == 0xC, "EnvMapWork");
_Static_assert(__builtin_offsetof(EnvMapWork, current) == 0x10, "EnvMapWork");
_Static_assert(__builtin_offsetof(EnvMapWork, elapsed) == 0x14, "EnvMapWork");
_Static_assert(__builtin_offsetof(BlurWork, model) == 0x0, "BlurWork");
_Static_assert(__builtin_offsetof(BlurWork, materials) == 0x4, "BlurWork");
_Static_assert(__builtin_offsetof(BlurWork, materialCount) == 0x8, "BlurWork");
_Static_assert(__builtin_offsetof(BlurWork, texture) == 0xC, "BlurWork");
_Static_assert(__builtin_offsetof(BlurWork, capture) == 0x10, "BlurWork");
_Static_assert(__builtin_offsetof(BlurWork, keys) == 0x14, "BlurWork");
_Static_assert(__builtin_offsetof(BlurWork, current) == 0x18, "BlurWork");
_Static_assert(__builtin_offsetof(BlurWork, elapsed) == 0x1C, "BlurWork");
_Static_assert(sizeof(FilterKey) == 0x14, "FilterKey");
_Static_assert(sizeof(FilterWork) == 0x5C, "FilterWork");
_Static_assert(sizeof(EffectValueKey) == 0x14, "EffectValueKey");
_Static_assert(sizeof(EnvMapWork) == 0x18, "EnvMapWork");
_Static_assert(sizeof(BlurWork) == 0x20, "BlurWork");
#endif

#endif
