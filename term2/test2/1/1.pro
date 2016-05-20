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
    testbubblesort.h \
    bubblesort.h \
    comparator.h \
    numbercomparator.h \
    stringcomparator.h
