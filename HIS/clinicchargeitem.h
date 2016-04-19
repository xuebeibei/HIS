#ifndef CLINICCHARGEITEM_H
#define CLINICCHARGEITEM_H
#include "stdafx.h"

class ClinicChargeItem
{
public:
    ClinicChargeItem();
    ClinicChargeItem(QString strChargeItemNo,
                     QString strChargeItemName,
                     int nChargeItemCount,
                     double dChargeItemPrice,
                     QString strClinicReceipt,
                     QString strClinicSort,
                     QString strClinicChargeId);
    ClinicChargeItem(ClinicChargeItem* chargeItem);

    QString getChargeItemNo() const;
    QString getChargeItemName() const;
    int getChargeItemCount() const;
    double getChargeItemPrice() const;
    QString getClinicReceipt() const;
    QString getClinicSort() const;
    QString getClinicChargeId() const;

    void setChargeItemNo(QString strChargeItemNo);
    void setChargeItemName(QString strChargeItemName);
    void setChargeItemCount(int nChargeItemCount);
    void setChargeItemPrice(double dChargeItemPrice);
    void setClinicReceipt(QString strClinicReceipt);
    void setClinicSort(QString strClinicSort);
    void setClinicChargeId(QString strClinicChargeId);
protected:
    QString m_strChargeItemNo;
    QString m_strChargeItemName;
    int m_nChargeItemCount;
    double m_dChargeItemPrice;
    QString m_strClinicReceipt;
    QString m_strClinicSort;
    QString m_strClinicChargeId;
};

#endif // CLINICCHARGEITEM_H
