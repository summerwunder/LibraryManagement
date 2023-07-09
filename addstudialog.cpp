#include "addstudialog.h"
#include "ui_addstudialog.h"

AddStuDialog::AddStuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStuDialog)
{
    ui->setupUi(this);
    this->setFixedSize(493,310);
    connect(ui->sureButton,&QPushButton::clicked,this,QDialog::accept);
    connect(ui->cancelButton,&QPushButton::clicked,this,QDialog::reject);
}

AddStuDialog::~AddStuDialog()
{
    delete ui;
}

int AddStuDialog::getId()
{
    return ui->idSpinBox->value();
}

QString AddStuDialog::getName()
{
    return ui->nameEdit->text();
}

QString AddStuDialog::getGender()
{
    if(ui->maleButton->isChecked())
        return "男";
    else if(ui->femaleButton->isChecked())
        return "女";
    else
        return nullptr;
}

QString AddStuDialog::getTele()
{
    return ui->teleEdit->text();
}

QString AddStuDialog::getUsrName()
{
    return ui->usernameEdit->text();
}

QString AddStuDialog::getPassWord()
{
    return ui->passwordEdit->text();
}

void AddStuDialog::setInitData(int originId,QString originalUsername,QString originalPassword)
{
    // 设置学生初始信息在对话框中的初始值
    ui->idSpinBox->setValue(originId);
    ui->usernameEdit->setText(originalUsername);
    ui->passwordEdit->setText(originalPassword);

    // 将学号和用户名密码设置为不可编辑
    ui->idSpinBox->setReadOnly(true);
    ui->usernameEdit->setReadOnly(true);
    ui->passwordEdit->setReadOnly(true);
}

bool AddStuDialog::isGenderEmpty()
{
    bool isMaleSelected = ui->maleButton->isChecked();
    bool isFemaleSelected = ui->femaleButton->isChecked();
    if (!isMaleSelected && !isFemaleSelected)
        return true;
    return false;
}


