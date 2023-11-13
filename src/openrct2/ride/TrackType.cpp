/*****************************************************************************
 * Copyright (c) 2014-2023 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "TrackType.h"

#include "TrackPaint.h"

namespace OpenRCT2
{
    namespace TrackPaintObject
    {

        static const ImageId GetColour(PaintSession& session, TrackTypeColourScheme colourScheme)
        {
            switch (colourScheme)
            {
                case TrackTypeColourScheme::Track:
                case TrackTypeColourScheme::GreenIsPrimaryPinkIsSecondary:
                    return session.TrackColours[SCHEME_TRACK];
                case TrackTypeColourScheme::Supports:
                case TrackTypeColourScheme::GreenIsTertiary:
                    return session.TrackColours[SCHEME_SUPPORTS];
                case TrackTypeColourScheme::Misc:
                    return session.TrackColours[SCHEME_MISC];
                case TrackTypeColourScheme::Scheme3:
                    return session.TrackColours[SCHEME_3];
                case TrackTypeColourScheme::GreenIsTertiaryPinkIsSecondary:
                    return session.TrackColours[SCHEME_TRACK].IsRemap() // is this check necessary?
                        ? session.TrackColours[SCHEME_TRACK]
                        : session.TrackColours[SCHEME_TRACK].WithPrimary(session.TrackColours[SCHEME_SUPPORTS].GetPrimary());
                case TrackTypeColourScheme::GreenIsPrimaryPinkIsTertiary:
                    return session.TrackColours[SCHEME_TRACK].IsRemap()
                        ? session.TrackColours[SCHEME_TRACK]
                        : session.TrackColours[SCHEME_TRACK].WithSecondary(session.TrackColours[SCHEME_SUPPORTS].GetPrimary());
                case TrackTypeColourScheme::GreenIsPrimaryPinkIsSecondaryYellowIsTertiary:
                    return session.TrackColours[SCHEME_TRACK];
                default:
                    return session.TrackColours[SCHEME_TRACK];
            }
        }

        TrackTypeElementEntry TrackTypeEntry::GetTrackTypeElementEntry(track_type_t trackType, TrackVariant trackVariant) const
        {
            return DummyTTElement;
        }

        void TrackTypeEntry::Paint(
            PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
            const TrackElement& trackElement)
        {
            auto element = GetTrackTypeElementEntry(trackElement.GetTrackType(), trackElement.GetVariant());
            element.Paint(session, trackSequence, direction, height);
        }

        void TrackTypeElementEntry::Paint(PaintSession& session, uint8_t trackSequence, uint8_t direction, int32_t height)
        {
            if (trackSequence >= NumSequence)
                return;
            SequenceEntries[direction][trackSequence].Paint(session, height);
        }

        void TrackTypeSequenceEntry::Paint(PaintSession& session, int32_t height)
        {
            for (uint8_t i = 0; i < MaxSpriteBoxPerSequence && Sprites[i].SpriteIdParent != 0; i++)
                Sprites[i].Paint(session, height);
            // TODO: tunnels
            // TODO: supports
            // TODO: supports blocking
            // TODO: whatever it is that miniature railway track needs
        }

        void SpriteAndBox::Paint(PaintSession& session, int32_t height)
        {
            if (SpriteIdParent == NULL_SPRITE)
                return;
            auto a = GetColour(session, TrackTypeColourScheme::Track);
            /*
            uint32_t imageIdParent = SpriteIdParent | getColour(session, ColourParent);
            PaintAddImageAsParent(
                session, imageIdParent, { SpriteOffset.x, SpriteOffset.y, height + SpriteOffset.z }, BoxSize,
                { BoxOffset.x, BoxOffset.y, height + BoxOffset.z });

            if (SpriteIdChild != NULL_SPRITE)
            {
                uint32_t imageIdChild = SpriteIdChild | getColour(session, ColourChild);
                PaintAddImageAsChild(
                    session, imageIdChild, { SpriteOffset.x, SpriteOffset.y, height + SpriteOffset.z }, BoxSize,
                    { BoxOffset.x, BoxOffset.y, height + BoxOffset.z });
            }
            */
        }

        bool TrackTypeEntry::SupportsTrackGroup(int32_t trackGroup) const
        {
            /* TODO: implement table that stores various information.
             * Requirements:
             * What track pieces are represented by the track group
             * What modifiers are represented by the track group (i.e. chain, giga, taking picture)
             */
            return true;
        }
    } // namespace TrackPaintObject
} // namespace OpenRCT2
