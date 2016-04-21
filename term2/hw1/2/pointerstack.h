#pragma once

#include "stack.h"

const int init = 0;

/*!
 * \brief The PointerStack class for working with pointer stack
 *
 * Determine the functions from Stack class
 */
class PointerStack : public Stack
{
public:
    PointerStack(){}
    ~PointerStack();
    /*!
     * \brief push value to pointer stack
     */
    void push(int value);
    /*!
     * \brief pop element from pointer stack
     * \return element from tail of pointer stack
     */
    int pop();
    /*!
     * \brief debugOutput all pointer stack from head to tail
     */
    void debugOutput();
    /*!
     * \brief The StackElement class for element of pointer stack
     *
     * Contains value and pointer to next element
     */
    class StackElement
    {
    public:
        StackElement(int currentValue)
        {
            value = currentValue;
        }
        int value = init;
        StackElement *next = nullptr;
    };

private:
    /*!
     * \brief tail of pointer stack
     */
    StackElement *tail = nullptr;
};
