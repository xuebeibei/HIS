#ifndef CLINICCHARGETABLE_H
#define CLINICCHARGETABLE_H
#include "histable.h"
#include "patient.h"


class ClinicChargeTable : public HISTable,public Patient
{
public:
    ClinicChargeTable();
    QString getID();
    double getDueIncome() const;
    double getRealImcome() const;
    QSqlTableModel* getChargeRecords() const;

    void setDueIncome(double d_DueIncome);
    void setRealIncome(double d_RealIncome);
    void setChargeRecords(QSqlTableModel *ChargeRecordsModel);

    bool Read();
    bool Save();
    void saveChargeRecords(QStandardItemModel *chargeRecordsmodel);
    bool Delete();
protected:
    bool findChargeTableByID(QString strId);
    bool findChargeRecordsByID(QString strId);


protected:
    QString m_strPrefixion;
    double m_dDueIncome;
    double m_dRealIncome;
    QSqlTableModel *m_ChargeModel; // 收费单
    QSqlTableModel *m_ChargeRecordsModel;


};

#endif // CLINICCHARGETABLE_H
