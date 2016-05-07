#pragma once

#include "list.h"

class ArrayLinkedList : public List
{
public:
    ~ArrayLinkedList();

    void add(int value);
    int remove(int value);
    void debugOutput();
    int lenght();

    const int maxSize = int(1e3);

    int *array = new int[maxSize];
};
