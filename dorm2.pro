#-------------------------------------------------
#
# Project created by QtCreator 2016-12-08T21:14:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dorm2
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    dormitory.cpp \
    administrator.cpp \
    mysql.cpp

HEADERS  += login.h \
    dormitory.h \
    administrator.h \
    mysql.h

FORMS    += login.ui \
    dormitory.ui \
    administrator.ui
