#include "findclincchargedlg.h"
#include "ui_findclincchargedlg.h"

FindClincChargeDlg::FindClincChargeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindClincChargeDlg)
{
    m_strId = strNull;
    ui->setupUi(this);
    create();
    init();
    setMyLayout();
}

FindClincChargeDlg::~FindClincChargeDlg()
{
    delete ui;
}

QString FindClincChargeDlg::getId()
{
    return m_strId;
}

void FindClincChargeDlg::create()
{
    m_chargeNumLabel = new QLabel(strClincChargeNumLabel);
    m_chargeNumEdit = new QLineEdit();
    m_chargeNumLabel->setBuddy(m_chargeNumEdit);

    m_nameLabel = new QLabel(strNameLabel);
    m_nameEdit = new QLineEdit();
    m_nameLabel->setBuddy(m_nameEdit);

    m_genderLabel = new QLabel(strGenderLabel);
    m_genderComboBox = new QComboBox;
    m_genderComboBox->addItem(strMan);
    m_genderComboBox->addItem(strWoman);

    m_findButton = new QToolButton;
    m_findButton->setIcon(QIcon(strIconPath + "find.png"));

    m_resultsTableView = new QTableView;
    m_resultsModel = new QStandardItemModel;
    m_resultsTableView->setModel(m_resultsModel);

    m_choiseButton = new QPushButton(strChoiseButton);
    m_cancelButton = new QPushButton(strCancelButton);
}

void FindClincChargeDlg::setMyLayout()
{
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(m_chargeNumLabel);
    topLayout->addWidget(m_chargeNumEdit);
    topLayout->addWidget(m_nameLabel);
    topLayout->addWidget(m_nameEdit);
    topLayout->addWidget(m_genderLabel);
    topLayout->addWidget(m_genderComboBox);
    topLayout->addStretch();
    topLayout->addWidget(m_findButton);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(m_choiseButton);
    bottomLayout->addWidget(m_cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(m_resultsTableView);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);
}

void FindClincChargeDlg::init()
{
    m_chargeNumEdit->setText(strNull);
    m_nameEdit->setText(strNull);
    m_genderComboBox->setCurrentIndex(man);
    m_resultsModel->clear();
    m_resultsModel->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("收费单号")));
    m_resultsModel->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("科室")));
    m_resultsModel->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("医生")));
    m_resultsModel->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("实收款")));
    m_resultsModel->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("时间")));
    m_resultsModel->setItem(0, 4, NULL);
}
