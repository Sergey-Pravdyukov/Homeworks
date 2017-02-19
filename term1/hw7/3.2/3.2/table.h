#pragma once
#include "myString.h"
#include "tree.h"
#include "qsort.h"
#include <cctype>

struct Table;
Table* createTable();
void addToTable(Table* &t, char* word);
void clearTable(Table *t);
Tree* findTree(Table* t, char* buffer);
void processTable(Table* t);
