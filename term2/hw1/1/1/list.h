#pragma once

class List
{
public:
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void debugOutput() = 0;
};
