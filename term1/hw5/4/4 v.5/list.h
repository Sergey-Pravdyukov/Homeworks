#pragma once

struct ListELement
{
	char value;
	ListELement *next;
};

struct List
{
	ListELement *head;
	ListELement *tail;
	int size;
};

void add(List *currentList, char value);