#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);  
    this->setFixedSize(441,400);
    this->setWindowTitle("登录界面");
   // this->setStyleSheet("QWidget {background-color: #83cadf}");
   // this->setWindowOpacity(0.88);
    this->beautify();
    connect(ui->exitButton,&QPushButton::clicked,[this](){
       this->close();
    });
    connect(ui->loginButton,&QPushButton::clicked,this,&Widget::clicked_on_loginButton);
}

Widget::~Widget()
{
    delete ui;
    MysqlServer::getInstance()->getDb().close();//关闭数据库
}

void Widget::beautify()
{
    //对输入文本美化
    ui->userNameEdit->setPlaceholderText("请输入您的账号");
    ui->passwordEdit->setPlaceholderText("请输入您的密码");
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    //对按钮美化
    //ui->loginButton->setStyleSheet("QPushButton:pressed { background-color: #d4ecf4; }");
    //ui->exitButton->setStyleSheet("QPushButton:pressed { background-color: #d4ecf4; }");
}

bool Widget::isEmpty()
{
    if(ui->userNameEdit->text().isEmpty()||ui->passwordEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","你有未输入的字段");
        return true;
    }
    if(!ui->readerButton->isChecked()&&!ui->adminButton->isChecked())
    {
        QMessageBox::warning(this,"警告","请选择你的身份");
        return true;
    }
    return false;
}

/*
 * 判断登录
 *
 */
void Widget::clicked_on_loginButton()
{
    if(this->isEmpty())
        return ;
    //获取文本
    QSqlQuery *query=MysqlServer::getInstance()->getQuery();
    QString strLogin=ui->userNameEdit->text();
    QString strPassword=ui->passwordEdit->text();
    QString strUser;
    //选定身份
    if(ui->adminButton->isChecked()) strUser="admin";
    else if(ui->readerButton->isChecked()) strUser="stu";

    QString strTest="select * from "+strUser+" where username=:username";//执行的sql查询语句
    query->prepare(strTest);
    query->bindValue(":username",strLogin);
    query->exec();
    while(query->next())
    {
        if(ui->adminButton->isChecked())//说明是管理
        {
             QString password= query->value(3).toString();
             if(password==strPassword)
             {
                 unsigned id=query->value(0).toUInt();
                 QString name=query->value(1).toString();
                 //QMessageBox::information(this,"info","欢迎管理员登录");
                 this->hide();
                 //创建管理员界面
                 new Administrator(id,name);
                 return;
             }else{
                 QMessageBox::warning(this,"警告","您的密码输入有误");
                 ui->passwordEdit->clear();
                 return;
             }
        }else{          //读者
             QString password= query->value(8).toString();
             if(password==strPassword)
             {
                //QMessageBox::information(this,"info","欢迎读者登录");
                 //获取相应的数据，为实现个人信息做准备
                int id=query->value(0).toInt();
                QString name=query->value(1).toString();
                QString gender=query->value(2).toString();
                QString tel=query->value(3).toString();
                int borrowNum=query->value(4).toInt();
                int readNum=query->value(5).toInt();
                int defyNum=query->value(6).toInt();
                QString password=query->value(8).toString();
                new Student(id,name,gender,tel,borrowNum,readNum,defyNum,password);
                this->hide();
                return;
             }else{
                 QMessageBox::warning(this,"警告","您的密码输入有误");
                 ui->passwordEdit->clear();//把密码栏给清空
                 return;
             }
        }
    }
    //未找到相应的账号就报错
    QMessageBox::warning(this,"警告","您的账号输入有误");
}

