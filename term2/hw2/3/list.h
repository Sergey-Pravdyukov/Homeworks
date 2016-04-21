#pragma once

#include "list.h"

using namespace std;

const int initListElement = 0;
const int initList = 0;

class List
{
public:
    class ListElement
    {
    public:
        ListElement(int currentValue)
        {
            value = currentValue;
        }
        int value = initListElement;
        ListElement *nextElement = nullptr;
    };
    void add(int value);
    void debugOutput();
    ListElement *headOfList = nullptr;
    ListElement *tailOfList = nullptr;
    List *nextList = nullptr;
    int sizeOfList = initList;
};
