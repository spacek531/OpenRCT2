/*****************************************************************************
 * Copyright (c) 2014-2025 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once
#include "../entity/Yaw.hpp"
#include "../ride/Angles.h"
#include "../world/Location.hpp"

#include <array>
#include <cstddef>

namespace OpenRCT2::Math::Trigonometry
{
    /**
     * The cos and sin of sprite direction
     * ROUND(COS((32/64+(L1/64))*(2*PI()))*256,0), ROUND(SIN(((L1/64))*(2*PI())) * 256,0)
     * Where L1 represents an incrementing column 0 - 63
     * Note: Must be at least 32bit to ensure all users do not overflow
     */
    static constexpr std::array<CoordsXY, 64> YawToDirectionVector = {
        CoordsXY{ -256, 0 }, { -255, 25 },   { -251, 50 },   { -245, 74 },   { -237, 98 },   { -226, 121 },  { -213, 142 },
        { -198, 162 },       { -181, 181 },  { -162, 198 },  { -142, 213 },  { -121, 226 },  { -98, 237 },   { -74, 245 },
        { -50, 251 },        { -25, 255 },   { 0, 256 },     { 25, 255 },    { 50, 251 },    { 74, 245 },    { 98, 237 },
        { 121, 226 },        { 142, 213 },   { 162, 198 },   { 181, 181 },   { 198, 162 },   { 213, 142 },   { 226, 121 },
        { 237, 98 },         { 245, 74 },    { 251, 50 },    { 255, 25 },    { 256, 0 },     { 255, -25 },   { 251, -50 },
        { 245, -74 },        { 237, -98 },   { 226, -121 },  { 213, -142 },  { 198, -162 },  { 181, -181 },  { 162, -198 },
        { 142, -213 },       { 121, -226 },  { 98, -237 },   { 74, -245 },   { 50, -251 },   { 25, -255 },   { 0, -256 },
        { -25, -255 },       { -50, -251 },  { -74, -245 },  { -98, -237 },  { -121, -226 }, { -142, -213 }, { -162, -198 },
        { -181, -181 },      { -198, -162 }, { -213, -142 }, { -226, -121 }, { -237, -98 },  { -245, -74 },  { -251, -50 },
        { -255, -25 },
    };
    // Currently OpenRCT2::Entity::Yaw::BaseSpritePrecision is 32, but one day it will be 64.
    static_assert(std::size(YawToDirectionVector) == 64);

    /**
     * The cos and sin of vehicle pitch based on vehicle sprite angles
     * COS((Y1/360)*2*PI())*256,-SIN((Y1/360)*2*PI())*256
     * Where Y1 represents the angle of pitch in degrees
     */
    constexpr std::array<CoordsXY, EnumValue(VehiclePitch::pitchCount)> PitchToDirectionVectorFromGeometry = {
        CoordsXY{ 256, 0 }, // flat
        { 251, 49 },        // slopes up
        { 236, 97 },        // slopes up
        { 195, 165 },       // slopes up
        { 134, 217 },       // slopes up
        { 251, -49 },       // slopes down
        { 236, -97 },       // slopes down
        { 195, -165 },      // slopes down
        { 135, -217 },      // slopes down
        { 70, 246 },        // slopes vertical up
        { 0, 256 },         // slopes vertical up
        { -66, 247 },       // slopes looping up
        { -128, 221 },      // slopes looping up
        { -181, 181 },      // slopes looping up
        { -221, 128 },      // slopes looping up
        { -247, 66 },       // slopes looping up
        { -256, 0 },        // inverted
        { 70, -246 },       // slopes vertical down
        { 0, -256 },        // slopes vertical down
        { -66, -247 },      // slopes looping down
        { -128, -221 },     // slopes looping down
        { -181, -181 },     // slopes looping down
        { -221, -128 },     // slopes looping down
        { -247, -66 },      // slopes looping down
        { 221, 128 },       // corkscrew up left
        { 128, 221 },       // corkscrew up left
        { 0, 256 },         // corkscrew up left
        { -128, 221 },      // corkscrew up left
        { -221, 128 },      // corkscrew up left
        { -221, -128 },     // corkscrew down left
        { -128, -221 },     // corkscrew down left
        { 0, -256 },        // corkscrew down left
        { 128, -221 },      // corkscrew down left
        { 221, -128 },      // corkscrew down left
        { 221, 128 },       // corkscrew up right
        { 128, 221 },       // corkscrew up right
        { 0, 256 },         // corkscrew up right
        { -128, 221 },      // corkscrew up right
        { -221, 128 },      // corkscrew up right
        { -221, -128 },     // corkscrew down right
        { -128, -221 },     // corkscrew down right
        { 0, -256 },        // corkscrew down right
        { 128, -221 },      // corkscrew down right
        { 221, 128 },       // corkscrew down right
        { 256, 0 },         // half helixes
        { 256, 0 },         // half helixes
        { 256, 0 },         // half helixes
        { 256, 0 },         // half helixes
        { 256, 0 },         // quarter helixes
        { 256, 0 },         // quarter helixes
        { 252, 42 },        // diagonal slopes up
        { 241, 83 },        // diagonal slopes up
        { 168, 193 },       // diagonal slopes up
        { 252, -42 },       // diagonal slopes down
        { 241, -83 },       // diagonal slopes down
        { 168, -193 },      // diagonal slopes down
        { 236, -97 },       // inverting transition slopes down
        { 195, -165 },      // inverting transition slopes down
        { 134, -217 },      // inverting transition slopes down
        { 252, 44 },        // spiral lift hill up
        { 252, -44 },       // spiral lift hill down
    };
    static_assert(std::size(PitchToDirectionVectorFromGeometry) == EnumValue(VehiclePitch::pitchCount));

    constexpr int32_t ComputeHorizontalMagnitude(int32_t length, uint8_t pitch)
    {
        return (-PitchToDirectionVectorFromGeometry[pitch].y * length) / 256;
    }

    constexpr CoordsXY ComputeXYVector(int32_t magnitude, uint8_t yaw)
    {
        return (static_cast<CoordsXY>(YawToDirectionVector[yaw]) * magnitude) / 256;
    }

    constexpr CoordsXY ComputeXYVector(int32_t length, uint8_t pitch, uint8_t yaw)
    {
        return ComputeXYVector(ComputeHorizontalMagnitude(length, pitch), yaw);
    }

    /** rct2: 0x009A2930
        The distance between subposition points in a movement direction (but not distance).
        */
    constexpr std::array<int32_t, 16> SubpositionTranslationDistances = {
        // For a base length of 8716 (0x220C) on the horizontal and 6554 (0x199A) on the vertical,
        // use the Pythagoras theorem and round up.
        0,     // no movement
        8716,  // X translation
        8716,  // Y translation
        12327, // XY translation
        6554,  // Z translation
        10905, // XZ translation
        10905, // YZ translation
        13961, // XYZ translation
        // For the reverser car, multiply the horizontal distance by 2.5 and the vertical distance by 4.072.
        0,     // no movement
        21790, // X translation
        21790, // Y translation
        30817, // Z translation
        16385, // XY translation
        27262, // XZ translation
        27262, // YZ translation
        34902, // XYZ translation
    };

    constexpr int32_t GetPythagorasDistance(CoordsXYZ distance, bool useReverserDistance = false)
    {
        uint8_t index = ((distance.x != 0) << 0) | ((distance.y != 0) << 1) | ((distance.z != 0) << 2)
            | ((useReverserDistance) << 3);
        return SubpositionTranslationDistances[index];
    }

    /** rct2: 0x009A2970 */
    const int32_t AccelerationFromPitch[] = {
        0,       // Flat
                 // The geometric angle of slopes 12.5 and 25 are actually 11.1 and 22.2 respectively.
        -124548, // 1 Slope Up 12.5
        -243318, // 2 Slope Up 25
        -416016, // 3 Slope Up 42.5
        -546342, // 4 Slope Up 60
        124548,  // 5 Slope Down 12.5
        243318,  // 6 Slope Down 25
        416016,  // 7 Slope Down 42.5
        546342,  // 8 Slope Down 60
        -617604, // 9 Slope Up 75
        -642000, // 10 Slope Up 90
        -620172, // 11 Slope Up 105
        -555972, // 12 Slope Up 120
        -453894, // 13 Slope Up 135
        -321000, // 14 Slope Up 150
        -166278, // 15 Slope Up 165
        0,       // 16 Fully Inverted
        617604,  // 17 Slope Down 75
        642000,  // 18 Slope Down 90
        620172,  // 19 Slope Down 105
        555972,  // 20 Slope Down 120
        453894,  // 21 Slope Down 135
        321000,  // 22 Slope Down 150
        166278,  // 23 Slope Down 165
        -321000, // 24 Corkscrew Right Up 0
        -555972, // 25 Corkscrew Right Up 1
        -642000, // 26 Corkscrew Right Up 2
        -555972, // 27 Corkscrew Right Up 3
        -321000, // 28 Corkscrew Right Up 4
        321000,  // 29 Corkscrew Right Down 4
        555972,  // 30 Corkscrew Right Down 3
        642000,  // 31 Corkscrew Right Down 2
        555972,  // 32 Corkscrew Right Down 1
        321000,  // 33 Corkscrew Right Down 0
        -321000, // 34 Corkscrew Left Up 0
        -555972, // 35 Corkscrew Left Up 1
        -642000, // 36 Corkscrew Left Up 2
        -555972, // 37 Corkscrew Left Up 3
        -321000, // 38 Corkscrew Left Up 4
        321000,  // 39 Corkscrew Left Down 4
        555972,  // 40 Corkscrew Left Down 2
        642000,  // 41 Corkscrew Left Down 1
        555972,  // 42 Corkscrew Left Down 1
        321000,  // 43 Corkscrew Left Down 0
        -33384,  // 44 Half Helix Up Large
        -55854,  // 45 Half Helix Up Small
        33384,   // 46 Half Helix Down Large
        55854,   // 47 Half Helix Down Small
        -66768,  // 48 Quarter Helix Up
        66768,   // 49 Quarter Helix Down
        // currently only diagonal elements use slopes angles 8, 16, 50. Diagonal gentle-to-steep transition uses
        // diagonal sprites of slopes 25 and 42.
        -90522,  // 50 Slope Up 8
        -179760, // 51 Slope Down 16
        -484068, // 52 Slope Up 50
        90522,   // 53 Slope Down 8
        179760,  // 54 Slope Down 16
        484068,  // 55 Slope Down 50
        243318,  // 56 Inverting Loop Down 25
        416016,  // 57 Inverting Loop Down 42.5
        546342,  // 58 Inverting Loop Down 60
        -110424, // 59 Slope Up Spiral Lift Hill
    };

    /** rct2: 0x009A3684 */
    constexpr std::array<int32_t, OpenRCT2::Entity::Yaw::kBaseRotation> SpriteDirectionToSoundDirection = {
        -0x4000, // 0
        -0x3000, // 1
        -0x2000, // 2
        -0x1000, // 3
        0,       // 4
        0x1000,  // 5
        0x2000,  // 6
        0x3000,  // 7
        0x4000,  // 8
        0x4800,  // 9
        0x4800,  // 10
        0x4800,  // 11
        0x4800,  // 12
        0x4800,  // 13
        0x4800,  // 14
        0x4800,  // 15
        0x4000,  // 16
        0x3000,  // 17
        0x2000,  // 18
        0x1000,  // 19
        0,       // 20
        -0x1000, // 21
        -0x2000, // 22
        -0x3000, // 23
        -0x4000, // 24
        -0x4800, // 25
        -0x4800, // 26
        -0x4800, // 27
        -0x4800, // 28
        -0x4800, // 29
        -0x4800, // 30
        -0x4800, // 31
    };

    /** rct2: 0x009A37E4 */
    static constexpr int32_t kUnk9A37E4[] = {
        2147483647,  2106585154,  1985590284,  1636362342,  1127484953,  2106585154,  1985590284,  1636362342,  1127484953,
        58579923,    0,           -555809667,  -1073741824, -1518500249, -1859775391, -2074309916, -2147483647, 58579923,
        0,           -555809667,  -1073741824, -1518500249, -1859775391, -2074309916, 1859775393,  1073741824,  0,
        -1073741824, -1859775393, 1859775393,  1073741824,  0,           -1073741824, -1859775393, 1859775393,  1073741824,
        0,           -1073741824, -1859775393, 1859775393,  1073741824,  0,           -1073741824, -1859775393, 2144540595,
        2139311823,  2144540595,  2139311823,  2135719507,  2135719507,  2125953864,  2061796213,  1411702590,  2125953864,
        2061796213,  1411702590,  1985590284,  1636362342,  1127484953,  2115506168,  -2115506168,
    };

    /** rct2: 0x009A38D4 */
    static constexpr int32_t kUnk9A38D4[] = {
        0,           417115092,   817995863,   1390684831,  1827693544,  -417115092,  -817995863,  -1390684831, -1827693544,
        2066040965,  2147483647,  2074309916,  1859775393,  1518500249,  1073741824,  555809666,   0,           -2066040965,
        -2147483647, -2074309916, -1859775393, -1518500249, -1073741824, -555809666,  1073741824,  1859775393,  2147483647,
        1859775393,  1073741824,  -1073741824, -1859775393, -2147483647, -1859775393, -1073741824, 1073741824,  1859775393,
        2147483647,  1859775393,  1073741824,  -1073741824, -1859775393, -2147483647, -1859775393, -1073741824, 112390610,
        187165532,   -112390610,  -187165532,  224473165,   -224473165,  303325208,   600568389,   1618265062,  -303325208,
        -600568389,  -1618265062, -817995863,  -1390684831, -1827693544, 369214930,   -369214930,
    };

    /** rct2: 0x009A39C4 */
    constexpr std::array<int32_t, OpenRCT2::Entity::Yaw::kBaseRotation> kUnk9A39C4[] = {
        2147483647,  2096579710,  1946281152,  2096579710, 1946281152, 1380375879, 555809667,
        -372906620,  -1231746017, -1859775391, 1380375879, 555809667,  -372906620, -1231746017,
        -1859775391, 0,           2096579710,  1946281152, 2096579710, 1946281152,
    };

    /** rct2: 0x009A36C4 */
    constexpr std::array<CoordsXY, OpenRCT2::Entity::Yaw::kBaseRotation> FreeRoamMovementData = {
        CoordsXY{ -1, 0 }, { -1, 0 }, { -1, 0 }, { -1, 1 },  { -1, 1 },  { -1, 1 },  { 0, 1 },  { -1, 1 },
        { 0, 1 },  { 0, 1 },  { 0, 1 },  { 1, 1 },   { 1, 1 },   { 1, 1 },   { 1, 0 },  { 1, 1 },
        { 1, 0 },  { 1, 0 },  { 1, 0 },  { 1, -1 },  { 1, -1 },  { 1, -1 },  { 0, -1 }, { 1, -1 },
        { 0, -1 }, { 0, -1 }, { 0, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, 0 }, { -1, -1 },
    };

    constexpr CoordsXY GetFreeRoamMovementData(uint8_t yaw)
    {
        return FreeRoamMovementData[yaw];
    }

    /** rct2: 0x009A3AC4, 0x009A3AC6 */
    constexpr std::array<CoordsXY, OpenRCT2::Entity::Yaw::kBaseRotation> stru_9A3AC4[] = {
        CoordsXY{ -256, 0 }, { -236, 98 },  { -181, 181 },  { -98, 236 },  { 0, 256 },    { 98, 236 },
        { 181, 181 },        { 236, 98 },   { 256, 0 },     { 236, -98 },  { 181, -181 }, { 98, -236 },
        { 0, -256 },         { -98, -236 }, { -181, -181 }, { -236, -98 },
    };
} // namespace OpenRCT2::Math::Trigonometry
