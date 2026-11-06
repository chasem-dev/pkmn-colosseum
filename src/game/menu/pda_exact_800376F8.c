#include "game/records/lbl_803A654C.h"
#include "dolphin/types.h"

typedef struct PdaSprite {
    u8 pad00[0x50];
    s16 field_50;
    u8 pad52[0x15];
    u8 alpha;
} PdaSprite;

extern u8 lbl_803A654C[];
extern f32 lbl_8047BA58;
extern f32 lbl_8047A494;

/* Four identical fade steps over the PDA fade block (one per sprite slot);
 * written out per function (was a PDA_FADE_STEP macro). */
void fn_800376F8(void* window, volatile PdaSprite* sprite)
{
    f32 value;
    f32 next;
    f32 velocity;
    s32 alpha;

    (void)window;
    value = ((Work803A654C*)lbl_803A654C)->field_58;
    if (value < lbl_8047BA58) {
        alpha = (s32)value;
        if ((s16)alpha < -0xff) {
            alpha = -0xff;
        }
        value = 0.0f;
        sprite->alpha = (u8)(alpha + 0xff);
        next = ((Work803A654C*)lbl_803A654C)->field_58 +
               (velocity = ((Work803A654C*)lbl_803A654C)->field_50);
        ((Work803A654C*)lbl_803A654C)->field_58 = next;
        ((Work803A654C*)lbl_803A654C)->field_50 =
            lbl_8047A494 * ((Work803A654C*)lbl_803A654C)->field_4C + velocity;
        if (next > value) {
            ((Work803A654C*)lbl_803A654C)->field_58 = value;
            sprite->field_50 = (s16)((Work803A654C*)lbl_803A654C)->field_54;
        }
        sprite->field_50 = (s16)(((Work803A654C*)lbl_803A654C)->field_54 +
                                  ((Work803A654C*)lbl_803A654C)->field_58);
    }
}

void fn_800377B4(void* window, volatile PdaSprite* sprite)
{
    f32 value;
    f32 next;
    f32 velocity;
    s32 alpha;

    (void)window;
    value = ((Work803A654C*)lbl_803A654C)->field_40;
    if (value < lbl_8047BA58) {
        alpha = (s32)value;
        if ((s16)alpha < -0xff) {
            alpha = -0xff;
        }
        value = 0.0f;
        sprite->alpha = (u8)(alpha + 0xff);
        next = ((Work803A654C*)lbl_803A654C)->field_40 +
               (velocity = ((Work803A654C*)lbl_803A654C)->field_38);
        ((Work803A654C*)lbl_803A654C)->field_40 = next;
        ((Work803A654C*)lbl_803A654C)->field_38 =
            lbl_8047A494 * ((Work803A654C*)lbl_803A654C)->field_34 + velocity;
        if (next > value) {
            ((Work803A654C*)lbl_803A654C)->field_40 = value;
            sprite->field_50 = (s16)((Work803A654C*)lbl_803A654C)->field_3C;
        }
        sprite->field_50 = (s16)(((Work803A654C*)lbl_803A654C)->field_3C +
                                  ((Work803A654C*)lbl_803A654C)->field_40);
    }
}

void fn_80037870(void* window, volatile PdaSprite* sprite)
{
    f32 value;
    f32 next;
    f32 velocity;
    s32 alpha;

    (void)window;
    value = ((Work803A654C*)lbl_803A654C)->field_28;
    if (value < lbl_8047BA58) {
        alpha = (s32)value;
        if ((s16)alpha < -0xff) {
            alpha = -0xff;
        }
        value = 0.0f;
        sprite->alpha = (u8)(alpha + 0xff);
        next = ((Work803A654C*)lbl_803A654C)->field_28 +
               (velocity = ((Work803A654C*)lbl_803A654C)->field_20);
        ((Work803A654C*)lbl_803A654C)->field_28 = next;
        ((Work803A654C*)lbl_803A654C)->field_20 =
            lbl_8047A494 * ((Work803A654C*)lbl_803A654C)->field_1C + velocity;
        if (next > value) {
            ((Work803A654C*)lbl_803A654C)->field_28 = value;
            sprite->field_50 = (s16)((Work803A654C*)lbl_803A654C)->field_24;
        }
        sprite->field_50 = (s16)(((Work803A654C*)lbl_803A654C)->field_24 +
                                  ((Work803A654C*)lbl_803A654C)->field_28);
    }
}

void fn_8003792C(void* window, volatile PdaSprite* sprite)
{
    f32 value;
    f32 next;
    f32 velocity;
    s32 alpha;

    (void)window;
    value = ((Work803A654C*)lbl_803A654C)->field_10;
    if (value < lbl_8047BA58) {
        alpha = (s32)value;
        if ((s16)alpha < -0xff) {
            alpha = -0xff;
        }
        value = 0.0f;
        sprite->alpha = (u8)(alpha + 0xff);
        next = ((Work803A654C*)lbl_803A654C)->field_10 +
               (velocity = ((Work803A654C*)lbl_803A654C)->field_8);
        ((Work803A654C*)lbl_803A654C)->field_10 = next;
        ((Work803A654C*)lbl_803A654C)->field_8 =
            lbl_8047A494 * ((Work803A654C*)lbl_803A654C)->field_4 + velocity;
        if (next > value) {
            ((Work803A654C*)lbl_803A654C)->field_10 = value;
            sprite->field_50 = (s16)((Work803A654C*)lbl_803A654C)->field_C;
        }
        sprite->field_50 = (s16)(((Work803A654C*)lbl_803A654C)->field_C +
                                  ((Work803A654C*)lbl_803A654C)->field_10);
    }
}
