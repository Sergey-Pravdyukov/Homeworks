#pragma once

struct ListElementForDigits
{
    char value;
    ListElementForDigits *next;
};

struct StackForDigits
{
    ListElementForDigits *head;
    int size;
};

void push(StackForDigits *currentStack, char value);
char pop(StackForDigits *currentStack);
int sizeOfStack(StackForDigits *currentStack);
char top(StackForDigits *currentStack);
