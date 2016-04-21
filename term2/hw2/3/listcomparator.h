#pragma once

#include "list.h"
#include "listoflists.h"

/*!
 * \brief The ListComparator class that compare two lists by size
 */
class ListComparator
{
public:
    ListComparator();
    /*!
     * \param currentListOfLists for finding appropriate list
     * \return number that means one of lists has more size,
     * sizes are equal, or any list not finding
     */
    static int haveCompareLists(List *firstList, List *secondList,
                                ListOfLists *currentListOfLists);
};
