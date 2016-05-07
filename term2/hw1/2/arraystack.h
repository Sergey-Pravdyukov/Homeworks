#pragma once
#include "stack.h"

/*!
 * \brief The ArrayStack class for working with array stack
 *
 * Determine functions from Stack class
 */
class ArrayStack : public Stack
{
public:
    ~ArrayStack();

    /*!
     * \brief push value to array stack
     */
    void push(int value);
    /*!
     * \brief pop element from array stack
     * \return rightmost element of array stack
     */
    int pop();
    /*!
     * \brief debugOutput all array stack from left to right
     */
    void debugOutput();
    /*!
     * \brief lenght of ArrayStack
     */
    int lenght();
private:
    const int initMaxSize = 100;

    /*!
     * \brief maxSize of array stack
     */
    int maxSize = initMaxSize;
    /*!
     * \brief currentStack array for Stack
     */
    int *currentStack = new int[maxSize];

    /*!
     * \brief updateMaxSizeOfStack where size more than maxSize
     */
    void updateMaxSizeOfStack();
};
