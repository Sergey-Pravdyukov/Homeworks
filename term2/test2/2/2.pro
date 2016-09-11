QT += core
QT += testlib
QT -= gui

CONFIG += c++11

TARGET = 2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    iterator.cpp \
    avltree.cpp

HEADERS += \
    iterator.h \
    testavltree.h \
    testiterator.h
