/**
 * @file gs_gfx_exact_800D9D68.c
 * @brief Matching GS graphics state range, 0x800D9D68-0x800DA578.
 */

#include "game/gs_gfx_state.h"
#include "dolphin/types.h"

extern u32 lbl_8047AA80;
extern void gfxRecordCommand(u32, ...);
extern u32 GScameraGetActiveCamera(void);
extern void GXSetScissor(u32, u32, u32, u32);
extern void GScameraSetScissor(u32, u16, u16, u16, u16);
extern void HSD_FogSet(u32);
extern u32 lbl_8047AA8C;
extern void GXSetCoPlanar(u32);
extern void GXSetClipMode(u32);
extern void GXSetCullMode(u32);
extern u8 lbl_8031453C[];
extern void GXSetDither(u32);
extern void GXSetAlphaCompare(u32, u8, u32, u32, u8);
extern u8 lbl_8031457C[];
extern u8 lbl_8031456C[];
extern void GXSetZMode(u32, u32, u32);
extern void GXSetZCompLoc(u32);
extern u8 lbl_8031454C[];
extern void GXSetColorUpdate(u32);
extern void GXSetAlphaUpdate(u32);
extern void GXSetDstAlpha(u32);
extern void GXSetBlendMode(u32, u32, u32, u32);
extern u8 lbl_803145D0[];
extern u32 lbl_8031459C[];
extern u32 lbl_803145A8[];

/* Retail marks every function in this physical island active. */
#pragma force_active on

void gfxSetScissor(u16 x1, u16 y1, u16 x2, u16 y2) {
    u32 state = lbl_8047AA80;
    if (*(s32*)state == 1) {
        gfxRecordCommand(0x37, 4, (u32)x1, (u32)y1, (u32)x2, (u32)y2);
    } else {
        GXSetScissor((u32)x1, (u32)y1, (u32)(x2 - x1) + 1, (u32)(y2 - y1) + 1);
        ((GSgfxState*)lbl_8047AA80)->scissorX1 = x1;
        ((GSgfxState*)lbl_8047AA80)->scissorY1 = y1;
        ((GSgfxState*)lbl_8047AA80)->scissorX2 = x2;
        ((GSgfxState*)lbl_8047AA80)->scissorY2 = y2;
        {
            u32 result = GScameraGetActiveCamera();
            if (result) {
                GScameraSetScissor(result, x1, y1, x2, y2);
            }
        }
    }
}

void fn_800D9E4C(s32 val) {
    u32 state = lbl_8047AA80;
    if (*(s32*)state == 1) {
        gfxRecordCommand(0x36, 1, val);
    } else {
        if (val == 1) {
            *(u8*)(state + 0x5d) = 1;
        } else if (val == 0) {
            *(u8*)(state + 0x5d) = 0;
        }
        if (((GSgfxState*)lbl_8047AA80)->field_5D == 1) {
            HSD_FogSet(lbl_8047AA8C);
        } else {
            HSD_FogSet(0);
        }
    }
}

void fn_800D9ED8(s32 val) {
    if (*(s32*)lbl_8047AA80 == 1) { gfxRecordCommand(0x35, 1, val); }
    else if (val == 1) { ((GSgfxState*)lbl_8047AA80)->viewportDirty = 1; }
    else if (val == 0) { ((GSgfxState*)lbl_8047AA80)->viewportDirty = 0; }
}

void gfxSetCoPlanar(s32 val) {
    u32 state = lbl_8047AA80;
    if (*(s32*)state == 1) { gfxRecordCommand(0x34, 1, val); }
    else {
        if (val == 1) { *(u8*)(state + 0x42d) = 1; }
        else if (val == 0) { *(u8*)(state + 0x42d) = 0; }
        GXSetCoPlanar(((GSgfxState*)lbl_8047AA80)->coPlanar);
    }
}

void gfxSetClipMode(s32 val) {
    u32 state = lbl_8047AA80;
    if (*(s32*)state == 1) { gfxRecordCommand(0x33, 1, val); }
    else {
        if (val == 1) { *(u8*)(state + 0x42c) = 0; }
        else if (val == 0) { *(u8*)(state + 0x42c) = 1; }
        GXSetClipMode(((GSgfxState*)lbl_8047AA80)->clipMode);
    }
}

void gfxSetCullMode(u32 idx) {
    if (*(s32*)lbl_8047AA80 == 1) { gfxRecordCommand(0x32, 1, idx); }
    else {
        ((GSgfxState*)lbl_8047AA80)->field_428 = ((u32*)lbl_8031453C)[idx];
        GXSetCullMode(((GSgfxState*)lbl_8047AA80)->field_428);
    }
}

void gfxSetDither(s32 val) {
    u32 state = lbl_8047AA80;
    if (*(s32*)state == 1) { gfxRecordCommand(0x31, 1, val); }
    else {
        if (val == 1) { *(u8*)(state + 0x426) = 1; }
        else if (val == 0) { *(u8*)(state + 0x426) = 0; }
        GXSetDither(((GSgfxState*)lbl_8047AA80)->dither);
    }
}

void gfxSetAlphaCompare(s32 enable, s32 comp0, u8 ref0, s32 op, s32 comp1, u8 ref1) {
    u32 state = lbl_8047AA80;
    if (*(s32*)state == 1) {
        gfxRecordCommand(0x30, 6, enable, comp0, (u32)ref0, op, comp1, (u32)ref1);
    } else {
        if (enable == 1) {
            *(u8*)(state + 0x425) = 1;
        } else if (enable == 0) {
            *(u8*)(state + 0x425) = 0;
        }
        if (((GSgfxState*)lbl_8047AA80)->field_425 == 0) {
            GXSetAlphaCompare(7, 0, 1, 7, 0);
        } else {
            GXSetAlphaCompare(((u32*)lbl_8031457C)[comp0], ref0,
                        ((u32*)lbl_8031456C)[op],
                        ((u32*)lbl_8031457C)[comp1], ref1);
        }
    }
}

void gfxSetZMode(s32 zEnable, s32 zFunc, s32 zUpdate) {
    u32 state = lbl_8047AA80;
    if (*(s32*)state == 1) {
        gfxRecordCommand(0x2f, 3, zEnable, zFunc, zUpdate);
    } else {
        if (zEnable == 1) {
            *(u8*)(state + 0x41c) = 1;
        } else if (zEnable == 0) {
            *(u8*)(state + 0x41c) = 0;
        }
        if (zUpdate == 1) {
            ((GSgfxState*)lbl_8047AA80)->field_424 = 1;
        } else if (zUpdate == 0) {
            ((GSgfxState*)lbl_8047AA80)->field_424 = 0;
        }
        ((GSgfxState*)lbl_8047AA80)->zFunc = *(u32*)(lbl_8031454C + zFunc * 4);
        GXSetZMode(((GSgfxState*)lbl_8047AA80)->field_41C, ((GSgfxState*)lbl_8047AA80)->zFunc, ((GSgfxState*)lbl_8047AA80)->field_41B);
        GXSetZCompLoc(((GSgfxState*)lbl_8047AA80)->field_424);
    }
}

void gfxSetUpdates(s32 zCompare, s32 zBeforeTexture, s32 zFunc) {
    u32 state = lbl_8047AA80;
    if (*(s32*)state == 1) {
        gfxRecordCommand(0x2e, 3, zCompare, zBeforeTexture, zFunc);
    } else {
        if (zCompare == 1) {
            *(u8*)(state + 0x419) = 1;
        } else if (zCompare == 0) {
            *(u8*)(state + 0x419) = 0;
        }
        if (zBeforeTexture == 1) {
            ((GSgfxState*)lbl_8047AA80)->field_41A = 1;
        } else if (zBeforeTexture == 0) {
            ((GSgfxState*)lbl_8047AA80)->field_41A = 0;
        }
        if (zFunc == 1) {
            ((GSgfxState*)lbl_8047AA80)->field_41B = 1;
        } else if (zFunc == 0) {
            ((GSgfxState*)lbl_8047AA80)->field_41B = 0;
        }
        GXSetColorUpdate(((GSgfxState*)lbl_8047AA80)->colorUpdate);
        GXSetAlphaUpdate(((GSgfxState*)lbl_8047AA80)->field_41A);
        GXSetZMode(((GSgfxState*)lbl_8047AA80)->field_41C,
                   ((GSgfxState*)lbl_8047AA80)->zFunc,
                   ((GSgfxState*)lbl_8047AA80)->field_41B);
    }
}

void gfxSetDstAlpha(s32 val, u8 b) {
    u32 state = lbl_8047AA80;
    if (*(s32*)state == 1) { gfxRecordCommand(0x2d, 2, val, (u32)b); }
    else {
        if (val == 1) { *(u8*)(state + 0x418) = 1; }
        else if (val == 0) { *(u8*)(state + 0x418) = 0; }
        GXSetDstAlpha(((GSgfxState*)lbl_8047AA80)->dstAlpha);
    }
}

void gfxSetBlendModeRaw(s32 val) {
    u32 state = lbl_8047AA80;
    if (*(s32*)state == 1) {
        gfxRecordCommand(0x2c, 1, val);
    } else if (val == 0) {
        GXSetBlendMode(0, 1, 1, 5);
        ((GSgfxState*)lbl_8047AA80)->fifoSize = 0x10;
    } else {
        GXSetBlendMode(2, 1, 1, *(u32*)(lbl_803145D0 + val * 4));
        ((GSgfxState*)lbl_8047AA80)->fifoSize = 0x2000;
    }
}

void gfxSetBlendMode(s32 a, s32 b, s32 c) {
    u32 state = lbl_8047AA80;
    if (*(s32*)state == 1) {
        gfxRecordCommand(0x2b, 3, a, b, c);
    } else if (a == 0) {
        GXSetBlendMode(0, 1, 1, 5);
        ((GSgfxState*)lbl_8047AA80)->fifoSize = 0x10;
    } else {
        GXSetBlendMode(lbl_8031459C[a], lbl_803145A8[b], lbl_803145A8[c], 5);
        ((GSgfxState*)lbl_8047AA80)->fifoSize = 0x2000;
    }
}
