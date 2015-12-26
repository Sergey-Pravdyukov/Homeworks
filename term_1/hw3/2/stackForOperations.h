#pragma once

struct ListElementForOperations
{
    char value;
    ListElementForOperations *next;
};

struct StackForOperations
{
    ListElementForOperations *head;
    int size;
};

void push(StackForOperations *currentStack, char value);
int sizeOfStack(StackForOperations *currentStack);
char pop(StackForOperations *currentStack);
char top(StackForOperations *currentStack);
