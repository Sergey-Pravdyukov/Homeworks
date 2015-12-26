#include "infixToPostfix.h"
#include "comparator.h"
#include "stackForOperations.h"
#include "postfixToSum.h"
#include <iostream>

int haveInfixToPostfix(char a[], int size)
{
    StackForOperations currentStack = {nullptr, 0};
    const int maxSize = int(1e4);
    char b[maxSize];
    int sizeOfCurrentStack = 0;
    for (int i = 0; i < size; ++i)
    {
        if (isDigit(a[i]))
        {
            b[sizeOfCurrentStack++] = a[i];
        }
        if (isOperation(a[i]))
        {
            push(&currentStack, a[i]);
        }
        if (isBracket(a[i]))
        {
            if (a[i] == '(')
            {
                push(&currentStack, a[i]);
            }
            else
            {
                while (sizeOfStack(&currentStack))
                {
                    char currentHead = top(&currentStack);
                    pop(&currentStack);
                    if (currentHead == '(')
                    {
                        break;
                    }
                    else
                    {
                        b[sizeOfCurrentStack++] = currentHead;
                    }
                }
            }
        }
    }
    while (sizeOfStack(&currentStack))
    {
        b[sizeOfCurrentStack++] = top(&currentStack);
        pop(&currentStack);
    }
    return havePostfixToSum(b, sizeOfCurrentStack);
}
