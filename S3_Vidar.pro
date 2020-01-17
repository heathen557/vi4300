#-------------------------------------------------
#
# Project created by QtCreator 2019-11-06T09:44:51
#
#-------------------------------------------------

QT       += core gui serialport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = VI4300
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    receserial_msg.cpp \
    qcustomplot.cpp \
    calhistogram_obj.cpp \
    regisitersetdialog.cpp \
    mcuupgradedialog.cpp \
    hex.cpp \
    highreact_dialog.cpp \
    historytof_dialog.cpp \
    devmanagement_dialog.cpp \
    pagewidget.cpp \
    adddev_dialog.cpp

HEADERS  += mainwindow.h \
    receserial_msg.h \
    qcustomplot.h \
    calhistogram_obj.h \
    regisitersetdialog.h \
    mcuupgradedialog.h \
    hex.h \
    highreact_dialog.h \
    historytof_dialog.h \
    devmanagement_dialog.h \
    pagewidget.h \
    adddev_dialog.h

FORMS    += mainwindow.ui \
    regisitersetdialog.ui \
    mcuupgradedialog.ui \
    highreact_dialog.ui \
    historytof_dialog.ui \
    devmanagement_dialog.ui \
    pagewidget.ui \
    adddev_dialog.ui

RESOURCES += \
    img.qrc

TRANSLATIONS = translate/myApp_EN.ts


OTHER_FILES += myapp.rc
RC_FILE += myapp.rc
