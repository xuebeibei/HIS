#include "clinicinternalpayment.h"

ClinicInternalPayment::ClinicInternalPayment()
{
}

QVector<InternalPaymentItem *> ClinicInternalPayment::selectFromDB(QDate startDate, QDate endDate)
{
    QVector<InternalPaymentItem *> result;
    QVector<QString> Receipt;
    if(myDB::connectDB())
    {
        QSqlQueryModel *sqlModel = new QSqlTableModel;
        sqlModel->setQuery("SELECT distinct ChinicReceipt FROM " + strClinicChargeDetails);

        for(int i = 0; i<sqlModel->rowCount();i++)
        {
            QSqlRecord record = sqlModel->record(i);
            QString strReceipt = record.value("ChinicReceipt").toString();
            Receipt.append(strReceipt);
        }

        for(int i=0;i<Receipt.size();i++)
        {
            InternalPaymentItem *item = new InternalPaymentItem;
            item->m_strName = Receipt.at(i);

            QString startTime = startDate.toString("yyyy-MM-dd") + "T00:00:00";
            QString endTime = endDate.toString("yyyy-MM-dd") + "T23:59:59";
            sqlModel->setQuery("Select * from " + strClinicChargeDetails +
                               " where ChinicReceipt = \'" + item->m_strName +
                               "\' and chargeid in (select id from cliniccharge where time between \'" +
                               startTime +
                               "\' and \'" +
                               endTime + "\')");
            for(int j = 0;j<sqlModel->rowCount();j++)
            {
                int nCount = sqlModel->record(j).value("ChargeItemCount").toInt();
                double nPrice = sqlModel->record(j).value("ChargeItemPrice").toDouble();
                item->m_dDueIncome += nCount*nPrice;
            }
            result.append(item);
        }
    }

    return result;
}
