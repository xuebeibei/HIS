#ifndef CLINICCHARGE_H
#define CLINICCHARGE_H

#include <QWidget>
#include "stdafx.h"
#include "subform.h"
#include "clinicchargetable.h"

namespace Ui {
class ClinicCharge;
}

class ClinicCharge : public SubForm
{
    Q_OBJECT
    
public:
    explicit ClinicCharge(SubForm *parent = 0);
    ~ClinicCharge();

public slots:
    void newTableFile();
    bool saveTableFile();
    void deleteTableFile();
    void exportTableFile();
    bool findTableFile();
    void amendTableFile();
    void previewTableFile();
    void printTableFile();
private slots:
    void addRow();
    void deleteRow();
    void combo();

private:

    void init();
    void initTableModel();
    void setAllDefaultEnable();
    void setAllUnEnable();
    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：create
    // 作用：创建门诊收费窗体中所有控件
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void create();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：CreatePatientPart
    // 作用：创建患者信息部分控件并编组
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void CreatePatientPart();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：CreateSocialSecurityPart
    // 作用：创建社保信息部分控件并编组
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void CreateSocialSecurityPart();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：CreateDoctorPart
    // 作用：创建医生信息部分控件并编组
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void CreateDoctorPart();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：CreateIncomePart
    // 作用：创建收入信息部分控件并编组
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void CreateIncomePart();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：CreateChargeTablePart
    // 作用：创建收费表格信息部分控件
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void CreateChargeTablePart();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：SetMyLayout
    // 作用：将门诊收费界面所有控件进行布局
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void SetMyLayout();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：Read
    // 作用：从数据类中读取收费单，并更新至界面
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    bool Read();
    bool Save();
    bool Delete();

private:
    Ui::ClinicCharge *ui;
    //-----------------------------------------------------------------------------------------------------------------------------------
    // - 界面控件
    //-----------------------------------------------------------------------------------------------------------------------------------
    QLabel *m_chargeNumLabel;                 // 收费单号
    QLabel *m_nameLabel;                      // 姓名
    QLabel *m_genderLabel;                    // 性别
    QLabel *m_ageLabel;                       // 年龄
    QLabel *m_idCardNumLabel;                 // 身份证号码
    QLabel *m_socialSecurityNumLabel;         // 社保号码
    QLabel *m_medicalInsuranceTypeLabel;      // 医保类型
    QLabel *m_departmentLabel;                // 科室
    QLabel *m_doctorLabel;                    // 医生
    QLabel *m_dueIncomeLabel;                 // 应收金额
    QLabel *m_realIncomeLabel;                // 实收金额

    QLineEdit *m_chargeNumEdit;               // 收费单号
    QLineEdit *m_nameEdit;                    // 姓名
    QLineEdit *m_ageEdit;                     // 年龄
    QLineEdit *m_idCardNumEdit;               // 身份证号码
    QLineEdit *m_socialSecurityNumEdit;       // 社保号码
    QLineEdit *m_departmentEdit;              // 科室
    QLineEdit *m_doctorEdit;                  // 医生
    QLineEdit *m_dueIncomeEdit;               // 应收金额
    QLineEdit *m_realIncomeEdit;              // 实收金额

    QComboBox *m_genderCombo;                 // 性别
    QComboBox *m_medicalInsuranceTypeCombo;   // 医保类型


    QTableView *m_chargeTableView;            // 收费明细表
    QStandardItemModel *m_chargeRecordsmodel;

    QGroupBox *m_patientGroup;                // 患者信息组
    QGroupBox *m_insuranceGroup;              // 医保信息组
    QGroupBox *m_doctorGroup;                 // 医生信息组
    QGroupBox *m_incomeGroup;                 // 应收信息组
    QGroupBox *m_chargeNumGroup;              // 实收信息组

    QToolButton *addRowButton;
    QToolButton *deleteRowButton;
    QToolButton *comboButton;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // - 数据
    //-----------------------------------------------------------------------------------------------------------------------------------
    ClinicChargeTable *m_chargeTable;

};

#endif // CLINICCHARGE_H
