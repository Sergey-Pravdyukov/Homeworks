QT += core
QT -= gui

CONFIG += c++11

TARGET = 2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    outputer.cpp \
    fileoutput.cpp \
    consoleoutput.cpp

HEADERS += \
    outputer.h \
    consoleoutput.h \
    fileoutput.h

DISTFILES += \
    output.txt \
    input.txt
