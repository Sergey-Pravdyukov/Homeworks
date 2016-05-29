#pragma once

#include <QVector>
#include <algorithm>
#include <exception>

template <typename T>
/*!
 * \brief This class for definition basis methods for working with Bag as an AVLTree
 */
class AVLTree
{
public:

    class RemoveNonexistentElementException : public std::exception
    {
        const char *what() const noexcept
        {
            return "Removal of a non-existent element.";
        }
    };

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
    int remove(const T &removingValue) throw(RemoveNonexistentElementException);
    /*!
     * \brief find
     * \param currentValue
     * \return number of finding elements
     */
    int find(const T &currentValue) const;
    /*!
     * \brief intersection this AVLTree with disjointBag
     * \param disjointBag
     */
    void intersection(AVLTree<T> *disjointBag);
    /*!
     * \brief merge this AVLTree with mergeBag
     * \param mergeBag
     */
    void merge(AVLTree<T> *mergeBag);
    /*!
     * \brief contains all TreeNodes of AVLTree from leftmost to rightmost
     */
    QVector<T> recordedTree;
private:
    /*!
     * \brief This class contains TreeNode for working with AVLTree
     */
    class TreeNode
    {
    public:
        TreeNode(const T &currentValue, const int &currentCount)
        {
            value = currentValue;
            height = 1;
            count = currentCount;
        }

        int height = heightInit;
        T value = valueInit;
        int count = countInit;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
    private:
        const T valueInit = 0;
        const int heightInit = 0;
        const int countInit = 0;
    };
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
     * \brief add currentCount currentValues in AVLTree
     * \param currentValue
     * \param currentCount
     */
    void add(const T &currentValue, const int &currentCount);
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
    /*!
     * \brief get number of elements of currentNode
     * \param currentNode
     * \return
     */
    int getCount(TreeNode *currentNode) const;

    const int sizeInit = 0;

    int size = sizeInit;
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
int AVLTree<T>::getCount(TreeNode *currentNode) const
{
    return currentNode->count;
}

template <typename T>
void AVLTree<T>::record(TreeNode *currentNode)
{
    if (currentNode == nullptr)
        return;
    if (currentNode->left != nullptr)
        record(currentNode->left);
    for (int i = 0; i < currentNode->count; ++i)
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
        return currentNode;
    }
    if (addedNode->value == currentNode->value)
    {
        currentNode->count += addedNode->count;
        return currentNode;
    }
    (addedNode->value < currentNode->value) ? currentNode->left = add(currentNode->left, addedNode)
                                            : currentNode->right = add(currentNode->right, addedNode);
    return balance(currentNode);
}

template <typename T>
void AVLTree<T>::add(const T &currentValue)
{
    const int currentCount = 1;
    add(currentValue, currentCount);
}

template <typename T>
void AVLTree<T>::add(const T &currentValue, const int &currentCount)
{
    TreeNode *currentNode = new TreeNode(currentValue, currentCount);
    add(root, currentNode);
    size += currentCount;
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
    {
        const int currentCount = 1;
        return new TreeNode(currentValue, currentCount);
    }
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
        if (currentNode->count == 0)
        {
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
        else
        {
            --currentNode->count;
            return currentNode;
        }
    }
    return balance(currentNode);
}

template <typename T>
int AVLTree<T>::remove(const T &removingValue) throw(RemoveNonexistentElementException)
{
    if (find(removingValue) == 0)
        throw RemoveNonexistentElementException();
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
int AVLTree<T>::find(const T &currentValue) const
{
    TreeNode *foundNode = find(root, currentValue);
    return (foundNode) ? foundNode->count : 0;
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
        currentNode->count = std::min(currentNode->count, foundNode->count);
        intersection(disjointTree, currentNode->left);
        intersection(disjointTree, currentNode->right);
    }
}

template <typename T>
void AVLTree<T>::intersection(AVLTree<T> *disjointBag)
{
    intersection(dynamic_cast<AVLTree<T> *>(disjointBag), root);
}

template <typename T>
void AVLTree<T>::merge(AVLTree<T> *mergeTree, TreeNode *mergeTreeNode)
{
    if (!mergeTreeNode)
        return;
    recordedTree.clear();
    record(root);
    TreeNode *foundNode = find(root, mergeTree->getValue(mergeTreeNode));
    if (foundNode)
        foundNode->count = std::max(foundNode->count, mergeTreeNode->count);
    else
        add(getValue(mergeTreeNode), getCount(mergeTreeNode));
    merge(mergeTree, mergeTreeNode->left);
    merge(mergeTree, mergeTreeNode->right);
}

template <typename T>
void AVLTree<T>::merge(AVLTree<T> *mergeTree)
{
    merge(mergeTree, mergeTree->getRoot());
}
