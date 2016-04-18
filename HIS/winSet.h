#ifndef WINSTRING_H
#define WINSTRING_H
#include <QString>

const QString strNull = "";

enum MedicalInsuranceType
{
    selfPay = 0,
    medicare = 1,
    NCMS = 2
};

enum Gender{
    man = 0,
    woman = 1
};

//---------------------------------------------------------------------------------------------------------------------------------------
// 数据库
//---------------------------------------------------------------------------------------------------------------------------------------
const QString strDBType = "QSQLITE";
const QString strDBName = "./test.db";
const QString strDBClinicCharge = "收费单";
const QString strDBClinicChargeRecords = "收费记录";

//---------------------------------------------------------------------------------------------------------------------------------------
// 主窗体 - 工具栏
//---------------------------------------------------------------------------------------------------------------------------------------
const QString strNewAction = "新建";
const QString strSaveAction = "保存";
const QString strDeleteAction = "删除";
const QString strExportAction = "导出";
const QString strFindAction = "查找";
const QString strAmendAction = "修改";
const QString strComboAction = "套餐";
const QString strDeleteRowAction = "删除行";
const QString strAddRowAction = "添加行";
const QString strPreviewAction = "预览";
const QString strPrintAction = "打印";
const QString strFileToolBar = "文件";
const QString strEditToolBar = "编辑";
const QString strPrintToolBar = "打印";

//---------------------------------------------------------------------------------------------------------------------------------------
// 主窗体 - 菜单栏
//---------------------------------------------------------------------------------------------------------------------------------------
const QString strClinicMenu = "门诊";
const QString strClinicChargeAction = "门诊收费";
const QString strClinicDailyReportAction = "门诊日结";

const int nSubFormDefaultWidth = 850;
const int nSubFormDefaultHeight = 600;

//---------------------------------------------------------------------------------------------------------------------------------------
// 门诊收费
//---------------------------------------------------------------------------------------------------------------------------------------
const QString strPatientGroup = "患者信息";
const QString strNameLabel = "姓名：";
const QString strGenderLabel = "性别：";
const QString strMan = "男";
const QString strWoman = "女";
const QString strAgeLabel = "年龄：";
const QString strIdCardLabel = "身份证号：";
const int nIdCardEditMinWidth = 135;

const QString strInsuranceGroup = "保险信息";
const QString strSocialSecurityNumLabel = "社保号码：";
const QString strMedicalInsuranceTypeLabel = "医保类型：";
const QString strSelfPay = "自费";
const QString strMedicare = "医保";
const QString strNCMS = "新农合";

const QString strDoctorGroup = "就诊信息";
const QString strDepartmentLabel = "就诊科室：";
const QString strDoctorLabel = "医生：";

const QString strIncomeGroup = "收费信息";
const QString strDueIncomeLabel = "应收金额：";
const QString strRealIncomeLabel = "实收金额：";

const QString strClinicChargeNumGroup = "收费单信息";
const QString strClincChargeNumLabel = "收费单号：";

const QString strClinicChargeNumPR = "CC";



#endif // WINSTRING_H
