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

#ifndef EVENTMODEL8_HPP
#define EVENTMODEL8_HPP

#include <Core/Parents/States/State.hpp>
#include <Forms/Models/TableModel.hpp>

class EventModel8 : public TableModel<State>
{
    Q_OBJECT
public:
    explicit EventModel8(QObject *parent);
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    QStringList header = { tr("Advances"), tr("PID"), tr("Shiny"), tr("Nature"), tr("Ability"), tr("HP"),
                           tr("Atk"),      tr("Def"), tr("SpA"),   tr("SpD"),    tr("Spe"),     tr("Gender") };
};

#endif // EVENTMODEL8_HPP
