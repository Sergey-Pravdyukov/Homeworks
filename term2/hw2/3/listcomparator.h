#pragma once

#include "list.h"
#include "listoflists.h"

class ListComparator
{
public:
    ListComparator();
    static int haveCompareLists(List *firstList, List *secondList,
                                ListOfLists *currentListOfLists);
};
