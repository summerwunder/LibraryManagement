#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>
#include <QListWidget>
#include <QStringList>
#include <mysqlServer.h>
#include <book.h>
#include <QVector>
#include <QSqlTableModel>
#include <QMessageBox>
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
    //图书操作
    void queryBookFunction();//查询的槽函数
    void queryAllBookFunction();//查询的槽函数
    void ascBookOrderFun();//升序
    void descBookOrderFun();//降序
    void delBookFun(); //删除
    void insertBookFun();//插入
    void updateBookFun();//更新

    unsigned id;//工号
    QString name;//姓名
    QSqlTableModel* bookTable;
    QSqlTableModel* logTable;
};

#endif // ADMINISTRATOR_H
