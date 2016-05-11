#pragma once

#include <QString>

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
    /*!
     * \brief output element of array or comment
     * \param stringForOutput
     */
    void out(const QString &stringForOutput);
protected:
    const int sizeInit = 0;

    int size = sizeInit;
    int **array = nullptr;
};
