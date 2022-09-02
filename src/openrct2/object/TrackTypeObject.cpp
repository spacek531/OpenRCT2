/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "TrackTypeObject.h"

#include "../core/IStream.hpp"
#include "../core/Json.hpp"
#include "../core/String.hpp"
#include "../drawing/Drawing.h"
#include "../drawing/Image.h"
#include "../localisation/Localisation.h"

void TrackTypeObject::Load()
{
    GetStringTable().Sort();
    NameStringId = language_allocate_object_string(GetName());

    auto numImages = GetImageTable().GetCount();
    if (numImages != 0)
    {
        BaseImageId = gfx_object_allocate_images(GetImageTable().GetImages(), GetImageTable().GetCount());
    }
}

void TrackTypeObject::Unload()
{
    language_free_object_string(NameStringId);
    gfx_object_free_images(BaseImageId, GetImageTable().GetCount());
}

void TrackTypeObject::ReadJson(IReadObjectContext* context, json_t& root)
{
    Guard::Assert(root.is_object(), "TrackTypeObject::ReadJson expects parameter root to be object");

    auto properties = root["properties"];

    if (properties.is_object())
    {
        Flags = Json::GetFlags<uint32_t>(
            properties,
            {
                { "hasPrimaryColour", 0 },
            });
    }

    PopulateTablesFromJson(context, root);
}

void TrackTypeObject::DrawPreview(rct_drawpixelinfo* dpi, int32_t width, int32_t height) const
{
    /*
    auto screenCoords = ScreenCoordsXY{ width / 2, (height / 2) + 16 };

    auto colour0 = COLOUR_LIGHT_BLUE;
    auto colour1 = COLOUR_BORDEAUX_RED;
    auto tcolour0 = colour0;

    auto imageId = ImageId(BaseImageId);
    auto tImageId = ImageId(BaseImageId + 16).WithTransparancy(tcolour0);
    if (Flags & STATION_OBJECT_FLAGS::HAS_PRIMARY_COLOUR)
    {
        imageId = imageId.WithPrimary(colour0);
    }
    if (Flags & STATION_OBJECT_FLAGS::HAS_SECONDARY_COLOUR)
    {
        imageId = imageId.WithSecondary(colour1);
    }

    gfx_draw_sprite(dpi, imageId, screenCoords);
    if (Flags & STATION_OBJECT_FLAGS::IS_TRANSPARENT)
    {
        gfx_draw_sprite(dpi, tImageId, screenCoords);
    }

    gfx_draw_sprite(dpi, imageId.WithIndexOffset(4), screenCoords);
    if (Flags & STATION_OBJECT_FLAGS::IS_TRANSPARENT)
    {
        gfx_draw_sprite(dpi, tImageId.WithIndexOffset(4), screenCoords);
    }
    */
}
