#include "clientGame.h"

ClientGame::ClientGame() : mMap(new Map()), mGameSocket(nullptr)
{
    setWidget();
}

ClientGame::ClientGame(int port, QWidget *parent) : QWidget(parent), mMap(new Map()),
    mGameSocket(new GameSocket("localhost", port))
{
    setWidget();
    connectMapAndSocket();
}

ClientGame::~ClientGame()
{
    delete mMap;
    delete mGameSocket;
}

bool ClientGame::socketNotCreated() const
{
    return (mGameSocket == nullptr);
}

void ClientGame::initSocket(QTcpSocket *playerSocket)
{
    mGameSocket = new GameSocket(playerSocket);
    connectMapAndSocket();
    mMap->makeFirst();
}

void ClientGame::completeGame()
{
    QMessageBox::information(0, tr("Game"), tr("Game is over"));
    close();
}

void ClientGame::connectMapAndSocket()
{
    connect(mMap, &Map::userChanged, mGameSocket, &GameSocket::sendCommand);
    connect(mGameSocket, &GameSocket::enemyChanged, mMap, &Map::updateEnemy);
    connect(mMap, &Map::gameIsOver, this, &ClientGame::completeGame);
}

void ClientGame::setWidget()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mMap);
    setLayout(mainLayout);
}
