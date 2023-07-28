/********************************************************************************
** Form generated from reading UI file 'datelabel.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATELABEL_H
#define UI_DATELABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dateLabel
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *dateLabel)
    {
        if (dateLabel->objectName().isEmpty())
            dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->resize(128, 75);
        verticalLayout = new QVBoxLayout(dateLabel);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(dateLabel);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        retranslateUi(dateLabel);

        QMetaObject::connectSlotsByName(dateLabel);
    } // setupUi

    void retranslateUi(QWidget *dateLabel)
    {
        dateLabel->setWindowTitle(QCoreApplication::translate("dateLabel", "Form", nullptr));
        label->setText(QCoreApplication::translate("dateLabel", "time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dateLabel: public Ui_dateLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATELABEL_H
