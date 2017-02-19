#include "hashtable.h"

HashTable::HashTable(const int &currentSize)
    : hashType(H37)
{
    hashTableCells = new QList<HashElement>[maxPrimeNumber];
    size = currentSize;
    hash = new HashH37();
}

void HashTable::debugOutput() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << i << " ";
        for (int j = 0; j < hashTableCells[i].size(); ++j)
        {
            QTextStream qtout(stdout);
            qtout << hashTableCells[i][j].string << " ";
        }
        std::cout << std::endl;
    }
}

bool isPrime(const int &value)
{
    for (int i = 2; i <= int(sqrt(value)); ++i)
        if (value % i == 0)
            return false;
    return true;
}

void findPrime(int &size, const int &maxSize)
{
    size *= 5;
    for (int i = 0; i <= maxSize; ++i)
        if (isPrime(size + i))
        {
            size += i;
            break;
        }
}

void HashTable::recalcHashTable()
{
    numberOfCells = 0;
    for (int i = 0; i < size; ++i)
        for (QList<HashElement>::iterator it = hashTableCells[i].begin(); it != hashTableCells[i].end(); ++it)
        {
            *it = HashElement(it->string, hash->calculateHash(it->string));
            if (i != int(it->hash % size))
            {
                HashElement removedElement = *it;
                hashTableCells[i].erase(it);
                add(removedElement.string);
            }
        }
}

void HashTable::changeHash(const int &newHashType)
{
    switch(newHashType)
    {
    case H37:
    {
        hash = new HashH37();
        break;
    }
    case FAQ6:
    {
        hash = new HashFAQ6();
        break;
    }
    case Ly:
        hash = new HashLy();
        break;
    }
    recalcHashTable();
}

void HashTable::rebuildHashTable()
{
    findPrime(size, maximalDifferenceBetweenAdjacentPrimes);
    HashTable::recalcHashTable();
}

void HashTable::add(const QString &currentString)
{
    HashElement hashElement = HashElement(currentString, hash->calculateHash(currentString));
    const int index = hashElement.hash % size;
    hashTableCells[index].push_back(hashElement);
    ++numberOfCells;
    if (haveLoadFactor() > maxLoadFactor)
        rebuildHashTable();
}

QString HashTable::remove(const QString &currentString)
{
    HashElement removedElement = HashElement();
    HashElement hashElement = HashElement(currentString, hash->calculateHash(currentString));
    const int index = hashElement.hash % size;
    for (QList<HashElement>::iterator it = hashTableCells[index].begin(); it != hashTableCells[index].end(); ++it)
        if (*it == hashElement)
        {
            removedElement = *it;
            hashTableCells[index].erase(it);
            --numberOfCells;
            break;
        }
    return removedElement.string;
}

int HashTable::find(const QString &currentString)
{
    HashElement hashElement = HashElement(currentString, hash->calculateHash(currentString));
    const int index = hashElement.hash % size;
    const int notFound = -1;
    for (QList<HashElement>::iterator it = hashTableCells[index].begin(); it != hashTableCells[index].end(); ++it)
        if (*it == hashElement)
            return index;
    return notFound;
}

int HashTable::haveNumberOfCells() const
{
    return numberOfCells;
}

double HashTable::haveLoadFactor() const
{
    return double(numberOfCells) / size;
}

int HashTable::haveNumberOfConflicts() const
{
    int result = 0;
    for (int i = 0; i < size; ++i)
        result += (hashTableCells[i].size() > conflictFreeCellSize);
    return result;
}

int HashTable::haveMaxSizeOfConflictList() const
{
    int result = 0;
    for (int i = 0; i < size; ++i)
        result = std::max(result, (hashTableCells[i].size() > conflictFreeCellSize) * hashTableCells[i].size());
    return result;
}

void HashTable::haveStatisctics(int &numberOfCells, double &loadFactor, int &numberOfConflicts, int &maxSizeOfConflictList) const
{
    numberOfCells = haveNumberOfCells();
    loadFactor = haveLoadFactor();
    numberOfConflicts = haveNumberOfConflicts();
    maxSizeOfConflictList = haveMaxSizeOfConflictList();
}

int HashTable::haveSize() const
{
    return size;
}

HashTable::~HashTable()
{
    delete hashTableCells;
    delete hash;
}
