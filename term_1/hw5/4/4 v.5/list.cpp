#include <iostream>
#include "list.h"

using namespace std;

void add(List *currentList, char value)
{
	ListELement *newElement = new ListELement;
	newElement->value = value;
	newElement->next = nullptr;
	currentList->size++;
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