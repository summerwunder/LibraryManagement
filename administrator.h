#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>
#include <QListWidget>
#include <QStringList>
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

    unsigned id;
    QString name;
};

#endif // ADMINISTRATOR_H
