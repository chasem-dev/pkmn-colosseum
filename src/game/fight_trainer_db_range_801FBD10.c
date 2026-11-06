/**
 * @file fight_trainer_db_range_801FBD10.c
 * @brief fightTrainerBios + fightTrainerDB + fightItemBios -- merged
 *        accessor farm, split from game/trainer.c (the XD fight-trainer
 *        bucket, 0x801F7F80-0x80201764), address range
 *        0x801FBD10-0x801FDB78, 317 fns.
 *
 * XD source units: game/pxdvs/app/fight/fightTrainerBios.cpp,
 *        fightTrainerDB.cpp, fightItemBios.cpp (kept merged: the six
 *        .sbss count/array-ptr pairs lbl_80478F08..F34 are referenced
 *        in non-address-monotonic text order, incompatible with a
 *        clean per-TU sbss split).
 * Physically split out of the trainer.c bucket by address (functions
 * bucketed via their /* 0xADDR *\/ markers), byte-identical
 * reconstruction verified against the original file.
 */
#include "game/trainer.h"
#include "game/bios_records.h"
#include "game/pokemon.h"

/* =========================================================================
 * External declarations (duplicated verbatim from the original
 * game/trainer.c preamble into every split segment, so each new
 * TU keeps the same external visibility it had before the split)
 * ========================================================================= */

/* pokemonGetStatus - Master data table resolver
 * The most-called function in the entire game (1769 calls).
 * Takes a context pointer, slot index, table ID, and flags.
 * Returns a pointer to the resolved data, or NULL. */
extern void* pokemonGetStatus(void* context, u32 slot, u16 tableId, u32 flags);

/* pokemonSetStatus - Master data table writer (544 calls) */
extern u32 pokemonSetStatus(void* context, u32 slot, u16 tableId, u32 flags, u32 value);

/* pokemonGrowBasisStatus - Data table auxiliary writer */
extern void pokemonGrowBasisStatus(void* context, u32 value);

/* itemGetStatus - Secondary data accessor (169 calls) */
extern u32 itemGetStatus(u32 context, u32 param, u16 field, u32 flags);

/* fightTargetGetPtr - PokemonSlotLookup (89 calls) */
extern u32 fightTargetGetPtr(u32 type, void* ptr, u32 param);

/* Category resolution sub-dispatchers (defined with real bodies at their
 * proper address-ordered locations, possibly in a sibling segment). */
void* fightTrainerDataBiosGetPtr(u16 slot); /* Battle trainer */
void* fightTrainerPokemonPartDataBiosGetPtr(u16 slot); /* Party config */
void* fightTrainerPokemonDataBiosGetPtr(u16 slot); /* Team roster */
void* fightTrainerAiDataBiosGetPtr(u16 slot); /* Story/event data */
void* fightTrainerAiValueAddsubDataBiosGetPtr(u16 slot); /* Misc attributes */

/* Event integration (defined with real bodies, possibly in a sibling segment) */
void fightOutPokemonSetHensinPokemonStatusId(void* trainer, u16 eventId, u32 param1, u32 param2);
u8   fightOutPokemonIsUseHensinBuff(void* trainer);
void fightOutPokemonSetHensinFightPokemonStatusId(void* trainer, u16 eventId, u32 param);

/* Item/Pokemon field access helpers used by battle item flow. */
u8 pokemonGetJoutai08(void* obj, s32 arg);
u8 statusGetJoutai08(void* obj, s32 arg);

/* SDA table pointers for trainer data arrays */
extern u32* lbl_80478F08;  /* Party config header */
extern u8*  lbl_80478F0C;  /* Party config data */
extern u32* lbl_80478F10;  /* Team roster header */
extern u8*  lbl_80478F14;  /* Team roster data */
extern u32* lbl_80478F18;  /* Slot data header */
extern u8*  lbl_80478F1C;  /* Slot data */
extern u32* lbl_80478F20;  /* Battle trainer header */
extern u8*  lbl_80478F24;  /* Battle trainer data */
extern u32* lbl_80478F28;  /* Misc attributes header */
extern u8*  lbl_80478F2C;  /* Misc attributes data */
extern u32* lbl_80478F30;  /* Story/event header */
extern u8*  lbl_80478F34;  /* Story/event data */

/* Forward declarations for converted functions (defined with real bodies,
 * possibly in a sibling segment). */
u16 fn_801FCC94(u8* ptr);
u8 fn_801FCCAC(u8* ptr);
void fightTrainerSetStatus(void);
void fightTrainerGetStatus(void);

/* Address: 0x801FBD10 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightTrainerKindDataBiosGetBgmSndId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerKindDataBiosFields*)ptr)->bgmSndId;
}

/* Address: 0x801FBD28 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightTrainerKindDataBiosGetPrefixName(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerKindDataBiosFields*)ptr)->prefixName;
}

/* Address: 0x801FBD40 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightTrainerKindDataBiosGetSyoukinBairitu(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerKindDataBiosFields*)ptr)->syoukinBairitu;
}

/* 0x801FBD58 | size: 0x2C */
u8* fightTrainerKindDataBiosGetPtr(u16 idx) {
    idx = idx;
    if (idx >= lbl_80478F18[0]) { return NULL; }
    return lbl_80478F1C + idx * 0xC;
}

/* Address: 0x801FBD84 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerEnemyPokemonBiosSetParam1bantakaiFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerEnemyPokemonBiosFields*)ptr)->param1bantakaiFlag = val;
}

/* Address: 0x801FBD94 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerEnemyPokemonBiosSetBadwazaHaveFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerEnemyPokemonBiosFields*)ptr)->badwazaHaveFlag = val;
}

/* Address: 0x801FBDA4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerEnemyPokemonBiosSetDefense1banhikuiFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerEnemyPokemonBiosFields*)ptr)->defense1banhikuiFlag = val;
}

/* Address: 0x801FBDB4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerEnemyPokemonBiosSetLv1banhikuiFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerEnemyPokemonBiosFields*)ptr)->lv1banhikuiFlag = val;
}

/* Address: 0x801FBDC4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerEnemyPokemonBiosSetNowhp1banhikuiFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerEnemyPokemonBiosFields*)ptr)->nowhp1banhikuiFlag = val;
}

/* Address: 0x801FBDD4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerEnemyPokemonBiosSetStoreTokuseiData(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerEnemyPokemonBiosFields*)ptr)->storeTokuseiData = val;
}

/* Address: 0x801FBDE4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerEnemyPokemonBiosSetTokuseiFlag(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerEnemyPokemonBiosFields*)ptr)->tokuseiFlag = val;
}

/* 0x801FBDF4 | size: 0x24 */
void fn_801FBDF4(u8* ptr, u8 idx, u16 val) {
    if (ptr == NULL) { return; }
    if (idx > 4) { return; }
    ptr += idx * 2;
    *(u16*)(ptr + 0x2) = val;
}

/* Address: 0x801FBE18 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerEnemyPokemonBiosSetFightEntryeId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerEnemyPokemonBiosFields*)ptr)->fightEntryeId = val;
}

/* Address: 0x801FBE28 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerEnemyPokemonBiosGetParam1bantakaiFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerEnemyPokemonBiosFields*)ptr)->param1bantakaiFlag;
}

/* Address: 0x801FBE40 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerEnemyPokemonBiosGetBadwazaHaveFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerEnemyPokemonBiosFields*)ptr)->badwazaHaveFlag;
}

/* Address: 0x801FBE58 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerEnemyPokemonBiosGetDefense1banhikuiFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerEnemyPokemonBiosFields*)ptr)->defense1banhikuiFlag;
}

/* Address: 0x801FBE70 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerEnemyPokemonBiosGetLv1banhikuiFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerEnemyPokemonBiosFields*)ptr)->lv1banhikuiFlag;
}

/* Address: 0x801FBE88 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerEnemyPokemonBiosGetNowhp1banhikuiFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerEnemyPokemonBiosFields*)ptr)->nowhp1banhikuiFlag;
}

/* Address: 0x801FBEA0 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightTrainerEnemyPokemonBiosGetStoreTokuseiData(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerEnemyPokemonBiosFields*)ptr)->storeTokuseiData;
}

/* Address: 0x801FBEB8 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightTrainerEnemyPokemonBiosGetTokuseiFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerEnemyPokemonBiosFields*)ptr)->tokuseiFlag;
}

/* 0x801FBED0 | size: 0x34 */
u16 fightTrainerGetU16Arr(u8* ptr, u8 idx) {
    if (ptr == NULL) { return 0; }
    if (idx > 4) { return 0; }
    ptr += idx * 2;
    return *(u16*)(ptr + 0x2);
}

/* Address: 0x801FBF04 | Size: 0x18 | Pattern: nullcheck_getter */
s16 fightTrainerEnemyPokemonBiosGetFightEntryeId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(s16*)(&ptr[0x0]);
}

/* Address: 0x801FBF1C | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiValueAddsubDataBiosSetPrefixName(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiValueAddsubDataBiosFields*)ptr)->prefixName = val;
}

/* Address: 0x801FBF2C | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiValueAddsubDataBiosSetKoudouName(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiValueAddsubDataBiosFields*)ptr)->koudouName = val;
}

/* Address: 0x801FBF3C | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiValueAddsubDataBiosSetName(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiValueAddsubDataBiosFields*)ptr)->name = val;
}

/* Address: 0x801FBF4C | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiValueAddsubDataBiosSetValue(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiValueAddsubDataBiosFields*)ptr)->value = val;
}

/* Address: 0x801FBF5C | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightTrainerAiValueAddsubDataBiosGetPrefixName(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiValueAddsubDataBiosFields*)ptr)->prefixName;
}

/* Address: 0x801FBF74 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightTrainerAiValueAddsubDataBiosGetKoudouName(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiValueAddsubDataBiosFields*)ptr)->koudouName;
}

/* Address: 0x801FBF8C | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightTrainerAiValueAddsubDataBiosGetName(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiValueAddsubDataBiosFields*)ptr)->name;
}

/* Address: 0x801FBFA4 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightTrainerAiValueAddsubDataBiosGetValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiValueAddsubDataBiosFields*)ptr)->value;
}

/* Address: 0x801FBFBC | Size: 0x2C | Pattern: dispatch_resolver (misc attributes) */
void* fightTrainerAiValueAddsubDataBiosGetPtr(u16 slot) {
    slot = slot;
    if (slot >= lbl_80478F28[0]) { return NULL; }
    return lbl_80478F2C + slot * 0x14;
}

/* Address: 0x801FBFE8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetLastValueRevise(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->lastValueRevise = val;
}

/* Address: 0x801FBFF8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetWazaNokoriPpValue(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->wazaNokoriPpValue = val;
}

/* Address: 0x801FC008 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetWazaRiskFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->wazaRiskFlag = val;
}

/* Address: 0x801FC018 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetWazaAvgValue(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->wazaAvgValue = val;
}

/* Address: 0x801FC028 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetWazaHitFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->wazaHitFlag = val;
}

/* 0x801FC038 | size: 0x44 */
void fightTrainerAiDataBiosSetWazaTypeReviseValue(u8* ptr, u16 idx, u8 val) {
    u8* entry;
    if (ptr == NULL) return;
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 2) {
        entry = NULL;
    } else {
        entry = ptr + idx * 2 + 0x24;
    }
    if (entry == NULL) return;
    entry[1] = val;
}

/* 0x801FC07C | size: 0x44 */
void fightTrainerAiDataBiosSetWazaTypeReviseTypeDataId(u8* ptr, u16 idx, u8 val) {
    u8* entry;
    if (ptr == NULL) return;
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 2) {
        entry = NULL;
    } else {
        entry = ptr + idx * 2 + 0x24;
    }
    if (entry == NULL) return;
    entry[0] = val;
}

/* Address: 0x801FC0C0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetPartFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->partFlag = val;
}

/* Address: 0x801FC0D0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetWazaInitValueFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->wazaInitValueFlag = val;
}

/* Address: 0x801FC0E0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetWazaRndSelectFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->wazaRndSelectFlag = val;
}

/* Address: 0x801FC0F0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetDefensePokemonRndSelectFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->defensePokemonRndSelectFlag = val;
}

/* Address: 0x801FC100 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetAbicntMinValue(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->abicntMinValue = val;
}

/* Address: 0x801FC110 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetAbicntMaxValue(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->abicntMaxValue = val;
}

/* Address: 0x801FC120 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetWazaDamageFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->wazaDamageFlag = val;
}

/* Address: 0x801FC130 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetNokoriHpValue(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->nokoriHpValue = val;
}

/* Address: 0x801FC140 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetTokuseiCheckFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->tokuseiCheckFlag = val;
}

/* 0x801FC150 | size: 0x44 */
void fightTrainerAiDataBiosSetZokuseiReviseValue(u8* ptr, u16 idx, u8 val) {
    u8* entry;
    if (ptr == NULL) return;
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 2) {
        entry = NULL;
    } else {
        entry = ptr + idx * 2 + 0x20;
    }
    if (entry == NULL) return;
    entry[1] = val;
}

/* 0x801FC194 | size: 0x44 */
void fightTrainerAiDataBiosSetZokuseiReviseZokuseiDataId(u8* ptr, u16 idx, u8 val) {
    u8* entry;
    if (ptr == NULL) return;
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 2) {
        entry = NULL;
    } else {
        entry = ptr + idx * 2 + 0x20;
    }
    if (entry == NULL) return;
    entry[0] = val;
}

/* Address: 0x801FC1D8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetZokuseiCheckFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->zokuseiCheckFlag = val;
}

/* Address: 0x801FC1E8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetParamStoreFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->paramStoreFlag = val;
}

/* Address: 0x801FC1F8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetParamExpectFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->paramExpectFlag = val;
}

/* Address: 0x801FC208 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetItemValue(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->itemValue = val;
}

/* Address: 0x801FC218 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetIrekaeValue(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->irekaeValue = val;
}

/* Address: 0x801FC228 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetComboValue(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->comboValue = val;
}

/* Address: 0x801FC238 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetPokemonJoutaiFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->pokemonJoutaiFlag = val;
}

/* Address: 0x801FC248 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetKeyPlayerFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->keyPlayerFlag = val;
}

/* Address: 0x801FC258 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetPokemonDataOrderAceBossFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->pokemonDataOrderAceBossFlag = val;
}

/* Address: 0x801FC268 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetPokemonDataOrderOutFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->pokemonDataOrderOutFlag = val;
}

/* Address: 0x801FC278 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetPokemonSelectWeakPointFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->pokemonSelectWeakPointFlag = val;
}

/* Address: 0x801FC288 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerAiDataBiosSetPokemonSelectRandomFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerAiDataBiosFields*)ptr)->pokemonSelectRandomFlag = val;
}

/* Address: 0x801FC298 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetLastValueRevise(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->lastValueRevise;
}

/* Address: 0x801FC2B0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetWazaNokoriPpValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->wazaNokoriPpValue;
}

/* Address: 0x801FC2C8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetWazaRiskFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->wazaRiskFlag;
}

/* Address: 0x801FC2E0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetWazaAvgValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->wazaAvgValue;
}

/* Address: 0x801FC2F8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetWazaHitFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->wazaHitFlag;
}

/* 0x801FC310 | size: 0x54 */
u32 fightTrainerAiDataBiosGetWazaTypeReviseValue(u8* ptr, u16 idx) {
    u8* entry;
    if (ptr == NULL) {
        return 0;
    }
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 2) {
        entry = NULL;
    } else {
        entry = ptr + idx * 2 + 0x24;
    }
    if (entry == NULL) {
        return 0;
    }
    return entry[1];
}

/* 0x801FC364 | size: 0x54 */
u32 fightTrainerAiDataBiosGetWazaTypeReviseTypeDataId(u8* ptr, u16 idx) {
    u8* entry;
    if (ptr == NULL) {
        return 0;
    }
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 2) {
        entry = NULL;
    } else {
        entry = ptr + idx * 2 + 0x24;
    }
    if (entry == NULL) {
        return 0;
    }
    return entry[0];
}

/* Address: 0x801FC3B8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetPartFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->partFlag;
}

/* Address: 0x801FC3D0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetWazaInitValueFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->wazaInitValueFlag;
}

/* Address: 0x801FC3E8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetWazaRndSelectFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->wazaRndSelectFlag;
}

/* Address: 0x801FC400 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetDefensePokemonRndSelectFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->defensePokemonRndSelectFlag;
}

/* Address: 0x801FC418 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetAbicntMinValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->abicntMinValue;
}

/* Address: 0x801FC430 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetAbicntMaxValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->abicntMaxValue;
}

/* Address: 0x801FC448 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetWazaDamageFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->wazaDamageFlag;
}

/* Address: 0x801FC460 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetNokoriHpValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->nokoriHpValue;
}

/* Address: 0x801FC478 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetTokuseiCheckFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->tokuseiCheckFlag;
}

/* 0x801FC490 | size: 0x54 */
u32 fightTrainerAiDataBiosGetZokuseiReviseValue(u8* ptr, u16 idx) {
    u8* entry;
    if (ptr == NULL) {
        return 0;
    }
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 2) {
        entry = NULL;
    } else {
        entry = ptr + idx * 2 + 0x20;
    }
    if (entry == NULL) {
        return 0;
    }
    return entry[1];
}

/* 0x801FC4E4 | size: 0x54 */
u32 fightTrainerAiDataBiosGetZokuseiReviseZokuseiDataId(u8* ptr, u16 idx) {
    u8* entry;
    if (ptr == NULL) {
        return 0;
    }
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 2) {
        entry = NULL;
    } else {
        entry = ptr + idx * 2 + 0x20;
    }
    if (entry == NULL) {
        return 0;
    }
    return entry[0];
}

/* Address: 0x801FC538 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetZokuseiCheckFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->zokuseiCheckFlag;
}

/* Address: 0x801FC550 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetParamStoreFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->paramStoreFlag;
}

/* Address: 0x801FC568 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetParamExpectFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->paramExpectFlag;
}

/* Address: 0x801FC580 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetItemValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->itemValue;
}

/* Address: 0x801FC598 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetIrekaeValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->irekaeValue;
}

/* Address: 0x801FC5B0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetComboValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->comboValue;
}

/* Address: 0x801FC5C8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetPokemonJoutaiFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->pokemonJoutaiFlag;
}

/* Address: 0x801FC5E0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetKeyPlayerFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->keyPlayerFlag;
}

/* Address: 0x801FC5F8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetPokemonDataOrderAceBossFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->pokemonDataOrderAceBossFlag;
}

/* Address: 0x801FC610 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetPokemonDataOrderOutFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->pokemonDataOrderOutFlag;
}

/* Address: 0x801FC628 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetPokemonSelectWeakPointFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->pokemonSelectWeakPointFlag;
}

/* Address: 0x801FC640 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerAiDataBiosGetPokemonSelectRandomFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerAiDataBiosFields*)ptr)->pokemonSelectRandomFlag;
}

/* Address: 0x801FC658 | Size: 0x2C | Pattern: dispatch_resolver (story/event) */
void* fightTrainerAiDataBiosGetPtr(u16 slot) {
    slot = slot;
    if (slot >= lbl_80478F30[0]) { return NULL; }
    return lbl_80478F34 + slot * 0x28;
}

/* Address: 0x801FC684 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetPartDataId(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->partDataId = val;
}

/* Address: 0x801FC694 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetKeyPlayerFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->keyPlayerFlag = val;
}

/* Address: 0x801FC6A4 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerPokemonDataBiosGetPartDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerPokemonDataBiosFields*)ptr)->partDataId;
}

/* Address: 0x801FC6BC | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerPokemonDataBiosGetKeyPlayerFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerPokemonDataBiosFields*)ptr)->keyPlayerFlag;
}

/* Address: 0x801FC6D4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetSeikakuDataId(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->seikakuDataId = val;
}

/* Address: 0x801FC6E4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetSexDataId(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->sexDataId = val;
}

/* Address: 0x801FC6F4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetFriend(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->friend = val;
}

/* 0x801FC704 | size: 0x40 */
void fightTrainerPokemonDataBiosSetPpCnt(u8* ptr, u8 idx, u8 val) {
    u8* entry;
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 4) {
        entry = NULL;
    } else {
        entry = ptr + idx * 8 + 0x30;
    }
    if (entry == 0) { return; }
    entry[0] = val;
}

/* 0x801FC744 | size: 0x40 */
void fightTrainerPokemonDataBiosSetWazaDataId(u8* ptr, u8 idx, u32 val) {
    u8* entry;
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 4) {
        entry = NULL;
    } else {
        entry = ptr + idx * 8 + 0x30;
    }
    if (entry == 0) { return; }
    *(u32*)(entry + 4) = val;
}

/* Address: 0x801FC784 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetItemDataId(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->itemDataId = val;
}

/* Address: 0x801FC794 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetPokemonDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->pokemonDataId = val;
}

/* Address: 0x801FC7A4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetTokuseiFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->tokuseiFlag = val;
}

/* Address: 0x801FC7B4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetDarkPokemonFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->darkPokemonFlag = val;
}

/* Address: 0x801FC7C4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetItemBallId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->itemBallId = val;
}

/* Address: 0x801FC7D4 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetLevel(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->level = val;
}

/* 0x801FC7E4 | size: 0x24 */
void fightTrainerPokemonDataBiosSetStatusEffort(u8* ptr, u8 idx, u16 val) {
    if (ptr == NULL) { return; }
    if (idx >= 6) { return; }
    ptr += idx * 2;
    *(u16*)(ptr + 0x22) = val;
}

/* 0x801FC808 | size: 0x20 */
void fightTrainerPokemonDataBiosSetStatusRnd(u8* ptr, u8 idx, u8 val) {
    if (ptr == NULL) { return; }
    if (idx >= 6) { return; }
    ptr += idx;
    *(ptr + 0x1C) = val;
}

/* Address: 0x801FC828 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonDataBiosSetNickname(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonDataBiosFields*)ptr)->nickname = val;
}

/* 0x801FC838 | size: 0x1C */
s32 fightTrainerPokemonDataBiosGetSeikakuDataId(u8* ptr) {
    if (ptr == NULL) { return -1; }
    return (s8)ptr[0x2];
}

/* 0x801FC854 | size: 0x1C */
s32 fightTrainerPokemonDataBiosGetSexDataId(u8* ptr) {
    if (ptr == NULL) { return -1; }
    return (s8)ptr[0x1];
}

/* 0x801FC870 | size: 0x18 */
s32 fightTrainerPokemonDataBiosGetFriend(u8* ptr) {
    if (ptr == NULL) { return -1; }
    return *(s16*)(ptr + 0x8);
}

/* 0x801FC888 | size: 0x48 */
u32 fightTrainerPokemonDataBiosGetPpCnt(u8* ptr, u8 idx) {
    u8* entry;
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 4) {
        entry = NULL;
    } else {
        entry = ptr + idx * 8 + 0x30;
    }
    if (entry == NULL) {
        return 0;
    }
    return entry[0];
}

/* 0x801FC8D0 | size: 0x48 */
s32 fightTrainerPokemonDataBiosGetWazaDataId(u8* ptr, u8 idx) {
    u8* entry;
    if (ptr == NULL) {
        entry = NULL;
    } else if (idx >= 4) {
        entry = NULL;
    } else {
        entry = ptr + idx * 8 + 0x30;
    }
    if (entry == NULL) {
        return -1;
    }
    return *(s32*)(entry + 4);
}

/* 0x801FC918 | size: 0x18 */
s32 fightTrainerPokemonDataBiosGetItemDataId(u8* ptr) {
    if (ptr == NULL) { return -1; }
    return *(s32*)(ptr + 0x10);
}

/* Address: 0x801FC930 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightTrainerPokemonDataBiosGetPokemonDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerPokemonDataBiosFields*)ptr)->pokemonDataId;
}

/* 0x801FC948 | size: 0x1C */
s32 fightTrainerPokemonDataBiosGetTokuseiFlag(u8* ptr) {
    if (ptr == NULL) { return -1; }
    return (s8)ptr[0x0];
}

/* Address: 0x801FC964 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerPokemonDataBiosGetDarkPokemonFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerPokemonDataBiosFields*)ptr)->darkPokemonFlag;
}

/* Address: 0x801FC97C | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightTrainerPokemonDataBiosGetItemBallId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerPokemonDataBiosFields*)ptr)->itemBallId;
}

/* Address: 0x801FC994 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainerPokemonDataBiosGetLevel(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerPokemonDataBiosFields*)ptr)->level;
}

/* 0x801FC9AC | size: 0x34 */
s32 fightTrainerPokemonDataBiosGetStatusEffort(u8* ptr, u8 idx) {
    if (ptr == NULL) { return -1; }
    if (idx >= 6) { return -1; }
    ptr += idx * 2;
    return *(s16*)(ptr + 0x22);
}

/* 0x801FC9E0 | size: 0x34 */
s32 fightTrainerPokemonDataBiosGetStatusRnd(u8* ptr, u8 idx) {
    if (ptr == NULL) { return -1; }
    if (idx >= 6) { return -1; }
    ptr += idx;
    return (s8)*(ptr + 0x1C);
}

/* Address: 0x801FCA14 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightTrainerPokemonDataBiosGetNickname(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerPokemonDataBiosFields*)ptr)->nickname;
}

/* Address: 0x801FCA2C | Size: 0x2C | Pattern: dispatch_resolver (team roster) */
void* fightTrainerPokemonDataBiosGetPtr(u16 slot) {
    slot = slot;
    if (slot >= lbl_80478F10[0]) { return NULL; }
    return lbl_80478F14 + slot * 0x50;
}

/* 0x801FCA58 | size: 0x20 */
void fightTrainerPokemonPartDataBiosSetWazaTypeRevise(u8* ptr, u8 idx, u8 val) {
    if (ptr == NULL) { return; }
    if (idx >= 0xC) { return; }
    ptr += idx;
    *(ptr + 0x8) = val;
}

/* Address: 0x801FCA78 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerPokemonPartDataBiosSetName(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerPokemonPartDataBiosFields*)ptr)->name = val;
}

/* 0x801FCA88 | size: 0x30 */
u32 fightTrainerPokemonPartDataBiosGetWazaTypeRevise(u8* ptr, u8 idx) {
    if (ptr == NULL) { return 0; }
    if (idx >= 0xC) { return 0; }
    ptr += idx;
    return *(ptr + 0x8);
}

/* Address: 0x801FCAB8 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightTrainerPokemonPartDataBiosGetName(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerPokemonPartDataBiosFields*)ptr)->name;
}

/* Address: 0x801FCAD0 | Size: 0x2C | Pattern: dispatch_resolver (party config) */
void* fightTrainerPokemonPartDataBiosGetPtr(u16 slot) {
    slot = slot;
    if (slot >= lbl_80478F08[0]) { return NULL; }
    return lbl_80478F0C + slot * 0x14;
}

/* Address: 0x801FCAFC | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerSet10(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerFields*)ptr)->field10 = val;
}

/* 0x801FCB0C | size: 0x24 */
void fightTrainerSet24Arr(u8* ptr, u8 idx, u32 val) {
    if (ptr == NULL) { return; }
    if (idx >= 4) { return; }
    ptr += idx * 4;
    *(u32*)(ptr + 0x24) = val;
}

/* Address: 0x801FCB30 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerSet0C(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerFields*)ptr)->field0C = val;
}

/* 0x801FCB40 | size: 0x24 */
void fightTrainerSetU16Arr14(u8* ptr, u8 idx, u16 val) {
    if (ptr == NULL) { return; }
    if (idx >= 8) { return; }
    ptr += idx * 2;
    *(u16*)(ptr + 0x14) = val;
}

/* Address: 0x801FCB64 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerSet04(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerFields*)ptr)->field04 = val;
}

/* Address: 0x801FCB74 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerSet08(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerFields*)ptr)->field08 = val;
}

/* Address: 0x801FCB84 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerSet06(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerFields*)ptr)->field06 = val;
}

/* Address: 0x801FCB94 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerSet00(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerFields*)ptr)->field00 = val;
}

/* Address: 0x801FCBA4 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fn_801FCBA4(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u32*)(&ptr[0x10]);
}

/* 0x801FCBBC | size: 0x34 */
u32 fn_801FCBBC(u8* ptr, u8 idx) {
    if (ptr == NULL) { return 0; }
    if (idx >= 4) { return 0; }
    ptr += idx * 4;
    return *(u32*)(ptr + 0x24);
}

/* Address: 0x801FCBF0 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fn_801FCBF0(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u32*)(&ptr[0xC]);
}

/* 0x801FCC08 | size: 0x34 */
u32 fn_801FCC08(u8* ptr, u8 idx) {
    if (ptr == NULL) { return 0; }
    if (idx >= 8) { return 0; }
    ptr += idx * 2;
    return *(u16*)(ptr + 0x14);
}

/* Address: 0x801FCC3C | Size: 0x18 | Pattern: nullcheck_getter */
u16 fn_801FCC3C(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u16*)(&ptr[0x4]);
}

/* Address: 0x801FCC54 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainerDataBiosSetKindDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightTrainerDataBiosFields*)ptr)->kindDataId = val;
}

/* Address: 0x801FCC64 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightTrainerDataBiosGetKindDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightTrainerDataBiosFields*)ptr)->kindDataId;
}

/* Address: 0x801FCC7C | Size: 0x18 | Pattern: nullcheck_getter */
u32 fn_801FCC7C(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u32*)(&ptr[0x8]);
}

/* Address: 0x801FCC94 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fn_801FCC94(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u16*)(&ptr[0x6]);
}

/* Address: 0x801FCCAC | Size: 0x18 | Pattern: nullcheck_getter */
u8 fn_801FCCAC(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u8*)(&ptr[0x0]);
}

/* #######################################################################
 * COVERAGE STUBS: Trainer data access (0x801F7F80 - 0x80201800)
 * 123 functions remaining for full coverage of trainer.c TU.
 *
 * Key functions in this range:
 *   fightTrainerGetStatus (TrainerDataGet) - 883 calls, 0x724 bytes
 *   fightTrainerSetStatus (TrainerDataSet) - 169 calls, 0x768 bytes
 *   fightTrainerDataBiosGetPtr (BattleTrainerResolve) - category dispatcher
 *   fightTrainerPokemonPartDataBiosGetPtr (PartyConfigResolve) - party config sub-dispatch
 *   fightTrainerPokemonDataBiosGetPtr (TeamRosterResolve) - team roster sub-dispatch
 *   fightTrainerAiDataBiosGetPtr (StoryDataResolve) - story/event sub-dispatch
 *   fightTrainerAiValueAddsubDataBiosGetPtr (MiscAttrResolve) - misc attribute sub-dispatch
 *   fightOutPokemonSetHensinPokemonStatusId (SetTrainerEventState) - 49 calls
 *   fightOutPokemonIsUseHensinBuff (CheckTrainerEventState) - 59 calls
 * ####################################################################### */

/* Address: 0x801FCCC4 | Size: 0x2C | Pattern: dispatch_resolver (battle trainer) */
void* fightTrainerDataBiosGetPtr(u16 slot) {
    slot = slot;
    if (slot >= lbl_80478F20[0]) { return NULL; }
    return lbl_80478F24 + slot * 0x34;
}

/* 0x801FCCF0 | size: 0x18 */
u8* fightTrainer_GetFightActionBuffPtr(u8* ptr) {
    if (ptr == NULL) { return NULL; }
    return ptr + 0x27C4;
}

/* Address: 0x801FCD08 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainer_SetControllerId(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    *(u8*)(&ptr[0x27BC]) = val;
}

/* Address: 0x801FCD18 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainer_SetNigeruCount(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    *(u8*)(&ptr[0x27B5]) = val;
}

/* Address: 0x801FCD28 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainer_SetKoban(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    *(u32*)(&ptr[0x27B8]) = val;
}

/* Address: 0x801FCD38 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainer_SetOkaneBai(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    *(u8*)(&ptr[0x27B4]) = val;
}

/* Address: 0x801FCD48 | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainer_SetFightTrainerDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    *(u16*)(&ptr[0x0]) = val;
}

/* 0x801FCD58 | size: 0x34 */
u8* fightTrainer_GetFightTrainerEnemyPokemonAryPtr(u8* ptr, u8 idx) {
    if (ptr == NULL) { return NULL; }
    if (idx >= 0xC) { return NULL; }
    return ptr + idx * 0x14 + 0x27F4;
}

/* Address: 0x801FCD8C | Size: 0x10 | Pattern: nullcheck_setter */
void fightTrainer_SetSequencePtr(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    *(u32*)(&ptr[0x27C0]) = val;
}

/* Address: 0x801FCD9C | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightTrainer_GetSequencePtr(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u32*)(&ptr[0x27C0]);
}

/* Address: 0x801FCDB4 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainer_GetControllerId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u8*)(&ptr[0x27BC]);
}

/* Address: 0x801FCDCC | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainer_GetNigeruCount(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u8*)(&ptr[0x27B5]);
}

/* Address: 0x801FCDE4 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightTrainer_GetKoban(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u32*)(&ptr[0x27B8]);
}

/* Address: 0x801FCDFC | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightTrainer_GetOkaneBai(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u8*)(&ptr[0x27B4]);
}

/* 0x801FCE14 | size: 0x18 */
u8* fightTrainer_GetFightoutPokemonBuffPtr(u8* ptr) {
    if (ptr == NULL) { return NULL; }
    return ptr + 0x20D4;
}

/* 0x801FCE2C | size: 0x34 */
u8* fightTrainer_GetFightoutPokemonPtr(u8* ptr, u16 idx) {
    if (ptr == NULL) { return NULL; }
    if (idx >= 2) { return NULL; }
    return ptr + idx * 0x6E0 + 0x1314;
}

/* 0x801FCE60 | size: 0x34 */
u8* fightTrainer_GetFightPokemonPtr(u8* ptr, u16 idx) {
    if (ptr == NULL) { return NULL; }
    if (idx >= 6) { return NULL; }
    return ptr + idx * 0x154 + 0xB1C;
}

/* Address: 0x801FCE94 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightTrainer_GetFightTrainerDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(u16*)(&ptr[0x0]);
}

/* 0x801FCEAC | size: 0x18 */
u8* fightTrainer_GetHeroPtr(u8* ptr) {
    if (ptr == NULL) { return NULL; }
    return ptr + 0x4;
}

/* FightOutPokemon: the per-slot "out" battle record copied wholesale by
 * fightOutPokemonBiosCopy below (0x6E0 bytes; matches the stride used throughout this
 * file, e.g. fightTrainer_GetFightoutPokemonPtr's idx * 0x6E0). Not yet
 * broken out field-by-field elsewhere in the codebase (still referenced
 * only via mangled names like _fightOutPokemonCheckFightActionSelectSub__
 * FP15FightOutPokemonUsUs), so this local definition only models the size
 * needed for the struct-assignment copy performed here. */
typedef struct FightOutPokemon {
    u8 data[0x6E0];
} FightOutPokemon;

/* 0x801FCEC4 | size: 0x38 */
void fightOutPokemonBiosCopy(FightOutPokemon* dst, FightOutPokemon* src) {
    if (dst == NULL) { return; }
    if (src == NULL) { return; }
    *dst = *src;
}

/* Address: 0x801FCEFC | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetOumuWazaDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->oumuWazaDataId = val;
}

/* Address: 0x801FCF0C | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetGamanDamageTargetId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->gamanDamageTargetId = val;
}

/* Address: 0x801FCF1C | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetGamanDamageValue(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->gamanDamageValue = val;
}

/* Address: 0x801FCF2C | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetHitWazaZokuseiDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->hitWazaZokuseiDataId = val;
}

/* Address: 0x801FCF3C | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetHitWazaDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->hitWazaDataId = val;
}

/* Address: 0x801FCF4C | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetLastReceiveWazaTargetDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->lastReceiveWazaTargetDataId = val;
}

/* Address: 0x801FCF5C | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetLastUseWazaDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->lastUseWazaDataId = val;
}

/* Address: 0x801FCF6C | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetLastSelectWazaDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->lastSelectWazaDataId = val;
}

/* Address: 0x801FCF7C | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetSketchWazaDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->sketchWazaDataId = val;
}

/* 0x801FCF8C | size: 0x18 */
u8* fightOutPokemonBiosGetKeepFightWazaPtr(u8* ptr) {
    if (ptr == NULL) { return NULL; }
    return ptr + 0x548;
}

/* Address: 0x801FCFA4 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetOumuWazaDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->oumuWazaDataId;
}

/* Address: 0x801FCFBC | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetGamanDamageTargetId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->gamanDamageTargetId;
}

/* Address: 0x801FCFD4 | Size: 0x18 | Pattern: nullcheck_getter */
s16 fightOutPokemonBiosGetGamanDamageValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(s16*)(&ptr[0x674]);
}

/* 0x801FCFEC | size: 0x18 */
u32 fightOutPokemonBiosGetHitWazaZokuseiDataId(u8* ptr) {
    if (ptr == NULL) { return 9; }
    return ((FightOutPokemonBiosFields*)ptr)->hitWazaZokuseiDataId;
}

/* Address: 0x801FD004 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetHitWazaDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->hitWazaDataId;
}

/* Address: 0x801FD01C | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetLastReceiveWazaTargetDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->lastReceiveWazaTargetDataId;
}

/* Address: 0x801FD034 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetLastUseWazaDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->lastUseWazaDataId;
}

/* Address: 0x801FD04C | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetLastSelectWazaDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->lastSelectWazaDataId;
}

/* Address: 0x801FD064 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetSketchWazaDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->sketchWazaDataId;
}

/* Address: 0x801FD07C | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonEnemyBiosSetDamage(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonEnemyBiosFields*)ptr)->damage = val;
}

/* Address: 0x801FD08C | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonEnemyBiosSetInitHp(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonEnemyBiosFields*)ptr)->initHp = val;
}

/* Address: 0x801FD09C | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonEnemyBiosSetOumuWazaDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonEnemyBiosFields*)ptr)->oumuWazaDataId = val;
}

/* Address: 0x801FD0AC | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonEnemyBiosSetTargetFightOutPokemonPtr(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonEnemyBiosFields*)ptr)->targetFightOutPokemonPtr = val;
}

/* Address: 0x801FD0BC | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonEnemyBiosGetDamage(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonEnemyBiosFields*)ptr)->damage;
}

/* Address: 0x801FD0D4 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonEnemyBiosGetInitHp(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonEnemyBiosFields*)ptr)->initHp;
}

/* Address: 0x801FD0EC | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonEnemyBiosGetOumuWazaDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonEnemyBiosFields*)ptr)->oumuWazaDataId;
}

/* Address: 0x801FD104 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightOutPokemonEnemyBiosGetTargetFightOutPokemonPtr(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonEnemyBiosFields*)ptr)->targetFightOutPokemonPtr;
}

/* 0x801FD11C | size: 0x34 */
u8* fightOutPokemonBiosGetFightOutPokemonEnemyPtr(u8* ptr, u16 idx) {
    if (ptr == NULL) { return NULL; }
    if (idx >= 4) { return NULL; }
    return ptr + idx * 0xC + 0x6B0;
}

/* Address: 0x801FD150 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetIrekaeTargetEntryId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->irekaeTargetEntryId = val;
}

/* 0x801FD160 | size: 0x18 */
s32 fightOutPokemonBiosGetIrekaeTargetEntryId(u8* ptr) {
    if (ptr == NULL) { return -1; }
    return *(s16*)(ptr + 0x6AE);
}

/* Address: 0x801FD178 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetKizetuFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->kizetuFlag = val;
}

/* Address: 0x801FD188 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetKizetuFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->kizetuFlag;
}

/* Address: 0x801FD1A0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetMyselfDamageSpeTargetId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->myselfDamageSpeTargetId = val;
}

/* Address: 0x801FD1B0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetMyselfDamageSpeValue(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->myselfDamageSpeValue = val;
}

/* Address: 0x801FD1C0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetMyselfDamageAtkTargetId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->myselfDamageAtkTargetId = val;
}

/* Address: 0x801FD1D0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetMyselfDamageAtkValue(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->myselfDamageAtkValue = val;
}

/* Address: 0x801FD1E0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetKaigaraDamageValue(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->kaigaraDamageValue = val;
}

/* Address: 0x801FD1F0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetItemKoraetaFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->itemKoraetaFlag = val;
}

/* Address: 0x801FD200 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetIrekaetaFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->irekaetaFlag = val;
}

/* Address: 0x801FD210 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetNoPressureFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->noPressureFlag = val;
}

/* Address: 0x801FD220 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetDoTraceFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->doTraceFlag = val;
}

/* Address: 0x801FD230 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetDoIkakuFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->doIkakuFlag = val;
}

/* Address: 0x801FD240 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetVanishoffFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->vanishoffFlag = val;
}

/* Address: 0x801FD250 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetReceivesWazaHiraishinFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->receivesWazaHiraishinFlag = val;
}

/* Address: 0x801FD260 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetDoClearbodyFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->doClearbodyFlag = val;
}

/* Address: 0x801FD270 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetFightActionFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->fightActionFlag = val;
}

/* Address: 0x801FD280 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetPassPpdecFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->passPpdecFlag = val;
}

/* Address: 0x801FD290 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetHirumuNoAttackFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->hirumuNoAttackFlag = val;
}

/* Address: 0x801FD2A0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetIchamonNoAttackFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->ichamonNoAttackFlag = val;
}

/* Address: 0x801FD2B0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetChouhatsuNoAttackFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->chouhatsuNoAttackFlag = val;
}

/* Address: 0x801FD2C0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetKanashibariNoAttackFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->kanashibariNoAttackFlag = val;
}

/* Address: 0x801FD2D0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetMeroMeroNoAttackFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->meroMeroNoAttackFlag = val;
}

/* Address: 0x801FD2E0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetHuuinNoAttackFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->huuinNoAttackFlag = val;
}

/* Address: 0x801FD2F0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetItemNigeruFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->itemNigeruFlag = val;
}

/* Address: 0x801FD300 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetTameWazaFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->tameWazaFlag = val;
}

/* Address: 0x801FD310 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetOutWazaKoukanaiFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->outWazaKoukanaiFlag = val;
}

/* Address: 0x801FD320 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetKonranMyselfAttackFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->konranMyselfAttackFlag = val;
}

/* Address: 0x801FD330 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetMahiNoAttackFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->mahiNoAttackFlag = val;
}

/* Address: 0x801FD340 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetMyselfDamageSpeTargetId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->myselfDamageSpeTargetId;
}

/* Address: 0x801FD358 | Size: 0x18 | Pattern: nullcheck_getter */
s16 fightOutPokemonBiosGetMyselfDamageSpeValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(s16*)(&ptr[0x6A8]);
}

/* Address: 0x801FD370 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetMyselfDamageAtkTargetId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->myselfDamageAtkTargetId;
}

/* Address: 0x801FD388 | Size: 0x18 | Pattern: nullcheck_getter */
s16 fightOutPokemonBiosGetMyselfDamageAtkValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(s16*)(&ptr[0x6A4]);
}

/* Address: 0x801FD3A0 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightOutPokemonBiosGetKaigaraDamageValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->kaigaraDamageValue;
}

/* Address: 0x801FD3B8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetItemKoraetaFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->itemKoraetaFlag;
}

/* Address: 0x801FD3D0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetIrekaetaFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->irekaetaFlag;
}

/* Address: 0x801FD3E8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetNoPressureFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->noPressureFlag;
}

/* Address: 0x801FD400 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetDoTraceFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->doTraceFlag;
}

/* Address: 0x801FD418 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetDoIkakuFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->doIkakuFlag;
}

/* Address: 0x801FD430 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetVanishoffFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->vanishoffFlag;
}

/* Address: 0x801FD448 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetReceivesWazaHiraishinFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->receivesWazaHiraishinFlag;
}

/* Address: 0x801FD460 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetDoClearbodyFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->doClearbodyFlag;
}

/* Address: 0x801FD478 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetFightActionFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->fightActionFlag;
}

/* Address: 0x801FD490 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetPassPpdecFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->passPpdecFlag;
}

/* Address: 0x801FD4A8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetHirumuNoAttackFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->hirumuNoAttackFlag;
}

/* Address: 0x801FD4C0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetIchamonNoAttackFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->ichamonNoAttackFlag;
}

/* Address: 0x801FD4D8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetChouhatsuNoAttackFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->chouhatsuNoAttackFlag;
}

/* Address: 0x801FD4F0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetKanashibariNoAttackFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->kanashibariNoAttackFlag;
}

/* Address: 0x801FD508 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetMeroMeroNoAttackFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->meroMeroNoAttackFlag;
}

/* Address: 0x801FD520 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetHuuinNoAttackFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->huuinNoAttackFlag;
}

/* Address: 0x801FD538 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetItemNigeruFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->itemNigeruFlag;
}

/* Address: 0x801FD550 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetTameWazaFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->tameWazaFlag;
}

/* Address: 0x801FD568 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetOutWazaKoukanaiFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->outWazaKoukanaiFlag;
}

/* Address: 0x801FD580 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetKonranMyselfAttackFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->konranMyselfAttackFlag;
}

/* Address: 0x801FD598 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetMahiNoAttackFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->mahiNoAttackFlag;
}

/* 0x801FD5B0 | size: 0x18 */
u8* fightOutPokemonBiosGetWazaMenuCurPtr(u8* ptr) {
    if (ptr == NULL) { return NULL; }
    return ptr + 0x664;
}

/* Address: 0x801FD5C8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetTokuseiDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->tokuseiDataId = val;
}

/* Address: 0x801FD5D8 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetTokuseiDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->tokuseiDataId;
}

/* 0x801FD5F0 | size: 0x24 */
void fightOutPokemonBiosSetZokuseiDataId(u8* ptr, u8 idx, u16 val) {
    if (ptr == NULL) { return; }
    if (idx >= 2) { return; }
    ptr += idx * 2;
    *(u16*)(ptr + 0x65C) = val;
}

/* 0x801FD614 | size: 0x34 */
u32 fightOutPokemonBiosGetZokuseiDataId(u8* ptr, u8 idx) {
    if (ptr == NULL) { return 0; }
    if (idx >= 2) { return 0; }
    ptr += idx * 2;
    return *(u16*)(ptr + 0x65C);
}

/* 0x801FD648 | size: 0x18 */
u8* fightOutPokemonBiosGetFightActionBuffPtr(u8* ptr) {
    if (ptr == NULL) { return NULL; }
    return ptr + 0x62C;
}

/* 0x801FD660 | size: 0x24 */
void fightOutPokemonBiosSetMeetEnemyFightPokemonEntryId(u8* ptr, u8 idx, u16 val) {
    if (ptr == NULL) { return; }
    if (idx >= 0xC) { return; }
    ptr += idx * 2;
    *(u16*)(ptr + 0x612) = val;
}

/* 0x801FD684 | size: 0x34 */
s32 fightOutPokemonBiosGetMeetEnemyFightPokemonEntryId(u8* ptr, u8 idx) {
    if (ptr == NULL) { return -1; }
    if (idx >= 0xC) { return -1; }
    ptr += idx * 2;
    return *(s16*)(ptr + 0x612);
}

/* Address: 0x801FD6B8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetDamageSpeTargetId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->damageSpeTargetId = val;
}

/* Address: 0x801FD6C8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetDamageSpeValue(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->damageSpeValue = val;
}

/* Address: 0x801FD6D8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetDamageAtkTargetId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->damageAtkTargetId = val;
}

/* Address: 0x801FD6E8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetDamageAtkValue(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->damageAtkValue = val;
}

/* Address: 0x801FD6F8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetSuccessCnt(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->successCnt = val;
}

/* Address: 0x801FD708 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetStockItemDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->stockItemDataId = val;
}

/* Address: 0x801FD718 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetUsedItemDataId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->usedItemDataId = val;
}

/* Address: 0x801FD728 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetNamakeFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->namakeFlag = val;
}

/* Address: 0x801FD738 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetDamageSpeTargetId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->damageSpeTargetId;
}

/* Address: 0x801FD750 | Size: 0x18 | Pattern: nullcheck_getter */
s16 fightOutPokemonBiosGetDamageSpeValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(s16*)(&ptr[0x686]);
}

/* Address: 0x801FD768 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetDamageAtkTargetId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->damageAtkTargetId;
}

/* Address: 0x801FD780 | Size: 0x18 | Pattern: nullcheck_getter */
s16 fightOutPokemonBiosGetDamageAtkValue(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return *(s16*)(&ptr[0x682]);
}

/* Address: 0x801FD798 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetSuccessCnt(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->successCnt;
}

/* Address: 0x801FD7B0 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetStockItemDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->stockItemDataId;
}

/* Address: 0x801FD7C8 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetUsedItemDataId(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->usedItemDataId;
}

/* Address: 0x801FD7E0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetNamakeFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->namakeFlag;
}

/* Address: 0x801FD7F8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetSequencePtr(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->sequencePtr = val;
}

/* Address: 0x801FD808 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightOutPokemonBiosGetSequencePtr(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->sequencePtr;
}

/* Address: 0x801FD820 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetFightoutTurnCount(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->fightoutTurnCount = val;
}

/* Address: 0x801FD830 | Size: 0x10 | Pattern: nullcheck_setter */
void fn_801FD830(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    *(u16*)(&ptr[0x60C]) = val;
}

/* Address: 0x801FD840 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetAbicntAvoid(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->abicntAvoid = val;
}

/* Address: 0x801FD850 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetAbicntAverage(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->abicntAverage = val;
}

/* Address: 0x801FD860 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetAbicntNimbleness(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->abicntNimbleness = val;
}

/* Address: 0x801FD870 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetAbicntSpeDef(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->abicntSpeDef = val;
}

/* Address: 0x801FD880 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetAbicntSpeAtk(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->abicntSpeAtk = val;
}

/* Address: 0x801FD890 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetAbicntPhyDef(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->abicntPhyDef = val;
}

/* Address: 0x801FD8A0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetAbicntPhyAtk(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->abicntPhyAtk = val;
}

/* Address: 0x801FD8B0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetFightPokemonPtr(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->fightPokemonPtr = val;
}

/* Address: 0x801FD8C0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightOutPokemonBiosSetMotoFightPokemonPtr(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightOutPokemonBiosFields*)ptr)->motoFightPokemonPtr = val;
}

/* Address: 0x801FD8D0 | Size: 0x10 | Pattern: nullcheck_setter */
void fightPokemonBiosSetHokakuFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightPokemonBiosFields*)ptr)->hokakuFlag = val;
}

/* Address: 0x801FD8E0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightPokemonBiosGetHokakuFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightPokemonBiosFields*)ptr)->hokakuFlag;
}

/* Address: 0x801FD8F8 | Size: 0x10 | Pattern: nullcheck_setter */
void fightPokemonBiosSetDarkOutFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightPokemonBiosFields*)ptr)->darkOutFlag = val;
}

/* Address: 0x801FD908 | Size: 0x10 | Pattern: nullcheck_setter */
void fightPokemonBiosSetLevelUpFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightPokemonBiosFields*)ptr)->levelUpFlag = val;
}

/* Address: 0x801FD918 | Size: 0x10 | Pattern: nullcheck_setter */
void fightPokemonBiosSetCatchEntryFlag(u8* ptr, u8 val) {
    if (ptr == NULL) { return; }
    ((FightPokemonBiosFields*)ptr)->catchEntryFlag = val;
}

/* Address: 0x801FD928 | Size: 0x10 | Pattern: nullcheck_setter */
void fightPokemonBiosSetEntryId(u8* ptr, u16 val) {
    if (ptr == NULL) { return; }
    ((FightPokemonBiosFields*)ptr)->entryId = val;
}

/* Address: 0x801FD938 | Size: 0x10 | Pattern: nullcheck_setter */
void fightPokemonBiosSetMotoPokemonPtr(u8* ptr, u32 val) {
    if (ptr == NULL) { return; }
    ((FightPokemonBiosFields*)ptr)->motoPokemonPtr = val;
}

/* Address: 0x801FD948 | Size: 0x18 | Pattern: nullcheck_getter */
u16 fightOutPokemonBiosGetFightoutTurnCount(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->fightoutTurnCount;
}

/* Address: 0x801FD960 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetAbicntAvoid(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->abicntAvoid;
}

/* Address: 0x801FD978 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetAbicntAverage(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->abicntAverage;
}

/* Address: 0x801FD990 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetAbicntNimbleness(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->abicntNimbleness;
}

/* Address: 0x801FD9A8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetAbicntSpeDef(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->abicntSpeDef;
}

/* Address: 0x801FD9C0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetAbicntSpeAtk(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->abicntSpeAtk;
}

/* Address: 0x801FD9D8 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetAbicntPhyDef(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->abicntPhyDef;
}

/* Address: 0x801FD9F0 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightOutPokemonBiosGetAbicntPhyAtk(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->abicntPhyAtk;
}

/* 0x801FDA08 | size: 0x18 */
u8* fightOutPokemonBiosGetFightItemPtr(u8* ptr) {
    if (ptr == NULL) { return NULL; }
    return ptr + 0x5F4;
}

/* 0x801FDA20 | size: 0x18 */
u8* fightOutPokemonBiosGetFightWazaPtr(u8* ptr) {
    if (ptr == NULL) { return NULL; }
    return ptr + 0x49C;
}

/* 0x801FDA38 | size: 0x34 */
u8* fightOutPokemonBiosGetFightoutJoutaiPtr(u8* ptr, u16 idx) {
    if (ptr == NULL) { return NULL; }
    if (idx >= 0x34) { return NULL; }
    return ptr + idx * 0x10 + 0x15C;
}

/* 0x801FDA6C | size: 0x18 */
u8* fightOutPokemonBiosGetFightPokemonHensinBuffPtr(u8* ptr) {
    if (ptr == NULL) { return NULL; }
    return ptr + 0x8;
}

/* Address: 0x801FDA84 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightOutPokemonBiosGetFightPokemonPtr(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->fightPokemonPtr;
}

/* Address: 0x801FDA9C | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightOutPokemonBiosGetMotoFightPokemonPtr(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightOutPokemonBiosFields*)ptr)->motoFightPokemonPtr;
}

/* Address: 0x801FDAB4 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightPokemonBiosGetDarkOutFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightPokemonBiosFields*)ptr)->darkOutFlag;
}

/* Address: 0x801FDACC | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightPokemonBiosGetLevelUpFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightPokemonBiosFields*)ptr)->levelUpFlag;
}

/* Address: 0x801FDAE4 | Size: 0x18 | Pattern: nullcheck_getter */
u8 fightPokemonBiosGetCatchEntryFlag(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightPokemonBiosFields*)ptr)->catchEntryFlag;
}

/* 0x801FDAFC | size: 0x18 */
s32 fightPokemonBiosGetEntryId(u8* ptr) {
    if (ptr == NULL) { return -1; }
    return *(s16*)(ptr + 0x14C);
}

/* 0x801FDB14 | size: 0x34 */
u8* fightPokemonBiosGetFightJoutaiPtr(u8* ptr, u16 idx) {
    if (ptr == NULL) { return NULL; }
    if (idx >= 1) { return NULL; }
    return ptr + idx * 0x10 + 0x13C;
}

/* 0x801FDB48 | size: 0x18 */
u8* fightPokemonBiosGetPokemonBuffPtr(u8* ptr) {
    if (ptr == NULL) { return NULL; }
    return ptr + 0x4;
}
/* Address: 0x801FDB60 | Size: 0x18 | Pattern: nullcheck_getter */
u32 fightPokemonBiosGetMotoPokemonPtr(u8* ptr) {
    if (ptr == NULL) { return 0; }
    return ((FightPokemonBiosFields*)ptr)->motoPokemonPtr;
}

/* ===================================================================
 * AUTO-GENERATED accessor functions
 * Generated by tools/gen_accessors.py
 * 2 functions matched
 * =================================================================== */

