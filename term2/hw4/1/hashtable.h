#pragma once

#include <QList>
#include <QTextStream>
#include <iostream>

#include "hashelement.h"
#include "hashh37.h"
#include "hashfaq6.h"
#include "hashly.h"

enum HashTypeForHashTable
{
    init,
    H37,
    FAQ6,
    Ly
};

/*!
 * \brief The HashTable class contains array of HashElement lists
 */
class HashTable
{
public:
    HashTable(const int &currentSize);
    ~HashTable();

    /*!
     * \brief add current string to HashTable
     */
    void add(const QString &currentString);
    /*!
     * \brief remove sought string from HashTable
     * \return HashElement of string
     */
    QString remove(const QString &currentString);
    /*!
     * \brief find current string in HashTable
     * \return if found return index of hashTable list, otherwise return -1
     */
    int find(const QString &currentString);
    /*!
     * \brief haveStatisctics current status of HashTable
     *
     * Calculate number of cells, load factor,
     * number of cinflict cells, max size of list in conflict cell
     */
    void haveStatisctics(int &numberOfCells, double &loadFactor,
                         int &numberOfConflicts, int &maxSizeOfConflictList) const;
    /*!
     * \brief changeHash current status of HashTable
     * \param newHashType of HashTable
     */
    void changeHash(const int &newHashType);
    /*!
     * \brief debugOutput all HashTable
     */
    int haveSize() const;
    /*!
     * \brief have number of added elements
     * \return
     */
    int haveNumberOfCells() const;
private:
    /*!
     * \brief maximalDifferenceBetweenAdjacentPrimes - magic constant for adjacent primes less than 10^9
     */
    const int maximalDifferenceBetweenAdjacentPrimes = 1476;

    /*!
     * \brief rebuildHashTable changed size of HashTable and recalcHashTable();
     */
    void rebuildHashTable();
    /*!
     * \brief recalcHashTable
     *
     * removed HashElement, changed its hash, add HashElement to HashTable
     */
    void recalcHashTable();
    /*!
     * \brief haveLoadFactor recalc load factor of increased HashTable
     */
    void debugOutput() const;
    /*!
     * \brief haveSize
     * \return size of HashTable array
     */
    double haveLoadFactor() const;
    int haveNumberOfConflicts() const;
    int haveMaxSizeOfConflictList() const;

    static const int maxPrimeNumber = 9369319;
    const int sizeInit = 0;
    const int numberOfCellsInit = 0;
    const int conflictFreeCellSize = 1;
    const double maxLoadFactor = 0.5;

    int hashType = init;
    Hash *hash;
    int numberOfCells = numberOfCellsInit;
    int size = sizeInit;
    QList<HashElement> *hashTableCells;
};
