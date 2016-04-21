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

private:
    /*!
     * \brief maxSize of array stack
     */
    const int maxSize = int(1e3);
    int *currentStack = new int[maxSize];
};
