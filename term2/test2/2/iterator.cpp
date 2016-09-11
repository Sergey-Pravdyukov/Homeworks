#include "iterator.h"
#include "avltree.h"

Iterator::Iterator()
{

    root = currentNode;
    do
    {
        currentStack.push(*currentNode);
        currentNode = currentNode->left;
    } while (currentNode != nullptr);
}

int Iterator::next()
{
    TreeNode *currentNode = &currentStack.top();
    currentStack.pop();
    const int result = currentNode->value;
    if (currentNode->right != nullptr)
    {
        currentNode = currentNode->right;
        while (currentNode != nullptr)
        {
            currentStack.push(*currentNode);
            currentNode = currentNode->left;
        }
    }
    return result;
}

bool Iterator::isEmpty()
{
    return currentStack.empty();
}

int Iterator::remove()
{
    TreeNode *currentNode = &currentStack.top();
    currentStack.pop();
    const int result = currentNode->value;
    AVLTree::remove(currentNode->value);
    if (currentNode->right != nullptr)
    {
        currentNode = currentNode->right;
        while (currentNode != nullptr)
        {
            currentStack.push(*currentNode);
            currentNode = currentNode->left;
        }
    }
    return result;
}
