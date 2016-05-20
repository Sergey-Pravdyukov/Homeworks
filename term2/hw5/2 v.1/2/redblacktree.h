#pragma once

#include <QVector>

#include "set.h"

enum Color
{
    red,
    black
};

template <typename T>
class RedBlackTree : public Set<T>
{
public:

    class TreeNode
    {
    public:
        TreeNode(const T &currentValue)
        {
            value = currentValue;
        }

        friend bool operator <(const TreeNode &left, const TreeNode &right)
        {
            return (left.value < right.value);
        }

        TreeNode *parent = nullptr;
        TreeNode *leftSon = nullptr;
        TreeNode *rightSon = nullptr;
        Color color = red;
        T value;

    private:
        const T valueInit = 0.0;
    };

    RedBlackTree();

    int getSize();

    void add(const T &currentValue);

    void treeRecord(TreeNode *currentNode);

    RedBlackTree<T>::TreeNode *getRoot();

    QVector<T> recordedTree;

private:

    TreeNode *grandparent(TreeNode *&currentNode) const;

    TreeNode *uncle(TreeNode *&currentNode) const;

    void shiftDown(TreeNode *&shiftingNode);

    void addCase1(TreeNode *&currentNode);

    void addCase2(TreeNode *&currentNode);

    void addCase3(TreeNode *&currentNode);

    void addCase4(TreeNode *&currentNode);

    void addCase5(TreeNode *&currentNode);

    bool haveSons(TreeNode *&currentNode) const;

    void rotateLeft(TreeNode *currentNode);

    void rotateRight(TreeNode *currentNode);

    const int sizeInit = 0;

    int size = sizeInit;
    TreeNode *root = nullptr;
};

// ---------------------------------

template <typename T>
RedBlackTree<T>::RedBlackTree()
{
    recordedTree.clear();
}

template <typename T>
int RedBlackTree<T>::getSize()
{
    return size;
}

template <typename T>
typename RedBlackTree<T>::TreeNode *RedBlackTree<T>::getRoot()
{
    return root;
}

template <typename T>
typename RedBlackTree<T>::TreeNode *RedBlackTree<T>::grandparent(TreeNode *&currentNode) const
{
    if ((currentNode != nullptr) && (currentNode->parent != nullptr))
        return currentNode->parent->parent;
    return nullptr;
}

template <typename T>
typename RedBlackTree<T>::TreeNode *RedBlackTree<T>::uncle(TreeNode *&currentNode) const
{
    TreeNode *currentGrandparent = grandparent(currentNode);
    if (currentGrandparent == nullptr)
        return nullptr;
    return (currentNode->parent == currentGrandparent->leftSon) ? currentGrandparent->rightSon
                                                                : currentGrandparent->leftSon;
}

template <typename T>
void RedBlackTree<T>::rotateLeft(TreeNode *currentNode)
{
    TreeNode *pivot = currentNode->rightSon;
    pivot->parent = currentNode->parent;
    if (currentNode->parent != nullptr)
        (currentNode->parent->leftSon == currentNode) ? currentNode->parent->leftSon = pivot
                                                      : currentNode->parent->rightSon = pivot;
    currentNode->rightSon = pivot->leftSon;
    if (pivot->leftSon != nullptr)
        pivot->leftSon->parent = currentNode;
    bool changeRoot = false;
    if (currentNode->parent == nullptr)
        changeRoot = true;
    currentNode->parent = pivot;
    pivot->leftSon = currentNode;
    if (changeRoot)
        root = pivot;
}

template <typename T>
void RedBlackTree<T>::rotateRight(TreeNode *currentNode)
{
    TreeNode *pivot = currentNode->leftSon;

    pivot->parent = currentNode->parent;
    if (currentNode->parent != nullptr)
        (currentNode->parent->leftSon == currentNode) ? currentNode->parent->leftSon = pivot
                                                      : currentNode->parent->rightSon = pivot;
    currentNode->leftSon = pivot->rightSon;
    if (pivot->rightSon != nullptr)
        pivot->rightSon->parent = currentNode;
    bool changeRoot = false;
    if (currentNode->parent == nullptr)
        changeRoot = true;
    currentNode->parent = pivot;
    pivot->rightSon = currentNode;
    if (changeRoot)
        root = pivot;
}

template <typename T>
bool RedBlackTree<T>::haveSons(TreeNode *&currentNode) const
{
    if (currentNode == nullptr)
        return false;
    if (currentNode->leftSon != nullptr)
        return true;
    if (currentNode->rightSon != nullptr)
        return true;
    return false;
}

template <typename T>
void RedBlackTree<T>::shiftDown(TreeNode *&shiftingNode)
{
    TreeNode *currentNode = root;
    if (currentNode == nullptr)
    {
        root = shiftingNode;
        return;
    }
    TreeNode *nextNode = nullptr;
    do
    {
        if (nextNode != nullptr)
            currentNode = nextNode;
        nextNode = (*shiftingNode < *currentNode) ? currentNode->leftSon
                                                  : currentNode->rightSon;
    } while (nextNode != nullptr);
    shiftingNode->parent = currentNode;
    (*shiftingNode < *currentNode) ? currentNode->leftSon = shiftingNode
                                   : currentNode->rightSon = shiftingNode;
}

template <typename T>
void RedBlackTree<T>::treeRecord(TreeNode *currentNode)
{
    if (currentNode == nullptr)
        return;
    if (currentNode->leftSon != nullptr)
        treeRecord(currentNode->leftSon);
    recordedTree.push_back(currentNode->value);
    if (currentNode->rightSon != nullptr)
        treeRecord(currentNode->rightSon);
}

template <typename T>
void RedBlackTree<T>::addCase5(TreeNode *&currentNode)
{
    TreeNode *currentGrandparent = grandparent(currentNode);
    currentNode->parent->color = black;
    currentGrandparent->color = red;
    ((currentNode == currentNode->parent->leftSon) &&
     (currentNode->parent == currentGrandparent->leftSon)) ? rotateRight(currentGrandparent)
                                                           : rotateLeft(currentGrandparent);
}

template <typename T>
void RedBlackTree<T>::addCase4(TreeNode *&currentNode)
{
    TreeNode *currentGrandparent = grandparent(currentNode);
    if ((currentNode == currentNode->parent->rightSon) && (currentNode->parent == currentGrandparent->leftSon))
    {
        rotateLeft(currentNode->parent);
        currentNode = currentNode->leftSon;
    }
    else if ((currentNode == currentNode->parent->leftSon) && (currentNode->parent == currentGrandparent->rightSon))
    {
        rotateRight(currentNode->parent);
        currentNode = currentNode->rightSon;
    }
    addCase5(currentNode);
    ++size;
}

template <typename T>
void RedBlackTree<T>::addCase3(TreeNode *&currentNode)
{
    TreeNode *currentUncle = uncle(currentNode);
    if ((currentUncle != nullptr) && (currentUncle->color == red) && (currentNode->parent->color == red))
    {
        currentNode->parent->color = currentUncle->color = black;
        TreeNode *currentGrandparent = grandparent(currentNode);
        currentGrandparent->color = red;
        addCase1(currentGrandparent);
        ++size;
    }
    else
        addCase4(currentNode);
}

template <typename T>
void RedBlackTree<T>::addCase2(TreeNode *&currentNode)
{
    if (currentNode->parent->color == black)
    {
        ++size;
        return;
    }
    addCase3(currentNode);
}

template <typename T>
void RedBlackTree<T>::addCase1(TreeNode *&currentNode)
{
    if (currentNode->parent == nullptr)
    {
        currentNode->color = black;
        ++size;
    }
    else
        addCase2(currentNode);
}

template <typename T>
void RedBlackTree<T>::add(const T &currentValue)
{
    TreeNode *currentNode = new TreeNode(currentValue);
    shiftDown(currentNode);
    addCase1(currentNode);
}

