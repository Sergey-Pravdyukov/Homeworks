#pragma once

class Stack
{
public:
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual void debugOutput() = 0;
    virtual void top() = 0;
    const int notADigit = 10;
};
