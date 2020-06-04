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

#include <iterator>

#ifndef NO_VEHICLES
static void vehicle_sprite_paint(
    paint_session* session, const Vehicle* vehicle, int32_t ebx, int32_t ecx, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    int32_t baseImage_id = ebx;
    if (vehicleEntry->draw_order >= std::size(VehicleBoundboxes))
    {
        return;
    }
    vehicle_boundbox bb = VehicleBoundboxes[vehicleEntry->draw_order][ecx];

    if (vehicleEntry->flags & VEHICLE_ENTRY_FLAG_VEHICLE_ANIMATION)
    {
        baseImage_id += vehicle->animation_frame;
    }
    int32_t image_id = baseImage_id | (vehicle->colours.body_colour << 19) | (vehicle->colours.trim_colour << 24)
        | IMAGE_TYPE_REMAP_2_PLUS;

    if (vehicle->IsGhost())
    {
        image_id &= 0x7FFFF;
        image_id |= CONSTRUCTION_MARKER;
    }
    paint_struct* ps = sub_98197C(
        session, image_id, 0, 0, bb.length_x, bb.length_y, bb.length_z, z, bb.offset_x, bb.offset_y, bb.offset_z + z);
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

static void vehicle_sprite_paint_6D51EB(
    paint_session* session, const Vehicle* vehicle, int32_t ebx, int32_t z, const rct_ride_entry_vehicle* vehicleEntry)
{
    int32_t ecx = ebx / 2;
    if (vehicleEntry->flags & VEHICLE_ENTRY_FLAG_11)
    {
        ebx = ebx / 2;
    }
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_15)
    {
        ebx = ebx / 8;
    }
    ebx = (ebx * vehicleEntry->base_num_frames) + vehicleEntry->base_image_id;
    vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
}

static void vehicle_sprite_0(
    paint_session* session, const Vehicle* vehicle, int32_t ebx, int32_t z, const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicle->restraints_position < 64)
    {
        vehicle_sprite_paint_6D51EB(session, vehicle, ebx, z, vehicleEntry);
        return;
    }
    if (!(vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_RESTRAINT_ANIMATION))
    {
        vehicle_sprite_paint_6D51EB(session, vehicle, ebx, z, vehicleEntry);
        return;
    }
    if (ebx & 7)
    {
        vehicle_sprite_paint_6D51EB(session, vehicle, ebx, z, vehicleEntry);
        return;
    }
    int32_t ecx = ebx / 2;
    ebx = ebx / 8;
    ebx += ((vehicle->restraints_position - 64) / 64) * 4;
    ebx *= vehicleEntry->base_num_frames;
    ebx += vehicleEntry->restraint_image_id;
    vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
}

static void vehicle_sprite_1(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_GENTLE_SLOPES)
    {
        int32_t ecx = imageDirection / 2;
        int32_t ebx = ((imageDirection / 8) * vehicleEntry->base_num_frames) + vehicleEntry->gentle_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_0(session, vehicle, imageDirection, z, vehicleEntry);
    }
}
static void vehicle_sprite_2(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_GENTLE_SLOPES)
    {
        
        int32_t ecx = (imageDirection / 2) + 16;
        int32_t ebx = ((imageDirection + 8) * vehicleEntry->base_num_frames) + vehicleEntry->gentle_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
        
    }
    else
    {
        vehicle_sprite_0(session, vehicle, imageDirection, z, vehicleEntry);
    }
}
static void vehicle_sprite_3(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (!(vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_STEEP_SLOPES))
    {
        vehicle_sprite_2(session, vehicle, imageDirection, z, vehicleEntry);
    }
    else
    {
        int32_t ecx = (imageDirection / 4) + 32;
        int32_t ebx = ((imageDirection / 4) * vehicleEntry->base_num_frames) + vehicleEntry->steep_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
}

static void vehicle_sprite_4(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (!(vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_STEEP_SLOPES))
    {
        vehicle_sprite_2(session, vehicle, imageDirection, z, vehicleEntry);
    }
    else
    {
        int32_t ecx = (imageDirection / 2) + 40;
        int32_t ebx = ((imageDirection + 16) * vehicleEntry->base_num_frames) + vehicleEntry->steep_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
}
static void vehicle_sprite_5(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_GENTLE_SLOPES)
    {
        int32_t ecx = imageDirection / 2;
        int32_t ebx = (((imageDirection / 8) + 4) * vehicleEntry->base_num_frames) + vehicleEntry->gentle_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_0(session, vehicle, imageDirection, z, vehicleEntry);
    }
}
static void vehicle_sprite_6(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_GENTLE_SLOPES)
    {
        int32_t ecx = ((imageDirection / 2) ^ 8) + 16;
        int32_t ebx = ((imageDirection + 40) * vehicleEntry->base_num_frames) + vehicleEntry->gentle_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_0(session, vehicle, imageDirection, z, vehicleEntry);
    }
}
static void vehicle_sprite_7(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_STEEP_SLOPES)
    {
        int32_t ecx = ((imageDirection / 4) ^ 4) + 32;
        int32_t ebx = (((imageDirection / 4) + 8) * vehicleEntry->base_num_frames) + vehicleEntry->steep_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_6(session, vehicle, imageDirection, z, vehicleEntry);
    }
}
static void vehicle_sprite_8(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_STEEP_SLOPES)
    {
        int32_t ecx = ((imageDirection / 2) ^ 8) + 40;
        int32_t ebx = ((imageDirection + 48) * vehicleEntry->base_num_frames) + vehicleEntry->steep_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_6(session, vehicle, imageDirection, z, vehicleEntry);
    }
}
// 6D4A81
static void vehicle_sprite_9(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = (imageDirection / 8) + 56;
        int32_t ebx = ((imageDirection / 8) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_4(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4AE8
static void vehicle_sprite_10(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = (imageDirection / 2) + 60;
        int32_t ebx = ((imageDirection + 8) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_4(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4B57
static void vehicle_sprite_11(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = (imageDirection / 8) + 76;
        int32_t ebx = (((imageDirection / 8) + 72) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_4(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4BB7
static void vehicle_sprite_12(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = (imageDirection / 8) + 80;
        int32_t ebx = (((imageDirection / 8) + 80) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_4(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4C17
static void vehicle_sprite_13(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = (imageDirection / 8) + 84;
        int32_t ebx = (((imageDirection / 8) + 88) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_4(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4C77
static void vehicle_sprite_14(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = (imageDirection / 8) + 88;
        int32_t ebx = (((imageDirection / 8) + 96) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_4(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4CD7
static void vehicle_sprite_15(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = (imageDirection / 8) + 92;
        int32_t ebx = (((imageDirection / 8) + 104) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_4(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4D37
static void vehicle_sprite_16(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = (imageDirection / 8) + 96;
        int32_t ebx = (((imageDirection / 8) + 112) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_4(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4AA3
static void vehicle_sprite_17(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicle->UpdateFlag(VEHICLE_UPDATE_FLAG_USE_INVERTED_SPRITES))
    {
        if ((vehicle->track_type >> 2) != TRACK_ELEM_90_DEG_DOWN_TO_60_DEG_DOWN
            && (vehicle->track_type >> 2) != TRACK_ELEM_60_DEG_DOWN_TO_90_DEG_DOWN)
        {
            vehicleEntry--;
        }
    }
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = ((imageDirection / 8) ^ 2) + 56;
        int32_t ebx = (((imageDirection / 8) + 4) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_8(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4B0D
static void vehicle_sprite_18(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicle->UpdateFlag(VEHICLE_UPDATE_FLAG_USE_INVERTED_SPRITES))
    {
        if ((vehicle->track_type >> 2) != TRACK_ELEM_90_DEG_DOWN
            && (vehicle->track_type >> 2) != TRACK_ELEM_90_DEG_DOWN_TO_60_DEG_DOWN
            && (vehicle->track_type >> 2) != TRACK_ELEM_60_DEG_DOWN_TO_90_DEG_DOWN)
        {
            vehicleEntry--;
        }
    }
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = ((imageDirection / 2) ^ 8) + 60;
        int32_t ebx = ((imageDirection + 40) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_8(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4B80
static void vehicle_sprite_19(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicle->UpdateFlag(VEHICLE_UPDATE_FLAG_USE_INVERTED_SPRITES))
    {
        vehicleEntry--;
    }
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = ((imageDirection / 8) ^ 2) + 76;
        int32_t ebx = (((imageDirection / 8) + 76) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_8(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4BE0
static void vehicle_sprite_20(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicle->UpdateFlag(VEHICLE_UPDATE_FLAG_USE_INVERTED_SPRITES))
    {
        vehicleEntry--;
    }
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = ((imageDirection / 8) ^ 2) + 80;
        int32_t ebx = (((imageDirection / 8) + 84) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_8(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4C40
static void vehicle_sprite_21(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicle->UpdateFlag(VEHICLE_UPDATE_FLAG_USE_INVERTED_SPRITES))
    {
        vehicleEntry--;
    }
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = ((imageDirection / 8) ^ 2) + 84;
        int32_t ebx = (((imageDirection / 8) + 92) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_8(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4CA0
static void vehicle_sprite_22(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicle->UpdateFlag(VEHICLE_UPDATE_FLAG_USE_INVERTED_SPRITES))
    {
        vehicleEntry--;
    }
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = ((imageDirection / 8) ^ 2) + 88;
        int32_t ebx = (((imageDirection / 8) + 100) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_8(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D4D00
static void vehicle_sprite_23(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicle->UpdateFlag(VEHICLE_UPDATE_FLAG_USE_INVERTED_SPRITES))
    {
        vehicleEntry--;
    }
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_VERTICAL_SLOPES)
    {
        int32_t ecx = ((imageDirection / 8) ^ 2) + 92;
        int32_t ebx = (((imageDirection / 8) + 108) * vehicleEntry->base_num_frames) + vehicleEntry->vertical_slope_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_8(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

// 6D51A5
static void vehicle_sprite_24(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicle->UpdateFlag(VEHICLE_UPDATE_FLAG_USE_INVERTED_SPRITES))
    {
        vehicleEntry--;
    }
    if (vehicleEntry->sprite_flags & VEHICLE_SPRITE_FLAG_CORKSCREWS)
    {
        int32_t eax = ((vehicle->vehicle_sprite_type - 24) * 4);
        int32_t ecx = (imageDirection / 8) + eax + 144;
        int32_t ebx = (((imageDirection / 8) + eax) * vehicleEntry->base_num_frames) + vehicleEntry->corkscrew_image_id;
        vehicle_sprite_paint(session, vehicle, ebx, ecx, z, vehicleEntry);
    }
    else
    {
        vehicle_sprite_0(session, vehicle, imageDirection, z, vehicleEntry);
    }
}

using vehicle_sprite_func = void (*)(
    paint_session* session, const Vehicle* vehicle, int32_t imageDirection, int32_t z,
    const rct_ride_entry_vehicle* vehicleEntry);

// clang-format off
static constexpr const vehicle_sprite_func disko_sprite_funcs[] = {
    vehicle_sprite_0,
    vehicle_sprite_1,
    vehicle_sprite_2,
    vehicle_sprite_3,
    vehicle_sprite_4,
    vehicle_sprite_5,
    vehicle_sprite_6,
    vehicle_sprite_7,
    vehicle_sprite_8,
    vehicle_sprite_9,
    vehicle_sprite_10,
    vehicle_sprite_11,
    vehicle_sprite_12,
    vehicle_sprite_13,
    vehicle_sprite_14,
    vehicle_sprite_15,
    vehicle_sprite_16,
    vehicle_sprite_17,
    vehicle_sprite_18,
    vehicle_sprite_19,
    vehicle_sprite_20,
    vehicle_sprite_21,
    vehicle_sprite_22,
    vehicle_sprite_23,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_24,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
    vehicle_sprite_0,
};
// clang-format on

void vehicle_visual_disko(
    paint_session* session, int32_t x, int32_t imageDirection, int32_t y, int32_t z, const Vehicle* vehicle,
    const rct_ride_entry_vehicle* vehicleEntry)
{
    if (vehicle->vehicle_sprite_type < std::size(disko_sprite_funcs))
    {
        disko_sprite_funcs[vehicle->vehicle_sprite_type](session, vehicle, imageDirection, z, vehicleEntry);
    }
}
#endif
