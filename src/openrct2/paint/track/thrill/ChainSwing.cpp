/*****************************************************************************
 * Copyright (c) 2014-2025 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../../../GameState.h"
#include "../../../entity/EntityRegistry.h"
#include "../../../interface/Viewport.h"
#include "../../../ride/Ride.h"
#include "../../../ride/RideEntry.h"
#include "../../../ride/Track.h"
#include "../../../ride/TrackPaint.h"
#include "../../../ride/Vehicle.h"
#include "../../../world/tile_element/TrackElement.h"
#include "../../Boundbox.h"
#include "../../Paint.h"
#include "../../support/WoodenSupports.h"
#include "../../tile_element/Segment.h"
#include "../../track/Segment.h"

using namespace OpenRCT2;
using namespace OpenRCT2::Numerics;
using namespace OpenRCT2::Entity::Yaw;

/*
static void PaintChainSwingRiders(
    PaintSession& session, const RideObjectEntry& rideEntry, Vehicle& vehicle, uint32_t imageOffset, const CoordsXYZ& offset,
    const BoundBoxXYZ& bb)
{
    if (session.DPI.zoom_level > ZoomLevel{ 0 })
        return;
    if (imageOffset >= 12)
        return;

    auto baseImageIndex = rideEntry.Cars[0].base_image_id;
    for (int32_t i = 0; i < 15; i++)
    {
        if (vehicle.num_peeps <= i)
            break;

        auto frameOffset1 = ((imageOffset % 4) * 4 + (i * 4) % 15) & 0x0F;
        auto frameOffset2 = floor2(imageOffset, 4) * 4;
        auto imageTemplate = ImageId(0, vehicle.peep_tshirt_colours[i]);
        auto imageId = imageTemplate.WithIndex(baseImageIndex + 196 + frameOffset1 + frameOffset2);
        PaintAddImageAsChild(session, imageId, offset, bb);
    }
}
*/
static void PaintChainSwingStructure(
    PaintSession& session, const Ride& ride, int8_t xOffset, int8_t yOffset, uint16_t height, const TrackElement& trackElement)
{
    const auto* rideEntry = GetRideEntryByIndex(ride.subtype);
    if (rideEntry == nullptr)
        return;

    Vehicle* vehicle = nullptr;
    if (ride.lifecycleFlags & RIDE_LIFECYCLE_ON_TRACK)
    {
        vehicle = getGameState().entities.GetEntity<Vehicle>(ride.vehicles[0]);
        if (vehicle != nullptr)
        {
            session.InteractionType = ViewportInteractionItem::entity;
            session.CurrentlyDrawnEntity = vehicle;
        }
    }

    // swing orientation in 256-degree rotation
    uint8_t swingOrientation = 0;

    // combined state for pedestal, chair swing angle, and wave angle
    uint8_t cycleProperty = 0;

    // which chair swing angle to use
    uint8_t frame = 0;

    // how high up to draw the chair swing
    uint8_t pedestalPosition = 0;

    // wave angle as a separate property in 256-degree rotation
    uint8_t waveAngle = 0;
    if (vehicle != nullptr)
    {
        swingOrientation = vehicle->flatRideAnimationFrame;
        cycleProperty = vehicle->flatRideSecondaryAnimationFrame;
    }

    Direction trackFacingAngle = trackElement.GetDirectionWithOffset(session.CurrentRotation);

    // rotate the swing's facing angle from relative to the ride to relative to the camera
    swingOrientation -= trackFacingAngle << 6;

    // convert swingAngle to 64-degree rotation. Add this as a property to vehicle object.
    swingOrientation >>= 2;

    constexpr auto cyclePropertyWaveStart = 128;

    auto cappedCycleProperty = std::min<uint8_t>(cycleProperty, cyclePropertyWaveStart);
    // expose the pedestal height options to vehicle object
    pedestalPosition = cappedCycleProperty / 5;
    if (cappedCycleProperty >= cyclePropertyWaveStart)
    {
        frame = 5;
        // convert 128-degree rotation to 256-degree rotation
        waveAngle = (cycleProperty - cyclePropertyWaveStart) << 1;
    }
    else if (cappedCycleProperty >= 116)
    {
        frame = 4;
    }
    else if (cappedCycleProperty >= 104)
    {
        frame = 3;
    }
    else if (cappedCycleProperty >= 90)
    {
        frame = 2;
    }
    else if (cappedCycleProperty >= 60)
    {
        frame = 1;
    }

    // rotate the wave angle from relative to the ride to relative to the camera
    waveAngle -= trackFacingAngle << 6;

    // convert waveAngle to 32-degree rotation. Add this as a property to vehicle object.
    waveAngle >>= 3;

    // frame 0: 0 chair angle
    // frame 1: 5 degree chair angle
    // frame 2: 12 degree chair angle
    // frame 3: 5 degree tilt angle, 25 degree chair angle
    // frame 4: 10 degree tilt angle
    // frame 5: 15 degree tilt angle, wave angle
    static constexpr uint8_t animationFrameOffset[] = { 0, 4, 8, 12, 28, 44 };
    static constexpr SpritePrecision animationFramePrecision[] = { SpritePrecision::Sprites1, SpritePrecision::Sprites1,
                                                                   SpritePrecision::Sprites1, SpritePrecision::Sprites4,
                                                                   SpritePrecision::Sprites4, SpritePrecision::Sprites32 };

    uint32_t imageOffset = (swingOrientation & 3);

    imageOffset += animationFrameOffset[frame] + 4 * (YawToPrecision(waveAngle, animationFramePrecision[frame]));



    CoordsXYZ offset(xOffset, yOffset, height + 7 + pedestalPosition);
    BoundBoxXYZ bb = { { 0, 0, height + 7}, { 24, 24, 128 } };

    auto imageTemplate = ImageId(0, ride.vehicleColours[0].Body, ride.vehicleColours[0].Trim, ride.vehicleColours[0].Tertiary);
    auto imageFlags = GetStationColourScheme(session, trackElement);
    if (imageFlags != TrackStationColour)
    {
        imageTemplate = imageFlags;
    }
    auto imageId = imageTemplate.WithIndex(rideEntry->Cars[0].base_image_id + imageOffset);
    PaintAddImageAsParent(session, imageId, offset, bb);
    /*
    if (vehicle != nullptr)
    {
        PaintChainSwingRiders(session, *rideEntry, *vehicle, imageOffset, offset, bb);
    }*/

    session.CurrentlyDrawnEntity = nullptr;
    session.InteractionType = ViewportInteractionItem::ride;
}

/** 5x5 track blocks
 *   5 13 17 21  6
 *  24  1  9  2 14
 *  20 12  0 10 18
 *  16  4 11  3 22
 *   8 23 19 15  7
 * 5: connect to side 0 and 3
 * 6: connect to side 0 and 1
 * 7: connect to side 1 and 2
 * 8: connect to side 2 and 3
 * 13-15: connect to side 0
 * 16-18: connect to side 1
 * 19-21: connect to side 2
 * 22-14: connect to side 3
 * height markers on 0, 5, 6, 7, 8
 */

static void PaintChainSwing(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement, SupportType supportType)
{
    trackSequence = kTrackMap5x5[direction][trackSequence];

    int32_t edges = kEdges5x5[trackSequence];

    WoodenASupportsPaintSetupRotated(
        session, WoodenSupportType::truss, WoodenSupportSubType::neSw, direction, height,
        GetStationColourScheme(session, trackElement));

    const StationObject* stationObject = ride.getStationObject();
    TrackPaintUtilPaintFloor(session, edges, session.TrackColours, height, kFloorSpritesMulch, stationObject);

    TrackPaintUtilPaintFences(
        session, edges, session.MapPosition, trackElement, ride, session.TrackColours, height, kFenceSpritesRope,
        session.CurrentRotation);

    switch (trackSequence)
    {
        case 8:
            PaintChainSwingStructure(session, ride, -64, 64, height, trackElement);
            break;
        case 19:
            PaintChainSwingStructure(session, ride, -64, 0, height, trackElement);
            break;
        case 3:
            PaintChainSwingStructure(session, ride, -32, -32, height, trackElement);
            break;
        case 18:
            PaintChainSwingStructure(session, ride, 0, -64, height, trackElement);
            break;
        case 6:
            PaintChainSwingStructure(session, ride, 64, -64, height, trackElement);
            break;
        case 17:
            PaintChainSwingStructure(session, ride, 64, 0, height, trackElement);
            break;
        case 20:
            PaintChainSwingStructure(session, ride, 0, 64, height, trackElement);
            break;
    }

    int32_t cornerSegments = 0;
    switch (trackSequence)
    {
        case 5:
            cornerSegments = EnumsToFlags(PaintSegment::top, PaintSegment::topLeft, PaintSegment::topRight);
            break;
        case 6:
            cornerSegments = EnumsToFlags(PaintSegment::topRight, PaintSegment::right, PaintSegment::bottomRight);
            break;
        case 7:
            cornerSegments = EnumsToFlags(PaintSegment::topLeft, PaintSegment::left, PaintSegment::bottomLeft);
            break;
        case 8:
            cornerSegments = EnumsToFlags(PaintSegment::bottomLeft, PaintSegment::bottom, PaintSegment::bottomRight);
            break;
    }
    PaintUtilSetSegmentSupportHeight(session, cornerSegments, height + 2, 0x20);
    PaintUtilSetSegmentSupportHeight(session, kSegmentsAll & ~cornerSegments, 0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 160);
}

TrackPaintFunction GetTrackPaintFunctionChainSwing(OpenRCT2::TrackElemType trackType)
{
    if (trackType != TrackElemType::FlatTrack5x5)
    {
        return TrackPaintFunctionDummy;
    }

    return PaintChainSwing;
}
