#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QDialog(parent), networkSession(0), blockSize(0)
{
    hostLabel = new QLabel(tr("&Server name:"));
    portLabel = new QLabel(tr("S&erver port:"));
    messageLabel = new QLabel(tr("Message:"));
    hostCombo = new QComboBox;
    hostCombo->setEditable(true);


    // find out name of this machine
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty())
    {
        hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            hostCombo->addItem(name + QChar('.') + domain);
    }

    if (name != QString("localhost"))
        hostCombo->addItem(QString("localhost"));

    // find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    // add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (!ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    // add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    quitButton = new QPushButton(tr("Quit"));
    sendMessageButton = new QPushButton(tr("Send"));
    sendMessageButton->setEnabled(false);

    connectButton = new QPushButton(tr("Connect"));

    chatBox = new QTextEdit;
    chatBox->setReadOnly(true);

    messageLineEdit = new QLineEdit;
    messageLineEdit->setEnabled(false);

    portLineEdit = new QLineEdit;
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));


    hostLabel->setBuddy(hostCombo);
    portLabel->setBuddy(portLineEdit);

    statusLabel = new QLabel(tr("This examples requires that you run the "
                                    "Fortune Server example as well."));

    tcpSocket = new QTcpSocket(this);

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(connectButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(sendMessageButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);


    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(hostCombo, 0, 1);
    mainLayout->addWidget(portLabel, 1, 0);
    mainLayout->addWidget(portLineEdit, 1, 1);
    mainLayout->addWidget(messageLabel, 2, 0);
    mainLayout->addWidget(messageLineEdit, 2, 1);
    mainLayout->addWidget(chatBox, 3, 1);
    mainLayout->addWidget(statusLabel, 4, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 5, 0, 1, 2);
    setLayout(mainLayout);


    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(sendMessageButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(connectButton, SIGNAL(clicked()), this, SLOT(connectServer()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readingMessage()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(disableAddressChange()));
    setWindowTitle("Client");

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
                QNetworkConfiguration::Discovered)
            config = manager.defaultConfiguration();

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        connectButton->setEnabled(false);
        statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    }
}


void Client::readingMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_1);

    if (blockSize == 0)
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (tcpSocket->bytesAvailable() < blockSize)
             return;

    blockSize = 0;
    QString newMessage;
    in >> newMessage;
    chatBox->textCursor().insertText("- " + newMessage + '\n');
}

void Client::sendMessage()
{
    QString tmp = messageLineEdit->text();
    sendMessageButton->setEnabled(false);
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    messageLineEdit->clear();
    out << (quint16)tmp.length();
    out << tmp;
    tcpSocket->write(block);
    chatBox->textCursor().insertText("- " + tmp + '\n');
    sendMessageButton->setEnabled(true);
}

void Client::sessionOpened()
{
    // Save the used configuration
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        id = config.identifier();

    enableSendButton();
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, tr("Chat Client"),
                                     tr("The host was not found. Please check the "
                                        "host name and port settings."));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, tr("Chat Client"),
                                     tr("The connection was refused by the peer. "
                                        "Make sure the chat server is running, "
                                        "and check that the host name and port "
                                        "settings are correct."));
            break;
        default:
            QMessageBox::information(this, tr("Chat Client"),
                                     tr("The following error occurred: %1.")
                                     .arg(tcpSocket->errorString()));
        }

        connectButton->setEnabled(true);
}

void Client::enableSendButton()
{
    sendMessageButton->setEnabled((!networkSession || networkSession->isOpen()) &&
                                 !hostCombo->currentText().isEmpty() &&
                                 !portLineEdit->text().isEmpty());
}

void Client::serverDisconnected()
{
    chatBox->textCursor().insertText("Server disconnected\n");
    messageLineEdit->setEnabled(false);
}

void Client::connectServer()
{
    tcpSocket->abort();
    messageLineEdit->setEnabled(true);
    tcpSocket->connectToHost(hostCombo->currentText(), portLineEdit->text().toInt());

    if (tcpSocket->waitForConnected(3000))
    {
        enableSendButton();
        messageLineEdit->setEnabled(true);
        statusLabel->setText("Connected");
    }
    else
    {
        chatBox->textCursor().insertText("Connection timed out");
        messageLineEdit->setEnabled(false);
    }
}
