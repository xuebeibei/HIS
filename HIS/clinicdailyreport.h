#ifndef CLINICDAILYREPORT_H
#define CLINICDAILYREPORT_H

#include <QWidget>
#include "stdafx.h"
#include "subform.h"


//-----------------------------------------------------------------------------------------------------------------------------------
// 门诊日结界面类
//-----------------------------------------------------------------------------------------------------------------------------------
class ClinicDailyReport : public SubForm
{
    Q_OBJECT
    
public:
    explicit ClinicDailyReport(SubForm *parent = 0);
    ~ClinicDailyReport();
public slots:
    void newTableFile();
    bool saveTableFile();
    void deleteTableFile();
    void exportTableFile();
    bool findTableFile();
    void amendTableFile();
    void previewTableFile();
    void printTableFile();
public slots:
    void find();
protected:
    void create();
    void init();
    void initTable();
    void setMyLayout();
    void setAllDefaultEnable();
protected:
    QLabel *m_dailyReportNumLabel;
    QLineEdit *m_dailyReportNumEdit;

    QLabel *m_dateLabel;
    QDateEdit *m_dateEdit;

    QToolButton *m_findButton;

    QLabel *m_allDueIncomeLabel;
    QLabel *m_allRealIncomeLabel;
    QLabel *m_allDebtLabel;

    QLineEdit *m_allDueIncomeEdit;
    QLineEdit *m_allRealIncomeEdit;
    QLineEdit *m_allDebtEdit;


    QTableView *m_dailyReportView;
    QStandardItemModel *m_dailyReportModel;
};

#endif // CLINICDAILYREPORT_H
