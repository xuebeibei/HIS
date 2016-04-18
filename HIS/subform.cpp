#include "subform.h"
#include "ui_subform.h"
#include "stdafx.h"

SubForm::SubForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubForm)
{
    ui->setupUi(this);
    setMinimumWidth(nSubFormDefaultWidth);
    setMinimumHeight(nSubFormDefaultHeight);
}

SubForm::~SubForm()
{
    delete ui;
}
