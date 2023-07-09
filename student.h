#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>
#include <QListWidget>
#include <protocol.h>
#include <QStringList>
#include <mysqlServer.h>
#include <book.h>
#include <QList>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QTextEdit>
#include <QSqlRecord>
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

private slots:
    void on_choiceComboBox_currentIndexChanged(int index);
    void tableViewClicked(const QModelIndex& index);

private:
    Ui::Student *ui;
    void initGraph();//初始化界面
    void initEdit();//初始化个人信息
    void borrowBook();
    void showMyRecord();//我的借阅
    void addTime();//续借
    void returnBook();
    void showAllBooks();
    void showReaderRating();


    int id;
    QString name;
    QString gender;
    QString tel;
    int borrowNum;//借阅书本数目
    int bookReadNum;//所有借阅数目
    int defyNum;//违规数目

    QSqlTableModel* infoTable;//个人信息
    QSqlTableModel* myTable;//表示个人所借阅书籍
    QSqlTableModel* mainTable;//在馆图书
    QSqlTableModel* userTable;//用户排行
    QSqlQuery* query=MysqlServer::getInstance()->getQuery();
};

#endif // STUDENT_H
