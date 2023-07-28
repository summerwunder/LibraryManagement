/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePassword
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *originLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *changeLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *changeAgainLineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *sureButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QLabel *label_4;

    void setupUi(QWidget *ChangePassword)
    {
        if (ChangePassword->objectName().isEmpty())
            ChangePassword->setObjectName(QString::fromUtf8("ChangePassword"));
        ChangePassword->resize(432, 316);
        layoutWidget = new QWidget(ChangePassword);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 50, 351, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        originLineEdit = new QLineEdit(layoutWidget);
        originLineEdit->setObjectName(QString::fromUtf8("originLineEdit"));

        horizontalLayout->addWidget(originLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        changeLineEdit = new QLineEdit(layoutWidget);
        changeLineEdit->setObjectName(QString::fromUtf8("changeLineEdit"));
        changeLineEdit->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(changeLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        changeAgainLineEdit = new QLineEdit(layoutWidget);
        changeAgainLineEdit->setObjectName(QString::fromUtf8("changeAgainLineEdit"));

        horizontalLayout_3->addWidget(changeAgainLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        layoutWidget1 = new QWidget(ChangePassword);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 250, 351, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        sureButton = new QPushButton(layoutWidget1);
        sureButton->setObjectName(QString::fromUtf8("sureButton"));
        sureButton->setFont(font);

        horizontalLayout_4->addWidget(sureButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        cancelButton = new QPushButton(layoutWidget1);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_4->addWidget(cancelButton);

        label_4 = new QLabel(ChangePassword);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 10, 111, 31));
        QFont font1;
        font1.setPointSize(14);
        label_4->setFont(font1);

        retranslateUi(ChangePassword);

        QMetaObject::connectSlotsByName(ChangePassword);
    } // setupUi

    void retranslateUi(QWidget *ChangePassword)
    {
        ChangePassword->setWindowTitle(QCoreApplication::translate("ChangePassword", "Form", nullptr));
        label->setText(QCoreApplication::translate("ChangePassword", "\345\216\237\345\257\206\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("ChangePassword", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("ChangePassword", "\345\206\215\346\254\241\350\276\223\345\205\245", nullptr));
        sureButton->setText(QCoreApplication::translate("ChangePassword", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("ChangePassword", "\345\217\226\346\266\210", nullptr));
        label_4->setText(QCoreApplication::translate("ChangePassword", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePassword: public Ui_ChangePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
