#include <QLabel>
#include <QtNetwork/QtNetwork>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QDialog>
#include <QMessageBox>

/*!
 * \brief The Server class - chat server
 */
class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);

private slots:
    /*!
     * \brief open network session
     */
    void sessionOpened();
    /*!
     * \brief processing client socket
     */
    void clientProcessing();
    /*!
     * \brief send message to client
     */
    void sendMessage();
    /*!
     * \brief reading message from server
     */
    void readingMessage();
    /*!
     * \brief disconnect with client
     */
    void clientDisconnected();

private:
    QLabel *serverStatusLabel;
    QLabel *messageLabel;
    QPushButton *quitButton;
    QPushButton *sendMessageButton;
    QLineEdit *messageLineEdit;
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
    QNetworkSession *networkSession;
    QTextEdit *chatBox;
    quint16 blockSize;
};
