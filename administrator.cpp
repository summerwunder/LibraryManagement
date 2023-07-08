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
    this->setFixedSize(799,657);
    this->bookGraph();
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

}

void Administrator::bookGraph()
{
    ui->tableWidget->setRowCount(15);
    ui->tableWidget->setColumnCount(5);
    QStringList listBuff;
    listBuff<<"ISBN";
    listBuff<<"书名";
    listBuff<<"作者";
    listBuff<<"出版社";
    listBuff<<"书本添加时间";
    // 设置对应的表头信息
    ui->tableWidget->setHorizontalHeaderLabels(listBuff);
    // 表头自由变化
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}
