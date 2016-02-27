QT += core
QT -= gui

CONFIG += c++11

TARGET = 2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    pointerstack.cpp \
    arraystack.cpp

HEADERS += \
    stack.h \
    pointerstack.h \
    arraystack.h
