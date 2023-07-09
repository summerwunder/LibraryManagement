#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>
#include <QListWidget>
#include <QStringList>
#include <mysqlServer.h>
#include <book.h>
#include <QList>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QTextEdit>
namespace Ui {
class Student;
}

class Student : public QWidget
{
    Q_OBJECT

public:
    explicit Student(int id, QString name, QString gender, QString tel,
                     int borrowNum, int bookReadNum, int defyNum,QWidget *parent=nullptr) ;
    ~Student();
    Student();

private:
    Ui::Student *ui;
    void initGraph();//初始化界面
    void initEdit();//初始化个人信息
    void borrowBook();



    int id;
    QString name;
    QString gender;
    QString tel;
    int borrowNum;//借阅书本数目
    int bookReadNum;//所有借阅数目
    int defyNum;//违规数目

    QSqlTableModel* myTable;//表示个人所借阅书籍
    QSqlQuery* query=MysqlServer::getInstance()->getQuery();
};

#endif // STUDENT_H
