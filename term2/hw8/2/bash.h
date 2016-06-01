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
    void load();
    void nextClicked();
    void prevClicked();
    void plusClicked();
    void minusClicked();
    void bayanClicked();

private:
    void generate(int id);
    /*!
     * \brief This method makes buttons enabled
     */
    void makeEnabled();
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
