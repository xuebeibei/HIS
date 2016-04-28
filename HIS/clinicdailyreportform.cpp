#include "clinicdailyreportform.h"
#include "clinicchargetable.h"

ClinicDailyReportFrom::ClinicDailyReportFrom(SubForm *parent) :
    SubForm(parent)
{
    create();
    setMyLayout();
    setAllDefaultEnable();
    init();
}

ClinicDailyReportFrom::~ClinicDailyReportFrom()
{

}

void ClinicDailyReportFrom::newTableFile()
{
    setAllDefaultEnable();
    QDate dTemp = m_dateEdit->date();
    m_dailyReportTable = new ClinicDailyReportTable;
    m_dailyReportTable->setDate(dTemp);
    Read();
}

bool ClinicDailyReportFrom::saveTableFile()
{
    if(Save())
    {
        QMessageBox::information(this,"提示","保存成功！");
        setAllUnEnable();
        showTodayReports();
        return true;
    }
    else
    {
        QMessageBox::information(this,"提示","保存失败！");
        return false;
    }

}

bool ClinicDailyReportFrom::deleteTableFile()
{
    QMessageBox *box = new QMessageBox;
    box->setWindowTitle(tr("警告"));
    box->setIcon(QMessageBox::Warning);
    box->setText(tr("确认删除？"));
    box->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    if(box->exec()==QMessageBox::Yes)
    {
        return Delete();
    }
    else
    {
        return false;
    }
}

void ClinicDailyReportFrom::exportTableFile()
{
    QMessageBox::information(this,"提示","导出 - 门诊日结");
}

bool ClinicDailyReportFrom::findTableFile()
{
    QMessageBox::information(this,"提示","查找 - 门诊日结 - 不可用");
    return true;
}

void ClinicDailyReportFrom::amendTableFile()
{
    QMessageBox::information(this,"提示","修改 - 门诊日结 - 不可用");
}

void ClinicDailyReportFrom::previewTableFile()
{
    QMessageBox::information(this,"提示","预览 - 门诊日结");
}

void ClinicDailyReportFrom::printTableFile()
{
    QMessageBox::information(this,"提示","打印 - 门诊日结");
}

void ClinicDailyReportFrom::onDateChanged()
{
    newTableFile();
}

void ClinicDailyReportFrom::updateIncome()
{
    double dAllDueIncome = 0.0;
    double dAllRealIncome = 0.0;

    for(int i = 0; i < m_dailyChargesModel->rowCount();i++)
    {
        QStandardItem *dueIncomeItem = m_dailyChargesModel->item(i,2);
        QStandardItem *realIncomeItem = m_dailyChargesModel->item(i,3);
        double dDueIncome  = (dueIncomeItem == NULL) ? 0 : dueIncomeItem->text().toDouble();
        double dRealIncome = (realIncomeItem == NULL) ? 0 : realIncomeItem->text().toDouble();
        dAllDueIncome += dDueIncome;
        dAllRealIncome += dRealIncome;
    }

    m_allDueIncomeEdit->setText(QString::number(dAllDueIncome));
    m_allRealIncomeEdit->setText(QString::number(dAllRealIncome));
    m_allDebtEdit->setText(QString::number(dAllDueIncome - dAllRealIncome));
}

void ClinicDailyReportFrom::create()
{
    m_dailyReportNumLabel = new QLabel("日结单号：");
    m_dailyReportNumEdit = new QLineEdit;

    m_dateLabel = new QLabel("日结日期：");
    m_dateEdit = new QDateEdit;
    m_dateEdit->setCalendarPopup(true);
    m_dateEdit->setMaximumDate(QDate::currentDate());
    connect(m_dateEdit, SIGNAL(dateChanged(QDate)), this, SLOT(onDateChanged()));
    connect(m_dateEdit,SIGNAL(dateChanged(QDate)),this, SLOT(showTodayReports()));

    m_allDueIncomeLabel = new QLabel("应收合计：");
    m_allRealIncomeLabel = new QLabel("实收合计：");
    m_allDebtLabel = new QLabel("欠款合计：");

    m_allDueIncomeEdit = new QLineEdit;
    m_allRealIncomeEdit = new QLineEdit;
    m_allDebtEdit = new QLineEdit;

    m_dailyReportsView = new QTableView;

    m_dailyChargesView = new QTableView;
    m_dailyChargesModel = new QStandardItemModel;
    m_dailyChargesView->setModel(m_dailyChargesModel);
    connect(m_dailyChargesModel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this, SLOT(updateIncome()));

    m_dailyReportsModel = new QStandardItemModel;
}

void ClinicDailyReportFrom::init()
{
    m_dailyReportNumEdit->setText(strNull);
    initTable();
    m_dateEdit->setDate(QDate::currentDate());
    showTodayReports();
}


void ClinicDailyReportFrom::initTable()
{
    m_dailyChargesModel->clear();
    m_dailyChargesModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("收费单号")));
    m_dailyChargesModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("收费时间")));
    m_dailyChargesModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("应收金额")));
    m_dailyChargesModel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("实收金额")));
    m_dailyChargesModel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("欠款金额")));
    m_dailyChargesModel->setItem(0, 4, NULL);

    m_dailyReportsModel->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("日结单号")));
    m_dailyReportsModel->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("应收款")));
    m_dailyReportsModel->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("实收款")));
}

void ClinicDailyReportFrom::showTodayReports()
{
    QVector<ClinicDailyReportTable*> record = ClinicDailyReportTable::getRecord(m_dateEdit->date(),m_dateEdit->date());

    for(int i = 0; i < record.size();i++)
    {
        ClinicDailyReportTable *table = record.at(i);
        m_dailyReportsModel->setItem(i,0,new QStandardItem(table->getId()));
        m_dailyReportsModel->setItem(i,1,new QStandardItem(QString::number(table->getAllDueIncome())));
        m_dailyReportsModel->setItem(i,2,new QStandardItem(QString::number(table->getAllRealIncome())));
    }
    m_dailyReportsView->setModel(m_dailyReportsModel);
}

void ClinicDailyReportFrom::setMyLayout()
{
    QGroupBox *topGroup = new QGroupBox("日结单信息");
    QGridLayout *topLeftLayout = new QGridLayout;
    topLeftLayout->addWidget(m_dailyReportNumLabel,0,0);
    topLeftLayout->addWidget(m_dailyReportNumEdit,0,1);
    topLeftLayout->addWidget(m_dateLabel,1,0);
    topLeftLayout->addWidget(m_dateEdit,1,1);
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
    LeftLayout->addWidget(m_dailyReportsView);
    LeftLayout->addStretch();

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(m_dailyChargesView);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(LeftLayout);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(rightLayout,1);
    setLayout(mainLayout);
}

void ClinicDailyReportFrom::setAllDefaultEnable()
{
    m_dailyReportNumEdit->setEnabled(false);
    m_allDueIncomeEdit->setEnabled(false);
    m_allRealIncomeEdit->setEnabled(false);
    m_allDebtEdit->setEnabled(false);
    m_dateEdit->setEnabled(true);

    m_dailyChargesView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void ClinicDailyReportFrom::setAllUnEnable()
{
    m_dailyReportNumEdit->setEnabled(false);
    m_allDueIncomeEdit->setEnabled(false);
    m_allRealIncomeEdit->setEnabled(false);
    m_allDebtEdit->setEnabled(false);
    m_dateEdit->setEnabled(false);

    m_dailyChargesView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

bool ClinicDailyReportFrom::Read()
{
    if(m_dailyReportTable->Read())
    {
        QString strId = m_dailyReportTable->getId();
        m_dailyReportNumEdit->setText(strId);
        m_dateEdit->setDate(m_dailyReportTable->getdate());

        m_allDueIncomeEdit->setText(QString::number(m_dailyReportTable->getAllDueIncome()));
        m_allRealIncomeEdit->setText(QString::number(m_dailyReportTable->getAllRealIncome()));
        m_allDebtEdit->setText(QString::number(m_dailyReportTable->getAllDebt()));

        initTable();
        for(int index = 0; index < m_dailyReportTable->getDailyReport().size(); index++)
        {
            ClinicChargeTable *charge = m_dailyReportTable->getDailyReport().at(index);

            m_dailyChargesModel->setItem(index, 0, new QStandardItem(charge->getID()));
            m_dailyChargesModel->setItem(index, 1, new QStandardItem(charge->getTime().toString("yyyy-MM-dd hh:mm:ss")));
            m_dailyChargesModel->setItem(index, 2, new QStandardItem(QString::number(charge->getDueIncome())));
            m_dailyChargesModel->setItem(index, 3, new QStandardItem(QString::number(charge->getRealImcome())));
            m_dailyChargesModel->setItem(index, 4, new QStandardItem(QString::number(charge->getDueIncome() - charge->getRealImcome())));
        }
        return true;
    }
    else
        return false;
}

bool ClinicDailyReportFrom::Save()
{
    m_dailyReportTable->setAllDueIncome(m_allDueIncomeEdit->text().toDouble());
    m_dailyReportTable->setAllRealIncome(m_allRealIncomeEdit->text().toDouble());
    m_dailyReportTable->setAllDebt(m_allDebtEdit->text().toDouble());
    return m_dailyReportTable->Save();
}

bool ClinicDailyReportFrom::Delete()
{

    if(m_dailyReportTable->Delete())
    {
        newTableFile();
        QMessageBox::information(this,"提示","删除成功！");
        showTodayReports();
        return true;
    }
    else
    {
        QMessageBox::information(this,"提示","删除失败！");
        return false;
    }
}
