#pragma region Copyright (c) 2014-2016 OpenRCT2 Developers
/*****************************************************************************
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * OpenRCT2 is the work of many authors, a full list can be found in contributors.md
 * For more information, visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * A full copy of the GNU General Public License can be found in licence.txt
 *****************************************************************************/
#pragma endregion

#include "../core/IStream.hpp"
#include "../core/Memory.hpp"
#include "../core/Util.hpp"
#include "ObjectRepository.h"
#include "RideObject.h"

extern "C"
{
    #include "../config.h"
    #include "../drawing/drawing.h"
    #include "../localisation/localisation.h"
    #include "../rct1.h"
}

enum OBJ_STRING_ID
{
    OBJ_STRING_ID_NAME,
    OBJ_STRING_ID_DESCRIPTION,
    OBJ_STRING_ID_CAPACITY,
};

RideObject::~RideObject()
{
    for (int i = 0; i < 4; i++)
    {
        Memory::Free(_peepLoadingPositions[i]);
    }
}

void RideObject::ReadLegacy(IStream * stream)
{
    stream->Read(&_legacyType);

    GetStringTable()->Read(stream, OBJ_STRING_ID_NAME);
    GetStringTable()->Read(stream, OBJ_STRING_ID_DESCRIPTION);

    // TODO: Move to its own function when ride construction window is merged.
    if (gConfigInterface.select_by_track_type) {
        _legacyType.enabledTrackPieces = 0xFFFFFFFFFFFFFFFF;
    }

    GetStringTable()->Read(stream, OBJ_STRING_ID_CAPACITY);

    // Read preset colours, by default there are 32
    _presetColours.count = stream->ReadValue<uint8>();
    if (_presetColours.count == 255)
    {
        _presetColours.count = 32;
    }
    for (uint8 i = 0; i < _presetColours.count; i++)
    {
        _presetColours.list[i] = stream->ReadValue<vehicle_colour>();
    }

    // Read peep loading positions
    for (int i = 0; i < 4; i++)
    {
        uint16 numPeepLoadingPositions = stream->ReadValue<uint8>();
        if (numPeepLoadingPositions == 255)
        {
            numPeepLoadingPositions = stream->ReadValue<uint16>();
        }
        _peepLoadingPositions[i] = stream->ReadArray<sint8>(numPeepLoadingPositions);
    }

    GetImageTable()->Read(stream);
}

void RideObject::Load()
{
    _legacyType.name = language_allocate_object_string(GetName());
    _legacyType.description = language_allocate_object_string(GetDescription());
    _legacyType.images_offset = gfx_object_allocate_images(GetImageTable()->GetImages(), GetImageTable()->GetCount());

    int cur_vehicle_images_offset = _legacyType.images_offset + 3;
    for (int i = 0; i < 4; i++)
    {
        rct_ride_entry_vehicle * vehicleEntry = &_legacyType.vehicles[i];
        if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_FLAT)
        {
            int al = 1;
            if (vehicleEntry->flags_b & VEHICLE_ENTRY_FLAG_B_SWINGING)
            {
                al = 13;
                if ((vehicleEntry->flags_b & (VEHICLE_ENTRY_FLAG_B_5 | VEHICLE_ENTRY_FLAG_B_11)) != (VEHICLE_ENTRY_FLAG_B_5 | VEHICLE_ENTRY_FLAG_B_11))
                {
                    al = 7;
                    if (!(vehicleEntry->flags_b & VEHICLE_ENTRY_FLAG_B_5))
                    {
                        if (!(vehicleEntry->flags_b & VEHICLE_ENTRY_FLAG_B_11))
                        {
                            al = 5;
                            if (vehicleEntry->flags_b & VEHICLE_ENTRY_FLAG_B_9)
                            {
                                al = 3;
                            }
                        }
                    }
                }
            }
            vehicleEntry->var_03 = al;
            // 0x6DE90B
            al = 0x20;
            if (!(vehicleEntry->flags_a & VEHICLE_ENTRY_FLAG_A_14))
            {
                al = 1;
                if (vehicleEntry->flags_b & VEHICLE_ENTRY_FLAG_B_7)
                {
                    if (vehicleEntry->var_11 != 6)
                    {
                        al = 2;
                        if (!(vehicleEntry->flags_a & VEHICLE_ENTRY_FLAG_A_7))
                        {
                            al = 4;
                        }
                    }
                }
            }
            if (vehicleEntry->flags_a & VEHICLE_ENTRY_FLAG_A_12)
            {
                al = vehicleEntry->special_frames;
            }
            vehicleEntry->var_02 = al;
            // 0x6DE946

            vehicleEntry->var_16 = vehicleEntry->var_02 * vehicleEntry->var_03;
            vehicleEntry->base_image_id = cur_vehicle_images_offset;
            int image_index = vehicleEntry->base_image_id;

            if (vehicleEntry->car_visual != VEHICLE_VISUAL_RIVER_RAPIDS)
            {
                int b = vehicleEntry->var_16 * 32;

                if (vehicleEntry->flags_a & VEHICLE_ENTRY_FLAG_A_11) b /= 2;
                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_15) b /= 8;

                image_index += b;

                // Incline 25
                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_GENTLE_SLOPES)
                {
                    vehicleEntry->var_20 = image_index;
                    b = vehicleEntry->var_16 * 72;
                    if (vehicleEntry->flags_a & VEHICLE_ENTRY_FLAG_A_14)
                    {
                        b = vehicleEntry->var_16 * 16;
                    }
                    image_index += b;
                }

                // Incline 60
                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_STEEP_SLOPES)
                {
                    vehicleEntry->var_24 = image_index;
                    b = vehicleEntry->var_16 * 80;
                    image_index += b;
                }

                // Verticle
                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
                {
                    vehicleEntry->var_28 = image_index;
                    b = vehicleEntry->var_16 * 116;
                    image_index += b;
                }

                // Unknown
                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_DIAGONAL_SLOPES)
                {
                    vehicleEntry->var_2C = image_index;
                    b = vehicleEntry->var_16 * 24;
                    image_index += b;
                }

                // Bank
                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_FLAT_BANKED)
                {
                    vehicleEntry->var_30 = image_index;
                    b = vehicleEntry->var_16 * 80;
                    image_index += b;
                }

                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_INLINE_TWISTS)
                {
                    vehicleEntry->var_34 = image_index;
                    b = vehicleEntry->var_16 * 40;
                    image_index += b;
                }

                // Track half? Up/Down
                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_FLAT_TO_GENTLE_SLOPE_BANKED_TRANSITIONS)
                {
                    vehicleEntry->var_38 = image_index;
                    b = vehicleEntry->var_16 * 128;
                    image_index += b;
                }

                // Unknown
                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_DIAGONAL_GENTLE_SLOPE_BANKED_TRANSITIONS)
                {
                    vehicleEntry->var_3C = image_index;
                    b = vehicleEntry->var_16 * 16;
                    image_index += b;
                }

                // Unknown
                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_GENTLE_SLOPE_BANKED_TRANSITIONS)
                {
                    vehicleEntry->var_40 = image_index;
                    b = vehicleEntry->var_16 * 16;
                    image_index += b;
                }

                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_GENTLE_SLOPE_BANKED_TURNS)
                {
                    vehicleEntry->var_44 = image_index;
                    b = vehicleEntry->var_16 * 128;
                    image_index += b;
                }

                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_FLAT_TO_GENTLE_SLOPE_WHILE_BANKED_TRANSITIONS)
                {
                    vehicleEntry->var_48 = image_index;
                    b = vehicleEntry->var_16 * 16;
                    image_index += b;
                }

                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_CORKSCREWS)
                {
                    vehicleEntry->var_4C = image_index;
                    b = vehicleEntry->var_16 * 80;
                    image_index += b;
                }

                // Unknown
                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_RESTRAINT_ANIMATION)
                {
                    vehicleEntry->var_1C = image_index;
                    b = vehicleEntry->var_16 * 12;
                    image_index += b;
                }

                if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_14)
                {
                    // Same offset as above???
                    vehicleEntry->var_4C = image_index;
                    b = vehicleEntry->var_16 * 32;
                    image_index += b;
                }
            }
            else
            {
                image_index += vehicleEntry->var_16 * 36;
            }

            // No vehicle images
            vehicleEntry->no_vehicle_images = image_index - cur_vehicle_images_offset;

            // Move the offset over this vehicles images. Including peeps
            cur_vehicle_images_offset = image_index + vehicleEntry->no_seating_rows * vehicleEntry->no_vehicle_images;
            // 0x6DEB0D

            if (!(vehicleEntry->flags_a & VEHICLE_ENTRY_FLAG_A_10))
            {
                int num_images = cur_vehicle_images_offset - vehicleEntry->base_image_id;
                if (vehicleEntry->flags_a & VEHICLE_ENTRY_FLAG_A_13)
                {
                    num_images *= 2;
                }

                set_vehicle_type_image_max_sizes(vehicleEntry, num_images);
            }
            vehicleEntry->peep_loading_positions = _peepLoadingPositions[i];
        }
    }

	// 0x6DEB71
    if (RCT2_GLOBAL(0x9ADAFD, uint8) == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            sint16 rideType = _legacyType.ride_type[i];
            if (rideType != RIDE_TYPE_NULL)
            {
                uint8 * typeToRideEntryIndexMap = gTypeToRideEntryIndexMap;
                while (rideType >= 0)
                {
                    if (*typeToRideEntryIndexMap++ == 0xFF)
                    {
                        rideType--;
                    }
                }

                typeToRideEntryIndexMap--;
                uint8 previous_entry = 0;       // TODO set this to entryIndex
                while (typeToRideEntryIndexMap < gTypeToRideEntryIndexMap + Util::CountOf(gTypeToRideEntryIndexMap))
                {
                    uint8 backup_entry = *typeToRideEntryIndexMap;
                    *typeToRideEntryIndexMap++ = previous_entry;
                    previous_entry = backup_entry;
                }
            }
        }
    }
}

void RideObject::Unload()
{
    language_free_object_string(_legacyType.name);
    language_free_object_string(_legacyType.description);
    gfx_object_free_images(_legacyType.images_offset, GetImageTable()->GetCount());
}

const utf8 * RideObject::GetName()
{
    const utf8 * name = GetStringTable()->GetString(OBJ_STRING_ID_NAME);
    return name != nullptr ? name : "";
}

const utf8 * RideObject::GetDescription()
{
    const utf8 * description = GetStringTable()->GetString(OBJ_STRING_ID_DESCRIPTION);
    return description != nullptr ? description : "";
}

const utf8 * RideObject::GetCapacity()
{
    const utf8 * capacity = GetStringTable()->GetString(OBJ_STRING_ID_CAPACITY);
    return capacity != nullptr ? capacity : "";
}

void RideObject::SetRepositoryItem(ObjectRepositoryItem * item) const
{
    for (int i = 0; i < 3; i++)
    {
        item->RideType[i] = _legacyType.ride_type[i];
    }
    for (int i = 0; i < 2; i++)
    {
        item->RideCategory[i] = _legacyType.category[i];
    }

    uint8 flags = 0;
    if ((_legacyType.flags & RIDE_ENTRY_FLAG_SEPARATE_RIDE_NAME) &&
        !rideTypeShouldLoseSeparateFlag(&_legacyType))
    {
        flags |= 0x1000000;
    }
    item->RideFlags = flags;
}
