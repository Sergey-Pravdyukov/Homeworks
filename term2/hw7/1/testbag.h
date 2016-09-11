#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QVector>
#include <set>

#include "Bag.h"

class TestBag : public QObject
{
    Q_OBJECT

public:
    explicit TestBag(QObject *parent = 0):
        QObject(parent)
    {}

private:
    Bag<int> *bag;
    QVector<int> recordedBag;

    const int maxSize = 17;
    const int maxNumber = 29;

    void addElementsWithRecording(Bag<int> *&bag, const int &elementsNumber, std::multiset<int> &elements)
    {
        for (int i = 0; i < elementsNumber; ++i)
        {
            int value = rand() % maxNumber + 1;
            elements.insert(value);
            bag->add(value);
        }
    }

    void removeElementsWithRecording(Bag<int> *&bag, std::multiset<int> &elements)
    {
        for (std::multiset<int>::iterator it = elements.begin(); it != elements.end(); ++it)
        {
            if (bag->find(*it) == 0)
            {
                QVERIFY_EXCEPTION_THROWN(bag->remove(*it), AVLTree<int>::RemoveNonexistentElementException);
                continue;
            }
            QVERIFY(bag->remove(*it));
            recordedBag.clear();
            recordedBag = bag->recording();
            for (int j = 1; j < recordedBag.size(); ++j)
                QVERIFY(recordedBag[j - 1] <= recordedBag[j]);
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
        bag = new Bag<int>();
        recordedBag.clear();
    }

    void cleanup()
    {
        delete bag;
    }

    void testEmptyBag()
    {
        recordedBag = bag->recording();
        QCOMPARE(recordedBag.size(), 0);
    }

    void testAddElement()
    {
        const int value = 26;
        bag->add(value);
        recordedBag = bag->recording();
        QCOMPARE(recordedBag.size(), 1);
        QCOMPARE(recordedBag[0], value);
    }

    void testAddElements()
    {
        srand(time(NULL));
        const int bagElementsNumber = rand() % maxSize + 1;
        std::multiset<int> bagElements;
        addElementsWithRecording(bag, bagElementsNumber, bagElements);
        recordedBag = bag->recording();
        QCOMPARE(bagElements.size(), (unsigned int)recordedBag.size());
        int counter = 0;
        for (std::multiset<int>::iterator it = bagElements.begin(); it != bagElements.end(); ++it)
            QCOMPARE(*it, recordedBag[counter++]);
    }

    void testRemoveElement()
    {
        const int value = 26;
        bag->add(value);
        QVERIFY(bag->remove(value));
    }

    void testRemoveElements()
    {
        srand(time(NULL));
        const int bagElementsNumber = rand() % maxSize + 1;
        std::multiset<int> bagElements;
        addElementsWithRecording(bag, bagElementsNumber, bagElements);
        removeElementsWithRecording(bag, bagElements);
    }

    void testFindElement()
    {
        int value = 26;
        bag->add(value);
        QCOMPARE((bag->find(value) > 0), true);
        value = 271;
        QCOMPARE((bag->find(value) > 0), false);
    }

    void testFindElements()
    {
        const int bagElementsNumber = rand() % maxSize + 1;
        std::multiset<int> bagElements;
        addElementsWithRecording(bag, bagElementsNumber, bagElements);
        const int findAttemptsNumber = rand() % maxSize;
        for (int i = 0; i < findAttemptsNumber; ++i)
        {
            const int value = rand() % maxNumber;
            QCOMPARE((bag->find(value) > 0), bagElements.find(value) != bagElements.end());
        }
    }

    void testIntersection()
    {
        const int bagElementsNumber = rand() % maxSize;
        std::multiset<int> bagElements;
        addElementsWithRecording(bag, bagElementsNumber, bagElements);
        const int disjointBagElementsNumber = rand() % maxSize;
        Bag<int> *disjointBag = new Bag<int>();
        std::multiset<int> disjointBagElements;
        addElementsWithRecording(disjointBag, disjointBagElementsNumber, disjointBagElements);
        bag->intersection(disjointBag);
        std::multiset<int> intersectionElements;
        intersectSets(bagElements, disjointBagElements, intersectionElements);
        recordedBag = bag->recording();
        QCOMPARE((unsigned int)recordedBag.size(), intersectionElements.size());
        int counter = 0;
        for (std::multiset<int>::iterator it = intersectionElements.begin(); it != intersectionElements.end(); ++it)
            QCOMPARE(*it, recordedBag[counter++]);
    }

    void testMerge()
    {
        const int bagElementsNumber = rand() % maxSize;
        std::multiset<int> bagElements;
        addElementsWithRecording(bag, bagElementsNumber, bagElements);
        const int mergeBagElementsNumber = rand() % maxSize;
        Bag<int> *mergeBag = new Bag<int>();
        std::multiset<int> mergeBagElements;
        addElementsWithRecording(mergeBag, mergeBagElementsNumber, mergeBagElements);
        bag->merge(mergeBag);
        std::multiset<int> mergedElements;
        mergeSets(bagElements, mergeBagElements, mergedElements);
        recordedBag = bag->recording();
        QCOMPARE((unsigned int)recordedBag.size(), mergedElements.size());
        int counter = 0;
        for (std::multiset<int>::iterator it = mergedElements.begin(); it != mergedElements.end(); ++it)
            QCOMPARE(*it, recordedBag[counter++]);
    }

};
