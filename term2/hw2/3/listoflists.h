#pragma once

#include "list.h"

const int initListOfLists = 0;

class ListOfLists
{
public:
    ListOfLists(){}
    ~ListOfLists();
    void add(List addedList);
    void debugOutput();

    List *headOfListOfLists = nullptr;
    List *tailOfListOfLists = nullptr;
    int sizeOfListOfLists = initListOfLists;
};
