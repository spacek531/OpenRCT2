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

static void disko_coaster_track_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
        case 2:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | 21606, 0, 0, 32, 27, 2, height, 0, 2, height);
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | 21608, 0, 0, 32, 27, 0, height, 0, 2,
                height + 27);
            wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
        case 3:
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | 21607, 0, 0, 32, 27, 2, height, 0, 2, height);
            sub_98197C_rotated(
                session, direction, session->TrackColours[SCHEME_TRACK] | 21609, 0, 0, 32, 27, 0, height, 0, 2,
                height + 27);
            wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}




TRACK_PAINT_FUNCTION get_track_paint_function_disko_coaster(int32_t trackType, int32_t direction)
{
    switch (trackType)
    {
        case TRACK_ELEM_FLAT:
            return disko_coaster_track_flat;
        case TRACK_ELEM_END_STATION:
        case TRACK_ELEM_BEGIN_STATION:
        case TRACK_ELEM_MIDDLE_STATION:
            return side_friction_rc_track_station;
        case TRACK_ELEM_25_DEG_UP:
            return side_friction_rc_track_25_deg_up;
        case TRACK_ELEM_FLAT_TO_25_DEG_UP:
            return side_friction_rc_track_flat_to_25_deg_up;
        case TRACK_ELEM_25_DEG_UP_TO_FLAT:
            return side_friction_rc_track_25_deg_up_to_flat;
        case TRACK_ELEM_25_DEG_DOWN:
            return side_friction_rc_track_25_deg_down;
        case TRACK_ELEM_FLAT_TO_25_DEG_DOWN:
            return side_friction_rc_track_flat_to_25_deg_down;
        case TRACK_ELEM_25_DEG_DOWN_TO_FLAT:
            return side_friction_rc_track_25_deg_down_to_flat;
        case TRACK_ELEM_LEFT_QUARTER_TURN_5_TILES:
            return side_friction_rc_track_left_quarter_turn_5;
        case TRACK_ELEM_RIGHT_QUARTER_TURN_5_TILES:
            return side_friction_rc_track_right_quarter_turn_5;
        case TRACK_ELEM_S_BEND_LEFT:
            return side_friction_rc_track_s_bend_left;
        case TRACK_ELEM_S_BEND_RIGHT:
            return side_friction_rc_track_s_bend_right;
        case TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES:
            return side_friction_rc_track_left_quarter_turn_3;
        case TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES:
            return side_friction_rc_track_right_quarter_turn_3;
        case TRACK_ELEM_BRAKES:
            return side_friction_rc_track_brakes;
        case TRACK_ELEM_LEFT_EIGHTH_TO_DIAG:
            return side_friction_rc_track_left_eighth_to_diag;
        case TRACK_ELEM_RIGHT_EIGHTH_TO_DIAG:
            return side_friction_rc_track_right_eighth_to_diag;
        case TRACK_ELEM_LEFT_EIGHTH_TO_ORTHOGONAL:
            return side_friction_rc_track_left_eighth_to_orthogonal;
        case TRACK_ELEM_RIGHT_EIGHTH_TO_ORTHOGONAL:
            return side_friction_rc_track_right_eighth_to_orthogonal;
        case TRACK_ELEM_DIAG_FLAT:
            return side_friction_rc_track_diag_flat;
        case TRACK_ELEM_DIAG_25_DEG_UP:
            return side_friction_rc_track_diag_25_deg_up;
        case TRACK_ELEM_DIAG_FLAT_TO_25_DEG_UP:
            return side_friction_rc_track_diag_flat_to_25_deg_up;
        case TRACK_ELEM_DIAG_25_DEG_UP_TO_FLAT:
            return side_friction_rc_track_diag_25_deg_up_to_flat;
        case TRACK_ELEM_DIAG_25_DEG_DOWN:
            return side_friction_rc_track_diag_25_deg_down;
        case TRACK_ELEM_DIAG_FLAT_TO_25_DEG_DOWN:
            return side_friction_rc_track_diag_flat_to_25_deg_down;
        case TRACK_ELEM_DIAG_25_DEG_DOWN_TO_FLAT:
            return side_friction_rc_track_diag_25_deg_down_to_flat;

        // Added by OpenRCT2
        case TRACK_ELEM_25_DEG_DOWN_TO_60_DEG_DOWN:
            return side_friction_rc_track_25_deg_down_to_60_deg_down;
        case TRACK_ELEM_60_DEG_DOWN_TO_25_DEG_DOWN:
            return side_friction_rc_track_60_deg_down_to_25_deg_down;
        case TRACK_ELEM_25_DEG_UP_TO_60_DEG_UP:
            return side_friction_rc_track_25_deg_up_to_60_deg_up;
        case TRACK_ELEM_60_DEG_UP_TO_25_DEG_UP:
            return side_friction_rc_track_60_deg_up_to_25_deg_up;
        case TRACK_ELEM_60_DEG_UP:
            return side_friction_rc_track_60_deg_up;
        case TRACK_ELEM_60_DEG_DOWN:
            return side_friction_rc_track_60_deg_down;

        case TRACK_ELEM_DIAG_60_DEG_UP:
            return side_friction_rc_track_diag_60_deg_up;
        case TRACK_ELEM_DIAG_60_DEG_DOWN:
            return side_friction_rc_track_diag_60_deg_down;
        case TRACK_ELEM_DIAG_60_DEG_UP_TO_25_DEG_UP:
            return side_friction_rc_track_diag_60_deg_up_to_25_deg_up;
        case TRACK_ELEM_DIAG_25_DEG_DOWN_TO_60_DEG_DOWN:
            return side_friction_rc_track_diag_25_deg_down_to_60_deg_down;
        case TRACK_ELEM_DIAG_25_DEG_UP_TO_60_DEG_UP:
            return side_friction_rc_track_diag_25_deg_up_to_60_deg_up;
        case TRACK_ELEM_DIAG_60_DEG_DOWN_TO_25_DEG_DOWN:
            return side_friction_rc_track_diag_60_deg_down_to_25_deg_down;
    }
    return nullptr;
}
