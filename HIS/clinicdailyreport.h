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
    void deleteTableFile();
    void exportTableFile();
    void findTableFile();
    void amendTableFile();
    void previewTableFile();
    void printTableFile();
    
private:
    Ui::ClinicDailyReport *ui;
};

#endif // CLINICDAILYREPORT_H
