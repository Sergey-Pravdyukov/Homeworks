QT += core gui
QT += network
CONFIG += c++11 console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp\
    startWindow.cpp \
    Network/Client/clientGame.cpp \
    Network/Server/serverGame.cpp \
    Network/GameSocket/gameSocket.cpp \
    MapManager/map.cpp \
    MapManager/Shell/bigShell.cpp \
    MapManager/Shell/shell.cpp \
    MapManager/Shell/smallShell.cpp \
    MapManager/Explosion/explosionZone.cpp \
    MapManager/Landscape/landscape.cpp \
    MapManager/Tank/tank.cpp \
    MapManager/Flight/flightParameters.cpp

HEADERS  +=\
    startWindow.h \
    Network/Client/clientGame.h \
    Network/Server/serverGame.h \
    Network/GameSocket/gameSocket.h \
    MapManager/Shell/bigShell.h \
    MapManager/Shell/shell.h \
    MapManager/Shell/smallShell.h \
    MapManager/Explosion/explosionZone.h \
    MapManager/Landscape/landscape.h \
    MapManager/Tank/tank.h \
    MapManager/Flight/flightParameters.h \
    MapManager/map.h
