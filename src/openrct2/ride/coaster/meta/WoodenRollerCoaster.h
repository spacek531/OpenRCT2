/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../../../sprites.h"
#include "../../RideData.h"
#include "../../ShopItem.h"
#include "../../Track.h"

// clang-format off
constexpr const RideTypeDescriptor WoodenRollerCoasterRTD =
{
    SET_FIELD(AlternateType, RIDE_TYPE_NULL),
    SET_FIELD(Category, RIDE_CATEGORY_ROLLERCOASTER),
    SET_FIELD(EnabledTrackPieces, (1ULL << TRACK_FLAT) | (1ULL << TRACK_STRAIGHT) | (1ULL << TRACK_STATION_END) | (1ULL << TRACK_LIFT_HILL) | (1ULL << TRACK_FLAT_ROLL_BANKING) | (1ULL << TRACK_VERTICAL_LOOP) | (1ULL << TRACK_SLOPE) | (1ULL << TRACK_SLOPE_STEEP) | (1ULL << TRACK_SLOPE_CURVE) | (1ULL << TRACK_SLOPE_CURVE_STEEP) | (1ULL << TRACK_S_BEND) | (1ULL << TRACK_CURVE_SMALL) | (1ULL << TRACK_CURVE) | (1ULL << TRACK_HELIX_SMALL) | (1ULL << TRACK_BRAKES) | (1ULL << TRACK_ON_RIDE_PHOTO) | (1ULL << TRACK_WATER_SPLASH) | (1ULL << TRACK_SLOPE_CURVE_BANKED) | (1ULL << TRACK_BLOCK_BRAKES) | (1ULL << TRACK_SLOPE_ROLL_BANKING)),
    SET_FIELD(ExtraTrackPieces, (1ULL << TRACK_BOOSTER)),
    SET_FIELD(CoveredTrackPieces, 0),
    SET_FIELD(StartTrackPiece, TrackElemType::EndStation),
    SET_FIELD(TrackPaintFunction, get_track_paint_function_wooden_rc),
    SET_FIELD(Flags, RIDE_TYPE_FLAGS_TRACK_HAS_3_COLOURS | RIDE_TYPE_FLAG_HAS_LEAVE_WHEN_ANOTHER_VEHICLE_ARRIVES_AT_STATION |
                     RIDE_TYPE_FLAGS_COMMON_COASTER | RIDE_TYPE_FLAGS_COMMON_COASTER_NON_ALT | RIDE_TYPE_FLAG_HAS_LARGE_CURVES |
                     RIDE_TYPE_FLAG_PEEP_CHECK_GFORCES | RIDE_TYPE_FLAG_ALLOW_MULTIPLE_CIRCUITS),
    SET_FIELD(RideModes, EnumsToFlags(RideMode::ContinuousCircuit, RideMode::ContinuousCircuitBlockSectioned, RideMode::ReverseInclineLaunchedShuttle)),
    SET_FIELD(DefaultMode, RideMode::ContinuousCircuit),
    SET_FIELD(OperatingSettings, { 0, 0, 0, 0, 68, 0 }),
    SET_FIELD(Naming, { STR_RIDE_NAME_WOODEN_ROLLER_COASTER, STR_RIDE_DESCRIPTION_WOODEN_ROLLER_COASTER }),
    SET_FIELD(NameConvention, { RideComponentType::Train, RideComponentType::Track, RideComponentType::Station }),
    SET_FIELD(EnumName, nameof(RIDE_TYPE_WOODEN_ROLLER_COASTER)),
    SET_FIELD(AvailableBreakdowns, (1 << BREAKDOWN_SAFETY_CUT_OUT) | (1 << BREAKDOWN_RESTRAINTS_STUCK_CLOSED) | (1 << BREAKDOWN_RESTRAINTS_STUCK_OPEN) | (1 << BREAKDOWN_VEHICLE_MALFUNCTION) | (1 << BREAKDOWN_BRAKES_FAILURE)),
    SET_FIELD(Heights, { 41, 24, 8, 11, }),
    SET_FIELD(MaxMass, 19),
    SET_FIELD(LiftData, { OpenRCT2::Audio::SoundId::LiftWood, 5, 7 }),
    SET_FIELD(RatingsCalculationFunction, ride_ratings_calculate_wooden_roller_coaster),
    SET_FIELD(RatingsMultipliers, { 52, 33, 8 }),
    SET_FIELD(UpkeepCosts, { 40, 20, 80, 10, 3, 10 }),
    SET_FIELD(BuildCosts, { 75, 7, 50, }),
    SET_FIELD(DefaultPrices, { 20, 20 }),
    SET_FIELD(DefaultMusic, MUSIC_STYLE_WILD_WEST),
    SET_FIELD(PhotoItem, ShopItem::Photo3),
    SET_FIELD(BonusValue, 105),
    SET_FIELD(ColourPresets, TRACK_COLOUR_PRESETS(
        { COLOUR_BORDEAUX_RED, COLOUR_BLACK, COLOUR_WHITE },
        { COLOUR_BRIGHT_RED, COLOUR_BLACK, COLOUR_GREY },
        { COLOUR_YELLOW, COLOUR_DARK_BROWN, COLOUR_DARK_BROWN },
        { COLOUR_TEAL, COLOUR_BORDEAUX_RED, COLOUR_WHITE },
        { COLOUR_LIGHT_BLUE, COLOUR_BLACK, COLOUR_BLACK },
    )),
    SET_FIELD(ColourPreview, { SPR_RIDE_DESIGN_PREVIEW_WOODEN_ROLLER_COASTER_TRACK, SPR_RIDE_DESIGN_PREVIEW_WOODEN_ROLLER_COASTER_SUPPORTS }),
    SET_FIELD(ColourKey, RideColourKey::Ride),
    SET_FIELD(TrackBehaviours,{RideBoosterBehaviour::Booster,RideRapidsBehaviour::LogBumps})
};
// clang-format on
