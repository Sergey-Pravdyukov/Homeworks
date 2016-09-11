#include <iostream>
#include "list.h"

using namespace std;

void add(List *currentList, char value)
{
	cout << value << endl;
	ListElement *newElement = new ListElement{ value, nullptr };
	++currentList->size;
	if (currentList->size == 1)
	{
		currentList->head = currentList->tail = newElement;
		return;
	}
	if (currentList->head->next == nullptr)
	{
		currentList->head->next = newElement;
	}
	currentList->tail->next = newElement;
	currentList->tail = currentList->tail->next;
}