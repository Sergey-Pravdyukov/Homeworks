#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QWebView>

using namespace std;

namespace Ui {
class Bash;
}

class Bash : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bash(QWidget *parent = 0);
    ~Bash();
    static const int size = 10;

private slots:
    /*!
     * \brief load all web elements
     */
    void load();
    /*!
     * \brief switch to the next article
     */
    void nextClicked();
    /*!
     * \brief switch to the previous article
     */
    void prevClicked();
    /*!
     * \brief plus this article
     */
    void plusClicked();
    /*!
     * \brief minus this article
     */
    void minusClicked();
    /*!
     * \brief this article is bayan =(
     */
    void bayanClicked();

private:
    /*!
     * \brief show text and rating of this article
     * \param id
     */
    void generate(int id);
    /*!
     * \brief This method makes buttons enabled
     */
    void makeEnabled();
    /*!
     * \brief This method makes buttons disabled
     */
    void makeDisabled();
    Ui::Bash *ui;
    QWebView *view;
    int index;
    QPushButton *bayanButton;
    QPushButton *plusButton;
    QPushButton *minusButton;
    QPushButton *nextButton;
    QPushButton *prevButton;
    QLabel *rating;
    QTextEdit *quote;

    QString quotes[size];
    QString ratings[size];
    QString plusLinks[size];
    QString minusLinks[size];
    QString bayanLinks[size];
};

