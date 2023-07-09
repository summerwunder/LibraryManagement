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
    ui->choiceComboBox->setCurrentIndex(0);
    this->showAllBooks();


    this->initGraph();
    this->initEdit();
    this->showMyRecord();
    connect(ui->longerTimeButton,&QPushButton::clicked,this,&Student::addTime);
    connect(ui->returnButton,&QPushButton::clicked,this,&Student::returnBook);
    connect(ui->BookTableView,&QTableView::clicked,this,&Student::tableViewClicked);
    connect(ui->borrowButton,&QPushButton::clicked,this,&Student::borrowBook);
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
    infoTable=new QSqlTableModel;
    infoTable->setTable("stu");
    infoTable->setFilter(QString("id=%1").arg(this->id));
    infoTable->select();
    QString text;
    text += "学号: " + infoTable->data(infoTable->index(0,0)).toString()+ "\n";
    text += "姓名: " + infoTable->data(infoTable->index(0,1)).toString()+ "\n";
    text += "性别: " + infoTable->data(infoTable->index(0,2)).toString() + "\n";
    text += "电话号码: " + infoTable->data(infoTable->index(0,3)).toString()+ "\n";
    text += "正在借阅的书籍数目: " + infoTable->data(infoTable->index(0,4)).toString() + "\n";
    text += "已经借阅的书籍数目: " + infoTable->data(infoTable->index(0,5)).toString() + "\n";
    text += "违规次数: " + infoTable->data(infoTable->index(0,6)).toString() + "\n";

    ui->infoText->setPlainText(text);
    ui->infoText->setFont(QFont(QString("黑体"),14));
    ui->infoText->setReadOnly(true);
}

/*
 * 借书，可以通过spinBox或者行选择
 */
void Student::borrowBook()
{
    //先检查
    if(this->borrowNum>=MAX_BORROW)
    {
        QMessageBox::information(this,"提示","你的借书数目已经到达了上限");
        return;
    }else if(this->defyNum>=MAX_DEFY)
    {
        QMessageBox::warning(this,"警告","你违规次数过多无法借书，请联系管理员");
        return;
    }
    int curRow=ui->BookTableView->currentIndex().row();
    if(this->mainTable->data(mainTable->index(curRow,4)).toString()=="已被借阅")
    {
        QMessageBox::warning(this,"警告","这本书不在馆内，无法借阅");
        return;
    }
    query->prepare("insert into book_record(stu_id,book_id,isOver,recordTime,backTime) "
                   "values(:id,:isbn,0,now(),date_add(now(),interval :time day))");
    query->bindValue(":id",this->id);
    query->bindValue(":isbn",ui->isbnSpinBox->value());
    query->bindValue(":time",BORROW_TIME);
    if(query->exec())
    {
        QMessageBox::information(this,"提示","借阅成功");
        this->myTable->select();
        this->initEdit();
        return;
    }
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
        this->mainTable->select();
        this->initEdit();
    }else{
        qDebug()<<"失败";
    }
}

void Student::showAllBooks()
{
    this->mainTable=new QSqlTableModel;
    this->mainTable->setTable("book_view");
    mainTable->select();
    ui->BookTableView->setModel(mainTable);

    mainTable->setHeaderData(0, Qt::Horizontal, "ISBN");
    mainTable->setHeaderData(1, Qt::Horizontal, "书名");
    mainTable->setHeaderData(2, Qt::Horizontal, "作者");
    mainTable->setHeaderData(3, Qt::Horizontal, "出版社");
    mainTable->setHeaderData(4, Qt::Horizontal, "状态");

    ui->BookTableView->setFixedSize(451,531);
    ui->BookTableView->setColumnWidth(0, 50);
    ui->BookTableView->setColumnWidth(1, 120);
    ui->BookTableView->setColumnWidth(2, 60);
    ui->BookTableView->setColumnWidth(3, 131);
    ui->BookTableView->setColumnWidth(4, 70);
}

void Student::showReaderRating()
{
    this->userTable=new QSqlTableModel;
    userTable->setTable("sturating");
    userTable->setSort(2,Qt::DescendingOrder);
    userTable->select();
    userTable->setHeaderData(0, Qt::Horizontal, "姓名");
    userTable->setHeaderData(1, Qt::Horizontal, "性别");
    userTable->setHeaderData(2, Qt::Horizontal, "借阅总数");
    ui->BookTableView->setModel(userTable);

    ui->BookTableView->setFixedSize(451,531);
    ui->BookTableView->setColumnWidth(0, 171);
    ui->BookTableView->setColumnWidth(1, 120);
    ui->BookTableView->setColumnWidth(2, 160);
}

/*
 * comboBox的槽函数（ui生成）
 */
void Student::on_choiceComboBox_currentIndexChanged(int index)
{
    if(index==0)
        this->showAllBooks();
    else if(index==1)
        this->showReaderRating();
}
//槽函数，会让spinBox内容随着点击事件而改变（ISBN）
void Student::tableViewClicked(const QModelIndex &index)
{
    if(index.isValid())
    {
        int row=index.row();
        QString isbn=this->mainTable->data(mainTable->index(row,0)).toString();
        ui->isbnSpinBox->setValue(isbn.toInt());
    }
}

