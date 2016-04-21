#ifndef FINDCLINCCHARGEDLG_H
#define FINDCLINCCHARGEDLG_H

#include <QDialog>
#include "stdafx.h"

//-----------------------------------------------------------------------------------------------------------------------------------
// 门诊收费 - 查找 - 界面类
//-----------------------------------------------------------------------------------------------------------------------------------
class FindClincChargeDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit FindClincChargeDlg(QWidget *parent = 0);
    ~FindClincChargeDlg();
    QString getId();
    
protected:

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：create
    // 作用：创建界面控件
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    void create();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setMyLayout
    // 作用：设置界面布局
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setMyLayout();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：init
    // 作用：初始化界面控件的值
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-20
    //-----------------------------------------------------------------------------------------------------------------------------------
    void init();

private:
    QLabel *m_chargeNumLabel;            // 门诊收费单单号
    QLabel *m_nameLabel;                 // 患者姓名
    QLabel *m_genderLabel;               // 患者性别

    QLineEdit *m_chargeNumEdit;          // 门诊收费单单号
    QLineEdit *m_nameEdit;               // 患者姓名

    QComboBox *m_genderComboBox;         // 患者性别
    QTableView *m_resultsTableView;      // 搜索结果列表

    QStandardItemModel *m_resultsModel;  // 搜索结果列表

    QToolButton *m_findButton;           // 查找按钮
    QPushButton *m_choiseButton;         // 选择按钮
    QPushButton *m_cancelButton;         // 取消按钮

    QString m_strId;                     // 最终选择的收费单的单号
};

#endif // FINDCLINCCHARGEDLG_H
