#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QDialog(parent), tcpServer(0), clientSocket(0), networkSession(0),
    blockSize(0)
{
    serverStatusLabel = new QLabel(tr("Status"));
    messageLabel = new QLabel(tr("Message:"));
    quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);
    sendMessageButton = new QPushButton(tr("Send Message"));
    chatBox = new QTextEdit;
    chatBox->setReadOnly(true);
    messageLineEdit = new QLineEdit;
    messageLineEdit->setEnabled(false);
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered)
        {
            config = manager.defaultConfiguration();
        }
        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));
        serverStatusLabel->setText("Opening network session.");
        networkSession->open();
    }
    else
        sessionOpened();
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(serverStatusLabel, 0, 0);
    mainLayout->addWidget(messageLabel, 2, 0);
    mainLayout->addWidget(messageLineEdit, 3, 0);
    mainLayout->addWidget(sendMessageButton, 4, 0);
    mainLayout->addWidget(chatBox, 5, 0);
    mainLayout->addWidget(quitButton, 6, 0, 1, 2);
    setLayout(mainLayout);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(sendMessageButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(clientProcessing()));
    setWindowTitle("Server");
}

void Server::sessionOpened()
 {
     if (networkSession)
     {
         QNetworkConfiguration config = networkSession->configuration();
         QString id;
         if (config.type() == QNetworkConfiguration::UserChoice)
             id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
         else
             id = config.identifier();
     }

     tcpServer = new QTcpServer(this);
     if (!tcpServer->listen(QHostAddress::LocalHost, tcpServer->serverPort()))
     {
         QMessageBox::critical(this, "Server",
                               "Unable to start the server: " + tcpServer->errorString());
         close();
         return;
     }

     serverStatusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n")
                          .arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort()));
 }

void Server::clientProcessing()
{
    clientSocket = tcpServer->nextPendingConnection();
    sendMessageButton->setEnabled(true);
    messageLineEdit->setEnabled(true);
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readingMessage()));
    connect(clientSocket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
}

void Server::readingMessage()
{
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_1);
    if (blockSize == 0)
    {
        if (clientSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }
    if (clientSocket->bytesAvailable() < blockSize)
             return;
    blockSize = 0;
    QString newMessage;
    in >> newMessage;
    chatBox->textCursor().insertText("-client: " + newMessage + '\n');
}

void Server::sendMessage()
{
    if (clientSocket)
    {
        sendMessageButton->setEnabled(false);
        QString message = messageLineEdit->text();
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        messageLineEdit->clear();
        out << (quint16)message.length();
        out << message;
        clientSocket->write(block);
        chatBox->textCursor().insertText("- " + message + '\n');
        sendMessageButton->setEnabled(true);
    }
}

void Server::clientDisconnected()
{
    sendMessageButton->setEnabled(false);
    messageLineEdit->setEnabled(false);
    chatBox->textCursor().insertText("Client disconnected\n");
}
