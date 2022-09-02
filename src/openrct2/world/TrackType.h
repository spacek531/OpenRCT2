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
constexpr const uint32_t NULL_SPRITE = 0xFFFFFFFF;
constexpr const uint16_t NULL_INDEX = 65535;

class TrackTypeObject;

/**
 * The.
 */
enum TrackTypeFlags : uint8_t
{
    UseMirrorElement = (1 << 0), // for tracks which are mirrored of another track element e.g. flatLeftBanked ->
                                 // flatRightBanked
    Animated = (1 << 1),         // For tracks which require map animations (animations applied to all blocks in sequence)
};

enum class TrackTypeColourScheme : uint8_t
{
    Track,
    Supports,
    Misc,
    Scheme3,
    GreenIsPrimaryPinkIsSecondary,
    GreenIsTertiary,
    GreenIsTertiaryPinkIsSecondary,
    GreenIsPrimaryPinkIsTertiary,
    GreenIsPrimaryPinkIsSecondaryYellowIsTertiary,
};

using SupportHeight = int16_t[2];
using TunnelType = uint8_t;
using SupportType = uint8_t;

struct SpriteAndBox
{
    uint32_t SpriteIdParent;
    TrackTypeColourScheme ColourParent;
    uint32_t SpriteIdChild;
    TrackTypeColourScheme ColourChild;
    CoordsXYZ SpriteOffset;
    CoordsXYZ BoxSize;
    CoordsXYZ BoxOffset;

    void Paint(paint_session& session, int32_t height);
};

struct TrackTypeSequenceEntry
{
    SupportType SupportType;
    SupportHeight SupportHeight;
    SpriteAndBox Sprites[MAX_SPRITEBOX_PER_SEQUENCE];

    void Paint(paint_session& session, int32_t height);
};

struct TrackTypeElementEntry
{
    track_type_t TrackElement;
    TrackVariant TrackVariant;
    TunnelType TunnelType;
    uint8_t Flags;
    uint8_t NumSequence;
    TrackTypeSequenceEntry SequenceEntries[4][MAX_SEQUENCE_PER_TRACKELEMENT];

    void Paint(paint_session& session, uint8_t trackSequence, uint8_t direction, int32_t height);
};

struct TrackTypeEntry
{
    // The localised name of this object
    StringId name;
    // the ID of the fallback track type object
    std::string FallbackObjectName;
    // The fallback track type entry
    struct TrackTypeEntry* FallbackType;
    // maps TrackElemType and variant to the index in TTRawEntries
    uint16_t TTElementMap[TrackElemType::Count][MAX_VARIANTS];
    std::vector<TrackTypeElementEntry> TTRawEntries;

    TrackTypeElementEntry* GetTrackTypeElementEntry(track_type_t trackType, TrackVariant trackVariant);
    void Paint(
        paint_session& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
        const TrackElement& trackElement);
};

#ifdef _WIN32
#    define SET_FIELD(fieldname, ...) __VA_ARGS__
#else
#    define SET_FIELD(fieldname, ...) .fieldname = __VA_ARGS__
#endif

TrackTypeEntry CreateNullTrackTypeEntry();
const TrackTypeObject* GetTrackTypeObject(ObjectEntryIndex entryIndex);

TrackTypeEntry NullTrackTypeEntry = CreateNullTrackTypeEntry();
