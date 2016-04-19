#include "cliniccharge.h"
#include "ui_cliniccharge.h"


ClinicCharge::ClinicCharge(SubForm *parent) :
    SubForm(parent),
    ui(new Ui::ClinicCharge)
{
    ui->setupUi(this);

    create();
    init();
    SetMyLayout();
    setAllDefaultEnable();
}

ClinicCharge::~ClinicCharge()
{
    delete ui;
}

void ClinicCharge::newTableFile()
{
    init();
    m_chargeTable = new ClinicChargeTable;
    Read();
    setAllDefaultEnable();
}

void ClinicCharge::saveTableFile()
{
    Save();
    setAllUnEnable();
}

void ClinicCharge::deleteTableFile()
{
    QMessageBox::information(this,"提示","删除门诊收费单");
    Delete();
}

void ClinicCharge::exportTableFile()
{
    QMessageBox::information(this,"提示","导出门诊收费单");
}

void ClinicCharge::findTableFile()
{
    QMessageBox::information(this,"提示","查询单号为CC2016419185656的收费单");
    m_chargeTable->setID("CC2016419185656");
    Read(); // 有待改进，添加更多的查询条件
    setAllUnEnable();
}

void ClinicCharge::amendTableFile()
{
    setAllDefaultEnable();
}

void ClinicCharge::previewTableFile()
{
    QMessageBox::information(this,"提示","预览收费单");
}

void ClinicCharge::printTableFile()
{
    QMessageBox::information(this,"提示","打印收费单");
}

void ClinicCharge::setAllDefaultEnable()
{
    m_nameEdit->setEnabled(true);
    m_genderCombo->setEnabled(true);
    m_ageEdit->setEnabled(true);
    m_idCardNumEdit->setEnabled(true);
    m_socialSecurityNumEdit->setEnabled(true);
    m_medicalInsuranceTypeCombo->setEnabled(true);
    m_departmentEdit->setEnabled(true);
    m_doctorEdit->setEnabled(true);
    m_dueIncomeEdit->setEnabled(false);
    m_realIncomeEdit->setEnabled(true);
    m_chargeNumEdit->setEnabled(false);
    addRowButton->setEnabled(true);
    deleteRowButton->setEnabled(true);
    comboButton->setEnabled(true);
    m_chargeTableView->setEnabled(true);
}


void ClinicCharge::setAllUnEnable()
{
    m_nameEdit->setEnabled(false);
    m_genderCombo->setEnabled(false);
    m_ageEdit->setEnabled(false);
    m_idCardNumEdit->setEnabled(false);
    m_socialSecurityNumEdit->setEnabled(false);
    m_medicalInsuranceTypeCombo->setEnabled(false);
    m_departmentEdit->setEnabled(false);
    m_doctorEdit->setEnabled(false);
    m_dueIncomeEdit->setEnabled(false);
    m_realIncomeEdit->setEnabled(false);
    m_chargeNumEdit->setEnabled(false);
    addRowButton->setEnabled(false);
    deleteRowButton->setEnabled(false);
    comboButton->setEnabled(false);
    //m_chargeTableView->setEnabled(false);
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
    QMessageBox::information(this,"提示","选择套餐！");
}

void ClinicCharge::create()
{
    CreatePatientPart();
    CreateSocialSecurityPart();
    CreateDoctorPart();
    CreateIncomePart();
    CreateChargeTablePart();
    m_chargeTable = new ClinicChargeTable;
}
void ClinicCharge::init()
{
    initPatientPart();
    initSocialSecurityPart();
    initDoctorPart();
    initIncomePart();
    initChargeTablePart();
}

void ClinicCharge::CreatePatientPart()
{
    m_nameLabel = new QLabel(strNameLabel);
    m_nameEdit = new QLineEdit;
    m_nameLabel->setBuddy(m_nameEdit);

    m_genderLabel = new QLabel(strGenderLabel);
    m_genderCombo = new QComboBox;
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

void ClinicCharge::initPatientPart()
{
    m_nameEdit->setText(strNull);
    m_genderCombo->addItem(strMan);
    m_genderCombo->addItem(strWoman);
    m_ageEdit->setText(strNull);
    m_idCardNumEdit->setText(strNull);
}

void ClinicCharge::CreateSocialSecurityPart()
{
    m_socialSecurityNumLabel = new QLabel(strSocialSecurityNumLabel);
    m_socialSecurityNumEdit = new QLineEdit;
    m_socialSecurityNumLabel->setBuddy(m_socialSecurityNumEdit);

    m_medicalInsuranceTypeLabel = new QLabel(strMedicalInsuranceTypeLabel);
    m_medicalInsuranceTypeCombo = new QComboBox;
    m_medicalInsuranceTypeLabel->setBuddy(m_medicalInsuranceTypeCombo);

    m_insuranceGroup = new QGroupBox(strInsuranceGroup);
    QGridLayout *insuranceGroupLayout = new QGridLayout;
    insuranceGroupLayout->addWidget(m_socialSecurityNumLabel,0,0);
    insuranceGroupLayout->addWidget(m_socialSecurityNumEdit,0,1);
    insuranceGroupLayout->addWidget(m_medicalInsuranceTypeLabel,1,0);
    insuranceGroupLayout->addWidget(m_medicalInsuranceTypeCombo,1,1);
    m_insuranceGroup->setLayout(insuranceGroupLayout);
}

void ClinicCharge::initSocialSecurityPart()
{
    m_socialSecurityNumEdit->setText(strNull);
    m_medicalInsuranceTypeCombo->addItem(strSelfPay);
    m_medicalInsuranceTypeCombo->addItem(strMedicare);
    m_medicalInsuranceTypeCombo->addItem(strNCMS);
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

void ClinicCharge::initDoctorPart()
{
    m_departmentEdit->setText(strNull);
    m_doctorEdit->setText(strNull);
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

void ClinicCharge::initIncomePart()
{
    m_dueIncomeEdit->setText(strNull);
    m_realIncomeEdit->setText(strNull);
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
    m_chargeTableView->setModel(m_chargeRecordsmodel);
    initTableModel();
}

void ClinicCharge::initChargeTablePart()
{
     m_chargeNumEdit->setText(strNull);
     initTableModel();
}

void ClinicCharge::initTableModel()
{
    m_chargeRecordsmodel->clear();
    m_chargeRecordsmodel->setHorizontalHeaderItem(chargeItemNo, new QStandardItem(QObject::tr("收费项编码")));
    m_chargeRecordsmodel->setHorizontalHeaderItem(chargeItemName, new QStandardItem(QObject::tr("收费项名称")));
    m_chargeRecordsmodel->setHorizontalHeaderItem(chargeItemCount, new QStandardItem(QObject::tr("数量")));
    m_chargeRecordsmodel->setHorizontalHeaderItem(chargeItemPrice, new QStandardItem(QObject::tr("单价")));
    m_chargeRecordsmodel->setHorizontalHeaderItem(clinicReceipt, new QStandardItem(QObject::tr("门诊收据")));
    m_chargeRecordsmodel->setHorizontalHeaderItem(clinicSort, new QStandardItem(QObject::tr("门诊分类")));
    m_chargeRecordsmodel->setItem(0, 5, new QStandardItem(""));
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
        QString strName = m_chargeTable->getPatient().getName();
        m_nameEdit->setText(strName);
        m_ageEdit->setText(QString::number(m_chargeTable->getPatient().getAge()));
        m_genderCombo->setCurrentIndex(m_chargeTable->getPatient().getGender());
        m_idCardNumEdit->setText(m_chargeTable->getPatient().getIDCard());
        m_socialSecurityNumEdit->setText(m_chargeTable->getPatient().getSocialSecurityNum());
        m_medicalInsuranceTypeCombo->setCurrentIndex(m_chargeTable->getPatient().getMedicalInsuranceType());
        m_departmentEdit->setText(m_chargeTable->getPatient().getDepartment());
        m_doctorEdit->setText(m_chargeTable->getPatient().getDoctor());
        m_dueIncomeEdit->setText(QString::number(m_chargeTable->getDueIncome()));
        m_realIncomeEdit->setText(QString::number(m_chargeTable->getRealImcome()));


        QVector<ClinicChargeItem*> chargeItems = m_chargeTable->getChargeItems();
        for(int index = 0; index< chargeItems.size();index++)
        {
            ClinicChargeItem *item = new ClinicChargeItem(chargeItems.at(index));

            m_chargeRecordsmodel->setItem(index, chargeItemNo, new QStandardItem(item->getChargeItemNo()));
            m_chargeRecordsmodel->setItem(index, chargeItemName, new QStandardItem(item->getChargeItemName()));
            m_chargeRecordsmodel->setItem(index, chargeItemCount, new QStandardItem(QString::number(item->getChargeItemCount())));
            m_chargeRecordsmodel->setItem(index, chargeItemPrice, new QStandardItem(QString::number(item->getChargeItemPrice())));
            m_chargeRecordsmodel->setItem(index, clinicReceipt, new QStandardItem(item->getClinicReceipt()));
            m_chargeRecordsmodel->setItem(index, clinicSort, new QStandardItem(item->getClinicSort()));
        }
        return true;
    }
    else
        return false;
}

bool ClinicCharge::Save()
{
    QString strChargeNum = m_chargeNumEdit->text();
    QString strName = m_nameEdit->text();
    int nAge = m_ageEdit->text().toInt();

    m_chargeTable->setID(strChargeNum);
    Patient onePatient;
    onePatient.setName(strName);
    onePatient.setAge(nAge);
    onePatient.setIDCard(m_idCardNumEdit->text());
    onePatient.setSocialSecurityNum(m_socialSecurityNumEdit->text());
    onePatient.setMedicalInsuranceType((MedicalInsuranceType)m_medicalInsuranceTypeCombo->currentIndex());
    onePatient.setDepartment(m_departmentEdit->text());
    onePatient.setDoctor(m_doctorEdit->text());

    m_chargeTable->setPatient(onePatient);
    m_chargeTable->setDueIncome(m_dueIncomeEdit->text().toDouble());
    m_chargeTable->setRealIncome(m_realIncomeEdit->text().toDouble());
    // 将明细显示在界面
    QVector<ClinicChargeItem*> chargeItems;
    for(int row = 0; row< m_chargeRecordsmodel->rowCount();row++)
    {
        ClinicChargeItem *chargeItem = new ClinicChargeItem;
        for(int column = 0; column < m_chargeRecordsmodel->columnCount();column++)
        {
            QStandardItem *modelItem = m_chargeRecordsmodel->item(row,column);
            if(modelItem == NULL)
                continue;
            else
            {
                switch(column)
                {
                case chargeItemNo:
                {
                    QString strNo = modelItem->text();
                    chargeItem->setChargeItemNo(strNo);
                    break;
                }
                case chargeItemName:
                {
                    QString strName = modelItem->text();
                    chargeItem->setChargeItemName(strName);
                    break;
                }
                case chargeItemCount:
                {
                    int nCount = modelItem->text().toInt();
                    chargeItem->setChargeItemCount(nCount);
                    break;
                }
                case chargeItemPrice:
                {
                    double nPrice= modelItem->text().toDouble();
                    chargeItem->setChargeItemPrice(nPrice);
                    break;
                }
                case clinicReceipt:
                {
                    QString strReceipt = modelItem->text();
                    chargeItem->setClinicReceipt(strReceipt);
                    break;
                }
                case clinicSort:
                {
                    QString strSort = modelItem->text();
                    chargeItem->setClinicSort(strSort);
                    break;
                }
                default:
                    break;
                }
            }
        }
        chargeItem->setClinicChargeId(m_chargeNumEdit->text());
        chargeItems.append(chargeItem);
    }
    m_chargeTable->setChargeItems(chargeItems);

    if(m_chargeTable->Save())
    {
        QMessageBox::information(this,"提示","保存成功！");
        return true;
    }
    else
        return false;
}

bool ClinicCharge::Delete()
{
    if(m_chargeTable->Delete())
    {
        QMessageBox::information(this,"提示","成功删除！");
        newTableFile();
        return true;
    }
    else
    {
        QMessageBox::information(this,"提示","成功失败！");
        return false;
    }
}

