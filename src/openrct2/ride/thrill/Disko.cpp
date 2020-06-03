/*****************************************************************************
 * Copyright (c) 2014-2019 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../../Game.h"
#include "../../config/Config.h"
#include "../../interface/Viewport.h"
#include "../../paint/Paint.h"
#include "../../paint/Supports.h"
#include "../../scenario/Scenario.h"
#include "../../world/Map.h"
#include "../../world/Sprite.h"
#include "../Track.h"
#include "../TrackPaint.h"
#include "../VehiclePaint.h"


#ifndef NO_VEHICLES

void vehicle_visual_disko(
    paint_session* session, int32_t x, int32_t imageDirection, int32_t y, int32_t z, const Vehicle* vehicle,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    int32_t image_id;
    int32_t baseImage_id = imageDirection + vehicle->animation_frame;
    uint32_t rotation = session->CurrentRotation;
    //int32_t ecx = (vehicle->animation_frame + rotation * 8) & 31; // what frame should be displayed?

    if (vehicleEntry->draw_order >= std::size(VehicleBoundboxes))
    {
        return;
    }
    vehicle_boundbox bb = VehicleBoundboxes[vehicleEntry->draw_order][ecx];

    image_id = baseImage_id | SPRITE_ID_PALETTE_COLOUR_2(vehicle->colours.body_colour, vehicle->colours.trim_colour);
    if (vehicle->IsGhost())
    {
        image_id &= 0x7FFFF;
        image_id |= CONSTRUCTION_MARKER;
    }
    sub_98197C(
        session, image_id, 0, 0, bb->length_x, bb->length_y, bb->length_z, z, bb->offset_x, bb->offset_y, bb->offset_z + z);
    if (ps != nullptr)
    {
        ps->tertiary_colour = vehicle->colours_extended;
    }
    rct_drawpixelinfo* dpi = &session->DPI;
    if (dpi->zoom_level < 2 && vehicle->num_peeps > 0 && vehicleEntry->no_seating_rows > 0)
    {
        baseImage_id += vehicleEntry->no_vehicle_images;
        for (int32_t i = 0; i < 8; i++)
        {
            if (vehicle->num_peeps > (i * 2) && vehicleEntry->no_seating_rows > i)
            {
                image_id = baseImage_id
                    | SPRITE_ID_PALETTE_COLOUR_2(
                               vehicle->peep_tshirt_colours[i * 2], vehicle->peep_tshirt_colours[(i * 2) + 1]);
                if (i == 0 && vehicleEntry->flags & VEHICLE_ENTRY_FLAG_RIDER_ANIMATION)
                {
                    image_id += (vehicleEntry->no_vehicle_images * vehicle->animation_frame);
                }

                if (vehicle->IsGhost())
                {
                    image_id &= 0x7FFFF;
                    image_id |= CONSTRUCTION_MARKER;
                }

                sub_98199C(
                    session, image_id, 0, 0, bb.length_x, bb.length_y, bb.length_z, z, bb.offset_x, bb.offset_y,
                    bb.offset_z + z);
                baseImage_id += vehicleEntry->no_vehicle_images;
            }
        }
    }
}
#endif
