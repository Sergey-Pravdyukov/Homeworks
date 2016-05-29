#pragma once

#include <QVector>
#include <algorithm>
#include <exception>

template <typename T>
/*!
 * \brief This class for definition basis methods for working with Set as an AVLTree
 */
class AVLTree
{
public:

    class AddExistingElement : public std::exception
    {
        const char *what() const noexcept
        {
            return "Add to an existing element.";
        }
    };

    class RemoveNonexistentElement : public std::exception
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
    void add(const T &currentValue) throw (AddExistingElement);
    /*!
     * \brief remove
     * \param removingValue
     * \return
     */
    bool remove(const T &removingValue) throw (RemoveNonexistentElement);
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
    void intersection(AVLTree<T> *disjointSet);
    /*!
     * \brief merge this AVLTree with mergeSet
     * \param mergeSet
     */
    void merge(AVLTree<T> *mergeSet);
    /*!
     * \brief contains all TreeNodes of AVLTree from leftmost to rightmost
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
void AVLTree<T>::add(const T &currentValue) throw(AddExistingElement)
{
    if (find(currentValue))
        throw AddExistingElement();
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
bool AVLTree<T>::remove(const T &removingValue) throw(RemoveNonexistentElement)
{
    if (!find(removingValue))
        throw RemoveNonexistentElement();
    remove(root, removingValue);
    return (removedNode->value == removingValue);
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
void AVLTree<T>::intersection(AVLTree<T> *disjointSet)
{
    intersection(disjointSet, root);
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
