#ifndef FINDCLINCCHARGEDLG_H
#define FINDCLINCCHARGEDLG_H

#include <QDialog>
#include "stdafx.h"

namespace Ui {
class FindClincChargeDlg;
}

class FindClincChargeDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit FindClincChargeDlg(QWidget *parent = 0);
    ~FindClincChargeDlg();
    QString getId();
    
protected:
    void create();
    void setMyLayout();
    void init();

private:
    Ui::FindClincChargeDlg *ui;

    QLabel *m_chargeNumLabel;
    QLabel *m_nameLabel;
    QLabel *m_genderLabel;

    QLineEdit *m_chargeNumEdit;
    QLineEdit *m_nameEdit;

    QComboBox *m_genderComboBox;
    QTableView *m_resultsTableView;

    QStandardItemModel *m_resultsModel;

    QToolButton *m_findButton;
    QPushButton *m_choiseButton;
    QPushButton *m_cancelButton;

    QString m_strId;
};

#endif // FINDCLINCCHARGEDLG_H
