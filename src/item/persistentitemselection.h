/*
    Copyright (c) 2017, Lukas Holecek <hluk@email.cz>

    This file is part of CopyQ.

    CopyQ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CopyQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CopyQ.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PERSISTENTITEMSELECTION_H
#define PERSISTENTITEMSELECTION_H

#include <QMetaType>
#include <QVariantMap>

#include <memory>

class QObject;
class QPersistentModelIndex;
class QModelIndex;
class QString;

class PersistentItemSelection final
{
public:
    PersistentItemSelection() = default;

    explicit PersistentItemSelection(const QString &tabName);

    PersistentItemSelection(
            const QString &tabName, const QVariantMap &data, const QObject *widget);

    QVariantMap data() const;

    QString tabName() const;

    const QObject *widget() const;

private:
    struct PersistentItemSelectionPrivate;
    std::shared_ptr<PersistentItemSelectionPrivate> m_d;
};

Q_DECLARE_METATYPE(PersistentItemSelection)

#endif // PERSISTENTITEMSELECTION_H
