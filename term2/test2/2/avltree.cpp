#include "avltree.h"

typename AVLTree::TreeNode *AVLTree::getRoot()
{
    return root;
}

int AVLTree::getValue(TreeNode *currentNode) const
{
    return currentNode->value;
}

void AVLTree::record(TreeNode *currentNode)
{
    if (currentNode == nullptr)
        return;
    if (currentNode->left != nullptr)
        record(currentNode->left);
    recordedTree.push_back(currentNode->value);
    if (currentNode->right != nullptr)
        record(currentNode->right);
}

void AVLTree::record()
{
    record(getRoot());
}

int AVLTree::getHeight(TreeNode *currentNode)
{
    return (currentNode) ? currentNode->height : 0;
}

int AVLTree::balanceFactor(TreeNode *currentNode)
{
    return getHeight(currentNode->right) - getHeight(currentNode->left);
}

void AVLTree::updateHeight(TreeNode *currentNode)
{
    const int heightLeft = getHeight(currentNode->left);
    const int heightRight = getHeight(currentNode->right);
    currentNode->height = std::max(heightLeft, heightRight) + 1;
}

typename AVLTree::TreeNode *AVLTree::balance(TreeNode *currentNode)
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

typename AVLTree::TreeNode *AVLTree::rotateLeft(TreeNode *currentNode)
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

typename AVLTree::TreeNode *AVLTree::rotateRight(TreeNode *currentNode)
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

typename AVLTree::TreeNode *AVLTree::add(TreeNode *currentNode, TreeNode *addedNode)
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

void AVLTree::add(const int &currentValue)
{
    TreeNode *currentNode = new TreeNode(currentValue);
    add(root, currentNode);
}

typename AVLTree::TreeNode *AVLTree::findMinNode(TreeNode *currentNode)
{
    return (currentNode->left) ? findMinNode(currentNode->left) : currentNode;
}

typename AVLTree::TreeNode *AVLTree::removeMinNode(TreeNode *currentNode)
{
    if (!currentNode->left)
        return currentNode->right;
    currentNode->left = removeMinNode(currentNode->left);
    return balance(currentNode);
}

typename AVLTree::TreeNode *AVLTree::remove(TreeNode *currentNode, const int &currentValue)
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

int AVLTree::remove(const int &removingValue)
{
    remove(root, removingValue);
    return removedNode->value;
}

typename AVLTree::TreeNode *AVLTree::find(TreeNode *currentNode, const int &currentValue) const
{
    if (!currentNode)
        return nullptr;
    if (currentNode->value == currentValue)
        return currentNode;
    return (currentValue < currentNode->value) ? find(currentNode->left, currentValue)
                                               : find(currentNode->right, currentValue);
}

bool AVLTree::find(const int &currentValue) const
{
    TreeNode *foundNode = find(root, currentValue);
    return (foundNode);
}
