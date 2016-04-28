#include "clinicpaymentstatisticform.h"

ClinicPaymentStatisticForm::ClinicPaymentStatisticForm(SubForm *parent) :
    SubForm(parent)
{
    create();
    setMyLayout();
    init();
}

ClinicPaymentStatisticForm::~ClinicPaymentStatisticForm()
{

}

void ClinicPaymentStatisticForm::newTableFile()
{
}

bool ClinicPaymentStatisticForm::saveTableFile()
{
    return true;
}

bool ClinicPaymentStatisticForm::deleteTableFile()
{
    return true;
}

void ClinicPaymentStatisticForm::exportTableFile()
{
}

bool ClinicPaymentStatisticForm::findTableFile()
{
    return true;
}

void ClinicPaymentStatisticForm::amendTableFile()
{
}

void ClinicPaymentStatisticForm::previewTableFile()
{
}

void ClinicPaymentStatisticForm::printTableFile()
{
}

void ClinicPaymentStatisticForm::create()
{
    m_startDateLabel = new QLabel(strStartDateLabel);
    m_startDateEdit = new QDateEdit;
    m_startDateEdit->setCalendarPopup(true);
    connect(m_startDateEdit, SIGNAL(dateChanged(QDate)), this, SLOT());
    m_endDateLabel = new QLabel(strEndDateLabel);
    m_endDateEdit = new QDateEdit;
    m_endDateEdit->setCalendarPopup(true);
    connect(m_endDateEdit, SIGNAL(dateChanged(QDate)), this, SLOT());


    m_conditionSortBtnGroup = new QButtonGroup(this);
    m_conditionWhoBtnGroup = new QButtonGroup(this);

    m_conditionSortGroup = new QGroupBox;
    m_clinicReceiptRadio = new QRadioButton("门诊收据");
    connect(m_clinicReceiptRadio, SIGNAL(clicked(bool)), this, SLOT(setConditionSort()));
    m_clinicSortRadio = new QRadioButton("门诊分类");
    connect(m_clinicSortRadio, SIGNAL(clicked(bool)), this, SLOT(setConditionSort()));
    m_conditionSortBtnGroup->addButton(m_clinicReceiptRadio, 0);
    m_conditionSortBtnGroup->addButton(m_clinicSortRadio, 1);

    m_conditionWhoGroup = new QGroupBox;
    m_departmentRadio = new QRadioButton("科室");
    connect(m_departmentRadio, SIGNAL(clicked(bool)), this, SLOT(setConditionWho()));
    m_doctorRadio = new QRadioButton("医生");
    connect(m_doctorRadio, SIGNAL(clicked(bool)), this, SLOT(setConditionWho()));
    m_makerRadio = new QRadioButton("制单人");
    connect(m_makerRadio, SIGNAL(clicked(bool)), this, SLOT(setConditionWho()));
    m_conditionWhoBtnGroup->addButton(m_departmentRadio, 0);
    m_conditionWhoBtnGroup->addButton(m_doctorRadio, 1);
    m_conditionWhoBtnGroup->addButton(m_makerRadio, 2);

    m_resultView = new QTableView;
    m_resultModel = new QStandardItemModel;
    m_resultView->setModel(m_resultModel);

    m_strConditionSort = "门诊收据";
    m_strConditionWho = "科室";
}

void ClinicPaymentStatisticForm::setMyLayout()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QVBoxLayout *leftLayout = new QVBoxLayout;
    QVBoxLayout *rightLayout = new QVBoxLayout;
    QGridLayout *dateLayout = new QGridLayout;
    QVBoxLayout *conditionSortLayout = new QVBoxLayout;
    QVBoxLayout *conditionWhoLayout = new QVBoxLayout;

    dateLayout->addWidget(m_startDateLabel,0,0);
    dateLayout->addWidget(m_startDateEdit,0,1);
    dateLayout->addWidget(m_endDateLabel,1,0);
    dateLayout->addWidget(m_endDateEdit,1,1);

    conditionSortLayout->addWidget(m_clinicReceiptRadio);
    conditionSortLayout->addWidget(m_clinicSortRadio);
    m_conditionSortGroup->setLayout(conditionSortLayout);

    conditionWhoLayout->addWidget(m_departmentRadio);
    conditionWhoLayout->addWidget(m_doctorRadio);
    conditionWhoLayout->addWidget(m_makerRadio);
    m_conditionWhoGroup->setLayout(conditionWhoLayout);

    leftLayout->addLayout(dateLayout);
    leftLayout->addWidget(m_conditionSortGroup);
    leftLayout->addWidget(m_conditionWhoGroup);
    leftLayout->addStretch();

    rightLayout->addWidget(m_resultView);

    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(rightLayout, 1);
    setLayout(mainLayout);
}

void ClinicPaymentStatisticForm::init()
{
    initTable();

    m_startDateEdit->setDate(QDate::currentDate());
    m_endDateEdit->setDate(QDate::currentDate());
    m_clinicReceiptRadio->setChecked(true);
    m_departmentRadio->setChecked(true);
}

void ClinicPaymentStatisticForm::initTable()
{
    m_resultModel->clear();
    m_resultModel->setHorizontalHeaderItem(0, new QStandardItem(m_strConditionSort));
    m_resultModel->setHorizontalHeaderItem(1, new QStandardItem(m_strConditionWho));
    m_resultModel->setHorizontalHeaderItem(2, new QStandardItem("应收合计"));
    m_resultModel->setItem(0, 2, NULL);
}

void ClinicPaymentStatisticForm::updateTable()
{
    // 获取条件
    initTable();

    if(myDB::connectDB())
    {

    }
    // 从数据库按条件查询
}

void ClinicPaymentStatisticForm::setConditionSort()
{
    switch(m_conditionSortBtnGroup->checkedId())
    {
    case 0:
        m_strConditionSort = "门诊收据";
        break;
    case 1:
        m_strConditionSort = "门诊分类";
        break;
    }
    updateTable();
}

void ClinicPaymentStatisticForm::setConditionWho()
{
    switch(m_conditionWhoBtnGroup->checkedId())
    {
    case 0:
        m_strConditionWho = "科室";
        break;
    case 1:
        m_strConditionWho = "医生";
        break;
    case 2:
        m_strConditionWho = "制单人";
        break;
    }
    updateTable();
}

void ClinicPaymentStatisticForm::setStartDate()
{
    m_startDate = m_startDateEdit->date();
    updateTable();
}

void ClinicPaymentStatisticForm::setEndDate()
{
    m_endDate = m_endDateEdit->date();
    updateTable();
}


