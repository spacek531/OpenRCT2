/*****************************************************************************
 * Copyright (c) 2014-2025 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../../ride/Vehicle.h"

#include "../Boundbox.h"
#include "../Paint.h"
#include "VehiclePaint.h"

#include <cstdint>

namespace OpenRCT2
{
    // 0x009927E6:
    static constexpr VehicleBoundBox _virginiaReelBoundbox[] = {
        { -11, -11, 1, 22, 22, 13 }, { -11, -11, 1, 22, 22, 13 }, { -11, -11, 1, 22, 22, 13 },
        { -11, -11, 1, 22, 22, 13 }, { -11, -11, 1, 22, 22, 13 }, { -11, -11, 1, 22, 22, 13 },
        { -11, -11, 1, 22, 22, 13 }, { -11, -11, 1, 22, 22, 13 }, { -11, -11, 1, 22, 22, 13 },
    };

    // Opposite Pitch values for reversed cars
    const VehiclePitch PitchInvertTable[] = {
        VehiclePitch::flat,

        VehiclePitch::down12,
        VehiclePitch::down25,
        VehiclePitch::down42,
        VehiclePitch::down60,

        VehiclePitch::up12,
        VehiclePitch::up25,
        VehiclePitch::up42,
        VehiclePitch::up60,

        VehiclePitch::down75,
        VehiclePitch::down90,
        VehiclePitch::down105,
        VehiclePitch::down120,
        VehiclePitch::down135,
        VehiclePitch::down150,
        VehiclePitch::down165,

        VehiclePitch::inverted,

        VehiclePitch::up75,
        VehiclePitch::up90,
        VehiclePitch::up105,
        VehiclePitch::up120,
        VehiclePitch::up135,
        VehiclePitch::up150,
        VehiclePitch::up165,

        VehiclePitch::corkscrewDownLeft0,
        VehiclePitch::corkscrewDownLeft1,
        VehiclePitch::corkscrewDownLeft2,
        VehiclePitch::corkscrewDownLeft3,
        VehiclePitch::corkscrewDownLeft4,

        VehiclePitch::corkscrewUpRight0,
        VehiclePitch::corkscrewUpRight1,
        VehiclePitch::corkscrewUpRight2,
        VehiclePitch::corkscrewUpRight3,
        VehiclePitch::corkscrewUpRight4,

        VehiclePitch::corkscrewDownRight0,
        VehiclePitch::corkscrewDownRight1,
        VehiclePitch::corkscrewDownRight2,
        VehiclePitch::corkscrewDownRight3,
        VehiclePitch::corkscrewDownRight4,

        VehiclePitch::corkscrewUpLeft0,
        VehiclePitch::corkscrewUpLeft1,
        VehiclePitch::corkscrewUpLeft2,
        VehiclePitch::corkscrewUpLeft3,
        VehiclePitch::corkscrewUpLeft4,

        VehiclePitch::flat, // helixes
        VehiclePitch::flat,
        VehiclePitch::flat,
        VehiclePitch::flat,
        VehiclePitch::flat,
        VehiclePitch::flat,

        VehiclePitch::down8,
        VehiclePitch::down16,
        VehiclePitch::down50,

        VehiclePitch::up8,
        VehiclePitch::up16,
        VehiclePitch::up50,

        VehiclePitch::up25,
        VehiclePitch::up42,
        VehiclePitch::up60,

        VehiclePitch::curvedLiftHillDown,
        VehiclePitch::curvedLiftHillUp,
    };
    static_assert(std::size(PitchInvertTable) == EnumValue(VehiclePitch::pitchCount));

    constexpr std::array<uint32_t, 9> kIndexDenominators = { 0, 256, 128, 86, 64, 52, 43, 37, 32 };
    using VehiclePaintOrder = std::array<uint8_t, 8>;

    constexpr std::array<VehiclePaintOrder, 8> kPeepPaintOrder = {
        VehiclePaintOrder{ 0 },
        VehiclePaintOrder{ 0, 1 },                   // TODO: determine this
        VehiclePaintOrder{ 0, 1, 2 },                // TODO: determine this
        VehiclePaintOrder{ 0, 1, 3, 2 },             // TODO: determine this
        VehiclePaintOrder{ 0, 1, 3, 4, 2 },          // TODO: determine this
        VehiclePaintOrder{ 0, 1, 2, 3, 4, 5 },       // TODO: determine this
        VehiclePaintOrder{ 0, 1, 2, 3, 4, 5, 6 },    // TODO: determine this
        VehiclePaintOrder{ 0, 1, 2, 3, 4, 5, 6, 7 }, // TODO: determine this
    };

    /**
     *
     *  rct2: 0x006D5B48
     */
    void VehicleVisualVirginiaReel(
        PaintSession& session, int32_t x, int32_t imageDirection, int32_t y, int32_t z, const Vehicle* vehicle,
        const CarEntry* carEntry)
    {
        assert(carEntry->spinningSymmetries != 0 && carEntry->spinningSymmetries <= 8);

        uint8_t numPeepsPerSeat = 1 + (carEntry->num_seats & kVehicleSeatPairFlag) != 0;

        assert((carEntry->num_seats & kVehicleSeatNumMask) % carEntry->spinningSymmetries == 0);
        assert(((carEntry->num_seats & kVehicleSeatNumMask) / carEntry->spinningSymmetries) % numPeepsPerSeat == 0);

        uint8_t relativeSpin = vehicle->spin_sprite + session.CurrentRotation * 64; // converts camera angle to 8-bit
        if (vehicle->HasFlag(VehicleFlags::SpinningIsLocked))
        {
            relativeSpin += vehicle->Orientation << 3; // convert 5-bit orientation to 8-bit
        }

        uint8_t reversed = vehicle->HasFlag(VehicleFlags::CarIsReversed)
            ^ (imageDirection >= OpenRCT2::Entity::Yaw::kBaseRotation / 2);
        reversed *= 128;
        relativeSpin += reversed;

        auto pitch = vehicle->pitch;
        auto roll = vehicle->roll;
        uint8_t vehicleOrientation = imageDirection << 3; // YawTo256
        // reversed = 128 if reversed, 0 if not.
        if (reversed)
        {
            pitch = PitchInvertTable[EnumValue(pitch)];
            // roll = RollInvertTable[EnumValue(roll)];
        }
        // mask off the msb so rotation is never more than 180 degrees
        vehicleOrientation = vehicleOrientation &= 0x7F;

        // determine how many spots to shift peeps around
        uint8_t rotationIndex = relativeSpin / kIndexDenominators[carEntry->spinningSymmetries];

        uint8_t rotationFrame = relativeSpin % kIndexDenominators[carEntry->spinningSymmetries];

        const uint8_t rotation = session.CurrentRotation;
        int32_t ecx = ((vehicle->spin_sprite / 8) + (rotation * 8)) & 31;
        int32_t baseImage_id = [&] {
            switch (vehicle->pitch)
            {
                case VehiclePitch::up12:
                    return (imageDirection & 24) + 8;
                case VehiclePitch::up25:
                    return (imageDirection & 24) + 40;
                case VehiclePitch::down12:
                    return ((imageDirection ^ 16) & 24) + 8;
                case VehiclePitch::down25:
                    return ((imageDirection ^ 16) & 24) + 40;
                default:
                    return 0;
            }
        }();
        baseImage_id += ecx & 7;
        const auto& vehicleBb = _virginiaReelBoundbox[baseImage_id >> 3];
        auto bb = BoundBoxXYZ{ { vehicleBb.offset_x, vehicleBb.offset_y, vehicleBb.offset_z + z },
                               { vehicleBb.length_x, vehicleBb.length_y, vehicleBb.length_z } };

        baseImage_id += carEntry->base_image_id;
        auto image_id = ImageId(baseImage_id, vehicle->colours.Body, vehicle->colours.Trim);
        if (vehicle->IsGhost())
        {
            image_id = ConstructionMarker.WithIndex(image_id.GetIndex());
        }
        PaintAddImageAsParent(session, image_id, { 0, 0, z }, bb);

        if (session.DPI.zoom_level < ZoomLevel{ 2 } && vehicle->num_peeps > 0 && !vehicle->IsGhost())
        {
            uint8_t riding_peep_sprites[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
            for (int32_t i = 0; i < vehicle->num_peeps; i++)
            {
                riding_peep_sprites[((ecx / 8) + i) & 3] = vehicle->peep_tshirt_colours[i];
            }
            int32_t draw_order[4] = { 0, 1, 3, 2 };
            for (auto i : draw_order)
            {
                if (riding_peep_sprites[i] != 0xFF)
                {
                    image_id = ImageId(baseImage_id + ((i + 1) * 72), riding_peep_sprites[i]);
                    PaintAddImageAsChild(session, image_id, { 0, 0, z }, bb);
                }
            }
        }

        assert(carEntry->effect_visual == 1);
    }
} // namespace OpenRCT2
