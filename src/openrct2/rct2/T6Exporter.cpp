/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "T6Exporter.h"

#include "../Context.h"
#include "../core/FileStream.h"
#include "../core/MemoryStream.h"
#include "../localisation/Localisation.h"
#include "../localisation/StringIds.h"
#include "../object/ObjectList.h"
#include "../rct12/SawyerChunkWriter.h"
#include "../ride/Ride.h"
#include "../ride/Station.h"
#include "../ride/Track.h"
#include "../ride/TrackData.h"
#include "../ride/TrackDesign.h"
#include "../ride/TrackDesignRepository.h"
#include "../windows/Intent.h"

#include <functional>

T6Exporter::T6Exporter(TrackDesign* trackDesign)
    : _trackDesign(trackDesign)
{
}

bool T6Exporter::SaveTrack(const utf8* path)
{
    try
    {
        auto fs = OpenRCT2::FileStream(path, OpenRCT2::FILE_MODE_WRITE);
        return SaveTrack(&fs);
    }
    catch (const std::exception& e)
    {
        log_error("Unable to save track design: %s", e.what());
        return false;
    }
}

bool T6Exporter::SaveTrack(OpenRCT2::IStream* stream)
{
    OpenRCT2::MemoryStream tempStream;
    tempStream.WriteValue<uint8_t>(_trackDesign->type);
    tempStream.WriteValue<uint8_t>(_trackDesign->vehicle_type);
    tempStream.WriteValue<uint32_t>(_trackDesign->flags);
    tempStream.WriteValue<uint8_t>(static_cast<uint8_t>(_trackDesign->ride_mode));
    tempStream.WriteValue<uint8_t>((_trackDesign->colour_scheme & 0x3) | (2 << 2));
    tempStream.WriteArray(_trackDesign->vehicle_colours.data(), RCT12_MAX_VEHICLE_COLOURS);
    tempStream.WriteValue<uint8_t>(0);
    tempStream.WriteValue<uint8_t>(_trackDesign->entrance_style);
    tempStream.WriteValue<uint8_t>(_trackDesign->total_air_time);
    tempStream.WriteValue<uint8_t>(_trackDesign->depart_flags);
    tempStream.WriteValue<uint8_t>(_trackDesign->number_of_trains);
    tempStream.WriteValue<uint8_t>(_trackDesign->number_of_cars_per_train);
    tempStream.WriteValue<uint8_t>(_trackDesign->min_waiting_time);
    tempStream.WriteValue<uint8_t>(_trackDesign->max_waiting_time);
    tempStream.WriteValue<uint8_t>(_trackDesign->operation_setting);
    tempStream.WriteValue<int8_t>(_trackDesign->max_speed);
    tempStream.WriteValue<int8_t>(_trackDesign->average_speed);
    tempStream.WriteValue<uint16_t>(_trackDesign->ride_length);
    tempStream.WriteValue<uint8_t>(_trackDesign->max_positive_vertical_g);
    tempStream.WriteValue<int8_t>(_trackDesign->max_negative_vertical_g);
    tempStream.WriteValue<uint8_t>(_trackDesign->max_lateral_g);
    tempStream.WriteValue<uint8_t>(_trackDesign->type == RIDE_TYPE_MINI_GOLF ? _trackDesign->holes : _trackDesign->inversions);
    tempStream.WriteValue<uint8_t>(_trackDesign->drops);
    tempStream.WriteValue<uint8_t>(_trackDesign->highest_drop_height);
    tempStream.WriteValue<uint8_t>(_trackDesign->excitement);
    tempStream.WriteValue<uint8_t>(_trackDesign->intensity);
    tempStream.WriteValue<uint8_t>(_trackDesign->nausea);
    tempStream.WriteValue<money16>(_trackDesign->upkeep_cost);
    tempStream.WriteArray(_trackDesign->track_spine_colour, RCT12_NUM_COLOUR_SCHEMES);
    tempStream.WriteArray(_trackDesign->track_rail_colour, RCT12_NUM_COLOUR_SCHEMES);
    tempStream.WriteArray(_trackDesign->track_support_colour, RCT12_NUM_COLOUR_SCHEMES);
    tempStream.WriteValue<uint32_t>(_trackDesign->flags2);
    tempStream.Write(&_trackDesign->vehicle_object, sizeof(rct_object_entry));
    tempStream.WriteValue<uint8_t>(_trackDesign->space_required_x);
    tempStream.WriteValue<uint8_t>(_trackDesign->space_required_y);
    tempStream.WriteArray(_trackDesign->vehicle_additional_colour, RCT2_MAX_CARS_PER_TRAIN);
    tempStream.WriteValue<uint8_t>(_trackDesign->lift_hill_speed | (_trackDesign->num_circuits << 5));

    if (_trackDesign->type == RIDE_TYPE_MAZE)
    {
        for (const auto& mazeElement : _trackDesign->maze_elements)
        {
            tempStream.WriteValue<uint32_t>(mazeElement.all);
        }

        tempStream.WriteValue<uint32_t>(0);
    }
    else
    {
        for (const auto& trackElement : _trackDesign->track_elements)
        {
            auto trackType = trackElement.type;
            if (trackElement.type == TrackElemType::RotationControlToggle)
            {
                trackType = TrackElemType::RotationControlToggleAlias;
            }
            else if (trackType == TrackElemType::MultiDimInvertedUp90ToFlatQuarterLoop)
            {
                trackType = TrackElemType::InvertedUp90ToFlatQuarterLoopAlias;
            }
            tempStream.WriteValue<uint8_t>(static_cast<uint8_t>(trackType));
            tempStream.WriteValue<uint8_t>(trackElement.flags);
        }

        tempStream.WriteValue<uint8_t>(0xFF);

        for (const auto& entranceElement : _trackDesign->entrance_elements)
        {
            tempStream.WriteValue<uint8_t>(entranceElement.z == -1 ? static_cast<uint8_t>(0x80) : entranceElement.z);
            tempStream.WriteValue<uint8_t>(entranceElement.direction | (entranceElement.isExit << 7));
            tempStream.WriteValue<int16_t>(entranceElement.x);
            tempStream.WriteValue<int16_t>(entranceElement.y);
        }

        tempStream.WriteValue<uint8_t>(0xFF);
    }

    for (const auto& sceneryElement : _trackDesign->scenery_elements)
    {
        tempStream.Write(&sceneryElement.scenery_object, sizeof(rct_object_entry));
        tempStream.WriteValue<int8_t>(sceneryElement.x);
        tempStream.WriteValue<int8_t>(sceneryElement.y);
        tempStream.WriteValue<int8_t>(sceneryElement.z);
        tempStream.WriteValue<uint8_t>(sceneryElement.flags);
        tempStream.WriteValue<uint8_t>(sceneryElement.primary_colour);
        tempStream.WriteValue<uint8_t>(sceneryElement.secondary_colour);
    }

    tempStream.WriteValue<uint8_t>(0xFF);

    SawyerChunkWriter sawyerCoding(stream);
    sawyerCoding.WriteChunkTrack(tempStream.GetData(), tempStream.GetLength());
    return true;
}
