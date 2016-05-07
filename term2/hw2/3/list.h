#pragma once

#include "list.h"

using namespace std;

const int initInList = 0;

class List
{
public:
    List(){}
    class ListElement
    {
    public:
        ListElement(int currentValue)
        {
            value = currentValue;
        }
        int value = initInList;
        ListElement *nextElement = nullptr;
    };
    void add(int value);
    void debugOutput();
    ListElement *headOfList = nullptr;
    ListElement *tailOfList = nullptr;
    List *nextList = nullptr;///< pointer on next list in listOfLists
    int sizeOfList = initInList;
};
