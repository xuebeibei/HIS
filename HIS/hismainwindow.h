#ifndef HISMAINWINDOW_H
#define HISMAINWINDOW_H

#include <QMainWindow>
#include "stdafx.h"
#include "cliniccharge.h"
#include "clinicdailyreport.h"

namespace Ui {
class HISMainWindow;
}

class HISMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit HISMainWindow(QWidget *parent = 0);
    ~HISMainWindow();
private slots:

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：showClinicCharge
    // 作用：菜单门诊-门诊收费响应项，显示门诊收费子窗口，并设置工具栏
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void showClinicCharge();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：showClinicDailyReport
    // 作用：菜单门诊-门诊日结响应项，显示门诊日结子窗口，并设置工具栏
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void showClinicDailyReport();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：newTableFile
    // 作用：工具栏-新建响应项，新建一个子窗口中的数据记录，并初始化子窗口中所有控件的值
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void newTableFile();
    void saveTableFile();
    void deleteTableFile();
    void exportTableFile();
    void findTableFile();
    void amendTableFile();
    void previewTableFile();
    void printTableFile();


private:

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：createActions
    // 作用：对菜单栏的子菜单和工具栏的选项进行创建
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void createActions();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：createMenus
    // 作用：创建主窗体的菜单栏
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void createMenus();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：createToolBars
    // 作用：创建主窗体的工具栏
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void createToolBars();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：initToolsAllEnable
    // 作用：将工具栏中的工具都设置为可用状态
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    void initToolsAllEnable();
private:
    Ui::HISMainWindow *ui;

    SubForm *subForm;                    // 子窗体

    QMenu *clinicMenu;                   // 门诊菜单

    QAction *clinicChargeAction;         // 门诊收费
    QAction *clinicDailyReportAction;    // 门诊日结

    QToolBar *fileToolBar;               // 包括：新建 保存 删除 导出
    QToolBar *editToolBar;               // 包括：查找 修改
    QToolBar *printToolBar;              // 包括：预览 打印

    QAction *newAction;                  // 新建
    QAction *saveAction;                 // 保存
    QAction *deleteAction;               // 删除
    QAction *exportAction;               // 导出

    QAction *findAction;                 // 查找
    QAction *amendAction;                // 修改

    QAction *previewAction;              // 预览
    QAction *printAction;                // 打印
};

#endif // HISMAINWINDOW_H
