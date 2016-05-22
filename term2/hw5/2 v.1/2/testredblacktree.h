#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <set>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

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
/*
    void testRemoveElement()
    {
        const int value = 26;
        redBlackTree->add(value);
        const int removedValue = redBlackTree->remove(value);
        const int correctSize = 0;
        const int size = redBlackTree->getSize();
        QCOMPARE(size, correctSize);
        QCOMPARE(removedValue, value);
    }
*/
    void testRemoveElements()
    {
        srand(time(NULL));
        //const int maxNumberOfElements = 3;
        const int numberOfElements = 10;
        //const int numberOfElements = rand() % maxNumberOfElements + 1;
        //int array[numberOfElements] = {21, 21, 28};
        int array[10] = {24, 12, 3, 9, 21, 27, 9, 23, 27, 22};
        for (int i = 0; i < numberOfElements; ++i)
        {
            //const int value = rand() % 29 + 1;
            //array[i] = value;
            std::cout << array[i] << " ";
            redBlackTree->add(array[i]);
        }
        std::cout << std::endl << std::endl;
        for (int i = 0; i < numberOfElements; ++i)
        {
            const int correctRemovedValue = array[i];
            const int removedValue = redBlackTree->remove(array[i]);
            QCOMPARE(removedValue, correctRemovedValue);
            redBlackTree->recordedTree.clear();
            redBlackTree->treeRecord(redBlackTree->getRoot());
            recordedTree = redBlackTree->recordedTree;
            //std::cout << "Size: " << recordedTree.size() << " !" << endl;
            for (int i = 0; i < recordedTree.size(); ++i)
                std::cout << recordedTree[i] << " ";
            std::cout << std::endl;
            for (int i = 1; i < recordedTree.size(); ++i)
                QVERIFY(recordedTree[i - 1] <= recordedTree[i]);
            //std::cout << removedValue << " " << correctRemovedValue << std::endl;
            //std::cout << correctRemovedValue << std::endl;
            //QCOMPARE(removedValue, correctRemovedValue);
        }
    }

};

