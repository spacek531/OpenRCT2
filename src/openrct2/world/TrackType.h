/*****************************************************************************
 * Copyright (c) 2014-2022 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../common.h"
#include "../object/Object.h"
#include "../ride/Track.h"

constexpr const uint8_t MAX_SEQUENCE_PER_TRACKELEMENT = 16;
constexpr const uint8_t MAX_SPRITEBOX_PER_SEQUENCE = 2;
constexpr const uint8_t MAX_VARIANTS = 4;
/**
 * The
 */
enum class TrackFlag : uint8_t
{
    UseMirrorElement = (1 << 0) // for tracks which are mirrored of another track element e.g. flatLeftBanked -> flatRightBanked
};

using SupportData = int16_t[2];
using PaintMode = uint8_t;
using TunnelType = uint8_t;
using SupportType = uint8_t;

struct SpriteAndBox
{
    uint32_t SpriteIdParent;
    uint32_t SpriteIdChild;
    CoordsXYZ SpriteOffset;
    CoordsXYZ BoxSize;
    CoordsXYZ BoxOffset;
    PaintMode ColourParent;
    PaintMode ColourChild;

    void Paint(paint_session& session, int32_t height);
};

struct TrackTypeSequenceEntry
{
    SpriteAndBox Sprites[4][MAX_SPRITEBOX_PER_SEQUENCE];
    SupportData SupportHeight[4];
    SupportType SupportType;
};

struct TrackTypeElementEntry
{
    track_type_t TrackElement;
    uint8_t TrackVariant;
    TunnelType TunnelType;
    TrackTypeSequenceEntry Sequence[MAX_SEQUENCE_PER_TRACKELEMENT];
    TrackFlag Flags;
    uint8_t MaxSequence;

    void Paint(paint_session& session, uint8_t trackSequence, uint8_t direction, int32_t height);
};

struct TrackTypeEntry
{
    // The localised name of this object
    StringId name;
    // The base object of the this object
    uint32_t base_image;
    // the ID of the fallback track type object
    std::string FallbackObjectName;
    // The fallback track type entry
    struct TrackTypeEntry* FallbackType;
    // maps TrackElemType to index of TrackTypeElementEntry variant 0 in elements
    uint16_t TTElementMap[TrackElemType::Count][MAX_VARIANTS];
    std::vector<TrackTypeElementEntry> TTRawEntries;

    TrackTypeElementEntry* GetTrackTypeElementEntry(track_type_t trackType, TrackVariant trackVariant);
    void Paint(
        paint_session& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
        const TrackElement& trackElement);
};
