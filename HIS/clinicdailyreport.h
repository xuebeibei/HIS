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
};

#endif // CLINICDAILYREPORT_H
