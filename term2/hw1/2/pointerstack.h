#pragma once

#include "stack.h"

const int init = 0;

class PointerStack : public Stack
{
public:
    PointerStack(){}
    ~PointerStack();
    void push(int value);
    int pop();
    void debugOutput();
    void top();
    class StackElement
    {
    public:
        StackElement(int currentValue)
        {
            value = currentValue;
        }
        int value = init;
        StackElement *next = nullptr;
    };
private:
    void deleteTail(StackElement *tail);
    StackElement *tail = nullptr;
};
