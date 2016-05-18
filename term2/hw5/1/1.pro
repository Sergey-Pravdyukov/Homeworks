QT += core
QT += testlib
QT -= gui

CONFIG += c++11

TARGET = 1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tree.cpp \
    parser.cpp \
    token.cpp \
    calculator.cpp

HEADERS += \
    tree.h \
    testtree.h \
    parser.h \
    token.h \
    calculator.h
