#include "histable.h"

HISTable::HISTable()
{
    m_strID = strNull;
    m_strMaker = strNull;
    //m_tableModel = new QSqlTableModel;
}

QString HISTable::getNewID() const
{
    QDate date = QDate::currentDate();
    QString strDate = QString::number(date.year())
            +QString::number(date.month())
            +QString::number(date.day());

    QTime timer = QTime::currentTime();
    QString strCurrentTime = QString::number(timer.hour())
            +QString::number(timer.minute())
            +QString::number(timer.second());
    return strDate+strCurrentTime;
}

QString HISTable::getID()
{
    if(m_strID.isEmpty())
        m_strID = getNewID();
    return m_strID;
}

QString HISTable::getMaker()
{
    return m_strMaker;
}

//QSqlTableModel* HISTable::getTableModel()
//{
//    return m_tableModel;
//}

void HISTable::setID(QString str_ID)
{
    this->m_strID = str_ID;
}

void HISTable::setMaker(QString str_Maker)
{
    this->m_strMaker = str_Maker;
}

//void HISTable::setTableModel(QSqlTableModel *model)
//{
//    this->m_tableModel = model;
//}
