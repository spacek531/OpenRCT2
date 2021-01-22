/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "Sprite.h"

#include "../Cheats.h"
#include "../Game.h"
#include "../OpenRCT2.h"
#include "../audio/audio.h"
#include "../core/Crypt.h"
#include "../core/Guard.hpp"
#include "../interface/Viewport.h"
#include "../localisation/Date.h"
#include "../localisation/Localisation.h"
#include "../scenario/Scenario.h"
#include "Fountain.h"

#include <algorithm>
#include <cmath>
#include <iterator>

static rct_sprite _spriteList[MAX_SPRITES];
static std::array<std::list<uint16_t>, EnumValue(EntityListId::Count)> gEntityLists;

static bool _spriteFlashingList[MAX_SPRITES];

uint16_t gSpriteSpatialIndex[SPATIAL_INDEX_SIZE];

const rct_string_id litterNames[12] = { STR_LITTER_VOMIT,
                                        STR_LITTER_VOMIT,
                                        STR_SHOP_ITEM_SINGULAR_EMPTY_CAN,
                                        STR_SHOP_ITEM_SINGULAR_RUBBISH,
                                        STR_SHOP_ITEM_SINGULAR_EMPTY_BURGER_BOX,
                                        STR_SHOP_ITEM_SINGULAR_EMPTY_CUP,
                                        STR_SHOP_ITEM_SINGULAR_EMPTY_BOX,
                                        STR_SHOP_ITEM_SINGULAR_EMPTY_BOTTLE,
                                        STR_SHOP_ITEM_SINGULAR_EMPTY_BOWL_RED,
                                        STR_SHOP_ITEM_SINGULAR_EMPTY_DRINK_CARTON,
                                        STR_SHOP_ITEM_SINGULAR_EMPTY_JUICE_CUP,
                                        STR_SHOP_ITEM_SINGULAR_EMPTY_BOWL_BLUE };

static size_t GetSpatialIndexOffset(int32_t x, int32_t y);

// Required for GetEntity to return a default
template<> bool SpriteBase::Is<SpriteBase>() const
{
    return true;
}

template<> bool SpriteBase::Is<Litter>() const
{
    return sprite_identifier == SpriteIdentifier::Litter;
}

template<> bool SpriteBase::Is<MiscEntity>() const
{
    return sprite_identifier == SpriteIdentifier::Misc;
}

template<> bool SpriteBase::Is<SteamParticle>() const
{
    auto* misc = As<MiscEntity>();
    return misc && misc->SubType == MiscEntityType::SteamParticle;
}

template<> bool SpriteBase::Is<ExplosionFlare>() const
{
    auto* misc = As<MiscEntity>();
    return misc && misc->SubType == MiscEntityType::ExplosionFlare;
}

template<> bool SpriteBase::Is<ExplosionCloud>() const
{
    auto* misc = As<MiscEntity>();
    return misc && misc->SubType == MiscEntityType::ExplosionCloud;
}

uint16_t GetEntityListCount(EntityListId list)
{
    return static_cast<uint16_t>(gEntityLists[static_cast<uint8_t>(list)].size());
}

std::string rct_sprite_checksum::ToString() const
{
    std::string result;

    result.reserve(raw.size() * 2);
    for (auto b : raw)
    {
        char buf[3];
        snprintf(buf, 3, "%02x", b);
        result.append(buf);
    }

    return result;
}

SpriteBase* try_get_sprite(size_t spriteIndex)
{
    return spriteIndex >= MAX_SPRITES ? nullptr : &_spriteList[spriteIndex].misc;
}

SpriteBase* get_sprite(size_t spriteIndex)
{
    if (spriteIndex == SPRITE_INDEX_NULL)
    {
        return nullptr;
    }
    openrct2_assert(spriteIndex < MAX_SPRITES, "Tried getting sprite %u", spriteIndex);
    return try_get_sprite(spriteIndex);
}

uint16_t sprite_get_first_in_quadrant(const CoordsXY& spritePos)
{
    return gSpriteSpatialIndex[GetSpatialIndexOffset(spritePos.x, spritePos.y)];
}

void SpriteBase::Invalidate()
{
    if (sprite_left == LOCATION_NULL)
        return;

    int32_t maxZoom = 0;
    switch (sprite_identifier)
    {
        case SpriteIdentifier::Vehicle:
        case SpriteIdentifier::Peep:
            maxZoom = 2;
            break;
        case SpriteIdentifier::Misc:
        {
            auto* misc = As<MiscEntity>();
            if (misc == nullptr)
            {
                return;
            }
            switch (misc->SubType)
            {
                case MiscEntityType::CrashedVehicleParticle:
                case MiscEntityType::JumpingFountainWater:
                case MiscEntityType::JumpingFountainSnow:
                    maxZoom = 0;
                    break;
                case MiscEntityType::Duck:
                    maxZoom = 1;
                    break;
                case MiscEntityType::SteamParticle:
                case MiscEntityType::MoneyEffect:
                case MiscEntityType::ExplosionCloud:
                case MiscEntityType::CrashSplash:
                case MiscEntityType::ExplosionFlare:
                case MiscEntityType::Balloon:
                    maxZoom = 2;
                    break;
                default:
                    break;
            }
        }
        break;
        case SpriteIdentifier::Litter:
            maxZoom = 0;
            break;
        default:
            break;
    }

    viewports_invalidate(sprite_left, sprite_top, sprite_right, sprite_bottom, maxZoom);
}
constexpr EntityListId EntityIdentifierToListId(const SpriteIdentifier type)
{
    EntityListId linkedListIndex = EntityListId::Free;
    switch (type)
    {
        case SpriteIdentifier::Vehicle:
            linkedListIndex = EntityListId::Vehicle;
            break;
        case SpriteIdentifier::Peep:
            linkedListIndex = EntityListId::Peep;
            break;
        case SpriteIdentifier::Misc:
            linkedListIndex = EntityListId::Misc;
            break;
        case SpriteIdentifier::Litter:
            linkedListIndex = EntityListId::Litter;
            break;
        default:
            break;
    }
    return linkedListIndex;
}

void RebuildEntityLists()
{
    for (auto& list : gEntityLists)
    {
        list.clear();
    }

    for (auto& ent : _spriteList)
    {
        // auto listId = EntityIdentifierToListId(ent.misc.sprite_identifier);
        gEntityLists[EnumValue(ent.misc.linked_list_index)].push_back(ent.misc.sprite_index);
    }
}

const std::list<uint16_t>& GetEntityList(const EntityListId id)
{
    return gEntityLists[EnumValue(id)];
}

/**
 *
 *  rct2: 0x0069EB13
 */
void reset_sprite_list()
{
    gSavedAge = 0;
    std::memset(static_cast<void*>(_spriteList), 0, sizeof(_spriteList));

    for (int32_t i = 0; i < MAX_SPRITES; ++i)
    {
        auto* spr = GetEntity(i);
        if (spr == nullptr)
        {
            continue;
        }

        spr->sprite_identifier = SpriteIdentifier::Null;
        spr->sprite_index = i;
        spr->linked_list_index = EntityListId::Free;

        _spriteFlashingList[i] = false;
    }

    RebuildEntityLists();
    reset_sprite_spatial_index();
}

/**
 *
 *  rct2: 0x0069EBE4
 * This function looks as though it sets some sort of order for sprites.
 * Sprites can share their position if this is the case.
 */
void reset_sprite_spatial_index()
{
    std::fill_n(gSpriteSpatialIndex, std::size(gSpriteSpatialIndex), SPRITE_INDEX_NULL);
    for (size_t i = 0; i < MAX_SPRITES; i++)
    {
        auto* spr = GetEntity(i);
        if (spr != nullptr && spr->sprite_identifier != SpriteIdentifier::Null)
        {
            size_t index = GetSpatialIndexOffset(spr->x, spr->y);
            uint32_t nextSpriteId = gSpriteSpatialIndex[index];
            gSpriteSpatialIndex[index] = spr->sprite_index;
            spr->next_in_quadrant = nextSpriteId;
        }
    }
}

static size_t GetSpatialIndexOffset(int32_t x, int32_t y)
{
    size_t index = SPATIAL_INDEX_LOCATION_NULL;
    if (x != LOCATION_NULL)
    {
        x = std::clamp(x, 0, 0xFFFF);
        y = std::clamp(y, 0, 0xFFFF);

        int16_t flooredX = floor2(x, 32);
        uint8_t tileY = y >> 5;
        index = (flooredX << 3) | tileY;
    }

    if (index >= sizeof(gSpriteSpatialIndex))
    {
        return SPATIAL_INDEX_LOCATION_NULL;
    }
    return index;
}

#ifndef DISABLE_NETWORK

rct_sprite_checksum sprite_checksum()
{
    using namespace Crypt;

    // TODO Remove statics, should be one of these per sprite manager / OpenRCT2 context.
    //      Alternatively, make a new class for this functionality.
    static std::unique_ptr<HashAlgorithm<20>> _spriteHashAlg;

    rct_sprite_checksum checksum;

    try
    {
        if (_spriteHashAlg == nullptr)
        {
            _spriteHashAlg = CreateSHA1();
        }

        _spriteHashAlg->Clear();
        for (size_t i = 0; i < MAX_SPRITES; i++)
        {
            // TODO create a way to copy only the specific type
            auto sprite = GetEntity(i);
            if (sprite != nullptr && sprite->sprite_identifier != SpriteIdentifier::Null
                && sprite->sprite_identifier != SpriteIdentifier::Misc)
            {
                // Upconvert it to rct_sprite so that the full size is copied.
                auto copy = *reinterpret_cast<rct_sprite*>(sprite);

                // Only required for rendering/invalidation, has no meaning to the game state.
                copy.misc.sprite_left = copy.misc.sprite_right = copy.misc.sprite_top = copy.misc.sprite_bottom = 0;
                copy.misc.sprite_width = copy.misc.sprite_height_negative = copy.misc.sprite_height_positive = 0;

                // Next in quadrant might be a misc sprite, set first non-misc sprite in quadrant.
                while (auto* nextSprite = GetEntity(copy.misc.next_in_quadrant))
                {
                    if (nextSprite->sprite_identifier == SpriteIdentifier::Misc)
                        copy.misc.next_in_quadrant = nextSprite->next_in_quadrant;
                    else
                        break;
                }

                if (copy.misc.Is<Peep>())
                {
                    // Name is pointer and will not be the same across clients
                    copy.peep.Name = {};

                    // We set this to 0 because as soon the client selects a guest the window will remove the
                    // invalidation flags causing the sprite checksum to be different than on server, the flag does not
                    // affect game state.
                    copy.peep.WindowInvalidateFlags = 0;
                }

                _spriteHashAlg->Update(&copy, sizeof(copy));
            }
        }

        checksum.raw = _spriteHashAlg->Finish();
    }
    catch (std::exception& e)
    {
        log_error("sprite_checksum failed: %s", e.what());
        throw;
    }

    return checksum;
}
#else

rct_sprite_checksum sprite_checksum()
{
    return rct_sprite_checksum{};
}

#endif // DISABLE_NETWORK

static void sprite_reset(SpriteBase* sprite)
{
    // Need to retain how the sprite is linked in lists
    auto llto = sprite->linked_list_index;
    uint16_t next_in_quadrant = sprite->next_in_quadrant;
    uint16_t sprite_index = sprite->sprite_index;
    _spriteFlashingList[sprite_index] = false;

    std::memset(sprite, 0, sizeof(rct_sprite));

    sprite->linked_list_index = llto;
    sprite->next_in_quadrant = next_in_quadrant;
    sprite->sprite_index = sprite_index;
    sprite->sprite_identifier = SpriteIdentifier::Null;
}

/**
 * Clears all the unused sprite memory to zero. Probably so that it can be compressed better when saving.
 *  rct2: 0x0069EBA4
 */
void sprite_clear_all_unused()
{
    for (auto sprite : EntityList(EntityListId::Free))
    {
        sprite_reset(sprite);
        sprite->linked_list_index = EntityListId::Free;

        // sprite->next_in_quadrant will only end up as zero owing to corruption
        // most likely due to previous builds not preserving it when resetting sprites
        // We reset it to SPRITE_INDEX_NULL to prevent cycles in the sprite lists
        if (sprite->next_in_quadrant == 0)
        {
            sprite->next_in_quadrant = SPRITE_INDEX_NULL;
        }
        _spriteFlashingList[sprite->sprite_index] = false;
    }
}

static void SpriteSpatialInsert(SpriteBase* sprite, const CoordsXY& newLoc);

static constexpr uint16_t MAX_MISC_SPRITES = 300;
static void AddToEntityList(const EntityListId linkedListIndex, SpriteBase* entity)
{
    auto& list = gEntityLists[EnumValue(linkedListIndex)];
    entity->linked_list_index = linkedListIndex;
    // Entity list must be in sprite_index order to prevent desync issues
    list.insert(std::lower_bound(std::begin(list), std::end(list), entity->sprite_index), entity->sprite_index);
}

static void RemoveFromEntityList(SpriteBase* entity)
{
    auto& list = gEntityLists[EnumValue(entity->linked_list_index)];
    auto ptr = std::lower_bound(std::begin(list), std::end(list), entity->sprite_index);
    if (ptr != std::end(list) && *ptr == entity->sprite_index)
    {
        list.erase(ptr);
    }
}

rct_sprite* create_sprite(SpriteIdentifier spriteIdentifier, EntityListId linkedListIndex)
{
    if (GetEntityListCount(EntityListId::Free) == 0)
    {
        // No free sprites.
        return nullptr;
    }

    if (linkedListIndex == EntityListId::Misc)
    {
        // Misc sprites are commonly used for effects, if there are less than MAX_MISC_SPRITES
        // free it will fail to keep slots for more relevant sprites.
        // Also there can't be more than MAX_MISC_SPRITES sprites in this list.
        uint16_t miscSlotsRemaining = MAX_MISC_SPRITES - GetEntityListCount(EntityListId::Misc);
        if (miscSlotsRemaining >= GetEntityListCount(EntityListId::Free))
        {
            return nullptr;
        }
    }

    auto* sprite = GetEntity(gEntityLists[static_cast<uint8_t>(EntityListId::Free)].front());
    if (sprite == nullptr)
    {
        return nullptr;
    }
    gEntityLists[static_cast<uint8_t>(EntityListId::Free)].pop_front();
    RemoveFromEntityList(sprite); // remove from Free list
    AddToEntityList(linkedListIndex, sprite);
    // Need to reset all sprite data, as the uninitialised values
    // may contain garbage and cause a desync later on.
    sprite_reset(sprite);

    sprite->x = LOCATION_NULL;
    sprite->y = LOCATION_NULL;
    sprite->z = 0;
    sprite->sprite_width = 0x10;
    sprite->sprite_height_negative = 0x14;
    sprite->sprite_height_positive = 0x8;
    sprite->flags = 0;
    sprite->sprite_left = LOCATION_NULL;

    SpriteSpatialInsert(sprite, { LOCATION_NULL, 0 });

    return reinterpret_cast<rct_sprite*>(sprite);
}

rct_sprite* create_sprite(SpriteIdentifier spriteIdentifier)
{
    EntityListId linkedListIndex = EntityListId::Free;
    switch (spriteIdentifier)
    {
        case SpriteIdentifier::Vehicle:
            linkedListIndex = EntityListId::Vehicle;
            break;
        case SpriteIdentifier::Peep:
            linkedListIndex = EntityListId::Peep;
            break;
        case SpriteIdentifier::Misc:
            linkedListIndex = EntityListId::Misc;
            break;
        case SpriteIdentifier::Litter:
            linkedListIndex = EntityListId::Litter;
            break;
        default:
            Guard::Assert(false, "Invalid sprite identifier: 0x%02X", spriteIdentifier);
            return nullptr;
    }
    return create_sprite(spriteIdentifier, linkedListIndex);
}

/**
 *
 *  rct2: 0x00673200
 */
void SteamParticle::Update()
{
    // Move up 1 z every 3 ticks (Starts after 4 ticks)
    Invalidate();
    time_to_move++;
    if (time_to_move >= 4)
    {
        time_to_move = 1;
        MoveTo({ x, y, z + 1 });
    }
    frame += 64;
    if (frame >= (56 * 64))
    {
        sprite_remove(this);
    }
}

/**
 *
 *  rct2: 0x0067363D
 */
void sprite_misc_explosion_cloud_create(const CoordsXYZ& cloudPos)
{
    MiscEntity* sprite = &create_sprite(SpriteIdentifier::Misc)->misc;
    if (sprite != nullptr)
    {
        sprite->sprite_width = 44;
        sprite->sprite_height_negative = 32;
        sprite->sprite_height_positive = 34;
        sprite->sprite_identifier = SpriteIdentifier::Misc;
        sprite->MoveTo(cloudPos + CoordsXYZ{ 0, 0, 4 });
        sprite->SubType = MiscEntityType::ExplosionCloud;
        sprite->frame = 0;
    }
}

/**
 *
 *  rct2: 0x00673385
 */
void ExplosionCloud::Update()
{
    Invalidate();
    frame += 128;
    if (frame >= (36 * 128))
    {
        sprite_remove(this);
    }
}

/**
 *
 *  rct2: 0x0067366B
 */
void sprite_misc_explosion_flare_create(const CoordsXYZ& flarePos)
{
    MiscEntity* sprite = &create_sprite(SpriteIdentifier::Misc)->misc;
    if (sprite != nullptr)
    {
        sprite->sprite_width = 25;
        sprite->sprite_height_negative = 85;
        sprite->sprite_height_positive = 8;
        sprite->sprite_identifier = SpriteIdentifier::Misc;
        sprite->MoveTo(flarePos + CoordsXYZ{ 0, 0, 4 });
        sprite->SubType = MiscEntityType::ExplosionFlare;
        sprite->frame = 0;
    }
}

/**
 *
 *  rct2: 0x006733B4
 */
void ExplosionFlare::Update()
{
    Invalidate();
    frame += 64;
    if (frame >= (124 * 64))
    {
        sprite_remove(this);
    }
}

template<typename T> void MiscUpdateAllType()
{
    for (auto misc : EntityList<T>(EntityListId::Misc))
    {
        misc->Update();
    }
}

template<typename... T> void MiscUpdateAllTypes()
{
    (MiscUpdateAllType<T>(), ...);
}

/**
 *
 *  rct2: 0x00672AA4
 */
void sprite_misc_update_all()
{
    MiscUpdateAllTypes<
        SteamParticle, MoneyEffect, VehicleCrashParticle, ExplosionCloud, CrashSplashParticle, ExplosionFlare, JumpingFountain,
        Balloon, Duck>();
}

// Performs a search to ensure that insert keeps next_in_quadrant in sprite_index order
static void SpriteSpatialInsert(SpriteBase* sprite, const CoordsXY& newLoc)
{
    size_t newIndex = GetSpatialIndexOffset(newLoc.x, newLoc.y);

    auto* next = &gSpriteSpatialIndex[newIndex];
    while (sprite->sprite_index < *next && *next != SPRITE_INDEX_NULL)
    {
        auto sprite2 = GetEntity(*next);
        next = &sprite2->next_in_quadrant;
    }

    sprite->next_in_quadrant = *next;
    *next = sprite->sprite_index;
}

static void SpriteSpatialRemove(SpriteBase* sprite)
{
    size_t currentIndex = GetSpatialIndexOffset(sprite->x, sprite->y);
    auto* index = &gSpriteSpatialIndex[currentIndex];

    // This indicates that the spatial index data is incorrect.
    if (*index == SPRITE_INDEX_NULL)
    {
        log_warning("Bad sprite spatial index. Rebuilding the spatial index...");
        reset_sprite_spatial_index();
    }

    auto* sprite2 = GetEntity(*index);
    while (sprite != sprite2)
    {
        index = &sprite2->next_in_quadrant;
        if (*index == SPRITE_INDEX_NULL)
        {
            break;
        }
        sprite2 = GetEntity(*index);
    }
    *index = sprite->next_in_quadrant;
}

static void SpriteSpatialMove(SpriteBase* sprite, const CoordsXY& newLoc)
{
    size_t newIndex = GetSpatialIndexOffset(newLoc.x, newLoc.y);
    size_t currentIndex = GetSpatialIndexOffset(sprite->x, sprite->y);
    if (newIndex == currentIndex)
        return;

    SpriteSpatialRemove(sprite);
    SpriteSpatialInsert(sprite, newLoc);
}

/**
 * Moves a sprite to a new location, invalidates the current position if valid
 * and also the new position.
 *
 *  rct2: 0x0069E9D3
 *
 * @param x (ax)
 * @param y (cx)
 * @param z (dx)
 * @param sprite (esi)
 */
void SpriteBase::MoveTo(const CoordsXYZ& newLocation)
{
    if (x != LOCATION_NULL)
    {
        // Invalidate old position.
        Invalidate();
    }

    auto loc = newLocation;
    if (!map_is_location_valid(loc))
    {
        loc.x = LOCATION_NULL;
    }

    SpriteSpatialMove(this, loc);

    if (loc.x == LOCATION_NULL)
    {
        sprite_left = LOCATION_NULL;
        x = loc.x;
        y = loc.y;
        z = loc.z;
    }
    else
    {
        sprite_set_coordinates(loc, this);
        Invalidate(); // Invalidate new position.
    }
}

void sprite_set_coordinates(const CoordsXYZ& spritePos, SpriteBase* sprite)
{
    auto screenCoords = translate_3d_to_2d_with_z(get_current_rotation(), spritePos);

    sprite->sprite_left = screenCoords.x - sprite->sprite_width;
    sprite->sprite_right = screenCoords.x + sprite->sprite_width;
    sprite->sprite_top = screenCoords.y - sprite->sprite_height_negative;
    sprite->sprite_bottom = screenCoords.y + sprite->sprite_height_positive;
    sprite->x = spritePos.x;
    sprite->y = spritePos.y;
    sprite->z = spritePos.z;
}

/**
 *
 *  rct2: 0x0069EDB6
 */
void sprite_remove(SpriteBase* sprite)
{
    auto peep = sprite->As<Peep>();
    if (peep != nullptr)
    {
        peep->SetName({});
    }

    EntityTweener::Get().RemoveEntity(sprite);
    RemoveFromEntityList(sprite); // remove from existing list
    AddToEntityList(EntityListId::Free, sprite);

    SpriteSpatialRemove(sprite);
    sprite_reset(sprite);
}

static bool litter_can_be_at(const CoordsXYZ& mapPos)
{
    TileElement* tileElement;

    if (!map_is_location_owned(mapPos))
        return false;

    tileElement = map_get_first_element_at(mapPos);
    if (tileElement == nullptr)
        return false;
    do
    {
        if (tileElement->GetType() != TILE_ELEMENT_TYPE_PATH)
            continue;

        int32_t pathZ = tileElement->GetBaseZ();
        if (pathZ < mapPos.z || pathZ >= mapPos.z + 32)
            continue;

        return !tile_element_is_underground(tileElement);
    } while (!(tileElement++)->IsLastForTile());
    return false;
}

/**
 *
 *  rct2: 0x0067375D
 */
void litter_create(const CoordsXYZD& litterPos, LitterType type)
{
    if (gCheatsDisableLittering)
        return;

    auto offsetLitterPos = litterPos
        + CoordsXY{ CoordsDirectionDelta[litterPos.direction >> 3].x / 8,
                    CoordsDirectionDelta[litterPos.direction >> 3].y / 8 };

    if (!litter_can_be_at(offsetLitterPos))
        return;

    if (GetEntityListCount(EntityListId::Litter) >= 500)
    {
        Litter* newestLitter = nullptr;
        uint32_t newestLitterCreationTick = 0;
        for (auto litter : EntityList<Litter>(EntityListId::Litter))
        {
            if (newestLitterCreationTick <= litter->creationTick)
            {
                newestLitterCreationTick = litter->creationTick;
                newestLitter = litter;
            }
        }

        if (newestLitter != nullptr)
        {
            newestLitter->Invalidate();
            sprite_remove(newestLitter);
        }
    }

    Litter* litter = reinterpret_cast<Litter*>(create_sprite(SpriteIdentifier::Litter));
    if (litter == nullptr)
        return;

    litter->sprite_direction = offsetLitterPos.direction;
    litter->sprite_width = 6;
    litter->sprite_height_negative = 6;
    litter->sprite_height_positive = 3;
    litter->sprite_identifier = SpriteIdentifier::Litter;
    litter->SubType = type;
    litter->MoveTo(offsetLitterPos);
    litter->creationTick = gScenarioTicks;
}

/**
 *
 *  rct2: 0x006738E1
 */
void litter_remove_at(const CoordsXYZ& litterPos)
{
    for (auto litter : EntityTileList<Litter>(litterPos))
    {
        if (abs(litter->z - litterPos.z) <= 16)
        {
            if (abs(litter->x - litterPos.x) <= 8 && abs(litter->y - litterPos.y) <= 8)
            {
                litter->Invalidate();
                sprite_remove(litter);
            }
        }
    }
}

/**
 * Loops through all sprites, finds floating objects and removes them.
 * Returns the amount of removed objects as feedback.
 */
uint16_t remove_floating_sprites()
{
    uint16_t removed = 0;
    for (auto* balloon : EntityList<Balloon>(EntityListId::Misc))
    {
        sprite_remove(balloon);
        removed++;
    }
    for (auto* duck : EntityList<Duck>(EntityListId::Misc))
    {
        if (duck->IsFlying())
        {
            sprite_remove(duck);
            removed++;
        }
    }
    for (auto* money : EntityList<MoneyEffect>(EntityListId::Misc))
    {
        sprite_remove(money);
        removed++;
    }
    return removed;
}

void EntityTweener::PopulateEntities(EntityListId id)
{
    for (auto ent : EntityList(id))
    {
        Entities.push_back(ent);
        PrePos.emplace_back(ent->x, ent->y, ent->z);
    }
}

void EntityTweener::PreTick()
{
    Restore();
    Reset();
    PopulateEntities(EntityListId::Peep);
    PopulateEntities(EntityListId::Vehicle);
    PopulateEntities(EntityListId::TrainHead);
}

void EntityTweener::PostTick()
{
    for (auto* ent : Entities)
    {
        if (ent == nullptr)
        {
            // Sprite was removed, add a dummy position to keep the index aligned.
            PostPos.emplace_back(0, 0, 0);
        }
        else
        {
            PostPos.emplace_back(ent->x, ent->y, ent->z);
        }
    }
}

void EntityTweener::RemoveEntity(SpriteBase* entity)
{
    if (entity->sprite_identifier != SpriteIdentifier::Peep && entity->sprite_identifier != SpriteIdentifier::Vehicle)
    {
        // Only peeps and vehicles are tweened, bail if type is incorrect.
        return;
    }

    auto it = std::find(Entities.begin(), Entities.end(), entity);
    if (it != Entities.end())
        *it = nullptr;
}

void EntityTweener::Tween(float alpha)
{
    const float inv = (1.0f - alpha);
    for (size_t i = 0; i < Entities.size(); ++i)
    {
        auto* ent = Entities[i];
        if (ent == nullptr)
            continue;

        auto& posA = PrePos[i];
        auto& posB = PostPos[i];

        if (posA == posB)
            continue;

        sprite_set_coordinates(
            { static_cast<int32_t>(std::round(posB.x * alpha + posA.x * inv)),
              static_cast<int32_t>(std::round(posB.y * alpha + posA.y * inv)),
              static_cast<int32_t>(std::round(posB.z * alpha + posA.z * inv)) },
            ent);
        ent->Invalidate();
    }
}

void EntityTweener::Restore()
{
    for (size_t i = 0; i < Entities.size(); ++i)
    {
        auto* ent = Entities[i];
        if (ent == nullptr)
            continue;

        sprite_set_coordinates(PostPos[i], ent);
        ent->Invalidate();
    }
}

void EntityTweener::Reset()
{
    Entities.clear();
    PrePos.clear();
    PostPos.clear();
}

static EntityTweener tweener;

EntityTweener& EntityTweener::Get()
{
    return tweener;
}

void sprite_set_flashing(SpriteBase* sprite, bool flashing)
{
    assert(sprite->sprite_index < MAX_SPRITES);
    _spriteFlashingList[sprite->sprite_index] = flashing;
}

bool sprite_get_flashing(SpriteBase* sprite)
{
    assert(sprite->sprite_index < MAX_SPRITES);
    return _spriteFlashingList[sprite->sprite_index];
}
