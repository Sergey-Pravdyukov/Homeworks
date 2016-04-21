QT += core
QT -= gui

CONFIG += c++11

TARGET = 3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    list.cpp \
    listoflists.cpp \
    listcomparator.cpp

HEADERS += \
    list.h \
    listoflists.h \
    listcomparator.h

DISTFILES += \
    thoughts.txt
