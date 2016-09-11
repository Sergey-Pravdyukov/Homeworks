#include "infixToPostfix.h"
#include "comparator.h"
#include "stackForOperations.h"
#include <iostream>

void haveInfixToPostfix(char a[], int size)
{
    StackForOperations currentStack = {nullptr, 0};
    for (int i = 0; i < size; ++i)
    {
        if (isDigit(a[i]))
        {
            std::cout << a[i];
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
                        std::cout << currentHead;
                    }
                }
            }
        }
    }
    while (sizeOfStack(&currentStack))
    {
        std::cout << top(&currentStack);
        pop(&currentStack);
    }
}
