#include "clinicdailyreporttable.h"

ClinicDailyReportTable::ClinicDailyReportTable()
{
    m_strId = strDailyReopotNumPR + getNewID();
    m_strPrefixion = strDailyReopotNumPR;
    m_dAllDueIncome = 0;
    m_dAllRealIncome = 0;
    m_dAllDebt = 0;
    m_date = QDate::currentDate();
    m_strMaker = "A";
}

bool ClinicDailyReportTable::Read()
{
    readDailyReport();
    selectClinicChargesByDate(m_date);
    return true;
}

bool ClinicDailyReportTable::Save()
{
    return saveDailyReport();
}

bool ClinicDailyReportTable::Delete()
{
    return deleteDailyReport();
}

QString ClinicDailyReportTable::getId() const
{
    return m_strId;
}

QString ClinicDailyReportTable::getPrefixion() const
{
    return m_strPrefixion;
}

double ClinicDailyReportTable::getAllDueIncome() const
{
    return m_dAllDueIncome;
}

double ClinicDailyReportTable::getAllRealIncome() const
{
    return m_dAllRealIncome;
}

double ClinicDailyReportTable::getAllDebt() const
{
    return m_dAllDebt;
}

QDate ClinicDailyReportTable::getdate() const
{
    return m_date;
}

QVector<ClinicChargeTable*> ClinicDailyReportTable::getDailyReport() const
{
    return m_vecDailyReportDetails;
}

void ClinicDailyReportTable::setId(QString strId)
{
    this->m_strId = strId;
}

void ClinicDailyReportTable::setPrefixion(QString strPrefixion)
{
    this->m_strPrefixion = strPrefixion;
}

void ClinicDailyReportTable::setAllDueIncome(double dAllDueIncome)
{
    this->m_dAllDueIncome = dAllDueIncome;
}

void ClinicDailyReportTable::setAllRealIncome(double dAllRealIncome)
{
    this->m_dAllRealIncome = dAllRealIncome;
}

void ClinicDailyReportTable::setAllDebt(double dAllDebt)
{
    this->m_dAllDebt = dAllDebt;
}

void ClinicDailyReportTable::setDate(QDate date)
{
    this->m_date = date;
}

void ClinicDailyReportTable::setDailyReport(QVector<ClinicChargeTable*> vecDailyReportDetails)
{
    m_vecDailyReportDetails.clear();
    for(int i = 0; i < vecDailyReportDetails.size(); i++)
    {
        ClinicChargeTable *chargeTable = vecDailyReportDetails.at(i);
        m_vecDailyReportDetails.append(chargeTable);
    }
}

QVector<ClinicDailyReportTable*> ClinicDailyReportTable::getRecord(QDate startDate, QDate endDate)
{
    QVector<ClinicDailyReportTable*> list;
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable(strClinicDailyReport);
        QString strStartTime = startDate.toString("yyyy-MM-dd") + "T00:00:00";
        QString strEndTime = endDate.toString("yyyy-MM-dd") + "T23:59:59";
        model->setFilter("ReportTime between \'" + strStartTime + "\' and \'" +strEndTime +"\'");
        model->select();

        for(int i = 0; i < model->rowCount(); i++)
        {
            ClinicDailyReportTable *table = new ClinicDailyReportTable;
            QSqlRecord record = model->record(i);
            table->setId(record.value("Id").toString());
            table->setDate(record.value("Date").toDate());
            table->setAllDueIncome(record.value("AllDueIncome").toDouble());
            table->setAllRealIncome(record.value("AllRealIncome").toDouble());
            list.append(table);
        }
    }
    return list;
}

bool ClinicDailyReportTable::selectClinicChargesByDate(QDate date)
{
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable(strClinicCharge);
        QString strStartTime = date.toString("yyyy-MM-dd") + "T00:00:00";
        QString strEndTime = date.toString("yyyy-MM-dd") + "T23:59:59";
        model->setFilter("Time between \'" + strStartTime + "\' and \'" +strEndTime +"\'");
        model->select();

        for(int i = 0; i < model->rowCount(); i++)
        {
            QSqlRecord record = model->record(i);
            QString strChargeId = record.value("ID").toString();
            ClinicChargeTable *charge = new ClinicChargeTable;
            charge->setID(strChargeId);
            charge->Read();
            m_vecDailyReportDetails.append(charge);
        }
        return true;
    }
    else
        return false;
}

bool ClinicDailyReportTable::readDailyReport()
{
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable(strClinicDailyReport);
        model->setFilter("Id = \'" + m_strId + "\'");
        model->select();

        if(model->rowCount() == 1)
        {
            QSqlRecord record = model->record();
            m_strId = record.value("Id").toString();
            m_date = record.value("Time").toDate();
            m_dAllDueIncome = record.value("AllDueIncome").toDouble();
            m_dAllRealIncome = record.value("AllRealIncome").toDouble();
            m_dAllDebt = m_dAllDueIncome - m_dAllRealIncome;
            m_strMaker = record.value("Maker").toString();

        }
        return true;
    }
    else
        return false;
}

bool ClinicDailyReportTable::saveDailyReport()
{
    deleteDailyReport();
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable(strClinicDailyReport);

        int row =0;
        model->insertRows(row,1);
        model->setData(model->index(row,0),m_strId);
        model->setData(model->index(row,1),m_date.toString("yyyy-MM-dd"));
        model->setData(model->index(row,2),QDateTime::currentDateTime());
        model->setData(model->index(row,3),QString::number(m_dAllDueIncome));
        model->setData(model->index(row,4),QString::number(m_dAllRealIncome));
        model->setData(model->index(row,5),m_strMaker);
        model->submitAll();
        return true;
    }
    else
        return false;
}

bool ClinicDailyReportTable::deleteDailyReport()
{
    if(myDB::connectDB())
    {
        return deleteRows(strClinicDailyReport,"Id",m_strId);
    }
    else
        return false;
}

