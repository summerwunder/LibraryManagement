#ifndef DATELABEL_H
#define DATELABEL_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QDateTime>
namespace Ui {
class dateLabel;
}

class dateLabel : public QWidget
{
    Q_OBJECT

public:
    explicit dateLabel(QWidget *parent = nullptr);
    ~dateLabel();

private:
    Ui::dateLabel *ui;
    QTimer* timer;
    void updateTime();
};

#endif // DATELABEL_H
