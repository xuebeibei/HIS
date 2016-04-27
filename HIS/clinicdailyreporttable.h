#ifndef CLINICDAILYREOPRTTABLE_H
#define CLINICDAILYREOPRTTABLE_H

#include "stdafx.h"
#include "histable.h"
#include "clinicchargetable.h"
#include "connectDB.h"

//-----------------------------------------------------------------------------------------------------------------------------------
// 门诊日结单类 - 数据类
//-----------------------------------------------------------------------------------------------------------------------------------
class ClinicDailyReportTable : public HISTable
{
public:
    ClinicDailyReportTable();
    bool Read();
    bool Save();
    bool Delete();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getId
    // 作用：得到门诊日结单的单号
    // 参数：无
    // 返回值：
    // QString - 日结单单号
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    QString getId() const;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getPrefixion
    // 作用：得到门诊日结单的单号前缀
    // 参数：无
    // 返回值：
    // QString - 门诊日结单的单号前缀
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    QString getPrefixion() const;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getAllDueIncome
    // 作用：得到日结单的应收款合计
    // 参数：无
    // 返回值：
    // double - 日记单的应收款合计
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    double getAllDueIncome() const;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getAllRealIncome
    // 作用：得到日结单的实收款合计
    // 参数：无
    // 返回值：
    // double - 日结单的实收合计
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    double getAllRealIncome() const;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getAllDebt
    // 作用：得到日结单的欠款合计
    // 参数：无
    // 返回值：
    // double - 日结单的欠款合计
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    double getAllDebt() const;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getdate
    // 作用：得到日结单的门诊收费单的筛选日期
    // 参数：无
    // 返回值：无
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    QDate getdate() const;

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getDailyReport
    // 作用：得到日结单中收费单明细
    // 参数：无
    // 返回值：
    // QVector<ClinicChargeTable*>
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    QVector<ClinicChargeTable*> getDailyReport() const;


    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setId
    // 作用：设置ID
    // 参数：
    // strId - 日结单ID
    // 返回值：无
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setId(QString strId);

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setPrefixion
    // 作用：设置日结单单号前缀
    // 参数：
    // strPrefixion - 日结单前缀
    // 返回值：无
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setPrefixion(QString strPrefixion);

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setAllDueIncome
    // 作用：设置日结单应收合计
    // 参数：
    // dAllDueIncome - 应收合计
    // 返回值：无
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setAllDueIncome(double dAllDueIncome);

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setAllRealIncome
    // 作用：设置日结单实收合计
    // 参数：
    // dAllRealIncome - 实收合计
    // 返回值：无
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setAllRealIncome(double dAllRealIncome);

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setAllDebt
    // 作用：设置日结单欠款合计
    // 参数：
    // dAllDebt - 欠款合计
    // 返回值：无
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setAllDebt(double dAllDebt);

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setDate
    // 作用：设置日结单的门诊收费单的筛选日期
    // 参数：
    // date - 日期
    // 返回值：无
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setDate(QDate date);

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：setDailyReport
    // 作用：设置日结单中收费单明细
    // 参数：
    // dailyReport - 收费单明细列表
    // 返回值：无
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    void setDailyReport(QVector<ClinicChargeTable*> dailyReport);


    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：getRecord
    // 作用：得到当天日结历史记录
    // 参数：无
    // 返回值：
    // QVector<ClinicDailyReportTable*> - 日结单记录列表
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    static QVector<ClinicDailyReportTable*> getRecord(QDate date);
protected:

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：selectClinicChargesByDate
    // 作用：从数据库中根据日期筛选出当天的收费单
    // 参数：
    // date - 日期
    // 返回值：
    // true  - 成功
    // false - 失败
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    bool selectClinicChargesByDate(QDate date);

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：readDailyReport
    // 作用：从数据库中读取已经存储的日结单
    // 参数：无
    // 返回值：
    // true  - 成功
    // false - 失败
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    bool readDailyReport();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：saveDailyReport
    // 作用：将日结单保存到数据库中
    // 参数：无
    // 返回值：
    // true  - 成功
    // false - 失败
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    bool saveDailyReport();

    //-----------------------------------------------------------------------------------------------------------------------------------
    // 名称：deleteDailyReport
    // 作用：从数据库中删除日结单
    // 参数：无
    // 返回值：
    // true  - 成功
    // false - 失败
    // 备注：无
    // 时间：2016-04-27
    //-----------------------------------------------------------------------------------------------------------------------------------
    bool deleteDailyReport();
protected:
    QString m_strId;                                                    // 日结单单号
    QString m_strPrefixion;                                             // 日结单单号前缀
    double m_dAllDueIncome;                                             // 应收合计
    double m_dAllRealIncome;                                            // 实收合计
    double m_dAllDebt;                                                  // 欠款合计 = 应收合计 - 实收合计
    QDate m_date;                                                       // 制单日期
    QVector<ClinicChargeTable*> m_vecDailyReportDetails;                // 结单内容
    QString m_strMaker;
};

#endif // CLINICDAILYREOPRTTABLE_H
