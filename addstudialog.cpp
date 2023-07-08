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
