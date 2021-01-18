#ifndef _RIDECONSTRUCTIONHELPER_
#define _RIDECONSTRUCTIONHELPER_

#include "../ride/track.h"
#include "../ride/RideTypes.h"

money32 place_provisional_track_piece(
    ride_id_t rideIndex, track_type_t trackType, int32_t trackDirection, int32_t liftHillAndAlternativeState,
    const CoordsXYZ& trackPos);
bool window_ride_construction_update_state(
    track_type_t* trackType, int32_t* trackDirection, ride_id_t* rideIndex, int32_t* _liftHillAndAlternativeState,
    CoordsXYZ* trackPos, int32_t* properties);

#endif
