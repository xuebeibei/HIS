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
    readCharges();
    return true;
}

bool ClinicDailyReportTable::Save()
{
    Delete();
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable(strClinicDailyReport);

        int row =0;
        model->insertRows(row,1);
        model->setData(model->index(row,0),m_strId);
        model->setData(model->index(row,1),m_date.toString());
        model->setData(model->index(row,2),QString::number(m_dAllDueIncome));
        model->setData(model->index(row,3),QString::number(m_dAllRealIncome));
        model->setData(model->index(row,4),QDateTime::currentDateTime());
        model->setData(model->index(row,5),m_strMaker);
        model->submitAll();
        return true;
    }
    else
        return false;
}

bool ClinicDailyReportTable::Delete()
{
    if(myDB::connectDB())
    {
//        QSqlTableModel *model = new QSqlTableModel;
//        model->setTable(strClinicDailyReport);
//        model->setFilter("Id = \'" + m_strId + "\'");
//        model->select();

//        if(model->rowCount() == 1)
//        {
//            bool isOk = model->removeRows(0,1);

//            return isOk;
//        }
//        else
//            return false;
        return deleteRows(strClinicDailyReport,"Id",m_strId);
    }
    else
        return false;
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

QStringList ClinicDailyReportTable::getdailyReport() const
{
    return m_listCharges;
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

void ClinicDailyReportTable::setDailyReport(QStringList listCharges)
{
    this->m_listCharges = listCharges;
}


bool ClinicDailyReportTable::readCharges()
{
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable(strClinicCharge);
        QString strStartTime = m_date.toString("yyyy-MM-dd") + "T00:00:00";
        QString strEndTime = m_date.toString("yyyy-MM-dd") + "T23:59:59";
        model->setFilter("Time between \'" + strStartTime + "\' and \'" +strEndTime +"\'");
        model->select();

        for(int i = 0; i < model->rowCount(); i++)
        {
            QSqlRecord record = model->record(i);
            QString strChargeId = record.value("ID").toString();
            m_listCharges.append(strChargeId);
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

