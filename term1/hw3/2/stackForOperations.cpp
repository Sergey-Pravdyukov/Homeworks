#include <iostream>
#include "stackForOperations.h"

void push(StackForOperations *currentStack, char value)
{
    ListElementForOperations *newElement = new ListElementForOperations {value, (currentStack->size) ? currentStack->head : nullptr};
    currentStack->head = newElement;
    ++currentStack->size;
}

int sizeOfStack(StackForOperations *currentStack)
{
    return currentStack->size;
}

char pop(StackForOperations *currentStack)
{
    char result = '!';
    if (currentStack->size != 0)
    {
        result = currentStack->head->value;
        currentStack->head = currentStack->head->next;
        --currentStack->size;
    }
    return result;
}

char top(StackForOperations *currentStack)
{
    char headElement = currentStack->head->value;
    return headElement;
}

