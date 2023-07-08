QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addstudialog.cpp \
    administrator.cpp \
    book.cpp \
    datelabel.cpp \
    main.cpp \
    mysqlServer.cpp \
    student.cpp \
    widget.cpp

HEADERS += \
    addstudialog.h \
    administrator.h \
    book.h \
    datelabel.h \
    mysqlServer.h \
    protocol.h \
    student.h \
    widget.h

FORMS += \
    addstudialog.ui \
    administrator.ui \
    datelabel.ui \
    student.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    init.sql
