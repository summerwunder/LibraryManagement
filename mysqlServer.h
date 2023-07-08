#ifndef MYSQLSERVER_H
#define MYSQLSERVER_H
#include <QSqlDatabase>
#include <protocol.h>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
class MysqlServer
{
public:
    //单例模式创建单个数据库句柄，防止多次建立数据库联系
    inline static MysqlServer* getInstance(){
        static MysqlServer mysqlServer;
        return &mysqlServer;
    }
    inline QSqlDatabase getDb(){return this->db;}
    inline QSqlQuery *getQuery(){return &this->query;}          //延长生命周期
private:
    MysqlServer();
    QSqlDatabase db;
    QSqlQuery query;

};

#endif // MYSQLSERVER_H
