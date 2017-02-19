#pragma once

#include "avltree.h"

#include <stack>

template <typename T>
/*!
 * \brief This class describes basis methods for iterator
 */
class Iterator : public AVLTree
{
public:

    Iterator();
    /*!
     * \brief moves to the next element
     * \return value of currentNode
     */
    static int next();
    /*!
     * \brief isEmpty
     * \return true if bypass all tree otherwise false
     */
    bool isEmpty();
    /*!
     * \brief remove currentNode and go to next
     * \return
     */
    int remove();
    /*!
     * \brief return Iterator in root
     */
    void reset();

    std::stack<T> currentStack;

    T *temp;
    T *begin;

};

//-----------------------------------------------------------------

template <class AVLTree::TreeNode>
Iterator::Iterator()
{
    AVLTree::TreeNode *currentNode =
    begin = currentNode;
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

