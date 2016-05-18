QT += core
QT -= gui

CONFIG += c++11

TARGET = 1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    pointerlinkedlist.cpp \
    arraylinkedlist.cpp

HEADERS += \
    list.h \
    pointerlinkedlist.h \
    arraylinkedlist.h
