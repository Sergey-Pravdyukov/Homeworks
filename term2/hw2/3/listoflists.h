#pragma once

#include "list.h"
/*!
 * \brief The ListOfLists class is list which contains sorted by size lists
 */
class ListOfLists
{
public:
    ListOfLists(){}
    ~ListOfLists();
    void add(List addedList);
    void debugOutput();
private:
    List *headOfListOfLists = nullptr;
    List *tailOfListOfLists = nullptr;
    int sizeOfListOfLists = initInList;
};
