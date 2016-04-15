#include "clinicdailyreport.h"
#include "ui_clinicdailyreport.h"

ClinicDailyReport::ClinicDailyReport(SubForm *parent) :
    SubForm(parent),
    ui(new Ui::ClinicDailyReport)
{
    ui->setupUi(this);
}

ClinicDailyReport::~ClinicDailyReport()
{
    delete ui;
}

void ClinicDailyReport::newTableFile()
{
    QMessageBox::information(this,"提示","门诊日结");
}
