#include "cliniccharge.h"
#include "ui_cliniccharge.h"
#include "connectDB.h"
ClinicCharge::ClinicCharge(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClinicCharge)
{
    ui->setupUi(this);

    init();
    SetMyLayout();
    setMinimumWidth(850);
    setMinimumHeight(600);
    LoadDate();
}

ClinicCharge::~ClinicCharge()
{
    delete ui;
}

bool ClinicCharge::LoadDate()
{
    if(connectDB())
    {
        UpdateChargeTable();
        return true;
    }
    else
        return false;

}

bool ClinicCharge::SaveDate()
{
    return true;

}

void ClinicCharge::init()
{
    CreatePatientPart();
    CreateSocialSecurityPart();
    CreateDoctorPart();
    CreateIncomePart();
    CreateChargeTablePart();
}

void ClinicCharge::CreatePatientPart()
{
    nameLabel = new QLabel(tr("姓名："));
    nameEdit = new QLineEdit;
    nameLabel->setBuddy(nameEdit);

    genderLabel = new QLabel(tr("性别："));
    genderCombo = new QComboBox;
    genderLabel->setBuddy(genderCombo);

    ageLabel = new QLabel(tr("年龄："));
    ageEdit = new QLineEdit;
    ageLabel->setBuddy(ageEdit);

    idCardNumLabel = new QLabel(tr("身份证号："));
    idCardNumEdit = new QLineEdit;
    idCardNumLabel->setBuddy(idCardNumEdit);

    patientGroup = new QGroupBox(tr(""));
    QGridLayout *patientGroupLayout = new QGridLayout;
    patientGroupLayout->addWidget(nameLabel,0,0);
    patientGroupLayout->addWidget(nameEdit,0,1);
    patientGroupLayout->addWidget(genderLabel,1,0);
    patientGroupLayout->addWidget(genderCombo,1,1);
    patientGroupLayout->addWidget(ageLabel,2,0);
    patientGroupLayout->addWidget(ageEdit,2,1);
    patientGroupLayout->addWidget(idCardNumLabel,3,0);
    patientGroupLayout->addWidget(idCardNumEdit,3,1);
    patientGroup->setLayout(patientGroupLayout);
}

void ClinicCharge::CreateSocialSecurityPart()
{
    socialSecurityNumLabel = new QLabel(tr("社保号码："));
    socialSecurityNumEdit = new QLineEdit;
    socialSecurityNumLabel->setBuddy(socialSecurityNumEdit);

    medicalInsuranceTypeLabel = new QLabel(tr("医保类型："));
    medicalInsuranceTypeCombo = new QComboBox;
    medicalInsuranceTypeLabel->setBuddy(medicalInsuranceTypeCombo);

    insuranceGroup = new QGroupBox(tr(""));
    QGridLayout *insuranceGroupLayout = new QGridLayout;
    insuranceGroupLayout->addWidget(socialSecurityNumLabel,0,0);
    insuranceGroupLayout->addWidget(socialSecurityNumEdit,0,1);
    insuranceGroupLayout->addWidget(medicalInsuranceTypeLabel,1,0);
    insuranceGroupLayout->addWidget(medicalInsuranceTypeCombo,1,1);
    insuranceGroup->setLayout(insuranceGroupLayout);
}

void ClinicCharge::CreateDoctorPart()
{
    departmentLabel = new QLabel(tr("就诊科室："));
    departmentEdit = new QLineEdit;
    departmentLabel->setBuddy(departmentEdit);

    doctorLabel = new QLabel(tr("医生："));
    doctorEdit = new QLineEdit;
    doctorLabel->setBuddy(doctorEdit);

    doctorGroup = new QGroupBox(tr(""));
    QGridLayout *doctorGroupLayout = new QGridLayout;
    doctorGroupLayout->addWidget(departmentLabel,0,0);
    doctorGroupLayout->addWidget(departmentEdit,0,1);
    doctorGroupLayout->addWidget(doctorLabel,1,0);
    doctorGroupLayout->addWidget(doctorEdit,1,1);
    doctorGroup->setLayout(doctorGroupLayout);
}

void ClinicCharge::CreateIncomePart()
{
    dueIncomeLabel = new QLabel(tr("应收金额："));
    dueIncomeEdit = new QLineEdit;
    dueIncomeEdit->setEnabled(false);
    dueIncomeLabel->setBuddy(dueIncomeEdit);

    realIncomeLabel = new QLabel(tr("实收金额："));
    realIncomeEdit = new QLineEdit;
    doctorLabel->setBuddy(doctorEdit);

    incomeGroup = new QGroupBox(tr(""));
    QGridLayout *incomeGroupLayout = new QGridLayout;
    incomeGroupLayout->addWidget(dueIncomeLabel,0,0);
    incomeGroupLayout->addWidget(dueIncomeEdit,0,1);
    incomeGroupLayout->addWidget(realIncomeLabel,1,0);
    incomeGroupLayout->addWidget(realIncomeEdit,1,1);
    incomeGroup->setLayout(incomeGroupLayout);
}

void ClinicCharge::CreateChargeTablePart()
{
    chargeNumLabel = new QLabel(tr("收费单号："));
    chargeNumEdit = new QLineEdit;
    chargeNumLabel->setBuddy(chargeNumEdit);

    chargeNumGroup = new QGroupBox(tr(""));
    QGridLayout *chargeGroupLayout = new QGridLayout;
    chargeGroupLayout->addWidget(chargeNumLabel,0,0);
    chargeGroupLayout->addWidget(chargeNumEdit,0,1);
    chargeNumGroup->setLayout(chargeGroupLayout);

    chargeTableView = new QTableView;
}


void ClinicCharge::SetMyLayout()
{
    QVBoxLayout *LeftLayout = new QVBoxLayout;
    LeftLayout->addWidget(chargeNumGroup);
    LeftLayout->addWidget(patientGroup);
    LeftLayout->addWidget(insuranceGroup);
    LeftLayout->addWidget(doctorGroup);
    LeftLayout->addWidget(incomeGroup);
    LeftLayout->addStretch();

    QVBoxLayout *RightLayout = new QVBoxLayout;
    RightLayout->addWidget(chargeTableView);

    QHBoxLayout *MainLayout = new QHBoxLayout;
    MainLayout->addLayout(LeftLayout);
    MainLayout->addLayout(RightLayout);
    MainLayout->setStretchFactor(RightLayout,1);

    setLayout(MainLayout);
}

void ClinicCharge::UpdateChargeTable()
{
    chargeTableModel = new QSqlTableModel;
    chargeTableModel->setTable("department");
    chargeTableModel->select();

    chargeTableView->setModel(chargeTableModel);
}


