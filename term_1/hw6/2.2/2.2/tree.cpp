#include "tree.h"
#include <iostream>
#include <cstdio>

struct Node
{
	int nodeValue;
	char nodeOperator;
	Node *left;
	Node *right;
};

struct Tree
{
	Node *root;
};

Tree* createTree()
{
	Tree *tree = new Tree;
	tree->root = new Node;
	return tree;
}

void createChild(Tree *tree, Node *node, FILE *file)
{
	if (feof(file))
	{
		return;
	}
	char curChar = 0;
	char uselessSpace = 0;
	fscanf(file, "%c", &curChar);
	if (curChar == '(')
	{
		Node *newLeftNode = new Node;
		Node *newRightNode = new Node;
		node->left = newLeftNode;
		node->right = newRightNode;
		fscanf(file, "%c", &node->nodeOperator);
		node->nodeValue = 0;
		fscanf(file, "%c", &uselessSpace);
		createChild(tree, newLeftNode, file);
		fscanf(file, "%c", &uselessSpace);
		if (uselessSpace == ')')
		{
			fscanf(file, "%c", &uselessSpace);
		}
		createChild(tree, newRightNode, file);
	}
	else
	{
		ungetc(curChar, file);
		fscanf(file, "%d", &node->nodeValue);
		node->nodeOperator = '0';
		node->left = nullptr;
		node->right = nullptr;
	}
}

void readTree(Tree *tree, FILE *file)
{
	createChild(tree, tree->root, file);
}

void printNode(Node *node)
{
	if (node->nodeOperator != '0')
	{
		std::cout << "(" << node->nodeOperator << ' ';
		printNode(node->left);
		printNode(node->right);
		std::cout << ") ";
	}
	else
	{
		std::cout << node->nodeValue << ' ';
	}

}

void printTree(Tree *tree)
{
	printNode(tree->root);
}

int calculateChilds(Node *node)
{
	switch (node->nodeOperator)
	{
	case '+':
		return calculateChilds(node->left) + calculateChilds(node->right);
	case '-':
		return calculateChilds(node->left) - calculateChilds(node->right);
	case '*':
		return calculateChilds(node->left) * calculateChilds(node->right);
	case '/':
		if (calculateChilds(node->right) != 0)
		{
			return calculateChilds(node->left) / calculateChilds(node->right);
		}
		else
		{
			return  INT_MAX;
		}
	case '0':
		return node->nodeValue;
	default:
		return  INT_MAX;
	}
}

int calculateTree(Tree *tree)
{
	return calculateChilds(tree->root);
}

void deleteNode(Node *node)
{
	if (node->left != nullptr)
	{
		deleteNode(node->left);
	}
	if (node->right != nullptr)
	{
		deleteNode(node->right);
	}
	delete node;
}

void deleteTree(Tree *tree)
{
	deleteNode(tree->root);
	delete tree;
}