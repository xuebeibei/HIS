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
    newAction = new QAction(tr("新建"),this);                  // 新建

    saveAction = new QAction(tr("保存"),this);                 // 保存

    deleteAction = new QAction(tr("删除"),this);               // 删除

    exportAction = new QAction(tr("导出"),this);               // 导出

    findAction = new QAction(tr("查找"),this);                 // 查找

    amendAction = new QAction(tr("修改"),this);                // 修改

    comboAction = new QAction(tr("套餐"),this);                // 套餐

    deleteRowAction = new QAction(tr("删除行"),this);          // 删除行

    previewAction = new QAction(tr("预览"),this);              // 预览

    printAction = new QAction(tr("打印"),this);                // 打印
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

