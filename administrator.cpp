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
    //删除书本
    connect(ui->delBookButton,&QPushButton::clicked,this,&Administrator::delBookFun);
    //插入书本
    connect(ui->addBookButton,&QPushButton::clicked,this,&Administrator::insertBookFun);
    //更新书本
    connect(ui->updateBookButton,&QPushButton::clicked,this,&Administrator::updateBookFun);
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
    int curRow=ui->tableViewBook->currentIndex().row();
    if(ui->isbnEdit->text().isEmpty()&&curRow==-1)//错误的操作
    {
        QMessageBox::warning(this,"警告","未选定删除对象，请重新操作");
        return;
    }
    int ret = QMessageBox::warning(this, "删除", "你确定要删除该行吗", QMessageBox::Yes | QMessageBox::No);
    if(ret==QMessageBox::No)
        return;
    if(ui->isbnEdit->text().isEmpty())
    {
        int curRow=ui->tableViewBook->currentIndex().row();  //获取选定行
        bookTable->removeRow(curRow);
        bookTable->select();
    }else{
        //判断是否存在该书本
        // 准备查询
        MysqlServer::getInstance()->getQuery()->prepare("select * from book_info where isbn = :id");
        MysqlServer::getInstance()->getQuery()->bindValue(":id", ui->isbnEdit->text().toInt());
        // 执行查询
        if (MysqlServer::getInstance()->getQuery()->exec()) {
            // 检查查询结果是否为空
            if (MysqlServer::getInstance()->getQuery()->next()) {
                // 如果结果不为空，那么书存在，可以进行删除操作
                MysqlServer::getInstance()->getQuery()->prepare("delete from book_info where isbn = :id");
                MysqlServer::getInstance()->getQuery()->bindValue(":id", ui->isbnEdit->text().toInt());
                if (MysqlServer::getInstance()->getQuery()->exec()) {
                    bookTable->select();
                }
            } else {
                //如果结果为空，那么书不存在，显示错误消息
                QMessageBox::warning(this, "错误", "不存在该书");
            }
        }
    }
}
/*
 * 插入操作：不能isbn重复
 *
 */
void Administrator::insertBookFun()
{
    QString newIsbn = ui->isbnEdit->text();
    // 先检查书是否已存在
    MysqlServer::getInstance()->getQuery()->prepare("SELECT * FROM book_info where isbn = :id");
    MysqlServer::getInstance()->getQuery()->bindValue(":id", newIsbn);
    MysqlServer::getInstance()->getQuery()->exec();
    if ( MysqlServer::getInstance()->getQuery()->next()) {//说明确实有数据
        QMessageBox::warning(this, "错误", "插入isbn不能相同");
        return;
    }
    // 执行插入操作
    int rowNum=bookTable->rowCount();
    bookTable->insertRow(rowNum);
    bookTable->setData(bookTable->index(rowNum,0),newIsbn);
    bookTable->setData(bookTable->index(rowNum,1),ui->booknameEdit->text());
    bookTable->setData(bookTable->index(rowNum,2),ui->authorEdit->text());
    bookTable->setData(bookTable->index(rowNum,3),ui->publisherEdit->text());
    bookTable->setData(bookTable->index(rowNum,4),QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    // 提交改动
    bookTable->submitAll() ;
}

void Administrator::updateBookFun()
{
    QString newIsbn = ui->isbnEdit->text();
    int rowNum = -1;
    for (int i = 0; i < bookTable->rowCount(); ++i)
    {
        if (bookTable->data(bookTable->index(i, 0)).toString() == newIsbn)
        {
            rowNum = i;
            break;
        }
    }
    if (rowNum == -1)
    {
       int ret = QMessageBox::warning(this, "错误", "未找到该isbn，是否进行添加操作", QMessageBox::Yes | QMessageBox::No);
       if(ret==QMessageBox::No)
            return;
       else{
           this->insertBookFun();
           return;
       }
    }
    // 更新数据
    bookTable->setData(bookTable->index(rowNum,1),ui->booknameEdit->text());
    bookTable->setData(bookTable->index(rowNum,2),ui->authorEdit->text());
    bookTable->setData(bookTable->index(rowNum,3),ui->publisherEdit->text());
    bookTable->setData(bookTable->index(rowNum,4),QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
}
