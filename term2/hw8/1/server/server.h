#include <QLabel>
#include <QtNetwork/QtNetwork>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QDialog>
#include <QMessageBox>


class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);

private slots:
    void sessionOpened();
    /**
     * @brief clientProcessing - обработка клиентского сокета
     */
    void clientProcessing();
    void sendMessage();
    void readingMessage();
    /**
     * @brief clientDisconnected - действия при разрыве связи с клиентом
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
