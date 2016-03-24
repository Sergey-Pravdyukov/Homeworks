#pragma once

template <typename Type>
class List
{
public:
    virtual void add(Type value) = 0;
    virtual void remove(Type value) = 0;
    virtual void debugOutput() = 0;
    virtual int lenght() = 0;
    virtual ~List(){}
protected:
    int size = 0;
};
