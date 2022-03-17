/*
 * This file is part of PokéFinder
 * Copyright (C) 2017-2022 by Admiral_Fish, bumba, and EzPzStreamz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef WILDGENERATOR3_HPP
#define WILDGENERATOR3_HPP

#include <Core/Enum/Game.hpp>
#include <Core/Parents/Generators/WildGenerator.hpp>

class EncounterArea3;
class WildState3;

class WildGenerator3 : public WildGenerator
{
public:
    WildGenerator3(u32 initialAdvances, u32 maxAdvances, u16 tid, u16 sid, u8 genderRatio, Method method, const StateFilter &filter, Game version);
    std::vector<WildState3> generate(u32 seed, const EncounterArea3 &encounterArea) const;
private:
    Game version;                                  // A   A   A   A   A   A   A   A   A   A   A   ?
    const std::array<u8, 12> unownLetterSlots[7] = {{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 27 },
                                                   // C   C   C   D   D   D   H   H   H   U   U   O
                                                    { 2,  2,  2,  3,  3,  3,  7,  7,  7, 20, 20, 14 },
                                                   // N   N   N   N   S   S   S   S   I   I   E   E
                                                    { 13, 13, 13, 13, 18, 18, 18, 18,  8,  8,  4, 4 },
                                                   // P   P   L   L   J   J   R   R   R   Q   Q   Q
                                                    { 15, 15, 11, 11,  9,  9, 17, 17, 17, 16, 16, 16 },
                                                   // Y   Y   T   T   G   G   G   F   F   F   K   K
                                                    { 24, 24, 19, 19,  6,  6,  6,  5,  5,  5, 10, 10 },
                                                   // V   V   V   W   W   W   X   X   M   M   B   B
                                                    { 21, 21, 21, 22, 22, 22, 23, 23, 12, 12,  1, 1 },
                                                   // Z   Z   Z   Z   Z   Z   Z   Z   Z   Z   Z   !
                                                    { 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26 }};
};

#endif // WILDGENERATOR3_HPP
