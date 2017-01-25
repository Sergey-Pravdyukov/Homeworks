#pragma once

#include <QTcpSocket>
#include "../../MapManager/map.h"

///Class provides socket for current game. It can read and send commands.
class GameSocket : public QTcpSocket
{
    Q_OBJECT
public:
    ///Constructor creates new socket by post and hostname
    GameSocket(const QString &strHost, int port);
    ///Constructor creates socket by existing
    GameSocket(QTcpSocket *socket);
    ~GameSocket();

signals:
    ///Signal means that socket can read inputing data
    void readyRead();
    ///Signal means that enemy has changed with something command
    void enemyChanged(Map::Command);

public slots:
    ///Slot reads inputing data
    void read();
    ///Slot sends command in socket
    void sendCommand(Map::Command command);

private:
    ///Has ownership
    QTcpSocket *mSocket;
    qint16 mNextBlockSize;
};
