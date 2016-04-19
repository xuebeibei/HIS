#include "hismainwindow.h"
#include "ui_hismainwindow.h"

HISMainWindow::HISMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HISMainWindow)
{
    ui->setupUi(this);
    createActions();
    createMenus();
    createToolBars();
    showClinicCharge();
}

HISMainWindow::~HISMainWindow()
{
    delete ui;
}

void HISMainWindow::showClinicCharge()
{
    initToolsAllEnable();
    subForm = new ClinicCharge;
    setCentralWidget(subForm);

    deleteAction->setEnabled(false);
    //comboAction->setEnabled(false);
}

void HISMainWindow::showClinicDailyReport()
{
    initToolsAllEnable();
    subForm = new ClinicDailyReport;
    setCentralWidget(subForm);
}

void HISMainWindow::newTableFile()
{
    subForm->newTableFile();
}

void HISMainWindow::saveTableFile()
{
    subForm->saveTableFile();
}

void HISMainWindow::findTableFile()
{
    subForm->findTableFile();
}


void HISMainWindow::createActions()
{  

    clinicChargeAction = new QAction(strClinicChargeAction,this);
    connect(clinicChargeAction, SIGNAL(triggered()), this, SLOT(showClinicCharge()));

    clinicDailyReportAction = new QAction(strClinicDailyReportAction,this);
    connect(clinicDailyReportAction, SIGNAL(triggered()), this, SLOT(showClinicDailyReport()));

    newAction = new QAction(strNewAction,this);
    connect(newAction, SIGNAL(triggered()), this, SLOT(newTableFile()));

    saveAction = new QAction(strSaveAction,this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveTableFile()));

    deleteAction = new QAction(strDeleteAction,this);
    exportAction = new QAction(strExportAction,this);
    findAction = new QAction(strFindAction,this);
    connect(findAction, SIGNAL(triggered()), this, SLOT(findTableFile()));
    amendAction = new QAction(strAmendAction,this);

    previewAction = new QAction(strPreviewAction,this);
    printAction = new QAction(strPrintAction,this);
}

void HISMainWindow::createMenus()
{
    clinicMenu = menuBar()->addMenu(strClinicMenu);
    clinicMenu->addAction(clinicChargeAction);
    clinicMenu->addAction(clinicDailyReportAction);
}

void HISMainWindow::createToolBars()
{
    fileToolBar = addToolBar(strFileToolBar);
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(saveAction);
    fileToolBar->addAction(deleteAction);
    fileToolBar->addAction(exportAction);

    editToolBar = addToolBar(strEditToolBar);
    editToolBar->addAction(findAction);
    editToolBar->addAction(amendAction);
    //editToolBar->addAction(comboAction);
    //editToolBar->addAction(deleteRowAction);

    printToolBar = addToolBar(strPrintToolBar);
    printToolBar->addAction(previewAction);
    printToolBar->addAction(printAction);
}

void HISMainWindow::initToolsAllEnable()
{
    newAction->setEnabled(true);
    saveAction->setEnabled(true);
    deleteAction->setEnabled(true);
    exportAction->setEnabled(true);
    findAction->setEnabled(true);
    amendAction->setEnabled(true);
    //comboAction->setEnabled(true);
    //deleteRowAction->setEnabled(true);
    previewAction->setEnabled(true);
    printAction->setEnabled(true);
}

