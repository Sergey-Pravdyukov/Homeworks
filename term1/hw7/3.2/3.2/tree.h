#pragma once
#include "myString.h"
#include <cstddef>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode;
struct Tree;
struct ElementsOfTree;

Tree *createTree();
bool addTreeNode(Tree *tree, String* x, int quantity);
bool addTreeNode(Tree *tree, String* x);
TreeNode **search(Tree *tree, String *x);
void clearTree(Tree *tree);
void fprintfTree(Tree* tree, FILE* stream);
ElementsOfTree* treeToArray(Tree* tree);
int heightOfTree(Tree* tree);
bool emptyTree(Tree* tree);
