#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QString>
#include <QVector>
#include <iostream>

#include "tree.h"

class TestTree : public QObject
{
    Q_OBJECT

public:
    explicit TestTree(QObject *parent = 0):
        QObject(parent)
    {}

private:
    Tree *tree;
    QString *expression;

    QVector<QString> recordedTree;

private slots:
    void init()
    {
        tree = new Tree();
        expression = new QString();
        recordedTree.clear();
    }

    void cleanup()
    {
        delete tree;
        delete expression;
    }

    void testEmptyTree()
    {
        const int correctSize = 0;
        const int size = tree->getSize();
        QCOMPARE(size, correctSize);
    }

    void testAddNumber()
    {
        expression = new QString("26");
        const int correctExpressionSize = 1;
        const int correctResultOfExpression = 26;
        tree->buildTree(expression);
        recordedTree = tree->traversalLeftToRight();
        const int treeSize = tree->getSize();
        QCOMPARE(treeSize, correctExpressionSize);
        QCOMPARE(recordedTree[0], *expression);
        const int resultOfExpression = tree->calculateExpression();
        QCOMPARE(resultOfExpression, correctResultOfExpression);
    }

    void testAddEasyExpression()
    {
        expression = new QString("(+ 1 2)");
        const int correctExpressionSize = 5;
        QString correctRecordedTree[correctExpressionSize] = {"(", "1", "+", "2", ")"};
        const int correctResultOfExpression = 3;
        tree->buildTree(expression);
        recordedTree = tree->traversalLeftToRight();
        const int treeSize = recordedTree.size();
        QCOMPARE(treeSize, correctExpressionSize);
        for (int i = 0; i < treeSize; ++i)
            QCOMPARE(recordedTree[i], correctRecordedTree[i]);
        const int resultOfExpression = tree->calculateExpression();
        QCOMPARE(resultOfExpression, correctResultOfExpression);
    }

    void testAddDifficultExpression()
    {
        expression = new QString("( + ( / ( - 15 6 ) 3 ) ( * 2 4 ) ) ");
        const int correctExpressionSize = 17;
        QString correctRecordedTree[correctExpressionSize] = {"(", "(", "(", "15", "-", "6", ")", "/",
                                                              "3", ")", "+", "(", "2", "*", "4", ")", ")"};
        const int correctResultOfExpression = 11;
        tree->buildTree(expression);
        recordedTree = tree->traversalLeftToRight();
        const int treeSize = recordedTree.size();
        QCOMPARE(treeSize, correctExpressionSize);
        for (int i = 0; i < treeSize; ++i)
            QCOMPARE(recordedTree[i], correctRecordedTree[i]);
        const int resultOfExpression = tree->calculateExpression();
        QCOMPARE(resultOfExpression, correctResultOfExpression);
    }
};
