#pragma once
#include "list.h"

struct Contact
{
	List name;
	List number;
	Contact *next;
};

struct Phonebook
{
	Contact *head;
	Contact *tail;
	int size;
};

void addToPhonebook(Phonebook *currentPhonebook, char name[], char number[]);
void isFindByName(Phonebook *currentPhonebook, char name[]);
void isFindByNumber(Phonebook *currentPhonebook, char number[]);
void save(Phonebook *currentPhonebook, Phonebook *currentQueue);
void haveOutput(Phonebook *currentPhonebook);