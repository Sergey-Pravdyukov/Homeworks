#pragma once

#include <climits>

class Stack
{
public:
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual void debugOutput() = 0;
    virtual void top() = 0;

    const int notANumber = INT_MAX;
protected:
    virtual ~Stack(){}
    int size = 0;
};
