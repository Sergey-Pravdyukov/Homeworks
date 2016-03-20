#pragma once

#include "list.h"

class ArrayLinkedList : public List
{
public:
    ArrayLinkedList(){}
private:
    ~ArrayLinkedList();
    void add(int value);
    void remove(int value);
    void debugOutput();
    int lenght();
    const int maxSize = int(1e3);
    int *array = new int[maxSize];
};
