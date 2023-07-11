#include "changepassword.h"
#include "ui_changepassword.h"

ChangePassword::ChangePassword(int id,QString password,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    this->show();
    this->setFixedSize(432,316);
    this->setWindowTitle("修改密码");
    ui->changeAgainLineEdit->setEchoMode(QLineEdit::Password);
    ui->changeLineEdit->setEchoMode(QLineEdit::Password);
    connect(ui->sureButton,&QPushButton::clicked,this,&ChangePassword::sureButtonClicked);
    connect(ui->cancelButton,&QPushButton::clicked,[=](){
       this->close();
    });
    this->password=password;
    this->id=id;
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::sureButtonClicked()
{
    if(password!=ui->originLineEdit->text())
    {
        QMessageBox::warning(this,"警告","原密码输入错误！");
        ui->originLineEdit->clear();
        return;
    }
    if(ui->changeLineEdit->text()!=ui->changeAgainLineEdit->text()||
            ui->changeAgainLineEdit->text().isEmpty()||
            ui->changeLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","两次输入的密码不一致");
        ui->changeAgainLineEdit->clear();
        ui->changeLineEdit->clear();
        return;
    }
    query->prepare("update stu set password=:password where id=:id");
    query->bindValue(":password",ui->changeAgainLineEdit->text());
    query->bindValue(":id",id);
    if(query->exec())
    {
        QMessageBox::information(this,"提示","修改成功");
        this->close();
        return;
    }
}
