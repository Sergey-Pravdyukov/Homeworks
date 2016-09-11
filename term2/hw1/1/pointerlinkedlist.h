#pragma once

#include "list.h"

class PointerLinkedList : public List
{
public:
    ~PointerLinkedList();

    class ListElement
    {
    public:
        ListElement(int currentValue)
        {
            value = currentValue;
        }
        int value = List::notANumber;
        ListElement *next = nullptr;
    };

    void add(int value);
    int remove(int value);
    void debugOutput();
    int lenght();

    ListElement *head = nullptr;
private:
    ListElement *tail = nullptr;
};
