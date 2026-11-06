/* The work records of the visual effects (effect_visual.c), as their code reads them. Offsets are the console's; the port's tools check them on every build with a compiler for it. */
#ifndef GAME_EFFECT_WORK_H
#define GAME_EFFECT_WORK_H

#include "dolphin/types.h"

typedef struct FilterKey FilterKey;
typedef struct FilterWork FilterWork;
typedef struct EffectValueKey EffectValueKey;
typedef struct EnvMapWork EnvMapWork;
typedef struct BlurWork BlurWork;
typedef struct LightningBolt LightningBolt;
typedef struct LightningWork LightningWork;
typedef struct ElectronWork ElectronWork;
typedef struct AuraWork AuraWork;
typedef struct BillboardWork BillboardWork;

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

struct LightningBolt {
    /* 0x00 */ u8 pad_00[0x960];
    /* 0x960 */ f32 start[3];
    /* 0x96C */ f32 end[3];
    /* 0x978 */ u32 segments;
};

struct LightningWork {
    /* 0x00 */ u8 pad_00[0x4];
    /* 0x04 */ u8* bolts;
    /* 0x08 */ u16 boltCount;
    /* 0x0A */ u16 resGroup;
    /* 0x0C */ u16 resId;
    /* 0x0E */ u8 pad_0E[0x2];
    /* 0x10 */ u16 frame;
    /* 0x12 */ u16 duration;
    /* 0x14 */ void* vtxDesc;
    /* 0x18 */ void* glowVtxDesc;
    /* 0x1C */ void* glowTexture;
    /* 0x20 */ u8 pad_20[0x8];
    /* 0x28 */ f32 scale[3];
    /* 0x34 */ u8 pad_34[0xC];
    /* 0x40 */ f32 noise[3];
    /* 0x4C */ f32 stepRange;
    /* 0x50 */ f32 turnRange;
    /* 0x54 */ f32 radiusBase;
    /* 0x58 */ f32 radiusRange;
    /* 0x5C */ f32 lengthBase;
    /* 0x60 */ f32 lengthRange;
    /* 0x64 */ f32 bend;
    /* 0x68 */ f32 glowBase;
    /* 0x6C */ f32 glowRange;
};

struct ElectronWork {
    /* 0x00 */ u8 pad_00[0x4];
    /* 0x04 */ void* vtxDesc;
    /* 0x08 */ u16 frame;
    /* 0x0A */ u16 duration;
    /* 0x0C */ u16 resGroup;
    /* 0x0E */ u16 resId;
    /* 0x10 */ f32 scale;
    /* 0x14 */ f32 field_14;
    /* 0x18 */ f32 segmentBase;
    /* 0x1C */ f32 segmentRange;
    /* 0x20 */ f32 chance;
};

struct AuraWork {
    /* 0x00 */ u8 pad_00[0x4];
    /* 0x04 */ void* texture;
    /* 0x08 */ u8 pad_08[0x10];
    /* 0x18 */ u8 enabled;
    /* 0x19 */ u8 pad_19[0x3];
    /* 0x1C */ f32 base;
    /* 0x20 */ f32 range;
    /* 0x24 */ f32 rate;
    /* 0x28 */ f32 alpha;
    /* 0x2C */ f32 wave;
    /* 0x30 */ u16 frame;
    /* 0x32 */ u16 duration;
};

struct BillboardWork {
    /* 0x00 */ u32 group;
    /* 0x04 */ u32 res04;
    /* 0x08 */ u32 modelRes;
    /* 0x0C */ u32 particleRes;
    /* 0x10 */ void* model;
    /* 0x14 */ void* particleBank;
    /* 0x18 */ u32 animType;
    /* 0x1C */ u16 animIndex;
    /* 0x1E */ u16 particleArg;
    /* 0x20 */ void* particle;
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
_Static_assert(__builtin_offsetof(LightningBolt, start) == 0x960, "LightningBolt");
_Static_assert(__builtin_offsetof(LightningBolt, end) == 0x96C, "LightningBolt");
_Static_assert(__builtin_offsetof(LightningBolt, segments) == 0x978, "LightningBolt");
_Static_assert(__builtin_offsetof(LightningWork, bolts) == 0x4, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, boltCount) == 0x8, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, resGroup) == 0xA, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, resId) == 0xC, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, frame) == 0x10, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, duration) == 0x12, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, vtxDesc) == 0x14, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, glowVtxDesc) == 0x18, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, glowTexture) == 0x1C, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, scale) == 0x28, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, noise) == 0x40, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, stepRange) == 0x4C, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, turnRange) == 0x50, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, radiusBase) == 0x54, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, radiusRange) == 0x58, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, lengthBase) == 0x5C, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, lengthRange) == 0x60, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, bend) == 0x64, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, glowBase) == 0x68, "LightningWork");
_Static_assert(__builtin_offsetof(LightningWork, glowRange) == 0x6C, "LightningWork");
_Static_assert(__builtin_offsetof(ElectronWork, vtxDesc) == 0x4, "ElectronWork");
_Static_assert(__builtin_offsetof(ElectronWork, frame) == 0x8, "ElectronWork");
_Static_assert(__builtin_offsetof(ElectronWork, duration) == 0xA, "ElectronWork");
_Static_assert(__builtin_offsetof(ElectronWork, resGroup) == 0xC, "ElectronWork");
_Static_assert(__builtin_offsetof(ElectronWork, resId) == 0xE, "ElectronWork");
_Static_assert(__builtin_offsetof(ElectronWork, scale) == 0x10, "ElectronWork");
_Static_assert(__builtin_offsetof(ElectronWork, field_14) == 0x14, "ElectronWork");
_Static_assert(__builtin_offsetof(ElectronWork, segmentBase) == 0x18, "ElectronWork");
_Static_assert(__builtin_offsetof(ElectronWork, segmentRange) == 0x1C, "ElectronWork");
_Static_assert(__builtin_offsetof(ElectronWork, chance) == 0x20, "ElectronWork");
_Static_assert(__builtin_offsetof(AuraWork, texture) == 0x4, "AuraWork");
_Static_assert(__builtin_offsetof(AuraWork, enabled) == 0x18, "AuraWork");
_Static_assert(__builtin_offsetof(AuraWork, base) == 0x1C, "AuraWork");
_Static_assert(__builtin_offsetof(AuraWork, range) == 0x20, "AuraWork");
_Static_assert(__builtin_offsetof(AuraWork, rate) == 0x24, "AuraWork");
_Static_assert(__builtin_offsetof(AuraWork, alpha) == 0x28, "AuraWork");
_Static_assert(__builtin_offsetof(AuraWork, wave) == 0x2C, "AuraWork");
_Static_assert(__builtin_offsetof(AuraWork, frame) == 0x30, "AuraWork");
_Static_assert(__builtin_offsetof(AuraWork, duration) == 0x32, "AuraWork");
_Static_assert(__builtin_offsetof(BillboardWork, group) == 0x0, "BillboardWork");
_Static_assert(__builtin_offsetof(BillboardWork, res04) == 0x4, "BillboardWork");
_Static_assert(__builtin_offsetof(BillboardWork, modelRes) == 0x8, "BillboardWork");
_Static_assert(__builtin_offsetof(BillboardWork, particleRes) == 0xC, "BillboardWork");
_Static_assert(__builtin_offsetof(BillboardWork, model) == 0x10, "BillboardWork");
_Static_assert(__builtin_offsetof(BillboardWork, particleBank) == 0x14, "BillboardWork");
_Static_assert(__builtin_offsetof(BillboardWork, animType) == 0x18, "BillboardWork");
_Static_assert(__builtin_offsetof(BillboardWork, animIndex) == 0x1C, "BillboardWork");
_Static_assert(__builtin_offsetof(BillboardWork, particleArg) == 0x1E, "BillboardWork");
_Static_assert(__builtin_offsetof(BillboardWork, particle) == 0x20, "BillboardWork");
_Static_assert(sizeof(FilterKey) == 0x14, "FilterKey");
_Static_assert(sizeof(FilterWork) == 0x5C, "FilterWork");
_Static_assert(sizeof(EffectValueKey) == 0x14, "EffectValueKey");
_Static_assert(sizeof(EnvMapWork) == 0x18, "EnvMapWork");
_Static_assert(sizeof(BlurWork) == 0x20, "BlurWork");
_Static_assert(sizeof(LightningBolt) == 0x97C, "LightningBolt");
_Static_assert(sizeof(LightningWork) == 0x70, "LightningWork");
_Static_assert(sizeof(ElectronWork) == 0x24, "ElectronWork");
_Static_assert(sizeof(AuraWork) == 0x34, "AuraWork");
_Static_assert(sizeof(BillboardWork) == 0x24, "BillboardWork");
#endif

#endif
