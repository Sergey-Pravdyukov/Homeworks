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

/*!
 * \brief The Client class - chat client
 */
class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);

private slots:
    void sessionOpened();
    /*!
     * \brief error handling
     */
    void displayError(QAbstractSocket::SocketError socketError);
    /*!
     * \brief send message to server
     */
    void sendMessage();
    /*!
     * \brief reading message from server
     */
    void readingMessage();
    /*!
     * \brief enable sendButton after connection
     */
    void enableSendButton();
    /*!
     * \brief disconnection with server
     */
    void serverDisconnected();
    /*!
     * \brief connection to server
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
