QT += core
QT += testlib
QT -= gui

CONFIG += c++11

TARGET = 3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    sharedpointer.h \
    testsharedpointer.h

DISTFILES += \
    output.txt
