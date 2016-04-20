#ifndef PERSION_H
#define PERSION_H
#include "stdafx.h"


//-----------------------------------------------------------------------------------------------------------------------------------
// 人类
//-----------------------------------------------------------------------------------------------------------------------------------
class Persion
{
public:
    Persion();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getName
    // 作用：得到姓名
    // 参数：无
    // 返回值：
    // QString - 姓名
    // 备注：无
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    QString getName() const;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getAge
    // 作用：得到年龄
    // 参数：无
    // 返回值：
    // int - 年龄
    // 备注：无
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    int getAge() const;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getGender
    // 作用：得到性别
    // 参数：无
    // 返回值：
    // Gender - 性别
    // 备注：无
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    Gender  getGender() const;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getIDCard
    // 作用：得到身份证号
    // 参数：无
    // 返回值：
    // QSting - 身份证号
    // 备注：无
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    QString getIDCard() const;


    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setName
    // 作用：设置姓名
    // 参数：
    // str_Name  - 姓名
    // 返回值：无
    // 备注：无
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setName(QString str_Name);

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setAge
    // 作用：设置年龄
    // 参数：
    // n_Age  - 年龄
    // 返回值：无
    // 备注：无
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setAge(int n_Age);

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setGender
    // 作用：设置性别
    // 参数：
    // e_Gender  - 性别
    // 返回值：无
    // 备注：无
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setGender(Gender e_Gender);

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setIDCard
    // 作用：设置身份证号
    // 参数：
    // str_IDCard  - 身份证号
    // 返回值：无
    // 备注：无
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setIDCard(QString str_IDCard);
protected:
    QString m_strName;  // 姓名
    int     m_nAge;     // 年龄
    Gender  m_eGender;  // 性别
    QString m_strIDCard;// 身份证号
};

#endif // PERSION_H