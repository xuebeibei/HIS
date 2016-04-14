#ifndef CONNECTDB_H
#define CONNECTDB_H
#include "stdafx.h"
bool connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/sqlite/test.db");
    if(!db.open())
        return false;
    else
        return true;
}
#endif // CONNECTDB_H
