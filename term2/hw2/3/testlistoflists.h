#pragma once

#include <QObject>
#include <QtTest/QtTest>

#include "listoflists.h"

class TestListOfLists : public QObject
{
    Q_OBJECT

public:
    explicit TestListOfLists(QObject *parent = 0):
        QObject(parent)
    {}

private:
    ListOfLists *currentListOfLists;
    List *currentList;

private slots:
    void init()
    {
        currentListOfLists = new ListOfLists();
        currentList = new List();
    }

    void cleanup()
    {
        delete currentListOfLists;
        delete currentList;
    }

    void testSizeOfEmptyListOfLists()
    {
        const int correctSizeOfListOsLists = 0;
        QCOMPARE(currentListOfLists->lenght(), correctSizeOfListOsLists);
    }

    void testSizeOfNonEmptyListOfLists()
    {
        const int value = 26;
        currentList->add(value);
        currentListOfLists->add(currentList);
        const int correctSizeOfListOfLists = 1;
        QCOMPARE(currentListOfLists->lenght(), correctSizeOfListOfLists);
    }

    void testAddList()
    {
        const int size = 7;
        for (int i = 0; i < size; ++i)
            currentList->add(i);
        currentListOfLists->add(currentList);
        int *correctArray = currentList->fromListToArray();
        List *recievedList = currentListOfLists->getHeadOfListOfLists();
        int *recievedArray = recievedList->fromListToArray();
        for (int i = 0; i < size; ++i)
            QCOMPARE(recievedArray[i], correctArray[i]);
    }
};
