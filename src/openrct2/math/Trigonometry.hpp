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

    // divide by this to convert a value of int32_t::max to 256. Equivalent to >> 23
    constexpr int32_t kInt32To256 = 8388607;

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

    constexpr CoordsXY GetYawVector(uint8_t yaw)
    {
        return YawToDirectionVector[OpenRCT2::Entity::Yaw::YawTo64(yaw)];
    }

    /** rct2: 0x009A37E4
     *  rct2: 0x009A38D4
     * The cos and sin of vehicle pitch based on vehicle sprite angles
     *  COS((Y1/360)*2*PI())*INT32MAX,SIN((Y1/360)*2*PI())*INT32MAX
     *  Where Y1 represents the angle of pitch in degrees
     * Note that some values are not correct. Someone should fix them.
     */
    constexpr std::array<CoordsXY, EnumValue(VehiclePitch::pitchCount)> PitchToDirectionVectorFromGeometryInt32 = {
        CoordsXY{ 2147483647, 0 },    // flat
        { 2106585154, 417115092 },    // up12
        { 1985590284, 817995863 },    // up25
        { 1636362342, 1390684831 },   // up42
        { 1127484953, 1827693544 },   // up60
        { 2106585154, -417115092 },   // down12
        { 1985590284, -817995863 },   // down25
        { 1636362342, -1390684831 },  // down42
        { 1127484953, -1827693544 },  // down60
        { 58579923, 2066040965 },     // up75
        { 0, 2147483647 },            // up90
        { -555809667, 2074309916 },   // up115
        { -1073741824, 1859775393 },  // up120
        { -1518500249, 1518500249 },  // up135
        { -1859775391, 1073741824 },  // up150
        { -2074309916, 555809666 },   // up165
        { -2147483647, 0 },           // inverted
        { 58579923, -2066040965 },    // down75
        { 0, -2147483647 },           // down90
        { -555809667, -2074309916 },  // down115
        { -1073741824, -1859775393 }, // down120
        { -1518500249, -1518500249 }, // down135
        { -1859775391, -1073741824 }, // down150
        { -2074309916, -555809666 },  // down165
        { 1859775393, 1073741824 },   // corkscrewUpRight0
        { 1073741824, 1859775393 },   // corkscrewUpRight1
        { 0, 2147483647 },            // corkscrewUpRight2
        { -1073741824, 1859775393 },  // corkscrewUpRight3
        { -1859775393, 1073741824 },  // corkscrewUpRight4
        { 1859775393, -1073741824 },  // corkscrewDownLeft0
        { 1073741824, -1859775393 },  // corkscrewDownLeft1
        { 0, -2147483647 },           // corkscrewDownLeft2
        { -1073741824, -1859775393 }, // corkscrewDownLeft3
        { -1859775393, -1073741824 }, // corkscrewDownLeft4
        { 1859775393, 1073741824 },   // corkscrewUpLeft0
        { 1073741824, 1859775393 },   // corkscrewUpLeft1
        { 0, 2147483647 },            // corkscrewUpLeft2
        { -1073741824, 1859775393 },  // corkscrewUpLeft3
        { -1859775393, 1073741824 },  // corkscrewUpLeft4
        { 1859775393, -1073741824 },  // corkscrewDownRight0
        { 1073741824, -1859775393 },  // corkscrewDownRight1
        { 0, -2147483647 },           // corkscrewDownRight2
        { -1073741824, -1859775393 }, // corkscrewDownRight3
        { -1859775393, -1073741824 }, // corkscrewDownRight4
        { 2144540595, 112390610 },    // upHalfHelixLarge
        { 2139311823, 187165532 },    // upHalfHelixSmall
        { 2144540595, -112390610 },   // downHalfHelixLarge
        { 2139311823, -187165532 },   // downHalfHelixSmall
        { 2135719507, 224473165 },    // upQuarterHelix
        { 2135719507, -224473165 },   // downQuarterHelix
        { 2125953864, 303325208 },    // up8
        { 2061796213, 600568389 },    // up16
        { 1411702590, 1618265062 },   // up50
        { 2125953864, -303325208 },   // down8
        { 2061796213, -600568389 },   // down16
        { 1411702590, -1618265062 },  // down50
        { 2115506168, 369214930 },    // curvedLifthillUp
        { 2115506168, -369214930 },   // curvedLiftHillDown
        { 1636362342, 1390684831 },   // up42
        { 1636362342, -1390684831 },  // down42
        { 1636362342, 1390684831 },   // up42
        { 1636362342, -1390684831 },  // down42
    };

    constexpr CoordsXY GetPitchComponents(VehiclePitch pitch)
    {
        return PitchToDirectionVectorFromGeometryInt32[EnumValue(pitch)];
    }

    constexpr CoordsXY GetPitchComponents256(VehiclePitch pitch)
    {
        return PitchToDirectionVectorFromGeometryInt32[EnumValue(pitch)] / kInt32To256;
    }

    constexpr int32_t ComputeHorizontalMagnitude(int32_t length, VehiclePitch pitch)
    {
        return (-GetPitchComponents256(pitch).y * length) / 256;
    }

    constexpr CoordsXY ComputeXYVector(int32_t magnitude, uint8_t yaw)
    {
        return (GetYawVector(yaw) * magnitude) / 256;
    }

    constexpr CoordsXY ComputeXYVector(int32_t length, VehiclePitch pitch, uint8_t yaw)
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
    constexpr std::array<int32_t, EnumValue(VehiclePitch::pitchCount)> AccelerationFromPitch = {
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
        -110424, // curvedLiftHillUp
        110424,  // curvedLiftHillDown
        -416016, // up42
        416016,  // down42
        -416016, // up42
        416016,  // down42
    };

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
        1380375879,  // uninvertingLeft67 
        555809667,   // uninvertingLeft90 
        -372906620,  // uninvertingLeft112
        -1231746017, // uninvertingLeft135
        -1859775391, // uninvertingLeft157
        1380375879,  // uninvertingRight67
        555809667,   // uninvertingRight90
        -372906620,  // uninvertingRight112
        -1231746017, // uninvertingRight135
        -1859775391, // uninvertingRight157
    };

    constexpr int32_t GetGravityFromRoll(VehicleRoll roll)
    {
        return GravityFromRollDataInt32[EnumValue(roll)];
    }

    /** rct2: 0x009A36C4 */
    constexpr std::array<CoordsXY, OpenRCT2::Entity::Yaw::kBaseRotation> FreeRoamMovementData = {
        CoordsXY{ -1, 0 }, { -1, 0 }, { -1, 0 }, { -1, 1 },  { -1, 1 },  { -1, 1 },  { 0, 1 },  { -1, 1 },
        { 0, 1 },          { 0, 1 },  { 0, 1 },  { 1, 1 },   { 1, 1 },   { 1, 1 },   { 1, 0 },  { 1, 1 },
        { 1, 0 },          { 1, 0 },  { 1, 0 },  { 1, -1 },  { 1, -1 },  { 1, -1 },  { 0, -1 }, { 1, -1 },
        { 0, -1 },         { 0, -1 }, { 0, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, 0 }, { -1, -1 },
    };

    constexpr CoordsXY GetFreeRoamMovementData(uint8_t yaw)
    {
        return FreeRoamMovementData[yaw];
    }

    /** rct2: 0x009A3AC4, 0x009A3AC6 */
    constexpr std::array<CoordsXY, OpenRCT2::Entity::Yaw::kBaseRotation> CrashDirectionComponents = {
        CoordsXY{ -256, 0 }, { -236, 98 },  { -181, 181 },  { -98, 236 },  { 0, 256 },    { 98, 236 },
        { 181, 181 },        { 236, 98 },   { 256, 0 },     { 236, -98 },  { 181, -181 }, { 98, -236 },
        { 0, -256 },         { -98, -236 }, { -181, -181 }, { -236, -98 },
    };
} // namespace OpenRCT2::Math::Trigonometry
