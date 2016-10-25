QT += core
QT -= gui
QT += testlib

CONFIG += c++11

TARGET = 1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    net.cpp \
    virus.cpp \
    operationsystem.cpp \
    testvirus.cpp

HEADERS += \
    computer.h \
    net.h \
    virus.h \
    operationsystem.h \
    nettest.h \
    testvirus.h
