/* The record at lbl_802EF0A8, generated from what its code reads. Offsets are the console's; the port's tools check them on every build with a compiler for it. Its names are offsets until someone works out what each field is. */
#ifndef GAME_RECORDS_LBL_802EF0A8_H
#define GAME_RECORDS_LBL_802EF0A8_H

#include "dolphin/types.h"

typedef struct Work802EF0A8 Work802EF0A8;

struct Work802EF0A8 {
    /* 0x00 */ u8 pad_00[0x4EFE];
    /* 0x4EFE */ s16 field_4EFE;
    /* 0x4F00 */ s16 field_4F00;
    /* 0x4F02 */ u8 pad_4F02[0xA0];
    /* 0x4FA2 */ s16 field_4FA2;
    /* 0x4FA4 */ s16 field_4FA4;
    /* 0x4FA6 */ s16 field_4FA6;
    /* 0x4FA8 */ s16 field_4FA8;
    /* 0x4FAA */ u8 pad_4FAA[0x6A];
    /* 0x5014 */ s16 field_5014;
    /* 0x5016 */ u8 pad_5016[0x36];
    /* 0x504C */ s16 field_504C;
    /* 0x504E */ u8 pad_504E[0x50];
    /* 0x509E */ s16 field_509E;
    /* 0x50A0 */ s16 field_50A0;
    /* 0x50A2 */ u8 pad_50A2[0x670];
    /* 0x5712 */ s16 field_5712;
    /* 0x5714 */ s16 field_5714;
    /* 0x5716 */ s16 field_5716;
    /* 0x5718 */ s16 field_5718;
    /* 0x571A */ u8 pad_571A[0xA2];
    /* 0x57BC */ s16 field_57BC;
    /* 0x57BE */ u8 pad_57BE[0x36];
    /* 0x57F4 */ s16 field_57F4;
    /* 0x57F6 */ u8 pad_57F6[0x1A0];
    /* 0x5996 */ s16 field_5996;
    /* 0x5998 */ s16 field_5998;
    /* 0x599A */ u8 pad_599A[0x18];
    /* 0x59B2 */ s16 field_59B2;
    /* 0x59B4 */ s16 field_59B4;
    /* 0x59B6 */ u8 pad_59B6[0x620];
    /* 0x5FD6 */ s16 field_5FD6;
    /* 0x5FD8 */ s16 field_5FD8;
    /* 0x5FDA */ u8 pad_5FDA[0xFF0];
    /* 0x6FCA */ s16 field_6FCA;
    /* 0x6FCC */ s16 field_6FCC;
    /* 0x6FCE */ u8 pad_6FCE[0x130];
    /* 0x70FE */ s16 field_70FE;
    /* 0x7100 */ u8 pad_7100[0x2BA];
    /* 0x73BA */ s16 field_73BA;
    /* 0x73BC */ u8 pad_73BC[0x39A];
    /* 0x7756 */ s16 field_7756;
    /* 0x7758 */ u8 pad_7758[0x1A];
    /* 0x7772 */ s16 field_7772;
    /* 0x7774 */ u8 pad_7774[0x1536];
    /* 0x8CAA */ s16 field_8CAA;
    /* 0x8CAC */ u8 pad_8CAC[0x1A];
    /* 0x8CC6 */ s16 field_8CC6;
    /* 0x8CC8 */ u8 pad_8CC8[0xEE38];
    /* 0x17B00 */ s16 field_17B00;
    /* 0x17B02 */ u8 pad_17B02[0x1A];
    /* 0x17B1C */ s16 field_17B1C;
    /* 0x17B1E */ u8 pad_17B1E[0x1A];
    /* 0x17B38 */ s16 field_17B38;
    /* 0x17B3A */ u8 pad_17B3A[0x18];
    /* 0x17B52 */ s16 field_17B52;
    /* 0x17B54 */ s16 field_17B54;
    /* 0x17B56 */ s16 field_17B56;
    /* 0x17B58 */ s16 field_17B58;
    /* 0x17B5A */ u8 pad_17B5A[0x9368];
    /* 0x20EC2 */ s16 field_20EC2;
};

#if defined(__clang__)
_Static_assert(__builtin_offsetof(Work802EF0A8, field_4EFE) == 0x4EFE, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_4F00) == 0x4F00, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_4FA2) == 0x4FA2, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_4FA4) == 0x4FA4, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_4FA6) == 0x4FA6, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_4FA8) == 0x4FA8, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_5014) == 0x5014, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_504C) == 0x504C, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_509E) == 0x509E, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_50A0) == 0x50A0, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_5712) == 0x5712, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_5714) == 0x5714, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_5716) == 0x5716, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_5718) == 0x5718, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_57BC) == 0x57BC, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_57F4) == 0x57F4, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_5996) == 0x5996, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_5998) == 0x5998, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_59B2) == 0x59B2, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_59B4) == 0x59B4, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_5FD6) == 0x5FD6, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_5FD8) == 0x5FD8, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_6FCA) == 0x6FCA, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_6FCC) == 0x6FCC, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_70FE) == 0x70FE, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_73BA) == 0x73BA, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_7756) == 0x7756, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_7772) == 0x7772, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_8CAA) == 0x8CAA, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_8CC6) == 0x8CC6, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_17B00) == 0x17B00, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_17B1C) == 0x17B1C, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_17B38) == 0x17B38, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_17B52) == 0x17B52, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_17B54) == 0x17B54, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_17B56) == 0x17B56, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_17B58) == 0x17B58, "Work802EF0A8");
_Static_assert(__builtin_offsetof(Work802EF0A8, field_20EC2) == 0x20EC2, "Work802EF0A8");
#endif

#endif
