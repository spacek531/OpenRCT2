/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../Cheats.h"
#include "../Context.h"
#include "../Game.h"
#include "../Input.h"
#include "../audio/audio.h"
#include "../interface/Viewport.h"
#include "../network/network.h"
#include "../paint/VirtualFloor.h"
#include "../peep/Staff.h"
#include "../world/Banner.h"
#include "../world/Scenery.h"
#include "../world/Sprite.h"
#include "Intent.h"

#include <iterator>
#include <tuple>

bool gDisableErrorWindowSound = false;

/**
 *
 *  rct2: 0x0066DB3D
 */
bool scenery_tool_is_active()
{
    int32_t toolWindowClassification = gCurrentToolWidget.window_classification;
    rct_widgetindex toolWidgetIndex = gCurrentToolWidget.widget_index;
    if (input_test_flag(INPUT_FLAG_TOOL_ACTIVE))
        if (toolWindowClassification == WC_TOP_TOOLBAR && toolWidgetIndex == WC_TOP_TOOLBAR__WIDX_SCENERY)
            return true;

    return false;
}

void init_scenery()
{
    auto intent = Intent(INTENT_ACTION_INIT_SCENERY);
    context_broadcast_intent(&intent);
}

void scenery_set_default_placement_configuration()
{
    auto intent = Intent(INTENT_ACTION_SET_DEFAULT_SCENERY_CONFIG);
    context_broadcast_intent(&intent);
}
