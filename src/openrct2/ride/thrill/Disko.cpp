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
#include "../../sprites.h"
#include "../Track.h"
#include "../TrackPaint.h"
#include "../VehiclePaint.h"

#include <iterator>

int8_t support_locations_60_deg_up[4][2] = { { 32, 32 }, { 32, 30 }, { 32, 28 }, { 32, 32 } };
int8_t support_locations_60_deg_up_to_90_deg_up[4][2] = { { 34, 34 }, { 34, 30 }, { 34, 28 }, { 34, 34 } };
int8_t support_locations_flat_to_60_deg_up_long_base[4][4][2] = {
    { // sequence 0
      { 6, 6 },
      { 6, 6 },
      { 6, 6 },
      { 6, 6 } },
    { // sequence 1
      { 13, 15 },
      { 13, 13 },
      { 13, 13 },
      { 13, 15 } },
    { // sequence 2
      { 16, 16 },
      { 16, 16 },
      { 16, 16 },
      { 16, 16 } },
    { // sequence 3
      { 22, 22 },
      { 22, 22 },
      { 22, 22 },
      { 22, 22 } },
};
int8_t support_locations_60_deg_up_to_flat_long_base[4][4][2] = {
    { // sequence 0
      { 26, 28 },
      { 26, 24 },
      { 26, 24 },
      { 26, 28 } },
    { // sequence 1
      { 20, 24 },
      { 20, 22 },
      { 20, 22 },
      { 20, 24 } },
    { // sequence 2
      { 12, 18 },
      { 12, 18 },
      { 12, 18 },
      { 12, 18 } },
    { // sequence 3
      { 10, 12 },
      { 10, 12 },
      { 10, 12 },
      { 10, 12 } },
};

static void disko_coaster_track_flat(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
        case 2:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT + 0), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 1:
        case 3:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT + 1), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
    };

    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1), 0, height,
        session->TrackColours[SCHEME_SUPPORTS]);
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1), 5, height,
        session->TrackColours[SCHEME_SUPPORTS]);


    paint_util_set_segment_support_height(
        session, paint_util_rotate_segments(SEGMENT_D0 | SEGMENT_C4 | SEGMENT_CC, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
    
}

static void disko_coaster_track_station(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
        case 2:
            sub_98197C(
                session, SPR_STATION_BASE_B_SW_NE | session->TrackColours[SCHEME_MISC], 0, 0, 28, 32, 1, height - 2, 2, 0,
                height);
            sub_98197C_rotated(
                session, direction, (SPR_G2_DISKO_TRACK_FLAT + 0) | session->TrackColours[SCHEME_TRACK], 0, 0, 32, 20, 1,
                height, 0, 6, height + 3);
            metal_a_supports_paint_setup(session, METAL_SUPPORTS_BOXED, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS]);
            metal_a_supports_paint_setup(session, METAL_SUPPORTS_BOXED, 8, 0, height, session->TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
        case 3:
            sub_98197C(
                session, SPR_STATION_BASE_B_NW_SE | session->TrackColours[SCHEME_MISC], 0, 0, 28, 32, 1, height - 2, 2, 0,
                height);
            sub_98197C_rotated(
                session, direction, (SPR_G2_DISKO_TRACK_FLAT + 1) | session->TrackColours[SCHEME_TRACK], 0, 0, 32, 20, 1,
                height, 0, 6, height + 3);
            metal_a_supports_paint_setup(session, METAL_SUPPORTS_BOXED, 6, 0, height, session->TrackColours[SCHEME_SUPPORTS]);
            metal_a_supports_paint_setup(session, METAL_SUPPORTS_BOXED, 7, 0, height, session->TrackColours[SCHEME_SUPPORTS]);
            break;

    }

    auto ride = get_ride(rideIndex);
    if (ride != nullptr)
        track_paint_util_draw_station_platform(session, ride, direction, height, 5, tileElement);

    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_8);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

static void disko_coaster_track_flat_to_25_deg_up(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 0), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 1), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 2), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 3), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
    }
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1), 0, height,
        session->TrackColours[SCHEME_SUPPORTS]);
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1), 7, height,
        session->TrackColours[SCHEME_SUPPORTS]);
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(
        session, paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 48, 0x20);
}

static void disko_coaster_track_25_deg_down_to_flat(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    disko_coaster_track_flat_to_25_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void disko_coaster_track_25_deg_up_to_flat(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 4), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 5), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 6), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 7), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
    }
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1), 4, height,
        session->TrackColours[SCHEME_SUPPORTS]);
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1), 10, height,
        session->TrackColours[SCHEME_SUPPORTS]);
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_14); //what is 14?
    }
    paint_util_set_segment_support_height(
        session, paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 48, 0x20);
}
static void disko_coaster_track_flat_to_25_deg_down(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    disko_coaster_track_25_deg_up_to_flat(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void disko_coaster_track_25_deg_up(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 8), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 9), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 10), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_GENTLE + 11), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
    }
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1), 10, height,
        session->TrackColours[SCHEME_SUPPORTS]);
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1), 13, height,
        session->TrackColours[SCHEME_SUPPORTS]);
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(
        session, paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_D0 | SEGMENT_CC, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

static void disko_coaster_track_25_deg_down(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    disko_coaster_track_25_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void disko_coaster_track_25_deg_up_to_60_deg_up(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
    case 0:
        sub_98197C_rotated(
            session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 0), 0, 0, 32, 20, 3,
            height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(
            session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 1), 0, 0, 32, 20, 3,
            height, 0, 6, height);
        sub_98197C_rotated(
            session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 2), 0, 0, 32, 1, 66,
            height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(
            session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 3), 0, 0, 32, 20, 3,
            height, 0, 6, height);
        sub_98197C_rotated(
            session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 4), 0, 0, 32, 1, 66,
            height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(
            session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 5), 0, 0, 32, 20, 3,
            height, 0, 6, height);
        break;
    }
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1), 10, height,
        session->TrackColours[SCHEME_SUPPORTS]);
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1), 14, height,
        session->TrackColours[SCHEME_SUPPORTS]);
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 24, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(
        session, paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_D0 | SEGMENT_CC, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 72, 0x20);
}

static void disko_coaster_track_60_deg_down_to_25_deg_down(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    disko_coaster_track_25_deg_up_to_60_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void disko_coaster_track_60_deg_up_to_25_deg_up(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 6), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 7), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 8), 0, 0, 32, 1, 66,
                height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 9), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 10), 0, 0, 32, 1, 66,
                height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 11), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
    }
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1), 22, height,
        session->TrackColours[SCHEME_SUPPORTS]);
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1), 24, height,
        session->TrackColours[SCHEME_SUPPORTS]);
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 24, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(
        session, paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_D0 | SEGMENT_CC, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 72, 0x20);
}
static void disko_coaster_track_25_deg_down_to_60_deg_down(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    disko_coaster_track_60_deg_up_to_25_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}
static void disko_coaster_track_60_deg_up(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 12), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 13), 0, 0, 32, 1, 98,
                height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 14), 0, 0, 32, 1, 98,
                height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_STEEP + 15), 0, 0, 32, 20, 3,
                height, 0, 6, height);
            break;
    }
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1),
        support_locations_60_deg_up[direction][0], height,
        session->TrackColours[SCHEME_SUPPORTS]);
    metal_a_supports_paint_setup(
        session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1),
        support_locations_60_deg_up[direction][1], height, session->TrackColours[SCHEME_SUPPORTS]);
    switch (direction)
    {
        case 0:
            paint_util_push_tunnel_left(session, height - 8, TUNNEL_SQUARE_7);
            break;
        case 1:
            paint_util_push_tunnel_right(session, height + 56, TUNNEL_SQUARE_8);
            break;
        case 2:
            paint_util_push_tunnel_left(session, height + 56, TUNNEL_SQUARE_8);
            break;
        case 3:
            paint_util_push_tunnel_right(session, height - 8, TUNNEL_SQUARE_7);
            break;
    }
    paint_util_set_segment_support_height(
        session, paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 104, 0x20);
}

static void disko_coaster_track_60_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    disko_coaster_track_60_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void disko_coaster_track_60_deg_up_to_90_deg_up(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 0), 0, 0, 32,
                        20, 3, height, 0, 6, height);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 1), 0, 0, 2,
                        20, 55, height, 24, 6, height);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 2), 0, 0, 2,
                        20, 55, height, 24, 6, height);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 3), 0, 0, 32,
                        20, 3, height, 0, 6, height);
                    break;
            }
            metal_a_supports_paint_setup(
                session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1),
                support_locations_60_deg_up_to_90_deg_up[direction][0], height,
                session->TrackColours[SCHEME_SUPPORTS]);
            metal_a_supports_paint_setup(
                session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1),
                support_locations_60_deg_up_to_90_deg_up[direction][1], height, session->TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
            }
            paint_util_set_vertical_tunnel(session, height + 56);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 104, 0x20);
            break;
        case 1:
            break;
    }
}

static void disko_coaster_track_90_deg_down_to_60_deg_down(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    disko_coaster_track_60_deg_up_to_90_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void disko_coaster_track_90_deg_up_to_60_deg_up(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 4), 0, 0, 32, 20, 3,
                height, 0, 6, height + 8);
            break;
        case 1:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 5), 0, 0, 2, 20, 31,
                height, 24, 6, height + 8);
            break;
        case 2:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 6), 0, 0, 2, 20, 31,
                height, 24, 6, height + 8);
            break;
        case 3:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 7), 0, 0, 32, 20, 3,
                height, 0, 6, height + 8);
            break;
    }
    switch (direction)
    {
        case 1:
            paint_util_push_tunnel_right(session, height + 48, TUNNEL_SQUARE_8);
            break;
        case 2:
            paint_util_push_tunnel_left(session, height + 48, TUNNEL_SQUARE_8);
            break;
    }
}

static void disko_coaster_track_60_deg_down_to_90_deg_down(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 6), 0, 0, 2,
                        20, 31, height, 24, 6, height + 8);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 7), 0, 0, 32,
                        20, 3, height, 0, 6, height + 8);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 4), 0, 0, 32,
                        20, 3, height, 0, 6, height + 8);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 5), 0, 0, 2,
                        20, 31, height, 24, 6, height + 8);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height + 48, TUNNEL_SQUARE_8);
            }
            break;
        case 1:
            break;
    }
}

static void disko_coaster_track_90_deg_up(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 8), 0, 0, 2,
                        20, 31, height, 4, 6, height + 8);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 9), 0, 0, 2,
                        20, 31, height, 24, 6, height + 8);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 10), 0, 0, 2,
                        20, 31, height, 24, 6, height + 8);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_VERTICAL + 11), 0, 0, 2,
                        20, 31, height, 4, 6, height + 8);
                    break;
            }
            paint_util_set_vertical_tunnel(session, height + 32);
            break;
        case 1:
            break;
    }
}

static void disko_coaster_track_90_deg_down(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    disko_coaster_track_90_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void disko_coaster_track_flat_to_60_deg_up_long_base(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 0), 0, 0,
                        32, 20, 3, height, 0, 6, height);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 4), 0, 0,
                        32, 20, 3, height, 0, 6, height);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 8), 0, 0,
                        32, 20, 3, height, 0, 6, height);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 12), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
            }
            metal_a_supports_paint_setup(
                session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1),
                support_locations_flat_to_60_deg_up_long_base[trackSequence][direction][0], height,
                session->TrackColours[SCHEME_SUPPORTS]);
            metal_a_supports_paint_setup(
                session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1),
                support_locations_flat_to_60_deg_up_long_base[trackSequence][direction][1], height, session->TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 1), 0, 0,
                        32, 20, 3, height, 0, 6, height);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 5), 0, 0,
                        32, 20, 3, height, 0, 6, height);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 9), 0, 0,
                        32, 20, 3, height, 0, 6, height);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 13), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
            }
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 2), 0, 0,
                        32, 20, 3, height, 0, 6, height);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 6), 0, 0,
                        32, 20, 3, height, 0, 6, height);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 10), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 14), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
            }
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 3), 0, 0,
                        32, 20, 3, height, 0, 6, height);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 7), 0, 0,
                        32, 1, 98, height, 0, 27, height);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 11), 0,
                        0, 32, 1, 98, height, 0, 27, height);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 15), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
            }

            metal_a_supports_paint_setup(
                session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1),
                support_locations_flat_to_60_deg_up_long_base[trackSequence][direction][0], height,
                session->TrackColours[SCHEME_SUPPORTS]);
            metal_a_supports_paint_setup(
                session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1),
                support_locations_flat_to_60_deg_up_long_base[trackSequence][direction][1], height,
                session->TrackColours[SCHEME_SUPPORTS]);

            switch (direction)
            {
                case 1:
                    paint_util_push_tunnel_right(session, height + 24, TUNNEL_SQUARE_7);
                    break;
                case 2:
                    paint_util_push_tunnel_left(session, height + 24, TUNNEL_SQUARE_7);
                    break;
            }
            break;
    }
    if (trackSequence > 0 && trackSequence < 3)
    {
        metal_a_supports_paint_setup(
            session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1),
            support_locations_flat_to_60_deg_up_long_base[trackSequence][direction][0], height,
            session->TrackColours[SCHEME_SUPPORTS]);
        metal_a_supports_paint_setup(
            session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1),
            support_locations_flat_to_60_deg_up_long_base[trackSequence][direction][1], height,
            session->TrackColours[SCHEME_SUPPORTS]);
        
    }
    paint_util_set_segment_support_height(
        session, paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 104, 0x20);
}

static void disko_coaster_track_flat_to_60_deg_down_long_base(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    disko_coaster_track_flat_to_60_deg_up_long_base(
        session, rideIndex, 3 - trackSequence, (direction + 2) & 3, height, tileElement);
}

static void disko_coaster_track_60_deg_up_to_flat_long_base(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 16), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 20), 0,
                        0, 32, 1, 98, height, 0, 27, height);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 24), 0,
                        0, 32, 1, 98, height, 0, 27, height);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 28), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
            }
            metal_a_supports_paint_setup(
                session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1),
                support_locations_60_deg_up_to_flat_long_base[trackSequence][direction][0], height,
                session->TrackColours[SCHEME_SUPPORTS]);
            metal_a_supports_paint_setup(
                session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1),
                support_locations_60_deg_up_to_flat_long_base[trackSequence][direction][1], height,
                session->TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_7);
            }
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 17), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 21), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 25), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 29), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
            }
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 18), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 22), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 26), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 30), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
            }
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 19), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 23), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 27), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | (SPR_G2_DISKO_TRACK_FLAT_TO_STEEP + 31), 0,
                        0, 32, 20, 3, height, 0, 6, height);
                    break;
            }
            metal_a_supports_paint_setup(
                session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1),
                support_locations_60_deg_up_to_flat_long_base[trackSequence][direction][0], height,
                session->TrackColours[SCHEME_SUPPORTS]);
            metal_a_supports_paint_setup(
                session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1),
                support_locations_60_deg_up_to_flat_long_base[trackSequence][direction][1], height,
                session->TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 1:
                    paint_util_push_tunnel_right(session, height + 8, TUNNEL_SQUARE_FLAT);
                    break;
                case 2:
                    paint_util_push_tunnel_left(session, height + 8, TUNNEL_SQUARE_FLAT);
                    break;
            }
            break;
    }

    if (trackSequence > 0 && trackSequence < 3)
    {
        metal_a_supports_paint_setup(
            session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 5 + (direction & 1),
            support_locations_60_deg_up_to_flat_long_base[trackSequence][direction][0], height,
            session->TrackColours[SCHEME_SUPPORTS]);
        metal_a_supports_paint_setup(
            session, (direction & 1) ? METAL_SUPPORTS_FORK : METAL_SUPPORTS_FORK_ALT, 8 - (direction & 1),
            support_locations_60_deg_up_to_flat_long_base[trackSequence][direction][1], height,
            session->TrackColours[SCHEME_SUPPORTS]);
    }
    paint_util_set_segment_support_height(
        session, paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 104, 0x20);
}
static void disko_coaster_track_60_deg_down_to_flat_long_base(
    paint_session* session, uint16_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    disko_coaster_track_60_deg_up_to_flat_long_base(
        session, rideIndex, 3 - trackSequence, (direction + 2) & 3, height, tileElement);
}


static void disko_coaster_track_90_deg_to_inverted_flat_quarter_loop_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 0), 0, 0,
                        2, 20, 31, height, 4, 6, height + 8);
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 1), 0, 0,
                        2, 20, 31, height, 4, 32, height + 8);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 5), 0, 0,
                        2, 20, 31, height, 24, -32, height + 8);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 8), 0, 0,
                        2, 20, 31, height, 24, -32, height + 8);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 11), 0, 0,
                        2, 20, 31, height, 4, 6, height + 8);
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 12), 0, 0,
                        2, 20, 31, height, 4, 32, height + 8);
                    break;
            }
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 2), 0, 0,
                        2, 20, 31, height, -8, 6, height);
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 3), 0, 0,
                        2, 20, 63, height, 24, 6, height + 8);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 6), 0, 0,
                        2, 20, 31, height, -8, 6, height);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 9), 0, 0,
                        2, 20, 31, height, -8, 6, height);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 13), 0, 0,
                        2, 20, 31, height, -8, 6, height);
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 14), 0, 0,
                        2, 20, 63, height, 24, 6, height + 8);
                    break;
            }
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 4), 0, 0,
                        32, 20, 3, height, 0, 6, height);
                    break;
                case 1:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 7), 0, 0,
                        2, 20, 3, height, 0, 6, height);
                    break;
                case 2:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 10), 0, 0,
                        2, 20, 3, height, 0, 6, height);
                    break;
                case 3:
                    sub_98197C_rotated(
                        session, direction, session->TrackColours[SCHEME_TRACK]  | (SPR_G2_DISKO_TRACK_QUARTER_LOOP + 15), 0, 0,
                        32, 20, 3, height, 0, 6, height);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height + 16, TUNNEL_SQUARE_FLAT);
            }
            break;
    }
}

static void disko_coaster_track_inverted_flat_to_90_deg_quarter_loop_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    disko_coaster_track_90_deg_to_inverted_flat_quarter_loop_up(
        session, rideIndex, 2 - trackSequence, direction, height, tileElement);
}

TRACK_PAINT_FUNCTION get_track_paint_function_disko_coaster(int32_t trackType, int32_t direction)
{
    switch (trackType)
    {
        // ortho flat track
        case TRACK_ELEM_BOOSTER:
        case TRACK_ELEM_FLAT:
            return disko_coaster_track_flat;
        case TRACK_ELEM_END_STATION:
        case TRACK_ELEM_BEGIN_STATION:
        case TRACK_ELEM_MIDDLE_STATION:
            return disko_coaster_track_station;

        // ortho gentle slopes
        case TRACK_ELEM_FLAT_TO_25_DEG_UP:
            return disko_coaster_track_flat_to_25_deg_up;
        case TRACK_ELEM_25_DEG_DOWN_TO_FLAT:
            return disko_coaster_track_25_deg_down_to_flat;
        case TRACK_ELEM_25_DEG_UP_TO_FLAT:
            return disko_coaster_track_25_deg_up_to_flat;
        case TRACK_ELEM_FLAT_TO_25_DEG_DOWN:
            return disko_coaster_track_flat_to_25_deg_down;
        case TRACK_ELEM_25_DEG_UP:
            return disko_coaster_track_25_deg_up;
        case TRACK_ELEM_25_DEG_DOWN:
            return disko_coaster_track_25_deg_down;

        // ortho steep slopes
        case TRACK_ELEM_25_DEG_UP_TO_60_DEG_UP:
            return disko_coaster_track_25_deg_up_to_60_deg_up;
        case TRACK_ELEM_60_DEG_DOWN_TO_25_DEG_DOWN:
            return disko_coaster_track_60_deg_down_to_25_deg_down;
        case TRACK_ELEM_60_DEG_UP_TO_25_DEG_UP:
            return disko_coaster_track_60_deg_up_to_25_deg_up;
        case TRACK_ELEM_25_DEG_DOWN_TO_60_DEG_DOWN:
            return disko_coaster_track_25_deg_down_to_60_deg_down;
        case TRACK_ELEM_60_DEG_UP:
            return disko_coaster_track_60_deg_up;
        case TRACK_ELEM_60_DEG_DOWN:
            return disko_coaster_track_60_deg_down;

        // ortho vertical slopes
        case TRACK_ELEM_60_DEG_UP_TO_90_DEG_UP:
            return disko_coaster_track_60_deg_up_to_90_deg_up;
        case TRACK_ELEM_90_DEG_DOWN_TO_60_DEG_DOWN:
            return disko_coaster_track_90_deg_down_to_60_deg_down;
        case TRACK_ELEM_90_DEG_UP_TO_60_DEG_UP:
            return disko_coaster_track_90_deg_up_to_60_deg_up;
        case TRACK_ELEM_60_DEG_DOWN_TO_90_DEG_DOWN:
            return disko_coaster_track_60_deg_down_to_90_deg_down;
        case TRACK_ELEM_90_DEG_UP:
            return disko_coaster_track_90_deg_up;
        case TRACK_ELEM_90_DEG_DOWN:
            return disko_coaster_track_90_deg_down;

        case TRACK_ELEM_FLAT_TO_60_DEG_UP_LONG_BASE:
            return disko_coaster_track_flat_to_60_deg_up_long_base;
        case TRACK_ELEM_60_DEG_UP_TO_FLAT_LONG_BASE_122:
            return disko_coaster_track_60_deg_down_to_flat_long_base;
        case TRACK_ELEM_60_DEG_UP_TO_FLAT_LONG_BASE:
            return disko_coaster_track_60_deg_up_to_flat_long_base;
        case TRACK_ELEM_FLAT_TO_60_DEG_DOWN_LONG_BASE:
            return disko_coaster_track_flat_to_60_deg_down_long_base;


        // flat turns
        case TRACK_ELEM_LEFT_QUARTER_TURN_5_TILES:
            return nullptr; // disko_coaster_track_left_quarter_turn_5;
        case TRACK_ELEM_RIGHT_QUARTER_TURN_5_TILES:
            return nullptr; // disko_coaster_track_right_quarter_turn_5;
        case TRACK_ELEM_S_BEND_LEFT:
            return nullptr; // disko_coaster_track_s_bend_left;
        case TRACK_ELEM_S_BEND_RIGHT:
            return nullptr; // disko_coaster_track_s_bend_right;
        case TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES:
            return nullptr; // disko_coaster_track_left_quarter_turn_3;
        case TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES:
            return nullptr; // disko_coaster_track_right_quarter_turn_3;
        case TRACK_ELEM_LEFT_EIGHTH_TO_DIAG:
            return nullptr; // disko_coaster_track_left_eighth_to_diag;
        case TRACK_ELEM_RIGHT_EIGHTH_TO_DIAG:
            return nullptr; // disko_coaster_track_right_eighth_to_diag;
        case TRACK_ELEM_LEFT_EIGHTH_TO_ORTHOGONAL:
            return nullptr; // disko_coaster_track_left_eighth_to_orthogonal;
        case TRACK_ELEM_RIGHT_EIGHTH_TO_ORTHOGONAL:
            return nullptr; // disko_coaster_track_right_eighth_to_orthogonal;

        // diag flat
        case TRACK_ELEM_DIAG_FLAT:
            return nullptr; // disko_coaster_track_diag_flat;

        // diag gentle slopes
        case TRACK_ELEM_DIAG_FLAT_TO_25_DEG_UP:
            return nullptr; // disko_coaster_track_diag_flat_to_25_deg_up;
        case TRACK_ELEM_DIAG_25_DEG_DOWN_TO_FLAT:
            return nullptr; // disko_coaster_track_diag_25_deg_down_to_flat;
        case TRACK_ELEM_DIAG_25_DEG_UP_TO_FLAT:
            return nullptr; // disko_coaster_track_diag_25_deg_up_to_flat;
        case TRACK_ELEM_DIAG_FLAT_TO_25_DEG_DOWN:
            return nullptr; // disko_coaster_track_diag_flat_to_25_deg_down;
        case TRACK_ELEM_DIAG_25_DEG_UP:
            return nullptr; // disko_coaster_track_diag_25_deg_up;
        case TRACK_ELEM_DIAG_25_DEG_DOWN:
            return nullptr; // disko_coaster_track_diag_25_deg_down;

        // diag steep slopes
        case TRACK_ELEM_DIAG_25_DEG_UP_TO_60_DEG_UP:
            return nullptr; // disko_coaster_track_diag_25_deg_up_to_60_deg_up;
        case TRACK_ELEM_DIAG_60_DEG_DOWN_TO_25_DEG_DOWN:
            return nullptr; // disko_coaster_track_diag_60_deg_down_to_25_deg_down;
        case TRACK_ELEM_DIAG_60_DEG_UP_TO_25_DEG_UP:
            return nullptr; // disko_coaster_track_diag_60_deg_up_to_25_deg_up;
        case TRACK_ELEM_DIAG_25_DEG_DOWN_TO_60_DEG_DOWN:
            return nullptr; // disko_coaster_track_diag_25_deg_down_to_60_deg_down;
        case TRACK_ELEM_DIAG_60_DEG_UP:
            return nullptr; // disko_coaster_track_diag_60_deg_up_setup;
        case TRACK_ELEM_DIAG_60_DEG_DOWN:
            return nullptr; // disko_coaster_track_diag_60_deg_down;

        // quarter loops
        case TRACK_ELEM_90_DEG_TO_INVERTED_FLAT_QUARTER_LOOP_UP:
            return disko_coaster_track_90_deg_to_inverted_flat_quarter_loop_up;
        case TRACK_ELEM_INVERTED_FLAT_TO_90_DEG_QUARTER_LOOP_DOWN:
            return disko_coaster_track_inverted_flat_to_90_deg_quarter_loop_down;
    }
    return nullptr;
}
