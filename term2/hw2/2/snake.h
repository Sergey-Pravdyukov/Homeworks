#pragma once

#include <iostream>
#include <QVector>

#include "output.h"

/*!
 * \brief This class for array bypass snake
 */
class Snake
{
public:
    /*!
     * \brief bypassSnake 2D array
     * \param size of array dimension
     * \param array
     */
    static QVector<int> bypassSnake(int &size, int **array);
private:
    /*!
     * \brief check going beyond the bounds of array
     */
    static bool check(const int &currentX, const int &currentY, const int &size);
};
