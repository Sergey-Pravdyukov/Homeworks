#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T09:13:59
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp \
    stack.cpp \
    sortingfacility.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    stack.h \
    sortingfacility.h

FORMS    += mainwindow.ui
