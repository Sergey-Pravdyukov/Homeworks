QT += core
QT += testlib
QT -= gui

CONFIG += c++11

TARGET = 2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    set.h \
    avltree.h \
    testavltree.h
