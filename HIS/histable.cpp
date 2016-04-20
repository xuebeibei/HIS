#include "histable.h"

HISTable::HISTable()
{
}

QString HISTable::getNewID() const
{
    QDate date = QDate::currentDate();
    QString strDate = QString::number(date.year()).right(2)
            +QString::number(date.month())
            +QString::number(date.day());

    QTime timer = QTime::currentTime();
    QString strCurrentTime = QString::number(timer.hour())
            +QString::number(timer.minute())
            +QString::number(timer.second());
    return strDate+strCurrentTime;
}

