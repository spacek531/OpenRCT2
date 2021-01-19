/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "CableLift.h"

#include "../audio/audio.h"
#include "../rct12/RCT12.h"
#include "../util/Util.h"
#include "../world/Sprite.h"
#include "Ride.h"
#include "RideData.h"
#include "Track.h"
#include "VehicleData.h"

#include <algorithm>

Vehicle* cable_lift_segment_create(
    Ride& ride, int32_t x, int32_t y, int32_t z, int32_t direction, uint16_t var_44, int32_t remaining_distance, bool head)
{
    Vehicle* current = &(
        create_sprite(SpriteIdentifier::Vehicle, head ? EntityListId::TrainHead : EntityListId::Vehicle)->vehicle);
    current->sprite_identifier = SpriteIdentifier::Vehicle;
    current->ride = ride.id;
    current->ride_subtype = RIDE_ENTRY_INDEX_NULL;
    if (head)
    {
        ride.cable_lift = current->sprite_index;
    }
    current->SubType = head ? Vehicle::Type::Head : Vehicle::Type::Tail;
    current->var_44 = var_44;
    current->remaining_distance = remaining_distance;
    current->sprite_width = 10;
    current->sprite_height_negative = 10;
    current->sprite_height_positive = 10;
    current->mass = 100;
    current->num_seats = 0;
    current->speed = 20;
    current->powered_acceleration = 80;
    current->velocity = 0;
    current->acceleration = 0;
    current->SwingSprite = 0;
    current->SwingPosition = 0;
    current->SwingSpeed = 0;
    current->restraints_position = 0;
    current->spin_sprite = 0;
    current->spin_speed = 0;
    current->sound2_flags = 0;
    current->sound1_id = OpenRCT2::Audio::SoundId::Null;
    current->sound2_id = OpenRCT2::Audio::SoundId::Null;
    current->var_C4 = 0;
    current->animation_frame = 0;
    current->var_C8 = 0;
    current->var_CA = 0;
    current->scream_sound_id = OpenRCT2::Audio::SoundId::Null;
    current->vehicle_sprite_type = 0;
    current->bank_rotation = 0;
    for (auto& peep : current->peep)
    {
        peep = SPRITE_INDEX_NULL;
    }
    current->TrackSubposition = VehicleTrackSubposition::Default;
    current->sprite_direction = direction << 3;

    z = z * COORDS_Z_STEP;
    current->TrackLocation = { x, y, z };
    z += RideTypeDescriptors[ride.type].Heights.VehicleZOffset;

    current->MoveTo({ 16, 16, z });
    current->track_type = (TrackElemType::CableLiftHill << 2) | (current->sprite_direction >> 3);
    current->track_progress = 164;
    current->update_flags = VEHICLE_UPDATE_FLAG_COLLISION_DISABLED;
    current->SetState(Vehicle::Status::MovingToEndOfStation, 0);
    current->num_peeps = 0;
    current->next_free_seat = 0;
    current->BoatLocation.setNull();
    return current;
}

void Vehicle::CableLiftUpdate()
{
    switch (status)
    {
        case Vehicle::Status::MovingToEndOfStation:
            CableLiftUpdateMovingToEndOfStation();
            break;
        case Vehicle::Status::WaitingForPassengers:
            // Stays in this state until a train puts it into next state
            break;
        case Vehicle::Status::WaitingToDepart:
            CableLiftUpdateWaitingToDepart();
            break;
        case Vehicle::Status::Departing:
            CableLiftUpdateDeparting();
            break;
        case Vehicle::Status::Travelling:
            CableLiftUpdateTravelling();
            break;
        case Vehicle::Status::Arriving:
            CableLiftUpdateArriving();
            break;
        default:
            break;
    }
}

/**
 *
 *  rct2: 0x006DF8A4
 */
void Vehicle::CableLiftUpdateMovingToEndOfStation()
{
    if (velocity >= -439800)
        acceleration = -2932;

    if (velocity < -439800)
    {
        velocity -= velocity / 16;
        acceleration = 0;
    }

    if (!(CableLiftUpdateTrackMotion() & VEHICLE_UPDATE_MOTION_TRACK_FLAG_VEHICLE_AT_STATION))
        return;

    velocity = 0;
    acceleration = 0;
    SetState(Vehicle::Status::WaitingForPassengers, sub_state);
}

/**
 *
 *  rct2: 0x006DF8F1
 */
void Vehicle::CableLiftUpdateWaitingToDepart()
{
    if (velocity >= -58640)
        acceleration = -14660;

    if (velocity < -58640)
    {
        velocity -= velocity / 16;
        acceleration = 0;
    }

    CableLiftUpdateTrackMotion();

    // Next check to see if the second part of the cable lift
    // is at the front of the passenger vehicle to simulate the
    // cable being attached underneath the train.
    Vehicle* passengerVehicle = GetEntity<Vehicle>(cable_lift_target);
    Vehicle* cableLiftSecondPart = GetEntity<Vehicle>(prev_vehicle_on_ride);
    if (passengerVehicle == nullptr || cableLiftSecondPart == nullptr)
    {
        return;
    }

    int16_t distX = abs(passengerVehicle->x - cableLiftSecondPart->x);
    int16_t distY = abs(passengerVehicle->y - cableLiftSecondPart->y);

    if (distX + distY > 2)
        return;

    velocity = 0;
    acceleration = 0;
    SetState(Vehicle::Status::Departing, 0);
}

/**
 *
 *  rct2: 0x006DF97A
 */
void Vehicle::CableLiftUpdateDeparting()
{
    sub_state++;
    if (sub_state < 16)
        return;

    Vehicle* passengerVehicle = GetEntity<Vehicle>(cable_lift_target);
    if (passengerVehicle == nullptr)
    {
        return;
    }
    SetState(Vehicle::Status::Travelling, sub_state);
    passengerVehicle->SetState(Vehicle::Status::TravellingCableLift, passengerVehicle->sub_state);
}

/**
 *
 *  rct2: 0x006DF99C
 */
void Vehicle::CableLiftUpdateTravelling()
{
    Vehicle* passengerVehicle = GetEntity<Vehicle>(cable_lift_target);
    if (passengerVehicle == nullptr)
    {
        return;
    }

    velocity = std::min(passengerVehicle->velocity, 439800);
    acceleration = 0;
    if (passengerVehicle->HasUpdateFlag(VEHICLE_UPDATE_FLAG_BROKEN_TRAIN))
        return;

    if (!(CableLiftUpdateTrackMotion() & VEHICLE_UPDATE_MOTION_TRACK_FLAG_1))
        return;

    velocity = 0;
    acceleration = 0;
    SetState(Vehicle::Status::Arriving, 0);
}

/**
 *
 *  rct2: 0x006DF9F0
 */
void Vehicle::CableLiftUpdateArriving()
{
    sub_state++;
    if (sub_state >= 64)
        SetState(Vehicle::Status::MovingToEndOfStation, sub_state);
}

bool Vehicle::CableLiftUpdateTrackMotionForwards()
{
    auto curRide = GetRide();
    if (curRide == nullptr)
        return false;

    for (; remaining_distance >= 13962; _vehicleUnkF64E10++)
    {
        uint16_t trackType = GetTrackType();
        if (trackType == TrackElemType::CableLiftHill && track_progress == 160)
        {
            _vehicleMotionTrackFlags |= VEHICLE_UPDATE_MOTION_TRACK_FLAG_1;
        }

        uint16_t trackProgress = track_progress + 1;

        uint16_t trackTotalProgress = GetTrackProgress();
        if (trackProgress >= trackTotalProgress)
        {
            TileElement* trackElement = map_get_track_element_at_of_type_seq(TrackLocation, trackType, 0);

            CoordsXYE output;
            int32_t outputZ;
            int32_t outputDirection;

            auto input = CoordsXYE{ TrackLocation, trackElement };

            if (!track_block_get_next(&input, &output, &outputZ, &outputDirection))
                return false;

            if (TrackPitchAndRollEnd(trackType) != TrackPitchAndRollStart(output.element->AsTrack()->GetTrackType()))
                return false;

            TrackLocation = { output, outputZ };
            track_direction = outputDirection;
            track_type |= output.element->AsTrack()->GetTrackType() << 2;
            trackProgress = 0;
        }

        track_progress = trackProgress;
        const auto moveInfo = GetMoveInfo();
        auto unk = CoordsXYZ{ moveInfo->x, moveInfo->y, moveInfo->z } + TrackLocation;

        uint8_t bx = 0;
        unk.z += RideTypeDescriptors[curRide->type].Heights.VehicleZOffset;
        if (unk.x != unk_F64E20.x)
            bx |= (1 << 0);
        if (unk.y != unk_F64E20.y)
            bx |= (1 << 1);
        if (unk.z != unk_F64E20.z)
            bx |= (1 << 2);

        remaining_distance -= dword_9A2930[bx];
        unk_F64E20.x = unk.x;
        unk_F64E20.y = unk.y;
        unk_F64E20.z = unk.z;

        sprite_direction = moveInfo->direction;
        bank_rotation = moveInfo->bank_rotation;
        vehicle_sprite_type = moveInfo->vehicle_sprite_type;

        if (remaining_distance >= 13962)
        {
            acceleration += dword_9A2970[vehicle_sprite_type];
        }
    }
    return true;
}

bool Vehicle::CableLiftUpdateTrackMotionBackwards()
{
    auto curRide = GetRide();
    if (curRide == nullptr)
        return false;

    for (; remaining_distance < 0; _vehicleUnkF64E10++)
    {
        uint16_t trackProgress = track_progress - 1;

        if (static_cast<int16_t>(trackProgress) == -1)
        {
            uint16_t trackType = GetTrackType();
            TileElement* trackElement = map_get_track_element_at_of_type_seq(TrackLocation, trackType, 0);

            auto input = CoordsXYE{ TrackLocation, trackElement };
            track_begin_end output;

            if (!track_block_get_previous(input, &output))
                return false;

            if (TrackPitchAndRollStart(trackType) != TrackPitchAndRollEnd(output.begin_element->AsTrack()->GetTrackType()))
                return false;

            TrackLocation = { output.begin_x, output.begin_y, output.begin_z };
            track_direction = output.begin_direction;
            track_type |= output.begin_element->AsTrack()->GetTrackType() << 2;

            if (output.begin_element->AsTrack()->GetTrackType() == TrackElemType::EndStation)
            {
                _vehicleMotionTrackFlags = VEHICLE_UPDATE_MOTION_TRACK_FLAG_VEHICLE_AT_STATION;
            }

            uint16_t trackTotalProgress = GetTrackProgress();
            trackProgress = trackTotalProgress - 1;
        }
        track_progress = trackProgress;
        const auto moveInfo = GetMoveInfo();
        auto unk = CoordsXYZ{ moveInfo->x, moveInfo->y, moveInfo->z } + TrackLocation;

        uint8_t bx = 0;
        unk.z += RideTypeDescriptors[curRide->type].Heights.VehicleZOffset;
        if (unk.x != unk_F64E20.x)
            bx |= (1 << 0);
        if (unk.y != unk_F64E20.y)
            bx |= (1 << 1);
        if (unk.z != unk_F64E20.z)
            bx |= (1 << 2);

        remaining_distance += dword_9A2930[bx];
        unk_F64E20.x = unk.x;
        unk_F64E20.y = unk.y;
        unk_F64E20.z = unk.z;

        sprite_direction = moveInfo->direction;
        bank_rotation = moveInfo->bank_rotation;
        vehicle_sprite_type = moveInfo->vehicle_sprite_type;

        if (remaining_distance < 0)
        {
            acceleration += dword_9A2970[vehicle_sprite_type];
        }
    }
    return true;
}

/**
 *
 *  rct2: 0x006DEF56
 */
int32_t Vehicle::CableLiftUpdateTrackMotion()
{
    _vehicleF64E2C = 0;
    gCurrentVehicle = this;
    _vehicleMotionTrackFlags = 0;
    _vehicleStationIndex = STATION_INDEX_NULL;

    velocity += acceleration;
    _vehicleVelocityF64E08 = velocity;
    _vehicleVelocityF64E0C = (velocity / 1024) * 42;

    Vehicle* frontVehicle = this;
    if (velocity < 0)
    {
        frontVehicle = TrainTail();
    }

    _vehicleFrontVehicle = frontVehicle;

    for (Vehicle* vehicle = frontVehicle; vehicle != nullptr;)
    {
        vehicle->acceleration = dword_9A2970[vehicle->vehicle_sprite_type];
        _vehicleUnkF64E10 = 1;
        vehicle->remaining_distance += _vehicleVelocityF64E0C;

        if (vehicle->remaining_distance < 0 || vehicle->remaining_distance >= 13962)
        {
            unk_F64E20.x = vehicle->x;
            unk_F64E20.y = vehicle->y;
            unk_F64E20.z = vehicle->z;
            vehicle->Invalidate();

            while (true)
            {
                if (vehicle->remaining_distance < 0)
                {
                    if (vehicle->CableLiftUpdateTrackMotionBackwards())
                    {
                        break;
                    }
                    else
                    {
                        _vehicleMotionTrackFlags |= VEHICLE_UPDATE_MOTION_TRACK_FLAG_5;
                        _vehicleVelocityF64E0C -= vehicle->remaining_distance - 13962;
                        vehicle->remaining_distance = 13962;
                        vehicle->acceleration += dword_9A2970[vehicle->vehicle_sprite_type];
                        _vehicleUnkF64E10++;
                        continue;
                    }
                }
                else
                {
                    if (vehicle->CableLiftUpdateTrackMotionForwards())
                    {
                        break;
                    }
                    else
                    {
                        _vehicleMotionTrackFlags |= VEHICLE_UPDATE_MOTION_TRACK_FLAG_5;
                        _vehicleVelocityF64E0C -= vehicle->remaining_distance + 1;
                        vehicle->remaining_distance = -1;
                        vehicle->acceleration += dword_9A2970[vehicle->vehicle_sprite_type];
                        _vehicleUnkF64E10++;
                    }
                }
            }
            vehicle->MoveTo(unk_F64E20);
        }
        vehicle->acceleration /= _vehicleUnkF64E10;
        if (_vehicleVelocityF64E08 >= 0)
        {
            vehicle = GetEntity<Vehicle>(vehicle->next_vehicle_on_train);
        }
        else
        {
            if (vehicle == this)
                break;
            vehicle = GetEntity<Vehicle>(vehicle->prev_vehicle_on_ride);
        }
    }

    uint32_t vehicleCount = 0;
    uint16_t massTotal = 0;
    int32_t accelerationTotal = 0;

    for (Vehicle* vehicle = GetEntity<Vehicle>(sprite_index); vehicle != nullptr;
         vehicle = GetEntity<Vehicle>(vehicle->next_vehicle_on_train))
    {
        vehicleCount++;

        massTotal += vehicle->mass;
        accelerationTotal = add_clamp_int32_t(accelerationTotal, vehicle->acceleration);
    }

    int32_t newAcceleration = (accelerationTotal / vehicleCount) >> 9;
    newAcceleration -= velocity >> 12;

    int32_t edx = velocity >> 8;
    edx *= edx;
    if (velocity < 0)
    {
        edx = -edx;
    }
    edx >>= 4;
    newAcceleration -= edx / massTotal;

    acceleration = newAcceleration;
    return _vehicleMotionTrackFlags;
}
