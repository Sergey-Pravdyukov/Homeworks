QT += core gui
QT += network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
	client.cpp

HEADERS  += client.h

FORMS    += client.ui
