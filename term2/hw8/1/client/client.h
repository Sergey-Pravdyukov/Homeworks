#include <QtNetwork/QtNetwork>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLayout>
#include <QMessageBox>

/**
 * @brief The Client class - клиент чата
 */
class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);

private slots:
    void sessionOpened();
    /**
     * @brief displayError - обработка ошибок
     */
    void displayError(QAbstractSocket::SocketError socketError);
    void sendMessage();
    void readingMessage();
    void enableSendButton();
    /**
     * @brief serverDisconnected - действия при разрыве связи с сервером
     */
    void serverDisconnected();
    /**
     * @brief connectServer - соединение с сервером
     */
    void connectServer();

private:
    QDialogButtonBox *buttonBox;
    QLabel *hostLabel;
    QLabel *messageLabel;
    QLabel *portLabel;
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLineEdit *messageLineEdit;
    QLabel *statusLabel;
    QPushButton *quitButton;
    QPushButton *sendMessageButton;
    QPushButton *connectButton;
    QTcpSocket *tcpSocket;
    QNetworkSession *networkSession;
    QTextEdit *chatBox;
    quint16 blockSize;
};
