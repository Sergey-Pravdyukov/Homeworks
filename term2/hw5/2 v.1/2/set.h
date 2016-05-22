#pragma once

template <typename T>
class Set
{
public:

    virtual void add(const T &currentValue) = 0;

    virtual T remove(const T &removingValue) = 0;

};

