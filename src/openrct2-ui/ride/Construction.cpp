/*****************************************************************************
 * Copyright (c) 2014-2023 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "Construction.h"

#include <openrct2/actions/RideCreateAction.h>
#include <openrct2/ride/Ride.h>
#include <openrct2/ride/RideConstruction.h>
#include <openrct2/ride/RideData.h>
#include <openrct2/ride/RideTypes.h>
#include <openrct2/ride/TrackData.h>

using namespace OpenRCT2::TrackMetaData;

/**
 *
 *  rct2: 0x006B4800
 */
void RideConstructNew(RideSelection listItem)
{
    int32_t rideEntryIndex = RideGetEntryIndex(listItem.Type, listItem.EntryIndex);
    int32_t colour1 = RideGetRandomColourPresetIndex(listItem.Type);
    int32_t colour2 = RideGetUnusedPresetVehicleColour(rideEntryIndex);

    auto gameAction = RideCreateAction(listItem.Type, listItem.EntryIndex, colour1, colour2, gLastEntranceStyle);

    gameAction.SetCallback([](const GameAction* ga, const GameActions::Result* result) {
        if (result->Error != GameActions::Status::Ok)
            return;
        const auto rideIndex = result->GetData<RideId>();
        auto ride = GetRide(rideIndex);
        RideConstructionStart(*ride);
    });

    GameActions::Execute(&gameAction);
}

SpecialElementsList BuildSpecialElementsList(
    const Ride& currentRide, uint8_t buildDirection, uint8_t buildSlope, uint8_t buildBank, RideConstructionState state)
{
    auto buildDirectionIsDiagonal = TrackPieceDirectionIsDiagonal(buildDirection);
    SpecialElementsList list;

    for (track_type_t trackType : DropdownOrder)
    {
        const auto& ted = GetTrackElementDescriptor(trackType);
        if (!IsTrackEnabled(ted.Definition.type))
            continue;
        int32_t trackSlope, trackBank;
        bool trackDirectionIsDiagonal = false;

        if (state == RideConstructionState::Front || state == RideConstructionState::Place)
        {
            trackSlope = ted.Definition.vangle_start;
            trackBank = ted.Definition.bank_start;
            trackDirectionIsDiagonal = TrackPieceDirectionIsDiagonal(ted.Coordinates.rotation_begin);
        }
        else if (state == RideConstructionState::Back)
        {
            trackSlope = ted.Definition.vangle_end;
            trackBank = ted.Definition.bank_end;
            trackDirectionIsDiagonal = TrackPieceDirectionIsDiagonal(ted.Coordinates.rotation_end);
        }
        else
        {
            // if it's building forwards nor backwards, no list is available
            return list;
        }

        // Only show up half helixes on alpine coaster
        if (currentRide.GetRideTypeDescriptor().HasFlag(RIDE_TYPE_FLAG_UP_INCLINE_REQUIRES_LIFT)
            && !gCheatsEnableAllDrawableTrackPieces
            && ((
                trackType == TrackElemType::LeftHalfBankedHelixUpSmall
                || trackType == TrackElemType::RightHalfBankedHelixUpSmall
                || trackType == TrackElemType::LeftHalfBankedHelixUpLarge
                || trackType == TrackElemType::RightHalfBankedHelixUpLarge)))
            continue;

        // At this point, the piece is desired to be in the list. Check if it should be disabled first and attempt to
        // collate entries.

        bool entryIsDisabled = true;

        // If all 3 orientations match, the track can be built
        if (buildDirectionIsDiagonal == trackDirectionIsDiagonal && buildSlope == trackSlope && buildBank == trackBank)
            entryIsDisabled = false;

        // Additional tower bases can only be built if the ride allows for it (elevator)
        if (trackType == TrackElemType::TowerBase
            && !currentRide.GetRideTypeDescriptor().HasFlag(RIDE_TYPE_FLAG_ALLOW_EXTRA_TOWER_BASES))
            entryIsDisabled = true;

        SpecialElement* previousEntryOfSameName = nullptr;
        // Search for any duplicate names in the last 10 entries. If a duplicate exists and is disabled, replace that entry with
        // this entry
        for (int32_t searchIndex = list.NumElements - 1; searchIndex >= 0 && searchIndex > list.NumElements - 11; searchIndex--)
        {
            if (GetTrackElementDescriptor(list.Elements[searchIndex].TrackType).Description == ted.Description)
            {
                previousEntryOfSameName = &list.Elements[searchIndex];
                break;
            }
        }

        if (previousEntryOfSameName != nullptr)
        {
            // If the current element is disabled, do not add current element.
            if (entryIsDisabled)
                continue;
            // If the previous element is disabled and current element is enabled, replace the previous element
            if (previousEntryOfSameName->Disabled && !entryIsDisabled)
            {
                previousEntryOfSameName->TrackType = trackType;
                previousEntryOfSameName->Disabled = false;
                list.HasActiveElements = true;
                continue;
            }
            // If the previous element and current element are enabled, add both to the list
        }
        list.Elements[list.NumElements].TrackType = trackType;
        list.Elements[list.NumElements++].Disabled = entryIsDisabled;
        list.HasActiveElements |= !entryIsDisabled;
    }
    return list;
}
