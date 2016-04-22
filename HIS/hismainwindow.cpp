#include "hismainwindow.h"

HISMainWindow::HISMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createActions();
    createMenus();
    createToolBars();
    //showClinicCharge();
    showClinicDailyReport();
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
//    QPrinter   printer( QPrinter::PrinterResolution );
//    QPrintDialog   dialog( &printer, this );
//    if ( dialog.exec() == QDialog::Accepted ) print( &printer );
    subForm->printTableFile();
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
    previewAction->setEnabled(true);
    printAction->setEnabled(true);
}

