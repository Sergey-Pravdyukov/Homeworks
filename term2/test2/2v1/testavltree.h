#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QVector>

#include "avltree.h"

class TestAVLTree : public QObject
{
    Q_OBJECT

public:
    explicit TestAVLTree(QObject *parent = 0):
        QObject(parent)
    {}

private:
    AVLTree<int> *tree;
    QVector<int> recordedTree;

private slots:
    void init()
    {
        tree = new AVLTree<int>();
        recordedTree.clear();
    }

    void cleanup()
    {
        delete tree;
    }

    void testEmptyTree()
    {
        const int correctSize = 0;
        tree->record();
        recordedTree = tree->recordedTree;
        const int size = recordedTree.size();
        QCOMPARE(size, correctSize);
    }

    void testAddElement()
    {
        const int correctValue = 26;
        const int correctSize = 1;
        tree->add(correctValue);
        tree->record();
        recordedTree = tree->recordedTree;
        const int size = recordedTree.size();
        QCOMPARE(size, correctSize);
        const int value = recordedTree[0];
        QCOMPARE(value, correctValue);
    }

    void testAddElements()
    {
        srand(time(NULL));
        const int maxSize = 17;
        const int numberOfElements = rand() % maxSize + 1;
        int correctSize = numberOfElements;
        const int maxNumber = 29;
        for (int i = 0; i < numberOfElements; ++i)
        {
            const int value = rand() % maxNumber;
            correctSize -= tree->find(value);
            tree->add(value);
        }
        tree->record();
        recordedTree = tree->recordedTree;
        const int size = recordedTree.size();
        QCOMPARE(size, correctSize);
        for (int i = 1; i < correctSize; ++i)
            QVERIFY(recordedTree[i - 1] <= recordedTree[i]);
    }

    void testRemoveElement()
    {
        const int value = 26;
        tree->add(value);
        const int removedValue = tree->remove(value);
        QCOMPARE(removedValue, value);
    }

    void testRemoveElements()
    {
        srand(time(NULL));
        const int maxSize = 17;
        const int numberOfElements = rand() % maxSize + 1;
        int correctSize = numberOfElements;
        const int maxNumber = 29;
        int array[maxSize];
        int counter = 0;
        for (int i = 0; i < numberOfElements; ++i)
        {
            const int value = rand() % maxNumber;
            (tree->find(value)) ? --correctSize : array[counter++] = value;
            tree->add(value);
        }
        for (int i = 0; i < correctSize; ++i)
        {
            const int correctValue = array[i];
            const int removedValue = tree->remove(correctValue);
            QCOMPARE(removedValue, correctValue);
            recordedTree.clear();
            tree->recordedTree.clear();
            tree->record();
            recordedTree = tree->recordedTree;
            for (int i = 1; i < recordedTree.size(); ++i)
                QVERIFY(recordedTree[i - 1] <= recordedTree[i]);
        }
    }

    void testFindElement()
    {
        int value = 26;
        bool correctResult = true;
        tree->add(value);
        bool result = (tree->find(value) > 0);
        QCOMPARE(result, correctResult);
        value = 271;
        correctResult = false;
        result = (tree->find(value) > 0);
        QCOMPARE(result, correctResult);
    }

    void testFindElements()
    {
        srand(time(NULL));
        const int maxSize = 17;
        const int correctSize = rand() % maxSize + 1;
        const int maxNumber = 29;
        int array[maxSize];
        for (int i = 0; i < correctSize; ++i)
        {
            const int value = rand() % maxNumber;
            array[i] = value;
            tree->add(value);
        }
        const int sizeForFind = rand() % maxSize + 1;
        int arrayForFind[maxSize];
        for (int i = 0; i < sizeForFind; ++i)
            arrayForFind[i] = rand() % maxNumber;
        for (int i = 0; i < sizeForFind; ++i)
        {
            bool correctResult = false;
            for (int j = 0; j < correctSize; ++j)
                if (array[j] == arrayForFind[i])
                {
                    correctResult = true;
                    break;
                }
            const bool result = (tree->find(arrayForFind[i]) > 0);
            QCOMPARE(result, correctResult);
        }
    }

};
