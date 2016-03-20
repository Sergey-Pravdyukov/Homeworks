#pragma once
#include "list.h"

class ArrayLinkedList : public List
{
public:
    ArrayLinkedList();
    ~ArrayLinkedList();
    void add(int value);
    void remove(int value);
    void debugOutput();
private:
    int size;
    const int maxSize = int(1e3);
    int *array = new int[maxSize] ;
};

