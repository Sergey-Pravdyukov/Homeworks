#include "tree.h"
#include <cstddef>
#include <cstdio>
#include <algorithm>
using namespace std;

struct TreeNode
{
	int value;
	int height;
	TreeNode *leftChild;
	TreeNode *rightChild;
};

struct Tree
{
	TreeNode *root;
};

void addTreeLeaf(TreeNode* &currentNode, int x);
void addTreeNode(TreeNode *&currentNode, int x);
TreeNode **search(TreeNode *&currentNode, int x);
void removeTreeNode(TreeNode *&currentNode, int x);
TreeNode **findMin(TreeNode *&currentNode);
void clearTree(TreeNode *currentNode);
void updateHeight(TreeNode *currentNode);
void smallLeftRotate(TreeNode *&rootNode);
void smallRightRotate(TreeNode *&rootNode);
void bigLeftRotate(TreeNode *&rootNode);
void bigRightRotate(TreeNode *&rootNode);
int equilibrium(TreeNode *rootNode);
void balance(TreeNode *&rootNode);
void printTree(TreeNode *currentNode);
void printInfix(TreeNode *currentNode);
void printLargestToSmallest(TreeNode *currentNode);


Tree *createTree()
{
	Tree *newTree = new Tree;
	newTree->root = NULL;
	return newTree;
}

void addTreeLeaf(TreeNode* &currentNode, int x)
{
	TreeNode *newNode = new TreeNode;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	newNode->value = x;
	newNode->height = 1;
	currentNode = newNode;
}

bool addTreeNode(Tree *tree, int x)
{
	if (tree->root == NULL)
	{
		addTreeLeaf(tree->root, x);
		return true;
	}
	if (search(tree, x) != NULL)
		return false;
	addTreeNode(tree->root, x);
	return true;
}

void addTreeNode(TreeNode *&currentNode, int x)
{
	if (x < currentNode->value)
	{
		if (currentNode->leftChild != NULL)
		{
			addTreeNode(currentNode->leftChild, x);
			updateHeight(currentNode);
			balance(currentNode);
			updateHeight(currentNode);
		}
		else
		{
			addTreeLeaf(currentNode->leftChild, x);
			if (currentNode->height == 1)
				currentNode->height = 2;
		}
	}
	else
	{
		if (currentNode->rightChild != NULL)
		{
			addTreeNode(currentNode->rightChild, x);
			updateHeight(currentNode);
			balance(currentNode);
			updateHeight(currentNode);
		}
		else
		{
			addTreeLeaf(currentNode->rightChild, x);
			if (currentNode->height == 1)
				currentNode->height = 2;
		}
	}
}

TreeNode **search(Tree *tree, int x)
{
	return search(tree->root, x);
}

TreeNode **search(TreeNode *&currentNode, int x)
{
	if (currentNode == NULL)
		return NULL;
	if (x == currentNode->value)
		return &currentNode;
	if (x < currentNode->value)
		return search(currentNode->leftChild, x);
	else
		return search(currentNode->rightChild, x);
}

TreeNode **findMin(TreeNode *&currentNode)
{
	if (currentNode->leftChild == NULL)
		return &currentNode;
	return findMin(currentNode->leftChild);
}

bool removeTreeNode(Tree *tree, int x)
{
	if (search(tree, x) == NULL)
		return false;
	removeTreeNode(tree->root, x);
	return true;
}

void removeTreeNode(TreeNode* &currentNode, int x)
{
	if (x < currentNode->value)
	{
		removeTreeNode(currentNode->leftChild, x);
		updateHeight(currentNode);
		balance(currentNode);
		updateHeight(currentNode);
		return;
	}
	else if (x > currentNode->value)
	{
		removeTreeNode(currentNode->rightChild, x);
		updateHeight(currentNode);
		balance(currentNode);
		updateHeight(currentNode);
		return;
	}
	if (currentNode->leftChild == NULL && currentNode->rightChild == NULL)
	{
		delete currentNode;
		currentNode = NULL;
	}
	else if ((currentNode->leftChild != NULL && currentNode->rightChild == NULL)
		|| (currentNode->leftChild == NULL && currentNode->rightChild != NULL))
	{
		if (currentNode->leftChild != NULL)
		{
			TreeNode *temporaryNode = currentNode->leftChild;
			delete currentNode;
			currentNode = temporaryNode;
		}
		else
		{
			TreeNode *temporaryNode = currentNode->rightChild;
			delete currentNode;
			currentNode = temporaryNode;
		}
	}
	else
	{
		TreeNode **temporaryNode = findMin(currentNode->rightChild);
		currentNode->value = (*temporaryNode)->value;
		removeTreeNode(*temporaryNode, (*temporaryNode)->value);
	}
}

void clearTree(Tree *tree)
{
	clearTree(tree->root);
	delete tree;
}

void clearTree(TreeNode *currentNode)
{
	if (currentNode == NULL)
		return;
	clearTree(currentNode->leftChild);
	clearTree(currentNode->rightChild);
	delete currentNode;
}

void updateHeight(TreeNode *currentNode)
{
	if (currentNode->rightChild != NULL && currentNode->leftChild != NULL)
		currentNode->height = max(currentNode->leftChild->height, currentNode->rightChild->height) + 1;
	else if (currentNode->rightChild == NULL && currentNode->leftChild == NULL)
		currentNode->height = 1;
	else if (currentNode->rightChild == NULL)
		currentNode->height = currentNode->leftChild->height + 1;
	else
		currentNode->height = currentNode->rightChild->height + 1;
}

void smallLeftRotate(TreeNode *&rootNode)
{
	TreeNode *right = rootNode->rightChild;
	rootNode->rightChild = right->leftChild;
	right->leftChild = rootNode;
	rootNode = right;
	updateHeight(rootNode->leftChild);
	updateHeight(rootNode);
}

void smallRightRotate(TreeNode *&rootNode)
{
	TreeNode *left = rootNode->leftChild;
	rootNode->leftChild = left->rightChild;
	left->rightChild = rootNode;
	rootNode = left;
	updateHeight(rootNode->rightChild);
	updateHeight(rootNode);
}

void bigLeftRotate(TreeNode *&rootNode)
{
	smallRightRotate(rootNode->rightChild);
	smallLeftRotate(rootNode);
}

void bigRightRotate(TreeNode *&rootNode)
{
	smallLeftRotate(rootNode->leftChild);
	smallRightRotate(rootNode);
}

void balance(TreeNode *&rootNode)
{
	if (equilibrium(rootNode) == 2)
	{
		if (equilibrium(rootNode->rightChild) >= 0)
			smallLeftRotate(rootNode);
		else
			bigLeftRotate(rootNode);
	}
	else if (equilibrium(rootNode) == -2)
	{
		if (equilibrium(rootNode->leftChild) <= 0)
			smallRightRotate(rootNode);
		else
			bigRightRotate(rootNode);
	}
}

int equilibrium(TreeNode *rootNode)
{
	int left = 0;
	int right = 0;
	if (rootNode->leftChild != NULL)
		left = rootNode->leftChild->height;
	if (rootNode->rightChild != NULL)
		right = rootNode->rightChild->height;
	return right - left;
}

void printTree(TreeNode *currentNode)
{
	printf("(");
	printf("%d ", currentNode->value);
	if (currentNode->leftChild != NULL)
		printTree(currentNode->leftChild);
	else
		printf("null ");
	if (currentNode->rightChild != NULL)
		printTree(currentNode->rightChild);
	else
		printf("null");
	printf(")");
}

void printTree(Tree *tree)
{
	printf("Tree:\n");
	printTree(tree->root);
	printf("\n");
}

void printInfix(TreeNode *currentNode)
{
	if (currentNode == NULL)
		return;
	printInfix(currentNode->leftChild);
	printf("%d ", currentNode->value);
	printInfix(currentNode->rightChild);
}

void printInfix(Tree *tree)
{
	printf("Tree:\n");
	printInfix(tree->root);
	printf("\n");
}

void printLargestToSmallest(TreeNode *currentNode)
{
	if (currentNode == NULL)
		return;
	printLargestToSmallest(currentNode->rightChild);
	printf("%d ", currentNode->value);
	printLargestToSmallest(currentNode->leftChild);
}

void printLargestToSmallest(Tree *tree)
{
	printf("Tree:\n");
	printLargestToSmallest(tree->root);
	printf("\n");
}
