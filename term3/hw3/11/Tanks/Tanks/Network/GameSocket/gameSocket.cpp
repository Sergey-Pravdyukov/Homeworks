#include "gameSocket.h"

GameSocket::GameSocket(const QString &strHost, int port)
{
    mSocket = new QTcpSocket();
    mSocket->connectToHost(strHost, port);
    connect(mSocket, &QTcpSocket::readyRead, this, &GameSocket::read);
}

GameSocket::GameSocket(QTcpSocket *socket) : mSocket(socket), mNextBlockSize(0)
{
    connect(mSocket, &QTcpSocket::readyRead, this, &GameSocket::read);
}

GameSocket::~GameSocket()
{
    delete mSocket;
}

void GameSocket::read()
{
    QDataStream in(mSocket);
    in.setVersion(QDataStream::Qt_5_4);
    for (;;)
    {
        if (!mNextBlockSize)
        {
            if (mSocket->bytesAvailable() < sizeof(quint16))
                break;
            in >> mNextBlockSize;
        }
        if (mSocket->bytesAvailable() < mNextBlockSize)
            break;
        QString statusMessage = "";
        in >> statusMessage;
        if (statusMessage == "command")
        {
            int commandInt = 0;
            in >> commandInt;
            Map::Command command = static_cast<Map::Command>(commandInt);
            emit enemyChanged(command);
        }
        mNextBlockSize = 0;
    }
}

void GameSocket::sendCommand(Map::Command command)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    int commandInt = static_cast<int>(command);
    QString statusMessage = "command";
    out << quint16(0) << statusMessage << commandInt;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    mSocket->write(arrBlock);
}
