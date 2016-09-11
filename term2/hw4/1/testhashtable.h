#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

#include "hashtable.h"

class TestHashTable : public QObject
{
    Q_OBJECT

public:
    explicit TestHashTable(QObject *parent = 0):
        QObject(parent)
    {}

private:
    const int primeNumber = 5;
    const int primeNumberForStrings = 83;
    const int sizeInit = 0;
    int size = sizeInit;

    HashTable *hashTable;
    Hash *hash;

    QString generateString()
    {
        srand(time(NULL));
        const int maxSizeOfString = 17;
        const int sizeOfString = rand() % maxSizeOfString + 1;
        const int numberOfLetters = 26;
        QString generatedString = "";
        for (int i = 0; i < sizeOfString; ++i)
        {
            QChar generatedChar = QChar(rand() % numberOfLetters + 'a');
            generatedString += generatedChar;
        }
        return generatedString;
    }

private slots:
    void init()
    {
        srand(time(NULL));
        size = rand() % primeNumber + 1;
        hashTable = new HashTable(size);
        hash = new HashH37();
    }

    void cleanup()
    {
        delete hashTable;
        delete hash;
    }

    void testCellsNumberInEmptyHashTable()
    {
        const int correctValue = 0;
        const int numberOfCells = hashTable->haveNumberOfCells();
        QCOMPARE(numberOfCells, correctValue);
    }

    void testNumberOfCells()
    {
        const QString currentString = generateString();
        const int correctNumberOfCells = 1;
        hashTable->add(currentString);
        const int numberOfCells = hashTable->haveNumberOfCells();
        QCOMPARE(numberOfCells, correctNumberOfCells);
    }

    void testFindElementInEmptyHashTable()
    {
        const QString currentString = generateString();
        const int correctIndex = -1;
        const int index = hashTable->find(currentString);
        QCOMPARE(index, correctIndex);
    }

    void testAddAndFindElement()
    {
        const QString currentString = generateString();
        hashTable->add(currentString);
        const int correctIndex = hash->calculateHash(currentString) % hashTable->haveSize();
        const int index = hashTable->find(currentString);
        QCOMPARE(index, correctIndex);
    }

    void testAddAndFindElements()
    {
        const int numberOfAddedElements = primeNumberForStrings;
        QString strings[numberOfAddedElements];
        for (int i = 0; i < numberOfAddedElements; ++i)
        {
            const QString currentString = generateString();
            strings[i] = currentString;
            hashTable->add(currentString);
        }
        for (int i = 0; i < numberOfAddedElements; ++i)
        {
            const int correctIndex = hash->calculateHash(strings[i]) % hashTable->haveSize();
            const int index = hashTable->find(strings[i]);
            QCOMPARE(index, correctIndex);
        }
    }

    void testRemoveElement()
    {
        const QString currentString = generateString();
        hashTable->add(currentString);
        const QString removedString = hashTable->remove(currentString);
        QCOMPARE(removedString, currentString);
    }

    void testRemoveElements()
    {
        const int numberOfStrings = primeNumberForStrings;
        QString strings[numberOfStrings];
        int indexes[numberOfStrings];
        for (int i = 0; i < numberOfStrings; ++i)
        {
            const QString currentString = generateString();
            strings[i] = currentString;
            indexes[i] = i;
            hashTable->add(currentString);
        }
        std::random_shuffle(indexes, indexes + numberOfStrings);
        for (int i = 0; i < numberOfStrings; ++i)
        {
            QString removedString = hashTable->remove(strings[indexes[i]]);
            QCOMPARE(removedString, strings[indexes[i]]);
        }
    }

    void testChooseHash()
    {
        const int numberOfStrings = primeNumberForStrings;
        QString strings[numberOfStrings];
        for (int i = 0; i < numberOfStrings; ++i)
        {
            const QString currentString = generateString();
            strings[i] = currentString;
            hashTable->add(currentString);
        }
        int hashType = FAQ6;
        hash = new HashFAQ6();
        hashTable->changeHash(hashType);
        for (int i = 0; i < numberOfStrings; ++i)
        {
            const int correctIndex = hash->calculateHash(strings[i]) % hashTable->haveSize();
            const int index = hashTable->find(strings[i]);
            QCOMPARE(index, correctIndex);
        }
        hashType = Ly;
        hash = new HashLy();
        hashTable->changeHash(hashType);
        for (int i = 0; i < numberOfStrings; ++i)
        {
            const int correctIndex = hash->calculateHash(strings[i]) % hashTable->haveSize();
            const int index = hashTable->find(strings[i]);
            QCOMPARE(index, correctIndex);
        }
    }
};
