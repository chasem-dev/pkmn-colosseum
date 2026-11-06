/* Work records as their code reads them. Offsets are the console's; the port's tools check them on every build with a compiler for it. A name that says nothing is a field whose purpose isn't known yet. */
#ifndef GAME_GS_WORK_RECORDS_H
#define GAME_GS_WORK_RECORDS_H

#include "dolphin/types.h"

typedef struct GSlightWork GSlightWork;
typedef struct WazaViewerState WazaViewerState;

struct GSlightWork {
    /* 0x00 */ u8 pad_00[0x4];
    /* 0x04 */ s32 type;
    /* 0x08 */ u32 animData;
    /* 0x0C */ u32 lobj;
    /* 0x10 */ u32 field_10;
    /* 0x14 */ f32 field_14;
    /* 0x18 */ f32 field_18;
    /* 0x1C */ f32 field_1C;
    /* 0x20 */ u32 field_20;
    /* 0x24 */ u32 field_24;
    /* 0x28 */ f32 field_28;
    /* 0x2C */ f32 field_2C;
    /* 0x30 */ f32 field_30;
    /* 0x34 */ u32 field_34;
    /* 0x38 */ u32 field_38;
    /* 0x3C */ u32 field_3C;
    /* 0x40 */ u16 field_40;
    /* 0x42 */ u16 field_42;
    /* 0x44 */ u8 pad_44[0x4];
    /* 0x48 */ u32 field_48;
    /* 0x4C */ u32 field_4C;
    /* 0x50 */ u32 field_50;
    /* 0x54 */ f32 field_54;
    /* 0x58 */ u32 field_58;
    /* 0x5C */ u32 animType;
    /* 0x60 */ u32 field_60;
    /* 0x64 */ f32 animRate;
    /* 0x68 */ f32 animFrame;
    /* 0x6C */ f32 field_6C;
    /* 0x70 */ u8 pad_70[0x1];
    /* 0x71 */ s8 field_71;
    /* 0x72 */ u8 pad_72[0x2];
};

struct WazaViewerState {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ u8 pad_08[0x4];
    /* 0x0C */ u32 field_C;
    /* 0x10 */ void* field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ u8 pad_1C[0x600];
    /* 0x61C */ void* field_61C;
    /* 0x620 */ void* field_620;
    /* 0x624 */ s32 field_624;
    /* 0x628 */ u8 pad_628[0x4];
    /* 0x62C */ s32 field_62C;
    /* 0x630 */ u8 pad_630[0x8];
    /* 0x638 */ s32 field_638;
    /* 0x63C */ s32 field_63C;
    /* 0x640 */ u8 pad_640[0x1C];
    /* 0x65C */ s32 field_65C;
    /* 0x660 */ u16 field_660;
    /* 0x662 */ u8 pad_662[0x2];
    /* 0x664 */ s32 field_664;
    /* 0x668 */ u16 field_668;
    /* 0x66A */ u8 pad_66A[0x2];
    /* 0x66C */ u32 field_66C;
    /* 0x670 */ u8 pad_670[0x200];
    /* 0x870 */ s32 field_870;
    /* 0x874 */ s32 field_874;
    /* 0x878 */ void* field_878;
    /* 0x87C */ u8 pad_87C[0x4];
    /* 0x880 */ s32 field_880;
    /* 0x884 */ u8 pad_884[0x4];
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(GSlightWork, type) == 0x4, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, animData) == 0x8, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, lobj) == 0xC, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_10) == 0x10, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_14) == 0x14, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_18) == 0x18, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_1C) == 0x1C, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_20) == 0x20, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_24) == 0x24, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_28) == 0x28, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_2C) == 0x2C, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_30) == 0x30, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_34) == 0x34, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_38) == 0x38, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_3C) == 0x3C, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_40) == 0x40, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_42) == 0x42, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_48) == 0x48, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_4C) == 0x4C, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_50) == 0x50, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_54) == 0x54, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_58) == 0x58, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, animType) == 0x5C, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_60) == 0x60, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, animRate) == 0x64, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, animFrame) == 0x68, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_6C) == 0x6C, "GSlightWork");
_Static_assert(__builtin_offsetof(GSlightWork, field_71) == 0x71, "GSlightWork");
_Static_assert(__builtin_offsetof(WazaViewerState, field_0) == 0x0, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_4) == 0x4, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_C) == 0xC, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_10) == 0x10, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_14) == 0x14, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_18) == 0x18, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_61C) == 0x61C, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_620) == 0x620, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_624) == 0x624, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_62C) == 0x62C, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_638) == 0x638, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_63C) == 0x63C, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_65C) == 0x65C, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_660) == 0x660, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_664) == 0x664, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_668) == 0x668, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_66C) == 0x66C, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_870) == 0x870, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_874) == 0x874, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_878) == 0x878, "WazaViewerState");
_Static_assert(__builtin_offsetof(WazaViewerState, field_880) == 0x880, "WazaViewerState");
_Static_assert(sizeof(GSlightWork) == 0x74, "GSlightWork");
_Static_assert(sizeof(WazaViewerState) == 0x888, "WazaViewerState");
#endif

#endif
