#pragma once

#include <climits>

class List
{
public:
    virtual ~List(){}
    virtual void add(int value) = 0;
    virtual int remove(int value) = 0;
    virtual void debugOutput() = 0;
    virtual int lenght() = 0;
protected:
    const int sizeInit = 0;
    static const int notANumber = INT_MIN;

    int size = sizeInit;

};
