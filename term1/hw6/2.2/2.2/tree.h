#pragma once
#include <cstdio>

struct Tree;

struct Node;

Tree* createTree();
void deleteTree(Tree *tree);
void readTree(Tree *tree, FILE *file);
void printTree(Tree *tree);
int calculateTree(Tree *tree);