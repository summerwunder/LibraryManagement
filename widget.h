#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <protocol.h>
#include <mysqlServer.h>
#include <administrator.h>
#include <student.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private:
    Ui::Widget *ui;
    void beautify();
    bool isEmpty();
private slots:
    void clicked_on_loginButton();
};
#endif // WIDGET_H
