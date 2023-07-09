#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>
#include <QListWidget>
#include <QStringList>
#include <mysqlServer.h>
#include <book.h>
#include <QList>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <addstudialog.h>
#include <QStandardItemModel>
#include <QTextEdit>
namespace Ui {
class Administrator;
}

class Administrator : public QWidget
{
    Q_OBJECT

public:
    Administrator();
    explicit Administrator(unsigned id,QString name,QWidget *parent = nullptr);

    ~Administrator();

private:
    Ui::Administrator *ui;
    void initGraph();
    void bookGraph();
    void logGraph();
    void stuGraph();
    //图书操作
    void queryBookFunction();//查询的槽函数
    void queryAllBookFunction();//查询的槽函数
    void ascBookOrderFun();//升序
    void descBookOrderFun();//降序
    void delBookFun(); //删除
    void insertBookFun();//插入
    void updateBookFun();//更新
    //对日志操作
    void ascLogOrderFun();//升序
    void descLogOrderFun();//降序
    //对学生操作
    void queryStuFun();//查询学生借阅信息
    void addStuFun();
    void delStuFun();
    void updateStuFun();


    unsigned id;//工号
    QString name;//姓名
    QSqlTableModel* bookTable;

    QSqlQueryModel *logModel;
    QSqlTableModel* logTable;

    QSqlTableModel* stuTable;
    QSqlQueryModel *stuModel;
};

#endif // ADMINISTRATOR_H
