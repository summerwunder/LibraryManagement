/********************************************************************************
** Form generated from reading UI file 'addstudialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDIALOG_H
#define UI_ADDSTUDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddStuDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpinBox *idSpinBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *maleButton;
    QRadioButton *femaleButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *teleEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *usernameEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *passwordEdit;
    QPushButton *sureButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AddStuDialog)
    {
        if (AddStuDialog->objectName().isEmpty())
            AddStuDialog->setObjectName(QString::fromUtf8("AddStuDialog"));
        AddStuDialog->resize(493, 310);
        layoutWidget = new QWidget(AddStuDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 10, 351, 251));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        idSpinBox = new QSpinBox(layoutWidget);
        idSpinBox->setObjectName(QString::fromUtf8("idSpinBox"));

        horizontalLayout_5->addWidget(idSpinBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        nameEdit = new QLineEdit(layoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        maleButton = new QRadioButton(layoutWidget);
        maleButton->setObjectName(QString::fromUtf8("maleButton"));

        horizontalLayout_6->addWidget(maleButton);

        femaleButton = new QRadioButton(layoutWidget);
        femaleButton->setObjectName(QString::fromUtf8("femaleButton"));

        horizontalLayout_6->addWidget(femaleButton);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        teleEdit = new QLineEdit(layoutWidget);
        teleEdit->setObjectName(QString::fromUtf8("teleEdit"));

        horizontalLayout_2->addWidget(teleEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        usernameEdit = new QLineEdit(layoutWidget);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        horizontalLayout_3->addWidget(usernameEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        passwordEdit = new QLineEdit(layoutWidget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));

        horizontalLayout_4->addWidget(passwordEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        sureButton = new QPushButton(AddStuDialog);
        sureButton->setObjectName(QString::fromUtf8("sureButton"));
        sureButton->setGeometry(QRect(90, 270, 93, 29));
        cancelButton = new QPushButton(AddStuDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(260, 270, 93, 29));

        retranslateUi(AddStuDialog);

        QMetaObject::connectSlotsByName(AddStuDialog);
    } // setupUi

    void retranslateUi(QDialog *AddStuDialog)
    {
        AddStuDialog->setWindowTitle(QCoreApplication::translate("AddStuDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddStuDialog", "\345\255\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("AddStuDialog", "\345\247\223\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("AddStuDialog", "\346\200\247\345\210\253", nullptr));
        maleButton->setText(QCoreApplication::translate("AddStuDialog", "\347\224\267", nullptr));
        femaleButton->setText(QCoreApplication::translate("AddStuDialog", "\345\245\263", nullptr));
        label_4->setText(QCoreApplication::translate("AddStuDialog", "\347\224\265\350\257\235\345\217\267\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("AddStuDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_6->setText(QCoreApplication::translate("AddStuDialog", "\345\257\206\347\240\201", nullptr));
        sureButton->setText(QCoreApplication::translate("AddStuDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddStuDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStuDialog: public Ui_AddStuDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDIALOG_H
