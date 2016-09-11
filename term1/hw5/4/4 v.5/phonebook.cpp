#include <iostream>
#include <fstream>
#include <cstring>
#include "phonebook.h"

using namespace std;

void stringAssignment(List *currentList, char string[])
{
	for (int i = 0; i < int(strlen(string)); ++i)
	{
		add(currentList, string[i]);
	}
}

void debugOutput(List *currentList)
{
	ListELement *currentElement = currentList->head;
	while (currentElement != nullptr)
	{
		cout << currentElement->value;
		currentElement = currentElement->next;
	}
	cout << endl;
}

void addToPhonebook(Phonebook *currentPhonebook, char name[], char number[])
{
	List newList = { nullptr, nullptr, 0 };
	Contact *newContact = new Contact{ newList, newList, nullptr };
	stringAssignment(&newContact->name, name);
	stringAssignment(&newContact->number, number);
	++currentPhonebook->size;
	if (currentPhonebook->size == 1)
	{
		currentPhonebook->head = currentPhonebook->tail = newContact;
		return;
	}
	if (currentPhonebook->head->next == nullptr)
	{
		currentPhonebook->head->next = newContact;
	}
	currentPhonebook->tail->next = newContact;
	currentPhonebook->tail = currentPhonebook->tail->next;
	cout << "  ###   " << currentPhonebook->size << endl;
	delete newContact;
}

bool isEqualStrings(List *currentList, char string[])
{
	if (currentList->size != strlen(string))
	{
		return false;
	}
	ListELement *currentElement = currentList->head;
	for (int i = 0; i < int(strlen(string)); ++i)
	{
		if (currentElement->value != string[i])
		{
			return false;
		}
		currentElement = currentElement->next;
	}
	return true;
}

void charOutput(char string[])
{
	for (int i = 0; i < int(strlen(string)); ++i)
	{
		cout << string[i];
	}
}

void isFindByName(Phonebook *currentPhonebook, char name[])
{
	Contact *currentContact = currentPhonebook->head;
	while (currentContact->next != nullptr)
	{
		if (isEqualStrings(&currentContact->name, name))
		{
			cout << "У контакта с именем ";
			charOutput(name); 
			cout << " номер ";
			debugOutput(&currentContact->number);
			cout << "." << endl;
			return;
		}
	}
	cout << "Контакт с таким именем не найден." << endl;
}

void isFindByNumber(Phonebook *currentPhonebook, char number[])
{
	Contact *currentContact = currentPhonebook->head;
	while (currentContact->next != nullptr)
	{
		if (isEqualStrings(&currentContact->number, number))
		{
			cout << "У контакта с именем ";
			debugOutput(&currentContact->name);
			cout << " номер ";
			charOutput(number);
			cout << "." << endl;
			return;
		}
	}
	cout << "Контакт с таким номером не найден." << endl;
}

void haveOutput(Phonebook *current)
{
	cout << "! " << current->size << endl;
	Contact *currentContact = current->head;
	while (currentContact != nullptr)
	{
		/*debugOutput(&currentContact->name); 
		cout << " ";
		debugOutput(&currentContact->number);
		cout << endl;*/
		currentContact = currentContact->next;
	}
}

void save(Phonebook *currentPhonebook, Phonebook *currentQueue)
{
	ofstream out("phonebook.txt");
	haveOutput(currentPhonebook);
	haveOutput(currentQueue);
	currentPhonebook = currentQueue = nullptr;
	out.close();
}