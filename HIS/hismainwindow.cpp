#include "hismainwindow.h"

HISMainWindow::HISMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createActions();
    createMenus();
    createToolBars();
    showClinicCharge();
}

HISMainWindow::~HISMainWindow()
{

}

void HISMainWindow::showClinicCharge()
{
    initToolsAllEnable();
    subForm = new ClinicChargeForm;
    setCentralWidget(subForm);

    saveAction->setEnabled(true);
    deleteAction->setEnabled(false);
    amendAction->setEnabled(false);
}

void HISMainWindow::showClinicDailyReport()
{
    initToolsAllEnable();
    subForm = new ClinicDailyReportFrom;
    setCentralWidget(subForm);

    saveAction->setEnabled(true);
    deleteAction->setEnabled(false);
    amendAction->setEnabled(false);
    findAction->setEnabled(false);
}

void HISMainWindow::showClinicInternalPayment()
{
    initToolsAllEnable();
    subForm = new ClinicInternalPaymentForm;
    setCentralWidget(subForm);

    newAction->setEnabled(false);
    deleteAction->setEnabled(false);
    amendAction->setEnabled(false);
    findAction->setEnabled(false);
    saveAction->setEnabled(false);
}

void HISMainWindow::showChargeStatistic()
{
    initToolsAllEnable();
    subForm = new ClinicChargeStatisticForm;
    setCentralWidget(subForm);

    newAction->setEnabled(false);
    deleteAction->setEnabled(false);
    amendAction->setEnabled(false);
    findAction->setEnabled(false);
    saveAction->setEnabled(false);
}

void HISMainWindow::showReportStatistic()
{
    initToolsAllEnable();
    subForm = new ClinicReportStatisticForm;
    setCentralWidget(subForm);

    newAction->setEnabled(false);
    deleteAction->setEnabled(false);
    amendAction->setEnabled(false);
    findAction->setEnabled(false);
    saveAction->setEnabled(false);
}

void HISMainWindow::showPaymentStatistic()
{
    initToolsAllEnable();
    subForm = new ClinicPaymentStatisticForm;
    setCentralWidget(subForm);

    newAction->setEnabled(false);
    deleteAction->setEnabled(false);
    amendAction->setEnabled(false);
    findAction->setEnabled(false);
    saveAction->setEnabled(false);
}

void HISMainWindow::newTableFile()
{
    subForm->newTableFile();

    saveAction->setEnabled(true);
    deleteAction->setEnabled(false);
    amendAction->setEnabled(false);
}

void HISMainWindow::saveTableFile()
{
    if(subForm->saveTableFile())
    {
        saveAction->setEnabled(false);
        deleteAction->setEnabled(true);
        amendAction->setEnabled(true);
    }
}

void HISMainWindow::deleteTableFile()
{
    subForm->deleteTableFile();
    saveAction->setEnabled(true);
    deleteAction->setEnabled(false);
    amendAction->setEnabled(false);
}

void HISMainWindow::exportTableFile()
{
    subForm->exportTableFile();
}

void HISMainWindow::findTableFile()
{
    if(subForm->findTableFile())
    {
        saveAction->setEnabled(false);
        deleteAction->setEnabled(true);
        amendAction->setEnabled(true);
    }
}

void HISMainWindow::amendTableFile()
{
    subForm->amendTableFile();

    saveAction->setEnabled(true);
    deleteAction->setEnabled(true);
    amendAction->setEnabled(false);
}

void HISMainWindow::previewTableFile()
{
    subForm->previewTableFile();
}

void HISMainWindow::printTableFile()
{
    subForm->printTableFile();
}

void HISMainWindow::createActions()
{  
    clinicChargeAction = new QAction(strClinicChargeAction,this);
    connect(clinicChargeAction, SIGNAL(triggered()), this, SLOT(showClinicCharge()));

    clinicDailyReportAction = new QAction(strClinicDailyReportAction,this);
    connect(clinicDailyReportAction, SIGNAL(triggered()), this, SLOT(showClinicDailyReport()));

    clinicInternalPaymentAction = new QAction(strClinicInternalPaymentAction,this);
    connect(clinicInternalPaymentAction, SIGNAL(triggered()), this, SLOT(showClinicInternalPayment()));

    clinicChargeStatisticAction = new QAction(strClinicChargeStatisticAction,this);
    connect(clinicChargeStatisticAction, SIGNAL(triggered()), this, SLOT(showChargeStatistic()));

    clinicReportStatisticAction = new QAction(strClinicReportStatisticAction,this);
    connect(clinicReportStatisticAction, SIGNAL(triggered()), this, SLOT(showReportStatistic()));

    clinicPaymentStatisticAction = new QAction(strClinicPaymentStatisticAction,this);
    connect(clinicPaymentStatisticAction, SIGNAL(triggered()), this, SLOT(showPaymentStatistic()));

    newAction = new QAction(strNewAction,this);
    connect(newAction, SIGNAL(triggered()), this, SLOT(newTableFile()));

    saveAction = new QAction(strSaveAction,this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveTableFile()));

    deleteAction = new QAction(strDeleteAction,this);
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteTableFile()));

    exportAction = new QAction(strExportAction,this);
    connect(exportAction, SIGNAL(triggered()), this, SLOT(exportTableFile()));

    findAction = new QAction(strFindAction,this);
    connect(findAction, SIGNAL(triggered()), this, SLOT(findTableFile()));

    amendAction = new QAction(strAmendAction,this);
    connect(amendAction, SIGNAL(triggered()), this, SLOT(amendTableFile()));

    previewAction = new QAction(strPreviewAction,this);
    connect(previewAction, SIGNAL(triggered()), this, SLOT(previewTableFile()));

    printAction = new QAction(strPrintAction,this);
    connect(printAction, SIGNAL(triggered()), this, SLOT(printTableFile()));
}

void HISMainWindow::createMenus()
{
    clinicMenu = menuBar()->addMenu(strClinicMenu);
    clinicMenu->addAction(clinicChargeAction);
    clinicMenu->addAction(clinicDailyReportAction);
    clinicMenu->addAction(clinicInternalPaymentAction);
    clinicStatistics = new QMenu("统计查询");
    clinicMenu->addMenu(clinicStatistics);

    clinicStatistics->addAction(clinicChargeStatisticAction);
    clinicStatistics->addAction(clinicReportStatisticAction);
    clinicStatistics->addAction(clinicPaymentStatisticAction);
}

void HISMainWindow::createToolBars()
{
    fileToolBar = addToolBar(strFileToolBar);
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(saveAction);
    fileToolBar->addAction(deleteAction);
    //fileToolBar->addAction(exportAction);

    editToolBar = addToolBar(strEditToolBar);
    editToolBar->addAction(findAction);
    editToolBar->addAction(amendAction);

    //printToolBar = addToolBar(strPrintToolBar);
    //printToolBar->addAction(previewAction);
    //printToolBar->addAction(printAction);
}

void HISMainWindow::initToolsAllEnable()
{
    newAction->setEnabled(true);
    saveAction->setEnabled(true);
    deleteAction->setEnabled(true);
    exportAction->setEnabled(true);
    findAction->setEnabled(true);
    amendAction->setEnabled(true);
    previewAction->setEnabled(true);
    printAction->setEnabled(true);
}
