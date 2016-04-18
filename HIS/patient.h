#ifndef PATIENT_H
#define PATIENT_H
#include "stdafx.h"
#include "persion.h"


class Patient : public Persion
{
public:
    Patient();
    QString getSocialSecurityNum() const;
    MedicalInsuranceType getMedicalInsuranceType() const;
    QString getDepartment() const;
    QString getDoctor() const;

    void setSocialSecurityNum(QString str_SocialSecurityNum);
    void setMedicalInsuranceType(MedicalInsuranceType edicalInsuranceType);
    void setDepartment(QString str_Department);
    void setDoctor(QString str_Doctor);
protected:
    QString m_strSocialSecurityNum;         // 社保号码
    MedicalInsuranceType m_eMedicalInsuranceType;      // 医保类型
    QString m_strDepartment;           // 科室
    QString m_strDoctor;               // 医生
};

#endif // PATIENT_H
