QT += core
QT -= gui

CONFIG += c++11

TARGET = 2v1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    avltree.h \
    testavltree.h
