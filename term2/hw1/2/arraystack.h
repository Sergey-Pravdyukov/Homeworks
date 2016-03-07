#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack(){}
    ~ArrayStack();
    void push(int value);
    int pop();
    void debugOutput();
    void top();
private:
    const int maxSize = int(1e3);
    int *currentStack = new int[maxSize];
};
