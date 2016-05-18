QT += core
QT += testlib
QT -= gui

CONFIG += c++11

TARGET = 1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    arraylinkedlist.cpp \
    pointerlinkedlist.cpp

HEADERS += \
    list.h \
    arraylinkedlist.h \
    pointerlinkedlist.h \
    pointerlisttest.h \
    arraylisttest.h
