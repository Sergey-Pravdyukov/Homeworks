#pragma once

struct ListElement
{
    int value;
    ListElement *next;
};

struct List
{
    ListElement *head;
    ListElement *tail;
    int size;
};

void add(List *currentList, int value);
void remove(List *currentList, int value);
void output(List *currentList);
int sizeOfList(List *currentList);
int topOfList(List *currentList);
