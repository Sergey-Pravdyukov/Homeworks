#pragma once

#include "arraylinkedlist.h"

/*!
 * \brief This class for working with List whose each element is unique
 */
class UniqueList : public ArrayLinkedList
{
public:
    class ElementAlreadyExistsException : public std::exception
    {
    public:
        const char *what() const noexcept
        {
            return "Element already exists.";
        }
    };

    /*!
     * \brief add element to UniqueList
     * \param value
     */
    void add(const int &value) throw(ElementAlreadyExistsException);

};
