#pragma once

template <class T>
class Comparator
{
public:
    virtual bool isFirstElementLessThanSecond(const T &firstElement, const T &secondElement) = 0;
};

