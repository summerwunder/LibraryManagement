#include "administrator.h"
#include "ui_administrator.h"

Administrator::Administrator()
{

}

Administrator::Administrator(unsigned id,QString name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrator)
{

    ui->setupUi(this);
    this->show();
    this->initGraph();
    this->bookGraph();
    this->logGraph();
    this->id=id;
    this->name=name;
    ui->userName->setText("管理员："+this->name);
    /*书本这块的槽函数*/
    connect(ui->queryBookButton,&QPushButton::clicked,this,&Administrator::queryBookFunction);
    connect(ui->queryAllBookButton,&QPushButton::clicked,this,&Administrator::queryAllBookFunction);
    //关于排序书本
    connect(ui->ascBookOrder,&QRadioButton::toggled,this,&Administrator::ascBookOrderFun);
    connect(ui->descBookOrder,&QRadioButton::toggled,this,&Administrator::descBookOrderFun);
}

Administrator::~Administrator()
{
    delete ui;
}

void Administrator::initGraph()
{
    this->setFixedSize(799,657);
}

void Administrator::bookGraph()
{
    ui->tableViewBook->setFixedSize(599,389);
    bookTable=new QSqlTableModel(this);
    bookTable->setTable("book_info");
    bookTable->setEditStrategy(QSqlTableModel::OnFieldChange);//自动更新
    bookTable->select();
    ui->tableViewBook->setModel(bookTable);
    ui->tableViewBook->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑


}

void Administrator::logGraph()
{
    ui->tableViewLog->setFixedSize(599,389);
    logTable=new QSqlTableModel(this);
    logTable->setTable("log");
    logTable->select();
    ui->tableViewLog->setModel(logTable);
    ui->tableViewLog->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
}

/*
 * 查询按照isbn号查找
 */
void Administrator::queryBookFunction()
{
    if(ui->isbnEdit->text().isEmpty())
        QMessageBox::warning(this,"警告","你还未选择isbn号");
    else{
        int idTemp=ui->isbnEdit->text().toInt();
        bookTable->setFilter(QString("isbn=%1").arg(idTemp));//进行筛选
        bookTable->select();
    }
}

void Administrator::queryAllBookFunction()
{
    bookTable->setTable("book_info");
    bookTable->select();
}

void Administrator::ascBookOrderFun()
{
    bookTable->setSort(0,Qt::AscendingOrder);
    bookTable->select();
}

void Administrator::descBookOrderFun()
{
    bookTable->setSort(0,Qt::DescendingOrder);
    bookTable->select();
}

/*
 * 删除可以行删除也可以根据ISBN进行删除
 * 规定:isbn删除优先级高于行删除优先级
 */
void Administrator::delBookFun()
{
    if(ui->isbnEdit->text().isEmpty())
    {
        int curRow=ui->tableViewBook->currentIndex().row();  //获取选定行
    }else{

    }
    bookTable->removeRow(curRow);
}
