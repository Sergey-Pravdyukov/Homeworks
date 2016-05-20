#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <QVector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#include "bubblesort.h"
#include "numbercomparator.h"

/*!
 * \brief This class for testing bubble sort with random type
 */
class TestBubbleSort : public QObject
{
    Q_OBJECT

public:
    explicit TestBubbleSort(QObject *parent = 0):
        QObject(parent)
    {}

private:
    BubbleSort<int> *bubbleSort;
    QVector<int> currentList;
    NumberComparator<int> comparator;

private slots:
    /*!
     * \brief initialize bubbleSort and clear currentList
     */
    void init()
    {
        bubbleSort = new BubbleSort<int>();
        currentList.clear();
    }

    /*!
     * \brief cleanup bubbleSort
     */
    void cleanup()
    {
        delete bubbleSort;
    }

    /*!
     * \brief This case tests size of empty list
     */
    void testEmptyList()
    {
        const int correctSize = 0;
        bubbleSort->sort(currentList, comparator);
        const int size = bubbleSort->getSize();
        QCOMPARE(size, correctSize);
    }

    /*!
     * \brief This case tests list of one element
     */
    void testOneElementList()
    {
        const int correctSize = 1;
        const int value = 26;
        int correctSortedList[correctSize] = {26};
        currentList.push_back(value);
        bubbleSort->sort(currentList, comparator);
        const int size = bubbleSort->getSize();
        QCOMPARE(size, correctSize);
        for (int i = 0; i < correctSize; ++i)
            QCOMPARE(correctSortedList[i], currentList[i]);
    }

    /*!
     * \brief This case tests list of random size
     */
    void testRandomList()
    {
        srand(time(NULL));
        const int maxSize = 13;
        const int maxValue = 17;
        const int correctSize = rand() % maxSize + 1;
        int correctSortedList[correctSize];
        for (int i = 0; i < correctSize; ++i)
        {
            const int value = rand() % maxValue + 1;
            currentList.push_back(value);
            correctSortedList[i] = value;
        }
        std::sort(correctSortedList, correctSortedList + correctSize);
        bubbleSort->sort(currentList, comparator);
        const int size = bubbleSort->getSize();
        QCOMPARE(size, correctSize);
        for (int i = 0; i < correctSize; ++i)
            QCOMPARE(correctSortedList[i], currentList[i]);
    }

};
