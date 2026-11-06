/**
 * @file menuPokemonOpen_exact.c
 * @brief Party-menu entry-point wrappers.
 */
#include "game/records/lbl_803A1D40.h"
#include "dolphin/types.h"

void menuPokemonOpenItemGive(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
    extern u8 lbl_803A1D40[];
    extern void menuPokemonOpenSub(u32, u32, u32, u32, u32, u32);

    lbl_803A1D40[4] = 1;
    menuPokemonOpenSub(5, arg0, arg1, arg2, arg3, 1);
}

void menuPokemonOpenItemUse(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
    extern u8 lbl_803A1D40[];
    extern void menuPokemonOpenSub();

    lbl_803A1D40[4] = 1;
    menuPokemonOpenSub(arg0, 0, 0, arg2, arg3, arg1);
}

void menuPokemonOpenFight(u8 arg0, u8 arg1, u32 arg2, u32 arg3)
{
    extern u8 lbl_803A1D40[];
    extern void menuPokemonOpenSub(u32, u32, u32, u32, u32, u32);

    if (arg0 == 1) {
        lbl_803A1D40[4] = 0;
    } else {
        lbl_803A1D40[4] = 1;
    }
    ((Work803A1D40*)lbl_803A1D40)->field_18 = arg3;
    menuPokemonOpenSub(2, 0, 0, arg1, arg2, 1);
}

void menuPokemonOpen(u32 arg0, u32 arg1, u32 arg2)
{
    extern u8 lbl_803A1D40[];
    extern void menuPokemonOpenSub(u32, u32, u32, u32, u32, u32);

    lbl_803A1D40[4] = 1;
    menuPokemonOpenSub(arg0, 0, 0, arg1, arg2, 1);
}
