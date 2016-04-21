#include "clinicdailyreport.h"

ClinicDailyReport::ClinicDailyReport(SubForm *parent) :
    SubForm(parent)
{
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
