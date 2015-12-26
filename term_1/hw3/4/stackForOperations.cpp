#include <iostream>
#include "stackForOperations.h"

void push(StackForOperations *currentStack, char value)
{
    ListElementForOperations *newElement = new ListElementForOperations {value, (currentStack->size) ? currentStack->head : nullptr};
    currentStack->head = newElement;
    ++currentStack->size;
}

char pop(StackForOperations *currentStack)
{
    if (currentStack->size != 0)
    {
        currentStack->head = currentStack->head->next;
        --currentStack->size;
    }
}

int sizeOfStack(StackForOperations *currentStack)
{
    return currentStack->size;
}

char top(StackForOperations *currentStack)
{
    char headElement = currentStack->head->value;
    return headElement;
}
