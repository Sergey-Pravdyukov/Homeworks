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
    int order = 1;
    while (newList != nullptr)
    {
        newList->debugOutput();
        if (isEqualLists(newList, currentList))
            return order;
        ++order;
        newList = newList->nextList;
    }
    return notFound;
}

int ListComparator::haveCompareLists(List *firstList, List *secondList,
                                     ListOfLists *currentListOfLists)
{
    std::cout << "sad" << std::endl;
    int firstOrder = haveFindList(firstList, currentListOfLists);
    int secondOrder = haveFindList(secondList, currentListOfLists);
    std::cout << firstOrder << " " << secondOrder << std::endl;
    if (firstOrder == notFound || secondOrder == notFound)
        return notFound;
    if (firstOrder == secondOrder)
        return isEqual;
    return (firstOrder < secondOrder) ? firstLess : secondLess;
}
