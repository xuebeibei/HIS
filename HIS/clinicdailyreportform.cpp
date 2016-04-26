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
    QMessageBox::information(this,"提示","查找 - 门诊日结");
    return true;
}

void ClinicDailyReportFrom::amendTableFile()
{
    QMessageBox::information(this,"提示","修改 - 门诊日结");
}

void ClinicDailyReportFrom::previewTableFile()
{
    QMessageBox::information(this,"提示","预览 - 门诊日结");
}

void ClinicDailyReportFrom::printTableFile()
{
    QMessageBox::information(this,"提示","打印 - 门诊日结");
}

void ClinicDailyReportFrom::find()
{
    newTableFile();
}

void ClinicDailyReportFrom::updateIncome()
{
    double dAllDueIncome = 0.0;
    double dAllRealIncome = 0.0;

    for(int i = 0; i < m_dailyReportModel->rowCount();i++)
    {
        QStandardItem *dueIncomeItem = m_dailyReportModel->item(i,2);
        QStandardItem *realIncomeItem = m_dailyReportModel->item(i,3);

        double dDueIncome = (realIncomeItem == NULL) ? 0 : realIncomeItem->text().toDouble();
        double dRealIncome = (dueIncomeItem == NULL) ? 0 : dueIncomeItem->text().toInt();

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
    connect(m_dateEdit, SIGNAL(dateChanged(QDate)), this, SLOT(find()));

    m_allDueIncomeLabel = new QLabel("应收合计：");
    m_allRealIncomeLabel = new QLabel("实收合计：");
    m_allDebtLabel = new QLabel("欠款合计：");

    m_allDueIncomeEdit = new QLineEdit;
    m_allRealIncomeEdit = new QLineEdit;
    m_allDebtEdit = new QLineEdit;

    m_dailyReportView = new QTableView;
    m_dailyReportModel = new QStandardItemModel;
    m_dailyReportView->setModel(m_dailyReportModel);
    connect(m_dailyReportModel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this, SLOT(updateIncome()));
}

void ClinicDailyReportFrom::init()
{
    m_dailyReportNumEdit->setText(strNull);
    initTable();
    m_dateEdit->setDate(QDate::currentDate());
}

void ClinicDailyReportFrom::initTable()
{
    m_dailyReportModel->clear();
    m_dailyReportModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("收费单号")));
    m_dailyReportModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("收费日期")));
    m_dailyReportModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("应收金额")));
    m_dailyReportModel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("实收金额")));
    m_dailyReportModel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("欠款金额")));

    m_dailyReportModel->setItem(0, 4, NULL);
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
    LeftLayout->addStretch();

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(m_dailyReportView);

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

    m_dailyReportView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void ClinicDailyReportFrom::setAllUnEnable()
{
    m_dailyReportNumEdit->setEnabled(false);
    m_allDueIncomeEdit->setEnabled(false);
    m_allRealIncomeEdit->setEnabled(false);
    m_allDebtEdit->setEnabled(false);
    m_dateEdit->setEnabled(false);

    m_dailyReportView->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
        for(int index = 0; index < m_dailyReportTable->getdailyReport().size(); index++)
        {
            QString item = m_dailyReportTable->getdailyReport().at(index);
            ClinicChargeTable charge;
            charge.setID(item);
            charge.Read();

            m_dailyReportModel->setItem(index, 0, new QStandardItem(charge.getID()));
            m_dailyReportModel->setItem(index, 1, new QStandardItem(charge.getTime().toString("yyyy-MM-dd hh:mm:ss")));
            m_dailyReportModel->setItem(index, 2, new QStandardItem(QString::number(charge.getDueIncome())));
            m_dailyReportModel->setItem(index, 3, new QStandardItem(QString::number(charge.getRealImcome())));
            m_dailyReportModel->setItem(index, 4, new QStandardItem(QString::number(charge.getDueIncome() - charge.getRealImcome())));
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
        return true;
    }
    else
    {
        QMessageBox::information(this,"提示","删除失败！");
        return false;
    }
}
