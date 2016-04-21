#include "subform.h"
#include "stdafx.h"

SubForm::SubForm(QWidget *parent) :
    QWidget(parent)
{
    setMinimumWidth(nSubFormDefaultWidth);
    setMinimumHeight(nSubFormDefaultHeight);
}

SubForm::~SubForm()
{
}
