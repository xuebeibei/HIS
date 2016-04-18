#ifndef HISTABLE_H
#define HISTABLE_H
#include "stdafx.h"
#include "winSet.h"
class HISTable
{
public:
    HISTable();
    virtual bool Read() = 0;
    virtual bool Save() = 0;
    virtual bool Delete() = 0;

    QString getID();
    QString getMaker();
    //QSqlTableModel* getTableModel();

    void setID(QString str_ID);
    void setMaker(QString str_Maker);
    //void setTableModel(QSqlTableModel *model);
protected:
    QString getNewID() const;

protected:
    QString m_strID;
    QString m_strMaker;
    //QSqlTableModel *m_tableModel;
};

#endif // HISTABLE_H
