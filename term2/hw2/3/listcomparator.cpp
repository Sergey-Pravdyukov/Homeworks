#include <iostream>

#include "listcomparator.h"

enum {notFound, isEqual, firstLess, secondLess};

bool isEqualLists(List *firstList, List *secondList)
{
    if (firstList->sizeOfList != secondList->sizeOfList)
        return false;
    List::ListElement *elementOfFirstList = firstList->headOfList;
    List::ListElement *elementOfSecondList = secondList->headOfList;
    while (elementOfFirstList != nullptr)
    {
        if (elementOfFirstList->value != elementOfSecondList->value)
            return false;
        elementOfFirstList = elementOfFirstList->nextElement;
        elementOfSecondList = elementOfSecondList->nextElement;
    }
    return true;
}

int haveFindList(List *currentList, ListOfLists *currentListOfLists)
{
    List *newList = currentListOfLists->headOfListOfLists;
    while (newList != nullptr)
    {
        if (isEqualLists(newList, currentList))
            return newList->sizeOfList;
        newList = newList->nextList;
    }
    return notFound;
}

int ListComparator::haveCompareLists(List *firstList, List *secondList,
                                     ListOfLists *currentListOfLists)
{
    int sizeOfFirstList = haveFindList(firstList, currentListOfLists);
    int sizeOfSecondList = haveFindList(secondList, currentListOfLists);
    if (sizeOfFirstList == notFound || sizeOfSecondList == notFound)
        return notFound;
    if (sizeOfFirstList == sizeOfSecondList)
        return isEqual;
    return (sizeOfFirstList < sizeOfSecondList) ? firstLess : secondLess;
}
