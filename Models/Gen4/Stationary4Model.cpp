/*
 * This file is part of PokéFinder
 * Copyright (C) 2017 by Admiral_Fish, bumba, and EzPzStreamz
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

#include "Stationary4Model.hpp"

Stationary4Model::Stationary4Model(QObject *parent, Method method) : QAbstractTableModel(parent)
{
    this->method = method;
}

void Stationary4Model::setModel(vector<Frame4> frames)
{
    if (frames.empty())
        return;
    int i = rowCount();
    emit beginInsertRows(QModelIndex(), i, i + frames.size() - 1);
    model.insert(model.end(), frames.begin(), frames.end());
    emit endInsertRows();
}

void Stationary4Model::clear()
{
    if (model.empty())
        return;
    emit beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
    model.clear();
    model.shrink_to_fit();
    emit endRemoveRows();
}

void Stationary4Model::setMethod(Method method)
{
    this->method = method;
    emit headerDataChanged(Qt::Horizontal, 0, columnCount());
}

int Stationary4Model::rowCount(const QModelIndex &parent) const
{
    (void) parent;
    return (int)model.size();
}

int Stationary4Model::columnCount(const QModelIndex &parent) const
{
    (void) parent;
    switch (method)
    {
        case Method1:
        case MethodJ:
            return 16;
        case MethodK:
            return 17;
    }
    return 0;
}

QVariant Stationary4Model::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        int row = index.row();
        int column = index.column();
        Frame4 frame = model[row];
        switch (method)
        {
            case Method1:
                switch (column)
                {
                    case 0:
                        return frame.frame;
                    case 1:
                        return "Elm"; // TODO
                    case 2:
                        return "Chatot"; // TODO
                    case 3:
                        return QString::number(frame.pid, 16).toUpper().rightJustified(8, '0');
                    case 4:
                        return frame.getShiny();
                    case 5:
                        return frame.getNature();
                    case 6:
                        return frame.ability;
                    case 7:
                        return frame.ivs[0];
                    case 8:
                        return frame.ivs[1];
                    case 9:
                        return frame.ivs[2];
                    case 10:
                        return frame.ivs[3];
                    case 11:
                        return frame.ivs[4];
                    case 12:
                        return frame.ivs[5];
                    case 13:
                        return frame.getPower();
                    case 14:
                        return frame.power;
                    case 15:
                        return frame.getGender();
                }
            case MethodJ:
                switch (column)
                {
                    case 0:
                        return frame.frame;
                    case 1:
                        return frame.occidentary;
                    case 2:
                        return "Chatot"; // TODO
                    case 3:
                        return QString::number(frame.pid, 16).toUpper().rightJustified(8, '0');
                    case 4:
                        return frame.getShiny();
                    case 5:
                        return frame.getNature();
                    case 6:
                        return frame.ability;
                    case 7:
                        return frame.ivs[0];
                    case 8:
                        return frame.ivs[1];
                    case 9:
                        return frame.ivs[2];
                    case 10:
                        return frame.ivs[3];
                    case 11:
                        return frame.ivs[4];
                    case 12:
                        return frame.ivs[5];
                    case 13:
                        return frame.getPower();
                    case 14:
                        return frame.power;
                    case 15:
                        return frame.getGender();
                }
            case MethodK:
                switch (column)
                {
                    case 0:
                        return frame.frame;
                    case 1:
                        return frame.occidentary; // TODO
                    case 2:
                        return "Elm"; // TODO
                    case 3:
                        return "Chatot"; // TODO
                    case 4:
                        return QString::number(frame.pid, 16).toUpper().rightJustified(8, '0');
                    case 5:
                        return frame.getShiny();
                    case 6:
                        return frame.getNature();
                    case 7:
                        return frame.ability;
                    case 8:
                        return frame.ivs[0];
                    case 9:
                        return frame.ivs[1];
                    case 10:
                        return frame.ivs[2];
                    case 11:
                        return frame.ivs[3];
                    case 12:
                        return frame.ivs[4];
                    case 13:
                        return frame.ivs[5];
                    case 14:
                        return frame.getPower();
                    case 15:
                        return frame.power;
                    case 16:
                        return frame.getGender();
                }
        }
    }
    return QVariant();
}

QVariant Stationary4Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (method)
            {
                case Method1:
                    switch (section)
                    {
                        case 0:
                            return tr("Frame");
                        case 1:
                            return tr("Elm");
                        case 2:
                            return tr("Chatot Pitch");
                        case 3:
                            return tr("PID");
                        case 4:
                            return "!!!";
                        case 5:
                            return tr("Nature");
                        case 6:
                            return tr("Ability");
                        case 7:
                            return tr("HP");
                        case 8:
                            return tr("Atk");
                        case 9:
                            return tr("Def");
                        case 10:
                            return tr("SpA");
                        case 11:
                            return tr("SpD");
                        case 12:
                            return tr("Spe");
                        case 13:
                            return tr("Hidden");
                        case 14:
                            return tr("Power");
                        case 15:
                            return tr("Gender");
                    }
                case MethodJ:
                    switch (section)
                    {
                        case 0:
                            return tr("Frame");
                        case 1:
                            return tr("Occidentary");
                        case 2:
                            return tr("Chatot Pitch");
                        case 3:
                            return tr("PID");
                        case 4:
                            return "!!!";
                        case 5:
                            return tr("Nature");
                        case 6:
                            return tr("Ability");
                        case 7:
                            return tr("HP");
                        case 8:
                            return tr("Atk");
                        case 9:
                            return tr("Def");
                        case 10:
                            return tr("SpA");
                        case 11:
                            return tr("SpD");
                        case 12:
                            return tr("Spe");
                        case 13:
                            return tr("Hidden");
                        case 14:
                            return tr("Power");
                        case 15:
                            return tr("Gender");
                    }
                case MethodK:
                    switch (section)
                    {
                        case 0:
                            return tr("Frame");
                        case 1:
                            return tr("Occidentary");
                        case 2:
                            return tr("Elm");
                        case 3:
                            return tr("Chatot Pitch");
                        case 4:
                            return tr("PID");
                        case 5:
                            return "!!!";
                        case 6:
                            return tr("Nature");
                        case 7:
                            return tr("Ability");
                        case 8:
                            return tr("HP");
                        case 9:
                            return tr("Atk");
                        case 10:
                            return tr("Def");
                        case 11:
                            return tr("SpA");
                        case 12:
                            return tr("SpD");
                        case 13:
                            return tr("Spe");
                        case 14:
                            return tr("Hidden");
                        case 15:
                            return tr("Power");
                        case 16:
                            return tr("Gender");
                    }
            }
        }
    }
    return QVariant();
}
