/**
 * @file gs_gfx.h
 * @brief GSgfx -- Genius Sonority graphics subsystem for Pokemon Colosseum.
 *
 * The GSgfxState layout below documents the 0x5A0-byte state structure
 * referenced by the gs_gfx.c functions through lbl_8047AA80.
 *
 * This header previously also declared a set of friendly-named wrapper
 * functions (GSgfxInit, GSgfxSetVideoMode, GSgfxEnableRendering,
 * GSgfxSwapBuffers, GSgfxSetDrawMode, GSgfxGetFrameCount,
 * GSgfxGetTickCount) whose bodies lived in gs_gfx.c behind a dead
 * `#ifdef PCPORT` (PCPORT is never defined anywhere in this build). None
 * of those names appear in config/GC6E01/symbols.txt; the prototypes have
 * been removed along with the dead definitions.
 *
 * Address range: 0x800D3074 - 0x800D3E4C (approx.)
 */
#ifndef GS_GFX_H
#define GS_GFX_H

#include "dolphin/types.h"

/* -----------------------------------------------------------------------
 * GSgfx global state structure -- 0x5A0 bytes.
 * Allocated from GSmem, pointer stored at lbl_8047AA80.
 * ----------------------------------------------------------------------- */
#include "game/gs_gfx_state.h"

extern GSgfxState* lbl_8047AA80;

u32 GSgetFrameStep(void);

/* -----------------------------------------------------------------------
 * TV standards taken by GSgfxInit / fn_800D37D4; each selects one row of
 * render modes (the SDK GXNtsc*, GXPal*, GXEurgb60Hz* and GXMpal* objects).
 * ----------------------------------------------------------------------- */
#define GSGFX_VMODE_NTSC       1
#define GSGFX_VMODE_PAL50      2
#define GSGFX_VMODE_PAL60      3 /* EURGB60 */
#define GSGFX_VMODE_MPAL       4

#endif /* GS_GFX_H */
