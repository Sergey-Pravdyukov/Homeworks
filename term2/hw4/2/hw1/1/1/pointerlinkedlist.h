#pragma once
#include "list.h"

using namespace std;

class PointerLinkedList : public List
{
public:
    PointerLinkedList();
    class ListElement
    {
    public:
        ListElement(int currentValue)
        {
            value = currentValue;
            next = nullptr;
        }
        int value;
        ListElement *next;
    };
    void add(int value);
    void remove(int value);
    void debugOutput();
private:
    ListElement *head;
    ListElement *tail;
    int size;
};
