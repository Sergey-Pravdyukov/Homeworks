#pragma once

#include <iostream>

#include "list.h"
#include "listcomparator.h"

class ListOfLists
{
public:
    ~ListOfLists();

    /*!
     * \brief add List to the ListOfLists
     */
    void add(List *addedList);
    /*!
     * \brief debugOutput each List that contained in ListOfLists
     */
    void debugOutput() const;
private:
    const int sizeOfListOfListsInit = 0;

    List *headOfListOfLists = nullptr;
    int sizeOfListOfLists = sizeOfListOfListsInit;
};
