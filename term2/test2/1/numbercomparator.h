#pragma once

#include "comparator.h"

template <typename T>
/*!
 * \brief This class compare two elements of number type list
 */
class NumberComparator : public Comparator<T>
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
    return (firstElement < secondElement);
}
