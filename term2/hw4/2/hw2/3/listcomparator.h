#pragma once

#include "list.h"

/*!
 * \brief The ListComparator class that compare two lists by size
 */
class ListComparator
{
public:
    /*!
     * \brief method for compare two Lists
     * \param firstList
     * \param secondList
     * \return true if firstList less than secondList otherwise false
     */
    static bool isFirstLessThanSecond(List *firstList, List *secondList);
};
