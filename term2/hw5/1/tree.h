#pragma once

#include <QString>
#include <QVector>
#include <iostream>

#include "parser.h"
#include "token.h"
#include "calculator.h"

/*!
 * \brief The Tree class determines standart methods for working with binary Tree
 */
class Tree
{
public:
    /*!
     * \brief traversalLeftToRight is a Tree in form of arithmetic expression
     * \return set of token in arithmetic expression
     */
    QVector<QString> traversalLeftToRight();
    /*!
     * \brief buildTree for postfix notationof arithmetic expression
     * \param expression
     */
    void buildTree(QString *&expression);
    /*!
     * \brief calculates value of parse Tree of arithmetic expression
     * \return
     */
    int calculateExpression();
    /*!
     * \brief get number of nodes in Tree
     * \return
     */
    int getSize() const;

private:
    /*!
     * \brief This class for working with node of Tree
     */
    class TreeNode
    {
    public:
        TreeNode(const QString &currentToken)
        {
            token = new QString(currentToken);
        }

        ~TreeNode()
        {
            delete token;
        }

        int value = valueInit;
        QString *token = nullptr;
        TreeNode *leftSon = nullptr;
        TreeNode *rightSon = nullptr;
    private:
        const int valueInit = 0;
    };

    /*!
     * \brief add current node in Tree
     * \param currentNode
     * \param index
     */
    void addNodes(TreeNode *&currentNode, int &index);
    /*!
     * \brief recordTree in infix notation
     * \param currentNode
     * \param recordedTree
     */
    void recordTree(TreeNode *&currentNode, QVector<QString> &recordedTree) const;
    /*!
     * \brief calculate values of subtree with root in current TreeNode
     * \param currentNode
     */
    void calculateValuesOfNodes(TreeNode *&currentNode);

    const int sizeInit = 0;

    int size = sizeInit;
    TreeNode *root = nullptr;
    QVector<QString> tokens;
};
