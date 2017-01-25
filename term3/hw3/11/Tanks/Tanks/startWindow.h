#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "Network/Client/clientGame.h"
#include "Network/Server/serverGame.h"

///Class shows start window, where user can choose type of the application(Server or Client)
class StartWindow : public QWidget
{
    Q_OBJECT
public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private slots:
    ///Slot opens a map with player's tanks
    void startGame();

private:
    ///Has ownership
    QRadioButton *mServerButton;
    ///Has ownership
    QRadioButton *mClientButton;
    ///Has ownership
    QLineEdit *mPortLine;
};
