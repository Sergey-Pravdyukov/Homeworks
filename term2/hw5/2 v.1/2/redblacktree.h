#pragma once

#include <QVector>
#include <climits>
#include <cstdlib>

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

    int getSize() const ;

    void add(const T &currentValue);

    T remove(const T &removingValue);

    void treeRecord(TreeNode *currentNode);

    RedBlackTree<T>::TreeNode *getRoot() const;

    QVector<T> recordedTree;

private:

    TreeNode *grandparent(TreeNode *&currentNode) const;

    TreeNode *uncle(TreeNode *&currentNode) const;

    TreeNode *sibling(TreeNode *&currentNode) const;

    void shiftDown(TreeNode *&shiftingNode);

    void addCase1(TreeNode *&currentNode);

    void addCase2(TreeNode *&currentNode);

    void addCase3(TreeNode *&currentNode);

    void addCase4(TreeNode *&currentNode);

    void addCase5(TreeNode *&currentNode);

    void rotateLeft(TreeNode *currentNode);

    void rotateRight(TreeNode *currentNode);

    void treeDescent(TreeNode *&currentNode, TreeNode *shiftingNode);

    void deleteChild(TreeNode *&currentNode);

    void replaceNode(TreeNode *oldNode, TreeNode *&newNode);

    bool isLeaf(TreeNode *&currentNode) const;

    void removeCase1(TreeNode *&currentNode);

    void removeCase2(TreeNode *&currentNode);

    void removeCase3(TreeNode *&currentNode);

    void removeCase4(TreeNode *&currentNode);

    void removeCase5(TreeNode *&currentNode);

    void removeCase6(TreeNode *&currentNode);

    const int sizeInit = 0;

    int size = sizeInit;
    TreeNode *root = nullptr;
    TreeNode *findingNode = nullptr;
};

// ---------------------------------

template <typename T>
RedBlackTree<T>::RedBlackTree()
{
    recordedTree.clear();
}

template <typename T>
int RedBlackTree<T>::getSize() const
{
    return size;
}

template <typename T>
typename RedBlackTree<T>::TreeNode *RedBlackTree<T>::getRoot() const
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
    TreeNode *grandparentNode = grandparent(currentNode);
    if (grandparentNode == nullptr)
        return nullptr;
    return (currentNode->parent == grandparentNode->leftSon) ? grandparentNode->rightSon
                                                                : grandparentNode->leftSon;
}

template <typename T>
typename RedBlackTree<T>::TreeNode *RedBlackTree<T>::sibling(TreeNode *&currentNode) const
{
    return (currentNode == currentNode->parent->leftSon) ? currentNode->parent->rightSon
                                                         : currentNode->parent->leftSon;
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
void RedBlackTree<T>::treeDescent(TreeNode *&currentNode, TreeNode *shiftingNode)
{
    TreeNode *nextNode = nullptr;
    do
    {
        if (nextNode != nullptr)
            currentNode = nextNode;
        if (currentNode->value == shiftingNode->value)
            findingNode = currentNode;
        nextNode = (*shiftingNode < *currentNode) ? currentNode->leftSon
                                                  : currentNode->rightSon;
    } while (nextNode != nullptr);
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
    treeDescent(currentNode, shiftingNode);
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
    TreeNode *grandparentNode = grandparent(currentNode);
    currentNode->parent->color = black;
    grandparentNode->color = red;
    ((currentNode == currentNode->parent->leftSon) &&
     (currentNode->parent == grandparentNode->leftSon)) ? rotateRight(grandparentNode)
                                                           : rotateLeft(grandparentNode);
}

template <typename T>
void RedBlackTree<T>::addCase4(TreeNode *&currentNode)
{
    TreeNode *grandparentNode = grandparent(currentNode);
    if ((currentNode == currentNode->parent->rightSon) && (currentNode->parent == grandparentNode->leftSon))
    {
        rotateLeft(currentNode->parent);
        currentNode = currentNode->leftSon;
    }
    else if ((currentNode == currentNode->parent->leftSon) && (currentNode->parent == grandparentNode->rightSon))
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
    TreeNode *uncleNode = uncle(currentNode);
    if ((uncleNode != nullptr) && (uncleNode->color == red) && (currentNode->parent->color == red))
    {
        currentNode->parent->color = uncleNode->color = black;
        TreeNode *grandparentNode = grandparent(currentNode);
        grandparentNode->color = red;
        addCase1(grandparentNode);
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

template <typename T>
void RedBlackTree<T>::replaceNode(TreeNode *oldNode, TreeNode *&newNode)
{
    if (newNode == nullptr)
        return;
    if (oldNode->leftSon == newNode)
    {
        TreeNode *maxNode = new TreeNode(INT_MAX);
        TreeNode *theRightmostNode = newNode;
        treeDescent(theRightmostNode, maxNode);
        if (theRightmostNode->parent != oldNode)
            theRightmostNode->parent->rightSon = theRightmostNode->leftSon;
        else
            theRightmostNode->parent->leftSon = theRightmostNode->leftSon;
        newNode = theRightmostNode;
    }
    else
    {
        TreeNode *minNode = new TreeNode(INT_MIN);
        TreeNode *theLeftmostNode = newNode;
        treeDescent(theLeftmostNode, minNode);
        if (theLeftmostNode->parent != oldNode)
            theLeftmostNode->parent->leftSon = theLeftmostNode->rightSon;
        else
            theLeftmostNode->parent->rightSon = theLeftmostNode->rightSon;
        newNode = theLeftmostNode;
    }
    newNode->parent = oldNode->parent;
    if (oldNode->parent != nullptr)
        (oldNode->parent->leftSon == oldNode) ? oldNode->parent->leftSon = newNode
                                              : oldNode->parent->rightSon = newNode;
    newNode->leftSon = oldNode->leftSon;
    if (newNode->leftSon != nullptr)
        newNode->leftSon->parent = newNode;
    newNode->rightSon = oldNode->rightSon;
    if (newNode->rightSon != nullptr)
        newNode->rightSon->parent = newNode;
    if (newNode->parent == nullptr)
        root = newNode;
}

template <typename T>
bool RedBlackTree<T>::isLeaf(TreeNode *&currentNode) const
{
    return (currentNode == nullptr);
}

template <typename T>
void RedBlackTree<T>::removeCase6(TreeNode *&currentNode)
{
    TreeNode *siblingNode = sibling(currentNode);
    siblingNode->color = currentNode->parent->color;
    currentNode->parent->color = black;
    if (currentNode == currentNode->parent->leftSon)
    {
        siblingNode->rightSon->color = black;
        rotateLeft(currentNode->parent);
    }
    else
    {
        siblingNode->leftSon->color = black;
        rotateRight(currentNode->parent);
    }
}

template <typename T>
void RedBlackTree<T>::removeCase5(TreeNode *&currentNode)
{
    TreeNode *siblingNode = sibling(currentNode);
    if (siblingNode->color == black)
    {
        if ((currentNode == currentNode->parent->leftSon)&&
            (siblingNode->rightSon->color == black) &&
            (siblingNode->leftSon->color == red))
        {
            siblingNode->color = red;
            siblingNode->leftSon->color = black;
            rotateRight(siblingNode);
        }
        else if ((currentNode == currentNode->parent->rightSon) &&
                 (siblingNode->leftSon->color == black) &&
                 (siblingNode->rightSon->color == red))
        {
            siblingNode->color = red;
            siblingNode->rightSon->color = black;
            rotateLeft(siblingNode);
        }
    }
    removeCase6(currentNode);
}

template <typename T>
void RedBlackTree<T>::removeCase4(TreeNode *&currentNode)
{
    TreeNode *siblingNode = sibling(currentNode);
    if ((currentNode->parent->color == red) &&
        (siblingNode->color == black) &&
        (siblingNode->leftSon->color == black) &&
        (siblingNode->rightSon->color == black))
    {
        siblingNode->color = red;
        currentNode->parent->color = black;
    }
    else
        removeCase5(currentNode);
}

template <typename T>
void RedBlackTree<T>::removeCase3(TreeNode *&currentNode)
{
    TreeNode *siblingNode = sibling(currentNode);
    if ((currentNode->parent->color == black) &&
        (siblingNode->color == black) &&
        (siblingNode->leftSon->color == black) &&
        (siblingNode->rightSon->color == black))
    {
        siblingNode->color = red;
        removeCase1(currentNode->parent);
    }
    else
        removeCase4(currentNode);
}

template <typename T>
void RedBlackTree<T>::removeCase2(TreeNode *&currentNode)
{
    TreeNode *siblingNode = sibling(currentNode);
    if (siblingNode->color == red)
    {
        currentNode->parent->color = red;
        siblingNode->color = black;
        (currentNode == currentNode->parent->leftSon) ? rotateLeft(currentNode->parent)
                                                      : rotateRight(currentNode->parent);
    }
    removeCase3(currentNode);
}

template <typename T>
void RedBlackTree<T>::removeCase1(TreeNode *&currentNode)
{
    if (currentNode->parent != nullptr)
        removeCase2(currentNode);
}

template <typename T>
void RedBlackTree<T>::deleteChild(TreeNode *&currentNode)
{
    TreeNode *childNode = isLeaf(currentNode->rightSon) ? currentNode->leftSon
                                                        : currentNode->rightSon;
    --size;
    if (childNode == nullptr)
    {
        if (currentNode->parent != nullptr)
            (currentNode->parent->leftSon == currentNode) ? currentNode->parent->leftSon = nullptr
                                                          : currentNode->parent->rightSon = nullptr;
        currentNode = nullptr;
        return;
    }
    replaceNode(currentNode, childNode);
    if (currentNode->color == black)
    {
        if (childNode->color == red)
            childNode->color = black;
        else
            removeCase1(childNode);
    }
    else
    {
        childNode->color = red;
        if (childNode->leftSon != nullptr)
            childNode->leftSon->color = black;
        if (childNode->rightSon != nullptr)
            childNode->rightSon->color = black;
    }
    free(currentNode);
}

template <typename T>
T RedBlackTree<T>::remove(const T &removingValue)
{
    TreeNode *removingNode = new TreeNode(removingValue);
    findingNode = nullptr;
    TreeNode *currentNode = root;
    treeDescent(currentNode, removingNode);
    if (findingNode != nullptr)
    {
        const T result = findingNode->value;
        deleteChild(findingNode);
        return result;
    }
}

