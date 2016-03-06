#pragma once

#include "list.h"

const int init = -1;

class PointerLinkedList : public List
{
public:
    PointerLinkedList(){}
private:
    ~PointerLinkedList();
    class ListElement
    {
    public:
        ListElement(int currentValue)
        {
            value = currentValue;
        }
        int value = init;
        ListElement *next = nullptr;
    };
    void add(int value);
    void remove(int value);
    void debugOutput();
    int lenght();
    ListElement *head = nullptr;
    ListElement *tail = nullptr;
};
