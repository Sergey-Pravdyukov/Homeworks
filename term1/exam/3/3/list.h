#pragma once

struct ListElement
{
	char value;
	ListElement *next;
};

struct List
{
	ListElement *head;
	ListElement *tail;
	int size;
};

void add(List *currentList, char value);