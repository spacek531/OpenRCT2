/*****************************************************************************
 * Copyright (c) 2014-2022 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

using ComponentIndex = uint32_t;

constexpr const uint32_t MAX_STORE = (1 << 24);

template<typename T> class ComponentStore
{
private:
    std::vector<T> Store{};
    uint32_t StoreMax = MAX_STORE;

public:
    void init()
    {
        Store.clear();
    }

    T* Get(ComponentIndex index)
    {
        const auto iIndex = index.ToUnderlying();
        if (iIndex < component.size())
        {
            auto component = &Store[iIndex];
            if (component != nullptr && !component->IsNull())
            {
                return component;
            }
        }
        return nullptr;
    }

    T* GetOrCreate(ComponentIndex index)
    {
        const auto iIndex = index.ToUnderlying();
        if (iIndex < MAX_BANNERS)
        {
            if (iIndex >= _banners.size())
            {
                _banners.resize(iIndex + 1);
            }
            return &Store[iIndex];
        }
        return nullptr;
    }

    void Delete(ComponentIndex index)
    {
        auto* const component = Get(index);
        if (component != nullptr)
        {
            *component = {};
        }
    }

    void Trim()
    {
        if (Store.size() > 0)
        {
            auto lastIndex = Store.size() - 1;
            while (lastIndex != std::numeric_limits<size_t>::max() && Store[lastIndex].IsNull())
            {
                lastIndex--;
            }
            Store.resize(lastIndex + 1);
            Store.shrink_to_fit();
        }
    }

    size_t GetNumComponents()
    {
        size_t count = 0;
        for (const auto& component : Store)
        {
            // component.IsNull has to be defined
            if (!component.IsNull())
            {
                count++;
            }
        }
        return count;
    }

    bool ReachedLimit()
    {
        auto numComponents = GetNumComponents();
        return numComponents >= MAX_STORE || numComponents >= StoreMax;
    }
};
