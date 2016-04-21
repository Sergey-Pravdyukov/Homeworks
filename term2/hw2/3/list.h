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
    /*!
     * \brief add ListElement to list
     * \param add with current value
     */
    void add(int value);

    /*!
     * \brief debugOutput of list from head to tail
     */
    void debugOutput();
    ListElement *headOfList = nullptr;
    ListElement *tailOfList = nullptr;
    /*!
     * \brief nextList in list of some lists
     */
    List *nextList = nullptr;
    int sizeOfList = initList;
};
