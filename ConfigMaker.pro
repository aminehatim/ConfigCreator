#-------------------------------------------------
#
# Project created by QtCreator 2014-01-16T19:46:31
#
#-------------------------------------------------

QT       += core gui
QT      += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConfigMaker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configfileparser.cpp \
    descriptionfileparser.cpp \
    configfileeditor.cpp

HEADERS  += mainwindow.h \
    configfileparser.h \
    descriptionfileparser.h \
    configfileeditor.h

FORMS    += mainwindow.ui \
    configfileeditor.ui
