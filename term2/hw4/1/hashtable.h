#pragma once

#include <QList>
#include <QTextStream>
#include <iostream>

#include "hashelement.h"
#include "hash.h"

class HashTable
{
public:
    HashTable(const int &currentSize, const int &currentHashType);

    void add(const QString &currentString);
    HashElement remove(const QString &currentString);
    bool find(const QString &currentString);
    void haveStatisctics();
    void changeHash(const int &newHashType);
    void debugOutput();

    static const int maximalDifferenceBetweenAdjacentPrimes = 1476;
private:
    void rebuildHashTable();
    void recalcHashTable();
    HashElement compareHash(const QString &currentString);
    double haveLoadFactor();
    int haveNumberOfConflicts();
    int haveMaxSizeOfConflictList();
    int haveNumberOfCells();

    static const int maxPrimeNumber = 9369319;
    const int hashTableInit = 0;
    const int conflictFreeCellSize = 1;
    const double maxLoadFactor = 0.5;

    int hashType = hashTableInit;

    int numberOfCells = hashTableInit;
    int size = hashTableInit;
    QList<HashElement> hashTableCells[maxPrimeNumber];
};
