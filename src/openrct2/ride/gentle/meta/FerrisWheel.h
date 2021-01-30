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
constexpr const RideTypeDescriptor FerrisWheelRTD =
{
    SET_FIELD(AlternateType, RIDE_TYPE_NULL),
    SET_FIELD(Category, RIDE_CATEGORY_GENTLE),
    SET_FIELD(EnabledTrackPieces, 0),
    SET_FIELD(ExtraTrackPieces, 0),
    SET_FIELD(CoveredTrackPieces, 0),
    SET_FIELD(StartTrackPiece, FLAT_TRACK_ELEM_1_X_4_C),
    SET_FIELD(TrackPaintFunction, get_track_paint_function_ferris_wheel),
    SET_FIELD(Flags, RIDE_TYPE_FLAG_HAS_TRACK_COLOUR_MAIN | RIDE_TYPE_FLAG_HAS_SINGLE_PIECE_STATION | RIDE_TYPE_FLAG_CANNOT_HAVE_GAPS |
                     RIDE_TYPE_FLAG_HAS_NO_TRACK | RIDE_TYPE_FLAG_VEHICLE_IS_INTEGRAL | RIDE_TYPE_FLAG_TRACK_NO_WALLS | RIDE_TYPE_FLAG_FLAT_RIDE |
                     RIDE_TYPE_FLAG_HAS_VEHICLE_COLOURS | RIDE_TYPE_FLAG_ALLOW_MUSIC | RIDE_TYPE_FLAG_HAS_ENTRANCE_EXIT |
                     RIDE_TYPE_FLAG_SINGLE_SESSION | RIDE_TYPE_FLAG_SLIGHTLY_INTERESTING_TO_LOOK_AT | RIDE_TYPE_FLAG_LIST_VEHICLES_SEPARATELY),
    SET_FIELD(RideModes, EnumsToFlags(RideMode::ForwardRotation, RideMode::BackwardRotation)),
    SET_FIELD(DefaultMode, RideMode::ForwardRotation),
    SET_FIELD(OperatingSettings, { 1, 3, 0, 0, 0, 0 }),
    SET_FIELD(Naming, { STR_RIDE_NAME_FERRIS_WHEEL, STR_RIDE_DESCRIPTION_FERRIS_WHEEL }),
    SET_FIELD(NameConvention, { RideComponentType::Wheel, RideComponentType::Structure, RideComponentType::Station }),
    SET_FIELD(EnumName, nameof(RIDE_TYPE_FERRIS_WHEEL)),
    SET_FIELD(AvailableBreakdowns, (1 << BREAKDOWN_SAFETY_CUT_OUT)),
    SET_FIELD(Heights, { 16, 176, 3, 2, }),
    SET_FIELD(MaxMass, 255),
    SET_FIELD(LiftData, { OpenRCT2::Audio::SoundId::Null, 5, 5 }),
    SET_FIELD(RatingsCalculationFunction, ride_ratings_calculate_ferris_wheel),
    SET_FIELD(RatingsMultipliers, { 60, 20, 10 }),
    SET_FIELD(UpkeepCosts, { 50, 1, 0, 0, 0, 0 }),
    SET_FIELD(BuildCosts, { 225, 2, 1, }),
    SET_FIELD(DefaultPrices, { 10, 0 }),
    SET_FIELD(DefaultMusic, MUSIC_STYLE_SUMMER),
    SET_FIELD(PhotoItem, ShopItem::Photo),
    SET_FIELD(BonusValue, 45),
    SET_FIELD(ColourPresets, TRACK_COLOUR_PRESETS(
        { COLOUR_BLACK, COLOUR_BLACK, COLOUR_BLACK },
        { COLOUR_GREY, COLOUR_GREY, COLOUR_GREY },
    )),
    SET_FIELD(ColourPreview, { SPR_RIDE_DESIGN_PREVIEW_FERRIS_WHEEL_TRACK, 0 }),
    SET_FIELD(ColourKey, RideColourKey::Ride),
    SET_FIELD(TrackBehaviours,{RideBoosterBehaviour::SpeedController,RideRapidsBehaviour::LogBumps})
};
// clang-format on
