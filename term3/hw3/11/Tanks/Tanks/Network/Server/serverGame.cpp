#include "serverGame.h"

ServerGame::ServerGame(int port, QObject *parent) : QObject(parent), mServer(new QTcpServer()), mClient(new ClientGame())
{
    if (!mServer->listen(QHostAddress::Any, port))
    {
        QMessageBox::critical(0, "Server error", "Unable to start the server" + mServer->errorString());
        mServer->close();
        return;
    }
    connect(mServer, &QTcpServer::newConnection, this, &ServerGame::connectNewPlayer);
}

ServerGame::~ServerGame()
{
    delete mServer;
    delete mClient;
}

void ServerGame::show()
{
    mClient->show();
}

void ServerGame::connectNewPlayer()
{
    if (mClient->socketNotCreated())
        mClient->initSocket(mServer->nextPendingConnection());
}
