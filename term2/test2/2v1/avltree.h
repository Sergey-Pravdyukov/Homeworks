#pragma once

#include <QVector>
#include <algorithm>

#include "set.h"

template <typename T>
/*!
 * \brief This class for definition basis methods for working with Set as an AVLTree
 */
class AVLTree : public Set<T>
{
public:
    /*!
     * \brief record AVLTree from leftmost TreeNode to rightmost TreeNode
     */
    void record();
    /*!
     * \brief add
     * \param currentValue
     */
    void add(const T &currentValue);
    /*!
     * \brief remove
     * \param removingValue
     * \return
     */
    T remove(const T &removingValue);
    /*!
     * \brief find value in AVLTree
     * \param currentValue
     * \return
     */
    bool find(const T &currentValue) const;
    /*!
     * \brief intersection this AVLTree with disjointSet
     * \param disjointSet
     */

    QVector<T> recordedTree;
    int size = sizeInit;
private:
    /*!
     * \brief This class contains TreeNode for working with AVLTree
     */
    class TreeNode
    {
    public:
        TreeNode(const T &currentValue)
        {
            value = currentValue;
            height = 1;
        }

        int height = heightInit;
        T value = valueInit;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
    private:
        const T valueInit = 0;
        const int heightInit = 0;
    };

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
         * \brief reset
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


    /*!
     * \brief balanced AVLTree
     * \param currentNode
     * \return
     *
     * Do some left and right rotates
     */
    TreeNode *balance(TreeNode *currentNode);
    /*!
     * \brief updateHeight of currentNode
     * \param currentNode
     */
    void updateHeight(TreeNode *currentNode);
    /*!
     * \brief getHeight of currentNode
     * \param currentNode
     * \return
     */
    int getHeight(TreeNode *currentNode);
    /*!
     * \brief balanceFactor considers differenc between left and right sons of currentNode
     * \param currentNode
     * \return
     */
    int balanceFactor(TreeNode *currentNode);
    /*!
     * \brief Do left rotate of AVLTree around currentNode
     * \param currentNode
     * \return
     */
    TreeNode *rotateLeft(TreeNode *currentNode);
    /*!
     * \brief Do right rotate of AVLTree around currentNode
     * \param currentNode
     * \return
     */
    TreeNode *rotateRight(TreeNode *currentNode);
    /*!
     * \brief add node to subtree with root in currentNode
     * \param currentNode
     * \param addedNode
     * \return addedNode
     */
    TreeNode *add(TreeNode *currentNode, TreeNode *addedNode);
    /*!
     * \brief remove currentValue from this subtree with root in currentNode
     * \param currentNode
     * \param currentValue
     * \return
     */
    TreeNode *remove(TreeNode *currentNode, const T &currentValue);
    /*!
     * \brief removeMinNode
     * \param currentNode
     * \return removing min value node in subtree with root in currentNode
     */
    TreeNode *removeMinNode(TreeNode *currentNode);
    /*!
     * \brief findMinNode
     * \param currentNode
     * \return min value node in subtree with root in currentNode
     */
    TreeNode *findMinNode(TreeNode *currentNode);
    /*!
     * \brief find
     * \param currentNode
     * \param currentValue
     * \return found node otherwise nullptr
     */
    TreeNode *find(TreeNode *currentNode, const T &currentValue) const;
    /*!
     * \brief intersection disjointTree with currentNode of this AVLTree
     * \param disjointTree
     * \param currentNode
     */
    void intersection(AVLTree<T> *disjointTree, TreeNode *currentNode);
    /*!
     * \brief merge this AVLTree with mergeTreeNode
     * \param mergeTree
     * \param mergeTreeNode
     */
    void merge(AVLTree<T> *mergeTree, TreeNode *mergeTreeNode);
    /*!
     * \brief merge mergeTree with this AVLTree
     * \param mergeTree
     */
    void merge(AVLTree<T> *mergeTree);
    /*!
     * \brief record subtree with root in currentNode from left most to rightmost nodes
     * \param currentNode
     */
    void record(TreeNode *currentNode);
    /*!
     * \brief get root of AVLTree
     * \return
     */
    TreeNode *getRoot() const;
    /*!
     * \brief get value of currentNode
     * \param currentNode
     * \return
     */
    T getValue(TreeNode *currentNode) const;

    const int sizeInit = 0;

    TreeNode *removedNode = nullptr;
    TreeNode *root = nullptr;
};

//-----------------------------------------------------------

template <typename T>
typename AVLTree<T>::TreeNode *AVLTree<T>::getRoot() const
{
    return root;
}

template <typename T>
T AVLTree<T>::getValue(TreeNode *currentNode) const
{
    return currentNode->value;
}

template <typename T>
void AVLTree<T>::record(TreeNode *currentNode)
{
    if (currentNode == nullptr)
        return;
    if (currentNode->left != nullptr)
        record(currentNode->left);
    recordedTree.push_back(currentNode->value);
    if (currentNode->right != nullptr)
        record(currentNode->right);
}

template <typename T>
void AVLTree<T>::record()
{
    record(getRoot());
}

template <typename T>
int AVLTree<T>::getHeight(TreeNode *currentNode)
{
    return (currentNode) ? currentNode->height : 0;
}

template <typename T>
int AVLTree<T>::balanceFactor(TreeNode *currentNode)
{
    return getHeight(currentNode->right) - getHeight(currentNode->left);
}

template <typename T>
void AVLTree<T>::updateHeight(TreeNode *currentNode)
{
    const int heightLeft = getHeight(currentNode->left);
    const int heightRight = getHeight(currentNode->right);
    currentNode->height = std::max(heightLeft, heightRight) + 1;
}

template <typename T>
typename AVLTree<T>::TreeNode *AVLTree<T>::balance(TreeNode *currentNode)
{
    updateHeight(currentNode);
    if (balanceFactor(currentNode) == 2)
    {
        if (balanceFactor(currentNode->right) < 0)
            currentNode->right = rotateRight(currentNode->right);
        currentNode = rotateLeft(currentNode);
    }
    if (balanceFactor(currentNode) == -2)
    {
        if (balanceFactor(currentNode->left) > 0)
            currentNode->left = rotateLeft(currentNode->left);
        currentNode = rotateRight(currentNode);
    }
    return currentNode;
}

template <typename T>
typename AVLTree<T>::TreeNode *AVLTree<T>::rotateLeft(TreeNode *currentNode)
{
    TreeNode *pivot = currentNode->right;
    if (currentNode == root)
        root = pivot;
    currentNode->right = pivot->left;
    pivot->left = currentNode;
    updateHeight(currentNode);
    updateHeight(pivot);
    return pivot;
}

template <typename T>
typename AVLTree<T>::TreeNode *AVLTree<T>::rotateRight(TreeNode *currentNode)
{
    TreeNode *pivot = currentNode->left;
    if (currentNode == root)
        root = pivot;
    currentNode->left = pivot->right;
    pivot->right = currentNode;
    updateHeight(currentNode);
    updateHeight(pivot);
    return pivot;
}

template <typename T>
typename AVLTree<T>::TreeNode *AVLTree<T>::add(TreeNode *currentNode, TreeNode *addedNode)
{
    if (currentNode == nullptr)
    {
        currentNode = addedNode;
        if (!root)
            root = currentNode;
        ++size;
        return currentNode;
    }
    if (addedNode->value == currentNode->value)
        return currentNode;
    (addedNode->value < currentNode->value) ? currentNode->left = add(currentNode->left, addedNode)
                                            : currentNode->right = add(currentNode->right, addedNode);
    return balance(currentNode);
}

template <typename T>
void AVLTree<T>::add(const T &currentValue)
{
    TreeNode *currentNode = new TreeNode(currentValue);
    add(root, currentNode);
}

template <typename T>
typename AVLTree<T>::TreeNode *AVLTree<T>::findMinNode(TreeNode *currentNode)
{
    return (currentNode->left) ? findMinNode(currentNode->left) : currentNode;
}

template <typename T>
typename AVLTree<T>::TreeNode *AVLTree<T>::removeMinNode(TreeNode *currentNode)
{
    if (!currentNode->left)
        return currentNode->right;
    currentNode->left = removeMinNode(currentNode->left);
    return balance(currentNode);
}

template <typename T>
typename AVLTree<T>::TreeNode *AVLTree<T>::remove(TreeNode *currentNode, const T &currentValue)
{
    if (!currentNode)
        return new TreeNode(currentValue);
    if (currentValue < currentNode->value)
        currentNode->left = remove(currentNode->left, currentValue);
    else if (currentValue > currentNode->value)
        currentNode->right = remove(currentNode->right, currentValue);
    else
    {
        TreeNode *leftNode = currentNode->left;
        TreeNode *rightNode = currentNode->right;
        removedNode = currentNode;
        --size;
        delete currentNode;
        if (!rightNode)
        {
            if (currentNode == root)
                root = leftNode;
            return leftNode;
        }
        TreeNode *minNode = findMinNode(rightNode);
        if (currentNode == root)
            root = minNode;
        minNode->right = removeMinNode(rightNode);
        minNode->left = leftNode;
        return balance(minNode);
    }
    return balance(currentNode);
}

template <typename T>
T AVLTree<T>::remove(const T &removingValue)
{
    remove(root, removingValue);
    return removedNode->value;
}

template <typename T>
typename AVLTree<T>::TreeNode *AVLTree<T>::find(TreeNode *currentNode, const T &currentValue) const
{
    if (!currentNode)
        return nullptr;
    if (currentNode->value == currentValue)
        return currentNode;
    return (currentValue < currentNode->value) ? find(currentNode->left, currentValue)
                                               : find(currentNode->right, currentValue);
}

template <typename T>
bool AVLTree<T>::find(const T &currentValue) const
{
    TreeNode *foundNode = find(root, currentValue);
    return (foundNode);
}

template <typename T>
void AVLTree<T>::intersection(AVLTree<T> *disjointTree, TreeNode *currentNode)
{
    if (!currentNode)
        return;
    TreeNode *foundNode = disjointTree->find(disjointTree->getRoot(), getValue(currentNode));
    if (!foundNode)
    {
        this->remove(root, getValue(currentNode));
        intersection(disjointTree, root);
    }
    else
    {
        intersection(disjointTree, currentNode->left);
        intersection(disjointTree, currentNode->right);
    }
}

template <typename T>
void AVLTree<T>::intersection(Set<T> *disjointSet)
{
    intersection(dynamic_cast<AVLTree<T> *>(disjointSet), root);
}

template <typename T>
void AVLTree<T>::merge(AVLTree<T> *mergeTree, TreeNode *mergeTreeNode)
{
    if (!mergeTreeNode)
        return;
    recordedTree.clear();
    record(root);
    TreeNode *foundNode = find(root, mergeTree->getValue(mergeTreeNode));
    if (!foundNode)
        add(getValue(mergeTreeNode));
    merge(mergeTree, mergeTreeNode->left);
    merge(mergeTree, mergeTreeNode->right);
}

template <typename T>
void AVLTree<T>::merge(AVLTree<T> *mergeTree)
{
    merge(mergeTree, mergeTree->getRoot());
}

template <typename T>
void AVLTree<T>::merge(Set<T> *mergeSet)
{
    merge(dynamic_cast<AVLTree<T> *>(mergeSet));
}
