#pragma once
#include <cstddef>
#include <string.h>
#include <cstdio>
#include <algorithm>

using namespace std;

struct String;

enum Comparison {
	equivalent = 0, 
	bigger, 
	smaller 
};


String *createString();
String *createGivenString(char *buffer);
void addToString(String *s, char *buffer);
void removeString(String *s);
Comparison compareString(String *s1, String *s2);
char *stringToChar(String *s);
String* clone(String* s);
char* allocateString(String *s, int begining, int end);
bool emptyString(String *s);
int lengthString(String *s);
