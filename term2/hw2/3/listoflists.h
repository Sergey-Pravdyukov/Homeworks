#pragma once

#include "list.h"

const int initListOfLists = 0;

class ListOfLists
{
public:
    ListOfLists(){}
    ~ListOfLists();
    /*!
     * \brief add List to the ListOfLists
     */
    void add(List addedList);
    /*!
     * \brief debugOutput each List that contained in ListOfLists
     */
    void debugOutput();

    List *headOfListOfLists = nullptr;
    List *tailOfListOfLists = nullptr;
    int sizeOfListOfLists = initListOfLists;
};
