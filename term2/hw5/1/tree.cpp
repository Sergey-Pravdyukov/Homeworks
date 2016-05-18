#include "tree.h"

void Tree::addNodes(TreeNode *&currentNode, int &index)
{
    if (index >= tokens.size())
        return;
    ++size;
    currentNode = new TreeNode(tokens[index]);
    if (Token::isOperation(*currentNode->token))
    {
        addNodes(currentNode->leftSon, ++index);
        addNodes(currentNode->rightSon, ++index);
    }
    else
        currentNode->value = currentNode->token->toInt();
}

void Tree::recordTree(TreeNode *&currentNode, QVector<QString> &recordedTree) const
{
    if (currentNode == nullptr)
        return;
    if (currentNode->leftSon != nullptr)
    {
        recordedTree.push_back("(");
        recordTree(currentNode->leftSon, recordedTree);
    }
    recordedTree.push_back(*currentNode->token);
    if (currentNode->rightSon != nullptr)
    {
        recordTree(currentNode->rightSon, recordedTree);
        recordedTree.push_back(")");
    }
}

QVector<QString> Tree::traversalLeftToRight()
{
    QVector<QString> recordedTree;
    recordedTree.clear();
    recordTree(this->root, recordedTree);
    return recordedTree;
}

void Tree::buildTree(QString *&expression)
{
    tokens = Parser::parseExpressionToTokens(*expression);
    const int indexInit = 0;
    int index = indexInit;
    this->addNodes(root, index);
}

void Tree::calculateValuesOfNodes(TreeNode *&currentNode)
{
    if(currentNode->leftSon != nullptr && Token::isOperation(*currentNode->leftSon->token))
        calculateValuesOfNodes(currentNode->leftSon);
    if(currentNode->rightSon != nullptr && Token::isOperation(*currentNode->rightSon->token))
        calculateValuesOfNodes(currentNode->rightSon);
    if (Token::isOperation(*currentNode->token))
        currentNode->value = Calculator::calculate(currentNode->leftSon->value,
                                                   currentNode->rightSon->value,
                                                   *currentNode->token);
}

int Tree::calculateExpression()
{
    calculateValuesOfNodes(root);
    return root->value;
}

int Tree::getSize() const
{
    return size;
}
