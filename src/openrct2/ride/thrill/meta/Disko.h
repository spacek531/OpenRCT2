/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../../RideData.h"
#include "../../ShopItem.h"
#include "../../Track.h"

// clang-format off
constexpr const RideTypeDescriptor DiskoCoasterRTD =
{
    SET_FIELD(AlternateType, RIDE_TYPE_NULL),
    SET_FIELD(Category, RIDE_CATEGORY_THRILL),
    SET_FIELD(EnabledTrackPieces, (1ULL << TRACK_STRAIGHT) | (1ULL << TRACK_STATION_END) | (1ULL << TRACK_SLOPE) | (1ULL << TRACK_SLOPE_STEEP)| (1ULL << TRACK_SLOPE_STEEP_LONG) | (1ULL << TRACK_BOOSTER) | (1ULL << TRACK_SLOPE_VERTICAL) | (1ULL << TRACK_QUARTER_LOOP)),
    SET_FIELD(ExtraTrackPieces, 0),
    SET_FIELD(StartTrackPiece, TRACK_ELEM_END_STATION),
    SET_FIELD(TrackPaintFunction, get_track_paint_function_giga_rc),
    SET_FIELD(Flags, RIDE_TYPE_FLAGS_TRACK_HAS_3_COLOURS | RIDE_TYPE_FLAG_ALLOW_MULTIPLE_CIRCUITS),
    SET_FIELD(RideModes, (1ULL << RIDE_MODE_POWERED_LAUNCH_SEQUENTIAL) | (1ULL << RIDE_MODE_POWERED_LAUNCH_PASSTROUGH)),
    SET_FIELD(DefaultMode, RIDE_MODE_POWERED_LAUNCH_SEQUENTIAL),
    SET_FIELD(NameConvention, { RIDE_COMPONENT_TYPE_TRAIN, RIDE_COMPONENT_TYPE_TRACK, RIDE_COMPONENT_TYPE_STATION }),
    SET_FIELD(AvailableBreakdowns, (1 << BREAKDOWN_SAFETY_CUT_OUT) | (1 << BREAKDOWN_RESTRAINTS_STUCK_CLOSED) | (1 << BREAKDOWN_RESTRAINTS_STUCK_OPEN) | (1 << BREAKDOWN_VEHICLE_MALFUNCTION)),
    SET_FIELD(LiftData, { SoundId::Null, 5, 8 }),
    SET_FIELD(UpkeepCosts, { 10, 20, 80, 12, 3, 40 }), //unknown
    SET_FIELD(PhotoItem, SHOP_ITEM_PHOTO),
};
// clang-format on
