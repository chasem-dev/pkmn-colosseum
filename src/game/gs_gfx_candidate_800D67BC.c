/**
 * @file gs_gfx_candidate_800D67BC.c
 * @brief GS graphics vertex-batch draw, 0x800D67BC - 0x800D6A00.
 *
 * Function-boundary carve of fn_800D67BC. The range needs nothing its TU
 * would own: no jump table, no pooled constant, and the primitive table
 * (lbl_80314350) and draw counters (lbl_804001F0) stay extern.
 *
 * Retail expands fn_800D6A80 (the vertex/primitive counter, out of line at
 * 0x800D6A80 and owned by gs_gfx_exact_800D6A00.c) at the end of this
 * function, with the two counter addresses constant-folded. The callee
 * sits later in the TU than this caller, so the original build inlined it
 * with deferred inlining. The carve reproduces the same expansion by
 * defining the same fn_800D6A80 source `inline` ahead of the caller, which
 * emits no second fn_800D6A80 symbol.
 */
#include "game/gs_gfx_state.h"
#include "dolphin/types.h"

extern void fn_800DB758(u16 vertCount);
extern void gfxRecordCommand(u32, u32, ...);
extern void gfxVtxDescClear(u8*);
extern void gfxVtxDescSetAttr(u8*, u32, u32, u32, u32, u8, u32, u8);
extern void gfxLoadVtxDesc(u32);
extern void gfxSetupChannelsTev(u32);
extern void GXBegin(u32, u32, u16);

extern u32 lbl_8047AA80;
extern u32 lbl_80314350[];
extern u8 lbl_804001F0[];

inline void fn_800D6A80(u16 vertCount, s32 type, u32* totalVerts, u32* totalPrims) {
    *totalVerts += vertCount;
    switch (type) {
        case 3: *totalPrims += vertCount / 3; break;
        case 4:
        case 5: *totalPrims += vertCount - 2; break;
        case 6:
        case 7: *totalPrims += (vertCount >> 1); break;
    }
}

void gfxBegin(u16 vertCount) {
    if (((GSgfxState*)lbl_8047AA80)->gammaMode == 1) {
        fn_800DB758(vertCount);
        return;
    }
    if (*(s32*)lbl_8047AA80 == 1) {
        gfxRecordCommand(2, 1, vertCount);
        return;
    }
    if (((GSgfxState*)lbl_8047AA80)->scissorDirty != ((GSgfxState*)lbl_8047AA80)->viewportDirty) {
        return;
    }
    if (((u32)((GSgfxState*)lbl_8047AA80)->frameCounter & ((GSgfxState*)lbl_8047AA80)->fifoSize) == 0) {
        return;
    }

    if (((GSgfxState*)lbl_8047AA80)->field_24 == 0) {
        gfxVtxDescClear((u8*)((GSgfxState*)lbl_8047AA80)->lightMask);
        gfxVtxDescSetAttr((u8*)((GSgfxState*)lbl_8047AA80)->lightMask, 1, 0, 1, 4, 0, 0, 0);
        if (((GSgfxState*)lbl_8047AA80)->field_10 & 4) {
            gfxVtxDescSetAttr((u8*)((GSgfxState*)lbl_8047AA80)->lightMask, 2, 0, 2, 4, 0, 0, 0);
        }
        if (((GSgfxState*)lbl_8047AA80)->field_10 & 1) {
            gfxVtxDescSetAttr((u8*)((GSgfxState*)lbl_8047AA80)->lightMask, 4, 0, 6, 10, 0, 0, 0);
        }
        if (((GSgfxState*)lbl_8047AA80)->field_10 & 2) {
            gfxVtxDescSetAttr((u8*)((GSgfxState*)lbl_8047AA80)->lightMask, 6, 0, 8, 4, 0, 0, 0);
        }
        ((GSgfxState*)lbl_8047AA80)->field_24 = ((GSgfxState*)lbl_8047AA80)->lightMask;
    }

    if ((s32)((GSgfxState*)lbl_8047AA80)->drawFlags == 7) {
        vertCount = (vertCount & 0x7fff) << 1;
    }

    gfxLoadVtxDesc(((GSgfxState*)lbl_8047AA80)->field_24);
    gfxSetupChannelsTev(((GSgfxState*)lbl_8047AA80)->field_24);
    GXBegin(lbl_80314350[((GSgfxState*)lbl_8047AA80)->drawFlags],
                *(u32*)(((GSgfxState*)lbl_8047AA80)->field_24 + 0x4), vertCount);
    fn_800D6A80(vertCount, (s32)((GSgfxState*)lbl_8047AA80)->drawFlags,
                (u32*)(lbl_804001F0 + 0xc), (u32*)(lbl_804001F0 + 0x4));
}
