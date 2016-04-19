#ifndef HISTABLE_H
#define HISTABLE_H
#include "stdafx.h"
#include "winSet.h"
class HISTable
{
public:
    HISTable();
    virtual bool Read(QString strId) = 0;
    virtual bool Save() = 0;
    virtual bool Find(QString strId) = 0;
    virtual bool Delete() = 0;

    QString getID();
    QString getMaker();

    void setID(QString str_ID);
    void setMaker(QString str_Maker);
protected:
    QString getNewID() const;

protected:
    QString m_strID;
    QString m_strMaker;
};

#endif // HISTABLE_H
