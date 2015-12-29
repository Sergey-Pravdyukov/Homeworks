#pragma once

struct Member
{
    int loyal;
    char* sirname;
};

struct ListElement
{
    Member value;
    ListElement *next;
};

struct List
{
    ListElement *head;
    ListElement *tail;
    int size;
};

void add(List *currentList, Member value);
ListElement remove(List *currentList, int value);
void output(List *currentList);
