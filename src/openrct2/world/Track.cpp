/*****************************************************************************
 * Copyright (c) 2014-2022 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "Track.h"

#include "../drawing/Drawing.h"
#include "../paint/Paint.h"
#include "../paint/Supports.h"
#include "../paint/tile_element/Paint.TileElement.h"
#include "../ride/RideData.h"
#include "../ride/Track.h"
#include "../ride/TrackData.h"
#include "../ride/TrackPaint.h"
#include "../sprites.h"
#include "../world/Map.h"

static const uint32_t getColour(paint_session& session, PaintMode paintType)
{
    return 0;
}

TrackTypeElementEntry* TrackTypeEntry::GetTrackTypeElementEntry(track_type_t trackType, TrackVariant trackVariant)
{
    if (TTElementMap[trackType][EnumValue(trackVariant)] != nullptr)
        return TTElementMap[trackType][EnumValue(trackVariant)];
    if (TTElementMap[trackType][0] != nullptr)
        return TTElementMap[trackType][0];
    if (FallbackType != nullptr)
        return FallbackType->GetTrackTypeElementEntry(trackType, trackVariant);
    return nullptr;
}

void TrackTypeEntry::Paint(
    paint_session& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement)
{
    auto element = GetTrackTypeElementEntry(trackElement.GetTrackType(), trackElement.GetVariant());
    if (element == nullptr)
        return;
    element->Paint(session, trackSequence, direction, height);
}

void TrackTypeElementEntry::Paint(paint_session& session, uint8_t trackSequence, uint8_t direction, int32_t height)
{
    if (trackSequence > MaxSequence)
        return;
    TrackTypeSequenceEntry sequence = Sequence[trackSequence];
    for (uint8_t i = 0; i < MAX_SPRITEBOX_PER_SEQUENCE && sequence.Sprites[direction][i].SpriteIdParent != 0; i++)
        sequence.Sprites[direction][i].Paint(session, height);
    // TODO: tunnels
    // TODO: supports
    // TODO: supports blocking
    // TODO: whatever it is that miniature railway track needs
}

void SpriteAndBox::Paint(paint_session& session, int32_t height)
{
    if (SpriteIdParent == 0)
        return;

    uint32_t imageIdParent = SpriteIdParent | getColour(session, ColourParent);
    PaintAddImageAsParent(
        session, imageIdParent, { SpriteOffset.x, SpriteOffset.y, height + SpriteOffset.z }, BoxSize,
        { BoxOffset.x, BoxOffset.y, height + BoxOffset.z });

    if (SpriteIdChild != 0)
    {
        uint32_t imageIdChild = SpriteIdChild | getColour(session, ColourChild);
        PaintAddImageAsChild(
            session, imageIdChild, { SpriteOffset.x, SpriteOffset.y, height + SpriteOffset.z }, BoxSize,
            { BoxOffset.x, BoxOffset.y, height + BoxOffset.z });
    }
}
