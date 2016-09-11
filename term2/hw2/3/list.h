#pragma once

#include "list.h"

#include <iostream>

/*!
 * \brief This class contains List of elements
 */
class List
{
public:
    ~List();

    /*!
     * \brief add ListElement to list
     * \param
     */
    void add(const int &value);
    /*!
     * \brief debugOutput of list from head to tail
     */
    void debugOutput() const;
    /*!
     * \brief lenght of List
     * \return
     */
    int lenght() const;
    /*!
     * \brief initialize currentList->nextList
     * \param new nextList
     */
    void nextListInit(List *newList);
    /*!
     * \brief next List
     * \return
     */
    List *next();
    /*!
     * \brief compare two List
     * \param firstList
     * \param secondList
     * \return true if it equal otherwise false
     */
    static bool isEqualLists(List *firstList, List *secondList);
    /*!
     * \brief transformation from List to array
     * \return
     */
    int *fromListToArray();
private:
    class ListElement
    {
    public:
        ListElement(const int &currentValue)
        {
            value = currentValue;
        }
        int value = valueInit;
        ListElement *nextElement = nullptr;
    private:
        const int valueInit = 0;
    };

    const int sizeOfListInit = 0;

    ListElement *headOfList = nullptr;
    ListElement *tailOfList = nullptr;
    /*!
     * \brief nextList in list of some lists
     */
    List *nextList = nullptr;
    int sizeOfList = sizeOfListInit;
};
