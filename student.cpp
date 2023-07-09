#include "student.h"
#include "ui_student.h"

Student::Student(int id, QString name, QString gender, QString tel,
                 int borrowNum, int bookReadNum, int defyNum,QWidget *parent) :
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
    this->showMyRecord();
    connect(ui->longerTimeButton,&QPushButton::clicked,this,&Student::addTime);
    connect(ui->returnButton,&QPushButton::clicked,this,&Student::returnBook);
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

void Student::showMyRecord()
{
    this->myTable=new QSqlTableModel;
    myTable->setTable("book_record_view");
    myTable->setFilter(QString("stu_id=%1").arg(this->id));
    myTable->select();
    ui->MytableView->setModel(myTable);

    this->myTable->removeColumn(3);
    ui->MytableView->setFixedSize(421,271);
    ui->MytableView->setColumnWidth(0, 161);
    ui->MytableView->setColumnWidth(1, 130);
    ui->MytableView->setColumnWidth(2, 130);
    // 设置表头标题
    myTable->setHeaderData(0, Qt::Horizontal, "书名");
    myTable->setHeaderData(1, Qt::Horizontal, "借阅时间");
    myTable->setHeaderData(2, Qt::Horizontal, "理应归还时间");

}

void Student::addTime()
{
    int curRow=ui->MytableView->currentIndex().row();
    if(curRow<0)
    {
        QMessageBox::warning(this,"警告","未选择有效目标");
        return ;
    }
    QDateTime backTime = myTable->data(myTable->index(curRow, 2)).toDateTime();
    QDateTime newBackTime = backTime.addDays(MORE_TIME);
    myTable->setData(myTable->index(curRow, 2), newBackTime);

    if(myTable->submitAll())
        QMessageBox::information(this,"提示","续借成功");
    this->myTable->select();
}

void Student::returnBook()
{
    int curRow=ui->MytableView->currentIndex().row();
    if(curRow<0)
    {
        QMessageBox::warning(this,"警告","未选择有效目标");
        return ;
    }
    if(QMessageBox::question(this, "提示", "确定要归还吗？",
       QMessageBox::Yes | QMessageBox::No)==QMessageBox::No)
        return;
    QString bookName=this->myTable->data(myTable->index(curRow,0)).toString();
    query->prepare("update book_record inner join book_info set "
                   "isOver=1 where book_record.book_id=book_info.isbn "
                   "and book_info.name=:name");
    query->bindValue(":name",bookName);
    if(query->exec())
    {
        myTable->select();
        QMessageBox::information(this,"提示","归还成功");
    }else{
        qDebug()<<"失败";
    }
}


