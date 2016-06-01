#include <QMainWindow>
#include <QMap>
#include <QPushButton>

#include "ticTacToeFunc.h"

using namespace std;

namespace Ui {
class TicTacToe;
}

/*!
 * \brief This class for game tic-tac-toe
 */
class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTacToe(QWidget *parent = 0);
    ~TicTacToe();

private slots:
    /*!
     * \brief generate - draws initial field
     */
    void generate();
    void buttonClicked();

private:
    Ui::TicTacToe *ui;
    QMap<QPushButton *, pair<int, int> > pos;
    TicTacToeFunc tic;

    /*!
     * \brief updateButton - set button's text's size correctly
     * \param button
     */
    void updateButton(QPushButton *button);
    void resizeEvent(QResizeEvent *event);

    /*!
     * \brief getCell
     * \param x
     * \param y
     * \return which player occupied this filed
     */
    QString getCell(int x, int y);

    /*!
     * \brief result
     * \return state of a game (In progress, X wins or O wins)
     */
    QString result();
    int size;
    bool firstDrawing;
};

