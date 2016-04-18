#ifndef CLINICDAILYREPORT_H
#define CLINICDAILYREPORT_H

#include <QWidget>
#include "stdafx.h"
#include "subform.h"

namespace Ui {
class ClinicDailyReport;
}

class ClinicDailyReport : public SubForm
{
    Q_OBJECT
    
public:
    explicit ClinicDailyReport(SubForm *parent = 0);
    ~ClinicDailyReport();
public slots:
    void newTableFile();
    void saveTableFile();
    void findTableFile();
    
private:
    Ui::ClinicDailyReport *ui;
};

#endif // CLINICDAILYREPORT_H
