#pragma once

#include <iostream>

#include "list.h"
#include "listcomparator.h"

/*!
 * \brief This class contains List that contains other Lists
 */
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
    /*!
     * \brief lenght of ListOfLists
     * \return
     */
    int lenght() const;
    /*!
     * \brief
     * \return current head of ListOfLists
     */
    List *getHeadOfListOfLists();
private:
    const int sizeOfListOfListsInit = 0;

    List *headOfListOfLists = nullptr;
    int sizeOfListOfLists = sizeOfListOfListsInit;
};
