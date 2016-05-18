QT += core
QT += testlib
QT -= gui

CONFIG += c++11

TARGET = 2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    fileoutput.cpp \
    consoleoutput.cpp \
    output.cpp \
    snake.cpp

HEADERS += \
    consoleoutput.h \
    fileoutput.h \
    output.h \
    testprinter.h \
    snake.h

DISTFILES += \
    output.txt \
    input.txt
