#ifndef CLINICDAILYREOPRTTABLE_H
#define CLINICDAILYREOPRTTABLE_H

#include "stdafx.h"
#include "histable.h"
#include "clinicchargetable.h"
#include "connectDB.h"

class ClinicDailyReportTable : public HISTable
{
public:
    ClinicDailyReportTable();
    bool Read();
    bool Save();
    bool Delete();

    QString getId() const;
    QString getPrefixion() const;
    double getAllDueIncome() const;
    double getAllRealIncome() const;
    double getAllDebt() const;
    QDate getdate() const;
    QStringList getdailyReport() const;

    void setId(QString strId);
    void setPrefixion(QString strPrefixion);
    void setAllDueIncome(double dAllDueIncome);
    void setAllRealIncome(double dAllRealIncome);
    void setAllDebt(double dAllDebt);
    void setDate(QDate date);
    void setDailyReport(QStringList dailyReport);
protected:
    bool readCharges();
    bool readDailyReport();
protected:
    QString m_strId;                          // 日结单单号
    QString m_strPrefixion;                   // 日结单单号前缀
    double m_dAllDueIncome;                   // 应收合计
    double m_dAllRealIncome;                  // 实收合计
    double m_dAllDebt;                        // 欠款合计 = 应收合计 - 实收合计
    QDate m_date;                             // 制单日期
    QStringList m_listCharges;                // 结单内容
    QString m_strMaker;
};

#endif // CLINICDAILYREOPRTTABLE_H
