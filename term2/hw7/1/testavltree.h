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
        const int correctSize = rand() % maxSize + 1;
        const int maxNumber = 29;
        for (int i = 0; i < correctSize; ++i)
        {
            const int value = rand() % maxNumber;
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
        const int correctSize = rand() % maxSize + 1;
        const int maxNumber = 29;
        int array[maxSize];
        for (int i = 0; i < correctSize; ++i)
        {
            const int value = rand() % maxNumber;
            array[i] = value;
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

    void testIntersection()
    {
        const int maxSize = 17;
        const int maxNumber = 29;
        const int intersectionArraySizeInit = 0;
        srand(time(NULL));
        const int treeSize = rand() % maxSize + 1;
        int arrayForTree[maxSize];
        bool usedForTree[maxSize];
        std::fill(usedForTree, usedForTree + maxSize, false);
        for (int i = 0; i < treeSize; ++i)
        {
            const int value = rand() % maxNumber;
            arrayForTree[i] = value;
            tree->add(value);
        }
        Set<int> *disjointSet = new AVLTree<int>();
        const int disjointSetSize = rand() % maxSize + 1;
        int arrayForDisjointSet[maxSize];
        bool usedForDisjointSet[maxSize];
        std::fill(usedForDisjointSet, usedForDisjointSet + maxSize, false);
        for (int i = 0; i < disjointSetSize; ++i)
        {
            const int value = rand() % maxNumber;
            arrayForDisjointSet[i] = value;
            disjointSet->add(value);
        }
        tree->intersection(disjointSet);
        int intersectionArray[maxSize];
        int intersectionArraySize = intersectionArraySizeInit;
        for (int i = 0; i < treeSize; ++i)
            for (int j = 0; j < disjointSetSize; ++j)
                if (arrayForTree[i] == arrayForDisjointSet[j] && !usedForTree[i] && !usedForDisjointSet[j])
                {
                    intersectionArray[intersectionArraySize++] = arrayForTree[i];
                    usedForDisjointSet[j] = usedForTree[i] = true;
                }
        const int correctSize = intersectionArraySize;
        tree->record();
        recordedTree = tree->recordedTree;
        const int size = recordedTree.size();
        QCOMPARE(size, correctSize);
        std::sort(intersectionArray, intersectionArray + intersectionArraySize);
        for (int i = 0; i < correctSize; ++i)
            QCOMPARE(recordedTree[i], intersectionArray[i]);
    }


    void testMerge()
    {
        const int maxSize = 5;
        const int maxNumber = 29;
        srand(time(NULL));
        const int treeSize = rand() % maxSize + 1;
        int arrayForTree[maxSize];
        for (int i = 0; i < treeSize; ++i)
        {
            const int value = rand() % maxNumber;
            arrayForTree[i] = value;
            tree->add(value);
        }
        std::sort(arrayForTree, arrayForTree + treeSize);
        Set<int> *mergeSet = new AVLTree<int>();
        const int mergeSetSize = rand() % maxSize + 1;
        int arrayForMergeSet[maxSize];
        for (int i = 0; i < mergeSetSize; ++i)
        {
            const int value = rand() % maxNumber;
            arrayForMergeSet[i] = value;
            mergeSet->add(value);
        }
        std::sort(arrayForMergeSet, arrayForMergeSet + mergeSetSize);
        tree->merge(mergeSet);
        recordedTree.clear();
        tree->recordedTree.clear();
        tree->record();
        recordedTree = tree->recordedTree;
        int mergedSet[maxSize * 2];
        int i = 0;
        int j = 0;
        int mergedSetSize = 0;
        while (i < treeSize && j < mergeSetSize)
        {
            if (arrayForTree[i] < arrayForMergeSet[j])
                mergedSet[mergedSetSize++] = arrayForTree[i++];
            else if (arrayForMergeSet[j] < arrayForTree[i])
                mergedSet[mergedSetSize++] = arrayForMergeSet[j++];
            else
            {
                mergedSet[mergedSetSize++] = arrayForTree[i++];
                ++j;
            }
        }
        while (i < treeSize)
            mergedSet[mergedSetSize++] = arrayForTree[i++];
        while (j < mergeSetSize)
            mergedSet[mergedSetSize++] = arrayForMergeSet[j++];
        std::sort(mergedSet, mergedSet + mergedSetSize);
        for (int i = 0; i < mergedSetSize; ++i)
            QCOMPARE(recordedTree[i], mergedSet[i]);
    }

};
