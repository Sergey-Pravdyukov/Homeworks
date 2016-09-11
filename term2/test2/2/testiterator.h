#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QVector>

#include "avltree.h"
#include "iterator.h"

class TestIterator : public QObject
{
    Q_OBJECT

public:
    explicit TestIterator(QObject *parent = 0):
        QObject(parent)
    {}

private:
    AVLTree::Iterator *currentIterator;
    AVLTree *tree;
    QVector<int> recordedTree;

    const int numberOfElements = 7;

    void fill(AVLTree *&tree)
    {
        for (int i = 0; i < numberOfElements; ++i)
            tree->add(i);
    }

private slots:
    void init()
    {
        tree = new AVLTree();
        fill(tree);
        currentIterator = new Iterator();
    }

    void cleanup()
    {
        delete tree;
        delete currentIterator;
    }

    void testNext()
    {
        tree->record();
        recordedTree = tree->recordedTree;
        for (int i = 0; i < numberOfElements; ++i)
        {
            const int value = currentIterator->next();
            const int correctValue = recordedTree[i];
            QCOMPARE(correctValue, value);
        }
    }

    void testIsEmpty()
    {
        tree->record();
        recordedTree = tree->recordedTree;
        for (int i = 0; i < numberOfElements; ++i)
        {
            const bool correctIsEmpty = false;
            const bool isEmpty = currentIterator->isEmpty();
            currentIterator->next();
            QCOMPARE(correctIsEmpty, isEmpty);
        }
        const bool correctIsEmpty = true;
        const bool isEmpty = currentIterator->isEmpty();
        QCOMPARE(correctIsEmpty, isEmpty);
    }

    void testRemove()
    {
        tree->record();
        recordedTree = tree->recordedTree;
        for (int i = 0; i < numberOfElements; ++i)
        {
            const int correctRemovedValue = tree->remove(recordedTree[i]);
            const int removedValue = currentIterator->remove();
            QCOMPARE(correctRemovedValue, removedValue);
        }
        const bool correctIsEmpty = true;
        const bool isEmpty = currentIterator->isEmpty();
        QCOMPARE(correctIsEmpty, isEmpty);
    }

};
