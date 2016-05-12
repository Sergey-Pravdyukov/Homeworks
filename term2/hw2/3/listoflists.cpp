#include "listoflists.h"

void ListOfLists::add(List *addedList)
{
    ++sizeOfListOfLists;
    if (sizeOfListOfLists == 1)
    {
        headOfListOfLists = addedList;
        return;
    }
    List *currentList = headOfListOfLists;
    List *precurrentList = nullptr;
    while (currentList != nullptr)
    {
        if (ListComparator::isFirstLessThanSecond(addedList, currentList))
        {
            addedList->nextListInit(currentList);
            if (precurrentList == nullptr)
                headOfListOfLists = addedList;
            else
                precurrentList->nextListInit(addedList);
            return;
        }
        else
        {
            precurrentList = currentList;
            currentList = currentList->next();
        }
    }
    precurrentList->nextListInit(addedList);
}

void ListOfLists::debugOutput() const
{
    if (sizeOfListOfLists == 0)
    {
        std::cout << std::endl << "List of lists is empty" << std::endl;
        return;
    }
    List *currentList = headOfListOfLists;
    while (currentList != nullptr)
    {
        currentList->debugOutput();
        currentList = currentList->next();
    }
}

ListOfLists::~ListOfLists()
{
    while (headOfListOfLists != nullptr)
    {
        List *nextList = headOfListOfLists->next();
        headOfListOfLists->~List();
        delete headOfListOfLists;
        headOfListOfLists = nextList;
    }
}

