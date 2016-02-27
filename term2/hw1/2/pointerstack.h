#pragma once
#include "stack.h"

class PointerStack : public Stack
{
public:
    PointerStack();
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
            next = nullptr;
        }
        int value;
        StackElement *next;
    };
private:
    StackElement *head;
    StackElement *tail;
    int size;
};
