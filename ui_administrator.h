/********************************************************************************
** Form generated from reading UI file 'administrator.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATOR_H
#define UI_ADMINISTRATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <datelabel.h>

QT_BEGIN_NAMESPACE

class Ui_Administrator
{
public:
    QStackedWidget *stackedWidget;
    QWidget *pageBook;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *isbnEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *booknameEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *authorEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *publisherEdit;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addBookButton;
    QPushButton *queryBookButton;
    QPushButton *queryAllBookButton;
    QPushButton *updateBookButton;
    QPushButton *delBookButton;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *ascBookOrder;
    QRadioButton *descBookOrder;
    QTableView *tableViewBook;
    QWidget *pageStu;
    QTableView *tableViewStu;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QPushButton *queryStuButton;
    QPushButton *addStuButton;
    QPushButton *delStuButton;
    QPushButton *updateStuButton;
    QPushButton *unreturnButton;
    QWidget *pageLog;
    QTableView *tableViewLog;
    QPushButton *logUpdate;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *logDesc;
    QRadioButton *logAsc;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *userName;
    QSpacerItem *horizontalSpacer_3;
    dateLabel *widget;
    QListWidget *listWidget;

    void setupUi(QWidget *Administrator)
    {
        if (Administrator->objectName().isEmpty())
            Administrator->setObjectName(QString::fromUtf8("Administrator"));
        Administrator->resize(777, 657);
        stackedWidget = new QStackedWidget(Administrator);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(150, 70, 641, 561));
        pageBook = new QWidget();
        pageBook->setObjectName(QString::fromUtf8("pageBook"));
        layoutWidget = new QWidget(pageBook);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 591, 541));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);

        horizontalLayout_5->addWidget(label_3);

        isbnEdit = new QLineEdit(layoutWidget);
        isbnEdit->setObjectName(QString::fromUtf8("isbnEdit"));
        isbnEdit->setFont(font);

        horizontalLayout_5->addWidget(isbnEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        booknameEdit = new QLineEdit(layoutWidget);
        booknameEdit->setObjectName(QString::fromUtf8("booknameEdit"));
        booknameEdit->setFont(font);

        horizontalLayout_4->addWidget(booknameEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);

        authorEdit = new QLineEdit(layoutWidget);
        authorEdit->setObjectName(QString::fromUtf8("authorEdit"));
        authorEdit->setFont(font);

        horizontalLayout_3->addWidget(authorEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_2->addWidget(label_6);

        publisherEdit = new QLineEdit(layoutWidget);
        publisherEdit->setObjectName(QString::fromUtf8("publisherEdit"));
        publisherEdit->setFont(font);

        horizontalLayout_2->addWidget(publisherEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        addBookButton = new QPushButton(layoutWidget);
        addBookButton->setObjectName(QString::fromUtf8("addBookButton"));
        addBookButton->setFont(font);

        verticalLayout_3->addWidget(addBookButton);

        queryBookButton = new QPushButton(layoutWidget);
        queryBookButton->setObjectName(QString::fromUtf8("queryBookButton"));
        queryBookButton->setFont(font);

        verticalLayout_3->addWidget(queryBookButton);

        queryAllBookButton = new QPushButton(layoutWidget);
        queryAllBookButton->setObjectName(QString::fromUtf8("queryAllBookButton"));
        queryAllBookButton->setFont(font);

        verticalLayout_3->addWidget(queryAllBookButton);

        updateBookButton = new QPushButton(layoutWidget);
        updateBookButton->setObjectName(QString::fromUtf8("updateBookButton"));
        updateBookButton->setFont(font);

        verticalLayout_3->addWidget(updateBookButton);

        delBookButton = new QPushButton(layoutWidget);
        delBookButton->setObjectName(QString::fromUtf8("delBookButton"));
        delBookButton->setFont(font);

        verticalLayout_3->addWidget(delBookButton);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ascBookOrder = new QRadioButton(layoutWidget);
        ascBookOrder->setObjectName(QString::fromUtf8("ascBookOrder"));
        ascBookOrder->setFont(font);

        verticalLayout_2->addWidget(ascBookOrder);

        descBookOrder = new QRadioButton(layoutWidget);
        descBookOrder->setObjectName(QString::fromUtf8("descBookOrder"));
        descBookOrder->setFont(font);

        verticalLayout_2->addWidget(descBookOrder);


        horizontalLayout_6->addLayout(verticalLayout_2);

        horizontalLayout_6->setStretch(2, 10);

        verticalLayout_4->addLayout(horizontalLayout_6);

        tableViewBook = new QTableView(layoutWidget);
        tableViewBook->setObjectName(QString::fromUtf8("tableViewBook"));
        QFont font1;
        font1.setPointSize(10);
        tableViewBook->setFont(font1);
        tableViewBook->setTextElideMode(Qt::ElideMiddle);

        verticalLayout_4->addWidget(tableViewBook);

        stackedWidget->addWidget(pageBook);
        pageStu = new QWidget();
        pageStu->setObjectName(QString::fromUtf8("pageStu"));
        tableViewStu = new QTableView(pageStu);
        tableViewStu->setObjectName(QString::fromUtf8("tableViewStu"));
        tableViewStu->setGeometry(QRect(10, 130, 600, 411));
        layoutWidget1 = new QWidget(pageStu);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 601, 111));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        queryStuButton = new QPushButton(layoutWidget1);
        queryStuButton->setObjectName(QString::fromUtf8("queryStuButton"));
        queryStuButton->setFont(font);

        gridLayout->addWidget(queryStuButton, 4, 1, 1, 1);

        addStuButton = new QPushButton(layoutWidget1);
        addStuButton->setObjectName(QString::fromUtf8("addStuButton"));
        addStuButton->setFont(font);
        addStuButton->setFocusPolicy(Qt::StrongFocus);
        addStuButton->setContextMenuPolicy(Qt::DefaultContextMenu);
        addStuButton->setAutoFillBackground(false);
        addStuButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(addStuButton, 0, 0, 1, 1);

        delStuButton = new QPushButton(layoutWidget1);
        delStuButton->setObjectName(QString::fromUtf8("delStuButton"));
        delStuButton->setFont(font);

        gridLayout->addWidget(delStuButton, 4, 0, 1, 1);

        updateStuButton = new QPushButton(layoutWidget1);
        updateStuButton->setObjectName(QString::fromUtf8("updateStuButton"));
        updateStuButton->setFont(font);
        updateStuButton->setContextMenuPolicy(Qt::PreventContextMenu);
        updateStuButton->setCheckable(false);
        updateStuButton->setAutoRepeat(false);
        updateStuButton->setFlat(false);

        gridLayout->addWidget(updateStuButton, 1, 0, 1, 1);

        unreturnButton = new QPushButton(layoutWidget1);
        unreturnButton->setObjectName(QString::fromUtf8("unreturnButton"));
        unreturnButton->setFont(font);

        gridLayout->addWidget(unreturnButton, 0, 1, 1, 1);

        stackedWidget->addWidget(pageStu);
        pageLog = new QWidget();
        pageLog->setObjectName(QString::fromUtf8("pageLog"));
        tableViewLog = new QTableView(pageLog);
        tableViewLog->setObjectName(QString::fromUtf8("tableViewLog"));
        tableViewLog->setGeometry(QRect(10, 90, 591, 451));
        tableViewLog->setFont(font1);
        logUpdate = new QPushButton(pageLog);
        logUpdate->setObjectName(QString::fromUtf8("logUpdate"));
        logUpdate->setGeometry(QRect(20, 30, 93, 41));
        QFont font2;
        font2.setPointSize(13);
        logUpdate->setFont(font2);
        layoutWidget2 = new QWidget(pageLog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(380, 0, 221, 77));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        logDesc = new QRadioButton(layoutWidget2);
        logDesc->setObjectName(QString::fromUtf8("logDesc"));
        QFont font3;
        font3.setPointSize(14);
        logDesc->setFont(font3);

        verticalLayout_5->addWidget(logDesc);

        logAsc = new QRadioButton(layoutWidget2);
        logAsc->setObjectName(QString::fromUtf8("logAsc"));
        logAsc->setFont(font3);

        verticalLayout_5->addWidget(logAsc);

        stackedWidget->addWidget(pageLog);
        layoutWidget3 = new QWidget(Administrator);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(12, 14, 751, 55));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(158, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget3);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223")});
        font4.setPointSize(26);
        label->setFont(font4);

        horizontalLayout->addWidget(label);

        userName = new QLabel(layoutWidget3);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setFont(font1);

        horizontalLayout->addWidget(userName);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        widget = new dateLabel(layoutWidget3);
        widget->setObjectName(QString::fromUtf8("widget"));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Kristen ITC")});
        font5.setPointSize(10);
        font5.setItalic(false);
        widget->setFont(font5);

        horizontalLayout->addWidget(widget);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(4, 1);
        listWidget = new QListWidget(Administrator);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font6.setPointSize(16);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font6);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setFont(font6);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setFont(font6);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setFont(font6);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 80, 121, 531));
        QWidget::setTabOrder(booknameEdit, authorEdit);
        QWidget::setTabOrder(authorEdit, isbnEdit);

        retranslateUi(Administrator);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Administrator);
    } // setupUi

    void retranslateUi(QWidget *Administrator)
    {
        Administrator->setWindowTitle(QCoreApplication::translate("Administrator", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Administrator", "ISBN", nullptr));
        label_4->setText(QCoreApplication::translate("Administrator", "\344\271\246\345\220\215", nullptr));
        label_5->setText(QCoreApplication::translate("Administrator", "\344\275\234\350\200\205", nullptr));
        label_6->setText(QCoreApplication::translate("Administrator", "\345\207\272\347\211\210\347\244\276", nullptr));
        addBookButton->setText(QCoreApplication::translate("Administrator", "\346\267\273\345\212\240\344\271\246\346\234\254", nullptr));
        queryBookButton->setText(QCoreApplication::translate("Administrator", "\346\240\271\346\215\256ISBN\346\237\245\346\211\276", nullptr));
        queryAllBookButton->setText(QCoreApplication::translate("Administrator", "\346\237\245\347\234\213\346\211\200\346\234\211\344\271\246\346\234\254", nullptr));
        updateBookButton->setText(QCoreApplication::translate("Administrator", "\344\277\256\346\224\271\344\271\246\346\234\254\344\277\241\346\201\257", nullptr));
        delBookButton->setText(QCoreApplication::translate("Administrator", "\346\240\271\346\215\256ISBN\345\210\240\351\231\244", nullptr));
        ascBookOrder->setText(QCoreApplication::translate("Administrator", "\346\214\211\347\205\247isbn\345\215\207\345\272\217\346\216\222\345\210\227", nullptr));
        descBookOrder->setText(QCoreApplication::translate("Administrator", "\346\214\211\347\205\247isbn\351\231\215\345\272\217\346\216\222\345\210\227", nullptr));
        queryStuButton->setText(QCoreApplication::translate("Administrator", "\346\237\245\350\257\242\346\214\207\345\256\232\350\257\273\350\200\205\347\232\204\345\200\237\344\271\246\344\277\241\346\201\257", nullptr));
        addStuButton->setText(QCoreApplication::translate("Administrator", "\346\267\273\345\212\240\350\257\273\350\200\205", nullptr));
        delStuButton->setText(QCoreApplication::translate("Administrator", "\345\210\240\351\231\244\350\257\273\350\200\205", nullptr));
        updateStuButton->setText(QCoreApplication::translate("Administrator", "\346\233\264\346\224\271\350\257\273\350\200\205\344\277\241\346\201\257", nullptr));
        unreturnButton->setText(QCoreApplication::translate("Administrator", "\346\237\245\350\257\242\350\266\205\346\234\237\346\234\252\345\275\222\350\277\230\347\232\204\345\200\237\351\230\205\344\277\241\346\201\257", nullptr));
        logUpdate->setText(QCoreApplication::translate("Administrator", "\345\210\267\346\226\260", nullptr));
        logDesc->setText(QCoreApplication::translate("Administrator", "\346\214\211\347\205\247\346\227\266\351\227\264\351\231\215\345\272\217\346\216\222\345\210\227", nullptr));
        logAsc->setText(QCoreApplication::translate("Administrator", "\346\214\211\347\205\247\346\227\266\351\227\264\345\215\207\345\272\217\346\216\222\345\210\227", nullptr));
        label->setText(QCoreApplication::translate("Administrator", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        userName->setText(QCoreApplication::translate("Administrator", "zhanweifu", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Administrator", "\344\271\246\346\234\254\344\277\241\346\201\257", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Administrator", "\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Administrator", "\347\263\273\347\273\237\346\227\245\345\277\227", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("Administrator", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Administrator: public Ui_Administrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATOR_H
