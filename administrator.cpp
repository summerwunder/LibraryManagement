#include "administrator.h"
#include "ui_administrator.h"

Administrator::Administrator()
{

}

Administrator::Administrator(unsigned id,QString name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrator)
{

    ui->setupUi(this);
    this->show();

    ui->label->setText(ui->label->getText());
    this->id=id;
    this->name=name;
}

Administrator::~Administrator()
{
    delete ui;
}
