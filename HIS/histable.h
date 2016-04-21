#ifndef HISTABLE_H
#define HISTABLE_H
#include "stdafx.h"
#include "winSet.h"

//-----------------------------------------------------------------------------------------------------------------------------------
// HIS系统单据类
//-----------------------------------------------------------------------------------------------------------------------------------
class HISTable
{
public:
    HISTable();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：Read
    // 作用：从数据库中读取
    // 参数：无
    // 返回值：
    // true  - 读取成功
    // false - 读取失败
    // 备注：需要在子类中实现
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    virtual bool Read() = 0;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：Save
    // 作用：保存到数据库
    // 参数：无
    // 返回值：
    // true  - 保存成功
    // false - 保存失败
    // 备注：需要在子类中实现
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    virtual bool Save() = 0;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：Delete
    // 作用：从数据库中删除
    // 参数：无
    // 返回值：
    // true  - 删除成功
    // false - 删除失败
    // 备注：需要在子类中实现
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    virtual bool Delete() = 0;
protected:

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getNewID
    // 作用：根据年月日时分秒产生新的单号
    // 参数：无
    // 返回值：
    // QString  - 新单号
    // 备注：需要在子类中实现
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    QString getNewID() const;

};

#endif // HISTABLE_H
