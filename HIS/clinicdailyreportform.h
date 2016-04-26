#ifndef CLINICDAILYREPORT_H
#define CLINICDAILYREPORT_H

#include <QWidget>
#include "stdafx.h"
#include "subform.h"
#include "clinicdailyreporttable.h"


//-----------------------------------------------------------------------------------------------------------------------------------
// 门诊日结界面类
//-----------------------------------------------------------------------------------------------------------------------------------
class ClinicDailyReportFrom : public SubForm
{
    Q_OBJECT
    
public:
    explicit ClinicDailyReportFrom(SubForm *parent = 0);
    ~ClinicDailyReportFrom();
public slots:
    void newTableFile();
    bool saveTableFile();
    bool deleteTableFile();
    void exportTableFile();
    bool findTableFile();
    void amendTableFile();
    void previewTableFile();
    void printTableFile();
public slots:
    void find();
    void updateIncome();
protected:
    void create();
    void init();
    void initTable();
    void setMyLayout();
    void setAllDefaultEnable();
    void setAllUnEnable();

    bool Read();
    bool Save();
    bool Delete();
protected:
    QLabel *m_dailyReportNumLabel;
    QLineEdit *m_dailyReportNumEdit;

    QLabel *m_dateLabel;
    QDateEdit *m_dateEdit;

    QLabel *m_allDueIncomeLabel;
    QLabel *m_allRealIncomeLabel;
    QLabel *m_allDebtLabel;

    QLineEdit *m_allDueIncomeEdit;
    QLineEdit *m_allRealIncomeEdit;
    QLineEdit *m_allDebtEdit;

    QTableView *m_dailyReportView;
    QStandardItemModel *m_dailyReportModel;

    ClinicDailyReportTable *m_dailyReportTable;
};

#endif // CLINICDAILYREPORT_H
