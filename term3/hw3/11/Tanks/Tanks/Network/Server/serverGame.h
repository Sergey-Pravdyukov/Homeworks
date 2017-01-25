#pragma once

#include <QMainWindow>
#include <QTcpServer>
#include "../Client/clientGame.h"

///Class provides server and client together
class ServerGame : public QObject
{
    Q_OBJECT
public:
    ///Constructor creates Server and ClientGame and waits for other client connection
    ServerGame(int port, QObject *parent = 0);
    ~ServerGame();
    void show();

private slots:
    ///Method connects the first player to the game and creates interaction between map and received socket
    void connectNewPlayer();

private:
    ///Has ownership
    QTcpServer *mServer;
    ///Has ownership
    ClientGame *mClient;
};
