#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>
#include <QListWidget>
#include <QStringList>
#include <book.h>
#include <QVector>
#include <QSqlTableModel>

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

    unsigned id;//工号
    QString name;//姓名
    QSqlTableModel* bookTable;
    QSqlTableModel* logTable;
};

#endif // ADMINISTRATOR_H
