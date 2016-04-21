#include "clinicchargetable.h"
#include "connectDB.h"

ClinicChargeTable::ClinicChargeTable()
{
    m_strPrefixion = strClinicChargeNumPR;
    m_dDueIncome = 0;
    m_dRealIncome = 0;
    m_strID = getNewClinicChargeID();
    m_chargeItems.clear();
}

QString ClinicChargeTable::getID()
{
    return m_strID;
}

QString ClinicChargeTable::getNewClinicChargeID()
{
    return m_strPrefixion + getNewID();
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

void ClinicChargeTable::setID(QString strID)
{
    this->m_strID = strID;
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

bool ClinicChargeTable::readChargeTable()
{
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable(strClinicCharge);
        model->setFilter("ID = \'" + m_strID + "\'");
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
bool ClinicChargeTable::ReadChargeRecords()
{
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable(strClinicChargeRecords);
        model->setFilter("ChargeId = \'" + m_strID +"\'");
        model->select();

        m_chargeItems.clear();
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
            item->setClinicChargeId(record.value("ClinicChargeId").toString());

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
        deleteRows(strClinicChargeRecords,"ChargeId",m_strID);

        QSqlTableModel *model = new QSqlTableModel;
        model->setTable(strClinicChargeRecords);

        for(int i = 0; i < m_chargeItems.size(); i++)
        {
            int row = i;
            model->insertRows(row,1);
            model->setData(model->index(row,chargeItemNo),m_chargeItems.at(row)->getChargeItemNo());
            model->setData(model->index(row,chargeItemName),m_chargeItems.at(row)->getChargeItemName());
            model->setData(model->index(row,chargeItemCount),m_chargeItems.at(row)->getChargeItemCount());
            model->setData(model->index(row,chargeItemPrice),m_chargeItems.at(row)->getChargeItemPrice());
            model->setData(model->index(row,clinicReceipt),m_chargeItems.at(row)->getClinicReceipt());
            model->setData(model->index(row,clinicSort),m_chargeItems.at(row)->getClinicSort());
            model->setData(model->index(row,clinicChargeId),m_chargeItems.at(row)->getClinicChargeId());
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
        deleteRows(strClinicCharge,"ID",m_strID);

        QSqlTableModel *model = new QSqlTableModel;
        model->setTable(strClinicCharge);

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

bool ClinicChargeTable::Read()
{
    if(readChargeTable())
    {
        return ReadChargeRecords();
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



bool ClinicChargeTable::Delete()
{
      if(deleteChargeTable())
            return deleteChargeRecords();
        else
            return false;
}

bool ClinicChargeTable::deleteChargeTable()
{
    if(myDB::connectDB())
    {
        return deleteRows(strClinicCharge,"ID",m_strID);
    }
    else
        return false;

}

bool ClinicChargeTable::deleteChargeRecords()
{
    if(myDB::connectDB())
    {
        return deleteRows(strClinicChargeRecords,"ChargeId",m_strID);
    }
    else
        return false;
}

