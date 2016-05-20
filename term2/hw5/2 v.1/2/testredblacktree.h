#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <set>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "redblacktree.h"

class TestRedBlackTree : public QObject
{
    Q_OBJECT

public:
    explicit TestRedBlackTree(QObject *parent = 0):
        QObject(parent)
    {}

private:
    RedBlackTree<int> *redBlackTree;
    std::multiset<int> set;
    QVector<int> recordedTree;

private slots:
    void init()
    {
        redBlackTree = new RedBlackTree<int>();
        set.clear();
        recordedTree.clear();
    }

    void cleanup()
    {
        delete redBlackTree;
    }

    void testEmptyTree()
    {
        const int correctSize = 0;
        const int size = redBlackTree->getSize();
        QCOMPARE(size, correctSize);
    }

    void testAddElement()
    {
        const int value = 26;
        const int correctSize = 1;
        redBlackTree->add(value);
        redBlackTree->treeRecord(redBlackTree->getRoot());
        recordedTree = redBlackTree->recordedTree;
        set.insert(value);
        const int size = recordedTree.size();
        QCOMPARE(size, correctSize);
        std::set<int>::iterator it = set.begin();
        QCOMPARE(recordedTree[0], *it);
    }

    void testAddElements()
    {
        srand(time(NULL));
        const int maxNumberOfElements = 27;
        const int numberOfElements = rand() % maxNumberOfElements + 1;
        for (int i = 0; i < numberOfElements; ++i)
        {
            const int value = rand() % 29;
            set.insert(value);
            redBlackTree->add(value);
        }
        redBlackTree->treeRecord(redBlackTree->getRoot());
        recordedTree = redBlackTree->recordedTree;
        const int size = recordedTree.size();
        QCOMPARE(size, numberOfElements);
        const int counterInit = 0;
        int counter = counterInit;
        for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
            QCOMPARE(recordedTree[counter++], *it);
    }

};

