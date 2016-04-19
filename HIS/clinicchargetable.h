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
    QString getNewClinicChargeID();
    double getDueIncome() const;
    double getRealImcome() const;
    Patient getPatient() const;
    QVector<ClinicChargeItem*> getChargeItems() const;

    void setID(QString strID);
    void setDueIncome(double d_DueIncome);
    void setRealIncome(double d_RealIncome);
    void setChargeItems(QVector<ClinicChargeItem*> chargeItems);
    void setPatient(Patient patient);

    bool Read();
    bool Save();
    bool Delete();
protected:
    bool readChargeTable();
    bool ReadChargeRecords();
    bool saveChargeRecords();
    bool saveChargeTable();
    bool deleteChargeTable();
    bool deleteChargeRecords();


protected:
    QString m_strID;
    QString m_strPrefixion;
    double m_dDueIncome;
    double m_dRealIncome;
    Patient m_patient;
    QVector<ClinicChargeItem*> m_chargeItems;
};

#endif // CLINICCHARGETABLE_H
