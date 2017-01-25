#pragma once

#include <QWidget>
#include <QMessageBox>
#include <QVBoxLayout>
#include "../../MapManager/map.h"
#include "../GameSocket/gameSocket.h"

///Class provides client part of the game
class ClientGame : public QWidget
{
    Q_OBJECT
public:
    ClientGame();
    ///Constructor creates application window
    /// and socket to connect with other
    ClientGame(int port, QWidget *parent = 0);
    ~ClientGame();
    ///Method checks socket initialization
    /// (because we can init it later)
    bool socketNotCreated() const;
    ///Method inits socket using recieved socket
    /// and connects it with the map for their interaction
    void initSocket(QTcpSocket *playerSocket);

private slots:
    ///Slot closes the window and show message of the end
    void completeGame();

private:
    ///Has ownership
    Map *mMap;
    ///Has ownership
    GameSocket *mGameSocket;
    ///Method connects socket's and map's interaction
    void connectMapAndSocket();
    ///Method sets widget to show the map
    void setWidget();
};
