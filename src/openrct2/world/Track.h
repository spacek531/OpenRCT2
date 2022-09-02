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

constexpr const uint8_t MAX_SEQUENCE_PER_TRACKELEMENT = 16;
constexpr const uint8_t MAX_SPRITEBOX_PER_SEQUENCE = 2;
constexpr const uint16_t NULL_ELEMENT = 65535;
/**
 * The
 */
enum class TrackFlag : uint8_t
{
    SpritesTwoDirections = (1 << 0), // for tracks which are mirrored along their length e.g. flat, brakes (how useful is this
                                     // truly?)
    UseMirrorElement = (1 << 1) // for tracks which are mirrored of another track element e.g. flatLeftBanked -> flatRightBanked
};

enum class TrackVariant : uint8_t
{
    Standard = 0,
    BrakesClosed = 0,
    ChainLift = 1,
    BrakesOpen = 2,
    CableLift = 3,

    Count = 4,
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
};

struct TrackTypeSequenceEntry
{
    SpriteAndBox sprites[4][MAX_SPRITEBOX_PER_SEQUENCE];
    SupportData supportHeight[4];
    SupportType supportType;
};

struct TrackTypeElementEntry
{
    track_type_t trackElement;
    uint8_t trackVariant;
    TunnelType tunnelType;
    TrackTypeSequenceEntry sequence[MAX_SEQUENCE_PER_TRACKELEMENT];
    TrackFlag flags;
    uint8_t maxSequence;

    void Paint(paint_session& session, uint8_t trackSequence, uint8_t direction, int32_t height);
};

struct TrackTypeEntry
{
    StringId name;
    std::string fallbackObjectName;
    struct TrackTypeEntry* fallbackType;
    uint32_t base_image;
    // maps TrackElemType to index of TrackTypeElementEntry variant 0 in elements
    uint16_t elementIndices[TrackElemType::Count + 1];
    std::vector<TrackTypeElementEntry*> elements;

    TrackTypeElementEntry* GetTrackTypeElementEntry(track_type_t trackType, uint8_t trackVariant)
    {
        if (elementIndices[trackType] != NULL_ELEMENT
            && elementIndices[trackType + 1] > elementIndices[trackType] + trackVariant)
        {
            auto element = elements[elementIndices[trackType] + trackVariant];
            if (element != nullptr)
                return element;
            return elements[elementIndices[trackType]];
        }
        if (fallbackType != nullptr)
            return fallbackType->GetTrackTypeElementEntry(trackType, trackVariant);
        return nullptr;
    }

    void Paint(
        paint_session& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
        const TrackElement& trackElement)
    {
        uint16_t trackVariant = trackElement.GetVariant();
        auto element = GetTrackTypeElementEntry(trackElement.GetTrackType(), trackVariant);
        if (element == nullptr)
            return;
        element->Paint(session, trackSequence, direction, height);
    }
};
