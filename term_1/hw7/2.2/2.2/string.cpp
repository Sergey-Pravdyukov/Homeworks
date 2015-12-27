#include "string.h"
#include <iostream>

using namespace std;

String createString(int size, int capacity) 
{
	String newString = { nullptr, size, capacity };
	return newString;
}

int sizeOfString(String *currentString)
{
	return currentString->size;
}

void debugOutput(String *currentString)
{
	for (int i = 0; i < currentString->size; ++i)
	{
		cout << currentString->data[i];
	}
	cout << endl;
}

void deleteString(String *currentString)
{
	const int capacity = int(1e3);
	char *data = new char[capacity];
	currentString->size = 0;
	currentString->data = data;
	currentString->capacity = capacity;
	delete data;
}

bool isEmpty(String *currentString)
{
	return (sizeOfString(currentString));
}

void add(String *currentString, char character)
{
	if (character == '\n')
	{
		return;
	}
	if (currentString->size + 1 >= currentString->capacity)
	{
		currentString->capacity *= 2;
	}
	if (currentString->size == 0)
	{
		char *data = new char[currentString->capacity];
		data[0] = character;
		currentString->size++;
		currentString->data = data;
		return;
	}
	currentString->data[currentString->size++] = character;
}

void input(String *currentString)
{
	char character = '~';
	int count = 0;
	while ((character = getchar()) != '\n' || count == 0)
	{
		add(currentString, character);
		++count;
	}
}

String clone(String *currentString, int left, int right)
{
	String newString = createString(0, currentString->capacity);
	for (int i = 0; i < currentString->size; ++i)
	{
		if (left <= i && i <= right)
		{
			add(&newString, currentString->data[i]);
		}
	}
	return newString;
}

bool isEqual(String *currentString)
{
	const int size = 0;
	const int capacity = int(1e3);
	String newString = { nullptr, size, capacity };
	input(&newString);
	if (sizeOfString(&newString) != sizeOfString(currentString))
	{
		return false;
	}
	for (int i = 0; i < currentString->size; ++i)
	{
		if (currentString->data[i] != newString.data[i])
		{
			return false;
		}
	}
	return true;
}

char* transformation(String *currentString)
{
	char *data = new char[currentString->size];
	for (int i = 0; i < currentString->size; ++i)
	{
		data[i] = currentString->data[i];
	}
	return data;
}

