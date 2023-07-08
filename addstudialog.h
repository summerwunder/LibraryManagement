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
private:
    Ui::AddStuDialog *ui;
};

#endif // ADDSTUDIALOG_H
