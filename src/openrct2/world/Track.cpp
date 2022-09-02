#include "Track.h"
#include "../ride/Track.h"
#include "../drawing/Drawing.h"
#include "../paint/Paint.h"
#include "../paint/Supports.h"
#include "../paint/tile_element/Paint.TileElement.h"
#include "../sprites.h"
#include "../world/Map.h"
#include "../ride/RideData.h"
#include "../ride/TrackData.h"
#include "../ride/TrackPaint.h"


static const uint32_t getColour(paint_session& session, PaintMode paintType)
{
    return 0;
}

void PaintSpriteAndBox(paint_session& session, const SpriteAndBox& sab, int32_t height)
{
    if (sab.SpriteIdParent == 0)
        return;

    uint32_t imageIdParent = sab.SpriteIdParent | getColour(session, sab.ColourParent);
    PaintAddImageAsParent(
        session, imageIdParent, { sab.SpriteOffset.x, sab.SpriteOffset.y, height + sab.SpriteOffset.z }, sab.BoxSize,
        { sab.BoxOffset.x, sab.BoxOffset.y, height + sab.BoxOffset.z });

    if (sab.SpriteIdChild != 0)
    {
        uint32_t imageIdChild = sab.SpriteIdChild | getColour(session, sab.ColourChild);
        PaintAddImageAsParent(
            session, imageIdChild, { sab.SpriteOffset.x, sab.SpriteOffset.y, height + sab.SpriteOffset.z }, sab.BoxSize,
            { sab.BoxOffset.x, sab.BoxOffset.y, height + sab.BoxOffset.z });
    }
}
