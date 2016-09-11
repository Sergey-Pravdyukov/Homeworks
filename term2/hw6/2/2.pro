QT += core
QT += testlib
QT -= gui

CONFIG += c++11

TARGET = 2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    arraylinkedlist.cpp \
    uniquelist.cpp

HEADERS += \
    arraylinkedlist.h \
    arraylisttest.h \
    list.h \
    uniquelist.h \
    testuniquelist.h

DISTFILES += \
    output.txt
