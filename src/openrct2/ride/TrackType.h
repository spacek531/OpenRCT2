/*****************************************************************************
 * Copyright (c) 2014-2023 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../common.h"
#include "../core/BitSet.hpp"
#include "../paint/Paint.h"
#include "../paint/Supports.h"
#include "Track.h"
namespace OpenRCT2
{
    namespace TrackPaintObject
    {

        constexpr uint8_t MaxSequencePerTrackPiece = 16;
        constexpr uint8_t MaxSpriteBoxPerSequence = 2;
        constexpr uint8_t MaxTrackVariants = 4;
        constexpr uint32_t NULL_SPRITE = 0xFFFFFFFF;
        constexpr uint16_t TrackTypeElementNullIndex = 65535;

        enum class TunnelWidth : uint8_t
        {
            Thin, // "tube" type tunnels
            Wide  // "box" type tunnels
        };
        enum class SupportsBoundingWidth : uint8_t
        {
            Thin,
            Wide // has a larger support-clearing footprint
        };

        enum class TrackTypeColourScheme : uint8_t
        {
            Track,
            Supports,
            Misc,
            Scheme3,
            GreenIsPrimaryPinkIsSecondary,
            GreenIsTertiary,
            GreenIsTertiaryPinkIsSecondary, // non-classic wooden roller coaster track
            GreenIsPrimaryPinkIsTertiary,
            GreenIsPrimaryPinkIsSecondaryYellowIsTertiary,
            UseDefault = 255,
        };

        struct SpriteBoundBox2
        {
            ImageIndex ImageIdA;
            ImageIndex ImageIdB;
            CoordsXYZ offset;
            ::BoundBoxXYZ BoundBox;
        };

        struct PreviewImage
        {
            uint32_t TrackImage;
            uint32_t SupportsImage;
        };

        struct SpriteAndBox
        {
            uint32_t SpriteIdParent;
            TrackTypeColourScheme ColourParent;
            uint32_t SpriteIdChild;
            TrackTypeColourScheme ColourChild;
            CoordsXYZ SpriteOffset;
            CoordsXYZ BoxSize;
            CoordsXYZ BoxOffset;

            void Paint(PaintSession& session, int32_t height);
        };

        struct TrackTypeSequenceEntry
        {
            uint16_t Flags;

            SpriteAndBox Sprites[MaxSpriteBoxPerSequence];

            void Paint(PaintSession& session, int32_t height);
        };

        struct TrackTypeElementEntry
        {
            track_type_t TrackElement; // TODO: is this important?
            TrackVariant TrackVariant; // TODO: is this important?
            TunnelWidth StartTunnelType;
            TunnelWidth EndTunnelType;
            uint8_t Flags;
            uint8_t NumSequence;
            TrackTypeSequenceEntry SequenceEntries[MaxSequencePerTrackPiece][NumOrthogonalDirections];

            void Paint(PaintSession& session, uint8_t trackSequence, uint8_t direction, int32_t height);
        };

        struct TrackTypeElementMapElement
        {
            uint16_t BaseIndex = TrackTypeElementNullIndex;
            std::underlying_type<TrackVariant> AvailableVariants;
        };

        enum TrackTypeEntryFlags : uint32_t
        {
            OverheadTrack = (1 << 0), // the track is intended to be drawn above the vehicle
        };

        // => The TrackTypeObject starts here <=

        struct TrackTypeEntry
        {
            TunnelWidth tunnelWidth; // TODO: move this to RTD
            SupportsBoundingWidth supportsBoundingWidth;
            int8_t TrackHeight;                     // same as RideHeights::VehicleZOffset
            TrackTypeColourScheme TrackPaintColour; // do not use "UseDefault" TODO: move this to RTD
            MetalSupportType StandardSupport;       // do not use "ForkAlt" TODO: move this to RTD
            WoodenSupportType StandardWoodenSupport; // TODO: move this to RTD
            uint32_t Flags;
            PreviewImage previewImage;

            // maps TrackElemType and variant to the index in TTRawEntries
            uint16_t TTElementMap[TrackElemType::Count];
            std::vector<TrackTypeElementEntry> TTRawEntries;

            
            // The localised name of this object
            StringId name = 0;
            // the ID of the fallback track type object (only used during initialization)
            std::string FallbackObjectName;
            // The fallback track type entry (only used during initialization)
            struct TrackTypeEntry* FallbackType;

            bool SupportsTrackGroup(int32_t trackGroup) const;

            TrackTypeElementEntry GetTrackTypeElementEntry(track_type_t trackType, TrackVariant trackVariant) const;
            void Paint(
                PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
                const TrackElement& trackElement);

            bool Exists()
            {
                return name != 0;
            };
        };

        constexpr TrackTypeElementEntry DummyTTElement = {
            TrackElemType::None, TrackVariant::Standard, TunnelWidth::Wide, TunnelWidth::Wide, 0, 0,
        };

    }; // namespace TrackPaintObject
} // namespace OpenRCT2
