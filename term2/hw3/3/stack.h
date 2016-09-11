#pragma once

#include <QString>

/*!
 * \brief The Stack class for working with Stack
 *
 * Determine basics methods for Stack
 */
class Stack
{
public:
    /*!
     * \brief push element to Stack
     * \param value
     */
    void push(const QString &value);
    /*!
     * \brief pop element from Stack
     * \return
     */
    QString pop();
    /*!
     * \brief get top of Stack
     * \return
     */
    QString top();
    /*!
     * \brief get size of Stack
     * \return
     */
    int haveSize();
private:
    class StackElement
    {
    public:
        StackElement(const QString &currentValue)
        {
            value = currentValue;
        }
        const QString valueInit = "?";
        QString value = valueInit;
        StackElement *next = nullptr;
    };

    StackElement *head = nullptr;
    const int sizeInit = 0;
    int size = sizeInit;
};
