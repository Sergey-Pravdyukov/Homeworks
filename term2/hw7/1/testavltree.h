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

    const int maxSize = 17;
    const int maxNumber = 29;

    void addElementsWithRecording(AVLTree<int> *&tree, const int &size, int elements[])
    {
        for (int i = 0; i < size; ++i)
        {
            const int value = rand() % maxNumber;
            elements[i] = value;
            tree->add(value);
        }
        std::sort(elements, elements + size);
    }

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
        const int correctSize = rand() % maxSize + 1;
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
        const int correctValue = 26;
        tree->add(correctValue);
        const int removedValue = tree->remove(correctValue);
        QCOMPARE(removedValue, correctValue);
    }

    void testRemoveElements()
    {
        srand(time(NULL));
        const int correctSize = rand() % maxSize + 1;
        const int notaddedElementsNumber = rand() % correctSize;
        int elements[maxSize];
        int i = 0;
        for (; i < correctSize - notaddedElementsNumber; ++i)
        {
            const int value = rand() % maxNumber;
            elements[i] = value;
            tree->add(value);
        }
        for (; i < correctSize; ++i)
        {
            const int value = rand() % maxNumber;
            elements[i] = value;
        }
        std::random_shuffle(elements, elements + correctSize);
        for (int i = 0; i < correctSize; ++i)
        {
            const int correctValue = elements[i];
            if (!tree->find(elements[i]))
            {
                QVERIFY_EXCEPTION_THROWN(tree->remove(elements[i]), AVLTree<int>::RemoveNonexistentElementException);
                continue;
            }
            const int removedValue = tree->remove(correctValue);
            QCOMPARE(removedValue, correctValue);
            recordedTree.clear();
            tree->recordedTree.clear();
            tree->record();
            recordedTree = tree->recordedTree;
            for (int j = 1; j < recordedTree.size(); ++j)
                QVERIFY(recordedTree[j - 1] <= recordedTree[j]);
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
        const int correctSize = rand() % maxSize + 1;
        int elements[maxSize];
        for (int i = 0; i < correctSize; ++i)
        {
            const int value = rand() % maxNumber;
            elements[i] = value;
            tree->add(value);
        }
        const int sizeForFind = rand() % maxSize + 1;
        int elementsForFind[maxSize];
        for (int i = 0; i < sizeForFind; ++i)
            elementsForFind[i] = rand() % maxNumber;
        for (int i = 0; i < sizeForFind; ++i)
        {
            bool correctResult = false;
            for (int j = 0; j < correctSize; ++j)
                if (elements[j] == elementsForFind[i])
                {
                    correctResult = true;
                    break;
                }
            const bool result = (tree->find(elementsForFind[i]) > 0);
            QCOMPARE(result, correctResult);
        }
    }

    void testIntersection()
    {
        const int intersectionArraySizeInit = 0;
        srand(time(NULL));
        const int treeSize = rand() % maxSize + 1;
        int treeElements[maxSize];
        bool treeUsed[maxSize];
        std::fill(treeUsed, treeUsed + maxSize, false);
        addElementsWithRecording(tree, treeSize, treeElements);
        AVLTree<int> *disjointTree = new AVLTree<int>();
        const int disjointTreeSize = rand() % maxSize + 1;
        int disjointTreeElements[maxSize];
        bool disjointTreeUsed[maxSize];
        std::fill(disjointTreeUsed, disjointTreeUsed + maxSize, false);
        for (int i = 0; i < disjointTreeSize; ++i)
        {
            const int value = rand() % maxNumber;
            disjointTreeElements[i] = value;
            disjointTree->add(value);
        }
        tree->intersection(disjointTree);
        int intersectionArray[maxSize];
        int intersectionArraySize = intersectionArraySizeInit;
        for (int i = 0; i < treeSize; ++i)
            for (int j = 0; j < disjointTreeSize; ++j)
                if (treeElements[i] == disjointTreeElements[j] && !treeUsed[i] && !disjointTreeUsed[j])
                {
                    intersectionArray[intersectionArraySize++] = treeElements[i];
                    disjointTreeUsed[j] = treeUsed[i] = true;
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
        int treeElements[maxSize];
        addElementsWithRecording(tree, treeSize, treeElements);
        AVLTree<int> *mergeTree = new AVLTree<int>();
        const int mergeTreeSize = rand() % maxSize + 1;
        int mergeTreeElements[maxSize];
        addElementsWithRecording(mergeTree, mergeTreeSize, mergeTreeElements);
        tree->merge(mergeTree);
        recordedTree.clear();
        tree->recordedTree.clear();
        tree->record();
        recordedTree = tree->recordedTree;
        int mergedTree[maxSize * 2];
        int i = 0;
        int j = 0;
        int mergedTreeSize = 0;
        while (i < treeSize && j < mergeTreeSize)
        {
            if (treeElements[i] < mergeTreeElements[j])
                mergedTree[mergedTreeSize++] = treeElements[i++];
            else if (mergeTreeElements[j] < treeElements[i])
                mergedTree[mergedTreeSize++] = mergeTreeElements[j++];
            else
            {
                mergedTree[mergedTreeSize++] = treeElements[i++];
                ++j;
            }
        }
        while (i < treeSize)
            mergedTree[mergedTreeSize++] = treeElements[i++];
        while (j < mergeTreeSize)
            mergedTree[mergedTreeSize++] = mergeTreeElements[j++];
        std::sort(mergedTree, mergedTree + mergedTreeSize);
        for (int i = 0; i < mergedTreeSize; ++i)
            QCOMPARE(recordedTree[i], mergedTree[i]);
    }

};
