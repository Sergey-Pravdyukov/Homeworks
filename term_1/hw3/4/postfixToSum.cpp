#include <iostream>
#include "postfixToSum.h"
#include "stackForDigits.h"
#include "comparator.h"

int havePostfixToSum(char a[], int size)
{
    StackForDigits currentStack = {nullptr, 0};
    for (int i = 0; i < size; ++i)
    {
        if (isDigit(a[i]))
        {
            push(&currentStack, a[i]);
        }
        if (isOperation(a[i]))
        {
            int firstDigit = int(top(&currentStack) - '0');
            pop(&currentStack);
            int secondDigit = int(top(&currentStack) - '0');
            pop(&currentStack);
            int result = 0;
            if (a[i] == '+')
            {
                result = firstDigit + secondDigit;
            }
            if (a[i] == '-')
            {
                result = secondDigit - firstDigit;
            }
            if (a[i] == '*')
            {
                result = firstDigit * secondDigit;
            }
            if (a[i] == '/')
            {
                result = secondDigit / firstDigit;
            }
            push(&currentStack, char(result + '0'));
        }
    }
    return int(top(&currentStack) - '0');
}
