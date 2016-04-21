#pragma once

#include <climits>

/*!
 * \brief The Stack abstract class for wotking with stack
 *
 * Determine basic methods for stack
 */
class Stack
{
public:
    virtual ~Stack(){}
    /*!
     * \brief push - add element to stack
     */
    virtual void push(int value) = 0;
    /*!
     * \brief pop element from stack
     * \return last element of stack
     */
    virtual int pop() = 0;
    /*!
     * \brief debugOutput all of stack
     */
    virtual void debugOutput() = 0;

    static const int notANumber = INT_MAX;

    int size = 0;
};
