#include "comparator.h"
#include <iostream>

bool isDigit(char current)
{
    return ('0' <= current && current <= '9');
}

bool isOperation(char current)
{
    int size = 4;
    const char dictionary[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < size; ++i)
    {
        if (current == dictionary[i])
        {
            return 1;
        }
    }
    return 0;
}

bool isBracket(char current)
{
    return (current == '(' || current == ')');
}
