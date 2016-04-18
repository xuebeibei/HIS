#include "cliniccharge.h"
#include "ui_cliniccharge.h"

ClinicCharge::ClinicCharge(SubForm *parent) :
    SubForm(parent),
    ui(new Ui::ClinicCharge)
{
    ui->setupUi(this);

    init();
    SetMyLayout();
}

ClinicCharge::~ClinicCharge()
{
    delete ui;
}

void ClinicCharge::newTableFile()
{
    Read();
}

void ClinicCharge::saveTableFile()
{
    Save();
}

void ClinicCharge::findTableFile()
{

}

void ClinicCharge::addRow()
{
    int row = m_chargeRecordsmodel->rowCount();

    m_chargeRecordsmodel->setItem(row, 5, new QStandardItem(""));
}

void ClinicCharge::deleteRow()
{
    m_chargeRecordsmodel->removeRow(0);
}

void ClinicCharge::combo()
{
}

void ClinicCharge::init()
{
    CreatePatientPart();
    CreateSocialSecurityPart();
    CreateDoctorPart();
    CreateIncomePart();
    CreateChargeTablePart();
    m_chargeTable = new ClinicChargeTable;
}

void ClinicCharge::CreatePatientPart()
{
    m_nameLabel = new QLabel(strNameLabel);
    m_nameEdit = new QLineEdit;
    m_nameLabel->setBuddy(m_nameEdit);

    m_genderLabel = new QLabel(strGenderLabel);
    m_genderCombo = new QComboBox;
    m_genderCombo->addItem(strMan);
    m_genderCombo->addItem(strWoman);
    m_genderLabel->setBuddy(m_genderCombo);

    m_ageLabel = new QLabel(strAgeLabel);
    m_ageEdit = new QLineEdit;
    m_ageLabel->setBuddy(m_ageEdit);

    m_idCardNumLabel = new QLabel(strIdCardLabel);
    m_idCardNumEdit = new QLineEdit;
    m_idCardNumEdit->setMinimumWidth(nIdCardEditMinWidth);
    m_idCardNumLabel->setBuddy(m_idCardNumEdit);

    m_patientGroup = new QGroupBox(strPatientGroup);
    QGridLayout *patientGroupLayout = new QGridLayout;
    patientGroupLayout->addWidget(m_nameLabel,0,0);
    patientGroupLayout->addWidget(m_nameEdit,0,1);
    patientGroupLayout->addWidget(m_genderLabel,1,0);
    patientGroupLayout->addWidget(m_genderCombo,1,1);
    patientGroupLayout->addWidget(m_ageLabel,2,0);
    patientGroupLayout->addWidget(m_ageEdit,2,1);
    patientGroupLayout->addWidget(m_idCardNumLabel,3,0);
    patientGroupLayout->addWidget(m_idCardNumEdit,3,1);
    m_patientGroup->setLayout(patientGroupLayout);
}

void ClinicCharge::CreateSocialSecurityPart()
{
    m_socialSecurityNumLabel = new QLabel(strSocialSecurityNumLabel);
    m_socialSecurityNumEdit = new QLineEdit;
    m_socialSecurityNumLabel->setBuddy(m_socialSecurityNumEdit);

    m_medicalInsuranceTypeLabel = new QLabel(strMedicalInsuranceTypeLabel);
    m_medicalInsuranceTypeCombo = new QComboBox;
    m_medicalInsuranceTypeCombo->addItem(strSelfPay);
    m_medicalInsuranceTypeCombo->addItem(strMedicare);
    m_medicalInsuranceTypeCombo->addItem(strNCMS);
    m_medicalInsuranceTypeLabel->setBuddy(m_medicalInsuranceTypeCombo);

    m_insuranceGroup = new QGroupBox(strInsuranceGroup);
    QGridLayout *insuranceGroupLayout = new QGridLayout;
    insuranceGroupLayout->addWidget(m_socialSecurityNumLabel,0,0);
    insuranceGroupLayout->addWidget(m_socialSecurityNumEdit,0,1);
    insuranceGroupLayout->addWidget(m_medicalInsuranceTypeLabel,1,0);
    insuranceGroupLayout->addWidget(m_medicalInsuranceTypeCombo,1,1);
    m_insuranceGroup->setLayout(insuranceGroupLayout);
}

void ClinicCharge::CreateDoctorPart()
{
    m_departmentLabel = new QLabel(strDepartmentLabel);
    m_departmentEdit = new QLineEdit;
    m_departmentLabel->setBuddy(m_departmentEdit);

    m_doctorLabel = new QLabel(strDoctorLabel);
    m_doctorEdit = new QLineEdit;
    m_doctorLabel->setBuddy(m_doctorEdit);

    m_doctorGroup = new QGroupBox(strDoctorGroup);
    QGridLayout *doctorGroupLayout = new QGridLayout;
    doctorGroupLayout->addWidget(m_departmentLabel,0,0);
    doctorGroupLayout->addWidget(m_departmentEdit,0,1);
    doctorGroupLayout->addWidget(m_doctorLabel,1,0);
    doctorGroupLayout->addWidget(m_doctorEdit,1,1);
    m_doctorGroup->setLayout(doctorGroupLayout);
}

void ClinicCharge::CreateIncomePart()
{
    m_dueIncomeLabel = new QLabel(strDueIncomeLabel);
    m_dueIncomeEdit = new QLineEdit;
    m_dueIncomeEdit->setEnabled(false);
    m_dueIncomeLabel->setBuddy(m_dueIncomeEdit);

    m_realIncomeLabel = new QLabel(strRealIncomeLabel);
    m_realIncomeEdit = new QLineEdit;
    m_doctorLabel->setBuddy(m_doctorEdit);

    m_incomeGroup = new QGroupBox(strIncomeGroup);
    QGridLayout *incomeGroupLayout = new QGridLayout;
    incomeGroupLayout->addWidget(m_dueIncomeLabel,0,0);
    incomeGroupLayout->addWidget(m_dueIncomeEdit,0,1);
    incomeGroupLayout->addWidget(m_realIncomeLabel,1,0);
    incomeGroupLayout->addWidget(m_realIncomeEdit,1,1);
    m_incomeGroup->setLayout(incomeGroupLayout);
}

void ClinicCharge::CreateChargeTablePart()
{
    m_chargeNumLabel = new QLabel(strClincChargeNumLabel);
    m_chargeNumEdit = new QLineEdit;
    m_chargeNumLabel->setBuddy(m_chargeNumEdit);

    m_chargeNumGroup = new QGroupBox(strClinicChargeNumGroup);
    QGridLayout *chargeGroupLayout = new QGridLayout;
    chargeGroupLayout->addWidget(m_chargeNumLabel,0,0);
    chargeGroupLayout->addWidget(m_chargeNumEdit,0,1);
    m_chargeNumGroup->setLayout(chargeGroupLayout);

    addRowButton = new QToolButton;
    addRowButton->setIcon(QIcon("D:/qtProgram/HIS2.0/HIS/icon/addRow.png"));
    connect(addRowButton, SIGNAL(clicked()), this, SLOT(addRow()));
    deleteRowButton = new QToolButton;
    deleteRowButton->setIcon(QIcon("D:/qtProgram/HIS2.0/HIS/icon/deleteRow.png"));
    connect(deleteRowButton, SIGNAL(clicked()), this, SLOT(deleteRow()));
    comboButton = new QToolButton;
    comboButton->setIcon(QIcon("D:/qtProgram/HIS2.0/HIS/icon/combo.png"));
    connect(comboButton, SIGNAL(clicked()), this, SLOT(combo()));

    m_chargeTableView = new QTableView;
    m_chargeRecordsmodel = new QStandardItemModel;

    m_chargeRecordsmodel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("收费项编码")));
    m_chargeRecordsmodel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("收费项名称")));
    m_chargeRecordsmodel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("数量")));
    m_chargeRecordsmodel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("单价")));
    m_chargeRecordsmodel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("门诊收据")));
    m_chargeRecordsmodel->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("门诊分类")));
    m_chargeRecordsmodel->setItem(0, 5, new QStandardItem(""));
    m_chargeTableView->setModel(m_chargeRecordsmodel);
}

void ClinicCharge::SetMyLayout()
{
    QVBoxLayout *LeftLayout = new QVBoxLayout;
    LeftLayout->addWidget(m_chargeNumGroup);
    LeftLayout->addWidget(m_patientGroup);
    LeftLayout->addWidget(m_insuranceGroup);
    LeftLayout->addWidget(m_doctorGroup);
    LeftLayout->addWidget(m_incomeGroup);
    LeftLayout->addStretch();

    QHBoxLayout *RightTopLayout = new QHBoxLayout;
    RightTopLayout->addWidget(addRowButton);
    RightTopLayout->addWidget(deleteRowButton);
    RightTopLayout->addWidget(comboButton);
    RightTopLayout->addStretch();
    QVBoxLayout *RightLayout = new QVBoxLayout;
    RightLayout->addLayout(RightTopLayout);
    RightLayout->addWidget(m_chargeTableView);

    QHBoxLayout *MainLayout = new QHBoxLayout;
    MainLayout->addLayout(LeftLayout);
    MainLayout->addLayout(RightLayout);
    MainLayout->setStretchFactor(RightLayout,1);

    setLayout(MainLayout);
}

bool ClinicCharge::Read()
{
    if(m_chargeTable->Read())
    {
        m_chargeNumEdit->setText(m_chargeTable->getID());
        QString strName = m_chargeTable->getName();
        m_nameEdit->setText(strName);
        m_ageEdit->setText(QString::number(m_chargeTable->getAge()));
        m_genderCombo->setCurrentIndex(m_chargeTable->getGender());
        m_idCardNumEdit->setText(m_chargeTable->getIDCard());
        m_socialSecurityNumEdit->setText(m_chargeTable->getSocialSecurityNum());
        m_medicalInsuranceTypeCombo->setCurrentIndex(m_chargeTable->getMedicalInsuranceType());
        m_departmentEdit->setText(m_chargeTable->getDepartment());
        m_doctorEdit->setText(m_chargeTable->getDoctor());
        m_dueIncomeEdit->setText(QString::number(m_chargeTable->getDueIncome()));
        m_realIncomeEdit->setText(QString::number(m_chargeTable->getRealImcome()));
        // 将明细显示在界面
        QSqlTableModel *model = m_chargeTable->getChargeRecords();
        for(int i = 0; i< model->rowCount();i++)
        {
            QSqlRecord record = model->record(i);
            m_chargeRecordsmodel->setItem(0, 0, new QStandardItem(record.value("ChargeItemNo").toString()));
            m_chargeRecordsmodel->setItem(0, 1, new QStandardItem(record.value("ChargeItemName").toString()));
            m_chargeRecordsmodel->setItem(0, 2, new QStandardItem(record.value("ChargeItemCount").toString()));
            m_chargeRecordsmodel->setItem(0, 3, new QStandardItem(record.value("ChargeItemPrice").toString()));
            m_chargeRecordsmodel->setItem(0, 4, new QStandardItem(record.value("ChinicReceipt").toString()));
            m_chargeRecordsmodel->setItem(0, 5, new QStandardItem(record.value("ClinicSort ").toString()));
        }

        return true;
    }
    else
        return false;
}

bool ClinicCharge::Save()
{
    m_chargeTable->setID(m_chargeNumEdit->text());
    m_chargeTable->setName(m_nameEdit->text());
    m_chargeTable->setAge(m_ageEdit->text().toInt());
    m_chargeTable->setGender((Gender)m_genderCombo->currentIndex());
    m_chargeTable->setIDCard(m_idCardNumEdit->text());
    m_chargeTable->setSocialSecurityNum(m_socialSecurityNumEdit->text());
    m_chargeTable->setMedicalInsuranceType((MedicalInsuranceType)m_medicalInsuranceTypeCombo->currentIndex());
    m_chargeTable->setDepartment(m_departmentEdit->text());
    m_chargeTable->setDoctor(m_doctorEdit->text());
    m_chargeTable->setDueIncome(m_dueIncomeEdit->text().toDouble());
    m_chargeTable->setRealIncome(m_realIncomeEdit->text().toDouble());
     // 将明细保存至数据
    m_chargeTable->saveChargeRecords(m_chargeRecordsmodel);//??
    if(m_chargeTable->Save())
        return true;
    else
        return false;
}
