#pragma once

#include <QList>
#include <QTextStream>
#include <iostream>

#include "hashelement.h"
#include "hash.h"

/*!
 * \brief The HashTable class contains array of HashElement lists
 */
class HashTable
{
public:
    HashTable(const int &currentSize, const int &currentHashType);

    /*!
     * \brief add current string to HashTable
     */
    void add(const QString &currentString);
    /*!
     * \brief remove sought string from HashTable
     * \return HashElement of string
     */
    HashElement remove(const QString &currentString);
    /*!
     * \brief find current string in HashTable
     * \return true if string founded otherwise false
     */
    bool find(const QString &currentString);
    /*!
     * \brief haveStatisctics current status of HashTable
     *
     * Calculate number of cells, load factor,
     * number of cinflict cells, max size of list in conflict cell
     */
    void haveStatisctics();
    /*!
     * \brief changeHash current status of HashTable
     * \param newHashType of HashTable
     */
    void changeHash(const int &newHashType);
    /*!
     * \brief debugOutput all HashTable
     */
    void debugOutput();

    /*!
     * \brief maximalDifferenceBetweenAdjacentPrimes - magic constant for adjacent primes less than 10^9
     */
    static const int maximalDifferenceBetweenAdjacentPrimes = 1476;
private:
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
     * \brief compareHash
     * \param currentString
     * \return HashElement with suitable hash
     */
    HashElement compareHash(const QString &currentString);
    /*!
     * \brief haveLoadFactor recalc load factor of increased HashTable
     */
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
