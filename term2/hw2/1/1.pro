QT += core
QT -= gui

CONFIG += c++11

TARGET = 1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    bubblesort.cpp \
    quicksort.cpp \
    heapsort.cpp \
    sort.cpp

HEADERS += \
    sort.h \
    bubblesort.h \
    quicksort.h \
    heapsort.h
