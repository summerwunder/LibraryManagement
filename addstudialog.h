#ifndef ADDSTUDIALOG_H
#define ADDSTUDIALOG_H

#include <QDialog>
#include <QString>
#include <QSpinBox>
namespace Ui {
class AddStuDialog;
}

class AddStuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStuDialog(QWidget *parent = nullptr);
    ~AddStuDialog();
    int getId();
    QString getName();
    QString getGender();
    QString getTele();
    QString getUsrName();
    QString getPassWord();
    void setInitData(int originId,QString originalUsername,QString originalPassword);//为更新学生信息而准备
    bool isGenderEmpty();//性别是否为空
private:
    Ui::AddStuDialog *ui;

};

#endif // ADDSTUDIALOG_H
