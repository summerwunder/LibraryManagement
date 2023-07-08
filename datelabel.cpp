#include "datelabel.h"
#include "ui_datelabel.h"

dateLabel::dateLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dateLabel)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    ui->label->setText(QDateTime::currentDateTime().toString("yyyy年MM月dd日  hh:mm:ss"));
    timer->start(1*1000);
    connect(timer,&QTimer::timeout,this,&dateLabel::updateTime);
}

dateLabel::~dateLabel()
{
    delete ui;
}

void dateLabel::updateTime()
{
    ui->label->setText(QDateTime::currentDateTime().toString("yyyy年MM月dd日  hh:mm:ss"));
}
