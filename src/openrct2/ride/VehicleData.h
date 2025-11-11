/*****************************************************************************
 * Copyright (c) 2014-2025 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../core/EnumUtils.hpp"

#include <array>
#include <assert.h>
#include <cstdint>

namespace OpenRCT2::FlatRide
{

    struct FlatRideAnimationFrame
    {
        uint8_t animationFrame{};
        uint8_t animationFrame2{};
        constexpr FlatRideAnimationFrame()
        {
            animationFrame = 0xFF;
            animationFrame2 = 0xFF;
        }
        constexpr FlatRideAnimationFrame(uint8_t frame1)
            : animationFrame(frame1)
        {
        }
        constexpr FlatRideAnimationFrame(uint8_t frame1, uint8_t frame2)
            : animationFrame(frame1)
            , animationFrame2(frame2)
        {
        }
        constexpr bool operator==(auto& b) const
        {
            return animationFrame == b.animationFrame && animationFrame2 == b.animationFrame2;
        }
    };

    constexpr FlatRideAnimationFrame kNullFrame{};

    using RotationAnimationSequence = std::array<FlatRideAnimationFrame, 1024>;

    enum class RotationModeSubState : uint8_t
    {
        acceleration,
        continuous,
        deceleration,
        count
    };

    struct RotationModeAnimationSet
    {
        const std::array<RotationAnimationSequence, EnumValue(RotationModeSubState::count)> animations;
        const uint8_t numRotationsOffset;
        constexpr RotationModeAnimationSet(
            const RotationAnimationSequence accelerationAnimation, const RotationAnimationSequence continuousAnimation,
            const RotationAnimationSequence decelerationAnimation, const uint8_t rotationsOffset)
            : animations(accelerationAnimation, continuousAnimation, decelerationAnimation)
            , numRotationsOffset(rotationsOffset)
        {
        }
        const RotationAnimationSequence get(RotationModeSubState subState) const
        {
            assert(subState < RotationModeSubState::count);
            return animations[EnumValue(subState)];
        }
    };

    extern const RotationModeAnimationSet kTwistAnimation;
    extern const RotationModeAnimationSet kEnterpriseAnimation;
    extern const RotationModeAnimationSet kMerryGoRoundAnimation;
}


struct TopSpinTimeToSpriteMap
{
    uint8_t arm_rotation;
    uint8_t bank_rotation;
};

extern const TopSpinTimeToSpriteMap* kTopSpinTimeToSpriteMaps[];

extern const uint8_t MotionSimulatorTimeToSpriteMap[];
extern const int32_t MotionSimulatorTimeToSpriteMapCount;

extern const uint8_t kSpaceRingsTimeToSpriteMap[];

/** rct2: 0x0099F9D0 */
extern const int8_t* kSwingingTimeToSpriteMaps[];
