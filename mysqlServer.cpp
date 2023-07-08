#include <mysqlServer.h>
MysqlServer::MysqlServer()
{
    // 数据库对象创建
    this->db = QSqlDatabase::addDatabase("QODBC");
    // 设置相关参数
    db.setHostName(ADDRESS); // 主机名(地址)
    db.setPort(PORT); // 端口
    db.setDatabaseName(DATABASE);
    db.setUserName(USER); //用户名
    db.setPassword(PASSWORD); //密码
   //测试连接
    if (!db.open())
        qDebug() << "连接失败数据库";
    else
        qDebug() << "连接成功数据库";
    this->query=QSqlQuery(db);
}
