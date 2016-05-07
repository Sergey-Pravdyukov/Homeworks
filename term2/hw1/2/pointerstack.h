#pragma once

#include "stack.h"

/*!
 * \brief The PointerStack class for working with pointer stack
 *
 * Determine the functions from Stack class
 */
class PointerStack : public Stack
{
public:
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
     * \brief lenght of PointerStack
     * \return
     */
    int lenght();
    /*!
     * \brief The StackElement class for element of pointer stack
     *
     * Contains value and pointer to next element
     */
private:
    class StackElement
    {
    public:
        StackElement(int currentValue)
        {
            value = currentValue;
        }

        int value = notANumber;
        /*!
         * \brief next StackElement in Stack
         */
        StackElement *next = nullptr;
    };

    /*!
     * \brief tail of pointer stack
     */
    StackElement *tail = nullptr;
};
