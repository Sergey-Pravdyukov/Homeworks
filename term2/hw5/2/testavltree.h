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

    void addElementsWithRecording(AVLTree<int> *&tree, const int &elementsNumber, std::set<int> &elements)
    {
        for (int i = 0; i < elementsNumber; ++i)
        {
            int value = rand() % maxNumber;
            if (elements.find(value) != elements.end())
            {
                QVERIFY_EXCEPTION_THROWN(tree->add(value), AVLTree<int>::AddExistingElementException);
                continue;
            }
            elements.insert(value);
            tree->add(value);
        }
    }

    void removeElementsWithRecording(AVLTree<int> *&tree, std::set<int> &elements)
    {
        for (std::set<int>::iterator it = elements.begin(); it != elements.end(); ++it)
        {
            if (!tree->find(*it))
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
        std::set<int> treeElements;
        addElementsWithRecording(tree, treeElementsNumber, treeElements);
        recordedTree = tree->recordingTree();
        QCOMPARE(treeElements.size(), (unsigned int)recordedTree.size());
        int counter = 0;
        for (std::set<int>::iterator it = treeElements.begin(); it != treeElements.end(); ++it)
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
        std::set<int> treeElements;
        addElementsWithRecording(tree, treeElementsNumber, treeElements);
        removeElementsWithRecording(tree, treeElements);
    }

    void testFindElement()
    {
        int value = 26;
        tree->add(value);
        QCOMPARE(tree->find(value), true);
        value = 271;
        QCOMPARE(tree->find(value), false);
    }

    void testFindElements()
    {
        const int treeElementsNumber = rand() % maxSize + 1;
        std::set<int> treeElements;
        addElementsWithRecording(tree, treeElementsNumber, treeElements);
        const int findAttemptsNumber = rand() % maxSize;
        for (int i = 0; i < findAttemptsNumber; ++i)
        {
            const int value = rand() % maxNumber;
            QCOMPARE(tree->find(value), treeElements.find(value) != treeElements.end());
        }
    }

    void testIntersection()
    {
        const int treeElementsNumber = rand() % maxSize + 1;
        std::set<int> treeElements;
        addElementsWithRecording(tree, treeElementsNumber, treeElements);
        AVLTree<int> *disjointTree = new AVLTree<int>();
        const int disjointTreeElementsNumber = rand() % maxSize + 1;
        std::set<int> disjointTreeElements;
        addElementsWithRecording(disjointTree, disjointTreeElementsNumber, disjointTreeElements);
        tree->intersection(disjointTree);
        std::set<int> intersectionElements;
        for (std::set<int>::iterator treeIt = treeElements.begin(); treeIt != treeElements.end(); ++treeIt)
            if (disjointTree->find(*treeIt))
                intersectionElements.insert(*treeIt);
        recordedTree = tree->recordingTree();
        QCOMPARE((unsigned int)recordedTree.size(), intersectionElements.size());
        int counter = 0;
        for (std::set<int>::iterator it = intersectionElements.begin(); it != intersectionElements.end(); ++it)
            QCOMPARE(recordedTree[counter++], *it);
    }

    void testMerge()
    {
        const int treeElementsNumber = rand() % maxSize + 1;
        std::set<int> treeElements;
        addElementsWithRecording(tree, treeElementsNumber, treeElements);
        AVLTree<int> *mergeTree = new AVLTree<int>();
        const int mergeTreeElementsNumber = rand() % maxSize + 1;
        std::set<int> mergeTreeElements;
        addElementsWithRecording(mergeTree, mergeTreeElementsNumber, mergeTreeElements);
        tree->merge(mergeTree);
        recordedTree = tree->recordingTree();
        std::set<int> mergedElements;
        mergedElements = mergeTreeElements;
        for (std::set<int>::iterator it = treeElements.begin(); it != treeElements.end(); ++it)
            if (mergeTreeElements.find(*it) == mergeTreeElements.end())
                mergedElements.insert(*it);
        QCOMPARE(mergedElements.size(), (unsigned int)recordedTree.size());
        int counter = 0;
        for (std::set<int>::iterator it = mergedElements.begin(); it != mergedElements.end(); ++it)
            QCOMPARE(*it, recordedTree[counter++]);
    }

};
