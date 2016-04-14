#ifndef CLINICCHARGE_H
#define CLINICCHARGE_H

#include <QWidget>
#include "stdafx.h"

namespace Ui {
class ClinicCharge;
}

/*
 *ClinicCharge 门诊收费界面类
 *时间：2016年4月12日
 *作者：xb
 */
class ClinicCharge : public QWidget
{
    Q_OBJECT
    
public:
    explicit ClinicCharge(QWidget *parent = 0);
    ~ClinicCharge();

public:
    bool LoadDate();
    bool SaveDate();

private:
    void init();
    void CreatePatientPart();
    void CreateSocialSecurityPart();
    void CreateDoctorPart();
    void CreateIncomePart();
    void CreateChargeTablePart();
    void SetMyLayout();
    void UpdateChargeTable();
private:
    Ui::ClinicCharge *ui;


    QLabel *chargeNumLabel;                 // 收费单号
    QLabel *nameLabel;                      // 姓名
    QLabel *genderLabel;                    // 性别
    QLabel *ageLabel;                       // 年龄
    QLabel *idCardNumLabel;                 // 身份证号码
    QLabel *socialSecurityNumLabel;         // 社保号码
    QLabel *medicalInsuranceTypeLabel;      // 医保类型
    QLabel *departmentLabel;                // 科室
    QLabel *doctorLabel;                    // 医生
    QLabel *dueIncomeLabel;                 // 应收金额
    QLabel *realIncomeLabel;                // 实收金额

    QLineEdit *chargeNumEdit;               // 收费单号
    QLineEdit *nameEdit;                    // 姓名
    QLineEdit *ageEdit;                     // 年龄
    QLineEdit *idCardNumEdit;               // 身份证号码
    QLineEdit *socialSecurityNumEdit;       // 社保号码
    QLineEdit *departmentEdit;              // 科室
    QLineEdit *doctorEdit;                  // 医生
    QLineEdit *dueIncomeEdit;               // 应收金额
    QLineEdit *realIncomeEdit;              // 实收金额

    QComboBox *genderCombo;                 // 性别
    QComboBox *medicalInsuranceTypeCombo;   // 医保类型

    QSqlTableModel *chargeTableModel;
    QTableView *chargeTableView;            // 收费明细表

    QGroupBox *patientGroup;                // 患者信息
    QGroupBox *insuranceGroup;              // 医保信息
    QGroupBox *doctorGroup;
    QGroupBox *incomeGroup;
    QGroupBox *chargeNumGroup;
};

#endif // CLINICCHARGE_H
