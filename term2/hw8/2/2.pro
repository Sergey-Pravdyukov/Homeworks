QT += core gui webkitwidgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2
TEMPLATE = app


SOURCES += main.cpp\
        bash.cpp

HEADERS += bash.h

FORMS += bash.ui
