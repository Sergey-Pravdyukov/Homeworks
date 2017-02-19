QT += core
QT += testlib
QT -= gui

CONFIG += c++11

TARGET = 1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    hashtable.cpp \
    hashh37.cpp \
    hashfaq6.cpp \
    hashly.cpp

HEADERS += \
    hash.h \
    hashtable.h \
    hashelement.h \
    hashh37.h \
    hashfaq6.h \
    hashly.h \
    testhashtable.h
