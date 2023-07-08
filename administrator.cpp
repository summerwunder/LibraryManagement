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
    this->bookGraph();
    this->logGraph();
    this->id=id;
    this->name=name;
    ui->userName->setText("用户："+this->name);



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
    bookTable->setEditStrategy(QSqlTableModel::OnManualSubmit);//手动更新
    bookTable->select();
    ui->tableViewBook->setModel(bookTable);
    ui->tableViewBook->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑


}

void Administrator::logGraph()
{
    ui->tableViewLog->setFixedSize(599,389);
    logTable=new QSqlTableModel(this);
    logTable->setTable("log");
    logTable->setEditStrategy(QSqlTableModel::OnManualSubmit);//手动更新
    logTable->select();
    ui->tableViewLog->setModel(logTable);
    ui->tableViewLog->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
}
