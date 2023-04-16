/*****************************************************************************
 * Copyright (c) 2014-2023 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include <openrct2/ride/RideTypes.h>
#include <openrct2/ride/Track.h>

enum class RideConstructionState : uint8_t;

/**
 * Order of special track elements dropdown
 */
constexpr std::array DropdownOrder = {
    TrackElemType::EndStation,

    // Simple track elements
    TrackElemType::SBendLeft,
    TrackElemType::SBendRight,

    TrackElemType::ReverseFreefallSlope,
    TrackElemType::ReverseFreefallVertical,
    TrackElemType::AirThrustTopCap,
    TrackElemType::AirThrustVerticalDown,
    TrackElemType::AirThrustVerticalDownToLevel,

    TrackElemType::TowerBase,
    TrackElemType::TowerSection,

    TrackElemType::MinigolfHoleA,
    TrackElemType::MinigolfHoleB,
    TrackElemType::MinigolfHoleC,
    TrackElemType::MinigolfHoleD,
    TrackElemType::MinigolfHoleE,

    TrackElemType::LeftHalfBankedHelixUpSmall,
    TrackElemType::RightHalfBankedHelixUpSmall,
    TrackElemType::LeftHalfBankedHelixDownSmall,
    TrackElemType::RightHalfBankedHelixDownSmall,
    TrackElemType::LeftHalfBankedHelixUpLarge,
    TrackElemType::RightHalfBankedHelixUpLarge,
    TrackElemType::LeftHalfBankedHelixDownLarge,
    TrackElemType::RightHalfBankedHelixDownLarge,

    TrackElemType::LeftQuarterBankedHelixLargeUp,
    TrackElemType::RightQuarterBankedHelixLargeUp,
    TrackElemType::LeftQuarterBankedHelixLargeDown,
    TrackElemType::RightQuarterBankedHelixLargeDown,

    TrackElemType::LeftQuarterHelixLargeUp,
    TrackElemType::RightQuarterHelixLargeUp,
    TrackElemType::LeftQuarterHelixLargeDown,
    TrackElemType::RightQuarterHelixLargeDown,

    // Simple behavior with special appearance
    TrackElemType::LeftReverser,
    TrackElemType::RightReverser,
    TrackElemType::Waterfall,
    TrackElemType::Rapids,
    TrackElemType::Whirlpool,
    TrackElemType::Watersplash,
    TrackElemType::SpinningTunnel,

    // Special behaviour track elements
    TrackElemType::RotationControlToggle,
    TrackElemType::LogFlumeReverser,
    TrackElemType::LeftCurvedLiftHill,
    TrackElemType::RightCurvedLiftHill,
    TrackElemType::Brakes,
    TrackElemType::BlockBrakes,
    TrackElemType::CableLiftHill,
    TrackElemType::BrakeForDrop,
    TrackElemType::Booster,
    TrackElemType::PoweredLift,
    TrackElemType::HeartLineTransferUp,
    TrackElemType::HeartLineTransferDown,

    // Inversion track elements
    TrackElemType::LeftVerticalLoop,
    TrackElemType::RightVerticalLoop,

    TrackElemType::HalfLoopUp,
    TrackElemType::HalfLoopDown,
    TrackElemType::FlyerHalfLoopUninvertedUp,
    TrackElemType::FlyerHalfLoopInvertedDown,
    TrackElemType::FlyerHalfLoopInvertedUp,
    TrackElemType::FlyerHalfLoopUninvertedDown,

    TrackElemType::LeftMediumHalfLoopUp,
    TrackElemType::LeftMediumHalfLoopDown,
    TrackElemType::RightMediumHalfLoopUp,
    TrackElemType::RightMediumHalfLoopDown,

    TrackElemType::LeftLargeHalfLoopUp,
    TrackElemType::LeftLargeHalfLoopDown,
    TrackElemType::LeftFlyerLargeHalfLoopUninvertedUp,
    TrackElemType::LeftFlyerLargeHalfLoopInvertedDown,
    TrackElemType::LeftFlyerLargeHalfLoopInvertedUp,
    TrackElemType::LeftFlyerLargeHalfLoopUninvertedDown,
    TrackElemType::RightLargeHalfLoopUp,
    TrackElemType::RightLargeHalfLoopDown,
    TrackElemType::RightFlyerLargeHalfLoopUninvertedUp,
    TrackElemType::RightFlyerLargeHalfLoopInvertedDown,
    TrackElemType::RightFlyerLargeHalfLoopInvertedUp,
    TrackElemType::RightFlyerLargeHalfLoopUninvertedDown,

    TrackElemType::LeftCorkscrewUp,
    TrackElemType::LeftFlyerCorkscrewUp,
    TrackElemType::LeftCorkscrewDown,
    TrackElemType::LeftFlyerCorkscrewDown,
    TrackElemType::RightCorkscrewUp,
    TrackElemType::RightFlyerCorkscrewUp,
    TrackElemType::RightCorkscrewDown,
    TrackElemType::RightFlyerCorkscrewDown,

    TrackElemType::LeftLargeCorkscrewUp,
    TrackElemType::RightLargeCorkscrewUp,
    TrackElemType::LeftLargeCorkscrewDown,
    TrackElemType::RightLargeCorkscrewDown,

    TrackElemType::LeftTwistDownToUp,
    TrackElemType::LeftFlyerTwistUp,
    TrackElemType::RightTwistDownToUp,
    TrackElemType::RightFlyerTwistUp,
    TrackElemType::LeftTwistUpToDown,
    TrackElemType::LeftFlyerTwistDown,
    TrackElemType::RightTwistUpToDown,
    TrackElemType::RightFlyerTwistDown,

    TrackElemType::LeftHeartLineRoll,
    TrackElemType::RightHeartLineRoll,

    TrackElemType::LeftBarrelRollUpToDown,
    TrackElemType::LeftBarrelRollDownToUp,
    TrackElemType::RightBarrelRollUpToDown,
    TrackElemType::RightBarrelRollDownToUp,

    TrackElemType::Up90ToInvertedFlatQuarterLoop,
    TrackElemType::InvertedFlatToDown90QuarterLoop,
    TrackElemType::MultiDimInvertedFlatToDown90QuarterLoop,
    TrackElemType::MultiDimUp90ToInvertedFlatQuarterLoop,
    TrackElemType::MultiDimFlatToDown90QuarterLoop,
    TrackElemType::MultiDimInvertedUp90ToFlatQuarterLoop,

    TrackElemType::LeftZeroGRollUp,
    TrackElemType::LeftZeroGRollDown,
    TrackElemType::RightZeroGRollUp,
    TrackElemType::RightZeroGRollDown,

    TrackElemType::LeftLargeZeroGRollUp,
    TrackElemType::LeftLargeZeroGRollDown,
    TrackElemType::RightLargeZeroGRollUp,
    TrackElemType::RightLargeZeroGRollDown,
};
constexpr const size_t DropdownLength = DropdownOrder.size();

// Reminder to add your track element to the list, if applicable
static_assert(TrackElemType::Count == 337);

constexpr bool TrackPieceDirectionIsDiagonal(const uint8_t direction)
{
    return direction >= NumOrthogonalDirections;
}

struct SpecialElement
{
    track_type_t TrackType;
    bool Disabled;
};

struct SpecialElementsList
{
    int32_t NumElements{};
    bool HasActiveElements = false;
    std::array<SpecialElement, DropdownLength> Elements{};
};

SpecialElementsList BuildSpecialElementsList(
    const Ride& currentRide, uint8_t buildDirection, uint8_t buildSlope, uint8_t buildBank, RideConstructionState state);

void RideConstructNew(RideSelection listItem);
