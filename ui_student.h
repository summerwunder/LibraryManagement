/********************************************************************************
** Form generated from reading UI file 'student.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_H
#define UI_STUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <datelabel.h>

QT_BEGIN_NAMESPACE

class Ui_Student
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *userName;
    QSpacerItem *horizontalSpacer_3;
    dateLabel *widget;
    QPushButton *borrowButton;
    QPushButton *returnButton;
    QPushButton *longerTimeButton;
    QComboBox *choiceComboBox;
    QPushButton *passwordChangeButton;
    QSpinBox *isbnSpinBox;
    QTextEdit *infoText;
    QLabel *label_2;
    QPushButton *exitButton;
    QTableView *BookTableView;
    QLabel *label_3;
    QTableView *MytableView;

    void setupUi(QWidget *Student)
    {
        if (Student->objectName().isEmpty())
            Student->setObjectName(QString::fromUtf8("Student"));
        Student->resize(965, 720);
        layoutWidget = new QWidget(Student);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 911, 55));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(158, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223")});
        font.setPointSize(26);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        userName = new QLabel(layoutWidget);
        userName->setObjectName(QString::fromUtf8("userName"));
        QFont font1;
        font1.setPointSize(10);
        userName->setFont(font1);

        horizontalLayout->addWidget(userName);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        widget = new dateLabel(layoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Kristen ITC")});
        font2.setPointSize(10);
        font2.setItalic(false);
        widget->setFont(font2);

        horizontalLayout->addWidget(widget);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(4, 1);
        borrowButton = new QPushButton(Student);
        borrowButton->setObjectName(QString::fromUtf8("borrowButton"));
        borrowButton->setGeometry(QRect(740, 90, 111, 61));
        QFont font3;
        font3.setPointSize(12);
        borrowButton->setFont(font3);
        returnButton = new QPushButton(Student);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(310, 670, 111, 41));
        returnButton->setFont(font3);
        longerTimeButton = new QPushButton(Student);
        longerTimeButton->setObjectName(QString::fromUtf8("longerTimeButton"));
        longerTimeButton->setGeometry(QRect(60, 670, 111, 41));
        longerTimeButton->setFont(font3);
        choiceComboBox = new QComboBox(Student);
        choiceComboBox->addItem(QString());
        choiceComboBox->addItem(QString());
        choiceComboBox->setObjectName(QString::fromUtf8("choiceComboBox"));
        choiceComboBox->setGeometry(QRect(490, 100, 141, 51));
        choiceComboBox->setFont(font3);
        passwordChangeButton = new QPushButton(Student);
        passwordChangeButton->setObjectName(QString::fromUtf8("passwordChangeButton"));
        passwordChangeButton->setGeometry(QRect(30, 70, 91, 41));
        passwordChangeButton->setFont(font3);
        isbnSpinBox = new QSpinBox(Student);
        isbnSpinBox->setObjectName(QString::fromUtf8("isbnSpinBox"));
        isbnSpinBox->setGeometry(QRect(860, 90, 71, 61));
        infoText = new QTextEdit(Student);
        infoText->setObjectName(QString::fromUtf8("infoText"));
        infoText->setGeometry(QRect(30, 150, 421, 191));
        label_2 = new QLabel(Student);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 110, 101, 41));
        QFont font4;
        font4.setPointSize(14);
        label_2->setFont(font4);
        exitButton = new QPushButton(Student);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(130, 70, 93, 41));
        exitButton->setFont(font3);
        BookTableView = new QTableView(Student);
        BookTableView->setObjectName(QString::fromUtf8("BookTableView"));
        BookTableView->setGeometry(QRect(490, 160, 451, 531));
        label_3 = new QLabel(Student);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 350, 131, 31));
        label_3->setFont(font4);
        MytableView = new QTableView(Student);
        MytableView->setObjectName(QString::fromUtf8("MytableView"));
        MytableView->setGeometry(QRect(30, 390, 421, 271));
        QFont font5;
        font5.setPointSize(9);
        MytableView->setFont(font5);

        retranslateUi(Student);

        QMetaObject::connectSlotsByName(Student);
    } // setupUi

    void retranslateUi(QWidget *Student)
    {
        Student->setWindowTitle(QCoreApplication::translate("Student", "Form", nullptr));
        label->setText(QCoreApplication::translate("Student", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        userName->setText(QCoreApplication::translate("Student", "zhanweifu", nullptr));
        borrowButton->setText(QCoreApplication::translate("Student", "\345\200\237\351\230\205\345\233\276\344\271\246", nullptr));
        returnButton->setText(QCoreApplication::translate("Student", "\345\275\222\350\277\230\345\233\276\344\271\246", nullptr));
        longerTimeButton->setText(QCoreApplication::translate("Student", "\347\273\255\345\200\237\345\233\276\344\271\246", nullptr));
        choiceComboBox->setItemText(0, QCoreApplication::translate("Student", "\345\234\250\351\246\206\345\233\276\344\271\246", nullptr));
        choiceComboBox->setItemText(1, QCoreApplication::translate("Student", "\347\224\250\346\210\267\346\216\222\350\241\214\346\246\234", nullptr));

        passwordChangeButton->setText(QCoreApplication::translate("Student", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
#if QT_CONFIG(whatsthis)
        isbnSpinBox->setWhatsThis(QCoreApplication::translate("Student", "<html><head/><body><p>isbn\346\237\245\350\257\242</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_2->setText(QCoreApplication::translate("Student", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        exitButton->setText(QCoreApplication::translate("Student", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        label_3->setText(QCoreApplication::translate("Student", "\346\210\221\347\232\204\345\200\237\351\230\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student: public Ui_Student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_H
