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
    /*!
     * \brief lenght of Stack
     * \return
     */
    virtual int lenght() = 0;
    /*!
     * \brief top of Stack
     * \return
     */
    virtual int top() = 0;
protected:
    int size = 0;

    /*!
     * \brief notANumber initialization constant for integer variables
     */
    static const int notANumber = INT_MIN;
};
