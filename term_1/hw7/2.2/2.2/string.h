#pragma once

struct String
{
	char *data;
	int size;
	int capacity;
};

void add(String *currentString, char character);
void debugOutput(String *currentString);
void deleteString(String *currentString);
String clone(String *currentString, int left, int right);
int sizeOfString(String *currentString);
void input(String *currentString);
bool isEqual(String *currentString);
bool isEmpty(String *currentString);
char* transformation(String *currentString);
String createString(int size, int capacity);
