#pragma once

#include "output.h"

/*!
 * \brief This class for output 2D array to console
 */
class ConsoleOutput : public Output
{
public:
    ConsoleOutput(int **currentArray, const int &currentSize);

    void print(const QVector<int> &recordSnakeCrawling);
};

