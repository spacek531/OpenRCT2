/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "TrackSetBrakeSpeedAction.h"

#include "../management/Finance.h"
#include "../ride/Track.h"

TrackSetBrakeSpeedAction::TrackSetBrakeSpeedAction(const CoordsXYZ& loc, track_type_t trackType, uint8_t brakeSpeed)
    : _loc(loc)
    , _trackType(trackType)
    , _brakeSpeed(brakeSpeed)
{
}

void TrackSetBrakeSpeedAction::AcceptParameters(GameActionParameterVisitor& visitor)
{
    visitor.Visit(_loc);
    visitor.Visit("trackType", _trackType);
    visitor.Visit("brakeSpeed", _brakeSpeed);
}

uint16_t TrackSetBrakeSpeedAction::GetActionFlags() const
{
    return GameAction::GetActionFlags() | GameActions::Flags::AllowWhilePaused;
}

void TrackSetBrakeSpeedAction::Serialise(DataSerialiser& stream)
{
    GameAction::Serialise(stream);
    stream << DS_TAG(_loc) << DS_TAG(_trackType) << DS_TAG(_brakeSpeed);
}

GameActions::Result::Ptr TrackSetBrakeSpeedAction::Query() const
{
    return QueryExecute(false);
}

GameActions::Result::Ptr TrackSetBrakeSpeedAction::Execute() const
{
    return QueryExecute(true);
}

GameActions::Result::Ptr TrackSetBrakeSpeedAction::QueryExecute(bool isExecuting) const
{
    auto res = MakeResult();

    res->Position = _loc;
    res->Position.x += 16;
    res->Position.y += 16;
    res->Expenditure = ExpenditureType::RideConstruction;

    if (!LocationValid(_loc))
    {
        return MakeResult(GameActions::Status::NotOwned, STR_NONE);
    }

    TileElement* tileElement = map_get_track_element_at_of_type(_loc, _trackType);
    if (tileElement == nullptr)
    {
        log_warning("Invalid game command for setting brakes speed. x = %d, y = %d", _loc.x, _loc.y);
        return MakeResult(GameActions::Status::InvalidParameters, STR_NONE);
    }

    if (isExecuting)
    {
        tileElement->AsTrack()->SetBrakeBoosterSpeed(_brakeSpeed);
        if (TrackTypeIsBrakes(tileElement->AsTrack()->GetTrackType()))
        {
            brakes_link_to_block_brake(_loc, tileElement);
        }
        else if (TrackTypeIsBlockBrakes(tileElement->AsTrack()->GetTrackType()))
        {
            block_brakes_set_linked_brakes_closed(_loc, tileElement, tileElement->AsTrack()->GetBrakeClosed());
        }
    }
    return res;
}
