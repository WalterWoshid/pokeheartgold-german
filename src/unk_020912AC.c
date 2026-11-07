#include "unk_020912AC.h"

#include "global.h"

#include "config.h"
#include "unk_02091278.h"

// Lookup table for dex flag cycling
#ifdef GERMAN
static const u8 sDexCycleTable[] = {
    3,
    1,
    2,
#else
static const u8 sDexCycleTable[] = {
    1,
    2,
    3,
#endif
    4,
    5,
    0
};

// Get dex cycle value at index
int sub_020912AC(int index) {
    GF_ASSERT(index < 6);

    if (index < 6) {
        return sDexCycleTable[index];
    }

    return LanguageToDexFlag(GAME_LANGUAGE);
}

// Get dex cycle value with offset wrapping
s16 sub_020912D0(s16 value, u32 offset) {
    u32 i;

    for (i = 0; i < 6; i++) {
        if (sDexCycleTable[i] == value) {
            i += offset + 6;
            i %= 6;
            return sDexCycleTable[i];
        }
    }

    return LanguageToDexFlag(GAME_LANGUAGE);
}
