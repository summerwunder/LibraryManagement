#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>
#include <mysqlServer.h>
namespace Ui {
class ChangePassword;
}

class ChangePassword : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePassword(int id,QString password,QWidget *parent = nullptr);
    ~ChangePassword();
private slots:
    void sureButtonClicked();
private:
    Ui::ChangePassword *ui;
    QSqlQuery *query=MysqlServer::getInstance()->getQuery();
    QString password;
    int id;
};

#endif // CHANGEPASSWORD_H
