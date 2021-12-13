/*****************************************************************************
 * Copyright (c) 2014-2022 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../common.h"

struct RotationSubtypeSpriteMap
{
    const uint8_t* Animations[3] = { 0, 0, 0 };
    constexpr RotationSubtypeSpriteMap(
        const uint8_t* accelerationAnimation, const uint8_t* continuousAnimation, const uint8_t* decelerationAnimation)
    {
        Animations[0] = accelerationAnimation;
        Animations[1] = continuousAnimation;
        Animations[2] = decelerationAnimation;
    }
    const uint8_t* GetAnimation(uint8_t sub_state) const
    {
        return Animations[sub_state];
    }
};

extern const RotationSubtypeSpriteMap RotationSubtypeMaps[];

struct top_spin_time_to_sprite_map
{
    uint8_t arm_rotation;
    uint8_t bank_rotation;
};

extern const top_spin_time_to_sprite_map* TopSpinTimeToSpriteMaps[];

extern const uint8_t MotionSimulatorTimeToSpriteMap[];
extern const int32_t MotionSimulatorTimeToSpriteMapCount;

extern const int32_t SubpositionTranslationDistances[];
extern const int32_t AccelerationFromPitch[];

extern const int32_t SpriteDirectionToSoundDirection[];
