#include "clinicchargetable.h"
#include "connectDB.h"

ClinicChargeTable::ClinicChargeTable()
{
    m_strPrefixion = "CC";
    m_dDueIncome = 0;
    m_dRealIncome = 0;
}

QString ClinicChargeTable::getID()
{
    if(m_strID.isEmpty())
        return m_strPrefixion + getNewID();
    else
        return m_strID;
}

double ClinicChargeTable::getDueIncome() const
{
    return m_dDueIncome;
}

double ClinicChargeTable::getRealImcome() const
{
    return m_dRealIncome;
}

Patient ClinicChargeTable::getPatient() const
{
    return m_patient;
}

QVector<ClinicChargeItem *> ClinicChargeTable::getChargeItems() const
{
    return m_chargeItems;
}

void ClinicChargeTable::setDueIncome(double d_DueIncome)
{
    this->m_dDueIncome = d_DueIncome;
}

void ClinicChargeTable::setRealIncome(double d_RealIncome)
{
    this->m_dRealIncome = d_RealIncome;
}

void ClinicChargeTable::setChargeItems(QVector<ClinicChargeItem *> chargeItems)
{
    m_chargeItems.clear();
    for(int i = 0; i< chargeItems.size(); i++)
    {
        ClinicChargeItem* item = new ClinicChargeItem(chargeItems.at(i));
        m_chargeItems.append(item);
    }
}

void ClinicChargeTable::setPatient(Patient patient)
{
    this->m_patient = patient;
}

bool ClinicChargeTable::readChargeTable(QString strId)
{
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("ClinicCharge");
        model->setFilter("ID = " + strId);
        model->select();
        for(int i = 0; i< model->rowCount();i++)
        {
            QSqlRecord record = model->record(i);
            m_strID = record.value("id").toString();
            m_patient.setName(record.value("name").toString());
            m_patient.setGender((Gender)record.value("Gender").toInt());
            m_patient.setAge(record.value("Age").toInt());
            m_patient.setIDCard(record.value("IdCardNum").toString());
            m_patient.setSocialSecurityNum(record.value("SocialSecurityNum").toString());
            m_patient.setMedicalInsuranceType((MedicalInsuranceType)record.value("MedicalInsuranceType").toInt());
            m_patient.setDepartment(record.value("Department").toString());
            m_patient.setDoctor(record.value("Doctor").toString());
            m_dDueIncome = record.value("DueIncome").toDouble();
            m_dRealIncome = record.value("RealIncome").toDouble();
        }

        return true;
    }
    else
        return false;
}
bool ClinicChargeTable::ReadChargeRecords(QString strId)
{
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("ClinicChargeRecords_1");
        model->setFilter("CliniChargeId = " + strId);
        model->select();

        for(int i =0; i < model->rowCount();i++)
        {
            QSqlRecord record = model->record(i);

            ClinicChargeItem *item = new ClinicChargeItem;
            item->setChargeItemNo(record.value("ChargeItemNo").toString());
            item->setChargeItemName(record.value("ChargeItemName").toString());
            item->setChargeItemCount(record.value("ChargeItemCount").toInt());
            item->setChargeItemPrice(record.value("ChargeItemPrice").toDouble());
            item->setClinicReceipt(record.value("ChinicReceipt").toString());
            item->setClinicSort(record.value("ClinicSort").toString());
            item->setClinicChargeId(record.value("CliniChargeId").toString());

            m_chargeItems.append(item);
        }

        return true;
    }
    else
        return false;
}

bool ClinicChargeTable::saveChargeRecords()
{
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("ClinicChargeRecords_1");
        for(int i = 0; i < m_chargeItems.size(); i++)
        {
            int row = i;
            model->insertRows(row,1);
            model->setData(model->index(row,0),m_chargeItems.at(i)->getChargeItemNo());
            model->setData(model->index(row,1),m_chargeItems.at(i)->getChargeItemName());
            model->setData(model->index(row,2),m_chargeItems.at(i)->getChargeItemCount());
            model->setData(model->index(row,3),m_chargeItems.at(i)->getChargeItemPrice());
            model->setData(model->index(row,4),m_chargeItems.at(i)->getClinicReceipt());
            model->setData(model->index(row,5),m_chargeItems.at(i)->getClinicSort());
            model->setData(model->index(row,6),m_chargeItems.at(i)->getClinicChargeId());
            model->submitAll();
        }

        return true;
    }
    else
        return false;
}

bool ClinicChargeTable::saveChargeTable()
{
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("ClinicCharge");
        int row =0;
        model->insertRows(row,1);
        model->setData(model->index(row,0),m_strID);
        model->setData(model->index(row,1),m_patient.getName());
        model->setData(model->index(row,2),m_patient.getGender());
        model->setData(model->index(row,3),m_patient.getAge());
        model->setData(model->index(row,4),m_patient.getIDCard());
        model->setData(model->index(row,5),m_patient.getSocialSecurityNum());
        model->setData(model->index(row,6),m_patient.getMedicalInsuranceType());
        model->setData(model->index(row,7),m_patient.getDepartment());
        model->setData(model->index(row,8),m_patient.getDoctor());
        model->setData(model->index(row,9),m_dDueIncome);
        model->setData(model->index(row,10),m_dRealIncome);
        model->setData(model->index(row,11),QDate::currentDate().toString());
        model->submitAll();
        return true;
    }
    else
        return false;
}

bool ClinicChargeTable::Read(QString strId)
{
    if(readChargeTable(strId))
    {
        return ReadChargeRecords(strId);
    }
    else
        return false;
}

bool ClinicChargeTable::Save()
{
    if(saveChargeTable())
    {
        return saveChargeRecords();
    }
    else
        return false;
}

bool ClinicChargeTable::Find(QString strId)
{
    return Read(strId);
}

bool ClinicChargeTable::Delete()
{
    return true;
}

