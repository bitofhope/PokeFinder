/*
 * This file is part of PokéFinder
 * Copyright (C) 2017-2019 by Admiral_Fish, bumba, and EzPzStreamz
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

#include "IVSearcher3.hpp"

IVSearcher3::IVSearcher3(const Searcher3 &searcher, const QVector<u8> &min, const QVector<u8> &max)
{
    this->searcher = searcher;
    this->min = min;
    this->max = max;
    cancel = false;
    progress = 0;

    connect(this, &IVSearcher3::finished, this, &IVSearcher3::deleteLater);
}

void IVSearcher3::run()
{
    for (u8 a = min.at(0); a <= max.at(0); a++)
    {
        for (u8 b = min.at(1); b <= max.at(1); b++)
        {
            for (u8 c = min.at(2); c <= max.at(2); c++)
            {
                for (u8 d = min.at(3); d <= max.at(3); d++)
                {
                    for (u8 e = min.at(4); e <= max.at(4); e++)
                    {
                        for (u8 f = min.at(5); f <= max.at(5); f++)
                        {
                            if (cancel)
                            {
                                return;
                            }

                            auto frames = searcher.search(a, b, c, d, e, f);
                            progress++;

                            QMutexLocker locker(&mutex);
                            results.append(frames);
                        }
                    }
                }
            }
        }
    }
}

int IVSearcher3::currentProgress() const
{
    return progress;
}

QVector<Frame3> IVSearcher3::getResults()
{
    QMutexLocker locker(&mutex);
    auto data(results);
    results.clear();
    return data;
}

void IVSearcher3::cancelSearch()
{
    cancel = true;
}
