#include "clinicchargetable.h"
#include "connectDB.h"

ClinicChargeTable::ClinicChargeTable()
{
    m_strPrefixion = "CC";
    m_dDueIncome = 0;
    m_dRealIncome = 0;
    m_ChargeModel = new QSqlTableModel;
    m_ChargeRecordsModel = new QSqlTableModel;
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

QSqlTableModel *ClinicChargeTable::getChargeRecords() const
{
    return m_ChargeRecordsModel;
}

void ClinicChargeTable::setDueIncome(double d_DueIncome)
{
    this->m_dDueIncome = d_DueIncome;
}

void ClinicChargeTable::setRealIncome(double d_RealIncome)
{
    this->m_dRealIncome = d_RealIncome;
}

void ClinicChargeTable::setChargeRecords(QSqlTableModel *ChargeRecordsModel)
{
    this->m_ChargeRecordsModel = ChargeRecordsModel;
}

bool ClinicChargeTable::findChargeTableByID(QString strId)
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
            m_strName = record.value("name").toString();
            m_eGender = (Gender)record.value("Gender").toInt();
            m_nAge = record.value("Age").toInt();
            m_strIDCard = record.value("IdCardNum").toString();
            m_strSocialSecurityNum = record.value("SocialSecurityNum").toString();
            m_eMedicalInsuranceType = (MedicalInsuranceType)record.value("MedicalInsuranceType").toInt();
            m_strDepartment = record.value("Department").toString();
            m_strDoctor = record.value("Doctor").toString();
            m_dDueIncome = record.value("DueIncome").toDouble();
            m_dRealIncome = record.value("RealIncome").toDouble();
        }

        return true;
    }
    else
        return false;
}
bool ClinicChargeTable::findChargeRecordsByID(QString strId)
{
    if(myDB::connectDB())
    {
        m_ChargeRecordsModel->setTable("ClinicChargeRecords");
        m_ChargeRecordsModel->setFilter("CliniChargeId = " + strId);
        m_ChargeRecordsModel->select();

        return true;
    }
    else
        return false;
}

void ClinicChargeTable::saveChargeRecords(QStandardItemModel *chargeRecordsmodel)
{
    if(myDB::connectDB())
    {
        m_ChargeRecordsModel->setTable("ClinicChargeRecords");
        for(int i = 0; i < chargeRecordsmodel->rowCount(); i++)
        {
            m_ChargeRecordsModel->insertRows(i,1);
            int j =0;
            for(j = 0; j<chargeRecordsmodel->columnCount(); j++)
            {
                QStandardItem *item = chargeRecordsmodel->item(i,j);
                if(item == NULL)
                    continue;
                QString sss = item->text();
                m_ChargeRecordsModel->setData(m_ChargeRecordsModel->index(i,j),sss);
                m_ChargeRecordsModel->submit();
            }
            m_ChargeRecordsModel->setData(m_ChargeRecordsModel->index(i,j+1),m_strID);
            m_ChargeRecordsModel->submitAll();
        }
    }
}

bool ClinicChargeTable::Read()
{
    m_strID = "222";
    if(findChargeTableByID(m_strID))
        return findChargeRecordsByID(m_strID);
    else
        return false;
}

bool ClinicChargeTable::Save()
{
    if(myDB::connectDB())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("ClinicCharge");
        int row =0;
        model->insertRows(row,1);
        model->setData(model->index(row,0),m_strID);
        model->setData(model->index(row,1),m_strName);
        model->setData(model->index(row,2),m_eGender);
        model->setData(model->index(row,3),m_nAge);
        model->setData(model->index(row,4),m_strIDCard);
        model->setData(model->index(row,5),m_strSocialSecurityNum);
        model->setData(model->index(row,6),m_eMedicalInsuranceType);
        model->setData(model->index(row,7),m_strDepartment);
        model->setData(model->index(row,8),m_strDoctor);
        model->setData(model->index(row,9),m_dDueIncome);
        model->setData(model->index(row,10),m_dRealIncome);
        model->setData(model->index(row,11),QDate::currentDate().toString());
        model->submitAll();
        // 缺少保存收费明细
        return true;
    }
    else
        return false;
}

bool ClinicChargeTable::Delete()
{
    return true;
}

