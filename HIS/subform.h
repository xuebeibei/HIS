#ifndef SUBFORM_H
#define SUBFORM_H

#include <QWidget>

namespace Ui {
class SubForm;
}

class SubForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit SubForm(QWidget *parent = 0);
    ~SubForm();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：newTableFile
    // 作用：新建
    // 参数：无
    // 返回值：无
    // 备注：虚函数，具体操作需要子类实现
    // 时间：2016-04-15
    //-----------------------------------------------------------------------------------------------------------------------------------
    virtual void newTableFile() = 0;
    virtual void saveTableFile() = 0;
    virtual void deleteTableFile() = 0;
    virtual void exportTableFile() = 0;
    virtual void findTableFile() = 0;
    virtual void amendTableFile() = 0;
    virtual void previewTableFile() = 0;
    virtual void printTableFile() = 0;
    
private:
    Ui::SubForm *ui;
};

#endif // SUBFORM_H
