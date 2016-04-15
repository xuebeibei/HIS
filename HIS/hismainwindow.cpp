#include "hismainwindow.h"
#include "ui_hismainwindow.h"

HISMainWindow::HISMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HISMainWindow)
{
    ui->setupUi(this);
    createActions();
    createToolBars();
    charge = new ClinicCharge;
    setCentralWidget(charge);
}

HISMainWindow::~HISMainWindow()
{
    delete ui;
}


void HISMainWindow::createActions()
{  
    newAction = new QAction(tr("新建"),this);
    saveAction = new QAction(tr("保存"),this);
    deleteAction = new QAction(tr("删除"),this);
    exportAction = new QAction(tr("导出"),this);
    findAction = new QAction(tr("查找"),this);
    amendAction = new QAction(tr("修改"),this);
    comboAction = new QAction(tr("套餐"),this);
    deleteRowAction = new QAction(tr("删除行"),this);
    previewAction = new QAction(tr("预览"),this);
    printAction = new QAction(tr("打印"),this);
}

void HISMainWindow::createMenus()
{

}

void HISMainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("文件"));                // 包括：新建 保存 删除 导出
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(saveAction);
    fileToolBar->addAction(deleteAction);
    fileToolBar->addAction(exportAction);

    editToolBar = addToolBar(tr("编辑"));                // 包括：查找 修改 删除行 套餐
    editToolBar->addAction(findAction);
    editToolBar->addAction(amendAction);
    editToolBar->addAction(comboAction);
    editToolBar->addAction(deleteRowAction);

    printToolBar = addToolBar(tr("打印"));               // 包括：预览 打印
    printToolBar->addAction(previewAction);
    printToolBar->addAction(printAction);
}

