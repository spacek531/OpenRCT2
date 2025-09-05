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

    /** rct2: 0x009A2970
     * The sin of vehicle pitch based on track angles
     * -SIN((Y1/360)*2*PI())*642000
     * Where Y1 represents the angle of pitch in degrees
     * Note that some values are not correct and these incorrect values are preserved for backwards-compatibility.
     */
    static constexpr int32_t AccelerationFromPitch[] = {
        0,       // flat
        -124548, // up12
        -243318, // up25
        -416016, // up42
        -546342, // up60
        124548,  // down12
        243318,  // down25
        416016,  // down42
        546342,  // down60
        -617604, // up75
        -642000, // up90
        -620172, // up105
        -555972, // up120
        -453894, // up135
        -321000, // up150
        -166278, // up165
        0,       // inverted
        617604,  // down75
        642000,  // down90
        620172,  // down105
        555972,  // down120
        453894,  // down135
        321000,  // down150
        166278,  // down165
        -321000, // corkscrewUpRight0
        -555972, // corkscrewUpRight1
        -642000, // corkscrewUpRight2
        -555972, // corkscrewUpRight3
        -321000, // corkscrewUpRight4
        321000,  // corkscrewDownLeft0
        555972,  // corkscrewDownLeft1
        642000,  // corkscrewDownLeft2
        555972,  // corkscrewDownLeft3
        321000,  // corkscrewDownLeft4
        -321000, // corkscrewUpLeft0
        -555972, // corkscrewUpLeft1
        -642000, // corkscrewUpLeft2
        -555972, // corkscrewUpLeft3
        -321000, // corkscrewUpLeft4
        321000,  // corkscrewDownRight0
        555972,  // corkscrewDownRight1
        642000,  // corkscrewDownRight2
        555972,  // corkscrewDownRight3
        321000,  // corkscrewDownRight4
        -33384,  // upHalfHelixLarge
        -55854,  // upHalfHelixSmall
        33384,   // downHalfHelixLarge
        55854,   // downHalfHelixSmall
        -66768,  // upQuarterHelix
        66768,   // downQuarterHelix
        -90522,  // up8
        -179760, // up16
        -484068, // up50
        90522,   // down8
        179760,  // down16
        484068,  // down50
        243318,  // uninvertingDown25
        416016,  // uninvertingDown42
        546342,  // uninvertingDown60
        -110424, // curvedLiftHillUp
        110424,  // curvedLiftHillDown
    };
    static_assert(std::size(AccelerationFromPitch) == EnumValue(VehiclePitch::pitchCount));

    constexpr int32_t GetAccelerationFromPitch(VehiclePitch pitch)
    {
        return AccelerationFromPitch[EnumValue(pitch)];
    }

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

    constexpr int32_t GetDopplerShift(uint8_t yaw)
    {
        return SpriteDirectionToSoundDirection[yaw];
    }

    /** rct2: 0x009A37E4
     *  rct2: 0x009A38D4
     * The cos and sin of vehicle pitch based on vehicle sprite angles
     *  COS((Y1/360)*2*PI())*INT32MAX,-SIN((Y1/360)*2*PI())*INT32MAX
     *  Where Y1 represents the angle of pitch in degrees
     */
    static constexpr CoordsXY PitchToDirectionVectorFromGeometryInt32[] = {
        { 2147483647, 0 },         // flat
        { 2106585154, 417115092 }, // up12
        { 1985590284, 817995863 },
        { 1636362342, 1390684831 },
        { 1127484953, 1827693544 },
        { 2106585154, -417115092 }, // down12
        { 1985590284, -817995863 },
        { 1636362342, -1390684831 },
        { 1127484953, -1827693544 },
        { 58579923, 2066040965 }, // up75
        { 0, 2147483647 },
        { -555809667, 2074309916 },
        { -1073741824, 1859775393 },
        { -1518500249, 1518500249 },
        { -1859775391, 1073741824 },
        { -2074309916, 555809666 },
        { -2147483647, 0 },        // inverted
        { 58579923, -2066040965 }, // down75
        { 0, -2147483647 },
        { -555809667, -2074309916 },
        { -1073741824, -1859775393 },
        { -1518500249, -1518500249 },
        { -1859775391, -1073741824 },
        { -2074309916, -555809666 },
        { 1859775393, 1073741824 }, // corkscrewUpRight0
        { 1073741824, 1859775393 },
        { 0, 2147483647 },
        { -1073741824, 1859775393 },
        { -1859775393, 1073741824 },
        { 1859775393, -1073741824 }, // corkscrewDownLeft0
        { 1073741824, -1859775393 },
        { 0, -2147483647 },
        { -1073741824, -1859775393 },
        { -1859775393, -1073741824 },
        { 1859775393, 1073741824 }, // corkscrewUpLeft0
        { 1073741824, 1859775393 },
        { 0, 2147483647 },
        { -1073741824, 1859775393 },
        { -1859775393, 1073741824 },
        { 1859775393, -1073741824 }, // corkscrewDownRight0
        { 1073741824, -1859775393 },
        { 0, -2147483647 },
        { -1073741824, -1859775393 },
        { -1859775393, -1073741824 },
        { 2144540595, 112390610 }, // upHalfHelixLarge
        { 2139311823, 187165532 },
        { 2144540595, -112390610 },
        { 2139311823, -187165532 },
        { 2135719507, 224473165 },
        { 2135719507, -224473165 },
        { 2125953864, 303325208 }, // up8
        { 2061796213, 600568389 },
        { 1411702590, 1618265062 },
        { 2125953864, -303325208 }, // down8
        { 2061796213, -600568389 },
        { 1411702590, -1618265062 },
        { 1985590284, -817995863 },  // uninvertingDown25
        { 1636362342, -1390684831 }, // uninvertingDown42
        { 1127484953, -1827693544 }, // uninvertingDown60
        { 2115506168, 369214930 },   // curvedLifthillUp
        { 2115506168, -369214930 },  // curvedLiftHillDown
    };
    static_assert(std::size(PitchToDirectionVectorFromGeometryInt32) == EnumValue(VehiclePitch::pitchCount));

    constexpr CoordsXY GetPitchComponents(VehiclePitch pitch)
    {
        return PitchToDirectionVectorFromGeometryInt32[EnumValue(pitch)];
    }

    /** rct2: 0x009A39C4
     * Used to calculate the vertical component of G-forces. Unfortunately these don't align with the actual geometry of the
     * track. See comments on the values for the difference between the vehicle's visual angle with the angle used in the
     * G-force calculation. Calculated ROUND(COS((32/64+(L1/64))*(2*PI()))*256,0), ROUND(COS(L1)*(2*PI())) * 2147483647,0).
     * where L1 represents the bank angle.
     */
    constexpr std::array<int32_t, EnumValue(VehicleRoll::rollCount)> GravityFromRollDataInt32 = {
        2147483647,  // unbanked
        2096579710,  // left22  (visually: 22.5 degrees;  actual: 12.5 degrees)
        1946281152,  // left45  (visually: 45 degrees;    actual: 25 degrees)
        2096579710,  // right22
        1946281152,  // right45
        1380375879,  // left67  (visually: 67.5 degrees;  actual: 50 degrees)
        555809667,   // left90  (visually: 90 degrees;    actual: 75 degrees)
        -372906620,  // left112 (visually: 112.5 degrees; actual: 100 degrees)
        -1231746017, // left135 (visually: 135 degrees;   actual: 120 degrees)
        -1859775391, // left157 (visually: 157.5 degrees; actual: 150 degrees)
        1380375879,  // right67
        555809667,   // right90
        -372906620,  // right112
        -1231746017, // right135
        -1859775391, // right157
        0,           // uninvertingUnbanked (unused by RCT2)
        2096579710,  // uninvertingLeft22
        1946281152,  // uninvertingLeft45
        2096579710,  // uninvertingRight22
        1946281152,  // uninvertingRight45
    };

    constexpr int32_t GetGravityFromRoll(VehicleRoll roll)
    {
        return GravityFromRollDataInt32[EnumValue(roll)];
    }

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
