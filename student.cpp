#include "student.h"
#include "ui_student.h"

Student::Student(int id, QString name, QString gender, QString tel, int borrowNum, int bookReadNum, int defyNum,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Student)
{
    ui->setupUi(this);
    this->show();
    this->id=id;
    this->name=name;
    this->gender=gender;
    this->tel=tel;
    this->borrowNum=borrowNum;
    this->bookReadNum=bookReadNum;
    this->defyNum=defyNum;
    ui->userName->setText("学生:"+name);
    this->initGraph();
    this->initEdit();
}

Student::~Student()
{
    delete ui;
}

Student::Student()
{


}

void Student::initGraph()
{
    this->setWindowTitle("学生界面");
    this->setFixedSize(965,720);
    connect(ui->exitButton,&QPushButton::clicked,[=](){
        this->close();
    });
}

void Student::initEdit()
{
  /*  query->prepare("select * from stu where id=:id");
    query->bindValue(":id",this->id);
    query->exec();
    while(query->next())*/
    QString text;
    text += "学号: " + QString::number(id) + "\n";
    text += "姓名: " + name + "\n";
    text += "性别: " + gender + "\n";
    text += "电话号码: " + tel + "\n";
    text += "正在借阅的书籍数目: " + QString::number(borrowNum) + "\n";
    text += "已经借阅的书籍数目: " + QString::number(bookReadNum) + "\n";
    text += "违规次数: " + QString::number(defyNum) + "\n";

    ui->infoText->setPlainText(text);
    ui->infoText->setFont(QFont(QString("黑体"),14));
    ui->infoText->setReadOnly(true);
}

