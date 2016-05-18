#include "listcomparator.h"

bool ListComparator::isFirstLessThanSecond(List *firstList, List *secondList)
{
    return (firstList->lenght() < secondList->lenght());
}
