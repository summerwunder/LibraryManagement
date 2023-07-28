#include "datelabel.h"
#include "ui_datelabel.h"

dateLabel::dateLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dateLabel)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    //获取当前时间
    ui->label->setText(QDateTime::currentDateTime().toString("yyyy年MM月dd日  hh:mm:ss"));
    //设定计时器，1s变化
    timer->start(1*1000);
    connect(timer,&QTimer::timeout,this,&dateLabel::updateTime);
}

dateLabel::~dateLabel()
{
    delete ui;
}
//展示当前实时时间
void dateLabel::updateTime()
{
    ui->label->setText(QDateTime::currentDateTime().toString("yyyy年MM月dd日  hh:mm:ss"));
}
