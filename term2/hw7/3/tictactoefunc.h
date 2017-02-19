#pragma once

#include <QString>

/*!
 * \brief This class for determines tic-tac-toe functionality
 */
class TicTacToeFunc
{
public:
    TicTacToeFunc();
    ~TicTacToeFunc();

    /*!
     * \brief enum for cells
     */
    enum States
    {
        stateFree,
        stateX,
        stateO
    };

    /*!
     * \brief enum shows current state of game
     */
    enum CurrentState
    {
        inProcess,
        winX,
        winO
    };

    /*!
     * \brief getCell
     * \param x
     * \param y
     * \return state of cells
     */
    States getCell(int x, int y);
    void makeMove(int x, int y);
    CurrentState getState();
    void updateState();
    /*!
     * \brief isFinished
     * \return true if all cells are filled or someone wins
     */
    bool isFinished();
    void changeSize(int newSize);
    int getSize();

private:
    enum Moves
    {
        moveX,
        moveO
    };

    Moves nextMove();
    /*!
     * \brief changeState
     * \param m
     * \return state of cell after player makes his move
     */
    States changeState(Moves m);
    void verticalWin();
    void horizontalWin();
    void mainDiagonalWin();
    void secondaryDiagonalWin();

    States **field;
    Moves move;
    CurrentState state;
    int size;
    int winSize;
};


