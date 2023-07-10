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
    this->stuGraph();
    this->id=id;
    this->name=name;
    ui->userName->setText("管理员："+this->name);
    ui->stackedWidget->setCurrentIndex(0);

}

Administrator::~Administrator()
{
    delete ui;
}

void Administrator::initGraph()
{
    this->setFixedSize(799,657);
    this->setWindowTitle("管理员界面");
}

void Administrator::bookGraph()
{
    ui->tableViewBook->setFixedSize(589,325);
    bookTable=new QSqlTableModel(this);
    bookTable->setTable("book_info");

    bookTable->setEditStrategy(QSqlTableModel::OnFieldChange);//自动更新
    bookTable->select();
    ui->tableViewBook->setModel(bookTable);
    ui->tableViewBook->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    //设置列宽
    ui->tableViewBook->setColumnWidth(0, 60);
    ui->tableViewBook->setColumnWidth(1, 160);
    ui->tableViewBook->setColumnWidth(2, 120);
    ui->tableViewBook->setColumnWidth(3, 120);
    ui->tableViewBook->setColumnWidth(4, 120);
    bookTable->setHeaderData(0, Qt::Horizontal, "ISBN");
    bookTable->setHeaderData(1, Qt::Horizontal, "书名");
    bookTable->setHeaderData(2, Qt::Horizontal, "作者");
    bookTable->setHeaderData(3, Qt::Horizontal, "出版社");
    bookTable->setHeaderData(4, Qt::Horizontal, "添加时间");
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

void Administrator::logGraph()
{
    ui->tableViewLog->setFixedSize(599,501);
    logTable=new QSqlTableModel(this);
    logModel = new QSqlQueryModel;
    logTable->setTable("log");
    logTable->select();
    ui->tableViewLog->setModel(logTable);
    bookTable->setEditStrategy(QSqlTableModel::OnFieldChange);//自动更新
    ui->tableViewLog->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    ui->tableViewLog->setColumnWidth(0, 45);
    ui->tableViewLog->setColumnWidth(1, 166);
    ui->tableViewLog->setColumnWidth(2, 380);
    //关于排序日志
    connect(ui->logAsc,&QRadioButton::toggled,this,&Administrator::ascLogOrderFun);
    connect(ui->logDesc,&QRadioButton::toggled,this,&Administrator::descLogOrderFun);
    //刷新
    connect(ui->logUpdate,&QPushButton::clicked,this,&Administrator::descLogOrderFun);//其实就是重新输出
}

void Administrator::stuGraph()
{
    ui->tableViewLog->setFixedSize(600,411);
    stuTable=new QSqlTableModel(this);
    stuModel = new QSqlQueryModel;
    stuTable->setTable("stu");
    stuTable->select();

    ui->tableViewStu->setModel(stuTable);
    stuTable->setEditStrategy(QSqlTableModel::OnFieldChange);//自动更新
    ui->tableViewStu->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑

    ui->tableViewStu->setColumnWidth(0, 40);   // ID
    ui->tableViewStu->setColumnWidth(1, 80);   // 姓名
    ui->tableViewStu->setColumnWidth(2, 70);   // 性别
    ui->tableViewStu->setColumnWidth(3, 110);  // 电话号码
    ui->tableViewStu->setColumnWidth(4, 100);   // 借阅数量
    ui->tableViewStu->setColumnWidth(5, 100);   // 阅读量
    ui->tableViewStu->setColumnWidth(6, 100);   // 违规次数
    ui->tableViewStu->setColumnWidth(7, 0);   // 用户名
    ui->tableViewStu->setColumnWidth(8, 0);   //密码不显示
    // 修改字段名
    stuTable->setHeaderData(0, Qt::Horizontal, "学号");
    stuTable->setHeaderData(1, Qt::Horizontal, "姓名");
    stuTable->setHeaderData(2, Qt::Horizontal, "性别");
    stuTable->setHeaderData(3, Qt::Horizontal, "电话号码");
    stuTable->setHeaderData(4, Qt::Horizontal, "借阅数量");
    stuTable->setHeaderData(5, Qt::Horizontal, "阅读量");
    stuTable->setHeaderData(6, Qt::Horizontal, "违规次数");

    ui->tableViewStu->setModel(stuTable);

    connect(ui->addStuButton,&QPushButton::clicked,this,&Administrator::addStuFun);
    connect(ui->updateStuButton,&QPushButton::clicked,this,&Administrator::updateStuFun);
    connect(ui->delStuButton,&QPushButton::clicked,this,&Administrator::delStuFun);
    connect(ui->queryStuButton,&QPushButton::clicked,this,&Administrator::queryStuFun);
    connect(ui->unreturnButton,&QPushButton::clicked,this,&Administrator::unreturnFun);
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
//查看所有书本信息
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
        if(bookTable->removeRow(curRow))
             QMessageBox::information(this, "成功", "书本已删除");
        bookTable->select();
    }else{
        //判断是否存在该书本
        MysqlServer::getInstance()->getQuery()->prepare("select * from book_info where isbn = :id");
        MysqlServer::getInstance()->getQuery()->bindValue(":id", ui->isbnEdit->text().toInt());
        if (MysqlServer::getInstance()->getQuery()->exec())
        {
            // 检查查询结果是否为空
            if (MysqlServer::getInstance()->getQuery()->next())
            {
                // 如果结果不为空，那么书存在，可以进行删除操作
                MysqlServer::getInstance()->getQuery()->prepare("delete from book_info where isbn = :id");
                MysqlServer::getInstance()->getQuery()->bindValue(":id", ui->isbnEdit->text().toInt());
                if (MysqlServer::getInstance()->getQuery()->exec())
                {
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

    if(bookTable->submitAll())
    {
        QMessageBox::information(this,"提示","添加成功");
        ui->isbnEdit->clear();
        ui->booknameEdit->clear();
        ui->authorEdit->clear();
        ui->publisherEdit->clear();
    }
}
/* 按照isbn进行更新书本信息
 * 更新书本信息，先判断是否存在该isbh的书本
 *
 */
void Administrator::updateBookFun()
{
    QString newIsbn = ui->isbnEdit->text();
    int rowNum = -1;
    for (int i = 0; i < bookTable->rowCount(); ++i)
    {
        if (bookTable->data(bookTable->index(i, 0)).toString() == newIsbn)//存在这本书
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
    if(ui->booknameEdit->text().isEmpty()||ui->authorEdit->text().isEmpty()||
            ui->publisherEdit->text().isEmpty())
    {
        QMessageBox::information(this,"提示","有未填写的字段");
        return;
    }
    // 更新数据
    bookTable->setData(bookTable->index(rowNum,1),ui->booknameEdit->text());
    bookTable->setData(bookTable->index(rowNum,2),ui->authorEdit->text());
    bookTable->setData(bookTable->index(rowNum,3),ui->publisherEdit->text());
    bookTable->setData(bookTable->index(rowNum,4),QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    bookTable->select();
    QMessageBox::information(this,"提示","修改成功");
    ui->isbnEdit->clear();
    ui->booknameEdit->clear();
    ui->authorEdit->clear();
    ui->publisherEdit->clear();
}

void Administrator::ascLogOrderFun()
{
    logModel->setQuery("select * from log order by log_time ASC");
    ui->tableViewLog->setModel(logModel);
}

void Administrator::descLogOrderFun()
{
    logModel->setQuery("select * from log order by log_time DESC");
    ui->tableViewLog->setModel(logModel);
}

void Administrator::queryStuFun()
{
    // 获取要查询的学生的学号
    int curRow= ui->tableViewStu->currentIndex().row();
    if(curRow==-1)
    {
        QMessageBox::warning(this,"警告","未选定查找对象，请重新操作");
        return;
    }
    int stuId = stuTable->data(stuTable->index(curRow, 0)).toInt();
    // 构建 SQL 查询语句
    QString queryStr = "select b.name, r.recordTime, r.backTime "
                       "from book_record AS r "
                       "inner join stu AS s ON r.stu_id = s.id "
                       "inner join book_info AS b ON r.book_id = b.isbn "
                       "where s.id = :stuId and r.isOver=0";

    QSqlQuery *query=MysqlServer::getInstance()->getQuery();
    query->prepare(queryStr);
    query->bindValue(":stuId", stuId);
    if (query->exec())
    {
        if (query->exec())
        {
            QDialog* dialog = new QDialog(this);
            dialog->setWindowTitle("借阅记录");
            dialog->setModal(true);//先设为模态
            QVBoxLayout* layout = new QVBoxLayout(dialog);
            QTextEdit* textEdit = new QTextEdit(dialog);
            textEdit->setReadOnly(true);

            // 将查询结果填充到文本编辑器中
            QString result;
            while (query->next()) {
                QString bookName = query->value(0).toString();
                QString recordTime = query->value(1).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
                QString backTime = query->value(2).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
                result+="书名："+bookName+"\n借阅时间："+recordTime+"\n应归还时间："+backTime +"\n\n\n";
            }
            textEdit->setText(result);
            // 将文本编辑器添加到布局中
            layout->addWidget(textEdit);

            // 设置弹窗的大小和显示方式
            dialog->setFixedSize(400, 300);
            dialog->exec();
        }else {
            QMessageBox::warning(this, "错误", "无法执行查询：" + query->lastError().text());
        }
    }
}

void Administrator::addStuFun()
{
    AddStuDialog dialog(this);
    dialog.setWindowTitle("添加学生");

    if (dialog.exec() == QDialog::Accepted)
    {
        int id = dialog.getId();
        QString name = dialog.getName();
        QString gender = dialog.getGender();
        QString tele = dialog.getTele();
        QString username = dialog.getUsrName();
        QString password = dialog.getPassWord();
        if (name.isEmpty() || gender==nullptr || tele.isEmpty() || username.isEmpty() || password.isEmpty())
        {
             QMessageBox::warning(this, "错误", "请填写所有必填字段");
             return;
        }
        // 先检查学生是否已存在
        MysqlServer::getInstance()->getQuery()->prepare("SELECT * FROM stu WHERE id = :id");
        MysqlServer::getInstance()->getQuery()->bindValue(":id", id);
        MysqlServer::getInstance()->getQuery()->exec();
        if (MysqlServer::getInstance()->getQuery()->next())
        {
            QMessageBox::warning(this, "错误", "插入读者ID不能相同");
            return;
        }
        // 执行插入操作
        int rowNum = stuTable->rowCount();
        stuTable->insertRow(rowNum);
        stuTable->setData(stuTable->index(rowNum, 0), id);
        stuTable->setData(stuTable->index(rowNum, 1), name);
        stuTable->setData(stuTable->index(rowNum, 2), gender);
        stuTable->setData(stuTable->index(rowNum, 3), tele);
        stuTable->setData(stuTable->index(rowNum, 4), 0);  // 借阅数量初始化为0
        stuTable->setData(stuTable->index(rowNum, 5), 0);  // 阅读量初始化为0
        stuTable->setData(stuTable->index(rowNum, 6), 0);  // 违规次数初始化为0
        stuTable->setData(stuTable->index(rowNum, 7), username);
        stuTable->setData(stuTable->index(rowNum, 8), password);

        if(stuTable->submitAll())
            QMessageBox::information(this,"提示","添加读者成功");
        stuTable->select();
    }
}

void Administrator::delStuFun()
{
    int curRow=ui->tableViewStu->currentIndex().row();
    if(curRow==-1)
    {
        QMessageBox::warning(this,"警告","未选定删除对象，请重新操作");
        return;
    }
    if(QMessageBox::question(this, "确认删除", "确定要删除该读者吗？",QMessageBox::Yes | QMessageBox::No)==QMessageBox::No)return;
    if(stuTable->removeRow(curRow))
         QMessageBox::information(this, "成功", "读者已删除");
    stuTable->select();
}
/*
 * 管理员更新时无权限更改用户的id和账号密码
 *
 */
void Administrator::updateStuFun()
{
    AddStuDialog dialog(this);
    dialog.setWindowTitle("更新学生");
    int row = ui->tableViewStu->currentIndex().row();
    if (row < 0)
    {
       QMessageBox::information(this, "提示", "请先选中一个读者");
       return;
    }
    int id = stuTable->data(stuTable->index(row, 0)).toInt();
    QString username = stuTable->data(stuTable->index(row, 7)).toString();
    QString password = stuTable->data(stuTable->index(row, 8)).toString();
    dialog.setInitData(id, username, password);
    if (dialog.exec() == QDialog::Accepted)
    {
       if (dialog.getName().isEmpty() ||dialog.isGenderEmpty()||dialog.getTele().isEmpty())
       {
          QMessageBox::warning(this, "错误", "字段不能为空");
          return;
       }
       QSqlQuery* query=MysqlServer::getInstance()->getQuery();
       query->prepare("update stu set name = :name, gender = :gender, tel = :tele where id = :id");
       query->bindValue(":name", dialog.getName());
       query->bindValue(":gender",dialog.getGender());
       query->bindValue(":tele",dialog.getTele());
       query->bindValue(":id", id);
       if (query->exec())
       {
           QMessageBox::information(this, "成功", "读者信息已更新");
           stuTable->select();
       } else {
           QMessageBox::warning(this, "错误", "无法更新学生信息" );
       }
    }
}

//这是listWidget列表的槽函数，实现切换页面(ui界面自动生成）
void Administrator::on_listWidget_itemClicked(QListWidgetItem *item)
{
    int index = ui->listWidget->row(item);
    if(index==3)//exit
    {
        QMessageBox::information(this,"提示","欢迎下次使用");
        this->close();
    }
    ui->stackedWidget->setCurrentIndex(index);

}

void Administrator::unreturnFun()
{
    QSqlQuery* query=MysqlServer::getInstance()->getQuery();
    query->prepare("select * from unreturn_log");
    if (query->exec())
    {
        QDialog* dialog = new QDialog(this);
        dialog->setWindowTitle("未归还记录");
        dialog->setModal(true);//先设为模态
        QVBoxLayout* layout = new QVBoxLayout(dialog);
        QTextEdit* textEdit = new QTextEdit(dialog);
        textEdit->setReadOnly(true);
        // 将查询结果填充到文本编辑器中
        QString result;
        while (query->next()) {
            int stuId=query->value(1).toInt();
            QString stuName = query->value(2).toString();
            int bookId=query->value(3).toInt();
            QString bookName= query->value(4).toString();
            QString logTime = query->value(5).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
            result+="学号："+QString::number(stuId)+"\t姓名："+stuName+"\n";
            result+="ISBN："+QString::number(bookId)+"\t书名"+bookName+"\n";
            result+="记录时间："+logTime+"\n\n\n";
        }
        textEdit->setText(result);

        layout->addWidget(textEdit);
        dialog->setFixedSize(400, 300);
        dialog->exec();
    }else {
        QMessageBox::warning(this, "错误", "无法执行" + query->lastError().text());
    }
}

