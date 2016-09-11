QT += core
QT += testlib
QT -= gui

CONFIG += c++11

TARGET = 1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    avltree.h \
    testavltree.h \
    bag.h \
    testbag.h
