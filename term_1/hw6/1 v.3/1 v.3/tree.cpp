#include <iostream>
#include "tree.h"

using namespace std;

bool check(TreeNode *currentVertex, int value)
{
	return ((currentVertex->value > value && currentVertex->left != nullptr) ||
		(currentVertex->value < value && currentVertex->right != nullptr));
}

void addValue(Tree *currentTree, int value)
{
	++currentTree->size;
	TreeNode *leaf = new TreeNode{ value, nullptr, nullptr };
	if (currentTree->size == 1)
	{
		currentTree->root = leaf;
		return;
	}
	TreeNode *currentVertex = currentTree->root;
	while (check(currentVertex, leaf->value))
	{
		(currentVertex->value > leaf->value) ? currentVertex = currentVertex->left : currentVertex = currentVertex->right;
	}
	(currentVertex->value > leaf->value) ? currentVertex->left = leaf : currentVertex->right = leaf;
}

void printAscending(TreeNode *currentVertex)
{
	if (currentVertex->left != nullptr)
	{
		printAscending(currentVertex->left);
	}
	cout << currentVertex->value << " ";
	if (currentVertex->right != nullptr)
	{
		printAscending(currentVertex->right);
	}
}

void printDescending(TreeNode *currentVertex)
{
	if (currentVertex->right != nullptr)
	{
		printDescending(currentVertex->right);
	}
	cout << currentVertex->value << " ";
	if (currentVertex->left != nullptr)
	{
		printDescending(currentVertex->left);
	}
}

void debugOutput(TreeNode *currentVertex)
{
	cout << "(" << currentVertex->value << " ";
	if (currentVertex->left != nullptr)
	{
		debugOutput(currentVertex->left);
	}
	else
	{
		cout << "null ";
	}
	if (currentVertex->right != nullptr)
	{
		debugOutput(currentVertex->right);
	}
	else
	{
		cout << "null ";
	}
	cout << ")";
}

bool removeFromRoot(TreeNode *currentVertex, Tree *currentTree)
{
	if (currentVertex->left == nullptr && currentVertex->right == nullptr)
	{
		currentVertex = new TreeNode{ 0, nullptr, nullptr };
		return true;
	}
	if (currentVertex->left == nullptr && currentVertex->right != nullptr)
	{
		currentTree->root = currentVertex->right;
		return true;
	}
	if (currentVertex->left != nullptr && currentVertex->right == nullptr)
	{
		currentVertex = currentVertex->left;
		return true;
	}
	return false;
}

bool haveNotSons(TreeNode *currentVertex, TreeNode *preCurrentVertex, int value)
{
	if (currentVertex->left == nullptr && currentVertex->right == nullptr)
	{
		if (preCurrentVertex->left != nullptr)
		{
			if (preCurrentVertex->left->value == value) preCurrentVertex->left = nullptr;
		}
		if (preCurrentVertex->right != nullptr)
		{
			if (preCurrentVertex->right->value == value) preCurrentVertex->right = nullptr;
		}
		delete currentVertex;
		return true;
	}
	return false;
}

bool haveOnlyLeftSon(TreeNode *currentVertex, TreeNode *preCurrentVertex, int value)
{
	if (currentVertex->left != nullptr && currentVertex->right == nullptr)
	{
		(preCurrentVertex->left->value == value) ? preCurrentVertex->left = currentVertex->left
			: preCurrentVertex->right = currentVertex->left;
		return true;
	}
	return false;
}

bool haveOnlyRightSon(TreeNode *currentVertex, TreeNode *preCurrentVertex, int value)
{
	if (currentVertex->left == nullptr && currentVertex->right != nullptr)
	{
		(preCurrentVertex->left->value == value) ? preCurrentVertex->left = currentVertex->right
			: preCurrentVertex->right = currentVertex->right;
		return true;
	}
	return false;
}

bool haveLeftAndRightSons(TreeNode *currentVertex, TreeNode *preCurrentVertex, int value)
{
	TreeNode *newVertex = currentVertex->right;
	TreeNode *preNewVertex = currentVertex;
	while (newVertex->left != nullptr)
	{
		preNewVertex = newVertex;
		newVertex = newVertex->left;
	}
	currentVertex->value = newVertex->value;
	(preNewVertex->right->value == newVertex->value) ? preNewVertex->right = nullptr : preNewVertex->left = nullptr;
	delete newVertex;
	return true;
}

TreeNode removeValue(Tree *currentTree, int value)
{
	--currentTree->size;
	TreeNode *currentVertex = currentTree->root;
	TreeNode *preCurrentVertex = new TreeNode{ -1, nullptr, nullptr };
	if (currentVertex->value == value)
	{
		TreeNode *result = currentVertex;
		if (!removeFromRoot(currentVertex, currentTree))
		{
			haveLeftAndRightSons(currentVertex, preCurrentVertex, value);
		}
		return *result;
	}
	while (check(currentVertex, value))
	{
		if (currentVertex->value == value)
		{
			break;
		}
		preCurrentVertex = currentVertex;
		(currentVertex->value > value) ? currentVertex = currentVertex->left : currentVertex = currentVertex->right;
	}
	TreeNode result = *currentVertex;
	bool wasRemoved = haveNotSons(currentVertex, preCurrentVertex, value);
	(!wasRemoved) ? haveOnlyLeftSon(currentVertex, preCurrentVertex, value) : 1;
	(!wasRemoved) ? haveOnlyRightSon(currentVertex, preCurrentVertex, value) : 1;
	(!wasRemoved) ? haveLeftAndRightSons(currentVertex, preCurrentVertex, value) : 1;
	return result;
}

bool isExists(Tree *currentTree, int value)
{
	TreeNode *currentVertex = currentTree->root;
	while (check(currentVertex, value))
	{
		if (value == currentVertex->value)
		{
			return true;
		}
		(currentVertex->value > value) ? currentVertex = currentVertex->left : currentVertex = currentVertex->right;
	}
	if (value == currentVertex->value)
	{
		return true;
	}
	return false;
}
