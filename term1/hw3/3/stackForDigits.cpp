#include <iostream>
#include "stackForDigits.h"

void push(StackForDigits *currentStack, char value)
{
    ListElementForDigits *newElement = new ListElementForDigits {value, (currentStack->size) ? currentStack->head : nullptr};
    currentStack->head = newElement;
    ++currentStack->size;
}

char pop(StackForDigits *currentStack)
{
    if (currentStack->size != 0)
    {
        currentStack->head = currentStack->head->next;
        --currentStack->size;
    }
}

char top(StackForDigits *currentStack)
{
    char headElement = currentStack->head->value;
    return headElement;
}
