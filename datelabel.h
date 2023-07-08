#ifndef DATELABEL_H
#define DATELABEL_H

#include <QLabel>

class DateLabel : public QLabel
{
public:
    DateLabel();
    QString getText(){return "yes";}
};

#endif // DATELABEL_H
