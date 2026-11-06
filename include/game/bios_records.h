/* The records the game reads through its *Bios accessors, as those accessors name them. Offsets are the console's:
 * tools check them on every build that has a compiler for it. Generated once from the accessors, then yours to edit. */
#ifndef GAME_BIOS_RECORDS_H
#define GAME_BIOS_RECORDS_H

#include "dolphin/types.h"

typedef struct FightActionBiosFields {
    u8 pad_00[0x1C];
    u32 fifoBanme; /* 0x1C */
} FightActionBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightActionBiosFields, fifoBanme) == 0x1C, "FightActionBiosFields.fifoBanme");
#endif

typedef struct FightActionDataBiosFields {
    u16 kind; /* 0x00 */
    u8 pad_02[0x2];
    u32 buff; /* 0x04 */
} FightActionDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightActionDataBiosFields, kind) == 0x0, "FightActionDataBiosFields.kind");
_Static_assert(__builtin_offsetof(FightActionDataBiosFields, buff) == 0x4, "FightActionDataBiosFields.buff");
#endif

typedef struct FightActionKindDataBiosFields {
    u8 pad_00[0x4];
    u32 flowFuncPtr; /* 0x04 */
    u32 dispFuncPtr; /* 0x08 */
} FightActionKindDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightActionKindDataBiosFields, flowFuncPtr) == 0x4, "FightActionKindDataBiosFields.flowFuncPtr");
_Static_assert(__builtin_offsetof(FightActionKindDataBiosFields, dispFuncPtr) == 0x8, "FightActionKindDataBiosFields.dispFuncPtr");
#endif

typedef struct FightFloorBiosFields {
    u8 pad_00[0x10];
    u16 turnCount; /* 0x10 */
    u16 encountDataId; /* 0x12 */
    u8 pad_14[0xA460];
    u32 attackPokemonPtr; /* 0xA474 */
    u32 defensePokemonPtr; /* 0xA478 */
    u32 escapePokemonPtr; /* 0xA47C */
    u32 irekaePokemonPtr; /* 0xA480 */
    u32 kizetuPokemonPtr; /* 0xA484 */
    u32 tuikakoukaPokemonPtr; /* 0xA488 */
    u32 tokuseiPokemonPtr; /* 0xA48C */
    u32 itemPokemonPtr; /* 0xA490 */
    u32 appointPokemonPtr; /* 0xA494 */
    u32 appointTrainerPtr; /* 0xA498 */
    u32 appointWazaPtr; /* 0xA49C */
    u32 appointSidePtr; /* 0xA4A0 */
    u32 appointItemPtr; /* 0xA4A4 */
    u32 attackMsgId; /* 0xA4A8 */
    u32 criticalMsgId; /* 0xA4AC */
    u32 wazakoukaMsgId; /* 0xA4B0 */
    u32 appointMsgId; /* 0xA4B4 */
    u16 appointPokemonDataId; /* 0xA4B8 */
    u16 appointWazaDataId; /* 0xA4BA */
    u16 appointItemDataId; /* 0xA4BC */
    u16 appointTokuseiDataId; /* 0xA4BE */
    u16 fightPokemonEntryCnt; /* 0xA4C0 */
    u8 pad_A4C2[0x22];
    u16 firstAttackRnd; /* 0xA4E4 */
} FightFloorBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightFloorBiosFields, turnCount) == 0x10, "FightFloorBiosFields.turnCount");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, encountDataId) == 0x12, "FightFloorBiosFields.encountDataId");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, attackPokemonPtr) == 0xA474, "FightFloorBiosFields.attackPokemonPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, defensePokemonPtr) == 0xA478, "FightFloorBiosFields.defensePokemonPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, escapePokemonPtr) == 0xA47C, "FightFloorBiosFields.escapePokemonPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, irekaePokemonPtr) == 0xA480, "FightFloorBiosFields.irekaePokemonPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, kizetuPokemonPtr) == 0xA484, "FightFloorBiosFields.kizetuPokemonPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, tuikakoukaPokemonPtr) == 0xA488, "FightFloorBiosFields.tuikakoukaPokemonPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, tokuseiPokemonPtr) == 0xA48C, "FightFloorBiosFields.tokuseiPokemonPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, itemPokemonPtr) == 0xA490, "FightFloorBiosFields.itemPokemonPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, appointPokemonPtr) == 0xA494, "FightFloorBiosFields.appointPokemonPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, appointTrainerPtr) == 0xA498, "FightFloorBiosFields.appointTrainerPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, appointWazaPtr) == 0xA49C, "FightFloorBiosFields.appointWazaPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, appointSidePtr) == 0xA4A0, "FightFloorBiosFields.appointSidePtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, appointItemPtr) == 0xA4A4, "FightFloorBiosFields.appointItemPtr");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, attackMsgId) == 0xA4A8, "FightFloorBiosFields.attackMsgId");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, criticalMsgId) == 0xA4AC, "FightFloorBiosFields.criticalMsgId");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, wazakoukaMsgId) == 0xA4B0, "FightFloorBiosFields.wazakoukaMsgId");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, appointMsgId) == 0xA4B4, "FightFloorBiosFields.appointMsgId");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, appointPokemonDataId) == 0xA4B8, "FightFloorBiosFields.appointPokemonDataId");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, appointWazaDataId) == 0xA4BA, "FightFloorBiosFields.appointWazaDataId");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, appointItemDataId) == 0xA4BC, "FightFloorBiosFields.appointItemDataId");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, appointTokuseiDataId) == 0xA4BE, "FightFloorBiosFields.appointTokuseiDataId");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, fightPokemonEntryCnt) == 0xA4C0, "FightFloorBiosFields.fightPokemonEntryCnt");
_Static_assert(__builtin_offsetof(FightFloorBiosFields, firstAttackRnd) == 0xA4E4, "FightFloorBiosFields.firstAttackRnd");
#endif

typedef struct FightFloorDataBiosFields {
    u8 tikeiDataId; /* 0x00 */
    u8 pad_01[0x1];
    u16 floorDataId; /* 0x02 */
    u32 name; /* 0x04 */
    u32 syoukaiWzxDataId; /* 0x08 */
    u32 bgmSndId; /* 0x0C */
    u32 envSndId; /* 0x10 */
} FightFloorDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightFloorDataBiosFields, tikeiDataId) == 0x0, "FightFloorDataBiosFields.tikeiDataId");
_Static_assert(__builtin_offsetof(FightFloorDataBiosFields, floorDataId) == 0x2, "FightFloorDataBiosFields.floorDataId");
_Static_assert(__builtin_offsetof(FightFloorDataBiosFields, name) == 0x4, "FightFloorDataBiosFields.name");
_Static_assert(__builtin_offsetof(FightFloorDataBiosFields, syoukaiWzxDataId) == 0x8, "FightFloorDataBiosFields.syoukaiWzxDataId");
_Static_assert(__builtin_offsetof(FightFloorDataBiosFields, bgmSndId) == 0xC, "FightFloorDataBiosFields.bgmSndId");
_Static_assert(__builtin_offsetof(FightFloorDataBiosFields, envSndId) == 0x10, "FightFloorDataBiosFields.envSndId");
#endif

typedef struct FightItemBiosFields {
    u16 itemDataId; /* 0x00 */
    u16 targetDataId; /* 0x02 */
    u32 count; /* 0x04 */
    u32 buff; /* 0x08 */
} FightItemBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightItemBiosFields, itemDataId) == 0x0, "FightItemBiosFields.itemDataId");
_Static_assert(__builtin_offsetof(FightItemBiosFields, targetDataId) == 0x2, "FightItemBiosFields.targetDataId");
_Static_assert(__builtin_offsetof(FightItemBiosFields, count) == 0x4, "FightItemBiosFields.count");
_Static_assert(__builtin_offsetof(FightItemBiosFields, buff) == 0x8, "FightItemBiosFields.buff");
#endif

typedef struct FightOutPokemonBiosFields {
    u32 motoFightPokemonPtr; /* 0x00 */
    u32 fightPokemonPtr; /* 0x04 */
    u8 pad_08[0x5F8];
    u32 sequencePtr; /* 0x600 */
    u8 abicntPhyAtk; /* 0x604 */
    u8 abicntPhyDef; /* 0x605 */
    u8 abicntSpeAtk; /* 0x606 */
    u8 abicntSpeDef; /* 0x607 */
    u8 abicntNimbleness; /* 0x608 */
    u8 abicntAverage; /* 0x609 */
    u8 abicntAvoid; /* 0x60A */
    u8 pad_60B[0x5];
    u16 fightoutTurnCount; /* 0x610 */
    u8 pad_612[0x4E];
    u16 tokuseiDataId; /* 0x660 */
    u8 pad_662[0x6];
    u16 sketchWazaDataId; /* 0x668 */
    u16 lastSelectWazaDataId; /* 0x66A */
    u16 lastUseWazaDataId; /* 0x66C */
    u16 lastReceiveWazaTargetDataId; /* 0x66E */
    u16 hitWazaDataId; /* 0x670 */
    u16 hitWazaZokuseiDataId; /* 0x672 */
    u16 gamanDamageValue; /* 0x674 */
    u16 gamanDamageTargetId; /* 0x676 */
    u16 oumuWazaDataId; /* 0x678 */
    u8 namakeFlag; /* 0x67A */
    u8 pad_67B[0x1];
    u16 usedItemDataId; /* 0x67C */
    u8 successCnt; /* 0x67E */
    u8 pad_67F[0x1];
    u16 stockItemDataId; /* 0x680 */
    u16 damageAtkValue; /* 0x682 */
    u16 damageAtkTargetId; /* 0x684 */
    u16 damageSpeValue; /* 0x686 */
    u16 damageSpeTargetId; /* 0x688 */
    u8 mahiNoAttackFlag; /* 0x68A */
    u8 konranMyselfAttackFlag; /* 0x68B */
    u8 outWazaKoukanaiFlag; /* 0x68C */
    u8 tameWazaFlag; /* 0x68D */
    u8 itemNigeruFlag; /* 0x68E */
    u8 huuinNoAttackFlag; /* 0x68F */
    u8 meroMeroNoAttackFlag; /* 0x690 */
    u8 kanashibariNoAttackFlag; /* 0x691 */
    u8 chouhatsuNoAttackFlag; /* 0x692 */
    u8 ichamonNoAttackFlag; /* 0x693 */
    u8 hirumuNoAttackFlag; /* 0x694 */
    u8 passPpdecFlag; /* 0x695 */
    u8 fightActionFlag; /* 0x696 */
    u8 doClearbodyFlag; /* 0x697 */
    u8 receivesWazaHiraishinFlag; /* 0x698 */
    u8 vanishoffFlag; /* 0x699 */
    u8 doIkakuFlag; /* 0x69A */
    u8 doTraceFlag; /* 0x69B */
    u8 noPressureFlag; /* 0x69C */
    u8 irekaetaFlag; /* 0x69D */
    u8 itemKoraetaFlag; /* 0x69E */
    u8 pad_69F[0x1];
    u32 kaigaraDamageValue; /* 0x6A0 */
    u16 myselfDamageAtkValue; /* 0x6A4 */
    u16 myselfDamageAtkTargetId; /* 0x6A6 */
    u16 myselfDamageSpeValue; /* 0x6A8 */
    u16 myselfDamageSpeTargetId; /* 0x6AA */
    u8 kizetuFlag; /* 0x6AC */
    u8 pad_6AD[0x1];
    u16 irekaeTargetEntryId; /* 0x6AE */
} FightOutPokemonBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, motoFightPokemonPtr) == 0x0, "FightOutPokemonBiosFields.motoFightPokemonPtr");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, fightPokemonPtr) == 0x4, "FightOutPokemonBiosFields.fightPokemonPtr");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, sequencePtr) == 0x600, "FightOutPokemonBiosFields.sequencePtr");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, abicntPhyAtk) == 0x604, "FightOutPokemonBiosFields.abicntPhyAtk");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, abicntPhyDef) == 0x605, "FightOutPokemonBiosFields.abicntPhyDef");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, abicntSpeAtk) == 0x606, "FightOutPokemonBiosFields.abicntSpeAtk");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, abicntSpeDef) == 0x607, "FightOutPokemonBiosFields.abicntSpeDef");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, abicntNimbleness) == 0x608, "FightOutPokemonBiosFields.abicntNimbleness");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, abicntAverage) == 0x609, "FightOutPokemonBiosFields.abicntAverage");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, abicntAvoid) == 0x60A, "FightOutPokemonBiosFields.abicntAvoid");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, fightoutTurnCount) == 0x610, "FightOutPokemonBiosFields.fightoutTurnCount");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, tokuseiDataId) == 0x660, "FightOutPokemonBiosFields.tokuseiDataId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, sketchWazaDataId) == 0x668, "FightOutPokemonBiosFields.sketchWazaDataId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, lastSelectWazaDataId) == 0x66A, "FightOutPokemonBiosFields.lastSelectWazaDataId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, lastUseWazaDataId) == 0x66C, "FightOutPokemonBiosFields.lastUseWazaDataId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, lastReceiveWazaTargetDataId) == 0x66E, "FightOutPokemonBiosFields.lastReceiveWazaTargetDataId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, hitWazaDataId) == 0x670, "FightOutPokemonBiosFields.hitWazaDataId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, hitWazaZokuseiDataId) == 0x672, "FightOutPokemonBiosFields.hitWazaZokuseiDataId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, gamanDamageValue) == 0x674, "FightOutPokemonBiosFields.gamanDamageValue");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, gamanDamageTargetId) == 0x676, "FightOutPokemonBiosFields.gamanDamageTargetId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, oumuWazaDataId) == 0x678, "FightOutPokemonBiosFields.oumuWazaDataId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, namakeFlag) == 0x67A, "FightOutPokemonBiosFields.namakeFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, usedItemDataId) == 0x67C, "FightOutPokemonBiosFields.usedItemDataId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, successCnt) == 0x67E, "FightOutPokemonBiosFields.successCnt");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, stockItemDataId) == 0x680, "FightOutPokemonBiosFields.stockItemDataId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, damageAtkValue) == 0x682, "FightOutPokemonBiosFields.damageAtkValue");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, damageAtkTargetId) == 0x684, "FightOutPokemonBiosFields.damageAtkTargetId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, damageSpeValue) == 0x686, "FightOutPokemonBiosFields.damageSpeValue");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, damageSpeTargetId) == 0x688, "FightOutPokemonBiosFields.damageSpeTargetId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, mahiNoAttackFlag) == 0x68A, "FightOutPokemonBiosFields.mahiNoAttackFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, konranMyselfAttackFlag) == 0x68B, "FightOutPokemonBiosFields.konranMyselfAttackFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, outWazaKoukanaiFlag) == 0x68C, "FightOutPokemonBiosFields.outWazaKoukanaiFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, tameWazaFlag) == 0x68D, "FightOutPokemonBiosFields.tameWazaFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, itemNigeruFlag) == 0x68E, "FightOutPokemonBiosFields.itemNigeruFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, huuinNoAttackFlag) == 0x68F, "FightOutPokemonBiosFields.huuinNoAttackFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, meroMeroNoAttackFlag) == 0x690, "FightOutPokemonBiosFields.meroMeroNoAttackFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, kanashibariNoAttackFlag) == 0x691, "FightOutPokemonBiosFields.kanashibariNoAttackFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, chouhatsuNoAttackFlag) == 0x692, "FightOutPokemonBiosFields.chouhatsuNoAttackFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, ichamonNoAttackFlag) == 0x693, "FightOutPokemonBiosFields.ichamonNoAttackFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, hirumuNoAttackFlag) == 0x694, "FightOutPokemonBiosFields.hirumuNoAttackFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, passPpdecFlag) == 0x695, "FightOutPokemonBiosFields.passPpdecFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, fightActionFlag) == 0x696, "FightOutPokemonBiosFields.fightActionFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, doClearbodyFlag) == 0x697, "FightOutPokemonBiosFields.doClearbodyFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, receivesWazaHiraishinFlag) == 0x698, "FightOutPokemonBiosFields.receivesWazaHiraishinFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, vanishoffFlag) == 0x699, "FightOutPokemonBiosFields.vanishoffFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, doIkakuFlag) == 0x69A, "FightOutPokemonBiosFields.doIkakuFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, doTraceFlag) == 0x69B, "FightOutPokemonBiosFields.doTraceFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, noPressureFlag) == 0x69C, "FightOutPokemonBiosFields.noPressureFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, irekaetaFlag) == 0x69D, "FightOutPokemonBiosFields.irekaetaFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, itemKoraetaFlag) == 0x69E, "FightOutPokemonBiosFields.itemKoraetaFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, kaigaraDamageValue) == 0x6A0, "FightOutPokemonBiosFields.kaigaraDamageValue");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, myselfDamageAtkValue) == 0x6A4, "FightOutPokemonBiosFields.myselfDamageAtkValue");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, myselfDamageAtkTargetId) == 0x6A6, "FightOutPokemonBiosFields.myselfDamageAtkTargetId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, myselfDamageSpeValue) == 0x6A8, "FightOutPokemonBiosFields.myselfDamageSpeValue");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, myselfDamageSpeTargetId) == 0x6AA, "FightOutPokemonBiosFields.myselfDamageSpeTargetId");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, kizetuFlag) == 0x6AC, "FightOutPokemonBiosFields.kizetuFlag");
_Static_assert(__builtin_offsetof(FightOutPokemonBiosFields, irekaeTargetEntryId) == 0x6AE, "FightOutPokemonBiosFields.irekaeTargetEntryId");
#endif

typedef struct FightOutPokemonEnemyBiosFields {
    u32 targetFightOutPokemonPtr; /* 0x00 */
    u16 oumuWazaDataId; /* 0x04 */
    u16 initHp; /* 0x06 */
    u16 damage; /* 0x08 */
} FightOutPokemonEnemyBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightOutPokemonEnemyBiosFields, targetFightOutPokemonPtr) == 0x0, "FightOutPokemonEnemyBiosFields.targetFightOutPokemonPtr");
_Static_assert(__builtin_offsetof(FightOutPokemonEnemyBiosFields, oumuWazaDataId) == 0x4, "FightOutPokemonEnemyBiosFields.oumuWazaDataId");
_Static_assert(__builtin_offsetof(FightOutPokemonEnemyBiosFields, initHp) == 0x6, "FightOutPokemonEnemyBiosFields.initHp");
_Static_assert(__builtin_offsetof(FightOutPokemonEnemyBiosFields, damage) == 0x8, "FightOutPokemonEnemyBiosFields.damage");
#endif

typedef struct FightPokemonBiosFields {
    u32 motoPokemonPtr; /* 0x00 */
    u8 pad_04[0x148];
    u16 entryId; /* 0x14C */
    u8 catchEntryFlag; /* 0x14E */
    u8 levelUpFlag; /* 0x14F */
    u8 darkOutFlag; /* 0x150 */
    u8 hokakuFlag; /* 0x151 */
} FightPokemonBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightPokemonBiosFields, motoPokemonPtr) == 0x0, "FightPokemonBiosFields.motoPokemonPtr");
_Static_assert(__builtin_offsetof(FightPokemonBiosFields, entryId) == 0x14C, "FightPokemonBiosFields.entryId");
_Static_assert(__builtin_offsetof(FightPokemonBiosFields, catchEntryFlag) == 0x14E, "FightPokemonBiosFields.catchEntryFlag");
_Static_assert(__builtin_offsetof(FightPokemonBiosFields, levelUpFlag) == 0x14F, "FightPokemonBiosFields.levelUpFlag");
_Static_assert(__builtin_offsetof(FightPokemonBiosFields, darkOutFlag) == 0x150, "FightPokemonBiosFields.darkOutFlag");
_Static_assert(__builtin_offsetof(FightPokemonBiosFields, hokakuFlag) == 0x151, "FightPokemonBiosFields.hokakuFlag");
#endif

typedef struct FightSideBiosFields {
    u16 fightSideDataId; /* 0x00 */
    u8 pad_02[0x522A];
    u8 makibisiCheckFlag; /* 0x522C */
} FightSideBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightSideBiosFields, fightSideDataId) == 0x0, "FightSideBiosFields.fightSideDataId");
_Static_assert(__builtin_offsetof(FightSideBiosFields, makibisiCheckFlag) == 0x522C, "FightSideBiosFields.makibisiCheckFlag");
#endif

typedef struct FightSideDataBiosFields {
    u16 yrot; /* 0x00 */
} FightSideDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightSideDataBiosFields, yrot) == 0x0, "FightSideDataBiosFields.yrot");
#endif

typedef struct FightTargetDataBiosFields {
    u8 statusKid; /* 0x00 */
    u8 pad_01[0x3];
    u32 buff; /* 0x04 */
} FightTargetDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightTargetDataBiosFields, statusKid) == 0x0, "FightTargetDataBiosFields.statusKid");
_Static_assert(__builtin_offsetof(FightTargetDataBiosFields, buff) == 0x4, "FightTargetDataBiosFields.buff");
#endif

typedef struct FightTrainerFields {
    u8 field00; /* 0x00 */
    u8 pad_01[0x3];
    u16 field04; /* 0x04 */
    u16 field06; /* 0x06 */
    u32 field08; /* 0x08 */
    u32 field0C; /* 0x0C */
    u32 field10; /* 0x10 */
} FightTrainerFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightTrainerFields, field00) == 0x0, "FightTrainerFields.field00");
_Static_assert(__builtin_offsetof(FightTrainerFields, field04) == 0x4, "FightTrainerFields.field04");
_Static_assert(__builtin_offsetof(FightTrainerFields, field06) == 0x6, "FightTrainerFields.field06");
_Static_assert(__builtin_offsetof(FightTrainerFields, field08) == 0x8, "FightTrainerFields.field08");
_Static_assert(__builtin_offsetof(FightTrainerFields, field0C) == 0xC, "FightTrainerFields.field0C");
_Static_assert(__builtin_offsetof(FightTrainerFields, field10) == 0x10, "FightTrainerFields.field10");
#endif

typedef struct FightTrainerAiDataBiosFields {
    u8 pokemonSelectRandomFlag; /* 0x00 */
    u8 pokemonSelectWeakPointFlag; /* 0x01 */
    u8 pokemonDataOrderOutFlag; /* 0x02 */
    u8 pokemonDataOrderAceBossFlag; /* 0x03 */
    u8 keyPlayerFlag; /* 0x04 */
    u8 pokemonJoutaiFlag; /* 0x05 */
    u8 comboValue; /* 0x06 */
    u8 irekaeValue; /* 0x07 */
    u8 itemValue; /* 0x08 */
    u8 paramExpectFlag; /* 0x09 */
    u8 paramStoreFlag; /* 0x0A */
    u8 zokuseiCheckFlag; /* 0x0B */
    u8 tokuseiCheckFlag; /* 0x0C */
    u8 nokoriHpValue; /* 0x0D */
    u8 wazaDamageFlag; /* 0x0E */
    u8 abicntMaxValue; /* 0x0F */
    u8 abicntMinValue; /* 0x10 */
    u8 defensePokemonRndSelectFlag; /* 0x11 */
    u8 wazaRndSelectFlag; /* 0x12 */
    u8 wazaInitValueFlag; /* 0x13 */
    u8 partFlag; /* 0x14 */
    u8 wazaHitFlag; /* 0x15 */
    u8 wazaAvgValue; /* 0x16 */
    u8 wazaRiskFlag; /* 0x17 */
    u8 wazaNokoriPpValue; /* 0x18 */
    u8 lastValueRevise; /* 0x19 */
} FightTrainerAiDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, pokemonSelectRandomFlag) == 0x0, "FightTrainerAiDataBiosFields.pokemonSelectRandomFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, pokemonSelectWeakPointFlag) == 0x1, "FightTrainerAiDataBiosFields.pokemonSelectWeakPointFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, pokemonDataOrderOutFlag) == 0x2, "FightTrainerAiDataBiosFields.pokemonDataOrderOutFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, pokemonDataOrderAceBossFlag) == 0x3, "FightTrainerAiDataBiosFields.pokemonDataOrderAceBossFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, keyPlayerFlag) == 0x4, "FightTrainerAiDataBiosFields.keyPlayerFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, pokemonJoutaiFlag) == 0x5, "FightTrainerAiDataBiosFields.pokemonJoutaiFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, comboValue) == 0x6, "FightTrainerAiDataBiosFields.comboValue");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, irekaeValue) == 0x7, "FightTrainerAiDataBiosFields.irekaeValue");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, itemValue) == 0x8, "FightTrainerAiDataBiosFields.itemValue");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, paramExpectFlag) == 0x9, "FightTrainerAiDataBiosFields.paramExpectFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, paramStoreFlag) == 0xA, "FightTrainerAiDataBiosFields.paramStoreFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, zokuseiCheckFlag) == 0xB, "FightTrainerAiDataBiosFields.zokuseiCheckFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, tokuseiCheckFlag) == 0xC, "FightTrainerAiDataBiosFields.tokuseiCheckFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, nokoriHpValue) == 0xD, "FightTrainerAiDataBiosFields.nokoriHpValue");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, wazaDamageFlag) == 0xE, "FightTrainerAiDataBiosFields.wazaDamageFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, abicntMaxValue) == 0xF, "FightTrainerAiDataBiosFields.abicntMaxValue");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, abicntMinValue) == 0x10, "FightTrainerAiDataBiosFields.abicntMinValue");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, defensePokemonRndSelectFlag) == 0x11, "FightTrainerAiDataBiosFields.defensePokemonRndSelectFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, wazaRndSelectFlag) == 0x12, "FightTrainerAiDataBiosFields.wazaRndSelectFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, wazaInitValueFlag) == 0x13, "FightTrainerAiDataBiosFields.wazaInitValueFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, partFlag) == 0x14, "FightTrainerAiDataBiosFields.partFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, wazaHitFlag) == 0x15, "FightTrainerAiDataBiosFields.wazaHitFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, wazaAvgValue) == 0x16, "FightTrainerAiDataBiosFields.wazaAvgValue");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, wazaRiskFlag) == 0x17, "FightTrainerAiDataBiosFields.wazaRiskFlag");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, wazaNokoriPpValue) == 0x18, "FightTrainerAiDataBiosFields.wazaNokoriPpValue");
_Static_assert(__builtin_offsetof(FightTrainerAiDataBiosFields, lastValueRevise) == 0x19, "FightTrainerAiDataBiosFields.lastValueRevise");
#endif

typedef struct FightTrainerAiValueAddsubDataBiosFields {
    u32 value; /* 0x00 */
    u32 koudouName; /* 0x04 */
    u32 prefixName; /* 0x08 */
    u32 name; /* 0x0C */
} FightTrainerAiValueAddsubDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightTrainerAiValueAddsubDataBiosFields, value) == 0x0, "FightTrainerAiValueAddsubDataBiosFields.value");
_Static_assert(__builtin_offsetof(FightTrainerAiValueAddsubDataBiosFields, koudouName) == 0x4, "FightTrainerAiValueAddsubDataBiosFields.koudouName");
_Static_assert(__builtin_offsetof(FightTrainerAiValueAddsubDataBiosFields, prefixName) == 0x8, "FightTrainerAiValueAddsubDataBiosFields.prefixName");
_Static_assert(__builtin_offsetof(FightTrainerAiValueAddsubDataBiosFields, name) == 0xC, "FightTrainerAiValueAddsubDataBiosFields.name");
#endif

typedef struct FightTrainerDataBiosFields {
    u8 pad_00[0x2];
    u16 kindDataId; /* 0x02 */
} FightTrainerDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightTrainerDataBiosFields, kindDataId) == 0x2, "FightTrainerDataBiosFields.kindDataId");
#endif

typedef struct FightTrainerEnemyPokemonBiosFields {
    u16 fightEntryeId; /* 0x00 */
    u8 pad_02[0x8];
    u16 tokuseiFlag; /* 0x0A */
    u16 storeTokuseiData; /* 0x0C */
    u8 nowhp1banhikuiFlag; /* 0x0E */
    u8 lv1banhikuiFlag; /* 0x0F */
    u8 defense1banhikuiFlag; /* 0x10 */
    u8 badwazaHaveFlag; /* 0x11 */
    u8 param1bantakaiFlag; /* 0x12 */
} FightTrainerEnemyPokemonBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightTrainerEnemyPokemonBiosFields, fightEntryeId) == 0x0, "FightTrainerEnemyPokemonBiosFields.fightEntryeId");
_Static_assert(__builtin_offsetof(FightTrainerEnemyPokemonBiosFields, tokuseiFlag) == 0xA, "FightTrainerEnemyPokemonBiosFields.tokuseiFlag");
_Static_assert(__builtin_offsetof(FightTrainerEnemyPokemonBiosFields, storeTokuseiData) == 0xC, "FightTrainerEnemyPokemonBiosFields.storeTokuseiData");
_Static_assert(__builtin_offsetof(FightTrainerEnemyPokemonBiosFields, nowhp1banhikuiFlag) == 0xE, "FightTrainerEnemyPokemonBiosFields.nowhp1banhikuiFlag");
_Static_assert(__builtin_offsetof(FightTrainerEnemyPokemonBiosFields, lv1banhikuiFlag) == 0xF, "FightTrainerEnemyPokemonBiosFields.lv1banhikuiFlag");
_Static_assert(__builtin_offsetof(FightTrainerEnemyPokemonBiosFields, defense1banhikuiFlag) == 0x10, "FightTrainerEnemyPokemonBiosFields.defense1banhikuiFlag");
_Static_assert(__builtin_offsetof(FightTrainerEnemyPokemonBiosFields, badwazaHaveFlag) == 0x11, "FightTrainerEnemyPokemonBiosFields.badwazaHaveFlag");
_Static_assert(__builtin_offsetof(FightTrainerEnemyPokemonBiosFields, param1bantakaiFlag) == 0x12, "FightTrainerEnemyPokemonBiosFields.param1bantakaiFlag");
#endif

typedef struct FightTrainerKindDataBiosFields {
    u16 syoukinBairitu; /* 0x00 */
    u8 pad_02[0x2];
    u32 prefixName; /* 0x04 */
    u32 bgmSndId; /* 0x08 */
} FightTrainerKindDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightTrainerKindDataBiosFields, syoukinBairitu) == 0x0, "FightTrainerKindDataBiosFields.syoukinBairitu");
_Static_assert(__builtin_offsetof(FightTrainerKindDataBiosFields, prefixName) == 0x4, "FightTrainerKindDataBiosFields.prefixName");
_Static_assert(__builtin_offsetof(FightTrainerKindDataBiosFields, bgmSndId) == 0x8, "FightTrainerKindDataBiosFields.bgmSndId");
#endif

typedef struct FightTrainerPokemonDataBiosFields {
    u8 tokuseiFlag; /* 0x00 */
    u8 sexDataId; /* 0x01 */
    u8 seikakuDataId; /* 0x02 */
    u8 darkPokemonFlag; /* 0x03 */
    u8 level; /* 0x04 */
    u8 keyPlayerFlag; /* 0x05 */
    u8 partDataId; /* 0x06 */
    u8 pad_07[0x1];
    u16 friend; /* 0x08 */
    u16 pokemonDataId; /* 0x0A */
    u16 itemBallId; /* 0x0C */
    u8 pad_0E[0x2];
    u32 itemDataId; /* 0x10 */
    u32 nickname; /* 0x14 */
} FightTrainerPokemonDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, tokuseiFlag) == 0x0, "FightTrainerPokemonDataBiosFields.tokuseiFlag");
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, sexDataId) == 0x1, "FightTrainerPokemonDataBiosFields.sexDataId");
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, seikakuDataId) == 0x2, "FightTrainerPokemonDataBiosFields.seikakuDataId");
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, darkPokemonFlag) == 0x3, "FightTrainerPokemonDataBiosFields.darkPokemonFlag");
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, level) == 0x4, "FightTrainerPokemonDataBiosFields.level");
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, keyPlayerFlag) == 0x5, "FightTrainerPokemonDataBiosFields.keyPlayerFlag");
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, partDataId) == 0x6, "FightTrainerPokemonDataBiosFields.partDataId");
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, friend) == 0x8, "FightTrainerPokemonDataBiosFields.friend");
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, pokemonDataId) == 0xA, "FightTrainerPokemonDataBiosFields.pokemonDataId");
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, itemBallId) == 0xC, "FightTrainerPokemonDataBiosFields.itemBallId");
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, itemDataId) == 0x10, "FightTrainerPokemonDataBiosFields.itemDataId");
_Static_assert(__builtin_offsetof(FightTrainerPokemonDataBiosFields, nickname) == 0x14, "FightTrainerPokemonDataBiosFields.nickname");
#endif

typedef struct FightTrainerPokemonPartDataBiosFields {
    u32 name; /* 0x00 */
} FightTrainerPokemonPartDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightTrainerPokemonPartDataBiosFields, name) == 0x0, "FightTrainerPokemonPartDataBiosFields.name");
#endif

typedef struct FightWazaBiosFields {
    u8 wazaBanme; /* 0x00 */
    u8 pad_01[0x1];
    u16 motoWazaDataId; /* 0x02 */
    u16 useWazaDataId; /* 0x04 */
    u16 targetDataId; /* 0x06 */
    u8 pad_08[0x90];
    u8 critical; /* 0x98 */
    u8 damageValue; /* 0x99 */
    u8 pad_9A[0x2];
    u32 damage; /* 0x9C */
    u32 hitDamage; /* 0xA0 */
    u16 iryoku; /* 0xA4 */
    u16 zokusei; /* 0xA6 */
    u8 kaisuu; /* 0xA8 */
    u8 autoMakeFlag; /* 0xA9 */
} FightWazaBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightWazaBiosFields, wazaBanme) == 0x0, "FightWazaBiosFields.wazaBanme");
_Static_assert(__builtin_offsetof(FightWazaBiosFields, motoWazaDataId) == 0x2, "FightWazaBiosFields.motoWazaDataId");
_Static_assert(__builtin_offsetof(FightWazaBiosFields, useWazaDataId) == 0x4, "FightWazaBiosFields.useWazaDataId");
_Static_assert(__builtin_offsetof(FightWazaBiosFields, targetDataId) == 0x6, "FightWazaBiosFields.targetDataId");
_Static_assert(__builtin_offsetof(FightWazaBiosFields, critical) == 0x98, "FightWazaBiosFields.critical");
_Static_assert(__builtin_offsetof(FightWazaBiosFields, damageValue) == 0x99, "FightWazaBiosFields.damageValue");
_Static_assert(__builtin_offsetof(FightWazaBiosFields, damage) == 0x9C, "FightWazaBiosFields.damage");
_Static_assert(__builtin_offsetof(FightWazaBiosFields, hitDamage) == 0xA0, "FightWazaBiosFields.hitDamage");
_Static_assert(__builtin_offsetof(FightWazaBiosFields, iryoku) == 0xA4, "FightWazaBiosFields.iryoku");
_Static_assert(__builtin_offsetof(FightWazaBiosFields, zokusei) == 0xA6, "FightWazaBiosFields.zokusei");
_Static_assert(__builtin_offsetof(FightWazaBiosFields, kaisuu) == 0xA8, "FightWazaBiosFields.kaisuu");
_Static_assert(__builtin_offsetof(FightWazaBiosFields, autoMakeFlag) == 0xA9, "FightWazaBiosFields.autoMakeFlag");
#endif

typedef struct FightWazaCriticalDataBiosFields {
    u8 bunbo; /* 0x00 */
} FightWazaCriticalDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FightWazaCriticalDataBiosFields, bunbo) == 0x0, "FightWazaCriticalDataBiosFields.bunbo");
#endif

typedef struct FloorCharacterBiosFields {
    u8 pad_00[0x8];
    u16 nameID; /* 0x08 */
    u8 pad_0A[0x6];
    u32 moveSctID; /* 0x10 */
    u32 talkSctID; /* 0x14 */
} FloorCharacterBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(FloorCharacterBiosFields, nameID) == 0x8, "FloorCharacterBiosFields.nameID");
_Static_assert(__builtin_offsetof(FloorCharacterBiosFields, moveSctID) == 0x10, "FloorCharacterBiosFields.moveSctID");
_Static_assert(__builtin_offsetof(FloorCharacterBiosFields, talkSctID) == 0x14, "FloorCharacterBiosFields.talkSctID");
#endif

typedef struct WazaDataBiosFields {
    u8 pri; /* 0x00 */
    u8 pp; /* 0x01 */
    u8 zokuseiDataId; /* 0x02 */
    u8 rangeId; /* 0x03 */
    u8 avg; /* 0x04 */
    u8 addFightKoukaAvg; /* 0x05 */
    u8 dageki; /* 0x06 */
    u8 mamoru; /* 0x07 */
    u8 majikku; /* 0x08 */
    u8 yokodori; /* 0x09 */
    u8 oumugaesi; /* 0x0A */
    u8 oujanosirusi; /* 0x0B */
    u8 yubiwohuru; /* 0x0C */
    u8 monomane; /* 0x0D */
    u8 nekonote; /* 0x0E */
    u8 negoto; /* 0x0F */
    u8 bouon; /* 0x10 */
    u8 pressure; /* 0x11 */
    u8 hidenFlag; /* 0x12 */
    u8 riskFlag; /* 0x13 */
    u8 pad_14[0x2];
    u16 iryoku; /* 0x16 */
    u16 fightKoukaDataId; /* 0x18 */
    u16 seqId; /* 0x1A */
    u8 pad_1C[0x4];
    u32 name; /* 0x20 */
    u32 fightAttackTunagiMsgId; /* 0x24 */
    u32 fightAttackMsgId; /* 0x28 */
    u32 doc; /* 0x2C */
    u32 wazawzxdataId; /* 0x30 */
} WazaDataBiosFields;
#ifdef __clang__
_Static_assert(__builtin_offsetof(WazaDataBiosFields, pri) == 0x0, "WazaDataBiosFields.pri");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, pp) == 0x1, "WazaDataBiosFields.pp");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, zokuseiDataId) == 0x2, "WazaDataBiosFields.zokuseiDataId");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, rangeId) == 0x3, "WazaDataBiosFields.rangeId");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, avg) == 0x4, "WazaDataBiosFields.avg");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, addFightKoukaAvg) == 0x5, "WazaDataBiosFields.addFightKoukaAvg");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, dageki) == 0x6, "WazaDataBiosFields.dageki");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, mamoru) == 0x7, "WazaDataBiosFields.mamoru");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, majikku) == 0x8, "WazaDataBiosFields.majikku");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, yokodori) == 0x9, "WazaDataBiosFields.yokodori");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, oumugaesi) == 0xA, "WazaDataBiosFields.oumugaesi");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, oujanosirusi) == 0xB, "WazaDataBiosFields.oujanosirusi");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, yubiwohuru) == 0xC, "WazaDataBiosFields.yubiwohuru");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, monomane) == 0xD, "WazaDataBiosFields.monomane");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, nekonote) == 0xE, "WazaDataBiosFields.nekonote");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, negoto) == 0xF, "WazaDataBiosFields.negoto");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, bouon) == 0x10, "WazaDataBiosFields.bouon");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, pressure) == 0x11, "WazaDataBiosFields.pressure");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, hidenFlag) == 0x12, "WazaDataBiosFields.hidenFlag");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, riskFlag) == 0x13, "WazaDataBiosFields.riskFlag");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, iryoku) == 0x16, "WazaDataBiosFields.iryoku");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, fightKoukaDataId) == 0x18, "WazaDataBiosFields.fightKoukaDataId");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, seqId) == 0x1A, "WazaDataBiosFields.seqId");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, name) == 0x20, "WazaDataBiosFields.name");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, fightAttackTunagiMsgId) == 0x24, "WazaDataBiosFields.fightAttackTunagiMsgId");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, fightAttackMsgId) == 0x28, "WazaDataBiosFields.fightAttackMsgId");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, doc) == 0x2C, "WazaDataBiosFields.doc");
_Static_assert(__builtin_offsetof(WazaDataBiosFields, wazawzxdataId) == 0x30, "WazaDataBiosFields.wazawzxdataId");
#endif

#endif
