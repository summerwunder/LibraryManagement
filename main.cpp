#include "widget.h"

#include <QApplication>
#include<QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
int main(int argc, char *argv[])
{

    // 数据库对象创建
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    // 设置相关参数
    db.setHostName("localhost"); // 主机名(地址)
    db.setPort(3306); // 端口
    db.setDatabaseName("LibraryManagement");
    db.setUserName("root"); //用户名
    db.setPassword("123456"); //密码
   //测试连接
    if(!db.open())
    {
        qDebug()<<"连接失败数据库";
       //  QMessageBox::warning(this,"警告","连接失败");
    }
    else
    {
        qDebug()<<"连接成功数据库";
       // QMessageBox::information(this,"消息","连接成功");
    }
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
    /***
     *      ┌─┐       ┌─┐ + +
     *   ┌──┘ ┴───────┘ ┴──┐++
     *   │                 │
     *   │       ───       │++ + + +
     *   ███████───███████ │+
     *   │                 │+
     *   │       ─┴─       │
     *   │                 │
     *   └───┐         ┌───┘
     *       │         │
     *       │         │   + +
     *       │         │
     *       │         └──────────────┐
     *       │                        │
     *       │                        ├─┐
     *       │                        ┌─┘
     *       │                        │
     *       └─┐  ┐  ┌───────┬──┐  ┌──┘  + + + +
     *         │ ─┤ ─┤       │ ─┤ ─┤
     *         └──┴──┘       └──┴──┘  + + + +
     *                神兽保佑
     *               代码无BUG!
     */
}
