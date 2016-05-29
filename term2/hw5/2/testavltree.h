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

    void addElementsWithRecording(AVLTree<int> *&tree, int &size, int elements[])
    {
        for (int i = 0; i < size; ++i)
        {
            const int value = rand() % maxNumber;
            if (tree->find(value))
                QVERIFY_EXCEPTION_THROWN(tree->add(value), AVLTree<int>::AddExistingElement);
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
            std::cout << value << " ";
            if (tree->find(value))
                QVERIFY_EXCEPTION_THROWN(tree->add(value), AVLTree<int>::AddExistingElement);
            tree->add(value);
        }
        std::cout << std::endl;
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
        QVERIFY(tree->remove(value));
    }

    void testRemoveElements()
    {
        srand(time(NULL));
        const int correctSize = rand() % maxSize + 1;
        int array[maxSize];
        for (int i = 0; i < correctSize; ++i)
        {
            const int value = rand() % maxNumber;
            if (tree->find(value))
                QVERIFY_EXCEPTION_THROWN(tree->add(value), AVLTree<int>::AddExistingElement);
            array[i] = value;
            tree->add(value);
        }
        for (int i = 0; i < correctSize; ++i)
        {
            const int correctValue = array[i];
            QVERIFY(tree->remove(correctValue));
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
        const int correctSize = rand() % maxSize + 1;
        int array[maxSize];
        bool foundEqualElements = false;
        for (int i = 0; i < correctSize; ++i)
        {
            const int value = rand() % maxNumber;
            array[i] = value;
            for (int j = 0; j < i; ++j)
                foundEqualElements = (foundEqualElements || (array[j] == value));
            if (foundEqualElements)
                QVERIFY_EXCEPTION_THROWN(tree->add(value), AVLTree<int>::AddExistingElement);
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
        srand(time(NULL));
        const int treeElementsNumber = rand() % maxSize + 1;
        int treeSize = treeElementsNumber;
        int treeElements[maxSize];
        bool treeUsed[maxSize];
        std::fill(treeUsed, treeUsed + maxSize, false);
        addElementsWithRecording(tree, treeSize, treeElements);
        AVLTree<int> *disjointTree = new AVLTree<int>();
        const int disjointTreeElementsNumber = rand() % maxSize + 1;
        int disjointTreeSize = disjointTreeElementsNumber;
        int disjointTreeElements[maxSize];
        bool disjointTreeUsed[maxSize];
        std::fill(disjointTreeUsed, disjointTreeUsed + maxSize, false);
        addElementsWithRecording(disjointTree, disjointTreeSize, disjointTreeElements);
        tree->intersection(disjointTree);
        int intersectionArray[maxSize];
        int intersectionArraySize = 0;
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
        for (int i = 0; i < correctSize; ++i)
            QCOMPARE(recordedTree[i], intersectionArray[i]);
    }


    void testMerge()
    {
        srand(time(NULL));
        const int treeElementsNumber = rand() % maxSize + 1;
        int treeSize = treeElementsNumber;
        int treeElements[maxSize];
        addElementsWithRecording(tree, treeSize, treeElements);
        AVLTree<int> *mergeTree = new AVLTree<int>();
        const int mergeTreeElementsNumber = rand() % maxSize + 1;
        int mergeTreeSize = mergeTreeElementsNumber;
        int mergeTreeElements[maxSize];
        addElementsWithRecording(mergeTree, mergeTreeSize, mergeTreeElements);
        tree->merge(mergeTree);
        recordedTree.clear();
        tree->recordedTree.clear();
        tree->record();
        recordedTree = tree->recordedTree;
        int mergedTreeElements[maxSize * 2];
        int i = 0;
        int j = 0;
        int mergedTreeSize = 0;
        while (i < treeSize && j < mergeTreeSize)
        {
            if (treeElements[i] < mergeTreeElements[j])
                mergedTreeElements[mergedTreeSize++] = treeElements[i++];
            else if (mergeTreeElements[j] < treeElements[i])
                mergedTreeElements[mergedTreeSize++] = mergeTreeElements[j++];
            else
            {
                mergedTreeElements[mergedTreeSize++] = treeElements[i++];
                ++j;
            }
        }
        while (i < treeSize)
            mergedTreeElements[mergedTreeSize++] = treeElements[i++];
        while (j < mergeTreeSize)
            mergedTreeElements[mergedTreeSize++] = mergeTreeElements[j++];
        for (int i = 0; i < mergedTreeSize; ++i)
            QCOMPARE(recordedTree[i], mergedTreeElements[i]);
    }

};
