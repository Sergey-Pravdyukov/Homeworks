#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QVector>
#include <set>

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

    void addElementsWithRecording(AVLTree<int> *&tree, const int &elementsNumber, std::multiset<int> &elements)
    {
        for (int i = 0; i < elementsNumber; ++i)
        {
            int value = rand() % maxNumber + 1;
            elements.insert(value);
            tree->add(value);
        }
    }

    void removeElementsWithRecording(AVLTree<int> *&tree, std::multiset<int> &elements)
    {
        for (std::multiset<int>::iterator it = elements.begin(); it != elements.end(); ++it)
        {
            if (tree->find(*it) == 0)
            {
                QVERIFY_EXCEPTION_THROWN(tree->remove(*it), AVLTree<int>::RemoveNonexistentElementException);
                continue;
            }
            QVERIFY(tree->remove(*it));
            recordedTree.clear();
            recordedTree = tree->recordingTree();
            for (int j = 1; j < recordedTree.size(); ++j)
                QVERIFY(recordedTree[j - 1] <= recordedTree[j]);
        }
    }

    void intersectSets(std::multiset<int> elements, std::multiset<int> disjointElements, std::multiset<int> &intersectionElements)
    {
        std::multiset<int>::iterator it = elements.begin();
        std::multiset<int>::iterator disjointIt = disjointElements.begin();
        while (it != elements.end() && disjointIt != disjointElements.end())
        {
            if (*it < *disjointIt)
                ++it;
            else if (*disjointIt < *it)
                ++disjointIt;
            else
            {
                intersectionElements.insert(*it);
                ++it;
                ++disjointIt;
            }
        }
    }

    void mergeSets(std::multiset<int> elements, std::multiset<int> mergingElements, std::multiset<int> &mergedElements)
    {
        std::multiset<int>::iterator it = elements.begin();
        std::multiset<int>::iterator mergingIt = mergingElements.begin();
        while (it != elements.end() && mergingIt != mergingElements.end())
        {
            if (*it < *mergingIt)
            {
                mergedElements.insert(*it);
                ++it;
            }
            else if (*mergingIt < *it)
            {
                mergedElements.insert(*mergingIt);
                ++mergingIt;
            }
            else
            {
                mergedElements.insert(*it);
                ++it;
                ++mergingIt;
            }
        }
        while (it != elements.end())
        {
            mergedElements.insert(*it);
            ++it;
        }
        while (mergingIt != mergingElements.end())
        {
            mergedElements.insert(*mergingIt);
            ++mergingIt;
        }
    }

    void printMultiset(std::multiset<int> currentMultiset)
    {
        for (std::multiset<int>::iterator it = currentMultiset.begin(); it != currentMultiset.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
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
        recordedTree = tree->recordingTree();
        QCOMPARE(recordedTree.size(), 0);
    }

    void testAddElement()
    {
        const int value = 26;
        tree->add(value);
        recordedTree = tree->recordingTree();
        QCOMPARE(recordedTree.size(), 1);
        QCOMPARE(recordedTree[0], value);
    }

    void testAddElements()
    {
        srand(time(NULL));
        const int treeElementsNumber = rand() % maxSize + 1;
        std::multiset<int> treeElements;
        addElementsWithRecording(tree, treeElementsNumber, treeElements);
        recordedTree = tree->recordingTree();
        QCOMPARE(treeElements.size(), (unsigned int)recordedTree.size());
        int counter = 0;
        for (std::multiset<int>::iterator it = treeElements.begin(); it != treeElements.end(); ++it)
            QCOMPARE(*it, recordedTree[counter++]);
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
        const int treeElementsNumber = rand() % maxSize + 1;
        std::multiset<int> treeElements;
        addElementsWithRecording(tree, treeElementsNumber, treeElements);
        removeElementsWithRecording(tree, treeElements);
    }

    void testFindElement()
    {
        int value = 26;
        tree->add(value);
        QCOMPARE((tree->find(value) > 0), true);
        value = 271;
        QCOMPARE((tree->find(value) > 0), false);
    }

    void testFindElements()
    {
        const int treeElementsNumber = rand() % maxSize + 1;
        std::multiset<int> treeElements;
        addElementsWithRecording(tree, treeElementsNumber, treeElements);
        const int findAttemptsNumber = rand() % maxSize;
        for (int i = 0; i < findAttemptsNumber; ++i)
        {
            const int value = rand() % maxNumber;
            QCOMPARE((tree->find(value) > 0), treeElements.find(value) != treeElements.end());
        }
    }

    void testIntersection()
    {
        const int treeElementsNumber = rand() % maxSize;
        std::multiset<int> treeElements;
        addElementsWithRecording(tree, treeElementsNumber, treeElements);
        const int disjointTreeElementsNumber = rand() % maxSize;
        AVLTree<int> *disjointTree = new AVLTree<int>();
        std::multiset<int> disjointTreeElements;
        addElementsWithRecording(disjointTree, disjointTreeElementsNumber, disjointTreeElements);
        tree->intersection(disjointTree);
        std::multiset<int> intersectionElements;
        intersectSets(treeElements, disjointTreeElements, intersectionElements);
        recordedTree = tree->recordingTree();
        QCOMPARE((unsigned int)recordedTree.size(), intersectionElements.size());
        int counter = 0;
        for (std::multiset<int>::iterator it = intersectionElements.begin(); it != intersectionElements.end(); ++it)
            QCOMPARE(*it, recordedTree[counter++]);
    }

    void testMerge()
    {
        const int treeElementsNumber = rand() % maxSize;
        std::multiset<int> treeElements;
        addElementsWithRecording(tree, treeElementsNumber, treeElements);
        const int mergeTreeElementsNumber = rand() % maxSize;
        AVLTree<int> *mergeTree = new AVLTree<int>();
        std::multiset<int> mergeTreeElements;
        addElementsWithRecording(mergeTree, mergeTreeElementsNumber, mergeTreeElements);
        tree->merge(mergeTree);
        std::multiset<int> mergedElements;
        mergeSets(treeElements, mergeTreeElements, mergedElements);
        recordedTree = tree->recordingTree();
        QCOMPARE((unsigned int)recordedTree.size(), mergedElements.size());
        int counter = 0;
        for (std::multiset<int>::iterator it = mergedElements.begin(); it != mergedElements.end(); ++it)
            QCOMPARE(*it, recordedTree[counter++]);
    }

};
