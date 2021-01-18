/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "TrackData.h"

#include "Track.h"
#include "TrackPaint.h"

#include <iterator>

// clang-format off
const rct_track_coordinates FlatTrackCoordinates[TrackElemType::Count] = {
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,   16,    0,    0 },
    {    0,    0,    0,   64,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    0,   32,    0,    0 },
    {    0,    0,    0,   32,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,   16,    0,    0,    0 },
    {    0,    0,   64,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,   32,    0,    0,    0 },
    {    0,    0,   32,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    3,    0,    0,  -64,  -64 },
    {    0,    1,    0,    0,  -64,   64 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    3,    0,    0,  -64,  -64 },
    {    0,    1,    0,    0,  -64,   64 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    3,    0,   64,  -64,  -64 },
    {    0,    1,    0,   64,  -64,   64 },
    {    0,    3,   64,    0,  -64,  -64 },
    {    0,    1,   64,    0,  -64,   64 },
    {    0,    0,    0,    0,  -64,  -32 },
    {    0,    0,    0,    0,  -64,   32 },
    {    0,    0,    0,    0,  -32,  -32 },
    {    0,    0,    0,    0,  -32,   32 },
    {    0,    3,    0,    0,  -32,  -32 },
    {    0,    1,    0,    0,  -32,   32 },
    {    0,    3,    0,    0,  -32,  -32 },
    {    0,    1,    0,    0,  -32,   32 },
    {    0,    3,    0,   32,  -32,  -32 },
    {    0,    1,    0,   32,  -32,   32 },
    {    0,    3,   32,    0,  -32,  -32 },
    {    0,    1,   32,    0,  -32,   32 },
    {    0,    3,    0,    0,    0,    0 },
    {    0,    1,    0,    0,    0,    0 },
    {    0,    0,    0,   16,  -64,    0 },
    {    0,    0,    0,   16,  -64,    0 },
    {    0,    0,    0,  -16,  -64,    0 },
    {    0,    0,    0,  -16,  -64,    0 },
    {    0,    2,    0,  152,  -32,    0 },
    {    0,    2,    0, -152,   32,    0 },
    {    0,    3,    0,   80,  -32,  -32 },
    {    0,    1,    0,   80,  -32,   32 },
    {    0,    3,    0,  -80,  -32,  -32 },
    {    0,    1,    0,  -80,  -32,   32 },
    {    0,    0,    0,   24,    0,    0 },
    {    0,    0,    0,   24,    0,    0 },
    {    0,    0,   24,    0,    0,    0 },
    {    0,    0,   24,    0,    0,    0 },
    {    0,    0,    0,   96,   32,    0 },
    {    0,    0,    0,   32,   32,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,   16,    0,    0 },
    {    0,    0,    0,   64,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    0,   32,    0,    0 },
    {    0,    0,    0,   32,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,   16,    0,    0,    0 },
    {    0,    0,   64,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,   32,    0,    0,    0 },
    {    0,    0,   32,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    3,    0,    0,  -64,  -64 },
    {    0,    1,    0,    0,  -64,   64 },
    {    0,    0,    0,    0,  -64,  -32 },
    {    0,    0,    0,    0,  -64,   32 },
    {    0,    3,    0,    0,  -32,  -32 },
    {    0,    1,    0,    0,  -32,   32 },
    {    0,    2,    0,   16,    0,  -96 },
    {    0,    2,    0,   16,    0,   96 },
    {    0,    2,   16,    0,    0,  -96 },
    {    0,    2,   16,    0,    0,   96 },
    {    0,    2,    0,   16,    0, -160 },
    {    0,    2,    0,   16,    0,  160 },
    {    0,    2,   16,    0,    0, -160 },
    {    0,    2,   16,    0,    0,  160 },
    {    0,    2,    0,    0,    0,   32 }, // FLAT_TRACK_ELEM_1_X_4_A
    {    0,    1,    0,   64,    0,    0 },
    {    0,    3,   64,    0,    0,    0 },
    {    0,    1,   64,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    3,    0,   16,  -64,  -64 },
    {    0,    1,    0,   16,  -64,   64 },
    {    0,    3,   16,    0,  -64,  -64 },
    {    0,    1,   16,    0,  -64,   64 },
    {    0,    3,    0,   16,  -64,  -64 },
    {    0,    1,    0,   16,  -64,   64 },
    {    0,    3,   16,    0,  -64,  -64 },
    {    0,    1,   16,    0,  -64,   64 },
    {    0,    2,    0,    0,    0,   32 }, // FLAT_TRACK_ELEM_2_X_2
    {    0,    2,    0,    0,    0,   32 }, // FLAT_TRACK_ELEM_4_X_4
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    2,    0,    0,    0,   32 }, // ???
    {    0,    2,    0,    0,    0,   32 }, // FLAT_TRACK_ELEM_1_X_5
    {    0,    0,   16,   16, -128,    0 },
    {    0,    2,    0,    0,    0,   32 }, // FLAT_TRACK_ELEM_1_X_1_A
    {    0,    2,    0,    0,    0,   32 }, // FLAT_TRACK_ELEM_1_X_4_B
    {    0,    0,    0,    0,    0,    0 },
    {    0,    2,    0,    0,    0,   32 }, // FLAT_TRACK_ELEM_1_X_1_B
    {    0,    2,    0,    0,    0,   32 }, // FLAT_TRACK_ELEM_1_X_4_C
    {    0,    0,    0,   96,   32,    0 }, // FLAT_TRACK_ELEM_3_X_3
    {    0,    0,    0,  240, -160,    0 },
    {    0,    0,    0,   80,   32,    0 },
    {    0,    0,    0,   32,   32,    0 },
    {    0,    0,   32,    0,   32,    0 },
    {    0,    0,    0,   56,   32,    0 },
    {    0,    0,   56,    0,    0,    0 },
    {    0,    0,    0,   56,    0,    0 },
    {    0,    0,   56,    0,   32,    0 },
    {    0,    0,   24,    0,    0,    0 },
    {    0,    7,    0,    0,  -64,  -32 },
    {    0,    4,    0,    0,  -64,   32 },
    {    4,    0,    0,    0,  -64,   32 },
    {    4,    1,    0,    0,  -32,   64 },
    {    0,    7,    0,    0,  -64,  -32 },
    {    0,    4,    0,    0,  -64,   32 },
    {    4,    0,    0,    0,  -64,   32 },
    {    4,    1,    0,    0,  -32,   64 },
    {    4,    4,    0,    0,  -32,   32 },
    {    4,    4,    0,   16,  -32,   32 },
    {    4,    4,    0,   64,  -32,   32 },
    {    4,    4,    0,    8,  -32,   32 },
    {    4,    4,    0,   32,  -32,   32 },
    {    4,    4,    0,   32,  -32,   32 },
    {    4,    4,    0,    8,  -32,   32 },
    {    4,    4,   16,    0,  -32,   32 },
    {    4,    4,   64,    0,  -32,   32 },
    {    4,    4,    8,    0,  -32,   32 },
    {    4,    4,   32,    0,  -32,   32 },
    {    4,    4,   32,    0,  -32,   32 },
    {    4,    4,    8,    0,  -32,   32 },
    {    4,    4,    0,   24,  -32,   32 },
    {    4,    4,    0,   24,  -32,   32 },
    {    4,    4,   24,    0,  -32,   32 },
    {    4,    4,   24,    0,  -32,   32 },
    {    4,    4,    0,    0,  -32,   32 },
    {    4,    4,    0,    0,  -32,   32 },
    {    4,    4,    0,    0,  -32,   32 },
    {    4,    4,    0,    0,  -32,   32 },
    {    4,    4,    0,    8,  -32,   32 },
    {    4,    4,    0,    8,  -32,   32 },
    {    4,    4,    0,    8,  -32,   32 },
    {    4,    4,    0,    8,  -32,   32 },
    {    4,    4,    8,    0,  -32,   32 },
    {    4,    4,    8,    0,  -32,   32 },
    {    4,    4,    8,    0,  -32,   32 },
    {    4,    4,    8,    0,  -32,   32 },
    {    4,    4,    0,    0,  -32,   32 },
    {    4,    4,    0,    0,  -32,   32 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    0,    0,   32,  -64,    0 },
    {    0,    0,    0,   32,  -64,    0 },
    {    0,    0,    0,  -32,  -64,    0 },
    {    0,    0,    0,  -32,  -64,    0 },
    {    0,    3,    0,   24,  -32,  -32 },
    {    0,    1,    0,   24,  -32,   32 },
    {    0,    3,   24,    0,  -32,  -32 },
    {    0,    1,   24,    0,  -32,   32 },
    {    0,    0,    0,   16,    0,    0 },
    {    0,    2,    0,  280,  -64,  -32 },
    {    0,    2,    0,  280,  -64,   32 },
    {    0,    2,    0, -280,   64,  -32 },
    {    0,    2,    0, -280,   64,   32 },
    {    0,    0,    0,  -16,  -64,    0 },
    {    0,    0,    0,  -16,  -64,    0 },
    {    0,    0,    0,   16,  -64,    0 },
    {    0,    0,    0,   16,  -64,    0 },
    {    0,    2,    0,  120,  -32,    0 },
    {    0,    2,    0, -120,   32,    0 },
    {    0,    3,    0,   48,  -32,  -32 },
    {    0,    1,    0,   48,  -32,   32 },
    {    0,    3,    0,  -48,  -32,  -32 },
    {    0,    1,    0,  -48,  -32,   32 },
    {    0,    2,    0,   32,    0,    0 },
    {    0,    2,    0,  -32,    0,    0 },
    {    0,    0,    0,    0, -160,    0 },
    {    0,    0,    0,    0, -160,    0 },
    {    0,    0,    0,    0,  -32,    0 },
    {    0,    0,    0,    0,  -32,    0 },
    {    0,    0,    0,    0,  -32,    0 },
    {    0,    1,    0,    0,  -32,   32 },
    {    0,    3,    0,    0,  -32,  -32 },
    {    0,    0,    0,    0,  -32,    0 }, // ???
    {    0,    0,    0,    0,  -32,    0 }, // ???
    {    0,    0,    0,    0,  -32,    0 }, // ???
    {    0,    3,    0,   16,  -32,  -32 },
    {    0,    1,    0,   16,  -32,   32 },
    {    0,    0,    0,    0,  -64,    0 },
    {    0,    0,    0,    0,  -64,    0 },
    {    0,    0,    0,    0,  -32,    0 },
    {    0,    0,   80,    0,   32,    0 },
    {    0,    0,  240,    0, -160,    0 },
    {    0,    0,    0,    0,    0,    0 },
    {    0,    3,    0,   32,  -32,  -32 },
    {    0,    1,    0,   32,  -32,   32 },
    {    0,    3,   32,    0,  -32,  -32 },
    {    0,    1,   32,    0,  -32,   32 },
    {    0,    3,    0,   64,  -64,  -64 },
    {    0,    1,    0,   64,  -64,   64 },
    {    0,    3,   64,    0,  -64,  -64 },
    {    0,    1,   64,    0,  -64,   64 },
    {    0,    0,    0,   16,    0,    0 },
    {    0,    0,    0,   16,    0,    0 },
    {    0,    0,    0,   16,    0,    0 },
    {    0,    0,    0,   16,    0,    0 },
    {    0,    0,   16,    0,    0,    0 },
    {    0,    0,   16,    0,    0,    0 },
    {    0,    0,   16,    0,    0,    0 },
    {    0,    0,   16,    0,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    0,    8,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    0,    8,    0,    0,    0 },
    {    0,    3,    0,   96,    0,   32 },
    {    0,    1,    0,   96,    0,  -32 },
    {    0,    3,   96,    0,    0,   32 },
    {    0,    1,   96,    0,    0,  -32 },
    {    0,    0,    0,    0,    0,    0 },
};

const rct_track_coordinates TrackCoordinates[TrackElemType::Count] = {
        { 0, 0, 0, 0, 0, 0 },       // Flat
        { 0, 0, 0, 0, 0, 0 },       // EndStation
        { 0, 0, 0, 0, 0, 0 },       // BeginStation
        { 0, 0, 0, 0, 0, 0 },       // MiddleStation
        { 0, 0, 0, 16, 0, 0 },      // Up25
        { 0, 0, 0, 64, 0, 0 },      // Up60
        { 0, 0, 0, 8, 0, 0 },       // FlatToUp25
        { 0, 0, 0, 32, 0, 0 },      // Up25ToUp60
        { 0, 0, 0, 32, 0, 0 },      // Up60ToUp25
        { 0, 0, 0, 8, 0, 0 },       // Up25ToFlat
        { 0, 0, 16, 0, 0, 0 },      // Down25
        { 0, 0, 64, 0, 0, 0 },      // Down60
        { 0, 0, 8, 0, 0, 0 },       // FlatToDown25
        { 0, 0, 32, 0, 0, 0 },      // Down25ToDown60
        { 0, 0, 32, 0, 0, 0 },      // Down60ToDown25
        { 0, 0, 8, 0, 0, 0 },       // Down25ToFlat
        { 0, 3, 0, 0, -64, -64 },   // LeftQuarterTurn5Tiles
        { 0, 1, 0, 0, -64, 64 },    // RightQuarterTurn5Tiles
        { 0, 0, 0, 0, 0, 0 },       // FlatToLeftBank
        { 0, 0, 0, 0, 0, 0 },       // FlatToRightBank
        { 0, 0, 0, 0, 0, 0 },       // LeftBankToFlat
        { 0, 0, 0, 0, 0, 0 },       // RightBankToFlat
        { 0, 3, 0, 0, -64, -64 },   // BankedLeftQuarterTurn5Tiles
        { 0, 1, 0, 0, -64, 64 },    // BankedRightQuarterTurn5Tiles
        { 0, 0, 0, 8, 0, 0 },       // LeftBankToUp25
        { 0, 0, 0, 8, 0, 0 },       // RightBankToUp25
        { 0, 0, 0, 8, 0, 0 },       // Up25ToLeftBank
        { 0, 0, 0, 8, 0, 0 },       // Up25ToRightBank
        { 0, 0, 8, 0, 0, 0 },       // LeftBankToDown25
        { 0, 0, 8, 0, 0, 0 },       // RightBankToDown25
        { 0, 0, 8, 0, 0, 0 },       // Down25ToLeftBank
        { 0, 0, 8, 0, 0, 0 },       // Down25ToRightBank
        { 0, 0, 0, 0, 0, 0 },       // LeftBank
        { 0, 0, 0, 0, 0, 0 },       // RightBank
        { 0, 3, 0, 64, -64, -64 },  // LeftQuarterTurn5TilesUp25
        { 0, 1, 0, 64, -64, 64 },   // RightQuarterTurn5TilesUp25
        { 0, 3, 64, 0, -64, -64 },  // LeftQuarterTurn5TilesDown25
        { 0, 1, 64, 0, -64, 64 },   // RightQuarterTurn5TilesDown25
        { 0, 0, 0, 0, -64, -32 },   // SBendLeft
        { 0, 0, 0, 0, -64, 32 },    // SBendRight
        { 0, 0, 0, 0, -32, -32 },   // LeftVerticalLoop
        { 0, 0, 0, 0, -32, 32 },    // RightVerticalLoop
        { 0, 3, 0, 0, -32, -32 },   // LeftQuarterTurn3Tiles
        { 0, 1, 0, 0, -32, 32 },    // RightQuarterTurn3Tiles
        { 0, 3, 0, 0, -32, -32 },   // LeftBankedQuarterTurn3Tiles
        { 0, 1, 0, 0, -32, 32 },    // RightBankedQuarterTurn3Tiles
        { 0, 3, 0, 32, -32, -32 },  // LeftQuarterTurn3TilesUp25
        { 0, 1, 0, 32, -32, 32 },   // RightQuarterTurn3TilesUp25
        { 0, 3, 32, 0, -32, -32 },  // LeftQuarterTurn3TilesDown25
        { 0, 1, 32, 0, -32, 32 },   // RightQuarterTurn3TilesDown25
        { 0, 3, 0, 0, 0, 0 },       // LeftQuarterTurn1Tile
        { 0, 1, 0, 0, 0, 0 },       // RightQuarterTurn1Tile
        { 0, 0, 0, 16, -64, 0 },    // LeftTwistDownToUp
        { 0, 0, 0, 16, -64, 0 },    // RightTwistDownToUp
        { 0, 0, 0, -16, -64, 0 },   // LeftTwistUpToDown
        { 0, 0, 0, -16, -64, 0 },   // RightTwistUpToDown
        { 0, 2, 0, 152, -32, 0 },   // HalfLoopUp
        { 0, 2, 0, -152, 32, 0 },   // HalfLoopDown
        { 0, 3, 0, 80, -32, -32 },  // LeftCorkscrewUp
        { 0, 1, 0, 80, -32, 32 },   // RightCorkscrewUp
        { 0, 3, 0, -80, -32, -32 }, // LeftCorkscrewDown
        { 0, 1, 0, -80, -32, 32 },  // RightCorkscrewDown
        { 0, 0, 0, 24, 0, 0 },      // FlatToUp60
        { 0, 0, 0, 24, 0, 0 },      // Up60ToFlat
        { 0, 0, 24, 0, 0, 0 },      // FlatToDown60
        { 0, 0, 24, 0, 0, 0 },      // Down60ToFlat
        { 0, 0, 0, 96, 32, 0 },     // TowerBase
        { 0, 0, 0, 32, 32, 0 },     // TowerSection
        { 0, 0, 0, 0, 0, 0 },       // FlatCovered
        { 0, 0, 0, 16, 0, 0 },      // Up25Covered
        { 0, 0, 0, 64, 0, 0 },      // Up60Covered
        { 0, 0, 0, 8, 0, 0 },       // FlatToUp25Covered
        { 0, 0, 0, 32, 0, 0 },      // Up25ToUp60Covered
        { 0, 0, 0, 32, 0, 0 },      // Up60ToUp25Covered
        { 0, 0, 0, 8, 0, 0 },       // Up25ToFlatCovered
        { 0, 0, 16, 0, 0, 0 },      // Down25Covered
        { 0, 0, 64, 0, 0, 0 },      // Down60Covered
        { 0, 0, 8, 0, 0, 0 },       // FlatToDown25Covered
        { 0, 0, 32, 0, 0, 0 },      // Down25ToDown60Covered
        { 0, 0, 32, 0, 0, 0 },      // Down60ToDown25Covered
        { 0, 0, 8, 0, 0, 0 },       // Down25ToFlatCovered
        { 0, 3, 0, 0, -64, -64 },   // LeftQuarterTurn5TilesCovered
        { 0, 1, 0, 0, -64, 64 },    // RightQuarterTurn5TilesCovered
        { 0, 0, 0, 0, -64, -32 },   // SBendLeftCovered
        { 0, 0, 0, 0, -64, 32 },    // SBendRightCovered
        { 0, 3, 0, 0, -32, -32 },   // LeftQuarterTurn3TilesCovered
        { 0, 1, 0, 0, -32, 32 },    // RightQuarterTurn3TilesCovered
        { 0, 2, 0, 16, 0, -96 },    // LeftHalfBankedHelixUpSmall
        { 0, 2, 0, 16, 0, 96 },     // RightHalfBankedHelixUpSmall
        { 0, 2, 16, 0, 0, -96 },    // LeftHalfBankedHelixDownSmall
        { 0, 2, 16, 0, 0, 96 },     // RightHalfBankedHelixDownSmall
        { 0, 2, 0, 16, 0, -160 },   // LeftHalfBankedHelixUpLarge
        { 0, 2, 0, 16, 0, 160 },    // RightHalfBankedHelixUpLarge
        { 0, 2, 16, 0, 0, -160 },   // LeftHalfBankedHelixDownLarge
        { 0, 2, 16, 0, 0, 160 },    // RightHalfBankedHelixDownLarge
        { 0, 3, 0, 64, 0, 0 },      // LeftQuarterTurn1TileUp60
        { 0, 1, 0, 64, 0, 0 },      // RightQuarterTurn1TileUp60
        { 0, 3, 64, 0, 0, 0 },      // LeftQuarterTurn1TileDown60
        { 0, 1, 64, 0, 0, 0 },      // RightQuarterTurn1TileDown60
        { 0, 0, 0, 0, 0, 0 },       // Brakes
        { 0, 0, 0, 0, 0, 0 },       // RotationControlToggle
        { 0, 0, 0, 0, 0, 0 },       // InvertedUp90ToFlatQuarterLoopAlias
        { 0, 3, 0, 16, -64, -64 },  // LeftQuarterBankedHelixLargeUp
        { 0, 1, 0, 16, -64, 64 },   // RightQuarterBankedHelixLargeUp
        { 0, 3, 16, 0, -64, -64 },  // LeftQuarterBankedHelixLargeDown
        { 0, 1, 16, 0, -64, 64 },   // RightQuarterBankedHelixLargeDown
        { 0, 3, 0, 16, -64, -64 },  // LeftQuarterHelixLargeUp
        { 0, 1, 0, 16, -64, 64 },   // RightQuarterHelixLargeUp
        { 0, 3, 16, 0, -64, -64 },  // LeftQuarterHelixLargeDown
        { 0, 1, 16, 0, -64, 64 },   // RightQuarterHelixLargeDown
        { 0, 0, 0, 16, 0, 0 },      // Up25LeftBanked
        { 0, 0, 0, 16, 0, 0 },      // Up25RightBanked
        { 0, 0, 0, 0, 0, 0 },       // Waterfall
        { 0, 0, 0, 0, 0, 0 },       // Rapids
        { 0, 0, 0, 0, 0, 0 },       // OnRidePhoto
        { 0, 0, 16, 0, 0, 0 },      // Down25LeftBanked
        { 0, 0, 16, 0, 0, 0 },      // Down25RightBanked
        { 0, 0, 16, 16, -128, 0 },  // Watersplash
        { 0, 0, 0, 88, -96, 0 },    // FlatToUp60LongBase
        { 0, 0, 0, 88, -96, 0 },    // Up60ToFlatLongBase
        { 0, 0, 0, 0, 0, 0 },       // Whirlpool
        { 0, 0, 88, 0, -96, 0 },    // Down60ToFlatLongBase
        { 0, 0, 88, 0, -96, 0 },    // FlatToDown60LongBase
        { 0, 0, 0, -96, -96, 0 },   // CableLiftHill
        { 0, 0, 0, 240, -160, 0 },  // ReverseFreefallSlope
        { 0, 0, 0, 80, 32, 0 },     // ReverseFreefallVertical
        { 0, 0, 0, 32, 32, 0 },     // Up90
        { 0, 0, 32, 0, 32, 0 },     // Down90
        { 0, 0, 0, 56, 32, 0 },     // Up60ToUp90
        { 0, 0, 56, 0, 0, 0 },      // Down90ToDown60
        { 0, 0, 0, 56, 0, 0 },      // Up90ToUp60
        { 0, 0, 56, 0, 32, 0 },     // Down60ToDown90
        { 0, 0, 24, 0, 0, 0 },      // BrakeForDrop
        { 0, 7, 0, 0, -64, -32 },   // LeftEighthToDiag
        { 0, 4, 0, 0, -64, 32 },    // RightEighthToDiag
        { 4, 0, 0, 0, -64, 32 },    // LeftEighthToOrthogonal
        { 4, 1, 0, 0, -32, 64 },    // RightEighthToOrthogonal
        { 0, 7, 0, 0, -64, -32 },   // LeftEighthBankToDiag
        { 0, 4, 0, 0, -64, 32 },    // RightEighthBankToDiag
        { 4, 0, 0, 0, -64, 32 },    // LeftEighthBankToOrthogonal
        { 4, 1, 0, 0, -32, 64 },    // RightEighthBankToOrthogonal
        { 4, 4, 0, 0, -32, 32 },    // DiagFlat
        { 4, 4, 0, 16, -32, 32 },   // DiagUp25
        { 4, 4, 0, 64, -32, 32 },   // DiagUp60
        { 4, 4, 0, 8, -32, 32 },    // DiagFlatToUp25
        { 4, 4, 0, 32, -32, 32 },   // DiagUp25ToUp60
        { 4, 4, 0, 32, -32, 32 },   // DiagUp60ToUp25
        { 4, 4, 0, 8, -32, 32 },    // DiagUp25ToFlat
        { 4, 4, 16, 0, -32, 32 },   // DiagDown25
        { 4, 4, 64, 0, -32, 32 },   // DiagDown60
        { 4, 4, 8, 0, -32, 32 },    // DiagFlatToDown25
        { 4, 4, 32, 0, -32, 32 },   // DiagDown25ToDown60
        { 4, 4, 32, 0, -32, 32 },   // DiagDown60ToDown25
        { 4, 4, 8, 0, -32, 32 },    // DiagDown25ToFlat
        { 4, 4, 0, 24, -32, 32 },   // DiagFlatToUp60
        { 4, 4, 0, 24, -32, 32 },   // DiagUp60ToFlat
        { 4, 4, 24, 0, -32, 32 },   // DiagFlatToDown60
        { 4, 4, 24, 0, -32, 32 },   // DiagDown60ToFlat
        { 4, 4, 0, 0, -32, 32 },    // DiagFlatToLeftBank
        { 4, 4, 0, 0, -32, 32 },    // DiagFlatToRightBank
        { 4, 4, 0, 0, -32, 32 },    // DiagLeftBankToFlat
        { 4, 4, 0, 0, -32, 32 },    // DiagRightBankToFlat
        { 4, 4, 0, 8, -32, 32 },    // DiagLeftBankToUp25
        { 4, 4, 0, 8, -32, 32 },    // DiagRightBankToUp25
        { 4, 4, 0, 8, -32, 32 },    // DiagUp25ToLeftBank
        { 4, 4, 0, 8, -32, 32 },    // DiagUp25ToRightBank
        { 4, 4, 8, 0, -32, 32 },    // DiagLeftBankToDown25
        { 4, 4, 8, 0, -32, 32 },    // DiagRightBankToDown25
        { 4, 4, 8, 0, -32, 32 },    // DiagDown25ToLeftBank
        { 4, 4, 8, 0, -32, 32 },    // DiagDown25ToRightBank
        { 4, 4, 0, 0, -32, 32 },    // DiagLeftBank
        { 4, 4, 0, 0, -32, 32 },    // DiagRightBank
        { 0, 0, 0, 0, 0, 0 },       // LogFlumeReverser
        { 0, 0, 0, 0, 0, 0 },       // SpinningTunnel
        { 0, 0, 0, 32, -64, 0 },    // LeftBarrelRollUpToDown
        { 0, 0, 0, 32, -64, 0 },    // RightBarrelRollUpToDown
        { 0, 0, 0, -32, -64, 0 },   // LeftBarrelRollDownToUp
        { 0, 0, 0, -32, -64, 0 },   // RightBarrelRollDownToUp
        { 0, 3, 0, 24, -32, -32 },  // LeftBankToLeftQuarterTurn3TilesUp25
        { 0, 1, 0, 24, -32, 32 },   // RightBankToRightQuarterTurn3TilesUp25
        { 0, 3, 24, 0, -32, -32 },  // LeftQuarterTurn3TilesDown25ToLeftBank
        { 0, 1, 24, 0, -32, 32 },   // RightQuarterTurn3TilesDown25ToRightBank
        { 0, 0, 0, 16, 0, 0 },      // PoweredLift
        { 0, 2, 0, 280, -64, -32 }, // LeftLargeHalfLoopUp
        { 0, 2, 0, 280, -64, 32 },  // RightLargeHalfLoopUp
        { 0, 2, 0, -280, 64, -32 }, // RightLargeHalfLoopDown
        { 0, 2, 0, -280, 64, 32 },  // LeftLargeHalfLoopDown
        { 0, 0, 0, -16, -64, 0 },   // LeftFlyerTwistUp
        { 0, 0, 0, -16, -64, 0 },   // RightFlyerTwistUp
        { 0, 0, 0, 16, -64, 0 },    // LeftFlyerTwistDown
        { 0, 0, 0, 16, -64, 0 },    // RightFlyerTwistDown
        { 0, 2, 0, 120, -32, 0 },   // FlyerHalfLoopUp
        { 0, 2, 0, -120, 32, 0 },   // FlyerHalfLoopDown
        { 0, 3, 0, 48, -32, -32 },  // LeftFlyerCorkscrewUp
        { 0, 1, 0, 48, -32, 32 },   // RightFlyerCorkscrewUp
        { 0, 3, 0, -48, -32, -32 }, // LeftFlyerCorkscrewDown
        { 0, 1, 0, -48, -32, 32 },  // RightFlyerCorkscrewDown
        { 0, 2, 0, 32, 0, 0 },      // HeartLineTransferUp
        { 0, 2, 0, -32, 0, 0 },     // HeartLineTransferDown
        { 0, 0, 0, 0, -160, 0 },    // LeftHeartLineRoll
        { 0, 0, 0, 0, -160, 0 },    // RightHeartLineRoll
        { 0, 0, 0, 0, -32, 0 },     // MinigolfHoleA
        { 0, 0, 0, 0, -32, 0 },     // MinigolfHoleB
        { 0, 0, 0, 0, -32, 0 },     // MinigolfHoleC
        { 0, 1, 0, 0, -32, 32 },    // MinigolfHoleD
        { 0, 3, 0, 0, -32, -32 },   // MinigolfHoleE
        { 0, 2, 0, -96, -96, 0 },   // MultiDimInvertedFlatToDown90QuarterLoop
        { 0, 2, 0, 128, 64, 0 },    // Up90ToInvertedFlatQuarterLoop
        { 0, 2, 0, -128, -96, 0 },  // InvertedFlatToDown90QuarterLoop
        { 0, 3, 0, 16, -32, -32 },  // LeftCurvedLiftHill
        { 0, 1, 0, 16, -32, 32 },   // RightCurvedLiftHill
        { 0, 0, 0, 0, -64, 0 },     // LeftReverser
        { 0, 0, 0, 0, -64, 0 },     // RightReverser
        { 0, 0, 0, 0, -32, 0 },     // AirThrustTopCap
        { 0, 0, 80, 0, 32, 0 },     // AirThrustVerticalDown
        { 0, 0, 240, 0, -160, 0 },  // AirThrustVerticalDownToLevel
        { 0, 0, 0, 0, 0, 0 },       // BlockBrakes
        { 0, 3, 0, 32, -32, -32 },  // LeftBankedQuarterTurn3TileUp25
        { 0, 1, 0, 32, -32, 32 },   // RightBankedQuarterTurn3TileUp25
        { 0, 3, 32, 0, -32, -32 },  // LeftBankedQuarterTurn3TileDown25
        { 0, 1, 32, 0, -32, 32 },   // RightBankedQuarterTurn3TileDown25
        { 0, 3, 0, 64, -64, -64 },  // LeftBankedQuarterTurn5TileUp25
        { 0, 1, 0, 64, -64, 64 },   // RightBankedQuarterTurn5TileUp25
        { 0, 3, 64, 0, -64, -64 },  // LeftBankedQuarterTurn5TileDown25
        { 0, 1, 64, 0, -64, 64 },   // RightBankedQuarterTurn5TileDown25
        { 0, 0, 0, 16, 0, 0 },      // Up25ToLeftBankedUp25
        { 0, 0, 0, 16, 0, 0 },      // Up25ToRightBankedUp25
        { 0, 0, 0, 16, 0, 0 },      // LeftBankedUp25ToUp25
        { 0, 0, 0, 16, 0, 0 },      // RightBankedUp25ToUp25
        { 0, 0, 16, 0, 0, 0 },      // Down25ToLeftBankedDown25
        { 0, 0, 16, 0, 0, 0 },      // Down25ToRightBankedDown25
        { 0, 0, 16, 0, 0, 0 },      // LeftBankedDown25ToDown25
        { 0, 0, 16, 0, 0, 0 },      // RightBankedDown25ToDown25
        { 0, 0, 0, 8, 0, 0 },       // LeftBankedFlatToLeftBankedUp25
        { 0, 0, 0, 8, 0, 0 },       // RightBankedFlatToRightBankedUp25
        { 0, 0, 0, 8, 0, 0 },       // LeftBankedUp25ToLeftBankedFlat
        { 0, 0, 0, 8, 0, 0 },       // RightBankedUp25ToRightBankedFlat
        { 0, 0, 8, 0, 0, 0 },       // LeftBankedFlatToLeftBankedDown25
        { 0, 0, 8, 0, 0, 0 },       // RightBankedFlatToRightBankedDown25
        { 0, 0, 8, 0, 0, 0 },       // LeftBankedDown25ToLeftBankedFlat
        { 0, 0, 8, 0, 0, 0 },       // RightBankedDown25ToRightBankedFlat
        { 0, 0, 0, 8, 0, 0 },       // FlatToLeftBankedUp25
        { 0, 0, 0, 8, 0, 0 },       // FlatToRightBankedUp25
        { 0, 0, 0, 8, 0, 0 },       // LeftBankedUp25ToFlat
        { 0, 0, 0, 8, 0, 0 },       // RightBankedUp25ToFlat
        { 0, 0, 8, 0, 0, 0 },       // FlatToLeftBankedDown25
        { 0, 0, 8, 0, 0, 0 },       // FlatToRightBankedDown25
        { 0, 0, 8, 0, 0, 0 },       // LeftBankedDown25ToFlat
        { 0, 0, 8, 0, 0, 0 },       // RightBankedDown25ToFlat
        { 0, 3, 0, 96, 0, 32 },     // LeftQuarterTurn1TileUp90
        { 0, 1, 0, 96, 0, -32 },    // RightQuarterTurn1TileUp90
        { 0, 3, 96, 0, 0, 32 },     // LeftQuarterTurn1TileDown90
        { 0, 1, 96, 0, 0, -32 },    // RightQuarterTurn1TileDown90
        { 0, 2, 0, 96, 64, 0 },     // MultiDimUp90ToInvertedFlatQuarterLoop
        { 0, 2, 0, -128, -96, 0 },  // MultiDimFlatToDown90QuarterLoop
        { 0, 2, 0, 128, 64, 0 }     // MultiDimInvertedUp90ToFlatQuarterLoop
};

/** rct2: 0x0099BA64 */
const uint8_t TrackSequenceProperties[][MaxSequencesPerPiece] = {
    { 0 },
    /* TrackElemType::EndStation */    { TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN | TRACK_SEQUENCE_FLAG_DISALLOW_DOORS, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    /* TrackElemType::BeginStation */  { TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN | TRACK_SEQUENCE_FLAG_DISALLOW_DOORS, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    /* TrackElemType::MiddleStation */ { TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN | TRACK_SEQUENCE_FLAG_DISALLOW_DOORS, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    /* TrackElemType::TowerBase */ { TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_0, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1, TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_1, TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2, TRACK_SEQUENCE_FLAG_DIRECTION_2, 0, 0, 0, 0, 0, 0, 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    /* TrackElemType::Maze */   { TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    /* TrackElemType::SpinningTunnel */    { TRACK_SEQUENCE_FLAG_DISALLOW_DOORS, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
};

/** rct2: 0x0099CA64 */
const uint8_t FlatRideTrackSequenceProperties[][MaxSequencesPerPiece] = {
    { 0 },
    /* 1 */ { TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    /* 2 */ { TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    /* 3 */ { TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    /* 66 */    { TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_0, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1, TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_1, TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2, TRACK_SEQUENCE_FLAG_DIRECTION_2, 0, 0, 0, 0, 0, 0, 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    /* FLAT_TRACK_ELEM_1_X_4_A */   { TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, 0, TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    /* Maze */   { TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    /* FLAT_TRACK_ELEM_2_X_2 */ { TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1, TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    /* FLAT_TRACK_ELEM_4_X_4 */ { TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0, TRACK_SEQUENCE_FLAG_DIRECTION_0, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1, TRACK_SEQUENCE_FLAG_DIRECTION_3, 0, 0, TRACK_SEQUENCE_FLAG_DIRECTION_1, TRACK_SEQUENCE_FLAG_DIRECTION_3, 0, 0, TRACK_SEQUENCE_FLAG_DIRECTION_1, TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_2, TRACK_SEQUENCE_FLAG_DIRECTION_2, TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 },
    { 0 },
    { 0 },
    { 0 },
    /* 115 */   { TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0, TRACK_SEQUENCE_FLAG_DIRECTION_0, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1, TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_2, TRACK_SEQUENCE_FLAG_DIRECTION_2, TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2, 0, 0, 0, 0, 0, 0, 0, 0 },
    /* FLAT_TRACK_ELEM_1_X_5 */ { TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, 0, TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0 },
    /* FLAT_TRACK_ELEM_1_X_1_A */   { TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_ORIGIN | TRACK_SEQUENCE_FLAG_CONNECTS_TO_PATH, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    /* FLAT_TRACK_ELEM_1_X_4_B */   { TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_ORIGIN, 0, TRACK_SEQUENCE_FLAG_DIRECTION_1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0 },
    /* FLAT_TRACK_ELEM_1_X_1_B */   { TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN | TRACK_SEQUENCE_FLAG_CONNECTS_TO_PATH, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    /* FLAT_TRACK_ELEM_1_X_4_C */   { TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3 | TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    /* FLAT_TRACK_ELEM_3_X_3 */ { TRACK_SEQUENCE_FLAG_ORIGIN, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_0, TRACK_SEQUENCE_FLAG_DIRECTION_0 | TRACK_SEQUENCE_FLAG_DIRECTION_1, TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_1, TRACK_SEQUENCE_FLAG_DIRECTION_2 | TRACK_SEQUENCE_FLAG_DIRECTION_3, TRACK_SEQUENCE_FLAG_DIRECTION_1 | TRACK_SEQUENCE_FLAG_DIRECTION_2, TRACK_SEQUENCE_FLAG_DIRECTION_2, 0, 0, 0, 0, 0, 0, 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
};

#define TRACK_BLOCK_END { 255, 255, 255, 255, 255, {255, 255}, 255 }

static constexpr const rct_preview_track TrackBlocksFlat[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksEndStation[] = {
    { 0, 0, 0, 0, 0,{ 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksBeginStation[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksMiddleStation[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp60[] = {
    { 0, 0, 0, 0, 64, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToUp25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25ToUp60[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp60ToUp25[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25ToFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown60[] = {
    { 0, 0, 0, 0, 64, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToDown25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25ToDown60[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown60ToDown25[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25ToFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn5Tiles[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 0, 0, { 0b0111, 0 }, 0 },
    { 6, -64, -64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn5Tiles[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 0, 0, { 0b1011, 0 }, 0 },
    { 6, -64, 64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToLeftBank[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToRightBank[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankToFlat[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankToFlat[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksBankedLeftQuarterTurn5Tiles[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 0, 0, { 0b0111, 0 }, 0 },
    { 6, -64, -64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksBankedRightQuarterTurn5Tiles[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 0, 0, { 0b1011, 0 }, 0 },
    { 6, -64, 64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankToUp25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankToUp25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25ToLeftBank[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25ToRightBank[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankToDown25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankToDown25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25ToLeftBank[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25ToRightBank[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBank[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBank[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn5TilesUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    { 1, 0, -32, 16, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 16, { 0b0111, 0b0100 }, 0 },
    { 3, -32, -32, 24, 16, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 48, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 32, 16, { 0b0111, 0b0100 }, 0 },
    { 6, -64, -64, 48, 16, { 0b1111, 0b0110 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn5TilesUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    { 1, 0, 32, 16, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 16, { 0b1011, 0b1000 }, 0 },
    { 3, -32, 32, 24, 16, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 48, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 32, 16, { 0b1011, 0b1000 }, 0 },
    { 6, -64, 64, 48, 16, { 0b1111, 0b1001 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn5TilesDown25[] = {
    { 0, 0, 0, 48, 16, { 0b1111, 0b0011 }, 0 },
    { 1, 0, -32, 48, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 32, 16, { 0b0111, 0b0001 }, 0 },
    { 3, -32, -32, 24, 16, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 16, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 16, 16, { 0b0111, 0b0001 }, 0 },
    { 6, -64, -64, 0, 16, { 0b1111, 0b1001 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn5TilesDown25[] = {
    { 0, 0, 0, 48, 16, { 0b1111, 0b0011 }, 0 },
    { 1, 0, 32, 48, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 32, 16, { 0b1011, 0b0010 }, 0 },
    { 3, -32, 32, 24, 16, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 16, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 16, 16, { 0b1011, 0b0010 }, 0 },
    { 6, -64, 64, 0, 16, { 0b1111, 0b0110 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksSBendLeft[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 2, -32, -32, 0, 0, { 0b1101, 0 }, 0 },
    { 3, -64, -32, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksSBendRight[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 2, -32, 32, 0, 0, { 0b1110, 0 }, 0 },
    { 3, -64, 32, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftVerticalLoop[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    { 1, -32, 0, 16, 16, { 0b1111, 0b1100 }, 0 },
    { 2, -64, 0, 32, 96, { 0b0010, 0 }, 0 },
    { 3, -32, 0, 120, 16, { 0b0110, 0 }, 0 },
    { 4, -32, -32, 120, 0, { 0b0001, 0 }, 0 },
    { 5, 0, 0, 120, 0, { 0b0100, 0 }, 0 },
    { 6, 0, -32, 120, 16, { 0b1001, 0 }, 0 },
    { 7, 32, -32, 32, 96, { 0b1000, 0 }, 0 },
    { 8, 0, -32, 16, 16, { 0b1111, 0b0011 }, 0 },
    { 9, -32, -32, 0, 16, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightVerticalLoop[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    { 1, -32, 0, 16, 16, { 0b1111, 0b1100 }, 0 },
    { 2, -64, 0, 32, 96, { 0b0001, 0 }, 0 },
    { 3, -32, 0, 120, 16, { 0b1001, 0 }, 0 },
    { 4, -32, 32, 120, 0, { 0b0010, 0 }, 0 },
    { 5, 0, 0, 120, 0, { 0b1000, 0 }, 0 },
    { 6, 0, 32, 120, 16, { 0b0110, 0 }, 0 },
    { 7, 32, 32, 32, 96, { 0b0100, 0 }, 0 },
    { 8, 0, 32, 16, 16, { 0b1111, 0b0011 }, 0 },
    { 9, -32, 32, 0, 16, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn3Tiles[] = {
    { 0, 0, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b0111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn3Tiles[] = {
    { 0, 0, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1011, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedQuarterTurn3Tiles[] = {
    { 0, 0, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b0111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedQuarterTurn3Tiles[] = {
    { 0, 0, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1011, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn3TilesUp25[] = {
    { 0, 0, 0, 0, 16, { 0b0111, 0b0100 }, 0 },
    { 1, 0, -32, 16, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 0, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 16, 16,{ 0b0111, 0b0110 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn3TilesUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1011, 0b1000 }, 0 },
    { 1, 0, 32, 16, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 0, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 16, 16,{ 0b1011, 0b1001 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn3TilesDown25[] = {
    { 0, 0, 0, 16, 16,{ 0b0111, 0b0011 }, 0 },
    { 1, 0, -32, 16, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 0, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 0, 16, { 0b0111, 0b0001 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn3TilesDown25[] = {
    { 0, 0, 0, 16, 16, { 0b1011, 0b0011 }, 0 },
    { 1, 0, 32, 16, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 0, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 0, 16, { 0b1011, 0b0010 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn1Tile[] = {
    { 0, 0, 0, 0, 0, { 0b0111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn1Tile[] = {
    { 0, 0, 0, 0, 0, { 0b1011, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftTwistDownToUp[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 16, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightTwistDownToUp[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 16, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftTwistUpToDown[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -16, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, -16, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightTwistUpToDown[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -16, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, -16, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksHalfLoopUp[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b1100 }, 0 },
    { 1, -32, 0, 16, 16, { 0b1111, 0b1100 }, 0 },
    { 2, -64, 0, 32, 96,{ 0b0011, 0 }, 0 },
    { 3, -32, 0, 120, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksHalfLoopDown[] = {
    { 0, 0, 0, -32, 32, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -120, 96,{ 0b0011, 0 }, 0 },
    { 2, 0, 0, -136, 16, { 0b1111, 0b1100 }, 0 },
    { 3, 32, 0, -152, 16, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftCorkscrewUp[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 24, 32, { 0b0111, 0 }, 0 },
    { 2, -32, -32, 48, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightCorkscrewUp[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 24, 32, { 0b1011, 0 }, 0 },
    { 2, -32, 32, 48, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftCorkscrewDown[] = {
    { 0, 0, 0, -32, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -56, 32, { 0b0111, 0 }, 0 },
    { 2, -32, -32, -80, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightCorkscrewDown[] = {
    { 0, 0, 0, -32, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -56, 32, { 0b1011, 0 }, 0 },
    { 2, -32, 32, -80, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToUp60[] = {
    { 0, 0, 0, 0, 24, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp60ToFlat[] = {
    { 0, 0, 0, 0, 24, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToDown60[] = {
    { 0, 0, 0, 0, 24, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown60ToFlat[] = {
    { 0, 0, 0, 0, 24, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksTowerBase[] = {
    { 0, 0, 0, 0, 64, { 0b1111, 0 }, 0 },
    { 1, -32, -32, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 4, 0, -32, 0, 0, { 0b1111, 0 }, 0 },
    { 5, 0, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 6, 32, -32, 0, 0, { 0b1111, 0 }, 0 },
    { 7, 32, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 8, 32, 0, 0, 0, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_1 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksTowerSection[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 32, 0, 0, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_1 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatCovered[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25Covered[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp60Covered[] = {
    { 0, 0, 0, 0, 64, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToUp25Covered[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25ToUp60Covered[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp60ToUp25Covered[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25ToFlatCovered[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25Covered[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown60Covered[] = {
    { 0, 0, 0, 0, 64, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToDown25Covered[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25ToDown60Covered[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown60ToDown25Covered[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25ToFlatCovered[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn5TilesCovered[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 0, 0, { 0b0111, 0 }, 0 },
    { 6, -64, -64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn5TilesCovered[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 0, 0, { 0b1011, 0 }, 0 },
    { 6, -64, 64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksSBendLeftCovered[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 2, -32, -32, 0, 0, { 0b1101, 0 }, 0 },
    { 3, -64, -32, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksSBendRightCovered[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 2, -32, 32, 0, 0, { 0b1110, 0 }, 0 },
    { 3, -64, 32, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn3TilesCovered[] = {
    { 0, 0, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b0111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn3TilesCovered[] = {
    { 0, 0, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1011, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftHalfBankedHelixUpSmall[] = {
    { 0, 0, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 4, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 0, 4, { 0b0111, 0 }, 0 },
    { 4, -32, -64, 8, 0, { 0b1011, 0 }, 0 },
    { 5, 0, -64, 8, 0, { 0b0100, 0b0000 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 6, -32, -96, 8, 4, { 0b0001, 0 }, 0 },
    { 7, 0, -96, 8, 4, { 0b1011, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightHalfBankedHelixUpSmall[] = {
    { 0, 0, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0b0000 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 4, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 0, 4, { 0b1011, 0 }, 0 },
    { 4, -32, 64, 8, 0, { 0b0111, 0 }, 0 },
    { 5, 0, 64, 8, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 6, -32, 96, 8, 4, { 0b0010, 0 }, 0 },
    { 7, 0, 96, 8, 4, { 0b0111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftHalfBankedHelixDownSmall[] = {
    { 0, 0, 0, 8, 4, { 0b0111, 0 }, 0 },
    { 1, 0, -32, 8, 4, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 8, 0, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 8, 0, { 0b0111, 0 }, 0 },
    { 4, -32, -64, 0, 4, { 0b1011, 0 }, 0 },
    { 5, 0, -64, 0, 4, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 6, -32, -96, 0, 0, { 0b0001, 0 }, 0 },
    { 7, 0, -96, 0, 0, { 0b1011, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightHalfBankedHelixDownSmall[] = {
    { 0, 0, 0, 8, 4, { 0b1011, 0 }, 0 },
    { 1, 0, 32, 8, 4, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 8, 0, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 8, 0, { 0b1011, 0 }, 0 },
    { 4, -32, 64, 0, 4, { 0b0111, 0 }, 0 },
    { 5, 0, 64, 0, 4, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 6, -32, 96, 0, 0, { 0b0010, 0 }, 0 },
    { 7, 0, 96, 0, 0, { 0b0111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftHalfBankedHelixUpLarge[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 0, 4, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 0, 4, { 0b0111, 0 }, 0 },
    { 6, -64, -64, 0, 4, { 0b1111, 0 }, 0 },
    { 7, -64, -96, 8, 0, { 0b1111, 0 }, 0 },
    { 8, -32, -96, 8, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 9, -64, -128, 8, 0, { 0b1011, 0 }, 0 },
    { 10, -32, -128, 8, 0, { 0b1110, 0 }, 0 },
    { 11, 0, -128, 8, 4, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 12, -32, -160, 8, 4, { 0b1011, 0 }, 0 },
    { 13, 0, -160, 8, 4, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightHalfBankedHelixUpLarge[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 0, 4, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 0, 4, { 0b1011, 0 }, 0 },
    { 6, -64, 64, 0, 4, { 0b1111, 0 }, 0 },
    { 7, -64, 96, 8, 0, { 0b1111, 0 }, 0 },
    { 8, -32, 96, 8, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 9, -64, 128, 8, 0, { 0b0111, 0 }, 0 },
    { 10, -32, 128, 8, 0, { 0b1101, 0 }, 0 },
    { 11, 0, 128, 8, 4, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 12, -32, 160, 8, 4, { 0b0111, 0 }, 0 },
    { 13, 0, 160, 8, 4, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftHalfBankedHelixDownLarge[] = {
    { 0, 0, 0, 8, 4, { 0b1111, 0 }, 0 },
    { 1, 0, -32, 8, 4, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 8, 4, { 0b0111, 0 }, 0 },
    { 3, -32, -32, 8, 0, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 8, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 8, 0, { 0b0111, 0 }, 0 },
    { 6, -64, -64, 8, 0, { 0b1111, 0 }, 0 },
    { 7, -64, -96, 0, 4, { 0b1111, 0 }, 0 },
    { 8, -32, -96, 0, 4, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 9, -64, -128, 0, 4, { 0b1011, 0 }, 0 },
    { 10, -32, -128, 0, 0, { 0b1110, 0 }, 0 },
    { 11, 0, -128, 0, 0, { 0b0100, 0b0000 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 12, -32, -160, 0, 0, { 0b1011, 0 }, 0 },
    { 13, 0, -160, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightHalfBankedHelixDownLarge[] = {
    { 0, 0, 0, 8, 4, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 8, 4, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 8, 4, { 0b1011, 0 }, 0 },
    { 3, -32, 32, 8, 0, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 8, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 8, 0, { 0b1011, 0 }, 0 },
    { 6, -64, 64, 8, 0, { 0b1111, 0 }, 0 },
    { 7, -64, 96, 0, 4, { 0b1111, 0 }, 0 },
    { 8, -32, 96, 0, 4, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 9, -64, 128, 0, 4, { 0b0111, 0 }, 0 },
    { 10, -32, 128, 0, 0, { 0b1101, 0 }, 0 },
    { 11, 0, 128, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 12, -32, 160, 0, 0, { 0b0111, 0 }, 0 },
    { 13, 0, 160, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn1TileUp60[] = {
    { 0, 0, 0, 0, 64, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn1TileUp60[] = {
    { 0, 0, 0, 0, 64, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn1TileDown60[] = {
    { 0, 0, 0, 0, 64, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftRightQuarterTurn1TileDown60[] = {
    { 0, 0, 0, 0, 64, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksBrakes[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRotationControlToggle[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksMaze[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterBankedHelixLargeUp[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 0, 12, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 0, 12, { 0b0111, 0 }, 0 },
    { 6, -64, -64, 0, 12, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterBankedHelixLargeUp[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 0, 12, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 0, 12, { 0b1011, 0 }, 0 },
    { 6, -64, 64, 0, 12, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterBankedHelixLargeDown[] = {
    { 0, 0, 0, 0, 12, { 0b1111, 0 }, 0 },
    { 1, 0, -32, 0, 12, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 12, { 0b0111, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 0, 0, { 0b0111, 0 }, 0 },
    { 6, -64, -64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterBankedHelixLargeDown[] = {
    { 0, 0, 0, 0, 12, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 12, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 12, { 0b1011, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 0, 0, { 0b1011, 0 }, 0 },
    { 6, -64, 64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterHelixLargeUp[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 0, 12, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 0, 12, { 0b0111, 0 }, 0 },
    { 6, -64, -64, 0, 12, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterHelixLargeUp[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 0, 12, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 0, 12, { 0b1011, 0 }, 0 },
    { 6, -64, 64, 0, 12, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterHelixLargeDown[] = {
    { 0, 0, 0, 0, 12, { 0b1111, 0 }, 0 },
    { 1, 0, -32, 0, 12, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 12, { 0b0111, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 0, 0, { 0b0111, 0 }, 0 },
    { 6, -64, -64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterHelixLargeDown[] = {
    { 0, 0, 0, 0, 12, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 12, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 12, { 0b1011, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 0, 0, { 0b1011, 0 }, 0 },
    { 6, -64, 64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25LeftBanked[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25RightBanked[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksWaterfall[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRapids[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksOnRidePhoto[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25LeftBanked[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25RightBanked[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksWatersplash[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 3, -96, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 4, -128, 0, 0, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToUp60LongBase[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 16, 24, { 0b1111, 0 }, 0 },
    { 3, -96, 0, 40, 48, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp60ToFlatLongBase[] = {
    { 0, 0, 0, 0, 48, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 40, 48, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 64, 24, { 0b1111, 0 }, 0 },
    { 3, -96, 0, 80, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksWhirlpool[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown60ToFlatLongBase[] = {
    { 0, 0, 0, 40, 48, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 16, 24, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 3, -96, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToDown60LongBase[] = {
    { 0, 0, 0, 80, 8, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 64, 24, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 40, 48, { 0b1111, 0 }, 0 },
    { 3, -96, 0, 0, 48, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksCableLiftHill[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b1100 }, 0 },
    { 1, -32, 0, 0, 8, { 0b1111, 0b0011 }, 0 },
    { 2, -64, 0, -32, 32, { 0b1111, 0b0011 }, 0 },
    { 3, -96, 0, -96, 64, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksReverseFreefallSlope[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 32, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 0, 48, { 0b1111, 0 }, 0 },
    { 3, -96, 0, 0, 80, { 0b1111, 0 }, 0 },
    { 4, -128, 0, 0, 160, { 0b1111, 0 }, 0 },
    { 5, -192, 0, 0, 208, { 0b1111, 0 }, 0 },
    { 6, -160, 0, 0, 208, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksReverseFreefallVertical[] = {
    { 0, 0, 0, 0, 48, { 0b1111, 0 }, 0 },
    { 1, 32, 0, 0, 48, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp90[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, 32, 0, 0, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown90[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, 32, 0, 0, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp60ToUp90[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b1100 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, 32, 0, 0, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown90ToDown60[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b0011 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp90ToUp60[] = {
    { 0, 0, 0, 0, 56, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown60ToDown90[] = {
    { 0, 0, 0, 0, 56, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, 32, 0, 0, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksBrakeForDrop[] = {
    { 0, 0, 0, 0, 24, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftEighthToDiag[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, -32, 0, 0, { 0b1000, 0 }, 0 },
    { 3, -64, 0, 0, 0, { 0b0010, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 4, -64, -32, 0, 0, { 0b0001, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightEighthToDiag[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, 32, 0, 0, { 0b0100, 0 }, 0 },
    { 3, -64, 0, 0, 0, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 4, -64, 32, 0, 0, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftEighthToOrthogonal[] = {
    { 0, 0, 0, 0, 0, { 0b1101, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b0001, 0 }, 0 },
    { 2, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 4, -64, 32, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightEighthToOrthogonal[] = {
    { 0, 0, 0, 0, 0, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, 0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 4, -32, 64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftEighthBankToDiag[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, -32, 0, 0, { 0b1000, 0 }, 0 },
    { 3, -64, 0, 0, 0, { 0b0010, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 4, -64, -32, 0, 0, { 0b0001, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightEighthBankToDiag[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, 32, 0, 0, { 0b0100, 0 }, 0 },
    { 3, -64, 0, 0, 0, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 4, -64, 32, 0, 0, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftEighthBankToOrthogonal[] = {
    { 0, 0, 0, 0, 0, { 0b1101, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b0001, 0 }, 0 },
    { 2, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 4, -64, 32, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightEighthBankToOrthogonal[] = {
    { 0, 0, 0, 0, 0, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, 0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 4, -32, 64, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagFlat[] = {
    { 0, 0, 0, 0, 0, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 0, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 16, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 16, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 16, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagUp60[] = {
    { 0, 0, 0, 0, 64, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 64, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 64, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 64, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagFlatToUp25[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagUp25ToUp60[] = {
    { 0, 0, 0, 0, 32, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 32, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 32, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 32, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagUp60ToUp25[] = {
    { 0, 0, 0, 0, 32, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 32, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 32, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 32, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagUp25ToFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagDown25[] = {
    { 0, 0, 0, 0, 16, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 16, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 16, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 16, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagDown60[] = {
    { 0, 0, 0, 0, 64, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 64, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 64, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 64, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagFlatToDown25[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagDown25ToDown60[] = {
    { 0, 0, 0, 0, 32, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 32, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 32, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 32, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagDown60ToDown25[] = {
    { 0, 0, 0, 0, 32, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 32, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 32, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 32, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagDown25ToFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagFlatToUp60[] = {
    { 0, 0, 0, 0, 24, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 24, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 24, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 24, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagUp60ToFlat[] = {
    { 0, 0, 0, 0, 24, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 24, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 24, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 24, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagFlatToDown60[] = {
    { 0, 0, 0, 0, 24, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 24, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 24, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 24, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagDown60ToFlat[] = {
    { 0, 0, 0, 0, 24, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 24, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 24, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 24, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagFlatToLeftBank[] = {
    { 0, 0, 0, 0, 0, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 0, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagFlatToRightBank[] = {
    { 0, 0, 0, 0, 0, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 0, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagLeftBankToFlat[] = {
    { 0, 0, 0, 0, 0, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 0, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagRightBankToFlat[] = {
    { 0, 0, 0, 0, 0, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 0, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagLeftBankToUp25[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagRightBankToUp25[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagUp25ToLeftBank[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagUp25ToRightBank[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagLeftBankToDown25[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagRightBankToDown25[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagDown25ToLeftBank[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagDown25ToRightBank[] = {
    { 0, 0, 0, 0, 8, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 8, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 8, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagLeftBank[] = {
    { 0, 0, 0, 0, 0, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 0, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDiagRightBank[] = {
    { 0, 0, 0, 0, 0, { 0b1101, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 0, { 0b0001, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 3, -32, 32, 0, 0, { 0b0010, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLogFlumeReverser[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksSpinningTunnel[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBarrelRollUpToDown[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 0, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBarrelRollUpToDown[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 0, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBarrelRollDownToUp[] = {
    { 0, 0, 0, -32, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -32, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, -32, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBarrelRollDownToUp[] = {
    { 0, 0, 0, -32, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -32, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, -32, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankToLeftQuarterTurn3TilesUp25[] = {
    { 0, 0, 0, 0, 0, { 0b0111, 0b0100 }, 0 },
    { 1, 0, -32, 0, 16, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 16, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 16, 16,{ 0b0111, 0b0110 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankToRightQuarterTurn3TilesUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1011, 0b1000 }, 0 },
    { 1, 0, 32, 0, 16, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 16, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 16, 16,{ 0b1011, 0b1001 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn3TilesDown25ToLeftBank[] = {
    { 0, 0, 0, 16, 16,{ 0b0111, 0b0011 }, 0 },
    { 1, 0, -32, 0, 16, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 16, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 0, 0, { 0b0111, 0b0001 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn3TilesDown25ToRightBank[] = {
    { 0, 0, 0, 16, 16, { 0b1011, 0b0011 }, 0 },
    { 1, 0, 32, 0, 16, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 16, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1011, 0b0010 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksPoweredLift[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftLargeHalfLoopUp[] = {
    { 0, 0, 0, 0, 24, { 0b1111, 0b1100 }, 0 },
    { 1, -32, 0, 16, 40, { 0b1111, 0b1100 }, 0 },
    { 2, -64, 0, 32, 56, { 0b1111, 0 }, 0 },
    { 3, -96, 0, 64, 192, { 0b1111, 0 }, 0 },
    { 4, -128, -32, 120, 96, { 0b1111, 0 }, 0 },
    { 5, -96, -32, 64, 192, { 0b1111, 0 }, 0 },
    { 6, -64, -32, 248, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightLargeHalfLoopUp[] = {
    { 0, 0, 0, 0, 24, { 0b1111, 0b1100 }, 0 },
    { 1, -32, 0, 16, 40, { 0b1111, 0b1100 }, 0 },
    { 2, -64, 0, 32, 56, { 0b1111, 0 }, 0 },
    { 3, -96, 0, 64, 192, { 0b1111, 0 }, 0 },
    { 4, -128, 32, 120, 96, { 0b1111, 0 }, 0 },
    { 5, -96, 32, 64, 192, { 0b1111, 0 }, 0 },
    { 6, -64, 32, 248, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightLargeHalfLoopDown[] = {
    { 0, 0, 0, -32, 24, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -216, 192, { 0b1111, 0 }, 0 },
    { 2, -64, 0, -160, 96, { 0b1111, 0 }, 0 },
    { 3, -32, -32, -216, 192, { 0b1111, 0 }, 0 },
    { 4, 0, -32, -248, 56, { 0b1111, 0 }, 0 },
    { 5, 32, -32, -264, 40, { 0b1111, 0b1100 }, 0 },
    { 6, 64, -32, -280, 24, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftLargeHalfLoopDown[] = {
    { 0, 0, 0, -32, 24, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -216, 192, { 0b1111, 0 }, 0 },
    { 2, -64, 0, -160, 96, { 0b1111, 0 }, 0 },
    { 3, -32, 32, -216, 192, { 0b1111, 0 }, 0 },
    { 4, 0, 32, -248, 56, { 0b1111, 0 }, 0 },
    { 5, 32, 32, -264, 40, { 0b1111, 0b1100 }, 0 },
    { 6, 64, 32, -280, 24, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftFlyerTwistUp[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -16, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, -16, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightFlyerTwistUp[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -16, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, -16, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftFlyerTwistDown[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 16, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightFlyerTwistDown[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 16, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlyerHalfLoopUp[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0b1100 }, 0 },
    { 1, -32, 0, 16, 16, { 0b1111, 0b1100 }, 0 },
    { 2, -64, 0, 32, 96,{ 0b0011, 0 }, 0 },
    { 3, -32, 0, 120, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlyerHalfLoopDown[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -88, 96,{ 0b0011, 0 }, 0 },
    { 2, 0, 0, -104, 16, { 0b1111, 0b1100 }, 0 },
    { 3, 32, 0, -120, 16, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftFlyerCorkscrewUp[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 24, 32, { 0b0111, 0 }, 0 },
    { 2, -32, -32, 48, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightFlyerCorkscrewUp[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 24, 32, { 0b1011, 0 }, 0 },
    { 2, -32, 32, 48, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftFlyerCorkscrewDown[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -24, 32, { 0b0111, 0 }, 0 },
    { 2, -32, -32, -48, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightFlyerCorkscrewDown[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -24, 32, { 0b1011, 0 }, 0 },
    { 2, -32, 32, -48, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksHeartLineTransferUp[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 32, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 16, 0, { 0b1111, 0 }, 0 },
    { 3, 0, 0, 32, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksHeartLineTransferDown[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, -32, 32, { 0b1111, 0 }, 0 },
    { 2, -64, 0, -16, 0, { 0b1111, 0 }, 0 },
    { 3, 0, 0, -32, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftHeartLineRoll[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 3, -96, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 4, -128, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 5, -160, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightHeartLineRoll[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 3, -96, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 4, -128, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 5, -160, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksMinigolfHoleA[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksMinigolfHoleB[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksMinigolfHoleC[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksMinigolfHoleD[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, 32, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksMinigolfHoleE[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, -32, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksMultiDimInvertedFlatToDown90QuarterLoop[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, -32, 0, -40, 32, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 2, -64, 0, -96, 56, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 3, -96, 0, -96, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp90ToInvertedFlatQuarterLoop[] = {
    { 0, 0, 0, 0, 56, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, 32, 0, 56, 32, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 2, 64, 0, 96, 16, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksInvertedFlatToDown90QuarterLoop[] = {
    { 0, 0, 0, -32, 16, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, -32, 0, -72, 32, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 2, -64, 0, -128, 56, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 3, -96, 0, -128, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftCurvedLiftHill[] = {
    { 0, 0, 0, 0, 0, { 0b0111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 0, 8, { 0b0111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightCurvedLiftHill[] = {
    { 0, 0, 0, 0, 0, { 0b1011, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 0, 8, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 0, 8, { 0b1011, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftReverser[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, -32, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, -32, 0, 0, { 0b1111, 0 }, 0 },
    { 3, -64, -32, 0, 0, { 0b1111, 0 }, 0 },
    { 4, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 5, -64, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightReverser[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 3, -64, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 4, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 5, -64, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksAirThrustTopCap[] = {
    { 0, 0, 0, 0, 32, { 0b1111, 0 }, 0 },
    { 1, 32, 0, 0, 32, { 0b1111, 0 }, 0 },
    { 2, -64, 0, 0, 32, { 0b1111, 0 }, 0 },
    { 3, -32, 0, 0, 32, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksAirThrustVerticalDown[] = {
    { 0, 0, 0, 0, 48, { 0b1111, 0 }, 0 },
    { 1, 32, 0, 0, 48, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksAirThrustVerticalDownToLevel[] = {
    { 0, 0, 0, 0, 208, { 0b1111, 0 }, 0 },
    { 1, 32, 0, 0, 208, { 0b1111, 0 }, 0 },
    { 2, -32, 0, 0, 160, { 0b1111, 0 }, 0 },
    { 3, -64, 0, 0, 80, { 0b1111, 0 }, 0 },
    { 4, -96, 0, 0, 48, { 0b1111, 0 }, 0 },
    { 5, -128, 0, 0, 32, { 0b1111, 0 }, 0 },
    { 6, -160, 0, 0, 16, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksBlockBrakes[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedQuarterTurn3TileUp25[] = {
    { 0, 0, 0, 0, 16, { 0b0111, 0b0100 }, 0 },
    { 1, 0, -32, 16, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 0, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 16, 16,{ 0b0111, 0b0110 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedQuarterTurn3TileUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1011, 0b1000 }, 0 },
    { 1, 0, 32, 16, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 0, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 16, 16,{ 0b1011, 0b1001 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedQuarterTurn3TileDown25[] = {
    { 0, 0, 0, 16, 16,{ 0b0111, 0b0011 }, 0 },
    { 1, 0, -32, 16, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 0, { 0b0010, 0 }, 0 },
    { 3, -32, -32, 0, 16, { 0b0111, 0b0001 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedQuarterTurn3TileDown25[] = {
    { 0, 0, 0, 16, 16, { 0b1011, 0b0011 }, 0 },
    { 1, 0, 32, 16, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 0, { 0b0001, 0 }, 0 },
    { 3, -32, 32, 0, 16, { 0b1011, 0b0010 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedQuarterTurn5TileUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    { 1, 0, -32, 16, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 16, { 0b0111, 0b0100 }, 0 },
    { 3, -32, -32, 24, 16, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 48, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 32, 16, { 0b0111, 0b0100 }, 0 },
    { 6, -64, -64, 48, 16, { 0b1111, 0b0110 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedQuarterTurn5TileUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    { 1, 0, 32, 16, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 16, 16, { 0b1011, 0b1000 }, 0 },
    { 3, -32, 32, 24, 16, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 48, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 32, 16, { 0b1011, 0b1000 }, 0 },
    { 6, -64, 64, 48, 16, { 0b1111, 0b1001 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedQuarterTurn5TileDown25[] = {
    { 0, 0, 0, 48, 16, { 0b1111, 0b0011 }, 0 },
    { 1, 0, -32, 48, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 32, 16, { 0b0111, 0b0001 }, 0 },
    { 3, -32, -32, 24, 16, { 0b1101, 0 }, 0 },
    { 4, -32, -64, 16, 0, { 0b1000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, -32, 16, 16, { 0b0111, 0b0001 }, 0 },
    { 6, -64, -64, 0, 16, { 0b1111, 0b1001 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedQuarterTurn5TileDown25[] = {
    { 0, 0, 0, 48, 16, { 0b1111, 0b0011 }, 0 },
    { 1, 0, 32, 48, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 2, -32, 0, 32, 16, { 0b1011, 0b0010 }, 0 },
    { 3, -32, 32, 24, 16, { 0b1110, 0 }, 0 },
    { 4, -32, 64, 16, 0, { 0b0100, 0 }, RCT_PREVIEW_TRACK_FLAG_0 },
    { 5, -64, 32, 16, 16, { 0b1011, 0b0010 }, 0 },
    { 6, -64, 64, 0, 16, { 0b1111, 0b0110 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25ToLeftBankedUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksUp25ToRightBankedUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedUp25ToUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedUp25ToUp25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25ToLeftBankedDown25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksDown25ToRightBankedDown25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedDown25ToDown25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedDown25ToDown25[] = {
    { 0, 0, 0, 0, 16, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedFlatToLeftBankedUp25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedFlatToRightBankedUp25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedUp25ToLeftBankedFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedUp25ToRightBankedFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedFlatToLeftBankedDown25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedFlatToRightBankedDown25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedDown25ToLeftBankedFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedDown25ToRightBankedFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlockFlatToLeftBankedUp25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlockFlatToRightBankedUp25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedUp25ToFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedUp25ToFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b1100 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToLeftBankedDown25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksFlatToRightBankedDown25[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0b0011 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftBankedDown25ToFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightBankedDown25ToFlat[] = {
    { 0, 0, 0, 0, 8, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn1TileUp90[] = {
    { 0, 0, 0, 0, 72, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, 0, 32, 0, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn1TileUp90[] = {
    { 0, 0, 0, 0, 72, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, 0, -32, 0, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksLeftQuarterTurn1TileDown90[] = {
    { 0, 0, 0, 0, 72, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, 0, 32, 0, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksRightQuarterTurn1TileDown90[] = {
    { 0, 0, 0, 0, 72, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, 0, -32, 0, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksMultiDimUp90ToInvertedFlatQuarterLoop[] = {
    { 0, 0, 0, 0, 56, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, 32, 0, 56, 32, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 2, 64, 0, 96, 16, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksMultiDimFlatToDown90QuarterLoop[] = {
    { 0, 0, 0, -32, 16, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, -32, 0, -72, 32, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 2, -64, 0, -128, 56, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 3, -96, 0, -128, 0, { 0b0000, 0 }, RCT_PREVIEW_TRACK_FLAG_0 | RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track TrackBlocksMultiDimInvertedUp90ToFlatQuarterLoop[] = {
    { 0, 0, 0, 32, 56, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 1, 32, 0, 88, 32, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    { 2, 64, 0, 128, 16, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_IS_VERTICAL },
    TRACK_BLOCK_END
};

// rct2: 0x00994638
const rct_preview_track *TrackBlocks[TrackElemType::Count] = {
    TrackBlocksFlat,
    TrackBlocksEndStation,
    TrackBlocksBeginStation,
    TrackBlocksMiddleStation,
    TrackBlocksUp25,
    TrackBlocksUp60,
    TrackBlocksFlatToUp25,
    TrackBlocksUp25ToUp60,
    TrackBlocksUp60ToUp25,
    TrackBlocksUp25ToFlat,
    TrackBlocksDown25,
    TrackBlocksDown60,
    TrackBlocksFlatToDown25,
    TrackBlocksDown25ToDown60,
    TrackBlocksDown60ToDown25,
    TrackBlocksDown25ToFlat,
    TrackBlocksLeftQuarterTurn5Tiles,
    TrackBlocksRightQuarterTurn5Tiles,
    TrackBlocksFlatToLeftBank,
    TrackBlocksFlatToRightBank,
    TrackBlocksLeftBankToFlat,
    TrackBlocksRightBankToFlat,
    TrackBlocksBankedLeftQuarterTurn5Tiles,
    TrackBlocksBankedRightQuarterTurn5Tiles,
    TrackBlocksLeftBankToUp25,
    TrackBlocksRightBankToUp25,
    TrackBlocksUp25ToLeftBank,
    TrackBlocksUp25ToRightBank,
    TrackBlocksLeftBankToDown25,
    TrackBlocksRightBankToDown25,
    TrackBlocksDown25ToLeftBank,
    TrackBlocksDown25ToRightBank,
    TrackBlocksLeftBank,
    TrackBlocksRightBank,
    TrackBlocksLeftQuarterTurn5TilesUp25,
    TrackBlocksRightQuarterTurn5TilesUp25,
    TrackBlocksLeftQuarterTurn5TilesDown25,
    TrackBlocksRightQuarterTurn5TilesDown25,
    TrackBlocksSBendLeft,
    TrackBlocksSBendRight,
    TrackBlocksLeftVerticalLoop,
    TrackBlocksRightVerticalLoop,
    TrackBlocksLeftQuarterTurn3Tiles,
    TrackBlocksRightQuarterTurn3Tiles,
    TrackBlocksLeftBankedQuarterTurn3Tiles,
    TrackBlocksRightBankedQuarterTurn3Tiles,
    TrackBlocksLeftQuarterTurn3TilesUp25,
    TrackBlocksRightQuarterTurn3TilesUp25,
    TrackBlocksLeftQuarterTurn3TilesDown25,
    TrackBlocksRightQuarterTurn3TilesDown25,
    TrackBlocksLeftQuarterTurn1Tile,
    TrackBlocksRightQuarterTurn1Tile,
    TrackBlocksLeftTwistDownToUp,
    TrackBlocksRightTwistDownToUp,
    TrackBlocksLeftTwistUpToDown,
    TrackBlocksRightTwistUpToDown,
    TrackBlocksHalfLoopUp,
    TrackBlocksHalfLoopDown,
    TrackBlocksLeftCorkscrewUp,
    TrackBlocksRightCorkscrewUp,
    TrackBlocksLeftCorkscrewDown,
    TrackBlocksRightCorkscrewDown,
    TrackBlocksFlatToUp60,
    TrackBlocksUp60ToFlat,
    TrackBlocksFlatToDown60,
    TrackBlocksDown60ToFlat,
    TrackBlocksTowerBase,
    TrackBlocksTowerSection,
    TrackBlocksFlatCovered,
    TrackBlocksUp25Covered,
    TrackBlocksUp60Covered,
    TrackBlocksFlatToUp25Covered,
    TrackBlocksUp25ToUp60Covered,
    TrackBlocksUp60ToUp25Covered,
    TrackBlocksUp25ToFlatCovered,
    TrackBlocksDown25Covered,
    TrackBlocksDown60Covered,
    TrackBlocksFlatToDown25Covered,
    TrackBlocksDown25ToDown60Covered,
    TrackBlocksDown60ToDown25Covered,
    TrackBlocksDown25ToFlatCovered,
    TrackBlocksLeftQuarterTurn5TilesCovered,
    TrackBlocksRightQuarterTurn5TilesCovered,
    TrackBlocksSBendLeftCovered,
    TrackBlocksSBendRightCovered,
    TrackBlocksLeftQuarterTurn3TilesCovered,
    TrackBlocksRightQuarterTurn3TilesCovered,
    TrackBlocksLeftHalfBankedHelixUpSmall,
    TrackBlocksRightHalfBankedHelixUpSmall,
    TrackBlocksLeftHalfBankedHelixDownSmall,
    TrackBlocksRightHalfBankedHelixDownSmall,
    TrackBlocksLeftHalfBankedHelixUpLarge,
    TrackBlocksRightHalfBankedHelixUpLarge,
    TrackBlocksLeftHalfBankedHelixDownLarge,
    TrackBlocksRightHalfBankedHelixDownLarge,
    TrackBlocksLeftQuarterTurn1TileUp60,
    TrackBlocksRightQuarterTurn1TileUp60,
    TrackBlocksLeftQuarterTurn1TileDown60,
    TrackBlocksLeftRightQuarterTurn1TileDown60,
    TrackBlocksBrakes,
    TrackBlocksRotationControlToggle,
    TrackBlocksMaze,
    TrackBlocksLeftQuarterBankedHelixLargeUp,
    TrackBlocksRightQuarterBankedHelixLargeUp,
    TrackBlocksLeftQuarterBankedHelixLargeDown,
    TrackBlocksRightQuarterBankedHelixLargeDown,
    TrackBlocksLeftQuarterHelixLargeUp,
    TrackBlocksRightQuarterHelixLargeUp,
    TrackBlocksLeftQuarterHelixLargeDown,
    TrackBlocksRightQuarterHelixLargeDown,
    TrackBlocksUp25LeftBanked,
    TrackBlocksUp25RightBanked,
    TrackBlocksWaterfall,
    TrackBlocksRapids,
    TrackBlocksOnRidePhoto,
    TrackBlocksDown25LeftBanked,
    TrackBlocksDown25RightBanked,
    TrackBlocksWatersplash,
    TrackBlocksFlatToUp60LongBase,
    TrackBlocksUp60ToFlatLongBase,
    TrackBlocksWhirlpool,
    TrackBlocksDown60ToFlatLongBase,
    TrackBlocksFlatToDown60LongBase,
    TrackBlocksCableLiftHill,
    TrackBlocksReverseFreefallSlope,
    TrackBlocksReverseFreefallVertical,
    TrackBlocksUp90,
    TrackBlocksDown90,
    TrackBlocksUp60ToUp90,
    TrackBlocksDown90ToDown60,
    TrackBlocksUp90ToUp60,
    TrackBlocksDown60ToDown90,
    TrackBlocksBrakeForDrop,
    TrackBlocksLeftEighthToDiag,
    TrackBlocksRightEighthToDiag,
    TrackBlocksLeftEighthToOrthogonal,
    TrackBlocksRightEighthToOrthogonal,
    TrackBlocksLeftEighthBankToDiag,
    TrackBlocksRightEighthBankToDiag,
    TrackBlocksLeftEighthBankToOrthogonal,
    TrackBlocksRightEighthBankToOrthogonal,
    TrackBlocksDiagFlat,
    TrackBlocksDiagUp25,
    TrackBlocksDiagUp60,
    TrackBlocksDiagFlatToUp25,
    TrackBlocksDiagUp25ToUp60,
    TrackBlocksDiagUp60ToUp25,
    TrackBlocksDiagUp25ToFlat,
    TrackBlocksDiagDown25,
    TrackBlocksDiagDown60,
    TrackBlocksDiagFlatToDown25,
    TrackBlocksDiagDown25ToDown60,
    TrackBlocksDiagDown60ToDown25,
    TrackBlocksDiagDown25ToFlat,
    TrackBlocksDiagFlatToUp60,
    TrackBlocksDiagUp60ToFlat,
    TrackBlocksDiagFlatToDown60,
    TrackBlocksDiagDown60ToFlat,
    TrackBlocksDiagFlatToLeftBank,
    TrackBlocksDiagFlatToRightBank,
    TrackBlocksDiagLeftBankToFlat,
    TrackBlocksDiagRightBankToFlat,
    TrackBlocksDiagLeftBankToUp25,
    TrackBlocksDiagRightBankToUp25,
    TrackBlocksDiagUp25ToLeftBank,
    TrackBlocksDiagUp25ToRightBank,
    TrackBlocksDiagLeftBankToDown25,
    TrackBlocksDiagRightBankToDown25,
    TrackBlocksDiagDown25ToLeftBank,
    TrackBlocksDiagDown25ToRightBank,
    TrackBlocksDiagLeftBank,
    TrackBlocksDiagRightBank,
    TrackBlocksLogFlumeReverser,
    TrackBlocksSpinningTunnel,
    TrackBlocksLeftBarrelRollUpToDown,
    TrackBlocksRightBarrelRollUpToDown,
    TrackBlocksLeftBarrelRollDownToUp,
    TrackBlocksRightBarrelRollDownToUp,
    TrackBlocksLeftBankToLeftQuarterTurn3TilesUp25,
    TrackBlocksRightBankToRightQuarterTurn3TilesUp25,
    TrackBlocksLeftQuarterTurn3TilesDown25ToLeftBank,
    TrackBlocksRightQuarterTurn3TilesDown25ToRightBank,
    TrackBlocksPoweredLift,
    TrackBlocksLeftLargeHalfLoopUp,
    TrackBlocksRightLargeHalfLoopUp,
    TrackBlocksRightLargeHalfLoopDown,
    TrackBlocksLeftLargeHalfLoopDown,
    TrackBlocksLeftFlyerTwistUp,
    TrackBlocksRightFlyerTwistUp,
    TrackBlocksLeftFlyerTwistDown,
    TrackBlocksRightFlyerTwistDown,
    TrackBlocksFlyerHalfLoopUp,
    TrackBlocksFlyerHalfLoopDown,
    TrackBlocksLeftFlyerCorkscrewUp,
    TrackBlocksRightFlyerCorkscrewUp,
    TrackBlocksLeftFlyerCorkscrewDown,
    TrackBlocksRightFlyerCorkscrewDown,
    TrackBlocksHeartLineTransferUp,
    TrackBlocksHeartLineTransferDown,
    TrackBlocksLeftHeartLineRoll,
    TrackBlocksRightHeartLineRoll,
    TrackBlocksMinigolfHoleA,
    TrackBlocksMinigolfHoleB,
    TrackBlocksMinigolfHoleC,
    TrackBlocksMinigolfHoleD,
    TrackBlocksMinigolfHoleE,
    TrackBlocksMultiDimInvertedFlatToDown90QuarterLoop,
    TrackBlocksUp90ToInvertedFlatQuarterLoop,
    TrackBlocksInvertedFlatToDown90QuarterLoop,
    TrackBlocksLeftCurvedLiftHill,
    TrackBlocksRightCurvedLiftHill,
    TrackBlocksLeftReverser,
    TrackBlocksRightReverser,
    TrackBlocksAirThrustTopCap,
    TrackBlocksAirThrustVerticalDown,
    TrackBlocksAirThrustVerticalDownToLevel,
    TrackBlocksBlockBrakes,
    TrackBlocksLeftBankedQuarterTurn3TileUp25,
    TrackBlocksRightBankedQuarterTurn3TileUp25,
    TrackBlocksLeftBankedQuarterTurn3TileDown25,
    TrackBlocksRightBankedQuarterTurn3TileDown25,
    TrackBlocksLeftBankedQuarterTurn5TileUp25,
    TrackBlocksRightBankedQuarterTurn5TileUp25,
    TrackBlocksLeftBankedQuarterTurn5TileDown25,
    TrackBlocksRightBankedQuarterTurn5TileDown25,
    TrackBlocksUp25ToLeftBankedUp25,
    TrackBlocksUp25ToRightBankedUp25,
    TrackBlocksLeftBankedUp25ToUp25,
    TrackBlocksRightBankedUp25ToUp25,
    TrackBlocksDown25ToLeftBankedDown25,
    TrackBlocksDown25ToRightBankedDown25,
    TrackBlocksLeftBankedDown25ToDown25,
    TrackBlocksRightBankedDown25ToDown25,
    TrackBlocksLeftBankedFlatToLeftBankedUp25,
    TrackBlocksRightBankedFlatToRightBankedUp25,
    TrackBlocksLeftBankedUp25ToLeftBankedFlat,
    TrackBlocksRightBankedUp25ToRightBankedFlat,
    TrackBlocksLeftBankedFlatToLeftBankedDown25,
    TrackBlocksRightBankedFlatToRightBankedDown25,
    TrackBlocksLeftBankedDown25ToLeftBankedFlat,
    TrackBlocksRightBankedDown25ToRightBankedFlat,
    TrackBlockFlatToLeftBankedUp25,
    TrackBlockFlatToRightBankedUp25,
    TrackBlocksLeftBankedUp25ToFlat,
    TrackBlocksRightBankedUp25ToFlat,
    TrackBlocksFlatToLeftBankedDown25,
    TrackBlocksFlatToRightBankedDown25,
    TrackBlocksLeftBankedDown25ToFlat,
    TrackBlocksRightBankedDown25ToFlat,
    TrackBlocksLeftQuarterTurn1TileUp90,
    TrackBlocksRightQuarterTurn1TileUp90,
    TrackBlocksLeftQuarterTurn1TileDown90,
    TrackBlocksRightQuarterTurn1TileDown90,
    TrackBlocksMultiDimUp90ToInvertedFlatQuarterLoop,
    TrackBlocksMultiDimFlatToDown90QuarterLoop,
    TrackBlocksMultiDimInvertedUp90ToFlatQuarterLoop
};

static constexpr const rct_preview_track FlatRideTrackBlocksLeftQuarterTurn1TileUp60[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -64, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 3, 32, 0, 0, 0, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_1 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track FlatRideTrackBlocksUp25LeftBanked[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 2, 32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 3, 32, 32, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track FlatRideTrackBlocksUp25RightBanked[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 2, 0, 64, 0, 0, { 0b1111, 0 }, 0 },
    { 3, 0, 96, 0, 0, { 0b1111, 0 }, 0 },
    { 4, 32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 5, 32, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 6, 32, 64, 0, 0, { 0b1111, 0 }, 0 },
    { 7, 32, 96, 0, 0, { 0b1111, 0 }, 0 },
    { 8, 64, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 9, 64, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 10, 64, 64, 0, 0, { 0b1111, 0 }, 0 },
    { 11, 64, 96, 0, 0, { 0b1111, 0 }, 0 },
    { 12, 96, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 13, 96, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 14, 96, 64, 0, 0, { 0b1111, 0 }, 0 },
    { 15, 96, 96, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track FlatRideTrackBlocksDown25LeftBanked[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, 0, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 2, 0, 64, 0, 0, { 0b1111, 0 }, 0 },
    { 3, 0, 96, 0, 0, { 0b1111, 0 }, 0 },
    { 4, 32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 5, 32, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 6, 32, 64, 0, 0, { 0b1111, 0 }, 0 },
    { 7, 32, 96, 0, 0, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_1 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track FlatRideTrackBlocksDown25RightBanked[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -64, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 3, 32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 4, 64, 0, 0, 0, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_1 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track FlatRideTrackBlocksFlatToUp60LongBase[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track FlatRideTrackBlocksUp60ToFlatLongBase[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -64, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 3, 32, 0, 0, 0, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_1 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track FlatRideTrackBlocksDown60ToFlatLongBase[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track FlatRideTrackBlocksFlatToDown60LongBase[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -64, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 3, 32, 0, 0, 0, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_1 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track FlatRideTrackBlocksCableLiftHill[] = {
    { 0, 0, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 1, -32, -32, 0, 0, { 0b1111, 0 }, 0 },
    { 2, -32, 0, 0, 0, { 0b1111, 0 }, 0 },
    { 3, -32, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 4, 0, -32, 0, 0, { 0b1111, 0 }, 0 },
    { 5, 0, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 6, 32, -32, 0, 0, { 0b1111, 0 }, 0 },
    { 7, 32, 32, 0, 0, { 0b1111, 0 }, 0 },
    { 8, 32, 0, 0, 0, { 0b1111, 0 }, RCT_PREVIEW_TRACK_FLAG_1 },
    TRACK_BLOCK_END
};

static constexpr const rct_preview_track FlatRideTrackBlocksMultiDimInvertedUp90ToFlatQuarterLoop[] = {
    TRACK_BLOCK_END
};

// rct2: 0x00994A38
const rct_preview_track *FlatRideTrackBlocks[TrackElemType::Count] = {
    TrackBlocksFlat,
    TrackBlocksEndStation,
    TrackBlocksBeginStation,
    TrackBlocksMiddleStation,
    TrackBlocksUp25,
    TrackBlocksUp60,
    TrackBlocksFlatToUp25,
    TrackBlocksUp25ToUp60,
    TrackBlocksUp60ToUp25,
    TrackBlocksUp25ToFlat,
    TrackBlocksDown25,
    TrackBlocksDown60,
    TrackBlocksFlatToDown25,
    TrackBlocksDown25ToDown60,
    TrackBlocksDown60ToDown25,
    TrackBlocksDown25ToFlat,
    TrackBlocksLeftQuarterTurn5Tiles,
    TrackBlocksRightQuarterTurn5Tiles,
    TrackBlocksFlatToLeftBank,
    TrackBlocksFlatToRightBank,
    TrackBlocksLeftBankToFlat,
    TrackBlocksRightBankToFlat,
    TrackBlocksBankedLeftQuarterTurn5Tiles,
    TrackBlocksBankedRightQuarterTurn5Tiles,
    TrackBlocksLeftBankToUp25,
    TrackBlocksRightBankToUp25,
    TrackBlocksUp25ToLeftBank,
    TrackBlocksUp25ToRightBank,
    TrackBlocksLeftBankToDown25,
    TrackBlocksRightBankToDown25,
    TrackBlocksDown25ToLeftBank,
    TrackBlocksDown25ToRightBank,
    TrackBlocksLeftBank,
    TrackBlocksRightBank,
    TrackBlocksLeftQuarterTurn5TilesUp25,
    TrackBlocksRightQuarterTurn5TilesUp25,
    TrackBlocksLeftQuarterTurn5TilesDown25,
    TrackBlocksRightQuarterTurn5TilesDown25,
    TrackBlocksSBendLeft,
    TrackBlocksSBendRight,
    TrackBlocksLeftVerticalLoop,
    TrackBlocksRightVerticalLoop,
    TrackBlocksLeftQuarterTurn3Tiles,
    TrackBlocksRightQuarterTurn3Tiles,
    TrackBlocksLeftBankedQuarterTurn3Tiles,
    TrackBlocksRightBankedQuarterTurn3Tiles,
    TrackBlocksLeftQuarterTurn3TilesUp25,
    TrackBlocksRightQuarterTurn3TilesUp25,
    TrackBlocksLeftQuarterTurn3TilesDown25,
    TrackBlocksRightQuarterTurn3TilesDown25,
    TrackBlocksLeftQuarterTurn1Tile,
    TrackBlocksRightQuarterTurn1Tile,
    TrackBlocksLeftTwistDownToUp,
    TrackBlocksRightTwistDownToUp,
    TrackBlocksLeftTwistUpToDown,
    TrackBlocksRightTwistUpToDown,
    TrackBlocksHalfLoopUp,
    TrackBlocksHalfLoopDown,
    TrackBlocksLeftCorkscrewUp,
    TrackBlocksRightCorkscrewUp,
    TrackBlocksLeftCorkscrewDown,
    TrackBlocksRightCorkscrewDown,
    TrackBlocksFlatToUp60,
    TrackBlocksUp60ToFlat,
    TrackBlocksFlatToDown60,
    TrackBlocksDown60ToFlat,
    TrackBlocksTowerBase,
    TrackBlocksTowerSection,
    TrackBlocksFlatCovered,
    TrackBlocksUp25Covered,
    TrackBlocksUp60Covered,
    TrackBlocksFlatToUp25Covered,
    TrackBlocksUp25ToUp60Covered,
    TrackBlocksUp60ToUp25Covered,
    TrackBlocksUp25ToFlatCovered,
    TrackBlocksDown25Covered,
    TrackBlocksDown60Covered,
    TrackBlocksFlatToDown25Covered,
    TrackBlocksDown25ToDown60Covered,
    TrackBlocksDown60ToDown25Covered,
    TrackBlocksDown25ToFlatCovered,
    TrackBlocksLeftQuarterTurn5TilesCovered,
    TrackBlocksRightQuarterTurn5TilesCovered,
    TrackBlocksSBendLeftCovered,
    TrackBlocksSBendRightCovered,
    TrackBlocksLeftQuarterTurn3TilesCovered,
    TrackBlocksRightQuarterTurn3TilesCovered,
    TrackBlocksLeftHalfBankedHelixUpSmall,
    TrackBlocksRightHalfBankedHelixUpSmall,
    TrackBlocksLeftHalfBankedHelixDownSmall,
    TrackBlocksRightHalfBankedHelixDownSmall,
    TrackBlocksLeftHalfBankedHelixUpLarge,
    TrackBlocksRightHalfBankedHelixUpLarge,
    TrackBlocksLeftHalfBankedHelixDownLarge,
    TrackBlocksRightHalfBankedHelixDownLarge,
    FlatRideTrackBlocksLeftQuarterTurn1TileUp60,
    TrackBlocksRightQuarterTurn1TileUp60,
    TrackBlocksLeftQuarterTurn1TileDown60,
    TrackBlocksLeftRightQuarterTurn1TileDown60,
    TrackBlocksBrakes,
    TrackBlocksRotationControlToggle,
    TrackBlocksMaze,
    TrackBlocksLeftQuarterBankedHelixLargeUp,
    TrackBlocksRightQuarterBankedHelixLargeUp,
    TrackBlocksLeftQuarterBankedHelixLargeDown,
    TrackBlocksRightQuarterBankedHelixLargeDown,
    TrackBlocksLeftQuarterHelixLargeUp,
    TrackBlocksRightQuarterHelixLargeUp,
    TrackBlocksLeftQuarterHelixLargeDown,
    TrackBlocksRightQuarterHelixLargeDown,
    FlatRideTrackBlocksUp25LeftBanked,
    FlatRideTrackBlocksUp25RightBanked,
    TrackBlocksWaterfall,
    TrackBlocksRapids,
    TrackBlocksOnRidePhoto,
    FlatRideTrackBlocksDown25LeftBanked,
    FlatRideTrackBlocksDown25RightBanked,
    TrackBlocksWatersplash,
    FlatRideTrackBlocksFlatToUp60LongBase,
    FlatRideTrackBlocksUp60ToFlatLongBase,
    TrackBlocksWhirlpool,
    FlatRideTrackBlocksDown60ToFlatLongBase,
    FlatRideTrackBlocksFlatToDown60LongBase,
    FlatRideTrackBlocksCableLiftHill,
    TrackBlocksReverseFreefallSlope,
    TrackBlocksReverseFreefallVertical,
    TrackBlocksUp90,
    TrackBlocksDown90,
    TrackBlocksUp60ToUp90,
    TrackBlocksDown90ToDown60,
    TrackBlocksUp90ToUp60,
    TrackBlocksDown60ToDown90,
    TrackBlocksBrakeForDrop,
    TrackBlocksLeftEighthToDiag,
    TrackBlocksRightEighthToDiag,
    TrackBlocksLeftEighthToOrthogonal,
    TrackBlocksRightEighthToOrthogonal,
    TrackBlocksLeftEighthBankToDiag,
    TrackBlocksRightEighthBankToDiag,
    TrackBlocksLeftEighthBankToOrthogonal,
    TrackBlocksRightEighthBankToOrthogonal,
    TrackBlocksDiagFlat,
    TrackBlocksDiagUp25,
    TrackBlocksDiagUp60,
    TrackBlocksDiagFlatToUp25,
    TrackBlocksDiagUp25ToUp60,
    TrackBlocksDiagUp60ToUp25,
    TrackBlocksDiagUp25ToFlat,
    TrackBlocksDiagDown25,
    TrackBlocksDiagDown60,
    TrackBlocksDiagFlatToDown25,
    TrackBlocksDiagDown25ToDown60,
    TrackBlocksDiagDown60ToDown25,
    TrackBlocksDiagDown25ToFlat,
    TrackBlocksDiagFlatToUp60,
    TrackBlocksDiagUp60ToFlat,
    TrackBlocksDiagFlatToDown60,
    TrackBlocksDiagDown60ToFlat,
    TrackBlocksDiagFlatToLeftBank,
    TrackBlocksDiagFlatToRightBank,
    TrackBlocksDiagLeftBankToFlat,
    TrackBlocksDiagRightBankToFlat,
    TrackBlocksDiagLeftBankToUp25,
    TrackBlocksDiagRightBankToUp25,
    TrackBlocksDiagUp25ToLeftBank,
    TrackBlocksDiagUp25ToRightBank,
    TrackBlocksDiagLeftBankToDown25,
    TrackBlocksDiagRightBankToDown25,
    TrackBlocksDiagDown25ToLeftBank,
    TrackBlocksDiagDown25ToRightBank,
    TrackBlocksDiagLeftBank,
    TrackBlocksDiagRightBank,
    TrackBlocksLogFlumeReverser,
    TrackBlocksSpinningTunnel,
    TrackBlocksLeftBarrelRollUpToDown,
    TrackBlocksRightBarrelRollUpToDown,
    TrackBlocksLeftBarrelRollDownToUp,
    TrackBlocksRightBarrelRollDownToUp,
    TrackBlocksLeftBankToLeftQuarterTurn3TilesUp25,
    TrackBlocksRightBankToRightQuarterTurn3TilesUp25,
    TrackBlocksLeftQuarterTurn3TilesDown25ToLeftBank,
    TrackBlocksRightQuarterTurn3TilesDown25ToRightBank,
    TrackBlocksPoweredLift,
    TrackBlocksLeftLargeHalfLoopUp,
    TrackBlocksRightLargeHalfLoopUp,
    TrackBlocksRightLargeHalfLoopDown,
    TrackBlocksLeftLargeHalfLoopDown,
    TrackBlocksLeftFlyerTwistUp,
    TrackBlocksRightFlyerTwistUp,
    TrackBlocksLeftFlyerTwistDown,
    TrackBlocksRightFlyerTwistDown,
    TrackBlocksFlyerHalfLoopUp,
    TrackBlocksFlyerHalfLoopDown,
    TrackBlocksLeftFlyerCorkscrewUp,
    TrackBlocksRightFlyerCorkscrewUp,
    TrackBlocksLeftFlyerCorkscrewDown,
    TrackBlocksRightFlyerCorkscrewDown,
    TrackBlocksHeartLineTransferUp,
    TrackBlocksHeartLineTransferDown,
    TrackBlocksLeftHeartLineRoll,
    TrackBlocksRightHeartLineRoll,
    TrackBlocksMinigolfHoleA,
    TrackBlocksMinigolfHoleB,
    TrackBlocksMinigolfHoleC,
    TrackBlocksMinigolfHoleD,
    TrackBlocksMinigolfHoleE,
    TrackBlocksMultiDimInvertedFlatToDown90QuarterLoop,
    TrackBlocksUp90ToInvertedFlatQuarterLoop,
    TrackBlocksInvertedFlatToDown90QuarterLoop,
    TrackBlocksLeftCurvedLiftHill,
    TrackBlocksRightCurvedLiftHill,
    TrackBlocksLeftReverser,
    TrackBlocksRightReverser,
    TrackBlocksAirThrustTopCap,
    TrackBlocksAirThrustVerticalDown,
    TrackBlocksAirThrustVerticalDownToLevel,
    TrackBlocksBlockBrakes,
    TrackBlocksLeftBankedQuarterTurn3TileUp25,
    TrackBlocksRightBankedQuarterTurn3TileUp25,
    TrackBlocksLeftBankedQuarterTurn3TileDown25,
    TrackBlocksRightBankedQuarterTurn3TileDown25,
    TrackBlocksLeftBankedQuarterTurn5TileUp25,
    TrackBlocksRightBankedQuarterTurn5TileUp25,
    TrackBlocksLeftBankedQuarterTurn5TileDown25,
    TrackBlocksRightBankedQuarterTurn5TileDown25,
    TrackBlocksUp25ToLeftBankedUp25,
    TrackBlocksUp25ToRightBankedUp25,
    TrackBlocksLeftBankedUp25ToUp25,
    TrackBlocksRightBankedUp25ToUp25,
    TrackBlocksDown25ToLeftBankedDown25,
    TrackBlocksDown25ToRightBankedDown25,
    TrackBlocksLeftBankedDown25ToDown25,
    TrackBlocksRightBankedDown25ToDown25,
    TrackBlocksLeftBankedFlatToLeftBankedUp25,
    TrackBlocksRightBankedFlatToRightBankedUp25,
    TrackBlocksLeftBankedUp25ToLeftBankedFlat,
    TrackBlocksRightBankedUp25ToRightBankedFlat,
    TrackBlocksLeftBankedFlatToLeftBankedDown25,
    TrackBlocksRightBankedFlatToRightBankedDown25,
    TrackBlocksLeftBankedDown25ToLeftBankedFlat,
    TrackBlocksRightBankedDown25ToRightBankedFlat,
    TrackBlockFlatToLeftBankedUp25,
    TrackBlockFlatToRightBankedUp25,
    TrackBlocksLeftBankedUp25ToFlat,
    TrackBlocksRightBankedUp25ToFlat,
    TrackBlocksFlatToLeftBankedDown25,
    TrackBlocksFlatToRightBankedDown25,
    TrackBlocksLeftBankedDown25ToFlat,
    TrackBlocksRightBankedDown25ToFlat,
    TrackBlocksLeftQuarterTurn1TileUp90,
    TrackBlocksRightQuarterTurn1TileUp90,
    TrackBlocksLeftQuarterTurn1TileDown90,
    TrackBlocksRightQuarterTurn1TileDown90,
    TrackBlocksMultiDimUp90ToInvertedFlatQuarterLoop,
    TrackBlocksMultiDimFlatToDown90QuarterLoop,
    FlatRideTrackBlocksMultiDimInvertedUp90ToFlatQuarterLoop
};

const uint8_t TrackPieceLengths[TrackElemType::Count] = {
    32,     // TrackElemType::Flat
    32,     // TrackElemType::EndStation
    32,     // TrackElemType::BeginStation
    32,     // TrackElemType::MiddleStation
    33,     // TrackElemType::Up25
    40,     // TrackElemType::Up60
    32,     // TrackElemType::FlatToUp25
    34,     // TrackElemType::Up25ToUp60
    34,     // TrackElemType::Up60ToUp25
    32,     // TrackElemType::Up25ToFlat
    33,     // TrackElemType::Down25
    40,     // TrackElemType::Down60
    32,     // TrackElemType::FlatToDown25
    34,     // TrackElemType::Down25ToDown60
    34,     // TrackElemType::Down60ToDown25
    32,     // TrackElemType::Down25ToFlat
    124,    // TrackElemType::LeftQuarterTurn5Tiles
    124,    // TrackElemType::RightQuarterTurn5Tiles
    32,     // TrackElemType::FlatToLeftBank
    32,     // TrackElemType::FlatToRightBank
    32,     // TrackElemType::LeftBankToFlat
    32,     // TrackElemType::RightBankToFlat
    124,    // TrackElemType::BankedLeftQuarterTurn5Tiles
    124,    // TrackElemType::BankedRightQuarterTurn5Tiles
    32,     // TrackElemType::LeftBankToUp25
    32,     // TrackElemType::RightBankToUp25
    32,     // TrackElemType::Up25ToLeftBank
    32,     // TrackElemType::Up25ToRightBank
    32,     // TrackElemType::LeftBankToDown25
    32,     // TrackElemType::RightBankToDown25
    32,     // TrackElemType::Down25ToLeftBank
    32,     // TrackElemType::Down25ToRightBank
    32,     // TrackElemType::LeftBank
    32,     // TrackElemType::RightBank
    130,    // TrackElemType::LeftQuarterTurn5TilesUp25
    130,    // TrackElemType::RightQuarterTurn5TilesUp25
    130,    // TrackElemType::LeftQuarterTurn5TilesDown25
    130,    // TrackElemType::RightQuarterTurn5TilesDown25
    96,     // TrackElemType::SBendLeft
    96,     // TrackElemType::SBendRight
    120,    // TrackElemType::LeftVerticalLoop
    120,    // TrackElemType::RightVerticalLoop
    75,     // TrackElemType::LeftQuarterTurn3Tiles
    75,     // TrackElemType::RightQuarterTurn3Tiles
    75,     // TrackElemType::LeftBankedQuarterTurn3Tiles
    75,     // TrackElemType::RightBankedQuarterTurn3Tiles
    77,     // TrackElemType::LeftQuarterTurn3TilesUp25
    77,     // TrackElemType::RightQuarterTurn3TilesUp25
    77,     // TrackElemType::LeftQuarterTurn3TilesDown25
    77,     // TrackElemType::RightQuarterTurn3TilesDown25
    24,     // TrackElemType::LeftQuarterTurn1Tile
    24,     // TrackElemType::RightQuarterTurn1Tile
    96,     // TrackElemType::LeftTwistDownToUp
    96,     // TrackElemType::RightTwistDownToUp
    96,     // TrackElemType::LeftTwistUpToDown
    96,     // TrackElemType::RightTwistUpToDown
    60,     // TrackElemType::HalfLoopUp
    60,     // TrackElemType::HalfLoopDown
    55,     // TrackElemType::LeftCorkscrewUp
    55,     // TrackElemType::RightCorkscrewUp
    55,     // TrackElemType::LeftCorkscrewDown
    55,     // TrackElemType::RightCorkscrewDown
    36,     // TrackElemType::FlatToUp60
    36,     // TrackElemType::Up60ToFlat
    36,     // TrackElemType::FlatToDown60
    36,     // TrackElemType::Down60ToFlat
    32,     // TrackElemType::TowerBase
    32,     // TrackElemType::TowerSection
    32,     // TrackElemType::FlatCovered
    33,     // TrackElemType::Up25Covered
    40,     // TrackElemType::Up60Covered
    32,     // TrackElemType::FlatToUp25Covered
    34,     // TrackElemType::Up25ToUp60Covered
    34,     // TrackElemType::Up60ToUp25Covered
    32,     // TrackElemType::Up25ToFlatCovered
    33,     // TrackElemType::Down25Covered
    40,     // TrackElemType::Down60Covered
    32,     // TrackElemType::FlatToDown25Covered
    34,     // TrackElemType::Down25ToDown60Covered
    34,     // TrackElemType::Down60ToDown25Covered
    32,     // TrackElemType::Down25ToFlatCovered
    124,    // TrackElemType::LeftQuarterTurn5TilesCovered
    124,    // TrackElemType::RightQuarterTurn5TilesCovered
    96,     // TrackElemType::SBendLeftCovered
    96,     // TrackElemType::SBendRightCovered
    75,     // TrackElemType::LeftQuarterTurn3TilesCovered
    75,     // TrackElemType::RightQuarterTurn3TilesCovered
    150,    // TrackElemType::LeftHalfBankedHelixUpSmall
    150,    // TrackElemType::RightHalfBankedHelixUpSmall
    150,    // TrackElemType::LeftHalfBankedHelixDownSmall
    150,    // TrackElemType::RightHalfBankedHelixDownSmall
    248,    // TrackElemType::LeftHalfBankedHelixUpLarge
    248,    // TrackElemType::RightHalfBankedHelixUpLarge
    248,    // TrackElemType::LeftHalfBankedHelixDownLarge
    248,    // TrackElemType::RightHalfBankedHelixDownLarge
    64,     // TrackElemType::LeftQuarterTurn1TileUp60
    64,     // TrackElemType::RightQuarterTurn1TileUp60
    64,     // TrackElemType::LeftQuarterTurn1TileDown60
    64,     // TrackElemType::RightQuarterTurn1TileDown60
    32,     // TrackElemType::Brakes
    32,     // TrackElemType::RotationControlToggle
    32,     // TrackElemType::InvertedUp90ToFlatQuarterLoopAlias / Maze
    124,    // TrackElemType::LeftQuarterBankedHelixLargeUp
    124,    // TrackElemType::RightQuarterBankedHelixLargeUp
    124,    // TrackElemType::LeftQuarterBankedHelixLargeDown
    124,    // TrackElemType::RightQuarterBankedHelixLargeDown
    124,    // TrackElemType::LeftQuarterHelixLargeUp
    124,    // TrackElemType::RightQuarterHelixLargeUp
    124,    // TrackElemType::LeftQuarterHelixLargeDown
    124,    // TrackElemType::RightQuarterHelixLargeDown
    33,     // TrackElemType::Up25LeftBanked
    33,     // TrackElemType::Up25RightBanked
    32,     // TrackElemType::Waterfall
    32,     // TrackElemType::Rapids
    32,     // TrackElemType::OnRidePhoto
    33,     // TrackElemType::Down25LeftBanked
    33,     // TrackElemType::Down25RightBanked
    128,    // TrackElemType::Watersplash
    165,    // TrackElemType::FlatToUp60LongBase
    165,    // TrackElemType::Up60ToFlatLongBase
    32,     // TrackElemType::Whirlpool
    165,    // TrackElemType::Down60ToFlatLongBase
    165,    // TrackElemType::FlatToDown60LongBase
    138,    // TrackElemType::CableLiftHill
    32,     // TrackElemType::ReverseFreefallSlope
    32,     // TrackElemType::ReverseFreefallVertical
    32,     // TrackElemType::Up90
    32,     // TrackElemType::Down90
    32,     // TrackElemType::Up60ToUp90
    32,     // TrackElemType::Down90ToDown60
    32,     // TrackElemType::Up90ToUp60
    32,     // TrackElemType::Down60ToDown90
    32,     // TrackElemType::BrakeForDrop
    87,     // TrackElemType::LeftEighthToDiag
    87,     // TrackElemType::RightEighthToDiag
    87,     // TrackElemType::LeftEighthToOrthogonal
    87,     // TrackElemType::RightEighthToOrthogonal
    87,     // TrackElemType::LeftEighthBankToDiag
    87,     // TrackElemType::RightEighthBankToDiag
    87,     // TrackElemType::LeftEighthBankToOrthogonal
    87,     // TrackElemType::RightEighthBankToOrthogonal
    45,     // TrackElemType::DiagFlat
    45,     // TrackElemType::DiagUp25
    45,     // TrackElemType::DiagUp60
    45,     // TrackElemType::DiagFlatToUp25
    45,     // TrackElemType::DiagUp25ToUp60
    45,     // TrackElemType::DiagUp60ToUp25
    45,     // TrackElemType::DiagUp25ToFlat
    45,     // TrackElemType::DiagDown25
    45,     // TrackElemType::DiagDown60
    45,     // TrackElemType::DiagFlatToDown25
    45,     // TrackElemType::DiagDown25ToDown60
    45,     // TrackElemType::DiagDown60ToDown25
    45,     // TrackElemType::DiagDown25ToFlat
    45,     // TrackElemType::DiagFlatToUp60
    45,     // TrackElemType::DiagUp60ToFlat
    45,     // TrackElemType::DiagFlatToDown60
    45,     // TrackElemType::DiagDown60ToFlat
    45,     // TrackElemType::DiagFlatToLeftBank
    45,     // TrackElemType::DiagFlatToRightBank
    45,     // TrackElemType::DiagLeftBankToFlat
    45,     // TrackElemType::DiagRightBankToFlat
    45,     // TrackElemType::DiagLeftBankToUp25
    45,     // TrackElemType::DiagRightBankToUp25
    45,     // TrackElemType::DiagUp25ToLeftBank
    45,     // TrackElemType::DiagUp25ToRightBank
    45,     // TrackElemType::DiagLeftBankToDown25
    45,     // TrackElemType::DiagRightBankToDown25
    45,     // TrackElemType::DiagDown25ToLeftBank
    45,     // TrackElemType::DiagDown25ToRightBank
    45,     // TrackElemType::DiagLeftBank
    45,     // TrackElemType::DiagRightBank
    16,     // TrackElemType::LogFlumeReverser
    32,     // TrackElemType::SpinningTunnel
    96,     // TrackElemType::LeftBarrelRollUpToDown
    96,     // TrackElemType::RightBarrelRollUpToDown
    96,     // TrackElemType::LeftBarrelRollDownToUp
    96,     // TrackElemType::RightBarrelRollDownToUp
    64,     // TrackElemType::LeftBankToLeftQuarterTurn3TilesUp25
    64,     // TrackElemType::RightBankToRightQuarterTurn3TilesUp25
    64,     // TrackElemType::LeftQuarterTurn3TilesDown25ToLeftBank
    64,     // TrackElemType::RightQuarterTurn3TilesDown25ToRightBank
    32,     // TrackElemType::PoweredLift
    100,    // TrackElemType::LeftLargeHalfLoopUp
    100,    // TrackElemType::RightLargeHalfLoopUp
    100,    // TrackElemType::RightLargeHalfLoopDown
    100,    // TrackElemType::LeftLargeHalfLoopDown
    96,     // TrackElemType::LeftFlyerTwistUp
    96,     // TrackElemType::RightFlyerTwistUp
    96,     // TrackElemType::LeftFlyerTwistDown
    96,     // TrackElemType::RightFlyerTwistDown
    64,     // TrackElemType::FlyerHalfLoopUp
    64,     // TrackElemType::FlyerHalfLoopDown
    64,     // TrackElemType::LeftFlyerCorkscrewUp
    64,     // TrackElemType::RightFlyerCorkscrewUp
    64,     // TrackElemType::LeftFlyerCorkscrewDown
    64,     // TrackElemType::RightFlyerCorkscrewDown
    16,     // TrackElemType::HeartLineTransferUp
    16,     // TrackElemType::HeartLineTransferDown
    64,     // TrackElemType::LeftHeartLineRoll
    64,     // TrackElemType::RightHeartLineRoll
    32,     // TrackElemType::MinigolfHoleA
    32,     // TrackElemType::MinigolfHoleB
    32,     // TrackElemType::MinigolfHoleC
    32,     // TrackElemType::MinigolfHoleD
    32,     // TrackElemType::MinigolfHoleE
    80,     // TrackElemType::MultiDimInvertedFlatToDown90QuarterLoop
    80,     // TrackElemType::Up90ToInvertedFlatQuarterLoop
    80,     // TrackElemType::InvertedFlatToDown90QuarterLoop
    64,     // TrackElemType::LeftCurvedLiftHill
    64,     // TrackElemType::RightCurvedLiftHill
    32,     // TrackElemType::LeftReverser
    32,     // TrackElemType::RightReverser
    32,     // TrackElemType::AirThrustTopCap
    32,     // TrackElemType::AirThrustVerticalDown
    32,     // TrackElemType::AirThrustVerticalDownToLevel
    32,     // TrackElemType::BlockBrakes
    32,     // TrackElemType::LeftBankedQuarterTurn3TileUp25
    32,     // TrackElemType::RightBankedQuarterTurn3TileUp25
    32,     // TrackElemType::LeftBankedQuarterTurn3TileDown25
    32,     // TrackElemType::RightBankedQuarterTurn3TileDown25
    32,     // TrackElemType::LeftBankedQuarterTurn5TileUp25
    32,     // TrackElemType::RightBankedQuarterTurn5TileUp25
    32,     // TrackElemType::LeftBankedQuarterTurn5TileDown25
    32,     // TrackElemType::RightBankedQuarterTurn5TileDown25
    32,     // TrackElemType::Up25ToLeftBankedUp25
    32,     // TrackElemType::Up25ToRightBankedUp25
    32,     // TrackElemType::LeftBankedUp25ToUp25
    32,     // TrackElemType::RightBankedUp25ToUp25
    32,     // TrackElemType::Down25ToLeftBankedDown25
    32,     // TrackElemType::Down25ToRightBankedDown25
    32,     // TrackElemType::LeftBankedDown25ToDown25
    32,     // TrackElemType::RightBankedDown25ToDown25
    32,     // TrackElemType::LeftBankedFlatToLeftBankedUp25
    32,     // TrackElemType::RightBankedFlatToRightBankedUp25
    32,     // TrackElemType::LeftBankedUp25ToLeftBankedFlat
    32,     // TrackElemType::RightBankedUp25ToRightBankedFlat
    32,     // TrackElemType::LeftBankedFlatToLeftBankedDown25
    32,     // TrackElemType::RightBankedFlatToRightBankedDown25
    32,     // TrackElemType::LeftBankedDown25ToLeftBankedFlat
    32,     // TrackElemType::RightBankedDown25ToRightBankedFlat
    32,     // TrackElemType::FlatToLeftBankedUp25
    32,     // TrackElemType::FlatToRightBankedUp25
    32,     // TrackElemType::LeftBankedUp25ToFlat
    32,     // TrackElemType::RightBankedUp25ToFlat
    32,     // TrackElemType::FlatToLeftBankedDown25
    32,     // TrackElemType::FlatToRightBankedDown25
    32,     // TrackElemType::LeftBankedDown25ToFlat
    32,     // TrackElemType::RightBankedDown25ToFlat
    32,     // TrackElemType::LeftQuarterTurn1TileUp90
    32,     // TrackElemType::RightQuarterTurn1TileUp90
    32,     // TrackElemType::LeftQuarterTurn1TileDown90
    32,     // TrackElemType::RightQuarterTurn1TileDown90
    80,     // TrackElemType::MultiDimUp90ToInvertedFlatQuarterLoop
    80,     // TrackElemType::MultiDimFlatToDown90QuarterLoop
    80,     // TrackElemType::MultiDimInvertedUp90ToFlatQuarterLoop
};

// rct2: 0x00998C95
const track_curve_chain gTrackCurveChain[TrackElemType::Count] = {
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::EndStation, RideConstructionSpecialPieceSelected | TrackElemType::EndStation },
    { RideConstructionSpecialPieceSelected | TrackElemType::EndStation, RideConstructionSpecialPieceSelected | TrackElemType::EndStation },
    { RideConstructionSpecialPieceSelected | TrackElemType::EndStation, RideConstructionSpecialPieceSelected | TrackElemType::EndStation },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_NONE },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_LEFT },
    { TRACK_CURVE_NONE, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_NONE, TRACK_CURVE_LEFT },
    { TRACK_CURVE_NONE, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_NONE },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_LEFT },
    { TRACK_CURVE_NONE, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_NONE },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_NONE },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { TRACK_CURVE_LEFT_VERY_SMALL, TRACK_CURVE_LEFT_VERY_SMALL },
    { TRACK_CURVE_RIGHT_VERY_SMALL, TRACK_CURVE_RIGHT_VERY_SMALL },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftTwistUpToDown, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightTwistUpToDown, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, RideConstructionSpecialPieceSelected | TrackElemType::LeftTwistDownToUp },
    { TRACK_CURVE_NONE, RideConstructionSpecialPieceSelected | TrackElemType::RightTwistDownToUp },
    { RideConstructionSpecialPieceSelected | TrackElemType::HalfLoopDown, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, RideConstructionSpecialPieceSelected | TrackElemType::HalfLoopUp },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightCorkscrewDown, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftCorkscrewDown, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, RideConstructionSpecialPieceSelected | TrackElemType::RightCorkscrewUp },
    { TRACK_CURVE_NONE, RideConstructionSpecialPieceSelected | TrackElemType::LeftCorkscrewUp },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::TowerSection, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::TowerSection, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftHalfBankedHelixUpSmall, RideConstructionSpecialPieceSelected | TrackElemType::LeftHalfBankedHelixUpSmall },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightHalfBankedHelixUpSmall, RideConstructionSpecialPieceSelected | TrackElemType::RightHalfBankedHelixUpSmall },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftHalfBankedHelixDownSmall, RideConstructionSpecialPieceSelected | TrackElemType::LeftHalfBankedHelixDownSmall },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightHalfBankedHelixDownSmall, RideConstructionSpecialPieceSelected | TrackElemType::RightHalfBankedHelixDownSmall },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftHalfBankedHelixUpLarge, RideConstructionSpecialPieceSelected | TrackElemType::LeftHalfBankedHelixUpLarge },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightHalfBankedHelixUpLarge, RideConstructionSpecialPieceSelected | TrackElemType::RightHalfBankedHelixUpLarge },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftHalfBankedHelixDownLarge, RideConstructionSpecialPieceSelected | TrackElemType::LeftHalfBankedHelixDownLarge },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightHalfBankedHelixDownLarge, RideConstructionSpecialPieceSelected | TrackElemType::RightHalfBankedHelixDownLarge },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { RideConstructionSpecialPieceSelected | TrackElemType::Brakes, RideConstructionSpecialPieceSelected | TrackElemType::Brakes },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftQuarterBankedHelixLargeUp, RideConstructionSpecialPieceSelected | TrackElemType::LeftQuarterBankedHelixLargeUp },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightQuarterBankedHelixLargeUp, RideConstructionSpecialPieceSelected | TrackElemType::RightQuarterBankedHelixLargeUp },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftQuarterBankedHelixLargeDown, RideConstructionSpecialPieceSelected | TrackElemType::LeftQuarterBankedHelixLargeDown },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightQuarterBankedHelixLargeDown, RideConstructionSpecialPieceSelected | TrackElemType::RightQuarterBankedHelixLargeDown },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftQuarterHelixLargeUp, RideConstructionSpecialPieceSelected | TrackElemType::LeftQuarterHelixLargeUp },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightQuarterHelixLargeUp, RideConstructionSpecialPieceSelected | TrackElemType::RightQuarterHelixLargeUp },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftQuarterHelixLargeDown, RideConstructionSpecialPieceSelected | TrackElemType::LeftQuarterHelixLargeDown },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightQuarterHelixLargeDown, RideConstructionSpecialPieceSelected | TrackElemType::RightQuarterHelixLargeDown },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { RideConstructionSpecialPieceSelected | TrackElemType::Waterfall, RideConstructionSpecialPieceSelected | TrackElemType::Waterfall },
    { RideConstructionSpecialPieceSelected | TrackElemType::Rapids, RideConstructionSpecialPieceSelected | TrackElemType::Rapids },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::ReverseFreefallVertical, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::ReverseFreefallVertical, RideConstructionSpecialPieceSelected | TrackElemType::ReverseFreefallVertical },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_LEFT_LARGE, TRACK_CURVE_LEFT_LARGE },
    { TRACK_CURVE_RIGHT_LARGE, TRACK_CURVE_RIGHT_LARGE },
    { TRACK_CURVE_LEFT_LARGE, TRACK_CURVE_LEFT_LARGE },
    { TRACK_CURVE_RIGHT_LARGE, TRACK_CURVE_RIGHT_LARGE },
    { TRACK_CURVE_LEFT_LARGE, TRACK_CURVE_LEFT_LARGE },
    { TRACK_CURVE_RIGHT_LARGE, TRACK_CURVE_RIGHT_LARGE },
    { TRACK_CURVE_LEFT_LARGE, TRACK_CURVE_LEFT_LARGE },
    { TRACK_CURVE_RIGHT_LARGE, TRACK_CURVE_RIGHT_LARGE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_LEFT_LARGE, TRACK_CURVE_NONE },
    { TRACK_CURVE_RIGHT_LARGE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_LEFT_LARGE },
    { TRACK_CURVE_NONE, TRACK_CURVE_RIGHT_LARGE },
    { TRACK_CURVE_NONE, TRACK_CURVE_LEFT_LARGE },
    { TRACK_CURVE_NONE, TRACK_CURVE_RIGHT_LARGE },
    { TRACK_CURVE_LEFT_LARGE, TRACK_CURVE_NONE },
    { TRACK_CURVE_RIGHT_LARGE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_LEFT_LARGE },
    { TRACK_CURVE_NONE, TRACK_CURVE_RIGHT_LARGE },
    { TRACK_CURVE_LEFT_LARGE, TRACK_CURVE_NONE },
    { TRACK_CURVE_RIGHT_LARGE, TRACK_CURVE_NONE },
    { TRACK_CURVE_LEFT_LARGE, TRACK_CURVE_LEFT_LARGE },
    { TRACK_CURVE_RIGHT_LARGE, TRACK_CURVE_RIGHT_LARGE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftBarrelRollDownToUp, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightBarrelRollDownToUp, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, RideConstructionSpecialPieceSelected | TrackElemType::LeftBarrelRollUpToDown },
    { TRACK_CURVE_NONE, RideConstructionSpecialPieceSelected | TrackElemType::RightBarrelRollUpToDown },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { RideConstructionSpecialPieceSelected | TrackElemType::PoweredLift, RideConstructionSpecialPieceSelected | TrackElemType::PoweredLift },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftLargeHalfLoopDown, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightLargeHalfLoopDown, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, RideConstructionSpecialPieceSelected | TrackElemType::RightLargeHalfLoopUp },
    { TRACK_CURVE_NONE, RideConstructionSpecialPieceSelected | TrackElemType::LeftLargeHalfLoopUp },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::InvertedFlatToDown90QuarterLoop, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, RideConstructionSpecialPieceSelected | TrackElemType::Up90ToInvertedFlatQuarterLoop },
    { RideConstructionSpecialPieceSelected | TrackElemType::LeftCurvedLiftHill, RideConstructionSpecialPieceSelected | TrackElemType::LeftCurvedLiftHill },
    { RideConstructionSpecialPieceSelected | TrackElemType::RightCurvedLiftHill, RideConstructionSpecialPieceSelected | TrackElemType::RightCurvedLiftHill },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { RideConstructionSpecialPieceSelected | TrackElemType::AirThrustVerticalDown, RideConstructionSpecialPieceSelected | TrackElemType::ReverseFreefallVertical },
    { RideConstructionSpecialPieceSelected | TrackElemType::AirThrustVerticalDown, RideConstructionSpecialPieceSelected | TrackElemType::AirThrustVerticalDown },
    { TRACK_CURVE_NONE, RideConstructionSpecialPieceSelected | TrackElemType::AirThrustVerticalDown },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_NONE },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_LEFT },
    { TRACK_CURVE_NONE, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_NONE },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_LEFT },
    { TRACK_CURVE_NONE, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_LEFT },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_NONE },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_LEFT },
    { TRACK_CURVE_NONE, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT, TRACK_CURVE_NONE },
    { TRACK_CURVE_RIGHT, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_LEFT },
    { TRACK_CURVE_NONE, TRACK_CURVE_RIGHT },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { TRACK_CURVE_LEFT_SMALL, TRACK_CURVE_LEFT_SMALL },
    { TRACK_CURVE_RIGHT_SMALL, TRACK_CURVE_RIGHT_SMALL },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
    { TRACK_CURVE_NONE, TRACK_CURVE_NONE },
};

// rct2: 0x00999095
const track_curve_chain gFlatRideTrackCurveChain[TrackElemType::Count] = {
    { 0, 0 },
    { 257, 257 },
    { 257, 257 },
    { 257, 257 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 1, 1 },
    { 2, 2 },
    { 1, 0 },
    { 2, 0 },
    { 0, 1 },
    { 0, 2 },
    { 1, 1 },
    { 2, 2 },
    { 0, 1 },
    { 0, 2 },
    { 1, 0 },
    { 2, 0 },
    { 0, 1 },
    { 0, 2 },
    { 1, 0 },
    { 2, 0 },
    { 1, 1 },
    { 2, 2 },
    { 1, 1 },
    { 2, 2 },
    { 1, 1 },
    { 2, 2 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 3, 3 },
    { 4, 4 },
    { 3, 3 },
    { 4, 4 },
    { 3, 3 },
    { 4, 4 },
    { 3, 3 },
    { 4, 4 },
    { 5, 5 },
    { 6, 6 },
    { 310, 0 },
    { 311, 0 },
    { 0, 308 },
    { 0, 309 },
    { 313, 0 },
    { 0, 312 },
    { 317, 0 },
    { 316, 0 },
    { 0, 315 },
    { 0, 314 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 323, 0 },
    { 323, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 1, 1 },
    { 2, 2 },
    { 0, 0 },
    { 0, 0 },
    { 3, 3 },
    { 4, 4 },
    { 343, 343 },
    { 344, 344 },
    { 345, 345 },
    { 346, 346 },
    { 347, 347 },
    { 348, 348 },
    { 349, 349 },
    { 350, 350 },
    { 65535, 65535 },
    { 4, 4 },
    { 3, 3 },
    { 4, 4 },
    { 355, 355 },
    { 0, 0 },
    { 0, 0 },
    { 358, 358 },
    { 359, 359 },
    { 360, 360 },
    { 361, 361 },
    { 362, 362 },
    { 363, 363 },
    { 364, 364 },
    { 365, 365 },
    { 65535, 65535 },
    { 65535, 65535 },
    { 368, 368 },
    { 369, 369 },
    { 0, 0 },
    { 65535, 65535 },
    { 65535, 65535 },
    { 0, 0 },
    { 65535, 65535 },
    { 65535, 65535 },
    { 0, 0 },
    { 65535, 65535 },
    { 65535, 65535 },
    { 65535, 65535 },
    { 381, 0 },
    { 381, 381 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 7, 7 },
    { 8, 8 },
    { 7, 7 },
    { 8, 8 },
    { 7, 7 },
    { 8, 8 },
    { 7, 7 },
    { 8, 8 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 7, 0 },
    { 8, 0 },
    { 0, 7 },
    { 0, 8 },
    { 0, 7 },
    { 0, 8 },
    { 7, 0 },
    { 8, 0 },
    { 0, 7 },
    { 0, 8 },
    { 7, 0 },
    { 8, 0 },
    { 7, 7 },
    { 8, 8 },
    { 0, 0 },
    { 0, 0 },
    { 432, 0 },
    { 433, 0 },
    { 0, 430 },
    { 0, 431 },
    { 3, 3 },
    { 4, 4 },
    { 3, 3 },
    { 4, 4 },
    { 438, 190 },
    { 442, 0 },
    { 441, 0 },
    { 0, 440 },
    { 0, 439 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 465, 465 },
    { 466, 466 },
    { 0, 0 },
    { 0, 0 },
    { 470, 381 },
    { 470, 470 },
    { 0, 470 },
    { 0, 0 },
    { 3, 3 },
    { 4, 4 },
    { 3, 3 },
    { 4, 4 },
    { 1, 1 },
    { 2, 2 },
    { 1, 1 },
    { 2, 2 },
    { 1, 0 },
    { 2, 0 },
    { 0, 1 },
    { 0, 1 },
    { 1, 0 },
    { 2, 0 },
    { 0, 1 },
    { 0, 2 },
    { 1, 1 },
    { 2, 2 },
    { 1, 1 },
    { 2, 2 },
    { 1, 1 },
    { 2, 2 },
    { 1, 1 },
    { 2, 2 },
    { 1, 0 },
    { 2, 0 },
    { 0, 1 },
    { 0, 2 },
    { 1, 0 },
    { 2, 0 },
    { 0, 1 },
    { 0, 2 },
    { 3, 3 },
    { 4, 4 },
    { 3, 3 },
    { 4, 4 },
    { 0, 0 },
    { 0, 0 },
    { 0, 57088 },
};

const track_descriptor gTrackDescriptors[142] = {
    {   true,   TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TrackElemType::DiagDown60                                     },
    {   true,   TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::DiagDown60ToDown25                      },
    {   true,   TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::DiagDown60ToFlat                             },
    {   true,   TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TrackElemType::DiagDown25ToDown60                      },
    {   true,   TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::DiagDown25                                     },
    {   true,   TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::DiagDown25ToLeftBank                        },
    {   true,   TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::DiagDown25ToFlat                             },
    {   true,   TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::DiagDown25ToRightBank                       },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_LEFT_LARGE,         TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::LeftEighthBankToOrthogonal                       },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::DiagLeftBankToDown25                        },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::DiagLeftBank                                       },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::DiagLeftBankToFlat                               },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::DiagLeftBankToUp25                          },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_LEFT_LARGE,         TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::LeftEighthToOrthogonal                            },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TrackElemType::DiagFlatToDown60                             },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::DiagFlatToDown25                             },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::DiagFlatToLeftBank                               },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::DiagFlat                                            },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::DiagFlatToRightBank                              },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::DiagFlatToUp25                               },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TrackElemType::DiagFlatToUp60                               },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_RIGHT_LARGE,        TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::RightEighthToOrthogonal                           },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::DiagRightBankToDown25                       },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::DiagRightBankToFlat                              },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::DiagRightBank                                      },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::DiagRightBankToUp25                         },
    {   true,   TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_RIGHT_LARGE,        TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::RightEighthBankToOrthogonal                      },
    {   true,   TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::DiagUp25ToLeftBank                          },
    {   true,   TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::DiagUp25ToFlat                               },
    {   true,   TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::DiagUp25ToRightBank                         },
    {   true,   TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::DiagUp25                                       },
    {   true,   TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TrackElemType::DiagUp25ToUp60                          },
    {   true,   TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::DiagUp60ToFlat                               },
    {   true,   TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::DiagUp60ToUp25                          },
    {   true,   TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TrackElemType::DiagUp60                                       },
    {   false,  TRACK_SLOPE_DOWN_90,    TRACK_BANK_NONE,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_DOWN_90,    TRACK_BANK_NONE,    TrackElemType::LeftQuarterTurn1TileDown90                 },
    {   false,  TRACK_SLOPE_DOWN_90,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_90,    TRACK_BANK_NONE,    TrackElemType::Down90                                          },
    {   false,  TRACK_SLOPE_DOWN_90,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TrackElemType::Down90ToDown60                           },
    {   false,  TRACK_SLOPE_DOWN_90,    TRACK_BANK_NONE,    TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_DOWN_90,    TRACK_BANK_NONE,    TrackElemType::RightQuarterTurn1TileDown90                },
    {   false,  TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TrackElemType::LeftQuarterTurn1TileDown60                 },
    {   false,  TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_90,    TRACK_BANK_NONE,    TrackElemType::Down60ToDown90                           },
    {   false,  TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TrackElemType::Down60                                          },
    {   false,  TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::Down60ToDown25                           },
    {   false,  TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::Down60ToFlat                                  },
    {   false,  TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TrackElemType::RightQuarterTurn1TileDown60                },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TrackElemType::LeftBankedQuarterTurn3TileDown25          },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TRACK_CURVE_LEFT,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TrackElemType::LeftBankedQuarterTurn5TileDown25          },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TrackElemType::Down25LeftBanked                              },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::LeftBankedDown25ToDown25               },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::LeftBankedDown25ToLeftBankedFlat          },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::LeftBankedDown25ToFlat                      },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::LeftQuarterTurn3TilesDown25                },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::LeftQuarterTurn3TilesDown25ToLeftBank   },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_LEFT,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::LeftQuarterTurn5TilesDown25                },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TrackElemType::Down25ToDown60                           },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TrackElemType::Down25ToLeftBankedDown25               },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::Down25                                          },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TrackElemType::Down25ToRightBankedDown25              },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::Down25ToLeftBank                             },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::Down25ToFlat                                  },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::Down25ToRightBank                            },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_RIGHT,              TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::RightQuarterTurn5TilesDown25               },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::RightQuarterTurn3TilesDown25ToRightBank },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::RightQuarterTurn3TilesDown25               },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::RightBankedDown25ToDown25              },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TrackElemType::Down25RightBanked                             },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::RightBankedDown25ToFlat                     },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::RightBankedDown25ToRightBankedFlat        },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TRACK_CURVE_RIGHT,              TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TrackElemType::RightBankedQuarterTurn5TileDown25         },
    {   false,  TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TrackElemType::RightBankedQuarterTurn3TileDown25         },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::LeftBankedQuarterTurn3Tiles                       },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::LeftBankToLeftQuarterTurn3TilesUp25     },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_LEFT,               TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::BankedLeftQuarterTurn5Tiles                     },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_LEFT_LARGE,         TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::LeftEighthBankToDiag                             },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TrackElemType::LeftBankedFlatToLeftBankedDown25          },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::LeftBankToDown25                             },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::LeftBank                                            },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::LeftBankToFlat                                    },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TrackElemType::LeftBankedFlatToLeftBankedUp25            },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::LeftBankToUp25                               },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::LeftQuarterTurn3Tiles                            },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_LEFT,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::LeftQuarterTurn5Tiles                            },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_LEFT_LARGE,         TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::LeftEighthToDiag                                  },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_60,    TRACK_BANK_NONE,    TrackElemType::FlatToDown60                                  },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_LEFT,    TrackElemType::FlatToLeftBankedDown25                      },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::FlatToDown25                                  },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TrackElemType::FlatToRightBankedDown25                     },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::FlatToLeftBank                                    },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::Flat                                                 },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_LEFT_VERY_SMALL,    TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::LeftQuarterTurn1Tile                             },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_RIGHT_VERY_SMALL,   TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::RightQuarterTurn1Tile                            },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::FlatToRightBank                                   },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TrackElemType::FlatToLeftBankedUp25                        },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::FlatToUp25                                    },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TrackElemType::FlatToRightBankedUp25                       },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TrackElemType::FlatToUp60                                    },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_RIGHT_LARGE,        TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::RightEighthToDiag                                 },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_RIGHT,              TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::RightQuarterTurn5Tiles                           },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::RightQuarterTurn3Tiles                           },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_NONE,    TrackElemType::RightBankToDown25                            },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_DOWN_25,    TRACK_BANK_RIGHT,   TrackElemType::RightBankedFlatToRightBankedDown25        },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::RightBankToFlat                                   },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::RightBank                                           },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::RightBankToUp25                              },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TrackElemType::RightBankedFlatToRightBankedUp25          },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_RIGHT_LARGE,        TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::RightEighthBankToDiag                            },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_RIGHT,              TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::BankedRightQuarterTurn5Tiles                    },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::RightBankedQuarterTurn3Tiles                      },
    {   false,  TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::RightBankToRightQuarterTurn3TilesUp25   },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TrackElemType::LeftBankedQuarterTurn3TileUp25            },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TRACK_CURVE_LEFT,               TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TrackElemType::LeftBankedQuarterTurn5TileUp25            },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::LeftBankedUp25ToLeftBankedFlat            },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::LeftBankedUp25ToFlat                        },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TrackElemType::Up25LeftBanked                                },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::LeftBankedUp25ToUp25                   },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::LeftQuarterTurn3TilesUp25                  },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_LEFT,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::LeftQuarterTurn5TilesUp25                  },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_LEFT,    TrackElemType::Up25ToLeftBank                               },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::Up25ToFlat                                    },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::Up25ToRightBank                              },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_LEFT,    TrackElemType::Up25ToLeftBankedUp25                   },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::Up25                                            },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TrackElemType::Up25ToRightBankedUp25                  },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TrackElemType::Up25ToUp60                               },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_RIGHT,              TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::RightQuarterTurn5TilesUp25                 },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::RightQuarterTurn3TilesUp25                 },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::RightBankedUp25ToFlat                       },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_RIGHT,   TrackElemType::RightBankedUp25ToRightBankedFlat          },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::RightBankedUp25ToUp25                  },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TrackElemType::Up25RightBanked                               },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TRACK_CURVE_RIGHT,              TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TrackElemType::RightBankedQuarterTurn5TileUp25           },
    {   false,  TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_UP_25,      TRACK_BANK_RIGHT,   TrackElemType::RightBankedQuarterTurn3TileUp25           },
    {   false,  TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TrackElemType::LeftQuarterTurn1TileUp60                   },
    {   false,  TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_NONE,       TRACK_BANK_NONE,    TrackElemType::Up60ToFlat                                    },
    {   false,  TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_25,      TRACK_BANK_NONE,    TrackElemType::Up60ToUp25                               },
    {   false,  TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TrackElemType::Up60                                            },
    {   false,  TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_90,      TRACK_BANK_NONE,    TrackElemType::Up60ToUp90                               },
    {   false,  TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TrackElemType::RightQuarterTurn1TileUp60                  },
    {   false,  TRACK_SLOPE_UP_90,      TRACK_BANK_NONE,    TRACK_CURVE_LEFT_SMALL,         TRACK_SLOPE_UP_90,      TRACK_BANK_NONE,    TrackElemType::LeftQuarterTurn1TileUp90                   },
    {   false,  TRACK_SLOPE_UP_90,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_60,      TRACK_BANK_NONE,    TrackElemType::Up90ToUp60                               },
    {   false,  TRACK_SLOPE_UP_90,      TRACK_BANK_NONE,    TRACK_CURVE_NONE,               TRACK_SLOPE_UP_90,      TRACK_BANK_NONE,    TrackElemType::Up90                                            },
    {   false,  TRACK_SLOPE_UP_90,      TRACK_BANK_NONE,    TRACK_CURVE_RIGHT_SMALL,        TRACK_SLOPE_UP_90,      TRACK_BANK_NONE,    TrackElemType::RightQuarterTurn1TileUp90                  },
};

/** rct2: 0x00993D1C */
const int16_t AlternativeTrackTypes[TrackElemType::Count] = {
    TrackElemType::FlatCovered,                        // TrackElemType::Flat
    -1,
    -1,
    -1,
    TrackElemType::Up25Covered,                   // TrackElemType::Up25
    TrackElemType::Up60Covered,                   // TrackElemType::Up60
    TrackElemType::FlatToUp25Covered,           // TrackElemType::FlatToUp25
    TrackElemType::Up25ToUp60Covered,      // TrackElemType::Up25ToUp60
    TrackElemType::Up60ToUp25Covered,      // TrackElemType::Up60ToUp25
    TrackElemType::Up25ToFlatCovered,           // TrackElemType::Up25ToFlat
    TrackElemType::Down25Covered,                 // TrackElemType::Down25
    TrackElemType::Down60Covered,                 // TrackElemType::Down60
    TrackElemType::FlatToDown25Covered,         // TrackElemType::FlatToDown25
    TrackElemType::Down25ToDown60Covered,  // TrackElemType::Down25ToDown60
    TrackElemType::Down60ToDown25Covered,  // TrackElemType::Down60ToDown25
    TrackElemType::Down25ToFlatCovered,         // TrackElemType::Down25ToFlat
    TrackElemType::LeftQuarterTurn5TilesCovered,   // TrackElemType::LeftQuarterTurn5Tiles
    TrackElemType::RightQuarterTurn5TilesCovered,  // TrackElemType::RightQuarterTurn5Tiles
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    TrackElemType::SBendLeftCovered,                 // TrackElemType::SBendLeft
    TrackElemType::SBendRightCovered,                // TrackElemType::SBendRight
    -1,
    -1,
    TrackElemType::LeftQuarterTurn3TilesCovered,   // TrackElemType::LeftQuarterTurn3Tiles
    TrackElemType::RightQuarterTurn3TilesCovered,  // TrackElemType::RightQuarterTurn3Tiles
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
};

/** rct2: 0x0099DA34 */
const money32 TrackPricing[] = {
    65536,  // TrackElemType::Flat
    98304,  // TrackElemType::EndStation
    98304,  // TrackElemType::BeginStation
    98304,  // TrackElemType::MiddleStation
    79872,  // TrackElemType::Up25
    114688, // TrackElemType::Up60
    73728,  // TrackElemType::FlatToUp25
    96256,  // TrackElemType::Up25ToUp60
    96256,  // TrackElemType::Up60ToUp25
    73728,  // TrackElemType::Up25ToFlat
    79872,  // TrackElemType::Down25
    114688, // TrackElemType::Down60
    73728,  // TrackElemType::FlatToDown25
    96256,  // TrackElemType::Down25ToDown60
    96256,  // TrackElemType::Down60ToDown25
    73728,  // TrackElemType::Down25ToFlat
    257359, // TrackElemType::LeftQuarterTurn5Tiles
    257359, // TrackElemType::RightQuarterTurn5Tiles
    69632,  // TrackElemType::FlatToLeftBank
    69632,  // TrackElemType::FlatToRightBank
    69632,  // TrackElemType::LeftBankToFlat
    69632,  // TrackElemType::RightBankToFlat
    273443, // TrackElemType::BankedLeftQuarterTurn5Tiles
    273443, // TrackElemType::BankedRightQuarterTurn5Tiles
    78336,  // TrackElemType::LeftBankToUp25
    78336,  // TrackElemType::RightBankToUp25
    78336,  // TrackElemType::Up25ToLeftBank
    78336,  // TrackElemType::Up25ToRightBank
    78336,  // TrackElemType::LeftBankToDown25
    78336,  // TrackElemType::RightBankToDown25
    78336,  // TrackElemType::Down25ToLeftBank
    78336,  // TrackElemType::Down25ToRightBank
    69632,  // TrackElemType::LeftBank
    69632,  // TrackElemType::RightBank
    313656, // TrackElemType::LeftQuarterTurn5TilesUp25
    313656, // TrackElemType::RightQuarterTurn5TilesUp25
    313656, // TrackElemType::LeftQuarterTurn5TilesDown25
    313656, // TrackElemType::RightQuarterTurn5TilesDown25
    229376, // TrackElemType::SBendLeft
    229376, // TrackElemType::SBendRight
    491520, // TrackElemType::LeftVerticalLoop
    491520, // TrackElemType::RightVerticalLoop
    154415, // TrackElemType::LeftQuarterTurn3Tiles
    154415, // TrackElemType::RightQuarterTurn3Tiles
    164065, // TrackElemType::LeftBankedQuarterTurn3Tiles
    164065, // TrackElemType::RightBankedQuarterTurn3Tiles
    270226, // TrackElemType::LeftQuarterTurn3TilesUp25
    270226, // TrackElemType::RightQuarterTurn3TilesUp25
    270226, // TrackElemType::LeftQuarterTurn3TilesDown25
    270226, // TrackElemType::RightQuarterTurn3TilesDown25
    51471,  // TrackElemType::LeftQuarterTurn1Tile
    51471,  // TrackElemType::RightQuarterTurn1Tile
    212992, // TrackElemType::LeftTwistDownToUp
    212992, // TrackElemType::RightTwistDownToUp
    212992, // TrackElemType::LeftTwistUpToDown
    212992, // TrackElemType::RightTwistUpToDown
    294912, // TrackElemType::HalfLoopUp
    294912, // TrackElemType::HalfLoopDown
    229376, // TrackElemType::LeftCorkscrewUp
    229376, // TrackElemType::RightCorkscrewUp
    229376, // TrackElemType::LeftCorkscrewDown
    229376, // TrackElemType::RightCorkscrewDown
    98304,  // TrackElemType::FlatToUp60
    98304,  // TrackElemType::Up60ToFlat
    98304,  // TrackElemType::FlatToDown60
    98304,  // TrackElemType::Down60ToFlat
    524288, // TrackElemType::TowerBase
    65536,  // TrackElemType::TowerSection
    69632,  // TrackElemType::FlatCovered
    83968,  // TrackElemType::Up25Covered
    118784, // TrackElemType::Up60Covered
    77824,  // TrackElemType::FlatToUp25Covered
    100352, // TrackElemType::Up25ToUp60Covered
    100352, // TrackElemType::Up60ToUp25Covered
    77824,  // TrackElemType::Up25ToFlatCovered
    83968,  // TrackElemType::Down25Covered
    118784, // TrackElemType::Down60Covered
    77824,  // TrackElemType::FlatToDown25Covered
    100352, // TrackElemType::Down25ToDown60Covered
    100352, // TrackElemType::Down60ToDown25Covered
    77824,  // TrackElemType::Down25ToFlatCovered
    261455, // TrackElemType::LeftQuarterTurn5TilesCovered
    261455, // TrackElemType::RightQuarterTurn5TilesCovered
    233472, // TrackElemType::SBendLeftCovered
    233472, // TrackElemType::SBendRightCovered
    158511, // TrackElemType::LeftQuarterTurn3TilesCovered
    158511, // TrackElemType::RightQuarterTurn3TilesCovered
    328192, // TrackElemType::LeftHalfBankedHelixUpSmall
    328192, // TrackElemType::RightHalfBankedHelixUpSmall
    328192, // TrackElemType::LeftHalfBankedHelixDownSmall
    328192, // TrackElemType::RightHalfBankedHelixDownSmall
    547072, // TrackElemType::LeftHalfBankedHelixUpLarge
    547072, // TrackElemType::RightHalfBankedHelixUpLarge
    547072, // TrackElemType::LeftHalfBankedHelixDownLarge
    547072, // TrackElemType::RightHalfBankedHelixDownLarge
    126976, // TrackElemType::LeftQuarterTurn1TileUp60
    126976, // TrackElemType::RightQuarterTurn1TileUp60
    126976, // TrackElemType::LeftQuarterTurn1TileDown60
    126976, // TrackElemType::RightQuarterTurn1TileDown60
    90112,  // TrackElemType::Brakes
    77824,  // TrackElemType::RotationControlToggle
    65536,  // TrackElemType::InvertedUp90ToFlatQuarterLoopAlias / Maze
    273539, // TrackElemType::LeftQuarterBankedHelixLargeUp
    273539, // TrackElemType::RightQuarterBankedHelixLargeUp
    273539, // TrackElemType::LeftQuarterBankedHelixLargeDown
    273539, // TrackElemType::RightQuarterBankedHelixLargeDown
    273539, // TrackElemType::LeftQuarterHelixLargeUp
    273539, // TrackElemType::RightQuarterHelixLargeUp
    273539, // TrackElemType::LeftQuarterHelixLargeDown
    273539, // TrackElemType::RightQuarterHelixLargeDown
    83968,  // TrackElemType::Up25LeftBanked
    83968,  // TrackElemType::Up25RightBanked
    143360, // TrackElemType::Waterfall
    118784, // TrackElemType::Rapids
    196608, // TrackElemType::OnRidePhoto
    83968,  // TrackElemType::Down25LeftBanked
    83968,  // TrackElemType::Down25RightBanked
    393216, // TrackElemType::Watersplash
    376832, // TrackElemType::FlatToUp60LongBase
    376832, // TrackElemType::Up60ToFlatLongBase
    126976, // TrackElemType::Whirlpool
    376832, // TrackElemType::Down60ToFlatLongBase
    376832, // TrackElemType::FlatToDown60LongBase
    643072, // TrackElemType::CableLiftHill
    491520, // TrackElemType::ReverseFreefallSlope
    65536,  // TrackElemType::ReverseFreefallVertical
    69632,  // TrackElemType::Up90
    69632,  // TrackElemType::Down90
    114688, // TrackElemType::Up60ToUp90
    114688, // TrackElemType::Down90ToDown60
    114688, // TrackElemType::Up90ToUp60
    114688, // TrackElemType::Down60ToDown90
    147456, // TrackElemType::BrakeForDrop
    180151, // TrackElemType::LeftEighthToDiag
    180151, // TrackElemType::RightEighthToDiag
    180151, // TrackElemType::LeftEighthToOrthogonal
    180151, // TrackElemType::RightEighthToOrthogonal
    190960, // TrackElemType::LeftEighthBankToDiag
    190960, // TrackElemType::RightEighthBankToDiag
    190960, // TrackElemType::LeftEighthBankToOrthogonal
    190960, // TrackElemType::RightEighthBankToOrthogonal
    92681,  // TrackElemType::DiagFlat
    111820, // TrackElemType::DiagUp25
    147456, // TrackElemType::DiagUp60
    102400, // TrackElemType::DiagFlatToUp25
    129024, // TrackElemType::DiagUp25ToUp60
    129024, // TrackElemType::DiagUp60ToUp25
    102400, // TrackElemType::DiagUp25ToFlat
    111820, // TrackElemType::DiagDown25
    147456, // TrackElemType::DiagDown60
    102400, // TrackElemType::DiagFlatToDown25
    129024, // TrackElemType::DiagDown25ToDown60
    129024, // TrackElemType::DiagDown60ToDown25
    102400, // TrackElemType::DiagDown25ToFlat
    107008, // TrackElemType::DiagFlatToUp60
    107008, // TrackElemType::DiagUp60ToFlat
    107008, // TrackElemType::DiagFlatToDown60
    107008, // TrackElemType::DiagDown60ToFlat
    96777,  // TrackElemType::DiagFlatToLeftBank
    96777,  // TrackElemType::DiagFlatToRightBank
    96777,  // TrackElemType::DiagLeftBankToFlat
    96777,  // TrackElemType::DiagRightBankToFlat
    106496, // TrackElemType::DiagLeftBankToUp25
    106496, // TrackElemType::DiagRightBankToUp25
    106496, // TrackElemType::DiagUp25ToLeftBank
    106496, // TrackElemType::DiagUp25ToRightBank
    106496, // TrackElemType::DiagLeftBankToDown25
    106496, // TrackElemType::DiagRightBankToDown25
    106496, // TrackElemType::DiagDown25ToLeftBank
    106496, // TrackElemType::DiagDown25ToRightBank
    96777,  // TrackElemType::DiagLeftBank
    96777,  // TrackElemType::DiagRightBank
    282624, // TrackElemType::LogFlumeReverser
    217088, // TrackElemType::SpinningTunnel
    221184, // TrackElemType::LeftBarrelRollUpToDown
    221184, // TrackElemType::RightBarrelRollUpToDown
    221184, // TrackElemType::LeftBarrelRollDownToUp
    221184, // TrackElemType::RightBarrelRollDownToUp
    270226, // TrackElemType::LeftBankToLeftQuarterTurn3TilesUp25
    270226, // TrackElemType::RightBankToRightQuarterTurn3TilesUp25
    270226, // TrackElemType::LeftQuarterTurn3TilesDown25ToLeftBank
    270226, // TrackElemType::RightQuarterTurn3TilesDown25ToRightBank
    96384,  // TrackElemType::PoweredLift
    884736, // TrackElemType::LeftLargeHalfLoopUp
    884736, // TrackElemType::RightLargeHalfLoopUp
    884736, // TrackElemType::RightLargeHalfLoopDown
    884736, // TrackElemType::LeftLargeHalfLoopDown
    221184, // TrackElemType::LeftFlyerTwistUp
    221184, // TrackElemType::RightFlyerTwistUp
    221184, // TrackElemType::LeftFlyerTwistDown
    221184, // TrackElemType::RightFlyerTwistDown
    294912, // TrackElemType::FlyerHalfLoopUp
    294912, // TrackElemType::FlyerHalfLoopDown
    229376, // TrackElemType::LeftFlyerCorkscrewUp
    229376, // TrackElemType::RightFlyerCorkscrewUp
    229376, // TrackElemType::LeftFlyerCorkscrewDown
    229376, // TrackElemType::RightFlyerCorkscrewDown
    294912, // TrackElemType::HeartLineTransferUp
    294912, // TrackElemType::HeartLineTransferDown
    417792, // TrackElemType::LeftHeartLineRoll
    417792, // TrackElemType::RightHeartLineRoll
    159744, // TrackElemType::MinigolfHoleA
    167936, // TrackElemType::MinigolfHoleB
    172032, // TrackElemType::MinigolfHoleC
    184320, // TrackElemType::MinigolfHoleD
    184320, // TrackElemType::MinigolfHoleE
    360448, // TrackElemType::MultiDimInvertedFlatToDown90QuarterLoop
    360448, // TrackElemType::Up90ToInvertedFlatQuarterLoop
    360448, // TrackElemType::InvertedFlatToDown90QuarterLoop
    270226, // TrackElemType::LeftCurvedLiftHill
    270226, // TrackElemType::RightCurvedLiftHill
    393216, // TrackElemType::LeftReverser
    393216, // TrackElemType::RightReverser
    65536,  // TrackElemType::AirThrustTopCap
    65536,  // TrackElemType::AirThrustVerticalDown
    491520, // TrackElemType::AirThrustVerticalDownToLevel
    94208,  // TrackElemType::BlockBrakes
    287115, // TrackElemType::LeftBankedQuarterTurn3TileUp25
    287115, // TrackElemType::RightBankedQuarterTurn3TileUp25
    287115, // TrackElemType::LeftBankedQuarterTurn3TileDown25
    287115, // TrackElemType::RightBankedQuarterTurn3TileDown25
    333259, // TrackElemType::LeftBankedQuarterTurn5TileUp25
    333259, // TrackElemType::RightBankedQuarterTurn5TileUp25
    333259, // TrackElemType::LeftBankedQuarterTurn5TileDown25
    333259, // TrackElemType::RightBankedQuarterTurn5TileDown25
    83968,  // TrackElemType::Up25ToLeftBankedUp25
    83968,  // TrackElemType::Up25ToRightBankedUp25
    83968,  // TrackElemType::LeftBankedUp25ToUp25
    83968,  // TrackElemType::RightBankedUp25ToUp25
    83968,  // TrackElemType::Down25ToLeftBankedDown25
    83968,  // TrackElemType::Down25ToRightBankedDown25
    83968,  // TrackElemType::LeftBankedDown25ToDown25
    83968,  // TrackElemType::RightBankedDown25ToDown25
    77824,  // TrackElemType::LeftBankedFlatToLeftBankedUp25
    77824,  // TrackElemType::RightBankedFlatToRightBankedUp25
    77824,  // TrackElemType::LeftBankedUp25ToLeftBankedFlat
    77824,  // TrackElemType::RightBankedUp25ToRightBankedFlat
    77824,  // TrackElemType::LeftBankedFlatToLeftBankedDown25
    77824,  // TrackElemType::RightBankedFlatToRightBankedDown25
    77824,  // TrackElemType::LeftBankedDown25ToLeftBankedFlat
    77824,  // TrackElemType::RightBankedDown25ToRightBankedFlat
    77824,  // TrackElemType::FlatToLeftBankedUp25
    77824,  // TrackElemType::FlatToRightBankedUp25
    77824,  // TrackElemType::LeftBankedUp25ToFlat
    77824,  // TrackElemType::RightBankedUp25ToFlat
    77824,  // TrackElemType::FlatToLeftBankedDown25
    77824,  // TrackElemType::FlatToRightBankedDown25
    77824,  // TrackElemType::LeftBankedDown25ToFlat
    77824,  // TrackElemType::RightBankedDown25ToFlat
    151552, // TrackElemType::LeftQuarterTurn1TileUp90
    151552, // TrackElemType::RightQuarterTurn1TileUp90
    151552, // TrackElemType::LeftQuarterTurn1TileDown90
    151552, // TrackElemType::RightQuarterTurn1TileDown90
    360448, // TrackElemType::MultiDimUp90ToInvertedFlatQuarterLoop
    360448, // TrackElemType::MultiDimFlatToDown90QuarterLoop
    360448, // 255
};

/** rct2: 0x0099DE34 */
const money32 FlatRideTrackPricing[] = {
    65536,
    98304,
    98304,
    98304,
    79872,
    114688,
    73728,
    96256,
    96256,
    73728,
    79872,
    114688,
    73728,
    96256,
    96256,
    73728,
    257359,
    257359,
    69632,
    69632,
    69632,
    69632,
    273443,
    273443,
    78336,
    78336,
    78336,
    78336,
    78336,
    78336,
    78336,
    78336,
    69632,
    69632,
    313656,
    313656,
    313656,
    313656,
    229376,
    229376,
    491520,
    491520,
    154415,
    154415,
    164065,
    164065,
    270226,
    270226,
    270226,
    270226,
    51471,
    51471,
    212992,
    212992,
    212992,
    212992,
    294912,
    294912,
    229376,
    229376,
    229376,
    229376,
    98304,
    98304,
    98304,
    98304,
    524288,
    65536,
    69632,
    83968,
    118784,
    77824,
    100352,
    100352,
    77824,
    83968,
    118784,
    77824,
    100352,
    100352,
    77824,
    261455,
    261455,
    233472,
    233472,
    158511,
    158511,
    328192,
    328192,
    328192,
    328192,
    547072,
    547072,
    547072,
    547072,
    262144, // FLAT_TRACK_ELEM_1_X_4_A
    126976,
    126976,
    126976,
    90112,
    77824,
    65536,
    273539,
    273539,
    273539,
    273539,
    273539,
    273539,
    273539,
    273539,
    262144, // FLAT_TRACK_ELEM_2_X_2
    1048576,    // FLAT_TRACK_ELEM_4_X_4
    143360,
    118784,
    196608,
    524288,
    327680, // FLAT_TRACK_ELEM_1_X_5
    393216,
    65536,  // FLAT_TRACK_ELEM_1_X_1_A
    262144, // FLAT_TRACK_ELEM_1_X_4_B
    126976,
    65536,  // FLAT_TRACK_ELEM_1_X_1_B
    262144, // FLAT_TRACK_ELEM_1_X_4_C
    524288, // FLAT_TRACK_ELEM_3_X_3
    491520,
    65536,
    69632,
    69632,
    114688,
    114688,
    114688,
    114688,
    147456,
    180151,
    180151,
    180151,
    180151,
    190960,
    190960,
    190960,
    190960,
    92681,
    111820,
    147456,
    102400,
    129024,
    129024,
    102400,
    111820,
    147456,
    102400,
    129024,
    129024,
    102400,
    107008,
    107008,
    107008,
    107008,
    96777,
    96777,
    96777,
    96777,
    106496,
    106496,
    106496,
    106496,
    106496,
    106496,
    106496,
    106496,
    96777,
    96777,
    282624,
    217088,
    221184,
    221184,
    221184,
    221184,
    270226,
    270226,
    270226,
    270226,
    96384,
    884736,
    884736,
    884736,
    884736,
    221184,
    221184,
    221184,
    221184,
    294912,
    294912,
    229376,
    229376,
    229376,
    229376,
    294912,
    294912,
    417792,
    417792,
    159744,
    167936,
    172032,
    184320,
    184320,
    159744,
    159744,
    159744,
    270226,
    270226,
    393216,
    393216,
    65536,
    65536,
    491520,
    94208,
    287115,
    287115,
    287115,
    287115,
    333259,
    333259,
    333259,
    333259,
    83968,
    83968,
    83968,
    83968,
    83968,
    83968,
    83968,
    83968,
    77824,
    77824,
    77824,
    77824,
    77824,
    77824,
    77824,
    77824,
    77824,
    77824,
    77824,
    77824,
    77824,
    77824,
    77824,
    77824,
    151552,
    151552,
    151552,
    151552,
};

/** rct2: 0x0099E228, 0x0099E229, 0x0099E22A, 0x0099E22B */
const dodgems_track_size DodgemsTrackSize[] = {
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 4,    4,  59,     59 },   // FLAT_TRACK_ELEM_2_X_2
    { 4,    4,  123,    123 },  // FLAT_TRACK_ELEM_4_X_4
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 4,    4,  59,     123 },  // 115
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
    { 0,    0,  0,      0 },
};

/** rct2: 0x0099EA1C */
const uint8_t TrackElementMirrorMap[] = {
    TrackElemType::Flat,
    TrackElemType::EndStation,
    TrackElemType::BeginStation,
    TrackElemType::MiddleStation,
    TrackElemType::Up25,
    TrackElemType::Up60,
    TrackElemType::FlatToUp25,
    TrackElemType::Up25ToUp60,
    TrackElemType::Up60ToUp25,
    TrackElemType::Up25ToFlat,
    TrackElemType::Down25,
    TrackElemType::Down60,
    TrackElemType::FlatToDown25,
    TrackElemType::Down25ToDown60,
    TrackElemType::Down60ToDown25,
    TrackElemType::Down25ToFlat,
    TrackElemType::RightQuarterTurn5Tiles, // TrackElemType::LeftQuarterTurn5Tiles
    TrackElemType::LeftQuarterTurn5Tiles, // TrackElemType::RightQuarterTurn5Tiles
    TrackElemType::FlatToRightBank, // TrackElemType::FlatToLeftBank
    TrackElemType::FlatToLeftBank, // TrackElemType::FlatToRightBank
    TrackElemType::RightBankToFlat, // TrackElemType::LeftBankToFlat
    TrackElemType::LeftBankToFlat, // TrackElemType::RightBankToFlat
    TrackElemType::BankedRightQuarterTurn5Tiles, // TrackElemType::BankedLeftQuarterTurn5Tiles
    TrackElemType::BankedLeftQuarterTurn5Tiles, // TrackElemType::BankedRightQuarterTurn5Tiles
    TrackElemType::RightBankToUp25, // TrackElemType::LeftBankToUp25
    TrackElemType::LeftBankToUp25, // TrackElemType::RightBankToUp25
    TrackElemType::Up25ToRightBank, // TrackElemType::Up25ToLeftBank
    TrackElemType::Up25ToLeftBank, // TrackElemType::Up25ToRightBank
    TrackElemType::RightBankToDown25, // TrackElemType::LeftBankToDown25
    TrackElemType::LeftBankToDown25, // TrackElemType::RightBankToDown25
    TrackElemType::Down25ToRightBank, // TrackElemType::Down25ToLeftBank
    TrackElemType::Down25ToLeftBank, // TrackElemType::Down25ToRightBank
    TrackElemType::RightBank, // TrackElemType::LeftBank
    TrackElemType::LeftBank, // TrackElemType::RightBank
    TrackElemType::RightQuarterTurn5TilesUp25, // TrackElemType::LeftQuarterTurn5TilesUp25
    TrackElemType::LeftQuarterTurn5TilesUp25, // TrackElemType::RightQuarterTurn5TilesUp25
    TrackElemType::RightQuarterTurn5TilesDown25, // TrackElemType::LeftQuarterTurn5TilesDown25
    TrackElemType::LeftQuarterTurn5TilesDown25, // TrackElemType::RightQuarterTurn5TilesDown25
    TrackElemType::SBendRight, // TrackElemType::SBendLeft
    TrackElemType::SBendLeft, // TrackElemType::SBendRight
    TrackElemType::RightVerticalLoop, // TrackElemType::LeftVerticalLoop
    TrackElemType::LeftVerticalLoop, // TrackElemType::RightVerticalLoop
    TrackElemType::RightQuarterTurn3Tiles, // TrackElemType::LeftQuarterTurn3Tiles
    TrackElemType::LeftQuarterTurn3Tiles, // TrackElemType::RightQuarterTurn3Tiles
    TrackElemType::RightBankedQuarterTurn3Tiles, // TrackElemType::LeftBankedQuarterTurn3Tiles
    TrackElemType::LeftBankedQuarterTurn3Tiles, // TrackElemType::RightBankedQuarterTurn3Tiles
    TrackElemType::RightQuarterTurn3TilesUp25, // TrackElemType::LeftQuarterTurn3TilesUp25
    TrackElemType::LeftQuarterTurn3TilesUp25, // TrackElemType::RightQuarterTurn3TilesUp25
    TrackElemType::RightQuarterTurn3TilesDown25, // TrackElemType::LeftQuarterTurn3TilesDown25
    TrackElemType::LeftQuarterTurn3TilesDown25, // TrackElemType::RightQuarterTurn3TilesDown25
    TrackElemType::RightQuarterTurn1Tile, // TrackElemType::LeftQuarterTurn1Tile
    TrackElemType::LeftQuarterTurn1Tile, // TrackElemType::RightQuarterTurn1Tile
    TrackElemType::RightTwistDownToUp, // TrackElemType::LeftTwistDownToUp
    TrackElemType::LeftTwistDownToUp, // TrackElemType::RightTwistDownToUp
    TrackElemType::RightTwistUpToDown, // TrackElemType::LeftTwistUpToDown
    TrackElemType::LeftTwistUpToDown, // TrackElemType::RightTwistUpToDown
    TrackElemType::HalfLoopUp,
    TrackElemType::HalfLoopDown,
    TrackElemType::RightCorkscrewUp, // TrackElemType::LeftCorkscrewUp
    TrackElemType::LeftCorkscrewUp, // TrackElemType::RightCorkscrewUp
    TrackElemType::RightCorkscrewDown, // TrackElemType::LeftCorkscrewDown
    TrackElemType::LeftCorkscrewDown, // TrackElemType::RightCorkscrewDown
    TrackElemType::FlatToUp60,
    TrackElemType::Up60ToFlat,
    TrackElemType::FlatToDown60,
    TrackElemType::Down60ToFlat,
    TrackElemType::TowerBase,
    TrackElemType::TowerSection,
    TrackElemType::FlatCovered,
    TrackElemType::Up25Covered,
    TrackElemType::Up60Covered,
    TrackElemType::FlatToUp25Covered,
    TrackElemType::Up25ToUp60Covered,
    TrackElemType::Up60ToUp25Covered,
    TrackElemType::Up25ToFlatCovered,
    TrackElemType::Down25Covered,
    TrackElemType::Down60Covered,
    TrackElemType::FlatToDown25Covered,
    TrackElemType::Down25ToDown60Covered,
    TrackElemType::Down60ToDown25Covered,
    TrackElemType::Down25ToFlatCovered,
    TrackElemType::RightQuarterTurn5TilesCovered, // TrackElemType::LeftQuarterTurn5TilesCovered
    TrackElemType::LeftQuarterTurn5TilesCovered, // TrackElemType::RightQuarterTurn5TilesCovered
    TrackElemType::SBendRightCovered, // TrackElemType::SBendLeftCovered
    TrackElemType::SBendLeftCovered, // TrackElemType::SBendRightCovered
    TrackElemType::RightQuarterTurn3TilesCovered, // TrackElemType::LeftQuarterTurn3TilesCovered
    TrackElemType::LeftQuarterTurn3TilesCovered, // TrackElemType::RightQuarterTurn3TilesCovered
    TrackElemType::RightHalfBankedHelixUpSmall, // TrackElemType::LeftHalfBankedHelixUpSmall
    TrackElemType::LeftHalfBankedHelixUpSmall, // TrackElemType::RightHalfBankedHelixUpSmall
    TrackElemType::RightHalfBankedHelixDownSmall, // TrackElemType::LeftHalfBankedHelixDownSmall
    TrackElemType::LeftHalfBankedHelixDownSmall, // TrackElemType::RightHalfBankedHelixDownSmall
    TrackElemType::RightHalfBankedHelixUpLarge, // TrackElemType::LeftHalfBankedHelixUpLarge
    TrackElemType::LeftHalfBankedHelixUpLarge, // TrackElemType::RightHalfBankedHelixUpLarge
    TrackElemType::RightHalfBankedHelixDownLarge, // TrackElemType::LeftHalfBankedHelixDownLarge
    TrackElemType::LeftHalfBankedHelixDownLarge, // TrackElemType::RightHalfBankedHelixDownLarge
    TrackElemType::RightQuarterTurn1TileUp60, // TrackElemType::LeftQuarterTurn1TileUp60
    TrackElemType::LeftQuarterTurn1TileUp60, // TrackElemType::RightQuarterTurn1TileUp60
    TrackElemType::RightQuarterTurn1TileDown60, // TrackElemType::LeftQuarterTurn1TileDown60
    TrackElemType::LeftQuarterTurn1TileDown60, // TrackElemType::RightQuarterTurn1TileDown60
    TrackElemType::Brakes,
    TrackElemType::RotationControlToggle,
    TrackElemType::Maze,
    TrackElemType::RightQuarterBankedHelixLargeUp, // TrackElemType::LeftQuarterBankedHelixLargeUp
    TrackElemType::LeftQuarterBankedHelixLargeUp, // TrackElemType::RightQuarterBankedHelixLargeUp
    TrackElemType::RightQuarterBankedHelixLargeDown, // TrackElemType::LeftQuarterBankedHelixLargeDown
    TrackElemType::LeftQuarterBankedHelixLargeDown, // TrackElemType::RightQuarterBankedHelixLargeDown
    TrackElemType::RightQuarterHelixLargeUp, // TrackElemType::LeftQuarterHelixLargeUp
    TrackElemType::LeftQuarterHelixLargeUp, // TrackElemType::RightQuarterHelixLargeUp
    TrackElemType::RightQuarterHelixLargeDown, // TrackElemType::LeftQuarterHelixLargeDown
    TrackElemType::LeftQuarterHelixLargeDown, // TrackElemType::RightQuarterHelixLargeDown
    TrackElemType::Up25RightBanked, // TrackElemType::Up25LeftBanked
    TrackElemType::Up25LeftBanked, // TrackElemType::Up25RightBanked
    TrackElemType::Waterfall,
    TrackElemType::Rapids,
    TrackElemType::OnRidePhoto,
    TrackElemType::Down25RightBanked, // TrackElemType::Down25LeftBanked
    TrackElemType::Down25LeftBanked, // TrackElemType::Down25RightBanked
    TrackElemType::Watersplash,
    TrackElemType::FlatToUp60LongBase,
    TrackElemType::Up60ToFlatLongBase,
    TrackElemType::Whirlpool,
    TrackElemType::Down60ToFlatLongBase,
    TrackElemType::FlatToDown60LongBase,
    TrackElemType::CableLiftHill,
    TrackElemType::ReverseFreefallSlope,
    TrackElemType::ReverseFreefallVertical,
    TrackElemType::Up90,
    TrackElemType::Down90,
    TrackElemType::Up60ToUp90,
    TrackElemType::Down90ToDown60,
    TrackElemType::Up90ToUp60,
    TrackElemType::Down60ToDown90,
    TrackElemType::BrakeForDrop,
    TrackElemType::RightEighthToDiag, // TrackElemType::LeftEighthToDiag
    TrackElemType::LeftEighthToDiag, // TrackElemType::RightEighthToDiag
    TrackElemType::RightEighthToOrthogonal, // TrackElemType::LeftEighthToOrthogonal
    TrackElemType::LeftEighthToOrthogonal, // TrackElemType::RightEighthToOrthogonal
    TrackElemType::RightEighthBankToDiag, // TrackElemType::LeftEighthBankToDiag
    TrackElemType::LeftEighthBankToDiag, // TrackElemType::RightEighthBankToDiag
    TrackElemType::RightEighthBankToOrthogonal, // TrackElemType::LeftEighthBankToOrthogonal
    TrackElemType::LeftEighthBankToOrthogonal, // TrackElemType::RightEighthBankToOrthogonal
    TrackElemType::DiagFlat,
    TrackElemType::DiagUp25,
    TrackElemType::DiagUp60,
    TrackElemType::DiagFlatToUp25,
    TrackElemType::DiagUp25ToUp60,
    TrackElemType::DiagUp60ToUp25,
    TrackElemType::DiagUp25ToFlat,
    TrackElemType::DiagDown25,
    TrackElemType::DiagDown60,
    TrackElemType::DiagFlatToDown25,
    TrackElemType::DiagDown25ToDown60,
    TrackElemType::DiagDown60ToDown25,
    TrackElemType::DiagDown25ToFlat,
    TrackElemType::DiagFlatToUp60,
    TrackElemType::DiagUp60ToFlat,
    TrackElemType::DiagFlatToDown60,
    TrackElemType::DiagDown60ToFlat,
    TrackElemType::DiagFlatToRightBank, // TrackElemType::DiagFlatToLeftBank
    TrackElemType::DiagFlatToLeftBank, // TrackElemType::DiagFlatToRightBank
    TrackElemType::DiagRightBankToFlat, // TrackElemType::DiagLeftBankToFlat
    TrackElemType::DiagLeftBankToFlat, // TrackElemType::DiagRightBankToFlat
    TrackElemType::DiagRightBankToUp25, // TrackElemType::DiagLeftBankToUp25
    TrackElemType::DiagLeftBankToUp25, // TrackElemType::DiagRightBankToUp25
    TrackElemType::DiagUp25ToRightBank, // TrackElemType::DiagUp25ToLeftBank
    TrackElemType::DiagUp25ToLeftBank, // TrackElemType::DiagUp25ToRightBank
    TrackElemType::DiagRightBankToDown25, // TrackElemType::DiagLeftBankToDown25
    TrackElemType::DiagLeftBankToDown25, // TrackElemType::DiagRightBankToDown25
    TrackElemType::DiagDown25ToRightBank, // TrackElemType::DiagDown25ToLeftBank
    TrackElemType::DiagDown25ToLeftBank, // TrackElemType::DiagDown25ToRightBank
    TrackElemType::DiagRightBank, // TrackElemType::DiagLeftBank
    TrackElemType::DiagLeftBank, // TrackElemType::DiagRightBank
    TrackElemType::LogFlumeReverser,
    TrackElemType::SpinningTunnel,
    TrackElemType::RightBarrelRollUpToDown, // TrackElemType::LeftBarrelRollUpToDown
    TrackElemType::LeftBarrelRollUpToDown, // TrackElemType::RightBarrelRollUpToDown
    TrackElemType::RightBarrelRollDownToUp, // TrackElemType::LeftBarrelRollDownToUp
    TrackElemType::LeftBarrelRollDownToUp, // TrackElemType::RightBarrelRollDownToUp
    TrackElemType::RightBankToRightQuarterTurn3TilesUp25, // TrackElemType::LeftBankToLeftQuarterTurn3TilesUp25
    TrackElemType::LeftBankToLeftQuarterTurn3TilesUp25, // TrackElemType::RightBankToRightQuarterTurn3TilesUp25
    TrackElemType::RightQuarterTurn3TilesDown25ToRightBank, // TrackElemType::LeftQuarterTurn3TilesDown25ToLeftBank
    TrackElemType::LeftQuarterTurn3TilesDown25ToLeftBank, // TrackElemType::RightQuarterTurn3TilesDown25ToRightBank
    TrackElemType::PoweredLift,
    TrackElemType::RightLargeHalfLoopUp, // TrackElemType::LeftLargeHalfLoopUp
    TrackElemType::LeftLargeHalfLoopUp, // TrackElemType::RightLargeHalfLoopUp
    TrackElemType::LeftLargeHalfLoopDown, // TrackElemType::RightLargeHalfLoopDown
    TrackElemType::RightLargeHalfLoopDown, // TrackElemType::LeftLargeHalfLoopDown
    TrackElemType::RightFlyerTwistUp, // TrackElemType::LeftFlyerTwistUp
    TrackElemType::LeftFlyerTwistUp, // TrackElemType::RightFlyerTwistUp
    TrackElemType::RightFlyerTwistDown, // TrackElemType::LeftFlyerTwistDown
    TrackElemType::LeftFlyerTwistDown, // TrackElemType::RightFlyerTwistDown
    TrackElemType::FlyerHalfLoopUp,
    TrackElemType::FlyerHalfLoopDown,
    TrackElemType::RightFlyerCorkscrewUp, // TrackElemType::LeftFlyerCorkscrewUp
    TrackElemType::LeftFlyerCorkscrewUp, // TrackElemType::RightFlyerCorkscrewUp
    TrackElemType::RightFlyerCorkscrewDown, // TrackElemType::LeftFlyerCorkscrewDown
    TrackElemType::LeftFlyerCorkscrewDown, // TrackElemType::RightFlyerCorkscrewDown
    TrackElemType::HeartLineTransferUp,
    TrackElemType::HeartLineTransferDown,
    TrackElemType::RightHeartLineRoll, // TrackElemType::LeftHeartLineRoll
    TrackElemType::LeftHeartLineRoll, // TrackElemType::RightHeartLineRoll
    TrackElemType::MinigolfHoleA,
    TrackElemType::MinigolfHoleB,
    TrackElemType::MinigolfHoleC,
    TrackElemType::MinigolfHoleE, // TrackElemType::MinigolfHoleD
    TrackElemType::MinigolfHoleD, // TrackElemType::MinigolfHoleE
    TrackElemType::MultiDimInvertedFlatToDown90QuarterLoop,
    TrackElemType::Up90ToInvertedFlatQuarterLoop,
    TrackElemType::InvertedFlatToDown90QuarterLoop,
    TrackElemType::RightCurvedLiftHill, // TrackElemType::LeftCurvedLiftHill
    TrackElemType::LeftCurvedLiftHill, // TrackElemType::RightCurvedLiftHill
    TrackElemType::RightReverser, // TrackElemType::LeftReverser
    TrackElemType::LeftReverser, // TrackElemType::RightReverser
    TrackElemType::AirThrustTopCap,
    TrackElemType::AirThrustVerticalDown,
    TrackElemType::AirThrustVerticalDownToLevel,
    TrackElemType::BlockBrakes,
    TrackElemType::RightBankedQuarterTurn3TileUp25, // TrackElemType::LeftBankedQuarterTurn3TileUp25
    TrackElemType::LeftBankedQuarterTurn3TileUp25, // TrackElemType::RightBankedQuarterTurn3TileUp25
    TrackElemType::RightBankedQuarterTurn3TileDown25, // TrackElemType::LeftBankedQuarterTurn3TileDown25
    TrackElemType::LeftBankedQuarterTurn3TileDown25, // TrackElemType::RightBankedQuarterTurn3TileDown25
    TrackElemType::RightBankedQuarterTurn5TileUp25, // TrackElemType::LeftBankedQuarterTurn5TileUp25
    TrackElemType::LeftBankedQuarterTurn5TileUp25, // TrackElemType::RightBankedQuarterTurn5TileUp25
    TrackElemType::RightBankedQuarterTurn5TileDown25, // TrackElemType::LeftBankedQuarterTurn5TileDown25
    TrackElemType::LeftBankedQuarterTurn5TileDown25, // TrackElemType::RightBankedQuarterTurn5TileDown25
    TrackElemType::Up25ToRightBankedUp25, // TrackElemType::Up25ToLeftBankedUp25
    TrackElemType::Up25ToLeftBankedUp25, // TrackElemType::Up25ToRightBankedUp25
    TrackElemType::RightBankedUp25ToUp25, // TrackElemType::LeftBankedUp25ToUp25
    TrackElemType::LeftBankedUp25ToUp25, // TrackElemType::RightBankedUp25ToUp25
    TrackElemType::Down25ToRightBankedDown25, // TrackElemType::Down25ToLeftBankedDown25
    TrackElemType::Down25ToLeftBankedDown25, // TrackElemType::Down25ToRightBankedDown25
    TrackElemType::RightBankedDown25ToDown25, // TrackElemType::LeftBankedDown25ToDown25
    TrackElemType::LeftBankedDown25ToDown25, // TrackElemType::RightBankedDown25ToDown25
    TrackElemType::RightBankedFlatToRightBankedUp25, // TrackElemType::LeftBankedFlatToLeftBankedUp25
    TrackElemType::LeftBankedFlatToLeftBankedUp25, // TrackElemType::RightBankedFlatToRightBankedUp25
    TrackElemType::RightBankedUp25ToRightBankedFlat, // TrackElemType::LeftBankedUp25ToLeftBankedFlat
    TrackElemType::LeftBankedUp25ToLeftBankedFlat, // TrackElemType::RightBankedUp25ToRightBankedFlat
    TrackElemType::RightBankedFlatToRightBankedDown25, // TrackElemType::LeftBankedFlatToLeftBankedDown25
    TrackElemType::LeftBankedFlatToLeftBankedDown25, // TrackElemType::RightBankedFlatToRightBankedDown25
    TrackElemType::RightBankedDown25ToRightBankedFlat, // TrackElemType::LeftBankedDown25ToLeftBankedFlat
    TrackElemType::LeftBankedDown25ToLeftBankedFlat, // TrackElemType::RightBankedDown25ToRightBankedFlat
    TrackElemType::FlatToRightBankedUp25, // TrackElemType::FlatToLeftBankedUp25
    TrackElemType::FlatToLeftBankedUp25, // TrackElemType::FlatToRightBankedUp25
    TrackElemType::RightBankedUp25ToFlat, // TrackElemType::LeftBankedUp25ToFlat
    TrackElemType::LeftBankedUp25ToFlat, // TrackElemType::RightBankedUp25ToFlat
    TrackElemType::FlatToRightBankedDown25, // TrackElemType::FlatToLeftBankedDown25
    TrackElemType::FlatToLeftBankedDown25, // TrackElemType::FlatToRightBankedDown25
    TrackElemType::RightBankedDown25ToFlat, // TrackElemType::LeftBankedDown25ToFlat
    TrackElemType::LeftBankedDown25ToFlat, // TrackElemType::RightBankedDown25ToFlat
    TrackElemType::RightQuarterTurn1TileUp90, // TrackElemType::LeftQuarterTurn1TileUp90
    TrackElemType::LeftQuarterTurn1TileUp90, // TrackElemType::RightQuarterTurn1TileUp90
    TrackElemType::RightQuarterTurn1TileDown90, // TrackElemType::LeftQuarterTurn1TileDown90
    TrackElemType::LeftQuarterTurn1TileDown90, // TrackElemType::RightQuarterTurn1TileDown90
    TrackElemType::MultiDimUp90ToInvertedFlatQuarterLoop,
    TrackElemType::MultiDimFlatToDown90QuarterLoop,
    255,
};

/** rct2: 0x00999694 */
const uint32_t TrackHeightMarkerPositions[TrackElemType::Count] = {
    (1 << 0), // TrackElemType::Flat
    (1 << 0), // TrackElemType::EndStation
    (1 << 0), // TrackElemType::BeginStation
    (1 << 0), // TrackElemType::MiddleStation
    (1 << 0), // TrackElemType::Up25
    (1 << 0), // TrackElemType::Up60
    (1 << 0), // TrackElemType::FlatToUp25
    (1 << 0), // TrackElemType::Up25ToUp60
    (1 << 0), // TrackElemType::Up60ToUp25
    (1 << 0), // TrackElemType::Up25ToFlat
    (1 << 0), // TrackElemType::Down25
    (1 << 0), // TrackElemType::Down60
    (1 << 0), // TrackElemType::FlatToDown25
    (1 << 0), // TrackElemType::Down25ToDown60
    (1 << 0), // TrackElemType::Down60ToDown25
    (1 << 0), // TrackElemType::Down25ToFlat
    (1 << 0) | (1 << 6), // TrackElemType::LeftQuarterTurn5Tiles
    (1 << 0) | (1 << 6), // TrackElemType::RightQuarterTurn5Tiles
    (1 << 0), // TrackElemType::FlatToLeftBank
    (1 << 0), // TrackElemType::FlatToRightBank
    (1 << 0), // TrackElemType::LeftBankToFlat
    (1 << 0), // TrackElemType::RightBankToFlat
    (1 << 0) | (1 << 6), // TrackElemType::BankedLeftQuarterTurn5Tiles
    (1 << 0) | (1 << 6), // TrackElemType::BankedRightQuarterTurn5Tiles
    (1 << 0), // TrackElemType::LeftBankToUp25
    (1 << 0), // TrackElemType::RightBankToUp25
    (1 << 0), // TrackElemType::Up25ToLeftBank
    (1 << 0), // TrackElemType::Up25ToRightBank
    (1 << 0), // TrackElemType::LeftBankToDown25
    (1 << 0), // TrackElemType::RightBankToDown25
    (1 << 0), // TrackElemType::Down25ToLeftBank
    (1 << 0), // TrackElemType::Down25ToRightBank
    (1 << 0), // TrackElemType::LeftBank
    (1 << 0), // TrackElemType::RightBank
    (1 << 0) | (1 << 6), // TrackElemType::LeftQuarterTurn5TilesUp25
    (1 << 0) | (1 << 6), // TrackElemType::RightQuarterTurn5TilesUp25
    (1 << 0) | (1 << 6), // TrackElemType::LeftQuarterTurn5TilesDown25
    (1 << 0) | (1 << 6), // TrackElemType::RightQuarterTurn5TilesDown25
    (1 << 0) | (1 << 3), // TrackElemType::SBendLeft
    (1 << 0) | (1 << 3), // TrackElemType::SBendRight
    (1 << 0) | (1 << 9), // TrackElemType::LeftVerticalLoop
    (1 << 0) | (1 << 9), // TrackElemType::RightVerticalLoop
    (1 << 0) | (1 << 3), // TrackElemType::LeftQuarterTurn3Tiles
    (1 << 0) | (1 << 3), // TrackElemType::RightQuarterTurn3Tiles
    (1 << 0) | (1 << 3), // TrackElemType::LeftBankedQuarterTurn3Tiles
    (1 << 0) | (1 << 3), // TrackElemType::RightBankedQuarterTurn3Tiles
    (1 << 0) | (1 << 3), // TrackElemType::LeftQuarterTurn3TilesUp25
    (1 << 0) | (1 << 3), // TrackElemType::RightQuarterTurn3TilesUp25
    (1 << 0) | (1 << 3), // TrackElemType::LeftQuarterTurn3TilesDown25
    (1 << 0) | (1 << 3), // TrackElemType::RightQuarterTurn3TilesDown25
    (1 << 0), // TrackElemType::LeftQuarterTurn1Tile
    (1 << 0), // TrackElemType::RightQuarterTurn1Tile
    (1 << 0) | (1 << 2), // TrackElemType::LeftTwistDownToUp
    (1 << 0) | (1 << 2), // TrackElemType::RightTwistDownToUp
    (1 << 0) | (1 << 2), // TrackElemType::LeftTwistUpToDown
    (1 << 0) | (1 << 2), // TrackElemType::RightTwistUpToDown
    (1 << 0) | (1 << 3), // TrackElemType::HalfLoopUp
    (1 << 0) | (1 << 3), // TrackElemType::HalfLoopDown
    (1 << 0) | (1 << 2), // TrackElemType::LeftCorkscrewUp
    (1 << 0) | (1 << 2), // TrackElemType::RightCorkscrewUp
    (1 << 0) | (1 << 2), // TrackElemType::LeftCorkscrewDown
    (1 << 0) | (1 << 2), // TrackElemType::RightCorkscrewDown
    (1 << 0), // TrackElemType::FlatToUp60
    (1 << 0), // TrackElemType::Up60ToFlat
    (1 << 0), // TrackElemType::FlatToDown60
    (1 << 0), // TrackElemType::Down60ToFlat
    (1 << 1) | (1 << 3) | (1 << 6) | (1 << 7), // TrackElemType::TowerBase
    (1 << 0), // TrackElemType::TowerSection
    (1 << 0), // TrackElemType::FlatCovered
    (1 << 0), // TrackElemType::Up25Covered
    (1 << 0), // TrackElemType::Up60Covered
    (1 << 0), // TrackElemType::FlatToUp25Covered
    (1 << 0), // TrackElemType::Up25ToUp60Covered
    (1 << 0), // TrackElemType::Up60ToUp25Covered
    (1 << 0), // TrackElemType::Up25ToFlatCovered
    (1 << 0), // TrackElemType::Down25Covered
    (1 << 0), // TrackElemType::Down60Covered
    (1 << 0), // TrackElemType::FlatToDown25Covered
    (1 << 0), // TrackElemType::Down25ToDown60Covered
    (1 << 0), // TrackElemType::Down60ToDown25Covered
    (1 << 0), // TrackElemType::Down25ToFlatCovered
    (1 << 0) | (1 << 6), // TrackElemType::LeftQuarterTurn5TilesCovered
    (1 << 0) | (1 << 6), // TrackElemType::RightQuarterTurn5TilesCovered
    (1 << 0) | (1 << 3), // TrackElemType::SBendLeftCovered
    (1 << 0) | (1 << 3), // TrackElemType::SBendRightCovered
    (1 << 0) | (1 << 3), // TrackElemType::LeftQuarterTurn3TilesCovered
    (1 << 0) | (1 << 3), // TrackElemType::RightQuarterTurn3TilesCovered
    (1 << 0) | (1 << 7), // TrackElemType::LeftHalfBankedHelixUpSmall
    (1 << 0) | (1 << 7), // TrackElemType::RightHalfBankedHelixUpSmall
    (1 << 0) | (1 << 7), // TrackElemType::LeftHalfBankedHelixDownSmall
    (1 << 0) | (1 << 7), // TrackElemType::RightHalfBankedHelixDownSmall
    (1 << 0) | (1 << 13), // TrackElemType::LeftHalfBankedHelixUpLarge
    (1 << 0) | (1 << 13), // TrackElemType::RightHalfBankedHelixUpLarge
    (1 << 0) | (1 << 13), // TrackElemType::LeftHalfBankedHelixDownLarge
    (1 << 0) | (1 << 13), // TrackElemType::RightHalfBankedHelixDownLarge
    (1 << 0), // TrackElemType::LeftQuarterTurn1TileUp60
    (1 << 0), // TrackElemType::RightQuarterTurn1TileUp60
    (1 << 0), // TrackElemType::LeftQuarterTurn1TileDown60
    (1 << 0), // TrackElemType::RightQuarterTurn1TileDown60
    (1 << 0), // TrackElemType::Brakes
    (1 << 0), // TrackElemType::RotationControlToggle
    (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10) | (1 << 11) | (1 << 12) | (1 << 13) | (1 << 14) | (1 << 15), // TrackElemType::InvertedUp90ToFlatQuarterLoopAlias / Maze
    (1 << 0) | (1 << 6), // TrackElemType::LeftQuarterBankedHelixLargeUp
    (1 << 0) | (1 << 6), // TrackElemType::RightQuarterBankedHelixLargeUp
    (1 << 0) | (1 << 6), // TrackElemType::LeftQuarterBankedHelixLargeDown
    (1 << 0) | (1 << 6), // TrackElemType::RightQuarterBankedHelixLargeDown
    (1 << 0) | (1 << 6), // TrackElemType::LeftQuarterHelixLargeUp
    (1 << 0) | (1 << 6), // TrackElemType::RightQuarterHelixLargeUp
    (1 << 0) | (1 << 6), // TrackElemType::LeftQuarterHelixLargeDown
    (1 << 0) | (1 << 6), // TrackElemType::RightQuarterHelixLargeDown
    (1 << 0), // TrackElemType::Up25LeftBanked
    (1 << 0) | (1 << 3) | (1 << 12) | (1 << 15), // TrackElemType::Up25RightBanked
    (1 << 0), // TrackElemType::Waterfall
    (1 << 0), // TrackElemType::Rapids
    (1 << 0), // TrackElemType::OnRidePhoto
    (1 << 0) | (1 << 7), // TrackElemType::Down25LeftBanked
    (1 << 0), // TrackElemType::Down25RightBanked
    (1 << 0) | (1 << 4), // TrackElemType::Watersplash
    (1 << 0) | (1 << 3), // TrackElemType::FlatToUp60LongBase
    (1 << 0) | (1 << 3), // TrackElemType::Up60ToFlatLongBase
    (1 << 0), // TrackElemType::Whirlpool
    (1 << 0) | (1 << 3), // TrackElemType::Down60ToFlatLongBase
    (1 << 0) | (1 << 3), // TrackElemType::FlatToUp60LongBase
    (1 << 0) | (1 << 3), // TrackElemType::CableLiftHill
    (1 << 0) | (1 << 5), // TrackElemType::ReverseFreefallSlope
    (1 << 0), // TrackElemType::ReverseFreefallVertical
    (1 << 0), // TrackElemType::Up90
    (1 << 0), // TrackElemType::Down90
    (1 << 0), // TrackElemType::Up60ToUp90
    (1 << 0), // TrackElemType::Down90ToDown60
    (1 << 0), // TrackElemType::Up90ToUp60
    (1 << 0), // TrackElemType::Down60ToDown90
    (1 << 0), // TrackElemType::BrakeForDrop
    (1 << 0) | (1 << 4), // TrackElemType::LeftEighthToDiag
    (1 << 0) | (1 << 4), // TrackElemType::RightEighthToDiag
    (1 << 0) | (1 << 4), // TrackElemType::LeftEighthToOrthogonal
    (1 << 0) | (1 << 4), // TrackElemType::RightEighthToOrthogonal
    (1 << 0) | (1 << 4), // TrackElemType::LeftEighthBankToDiag
    (1 << 0) | (1 << 4), // TrackElemType::RightEighthBankToDiag
    (1 << 0) | (1 << 4), // TrackElemType::LeftEighthBankToOrthogonal
    (1 << 0) | (1 << 4), // TrackElemType::RightEighthBankToOrthogonal
    (1 << 0), // TrackElemType::DiagFlat
    (1 << 0), // TrackElemType::DiagUp25
    (1 << 0), // TrackElemType::DiagUp60
    (1 << 0), // TrackElemType::DiagFlatToUp25
    (1 << 0), // TrackElemType::DiagUp25ToUp60
    (1 << 0), // TrackElemType::DiagUp60ToUp25
    (1 << 0), // TrackElemType::DiagUp25ToFlat
    (1 << 3), // TrackElemType::DiagDown25
    (1 << 3), // TrackElemType::DiagDown60
    (1 << 3), // TrackElemType::DiagFlatToDown25
    (1 << 3), // TrackElemType::DiagDown25ToDown60
    (1 << 3), // TrackElemType::DiagDown60ToDown25
    (1 << 3), // TrackElemType::DiagDown25ToFlat
    (1 << 0), // TrackElemType::DiagFlatToUp60
    (1 << 0), // TrackElemType::DiagUp60ToFlat
    (1 << 3), // TrackElemType::DiagFlatToDown60
    (1 << 3), // TrackElemType::DiagDown60ToFlat
    (1 << 0), // TrackElemType::DiagFlatToLeftBank
    (1 << 0), // TrackElemType::DiagFlatToRightBank
    (1 << 0), // TrackElemType::DiagLeftBankToFlat
    (1 << 0), // TrackElemType::DiagRightBankToFlat
    (1 << 0), // TrackElemType::DiagLeftBankToUp25
    (1 << 0), // TrackElemType::DiagRightBankToUp25
    (1 << 0), // TrackElemType::DiagUp25ToLeftBank
    (1 << 0), // TrackElemType::DiagUp25ToRightBank
    (1 << 3), // TrackElemType::DiagLeftBankToDown25
    (1 << 3), // TrackElemType::DiagRightBankToDown25
    (1 << 3), // TrackElemType::DiagDown25ToLeftBank
    (1 << 3), // TrackElemType::DiagDown25ToRightBank
    (1 << 0), // TrackElemType::DiagLeftBank
    (1 << 0), // TrackElemType::DiagRightBank
    (1 << 0), // TrackElemType::LogFlumeReverser
    (1 << 0), // TrackElemType::SpinningTunnel
    (1 << 0) | (1 << 2), // TrackElemType::LeftBarrelRollUpToDown
    (1 << 0) | (1 << 2), // TrackElemType::RightBarrelRollUpToDown
    (1 << 0) | (1 << 2), // TrackElemType::LeftBarrelRollDownToUp
    (1 << 0) | (1 << 2), // TrackElemType::RightBarrelRollDownToUp
    (1 << 0) | (1 << 3), // TrackElemType::LeftBankToLeftQuarterTurn3TilesUp25
    (1 << 0) | (1 << 3), // TrackElemType::RightBankToRightQuarterTurn3TilesUp25
    (1 << 0) | (1 << 3), // TrackElemType::LeftQuarterTurn3TilesDown25ToLeftBank
    (1 << 0) | (1 << 3), // TrackElemType::RightQuarterTurn3TilesDown25ToRightBank
    (1 << 0), // TrackElemType::PoweredLift
    (1 << 0) | (1 << 6), // TrackElemType::LeftLargeHalfLoopUp
    (1 << 0) | (1 << 6), // TrackElemType::RightLargeHalfLoopUp
    (1 << 0) | (1 << 6), // TrackElemType::RightLargeHalfLoopDown
    (1 << 0) | (1 << 6), // TrackElemType::LeftLargeHalfLoopDown
    (1 << 0) | (1 << 2), // TrackElemType::LeftFlyerTwistUp
    (1 << 0) | (1 << 2), // TrackElemType::RightFlyerTwistUp
    (1 << 0) | (1 << 2), // TrackElemType::LeftFlyerTwistDown
    (1 << 0) | (1 << 2), // TrackElemType::RightFlyerTwistDown
    (1 << 0) | (1 << 3), // TrackElemType::FlyerHalfLoopUp
    (1 << 0) | (1 << 3), // TrackElemType::FlyerHalfLoopDown
    (1 << 0) | (1 << 2), // TrackElemType::LeftFlyerCorkscrewUp
    (1 << 0) | (1 << 2), // TrackElemType::RightFlyerCorkscrewUp
    (1 << 0) | (1 << 2), // TrackElemType::LeftFlyerCorkscrewDown
    (1 << 0) | (1 << 2), // TrackElemType::RightFlyerCorkscrewDown
    (1 << 0) | (1 << 3), // TrackElemType::HeartLineTransferUp
    (1 << 0) | (1 << 3), // TrackElemType::HeartLineTransferDown
    (1 << 0) | (1 << 5), // TrackElemType::LeftHeartLineRoll
    (1 << 0) | (1 << 5), // TrackElemType::RightHeartLineRoll
    (1 << 0) | (1 << 1), // TrackElemType::MinigolfHoleA
    (1 << 0) | (1 << 1), // TrackElemType::MinigolfHoleB
    (1 << 0) | (1 << 1), // TrackElemType::MinigolfHoleC
    (1 << 0) | (1 << 2), // TrackElemType::MinigolfHoleD
    (1 << 0) | (1 << 2), // TrackElemType::MinigolfHoleE
    (1 << 0) | (1 << 2), // TrackElemType::MultiDimInvertedFlatToDown90QuarterLoop
    (1 << 0) | (1 << 2), // TrackElemType::Up90ToInvertedFlatQuarterLoop
    (1 << 0) | (1 << 2), // TrackElemType::InvertedFlatToDown90QuarterLoop
    (1 << 0) | (1 << 3), // TrackElemType::LeftCurvedLiftHill
    (1 << 0) | (1 << 3), // TrackElemType::RightCurvedLiftHill
    (1 << 0) | (1 << 5), // TrackElemType::LeftReverser
    (1 << 0) | (1 << 5), // TrackElemType::RightReverser
    (1 << 0) | (1 << 3), // TrackElemType::AirThrustTopCap
    (1 << 0), // TrackElemType::AirThrustVerticalDown
    (1 << 0) | (1 << 5), // TrackElemType::AirThrustVerticalDownToLevel
    (1 << 0), // TrackElemType::BlockBrakes
    (1 << 0) | (1 << 3), // TrackElemType::LeftBankedQuarterTurn3TileUp25
    (1 << 0) | (1 << 3), // TrackElemType::RightBankedQuarterTurn3TileUp25
    (1 << 0) | (1 << 3), // TrackElemType::LeftBankedQuarterTurn3TileDown25
    (1 << 0) | (1 << 3), // TrackElemType::RightBankedQuarterTurn3TileDown25
    (1 << 0) | (1 << 6), // TrackElemType::LeftBankedQuarterTurn5TileUp25
    (1 << 0) | (1 << 6), // TrackElemType::RightBankedQuarterTurn5TileUp25
    (1 << 0) | (1 << 6), // TrackElemType::LeftBankedQuarterTurn5TileDown25
    (1 << 0) | (1 << 6), // TrackElemType::RightBankedQuarterTurn5TileDown25
    (1 << 0), // TrackElemType::Up25ToLeftBankedUp25
    (1 << 0), // TrackElemType::Up25ToRightBankedUp25
    (1 << 0), // TrackElemType::LeftBankedUp25ToUp25
    (1 << 0), // TrackElemType::RightBankedUp25ToUp25
    (1 << 0), // TrackElemType::Down25ToLeftBankedDown25
    (1 << 0), // TrackElemType::Down25ToRightBankedDown25
    (1 << 0), // TrackElemType::LeftBankedDown25ToDown25
    (1 << 0), // TrackElemType::RightBankedDown25ToDown25
    (1 << 0), // TrackElemType::LeftBankedFlatToLeftBankedUp25
    (1 << 0), // TrackElemType::RightBankedFlatToRightBankedUp25
    (1 << 0), // TrackElemType::LeftBankedUp25ToLeftBankedFlat
    (1 << 0), // TrackElemType::RightBankedUp25ToRightBankedFlat
    (1 << 0), // TrackElemType::LeftBankedFlatToLeftBankedDown25
    (1 << 0), // TrackElemType::RightBankedFlatToRightBankedDown25
    (1 << 0), // TrackElemType::LeftBankedDown25ToLeftBankedFlat
    (1 << 0), // TrackElemType::RightBankedDown25ToRightBankedFlat
    (1 << 0), // TrackElemType::FlatToLeftBankedUp25
    (1 << 0), // TrackElemType::FlatToRightBankedUp25
    (1 << 0), // TrackElemType::LeftBankedUp25ToFlat
    (1 << 0), // TrackElemType::RightBankedUp25ToFlat
    (1 << 0), // TrackElemType::FlatToLeftBankedDown25
    (1 << 0), // TrackElemType::FlatToRightBankedDown25
    (1 << 0), // TrackElemType::LeftBankedDown25ToFlat
    (1 << 0), // TrackElemType::RightBankedDown25ToFlat
    (1 << 0), // TrackElemType::LeftQuarterTurn1TileUp90
    (1 << 0), // TrackElemType::RightQuarterTurn1TileUp90
    (1 << 0), // TrackElemType::LeftQuarterTurn1TileDown90
    (1 << 0), // TrackElemType::RightQuarterTurn1TileDown90
    (1 << 0) | (1 << 2), // TrackElemType::MultiDimUp90ToInvertedFlatQuarterLoop
    (1 << 0) | (1 << 2), // TrackElemType::MultiDimFlatToDown90QuarterLoop
    (1 << 0) | (1 << 2), // 255
};

/** rct2: 0x00999A94 */
const uint8_t TrackSequenceElementAllowedWallEdges[][MaxSequencesPerPiece] = {
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Flat
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::EndStation
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::BeginStation
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::MiddleStation
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up60
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25ToUp60
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up60ToUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25ToFlat
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down60
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25ToDown60
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down60ToDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25ToFlat
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn5Tiles
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn5Tiles
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToLeftBank
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToRightBank
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankToFlat
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankToFlat
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::BankedLeftQuarterTurn5Tiles
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::BankedRightQuarterTurn5Tiles
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankToUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankToUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25ToLeftBank
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25ToRightBank
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankToDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankToDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25ToLeftBank
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25ToRightBank
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBank
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBank
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn5TilesUp25
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn5TilesUp25
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn5TilesDown25
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn5TilesDown25
    { 0b1010, 0b0011, 0b1100, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::SBendLeft
    { 0b1010, 0b1001, 0b0110, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::SBendRight
    { 0b0010, 0b0010, 0b0011,      0,      0,      0,      0, 0b1100, 0b1000, 0b1000,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftVerticalLoop
    { 0b1000, 0b1000, 0b1001,      0,      0,      0,      0, 0b0110, 0b0010, 0b0010,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightVerticalLoop
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn3Tiles
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn3Tiles
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedQuarterTurn3Tiles
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedQuarterTurn3Tiles
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn3TilesUp25
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn3TilesUp25
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn3TilesDown25
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn3TilesDown25
    { 0b0011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn1Tile
    { 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn1Tile
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftTwistDownToUp
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightTwistDownToUp
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftTwistUpToDown
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightTwistUpToDown
    { 0b1010, 0b1010, 0b1011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::HalfLoopUp
    {      0, 0b1011, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::HalfLoopDown
    { 0b1010, 0b0011, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftCorkscrewUp
    { 0b1010, 0b1001, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightCorkscrewUp
    { 0b1010, 0b0011, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftCorkscrewDown
    { 0b1010, 0b1001, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightCorkscrewDown
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToUp60
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up60ToFlat
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToDown60
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down60ToFlat
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::TowerBase
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::TowerSection
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatCovered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25Covered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up60Covered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToUp25Covered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25ToUp60Covered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up60ToUp25Covered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25ToFlatCovered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25Covered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down60Covered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToDown25Covered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25ToDown60Covered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down60ToDown25Covered
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25ToFlatCovered
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn5TilesCovered
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn5TilesCovered
    { 0b1010, 0b0011, 0b1100, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::SBendLeftCovered
    { 0b1010, 0b1001, 0b0110, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::SBendRightCovered
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn3TilesCovered
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn3TilesCovered
    { 0b0010, 0b1100, 0b0011, 0b0001, 0b0001, 0b0110, 0b1001, 0b1000,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftHalfBankedHelixUpSmall
    { 0b1000, 0b0110, 0b1001, 0b0001, 0b0001, 0b1100, 0b0011, 0b0010,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightHalfBankedHelixUpSmall
    { 0b0010, 0b1100, 0b0011, 0b0001, 0b0001, 0b0110, 0b1001, 0b1000,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftHalfBankedHelixDownSmall
    { 0b1000, 0b0110, 0b1001, 0b0001, 0b0001, 0b1100, 0b0011, 0b0010,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightHalfBankedHelixDownSmall
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001, 0b0001, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b1000,      0,      0 }, // TrackElemType::LeftHalfBankedHelixUpLarge
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001, 0b0001, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0010,      0,      0 }, // TrackElemType::RightHalfBankedHelixUpLarge
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001, 0b0001, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b1000,      0,      0 }, // TrackElemType::LeftHalfBankedHelixDownLarge
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001, 0b0001, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0010,      0,      0 }, // TrackElemType::RightHalfBankedHelixDownLarge
    { 0b0011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn1TileUp60
    { 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn1TileUp60
    { 0b0011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn1TileDown60
    { 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn1TileDown60
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Brakes
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RotationControlToggle
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::InvertedUp90ToFlatQuarterLoopAlias / Maze
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterBankedHelixLargeUp
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterBankedHelixLargeUp
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterBankedHelixLargeDown
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterBankedHelixLargeDown
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterHelixLargeUp
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterHelixLargeUp
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterHelixLargeDown
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterHelixLargeDown
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25LeftBanked
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25RightBanked
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Waterfall
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Rapids
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::OnRidePhoto
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25LeftBanked
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25RightBanked
    { 0b1010, 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Watersplash
    { 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToUp60LongBase
    { 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up60ToFlatLongBase
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Whirlpool
    { 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down60ToFlatLongBase
    { 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToDown60LongBase
    { 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::CableLiftHill
    { 0b1010, 0b1010, 0b1010, 0b1010, 0b1010, 0b1011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::ReverseFreefallSlope
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::ReverseFreefallVertical
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up90
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down90
    { 0b1011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up60ToUp90
    { 0b1110,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down90ToDown60
    { 0b1011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up90ToUp60
    { 0b1110,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down60ToDown90
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::BrakeForDrop
    { 0b0010, 0b0010, 0b1000, 0b0011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftEighthToDiag
    { 0b1000, 0b1000, 0b0010, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightEighthToDiag
    {      0, 0b1000, 0b0110, 0b0010, 0b0010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftEighthToOrthogonal
    {      0, 0b0100, 0b1001, 0b0001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightEighthToOrthogonal
    { 0b0010, 0b0010, 0b1000, 0b0011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftEighthBankToDiag
    { 0b1000, 0b1000, 0b0010, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightEighthBankToDiag
    {      0, 0b1000, 0b0110, 0b0010, 0b0010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftEighthBankToOrthogonal
    {      0, 0b0100, 0b1001, 0b0001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightEighthBankToOrthogonal
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagFlat
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagUp25
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagUp60
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagFlatToUp25
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagUp25ToUp60
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagUp60ToUp25
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagUp25ToFlat
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagDown25
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagDown60
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagFlatToDown25
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagDown25ToDown60
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagDown60ToDown25
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagDown25ToFlat
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagFlatToUp60
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagUp60ToFlat
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagFlatToDown60
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagDown60ToFlat
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagFlatToLeftBank
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagFlatToRightBank
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagLeftBankToFlat
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagRightBankToFlat
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagLeftBankToUp25
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagRightBankToUp25
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagUp25ToLeftBank
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagUp25ToRightBank
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagLeftBankToDown25
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagRightBankToDown25
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagDown25ToLeftBank
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagDown25ToRightBank
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagLeftBank
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::DiagRightBank
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LogFlumeReverser
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::SpinningTunnel
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBarrelRollUpToDown
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBarrelRollUpToDown
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBarrelRollDownToUp
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBarrelRollDownToUp
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankToLeftQuarterTurn3TilesUp25
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankToRightQuarterTurn3TilesUp25
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn3TilesDown25ToLeftBank
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn3TilesDown25ToRightBank
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::PoweredLift
    { 0b1010, 0b1010, 0b0010, 0b0011, 0b1001, 0b1000, 0b1000,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftLargeHalfLoopUp
    { 0b1010, 0b1010, 0b1000, 0b1001, 0b0011, 0b0010, 0b0010,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightLargeHalfLoopUp
    { 0b0010, 0b0010, 0b0011, 0b1001, 0b1000, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightLargeHalfLoopDown
    { 0b1000, 0b1000, 0b1001, 0b0011, 0b0010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftLargeHalfLoopDown
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftFlyerTwistUp
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightFlyerTwistUp
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftFlyerTwistDown
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightFlyerTwistDown
    { 0b1010, 0b1010, 0b1011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlyerHalfLoopUp
    {      0, 0b1011, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlyerHalfLoopDown
    { 0b1010, 0b0011, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftFlyerCorkscrewUp
    { 0b1010, 0b1001, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightFlyerCorkscrewUp
    { 0b1010, 0b0011, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftFlyerCorkscrewDown
    { 0b1010, 0b1001, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightFlyerCorkscrewDown
    { 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::HeartLineTransferUp
    { 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::HeartLineTransferDown
    { 0b1010, 0b1010, 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftHeartLineRoll
    { 0b1010, 0b1010, 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightHeartLineRoll
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::MinigolfHoleA
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::MinigolfHoleB
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::MinigolfHoleC
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::MinigolfHoleD
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::MinigolfHoleE
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::MultiDimInvertedFlatToDown90QuarterLoop
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up90ToInvertedFlatQuarterLoop
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::InvertedFlatToDown90QuarterLoop
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftCurvedLiftHill
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightCurvedLiftHill
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftReverser
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightReverser
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::AirThrustTopCap
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::AirThrustVerticalDown
    { 0b1010, 0b1010, 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::AirThrustVerticalDownToLevel
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::BlockBrakes
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedQuarterTurn3TileUp25
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedQuarterTurn3TileUp25
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedQuarterTurn3TileDown25
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedQuarterTurn3TileDown25
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedQuarterTurn5TileUp25
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedQuarterTurn5TileUp25
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedQuarterTurn5TileDown25
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedQuarterTurn5TileDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25ToLeftBankedUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Up25ToRightBankedUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedUp25ToUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedUp25ToUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25ToLeftBankedDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::Down25ToRightBankedDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedDown25ToDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedDown25ToDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedFlatToLeftBankedUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedFlatToRightBankedUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedUp25ToLeftBankedFlat
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedUp25ToRightBankedFlat
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedFlatToLeftBankedDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedFlatToRightBankedDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedDown25ToLeftBankedFlat
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedDown25ToRightBankedFlat
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToLeftBankedUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToRightBankedUp25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedUp25ToFlat
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedUp25ToFlat
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToLeftBankedDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::FlatToRightBankedDown25
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftBankedDown25ToFlat
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightBankedDown25ToFlat
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn1TileUp90
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn1TileUp90
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::LeftQuarterTurn1TileDown90
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::RightQuarterTurn1TileDown90
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::MultiDimUp90ToInvertedFlatQuarterLoop
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // TrackElemType::MultiDimFlatToDown90QuarterLoop
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // 255
};

/** rct2: 0x0099AA94 */
const uint8_t FlatRideTrackSequenceElementAllowedWallEdges[][MaxSequencesPerPiece] = {
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b0011, 0b1100, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1001, 0b0110, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b0010, 0b0011,      0,      0,      0,      0, 0b1100, 0b1000, 0b1000,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b1000, 0b1001,      0,      0,      0,      0, 0b0110, 0b0010, 0b0010,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b1011, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b0011, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1001, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b0011, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1001, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b0011, 0b1100, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1001, 0b0110, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001, 0b0001, 0b0110, 0b1001, 0b1000,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001, 0b0001, 0b1100, 0b0011, 0b0010,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001, 0b0001, 0b0110, 0b1001, 0b1000,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001, 0b0001, 0b1100, 0b0011, 0b0010,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001, 0b0001, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b1000,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001, 0b0001, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0010,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001, 0b0001, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b1000,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001, 0b0001, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0010,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // FLAT_TRACK_ELEM_1_X_4_A
    { 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // FLAT_TRACK_ELEM_2_X_2
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // FLAT_TRACK_ELEM_4_X_4
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // FLAT_TRACK_ELEM_1_X_5
    { 0b1010, 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // FLAT_TRACK_ELEM_1_X_1_A
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // FLAT_TRACK_ELEM_1_X_4_B
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // FLAT_TRACK_ELEM_1_X_1_B
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // FLAT_TRACK_ELEM_1_X_4_C
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }, // FLAT_TRACK_ELEM_3_X_3
    { 0b1010, 0b1010, 0b1010, 0b1010, 0b1010, 0b1011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1110,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1110,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b0010, 0b1000, 0b0011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b1000, 0b0010, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b1000, 0b0110, 0b0010, 0b0010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0100, 0b1001, 0b0001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b0010, 0b1000, 0b0011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b1000, 0b0010, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b1000, 0b0110, 0b0010, 0b0010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0100, 0b1001, 0b0001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b0110, 0b1001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b0010, 0b0011, 0b1001, 0b1000, 0b1000,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1000, 0b1001, 0b0011, 0b0010, 0b0010,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b0010, 0b0011, 0b1001, 0b1000, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b1000, 0b1001, 0b0011, 0b0010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1011,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0, 0b1011, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b0011, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1001, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b0011, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1001, 0b0101,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010, 0b1010, 0b1010, 0b1010, 0b1010, 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b0010, 0b1100, 0b0011,      0, 0b1100, 0b0011, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1000, 0b0110, 0b1001,      0, 0b0110, 0b1001, 0b0001,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1010,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
    { 0b1111,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
};

/** rct2: 0x0099443C */
const uint16_t FlatTrackFlags[] = {
    /*                                                                 */   TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   0,
    /*                                                                 */   0,
    /*                                                                 */   0,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /*                                                                 */   0,
    /*                                                                 */   0,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   0,
    /*                                                                 */   0,
    /*                                                                 */   0,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_UP,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /*                                                                 */   0,
    /*                                                                 */   0,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* FLAT_TRACK_ELEM_1_X_4_A                                         */   0,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   0,
    /*                                                                 */   0,
    /*                                                                 */   TRACK_ELEM_FLAG_ONLY_ABOVE_GROUND,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX,
    /* FLAT_TRACK_ELEM_2_X_2                                           */   0,
    /* FLAT_TRACK_ELEM_4_X_4                                           */   0,
    /*                                                                 */   0,
    /*                                                                 */   0,
    /*                                                                 */   TRACK_ELEM_FLAG_ONLY_ABOVE_GROUND,
    /* ???                                                             */   TRACK_ELEM_FLAG_ONLY_ABOVE_GROUND,
    /* FLAT_TRACK_ELEM_1_X_5                                           */   0,
    /*                                                                 */   0,
    /* FLAT_TRACK_ELEM_1_X_1_A                                         */   0,
    /* FLAT_TRACK_ELEM_1_X_4_B                                         */   0,
    /*                                                                 */   0,
    /* FLAT_TRACK_ELEM_1_X_1_B                                         */   0,
    /* FLAT_TRACK_ELEM_1_X_4_C                                         */   0,
    /* FLAT_TRACK_ELEM_3_X_3                                           */   0,
    /*                                                                 */   TRACK_ELEM_FLAG_UP,
    /*                                                                 */   TRACK_ELEM_FLAG_UP,
    /*                                                                 */   TRACK_ELEM_FLAG_UP,
    /* ???                                                             */   TRACK_ELEM_FLAG_DOWN,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* ???                                                             */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_UP,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   0,
    /*                                                                 */   0,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION,
    /*                                                                 */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION,
    /* ???                                                             */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION,
    /* ???                                                             */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION,
    /* ???                                                             */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_UP,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_UP,
    /*                                                                 */   0,
    /*                                                                 */   0,
    /*                                                                 */   0,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN,
    /*                                                                 */   0,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN,
    /*                                                                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN,
    /* ???                                                             */   0,
};

/** rct2: 0x0099423C */
const uint16_t TrackFlags[] = {
    /* TrackElemType::Flat                                          */   TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::EndStation                                    */   0,
    /* TrackElemType::BeginStation                                  */   0,
    /* TrackElemType::MiddleStation                                 */   0,
    /* TrackElemType::Up25                                          */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Up60                                          */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::FlatToUp25                                    */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Up25ToUp60                                    */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Up60ToUp25                                    */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Up25ToFlat                                    */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Down25                                        */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Down60                                        */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::FlatToDown25                                  */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Down25ToDown60                                */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Down60ToDown25                                */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Down25ToFlat                                  */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::LeftQuarterTurn5Tiles                         */   TRACK_ELEM_FLAG_TURN_LEFT,
    /* TrackElemType::RightQuarterTurn5Tiles                        */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /* TrackElemType::FlatToLeftBank                                */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::FlatToRightBank                               */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankToFlat                                */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankToFlat                               */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::BankedLeftQuarterTurn5Tiles                   */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::BankedRightQuarterTurn5Tiles                  */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankToUp25                                */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankToUp25                               */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Up25ToLeftBank                                */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Up25ToRightBank                               */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankToDown25                              */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankToDown25                             */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Down25ToLeftBank                              */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Down25ToRightBank                             */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBank                                      */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBank                                     */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftQuarterTurn5TilesUp25                     */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /* TrackElemType::RightQuarterTurn5TilesUp25                    */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /* TrackElemType::LeftQuarterTurn5TilesDown25                   */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /* TrackElemType::RightQuarterTurn5TilesDown25                  */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /* TrackElemType::SBendLeft                                     */   0,
    /* TrackElemType::SBendRight                                    */   0,
    /* TrackElemType::LeftVerticalLoop                              */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightVerticalLoop                             */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftQuarterTurn3Tiles                         */   TRACK_ELEM_FLAG_TURN_LEFT,
    /* TrackElemType::RightQuarterTurn3Tiles                        */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /* TrackElemType::LeftBankedQuarterTurn3Tiles                   */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedQuarterTurn3Tiles                  */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftQuarterTurn3TilesUp25                     */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /* TrackElemType::RightQuarterTurn3TilesUp25                    */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /* TrackElemType::LeftQuarterTurn3TilesDown25                   */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /* TrackElemType::RightQuarterTurn3TilesDown25                  */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL | TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT,
    /* TrackElemType::LeftQuarterTurn1Tile                          */   TRACK_ELEM_FLAG_TURN_LEFT,
    /* TrackElemType::RightQuarterTurn1Tile                         */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /* TrackElemType::LeftTwistDownToUp                             */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightTwistDownToUp                            */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftTwistUpToDown                             */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightTwistUpToDown                            */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::HalfLoopUp                                    */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::HalfLoopDown                                  */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftCorkscrewUp                               */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightCorkscrewUp                              */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftCorkscrewDown                             */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightCorkscrewDown                            */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::FlatToUp60                                    */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Up60ToFlat                                    */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::FlatToDown60                                  */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Down60ToFlat                                  */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::TowerBase                                     */   0,
    /* TrackElemType::TowerSection                                  */   0,
    /* TrackElemType::FlatCovered                                   */   0,
    /* TrackElemType::Up25Covered                                   */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::Up60Covered                                   */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::FlatToUp25Covered                             */   TRACK_ELEM_FLAG_UP,
    /* TrackElemType::Up25ToUp60Covered                             */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::Up60ToUp25Covered                             */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::Up25ToFlatCovered                             */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::Down25Covered                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::Down60Covered                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::FlatToDown25Covered                           */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::Down25ToDown60Covered                         */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::Down60ToDown25Covered                         */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::Down25ToFlatCovered                           */   TRACK_ELEM_FLAG_DOWN,
    /* TrackElemType::LeftQuarterTurn5TilesCovered                  */   TRACK_ELEM_FLAG_TURN_LEFT,
    /* TrackElemType::RightQuarterTurn5TilesCovered                 */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /* TrackElemType::SBendLeftCovered                              */   0,
    /* TrackElemType::SBendRightCovered                             */   0,
    /* TrackElemType::LeftQuarterTurn3TilesCovered                  */   TRACK_ELEM_FLAG_TURN_LEFT,
    /* TrackElemType::RightQuarterTurn3TilesCovered                 */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /* TrackElemType::LeftHalfBankedHelixUpSmall                    */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightHalfBankedHelixUpSmall                   */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftHalfBankedHelixDownSmall                  */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightHalfBankedHelixDownSmall                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftHalfBankedHelixUpLarge                    */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightHalfBankedHelixUpLarge                   */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftHalfBankedHelixDownLarge                  */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightHalfBankedHelixDownLarge                 */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftQuarterTurn1TileUp60                      */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::RightQuarterTurn1TileUp60                     */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::LeftQuarterTurn1TileDown60                    */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::RightQuarterTurn1TileDown60                   */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::Brakes                                        */   0,
    /* TrackElemType::RotationControlToggle                         */   0,
    /* TrackElemType::InvertedUp90ToFlatQuarterLoopAlias / Maze     */   TRACK_ELEM_FLAG_ONLY_ABOVE_GROUND,
    /* TrackElemType::LeftQuarterBankedHelixLargeUp                 */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightQuarterBankedHelixLargeUp                */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftQuarterBankedHelixLargeDown               */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightQuarterBankedHelixLargeDown              */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftQuarterHelixLargeUp                       */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX,
    /* TrackElemType::RightQuarterHelixLargeUp                      */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX,
    /* TrackElemType::LeftQuarterHelixLargeDown                     */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_HELIX,
    /* TrackElemType::RightQuarterHelixLargeDown                    */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_HELIX,
    /* TrackElemType::Up25LeftBanked                                */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Up25RightBanked                               */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Waterfall                                     */   0,
    /* TrackElemType::Rapids                                        */   0,
    /* TrackElemType::OnRidePhoto                                   */   0,
    /* TrackElemType::Down25LeftBanked                              */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Down25RightBanked                             */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Watersplash                                   */   0,
    /* TrackElemType::FlatToUp60LongBase                            */   TRACK_ELEM_FLAG_UP,
    /* TrackElemType::Up60ToFlatLongBase                            */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::Whirlpool                                     */   0,
    /* TrackElemType::Down60ToFlatLongBase                          */   TRACK_ELEM_FLAG_DOWN,
    /* TrackElemType::FlatToDown60LongBase                          */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::CableLiftHill                                 */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::ReverseFreefallSlope                          */ TRACK_ELEM_FLAG_UP,
    /* TrackElemType::ReverseFreefallVertical                       */ TRACK_ELEM_FLAG_UP,
    /* TrackElemType::Up90                                          */   TRACK_ELEM_FLAG_UP,
    /* TrackElemType::Down90                                        */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Up60ToUp90                                    */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::Down90ToDown60                                */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::Up90ToUp60                                    */   TRACK_ELEM_FLAG_UP,
    /* TrackElemType::Down60ToDown90                                */   TRACK_ELEM_FLAG_DOWN,
    /* TrackElemType::BrakeForDrop                                  */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::LeftEighthToDiag                              */   TRACK_ELEM_FLAG_TURN_LEFT,
    /* TrackElemType::RightEighthToDiag                             */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /* TrackElemType::LeftEighthToOrthogonal                        */   TRACK_ELEM_FLAG_TURN_LEFT,
    /* TrackElemType::RightEighthToOrthogonal                       */   TRACK_ELEM_FLAG_TURN_RIGHT,
    /* TrackElemType::LeftEighthBankToDiag                          */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightEighthBankToDiag                         */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftEighthBankToOrthogonal                    */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightEighthBankToOrthogonal                   */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_BANKED | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagFlat                                      */   TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagUp25                                      */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagUp60                                      */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagFlatToUp25                                */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagUp25ToUp60                                */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagUp60ToUp25                                */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagUp25ToFlat                                */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagDown25                                    */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagDown60                                    */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagFlatToDown25                              */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagDown25ToDown60                            */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagDown60ToDown25                            */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagDown25ToFlat                              */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagFlatToUp60                                */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagUp60ToFlat                                */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_IS_STEEP_UP | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagFlatToDown60                              */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagDown60ToFlat                              */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_ALLOW_LIFT_HILL,
    /* TrackElemType::DiagFlatToLeftBank                            */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagFlatToRightBank                           */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagLeftBankToFlat                            */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagRightBankToFlat                           */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagLeftBankToUp25                            */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagRightBankToUp25                           */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagUp25ToLeftBank                            */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagUp25ToRightBank                           */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagLeftBankToDown25                          */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagRightBankToDown25                         */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagDown25ToLeftBank                          */   TRACK_ELEM_FLAG_DOWN,
    /* TrackElemType::DiagDown25ToRightBank                         */   TRACK_ELEM_FLAG_DOWN,
    /* TrackElemType::DiagLeftBank                                  */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::DiagRightBank                                 */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LogFlumeReverser                              */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::SpinningTunnel                                */   TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBarrelRollUpToDown                        */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightBarrelRollUpToDown                       */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftBarrelRollDownToUp                        */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightBarrelRollDownToUp                       */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftBankToLeftQuarterTurn3TilesUp25           */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankToRightQuarterTurn3TilesUp25         */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftQuarterTurn3TilesDown25ToLeftBank         */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightQuarterTurn3TilesDown25ToRightBank       */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::PoweredLift                                   */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT,
    /* TrackElemType::LeftLargeHalfLoopUp                           */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightLargeHalfLoopUp                          */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightLargeHalfLoopDown                        */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftLargeHalfLoopDown                         */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftFlyerTwistUp                              */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightFlyerTwistUp                             */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftFlyerTwistDown                            */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightFlyerTwistDown                           */   TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::FlyerHalfLoopUp                               */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::FlyerHalfLoopDown                             */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftFlyerCorkscrewUp                          */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightFlyerCorkscrewUp                         */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftFlyerCorkscrewDown                        */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightFlyerCorkscrewDown                       */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::HeartLineTransferUp                           */   0,
    /* TrackElemType::HeartLineTransferDown                         */   0,
    /* TrackElemType::LeftHeartLineRoll                             */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::RightHeartLineRoll                            */   TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::MinigolfHoleA                                 */   TRACK_ELEM_FLAG_IS_GOLF_HOLE,
    /* TrackElemType::MinigolfHoleB                                 */   TRACK_ELEM_FLAG_IS_GOLF_HOLE,
    /* TrackElemType::MinigolfHoleC                                 */   TRACK_ELEM_FLAG_IS_GOLF_HOLE,
    /* TrackElemType::MinigolfHoleD                                 */   TRACK_ELEM_FLAG_IS_GOLF_HOLE,
    /* TrackElemType::MinigolfHoleE                                 */   TRACK_ELEM_FLAG_IS_GOLF_HOLE,
    /* TrackElemType::MultiDimInvertedFlatToDown90QuarterLoop       */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::Up90ToInvertedFlatQuarterLoop                 */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::InvertedFlatToDown90QuarterLoop               */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::LeftCurvedLiftHill                            */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_UP,
    /* TrackElemType::RightCurvedLiftHill                           */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_UP,
    /* TrackElemType::LeftReverser                                  */   0,
    /* TrackElemType::RightReverser                                 */   0,
    /* TrackElemType::AirThrustTopCap                               */   0,
    /* TrackElemType::AirThrustVerticalDown                         */   TRACK_ELEM_FLAG_DOWN,
    /* TrackElemType::AirThrustVerticalDownToLevel                  */   TRACK_ELEM_FLAG_DOWN,
    /* TrackElemType::BlockBrakes                                   */   0,
    /* TrackElemType::LeftBankedQuarterTurn3TileUp25                */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedQuarterTurn3TileUp25               */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankedQuarterTurn3TileDown25              */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedQuarterTurn3TileDown25             */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankedQuarterTurn5TileUp25                */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedQuarterTurn5TileUp25               */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankedQuarterTurn5TileDown25              */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedQuarterTurn5TileDown25             */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Up25ToLeftBankedUp25                          */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Up25ToRightBankedUp25                         */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankedUp25ToUp25                          */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedUp25ToUp25                         */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Down25ToLeftBankedDown25                      */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::Down25ToRightBankedDown25                     */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankedDown25ToDown25                      */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedDown25ToDown25                     */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankedFlatToLeftBankedUp25                */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedFlatToRightBankedUp25              */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankedUp25ToLeftBankedFlat                */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedUp25ToRightBankedFlat              */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankedFlatToLeftBankedDown25              */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedFlatToRightBankedDown25            */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankedDown25ToLeftBankedFlat              */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedDown25ToRightBankedFlat            */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::FlatToLeftBankedUp25                          */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::FlatToRightBankedUp25                         */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankedUp25ToFlat                          */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedUp25ToFlat                         */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::FlatToLeftBankedDown25                        */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::FlatToRightBankedDown25                       */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftBankedDown25ToFlat                        */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::RightBankedDown25ToFlat                       */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_BANKED,
    /* TrackElemType::LeftQuarterTurn1TileUp90                      */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP,
    /* TrackElemType::RightQuarterTurn1TileUp90                     */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_UP,
    /* TrackElemType::LeftQuarterTurn1TileDown90                    */   TRACK_ELEM_FLAG_TURN_LEFT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN,
    /* TrackElemType::RightQuarterTurn1TileDown90                   */   TRACK_ELEM_FLAG_TURN_RIGHT | TRACK_ELEM_FLAG_TURN_SLOPED | TRACK_ELEM_FLAG_DOWN,
    /* TrackElemType::MultiDimUp90ToInvertedFlatQuarterLoop         */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /* TrackElemType::MultiDimFlatToDown90QuarterLoop               */   TRACK_ELEM_FLAG_DOWN | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
    /*                                                              */   TRACK_ELEM_FLAG_UP | TRACK_ELEM_FLAG_NORMAL_TO_INVERSION | TRACK_ELEM_FLAG_INVERSION_TO_NORMAL,
};
// clang-format on
