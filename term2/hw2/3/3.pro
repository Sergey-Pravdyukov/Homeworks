QT += core
QT += testlib
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
    listcomparator.h \
    testlistcomparator.h \
    testlist.h \
    testlistoflists.h

DISTFILES += \
    thoughts.txt
