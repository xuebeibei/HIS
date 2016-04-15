#include "subform.h"
#include "ui_subform.h"

SubForm::SubForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubForm)
{
    ui->setupUi(this);
}

SubForm::~SubForm()
{
    delete ui;
}
