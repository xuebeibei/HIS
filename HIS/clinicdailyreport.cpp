#include "clinicdailyreport.h"

ClinicDailyReport::ClinicDailyReport(SubForm *parent) :
    SubForm(parent)
{
    create();
    init();
    setMyLayout();
    setAllDefaultEnable();
}

ClinicDailyReport::~ClinicDailyReport()
{

}

void ClinicDailyReport::newTableFile()
{
    QMessageBox::information(this,"提示","新建 - 门诊日结");
}

bool ClinicDailyReport::saveTableFile()
{
    QMessageBox::information(this,"提示","保存 - 门诊日结");
    return true;
}

void ClinicDailyReport::deleteTableFile()
{
    QMessageBox::information(this,"提示","删除 - 门诊日结");
}

void ClinicDailyReport::exportTableFile()
{
    QMessageBox::information(this,"提示","导出 - 门诊日结");
}

bool ClinicDailyReport::findTableFile()
{
    QMessageBox::information(this,"提示","查找 - 门诊日结");
    return true;
}

void ClinicDailyReport::amendTableFile()
{
    QMessageBox::information(this,"提示","修改 - 门诊日结");
}

void ClinicDailyReport::previewTableFile()
{
    QMessageBox::information(this,"提示","预览 - 门诊日结");
}

void ClinicDailyReport::printTableFile()
{
    QMessageBox::information(this,"提示","打印 - 门诊日结");
}

void ClinicDailyReport::find()
{
    QMessageBox::information(this,"提示","查询 - 门诊日结");
}

void ClinicDailyReport::create()
{
    m_dailyReportNumLabel = new QLabel("日结单号：");
    m_dailyReportNumEdit = new QLineEdit;

    m_dateLabel = new QLabel("日结日期：");
    m_dateEdit = new QDateEdit;

    m_findButton = new QToolButton;
    m_findButton->setIcon(QIcon(strIconPath + "find.png"));
    connect(m_findButton, SIGNAL(clicked()), this, SLOT(find()));

    m_allDueIncomeLabel = new QLabel("应收合计：");
    m_allRealIncomeLabel = new QLabel("实收合计：");
    m_allDebtLabel = new QLabel("欠款合计：");

    m_allDueIncomeEdit = new QLineEdit;
    m_allRealIncomeEdit = new QLineEdit;
    m_allDebtEdit = new QLineEdit;

    m_dailyReportView = new QTableView;
    m_dailyReportModel = new QStandardItemModel;
    m_dailyReportView->setModel(m_dailyReportModel);
}

void ClinicDailyReport::init()
{
    m_dailyReportNumEdit->setText(strNull);
    m_dateEdit->setDate(QDate::currentDate());
    initTable();
}

void ClinicDailyReport::initTable()
{
    m_dailyReportModel->clear();
    m_dailyReportModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("收费单号")));
    m_dailyReportModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("收费日期")));
    m_dailyReportModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("应收金额")));
    m_dailyReportModel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("实收金额")));
    m_dailyReportModel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("欠款金额")));

    m_dailyReportModel->setItem(0, 4, NULL);
}

void ClinicDailyReport::setMyLayout()
{
    QGroupBox *topGroup = new QGroupBox("日结单信息");
    QGridLayout *topLeftLayout = new QGridLayout;
    topLeftLayout->addWidget(m_dailyReportNumLabel,0,0);
    topLeftLayout->addWidget(m_dailyReportNumEdit,0,1,1,2);
    topLeftLayout->addWidget(m_dateLabel,1,0);
    topLeftLayout->addWidget(m_dateEdit,1,1);
    topLeftLayout->addWidget(m_findButton,1,2);
    topGroup->setLayout(topLeftLayout);

    QGroupBox *IncomeGroup = new QGroupBox("合计信息");
    QGridLayout *IncomeLayout = new QGridLayout;
    IncomeLayout->addWidget(m_allDueIncomeLabel,0,0);
    IncomeLayout->addWidget(m_allDueIncomeEdit,0,1);
    IncomeLayout->addWidget(m_allRealIncomeLabel,1,0);
    IncomeLayout->addWidget(m_allRealIncomeEdit,1,1);
    IncomeLayout->addWidget(m_allDebtLabel,2,0);
    IncomeLayout->addWidget(m_allDebtEdit,2,1);
    IncomeGroup->setLayout(IncomeLayout);

    QVBoxLayout *LeftLayout = new QVBoxLayout;
    LeftLayout->addWidget(topGroup);
    LeftLayout->addWidget(IncomeGroup);
    LeftLayout->addStretch();

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(m_dailyReportView);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(LeftLayout);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(rightLayout,1);
    setLayout(mainLayout);
}

void ClinicDailyReport::setAllDefaultEnable()
{
    m_dailyReportNumEdit->setEnabled(false);
    m_allDueIncomeEdit->setEnabled(false);
    m_allRealIncomeEdit->setEnabled(false);
    m_allDebtEdit->setEnabled(false);

    m_dailyReportView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
