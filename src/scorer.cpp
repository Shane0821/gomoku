#include "scorer.h"

const int Scorer::TYPE_SCORES[CNT_TYPES] = {50000000, 5000000, 50000, 5000, 500,
                                            500,      50,      50,    5,    0};

const int Scorer::BASE_SCORES[Board::BOARD_SIZE][Board::BOARD_SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},
    {0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 0},
    {0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1, 0},
    {0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 4, 3, 2, 1, 0},
    {0, 1, 2, 3, 4, 5, 6, 6, 6, 5, 4, 3, 2, 1, 0},
    {0, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0},
    {0, 1, 2, 3, 4, 5, 6, 6, 6, 5, 4, 3, 2, 1, 0},
    {0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 4, 3, 2, 1, 0},
    {0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1, 0},
    {0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 0},
    {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

Scorer::Scorer() {
    m_pTypeTable = new Type[CNT_STATES];
    for (int i = 0; i < CNT_STATES; i++) m_pTypeTable[i] = BASE;
    // refer to /scoretable
    m_pTypeTable[364] = FIVE;
    m_pTypeTable[1093] = FIVE;
    m_pTypeTable[1094] = FIVE;
    m_pTypeTable[1822] = FIVE;
    m_pTypeTable[3280] = FIVE;
    m_pTypeTable[3281] = FIVE;
    m_pTypeTable[3283] = FIVE;
    m_pTypeTable[3284] = FIVE;
    m_pTypeTable[4009] = FIVE;
    m_pTypeTable[5467] = FIVE;
    m_pTypeTable[5468] = FIVE;
    m_pTypeTable[6196] = FIVE;
    m_pTypeTable[9841] = FIVE;
    m_pTypeTable[9842] = FIVE;
    m_pTypeTable[9844] = FIVE;
    m_pTypeTable[9845] = FIVE;
    m_pTypeTable[9850] = FIVE;
    m_pTypeTable[9851] = FIVE;
    m_pTypeTable[10570] = FIVE;
    m_pTypeTable[12028] = FIVE;
    m_pTypeTable[12029] = FIVE;
    m_pTypeTable[16402] = FIVE;
    m_pTypeTable[16403] = FIVE;
    m_pTypeTable[16405] = FIVE;
    m_pTypeTable[16406] = FIVE;
    m_pTypeTable[17131] = FIVE;
    m_pTypeTable[18589] = FIVE;
    m_pTypeTable[18590] = FIVE;

    m_pTypeTable[121] = FIVE;
    m_pTypeTable[122] = SLEEP_FOUR;
    m_pTypeTable[124] = SLEEP_FOUR;
    m_pTypeTable[125] = SLEEP_THREE;
    m_pTypeTable[130] = SLEEP_FOUR;
    m_pTypeTable[131] = SLEEP_THREE;
    m_pTypeTable[148] = SLEEP_FOUR;
    m_pTypeTable[149] = SLEEP_THREE;
    m_pTypeTable[151] = SLEEP_THREE;
    m_pTypeTable[152] = SLEEP_TWO;
    m_pTypeTable[202] = SLEEP_FOUR;
    m_pTypeTable[203] = SLEEP_THREE;
    m_pTypeTable[205] = SLEEP_THREE;
    m_pTypeTable[206] = SLEEP_TWO;
    m_pTypeTable[211] = SLEEP_THREE;
    m_pTypeTable[212] = SLEEP_TWO;
    m_pTypeTable[229] = SLEEP_THREE;
    m_pTypeTable[230] = SLEEP_TWO;
    m_pTypeTable[232] = SLEEP_TWO;
    m_pTypeTable[233] = BASE;
    m_pTypeTable[365] = FIVE;
    m_pTypeTable[367] = SLEEP_FOUR;
    m_pTypeTable[368] = SLEEP_FOUR;
    m_pTypeTable[373] = SLEEP_FOUR;
    m_pTypeTable[374] = SLEEP_FOUR;
    m_pTypeTable[391] = SLEEP_FOUR;
    m_pTypeTable[392] = SLEEP_FOUR;
    m_pTypeTable[394] = SLEEP_THREE;
    m_pTypeTable[395] = SLEEP_THREE;
    m_pTypeTable[445] = SLEEP_FOUR;
    m_pTypeTable[446] = SLEEP_FOUR;
    m_pTypeTable[448] = SLEEP_THREE;
    m_pTypeTable[449] = SLEEP_THREE;
    m_pTypeTable[454] = SLEEP_THREE;
    m_pTypeTable[455] = SLEEP_THREE;
    m_pTypeTable[607] = FIVE;
    m_pTypeTable[608] = LIVE_FOUR;
    m_pTypeTable[610] = SLEEP_FOUR;
    m_pTypeTable[611] = LIVE_THREE;
    m_pTypeTable[616] = SLEEP_FOUR;
    m_pTypeTable[617] = LIVE_THREE;
    m_pTypeTable[634] = SLEEP_FOUR;
    m_pTypeTable[635] = LIVE_THREE;
    m_pTypeTable[637] = SLEEP_THREE;
    m_pTypeTable[638] = LIVE_TWO;
    m_pTypeTable[688] = SLEEP_FOUR;
    m_pTypeTable[689] = LIVE_THREE;
    m_pTypeTable[691] = SLEEP_THREE;
    m_pTypeTable[692] = LIVE_TWO;
    m_pTypeTable[697] = SLEEP_THREE;
    m_pTypeTable[698] = LIVE_TWO;
    m_pTypeTable[1096] = FIVE;
    m_pTypeTable[1097] = FIVE;
    m_pTypeTable[1102] = SLEEP_FOUR;
    m_pTypeTable[1103] = SLEEP_FOUR;
    m_pTypeTable[1120] = SLEEP_FOUR;
    m_pTypeTable[1121] = SLEEP_FOUR;
    m_pTypeTable[1123] = SLEEP_FOUR;
    m_pTypeTable[1124] = SLEEP_FOUR;
    m_pTypeTable[1174] = SLEEP_FOUR;
    m_pTypeTable[1175] = SLEEP_FOUR;
    m_pTypeTable[1177] = SLEEP_FOUR;
    m_pTypeTable[1178] = SLEEP_FOUR;
    m_pTypeTable[1183] = SLEEP_THREE;
    m_pTypeTable[1184] = SLEEP_THREE;
    m_pTypeTable[1336] = FIVE;
    m_pTypeTable[1337] = LIVE_FOUR;
    m_pTypeTable[1339] = LIVE_FOUR;
    m_pTypeTable[1340] = SLEEP_FOUR;
    m_pTypeTable[1345] = SLEEP_FOUR;
    m_pTypeTable[1346] = LIVE_THREE;
    m_pTypeTable[1363] = SLEEP_FOUR;
    m_pTypeTable[1364] = LIVE_THREE;
    m_pTypeTable[1366] = LIVE_THREE;
    m_pTypeTable[1367] = SLEEP_THREE;
    m_pTypeTable[1823] = FIVE;
    m_pTypeTable[1825] = LIVE_FOUR;
    m_pTypeTable[1826] = LIVE_FOUR;
    m_pTypeTable[1831] = SLEEP_FOUR;
    m_pTypeTable[1832] = SLEEP_FOUR;
    m_pTypeTable[1849] = SLEEP_FOUR;
    m_pTypeTable[1850] = SLEEP_FOUR;
    m_pTypeTable[1852] = LIVE_THREE;
    m_pTypeTable[1853] = LIVE_THREE;
    m_pTypeTable[1903] = SLEEP_FOUR;
    m_pTypeTable[1904] = SLEEP_FOUR;
    m_pTypeTable[1906] = LIVE_THREE;
    m_pTypeTable[1907] = LIVE_THREE;
    m_pTypeTable[1912] = SLEEP_THREE;
    m_pTypeTable[1913] = SLEEP_THREE;
    m_pTypeTable[2065] = FIVE;
    m_pTypeTable[2066] = LIVE_FOUR;
    m_pTypeTable[2068] = SLEEP_FOUR;
    m_pTypeTable[2069] = LIVE_THREE;
    m_pTypeTable[2074] = SLEEP_FOUR;
    m_pTypeTable[2075] = LIVE_THREE;
    m_pTypeTable[2092] = SLEEP_FOUR;
    m_pTypeTable[2093] = LIVE_THREE;
    m_pTypeTable[2095] = SLEEP_THREE;
    m_pTypeTable[2096] = LIVE_TWO;
    m_pTypeTable[3289] = FIVE;
    m_pTypeTable[3290] = FIVE;
    m_pTypeTable[3307] = SLEEP_FOUR;
    m_pTypeTable[3308] = SLEEP_FOUR;
    m_pTypeTable[3310] = SLEEP_FOUR;
    m_pTypeTable[3311] = SLEEP_FOUR;
    m_pTypeTable[3361] = SLEEP_FOUR;
    m_pTypeTable[3362] = SLEEP_FOUR;
    m_pTypeTable[3364] = SLEEP_FOUR;
    m_pTypeTable[3365] = SLEEP_FOUR;
    m_pTypeTable[3370] = SLEEP_FOUR;
    m_pTypeTable[3371] = SLEEP_FOUR;
    m_pTypeTable[3523] = FIVE;
    m_pTypeTable[3524] = LIVE_FOUR;
    m_pTypeTable[3526] = LIVE_FOUR;
    m_pTypeTable[3527] = SLEEP_FOUR;
    m_pTypeTable[3532] = LIVE_FOUR;
    m_pTypeTable[3533] = SLEEP_FOUR;
    m_pTypeTable[3550] = SLEEP_FOUR;
    m_pTypeTable[3551] = LIVE_THREE;
    m_pTypeTable[3553] = LIVE_THREE;
    m_pTypeTable[3554] = SLEEP_THREE;
    m_pTypeTable[4010] = FIVE;
    m_pTypeTable[4012] = LIVE_FOUR;
    m_pTypeTable[4013] = LIVE_FOUR;
    m_pTypeTable[4018] = LIVE_FOUR;
    m_pTypeTable[4019] = LIVE_FOUR;
    m_pTypeTable[4036] = SLEEP_FOUR;
    m_pTypeTable[4037] = SLEEP_FOUR;
    m_pTypeTable[4039] = LIVE_THREE;
    m_pTypeTable[4040] = LIVE_THREE;
    m_pTypeTable[4090] = SLEEP_FOUR;
    m_pTypeTable[4091] = SLEEP_FOUR;
    m_pTypeTable[4093] = LIVE_THREE;
    m_pTypeTable[4094] = LIVE_THREE;
    m_pTypeTable[4099] = LIVE_THREE;
    m_pTypeTable[4100] = LIVE_THREE;
    m_pTypeTable[5470] = FIVE;
    m_pTypeTable[5471] = FIVE;
    m_pTypeTable[5476] = LIVE_FOUR;
    m_pTypeTable[5477] = LIVE_FOUR;
    m_pTypeTable[5494] = SLEEP_FOUR;
    m_pTypeTable[5495] = SLEEP_FOUR;
    m_pTypeTable[5497] = SLEEP_FOUR;
    m_pTypeTable[5498] = SLEEP_FOUR;
    m_pTypeTable[5548] = SLEEP_FOUR;
    m_pTypeTable[5549] = SLEEP_FOUR;
    m_pTypeTable[5551] = SLEEP_FOUR;
    m_pTypeTable[5552] = SLEEP_FOUR;
    m_pTypeTable[5557] = LIVE_THREE;
    m_pTypeTable[5558] = LIVE_THREE;
    m_pTypeTable[5710] = FIVE;
    m_pTypeTable[5711] = LIVE_FOUR;
    m_pTypeTable[5713] = LIVE_FOUR;
    m_pTypeTable[5714] = SLEEP_FOUR;
    m_pTypeTable[5719] = SLEEP_FOUR;
    m_pTypeTable[5720] = LIVE_THREE;
    m_pTypeTable[5737] = SLEEP_FOUR;
    m_pTypeTable[5738] = LIVE_THREE;
    m_pTypeTable[5740] = LIVE_THREE;
    m_pTypeTable[5741] = SLEEP_THREE;
    m_pTypeTable[6197] = FIVE;
    m_pTypeTable[6199] = LIVE_FOUR;
    m_pTypeTable[6200] = LIVE_FOUR;
    m_pTypeTable[6205] = SLEEP_FOUR;
    m_pTypeTable[6206] = SLEEP_FOUR;
    m_pTypeTable[6227] = LIVE_THREE;
    m_pTypeTable[6277] = SLEEP_FOUR;
    m_pTypeTable[6278] = SLEEP_FOUR;
    m_pTypeTable[6280] = LIVE_THREE;
    m_pTypeTable[6281] = LIVE_THREE;
    m_pTypeTable[6286] = SLEEP_THREE;
    m_pTypeTable[6287] = SLEEP_THREE;
    m_pTypeTable[9868] = FIVE;
    m_pTypeTable[9869] = FIVE;
    m_pTypeTable[9871] = FIVE;
    m_pTypeTable[9872] = FIVE;
    m_pTypeTable[10084] = FIVE;
    m_pTypeTable[10085] = LIVE_FOUR;
    m_pTypeTable[10087] = LIVE_FOUR;
    m_pTypeTable[10088] = SLEEP_FOUR;
    m_pTypeTable[10093] = LIVE_FOUR;
    m_pTypeTable[10094] = SLEEP_FOUR;
    m_pTypeTable[10111] = SLEEP_FOUR;
    m_pTypeTable[10112] = SLEEP_FOUR;
    m_pTypeTable[10114] = SLEEP_FOUR;
    m_pTypeTable[10115] = SLEEP_FOUR;
    m_pTypeTable[10571] = FIVE;
    m_pTypeTable[10573] = LIVE_FOUR;
    m_pTypeTable[10574] = LIVE_FOUR;
    m_pTypeTable[10579] = LIVE_FOUR;
    m_pTypeTable[10580] = LIVE_FOUR;
    m_pTypeTable[10597] = LIVE_FOUR;
    m_pTypeTable[10598] = LIVE_FOUR;
    m_pTypeTable[10600] = SLEEP_FOUR;
    m_pTypeTable[10601] = SLEEP_FOUR;
    m_pTypeTable[12031] = FIVE;
    m_pTypeTable[12032] = FIVE;
    m_pTypeTable[12037] = LIVE_FOUR;
    m_pTypeTable[12038] = LIVE_FOUR;
    m_pTypeTable[12055] = LIVE_FOUR;
    m_pTypeTable[12056] = LIVE_FOUR;
    m_pTypeTable[12058] = LIVE_FOUR;
    m_pTypeTable[12059] = LIVE_FOUR;
    m_pTypeTable[12271] = FIVE;
    m_pTypeTable[12272] = LIVE_FOUR;
    m_pTypeTable[12274] = LIVE_FOUR;
    m_pTypeTable[12275] = SLEEP_FOUR;
    m_pTypeTable[12280] = SLEEP_FOUR;
    m_pTypeTable[12281] = LIVE_THREE;
    m_pTypeTable[12298] = SLEEP_FOUR;
    m_pTypeTable[12299] = LIVE_THREE;
    m_pTypeTable[12301] = LIVE_THREE;
    m_pTypeTable[12302] = LIVE_THREE;
    m_pTypeTable[16411] = FIVE;
    m_pTypeTable[16412] = FIVE;
    m_pTypeTable[16429] = LIVE_FOUR;
    m_pTypeTable[16430] = LIVE_FOUR;
    m_pTypeTable[16432] = LIVE_FOUR;
    m_pTypeTable[16433] = LIVE_FOUR;
    m_pTypeTable[16645] = FIVE;
    m_pTypeTable[16646] = LIVE_FOUR;
    m_pTypeTable[16648] = LIVE_FOUR;
    m_pTypeTable[16649] = SLEEP_FOUR;
    m_pTypeTable[16654] = LIVE_FOUR;
    m_pTypeTable[16655] = SLEEP_FOUR;
    m_pTypeTable[16672] = SLEEP_FOUR;
    m_pTypeTable[16673] = LIVE_THREE;
    m_pTypeTable[16675] = LIVE_THREE;
    m_pTypeTable[16676] = LIVE_THREE;
    m_pTypeTable[17132] = FIVE;
    m_pTypeTable[17134] = LIVE_FOUR;
    m_pTypeTable[17135] = LIVE_FOUR;
    m_pTypeTable[17140] = LIVE_FOUR;
    m_pTypeTable[17141] = LIVE_FOUR;
    m_pTypeTable[17158] = SLEEP_FOUR;
    m_pTypeTable[17159] = SLEEP_FOUR;
    m_pTypeTable[17161] = LIVE_THREE;
    m_pTypeTable[17162] = LIVE_THREE;
    m_pTypeTable[18592] = FIVE;
    m_pTypeTable[18593] = FIVE;
    m_pTypeTable[18598] = LIVE_FOUR;
    m_pTypeTable[18599] = LIVE_FOUR;
    m_pTypeTable[18616] = SLEEP_FOUR;
    m_pTypeTable[18617] = SLEEP_FOUR;
    m_pTypeTable[18619] = SLEEP_FOUR;
    m_pTypeTable[18620] = SLEEP_FOUR;
    m_pTypeTable[18832] = FIVE;
    m_pTypeTable[18833] = LIVE_FOUR;
    m_pTypeTable[18835] = LIVE_FOUR;
    m_pTypeTable[18836] = SLEEP_FOUR;
    m_pTypeTable[18841] = SLEEP_FOUR;
    m_pTypeTable[18842] = LIVE_THREE;
    m_pTypeTable[18859] = SLEEP_FOUR;
    m_pTypeTable[18860] = LIVE_THREE;
    m_pTypeTable[18862] = LIVE_THREE;
    m_pTypeTable[18863] = SLEEP_THREE;
}