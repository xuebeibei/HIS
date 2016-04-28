#ifndef CLINICPAYMENTSTATISTICFORM_H
#define CLINICPAYMENTSTATISTICFORM_H

#include <QWidget>
#include "stdafx.h"
#include "subform.h"
#include "connectDB.h"

class ClinicPaymentStatisticForm : public SubForm
{
    Q_OBJECT
    
public:
    explicit ClinicPaymentStatisticForm(SubForm *parent = 0);
    ~ClinicPaymentStatisticForm();

    void newTableFile();
    bool saveTableFile();
    bool deleteTableFile();
    void exportTableFile();
    bool findTableFile();
    void amendTableFile();
    void previewTableFile();
    void printTableFile();

    void create();
    void setMyLayout();
    void init();
    void initTable();

protected slots:
    void updateTable();
    void setConditionSort();
    void setConditionWho();
    void setStartDate();
    void setEndDate();

protected:
    QLabel *m_startDateLabel;
    QDateEdit *m_startDateEdit;
    QLabel *m_endDateLabel;
    QDateEdit *m_endDateEdit;

    QButtonGroup *m_conditionSortBtnGroup;
    QButtonGroup *m_conditionWhoBtnGroup;

    QGroupBox *m_conditionSortGroup;
    QRadioButton *m_clinicReceiptRadio;
    QRadioButton *m_clinicSortRadio;

    QGroupBox *m_conditionWhoGroup;
    QRadioButton *m_departmentRadio;
    QRadioButton *m_doctorRadio;
    QRadioButton *m_makerRadio;

    QTableView *m_resultView;
    QStandardItemModel *m_resultModel;

    QString m_strConditionSort;
    QString m_strConditionWho;
    QDate m_startDate;
    QDate m_endDate;
};

#endif // CLINICPAYMENTSTATISTICFORM_H
