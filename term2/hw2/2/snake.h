#pragma once

#include <iostream>
#include <stdio.h>
#include <QVector>
#include <QString>

#include "output.h"

/*!
 * \brief This class for array bypass snake
 */
class Snake
{
public:
    Snake(const bool &currentToOutput);

    /*!
     * \brief bypassSnake 2D array
     * \param size of array dimension
     * \param array
     * \param toOutput status of array operation
     *
     * if toOutput equals true then output element of array,
     * otherwise add element of array to QVector for test
     */
    void bypassSnake(int &size, int **array);
    /*!
     * \brief recieveElementsOfArray bypass snake in QVector
     * \return
     */
    QVector<int> recieveElementsOfArray();
private:
    const bool toOutputInit = true;

    QVector<int> elementsOfArray;
    /*!
     * \brief toOutput status of methods prepareItemsToAdd() and addItems()
     *
     * if toOutput equals true then output mode otherwise test mode
     * default output mode
     */
    bool toOutput = toOutputInit;

    /*!
     * \brief check going beyond the bounds of array
     */
    bool check(const int &currentX, const int &currentY, const int &size);
    /*!
     * \brief This method prepare for print or add to QVector
     */
    void prepareItemsToAdd();
    /*!
     * \brief addItems to print or QVector
     * \param added value
     */
    void addItems(const int &value);
};
