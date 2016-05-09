#pragma once

#include "snake.h"

/*!
 * \brief This class for output 2D array
 */
class Output
{
public:
    /*!
     * \brief print 2D array
     */
    void print();
protected:
    const int sizeInit = 0;

    int size = sizeInit;
    int **array = nullptr;
};
