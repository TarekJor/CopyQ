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

#include "persistentitemselection.h"

#include <QCoreApplication>
#include <QPersistentModelIndex>
#include <QPointer>
#include <QString>
#include <QThread>

struct PersistentItemSelection::PersistentItemSelectionPrivate
{
    QString tabName;
    QVariantMap data;
    QPointer<const QObject> widget;
};

PersistentItemSelection::PersistentItemSelection(const QString &tabName)
    : m_d(std::make_shared<PersistentItemSelectionPrivate>())
{
    m_d->tabName = tabName;
}

PersistentItemSelection::PersistentItemSelection(const QString &tabName,
        const QVariantMap &data,
        const QObject *widget)
    : m_d(std::make_shared<PersistentItemSelectionPrivate>())
{
    m_d->tabName = tabName;
    m_d->data = data;
    m_d->widget = widget;
}

QVariantMap PersistentItemSelection::data() const
{
    return m_d->data;
}

QString PersistentItemSelection::tabName() const
{
    return m_d->tabName;
}

const QObject *PersistentItemSelection::widget() const
{
    Q_ASSERT(QThread::currentThread() == qApp->thread());
    return m_d->widget.data();
}
