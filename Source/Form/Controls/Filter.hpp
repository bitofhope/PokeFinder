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

#ifndef FILTER_HPP
#define FILTER_HPP

#include <Core/Global.hpp>
#include <QWidget>

enum class Controls : u16;

namespace Ui
{
    class Filter;
}

/**
 * @brief Provides settings to filter results on
 */
class Filter : public QWidget
{
    Q_OBJECT
signals:
    void showStatsChanged(bool);

public:
    /**
     * @brief Construct a new Filter object
     *
     * @param parent Parent widget, which takes memory ownership
     */
    Filter(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Filter object
     */
    ~Filter() override;

    /**
     * @brief Disables specified controls
     *
     * @param control Controls value
     */
    void disableControls(Controls control);

    /**
     * @brief Enables specified controls
     *
     * @param control Controls value
     */
    void enableControls(Controls control);

    /**
     * @brief Enables showing the hidden ability
     */
    void enableHiddenAbility();

    /**
     * @brief Gets ability to filter by
     *
     * @return Ability value
     */
    u8 getAbility() const;

    /**
     * @brief Gets delay to add
     *
     * @return Delay value
     */
    u32 getDelay() const;

    /**
     * @brief Checks if filters should be ignored
     *
     * @return true Filters are disabled
     * @return false Filters are not disabled
     */
    bool getDisableFilters() const;

    /**
     * @brief Gets encounter slots to filter by
     *
     * @return Vector of encounter slots
     */
    std::vector<bool> getEncounterSlots();

    /**
     * @brief Gets gender to filter by
     *
     * @return Gender value
     */
    u8 getGender() const;

    /**
     * @brief Gets hidden powers to filter by
     *
     * @return Vector of hidden powers
     */
    std::array<bool, 16> getHiddenPowers();

    /**
     * @brief Gets upper bound IVs to filter by
     *
     * @return Array of maximum IVs
     */
    std::array<u8, 6> getMaxIVs() const;

    /**
     * @brief Gets lower bound IVs to filter by
     *
     * @return Array of minimum IVs
     */
    std::array<u8, 6> getMinIVs() const;

    /**
     * @brief Get natures to filter by
     *
     * @return Vector of natures
     */
    std::array<bool, 25> getNatures();

    /**
     * @brief Gets shiny status to filter by
     *
     * @return Shiny value
     */
    u8 getShiny() const;

    /**
     * @brief Unchecks all encounter slots
     */
    void resetEncounterSlots() const;

    /**
     * @brief Sets encounter slots that are available
     *
     * @param encounterSlots Vector of encounter slots
     */
    void setEncounterSlots(const std::vector<std::string> &encounterSlots) const;

    /**
     * @brief Sets encounter slots that are checked and not checked
     *
     * @param encounterSlots Vector of encounter slots
     */
    void toggleEncounterSlots(const std::vector<bool> &encounterSlots) const;

    /**
     * @brief Gets if delay should be added
     *
     * @return true Delay is enabled
     * @return false Delay is not enabled
     */
    bool useDelay() const;

private:
    Ui::Filter *ui;
};

#endif // FILTER_HPP
