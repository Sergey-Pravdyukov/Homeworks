#include "startWindow.h"

StartWindow::StartWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *radioButtonLayout = new QHBoxLayout;
    mServerButton = new QRadioButton(tr("Server"));
    mServerButton->setChecked(true);
    radioButtonLayout->addWidget(mServerButton);
    mClientButton = new QRadioButton(tr("Client"));
    radioButtonLayout->addWidget(mClientButton);
    mainLayout->addLayout(radioButtonLayout);
    QLabel *infoLabel = new QLabel(tr("Input server port:"));
    mainLayout->addWidget(infoLabel);
    mPortLine = new QLineEdit;
    mainLayout->addWidget(mPortLine);
    QPushButton *creatingButton = new QPushButton(tr("Create"));
    mainLayout->addWidget(creatingButton);
    setLayout(mainLayout);
    connect(creatingButton, &QPushButton::clicked, this, &StartWindow::startGame);
}

StartWindow::~StartWindow()
{
    delete mServerButton;
    delete mClientButton;
    delete mPortLine;
}

void StartWindow::startGame()
{
    const int portNumber = mPortLine->text().toInt();
    if (mServerButton->isChecked())
    {
        ServerGame *newServerGame = new ServerGame(portNumber);
        newServerGame->show();
    }
    if (mClientButton->isChecked())
    {
        ClientGame *newClientGame = new ClientGame(portNumber);
        newClientGame->show();
    }
    close();
}
