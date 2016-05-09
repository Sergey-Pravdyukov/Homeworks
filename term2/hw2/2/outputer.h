#pragma once

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QVector>

class Outputer
{
public:
    void snakePrint(int &size, int **&array, const bool &toOutput);

    QVector<int> recieveBypassSnake();
private:
    /*!
     * \brief check going beyond the bounds of array
     */
    bool check(const int &currentX, const int &currentY, const int &size);

    QVector<int> bypassSnake;

    void prepareItemsToAdd(const bool &toOutput);

    void addItems(const bool &toOutput, const int &value);
};
