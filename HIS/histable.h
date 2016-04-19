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
    //virtual bool amend() = 0;
protected:
    QString getNewID() const;
};

#endif // HISTABLE_H
