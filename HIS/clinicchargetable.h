#ifndef CLINICCHARGETABLE_H
#define CLINICCHARGETABLE_H
#include "histable.h"
#include "patient.h"
#include "clinicchargeitem.h"

class ClinicChargeTable : public HISTable
{
public:
    ClinicChargeTable();
    QString getID();
    double getDueIncome() const;
    double getRealImcome() const;
    Patient getPatient() const;
    QVector<ClinicChargeItem*> getChargeItems() const;

    void setDueIncome(double d_DueIncome);
    void setRealIncome(double d_RealIncome);
    void setChargeItems(QVector<ClinicChargeItem*> chargeItems);
    void setPatient(Patient patient);

    bool Read(QString strId = "");
    bool Save();
    virtual bool Find(QString strId);
    bool Delete();
protected:
    bool readChargeTable(QString strId);
    bool ReadChargeRecords(QString strId);
    bool saveChargeRecords();
    bool saveChargeTable();

protected:
    QString m_strPrefixion;
    double m_dDueIncome;
    double m_dRealIncome;
    Patient m_patient;
    QVector<ClinicChargeItem*> m_chargeItems;
};

#endif // CLINICCHARGETABLE_H
