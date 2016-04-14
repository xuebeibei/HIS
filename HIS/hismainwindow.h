#ifndef HISMAINWINDOW_H
#define HISMAINWINDOW_H

#include <QMainWindow>
#include "stdafx.h"
#include "cliniccharge.h"

namespace Ui {
class HISMainWindow;
}

class HISMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit HISMainWindow(QWidget *parent = 0);
    ~HISMainWindow();

private:
    void createActions();
    void createMenus();
    void createToolBars();
private:
    Ui::HISMainWindow *ui;
    ClinicCharge *charge;

    QToolBar *fileToolBar;                // 包括：新建 保存 删除 导出
    QToolBar *editToolBar;                // 包括：查找 修改 删除行 套餐
    QToolBar *printToolBar;               // 包括：预览 打印

    QAction *newAction;                  // 新建
    QAction *saveAction;                 // 保存
    QAction *deleteAction;               // 删除
    QAction *exportAction;               // 导出

    QAction *findAction;                 // 查找
    QAction *amendAction;                // 修改
    QAction *comboAction;                // 套餐
    QAction *deleteRowAction;            // 删除行

    QAction *previewAction;              // 预览
    QAction *printAction;                // 打印

};

#endif // HISMAINWINDOW_H
