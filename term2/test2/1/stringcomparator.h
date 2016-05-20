#pragma once

#include <algorithm>

#include "comparator.h"

template <typename T>
/*!
 * \brief This class compare two elements of number type list
 */
class StringComparator : public Comparator<T>
{
public:
    /*!
     * \brief isFirstElementLessThanSecond
     * \param firstElement
     * \param secondElement
     * \return true if first element less than second otherwise false
     */
    bool isFirstElementLessThanSecond(const T &firstElement, const T &secondElement);
};

//------------------------------------------------------------------

template <typename T>
bool NumberComparator<T>::isFirstElementLessThanSecond(const T &firstElement, const T &secondElement)
{
    for (int i = 0; i < std::min(firstElement.size(), secondElement.size()); ++i)
    {
        if (firstElement[i] < secondElement[i])
    }

}
