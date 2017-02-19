#pragma once

#include <QObject>
#include <QtTest/QtTest>

#include "listcomparator.h"
#include "list.h"

class TestListComparator : public QObject
{
    Q_OBJECT

public:
    explicit TestListComparator(QObject *parent = 0):
        QObject(parent)
    {}
private:
    List *firstList;
    List *secondList;

private slots:
    void init()
    {
        firstList = new List();
        secondList = new List();
    }

    void cleanup()
    {
        delete firstList;
        delete secondList;
    }

    void testEmptyLists()
    {
        const int correctFisrtListSize = 0;
        QCOMPARE(firstList->lenght(), correctFisrtListSize);
        const int correctSecondListSize = 0;
        QCOMPARE(secondList->lenght(), correctSecondListSize);
        const bool correctListsCompare = false;
        QCOMPARE(ListComparator::isFirstLessThanSecond(firstList, secondList), correctListsCompare);
    }

    void testEmptyAndNonEmptyLists()
    {
        const int value = 26;
        secondList->add(value);
        const int correctFirstListSize = 0;
        QCOMPARE(firstList->lenght(), correctFirstListSize);
        const int correctSecondListSize = 1;
        QCOMPARE(secondList->lenght(), correctSecondListSize);
        const bool correctListsCompare = true;
        QCOMPARE(ListComparator::isFirstLessThanSecond(firstList, secondList), correctListsCompare);
    }

    void testNonEmptyAndEmptyLists()
    {
        const int value = 26;
        firstList->add(value);
        const int correctFirstListSize = 1;
        QCOMPARE(firstList->lenght(), correctFirstListSize);
        const int correctSecondListSize = 0;
        QCOMPARE(secondList->lenght(), correctSecondListSize);
        const bool correctListsCompare = false;
        QCOMPARE(ListComparator::isFirstLessThanSecond(firstList, secondList), correctListsCompare);
    }

    void testFirstLess()
    {
        const int correctFirstListSize = 13;
        for (int i = 0; i < correctFirstListSize; ++i)
            firstList->add(correctFirstListSize - i);
        QCOMPARE(firstList->lenght(), correctFirstListSize);
        const int correctSecondListSize = 19;
        for (int i = 0; i < correctSecondListSize; ++i)
            secondList->add(correctSecondListSize - i);
        QCOMPARE(secondList->lenght(), correctSecondListSize);
        const bool correctListsCompare = true;
        QCOMPARE(ListComparator::isFirstLessThanSecond(firstList, secondList), correctListsCompare);
    }

    void testSecondLess()
    {
        const int correctFirstListSize = 17;
        for (int i = 0; i < correctFirstListSize; ++i)
            firstList->add(correctFirstListSize - i);
        QCOMPARE(firstList->lenght(), correctFirstListSize);
        const int correctSecondListSize = 11;
        for (int i = 0; i < correctSecondListSize; ++i)
            secondList->add(correctSecondListSize - i);
        QCOMPARE(secondList->lenght(), correctSecondListSize);
        const bool correctListsCompare = false;
        QCOMPARE(ListComparator::isFirstLessThanSecond(firstList, secondList), correctListsCompare);
    }

    void testEqual()
    {
        const int correctFirstListSize = 23;
        for (int i = 0; i < correctFirstListSize; ++i)
            firstList->add(correctFirstListSize - i);
        QCOMPARE(firstList->lenght(), correctFirstListSize);
        const int correctSecondListSize = 23;
        for (int i = 0; i < correctSecondListSize; ++i)
            secondList->add(correctSecondListSize - i);
        QCOMPARE(secondList->lenght(), correctSecondListSize);
        const bool correctListsCompare = false;
        QCOMPARE(ListComparator::isFirstLessThanSecond(firstList, secondList), correctListsCompare);
    }
};
