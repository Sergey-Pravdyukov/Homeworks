#pragma once

#include "list.h"

#include <iostream>

/*!
 * \brief This class determine basis methods for working with ArrayLinkedList
 */
class ArrayLinkedList : public List
{
public:
    ~ArrayLinkedList();

    class RemoveNonexistedElementException : public std::exception
    {
    public:
        const char *what() const noexcept
        {
            return "Removal of a non-existent element.";
        }
    };

    /*!
     * \brief add element to ArrayLinkedList
     * \param value
     */
    void add(const int &value);
    /*!
     * \brief remove element from ArrayLinkedList
     * \param value
     * \return
     */
    int remove(const int &value) throw(RemoveNonexistedElementException);
    /*!
     * \brief find element in ArrayLinkedList
     * \param value
     * \return
     */
    int find(const int &value);

    void debugOutput();
    /*!
     * \brief getLenght
     * \return lenght of ArrayLinkedList
     */
    int getLenght();

    int *elements = new int[maxSize];

    const int notFoundIndex = -1;

protected:
    const int maxSizeInit = 1;

    int maxSize = maxSizeInit;

private:

    void updateMaxSize(int &maxSize);
};
