#ifndef PERSION_H
#define PERSION_H
#include "stdafx.h"

class Persion
{
public:
    Persion();
    QString getName() const;
    int     getAge() const;
    Gender  getGender() const;
    QString getIDCard() const;

    void setName(QString str_Name);
    void setAge(int n_Age);
    void setGender(Gender e_Gender);
    void setIDCard(QString str_IDCard);
protected:
    QString m_strName;
    int     m_nAge;
    Gender  m_eGender;
    QString m_strIDCard;
};

#endif // PERSION_H
