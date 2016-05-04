#include "hashtable.h"

HashTable::HashTable(const int &currentSize, const int &currentHashType)
{
    size = currentSize;
    hashType = currentHashType;
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

void findPrime(int &size)
{
    size *= 5;
    for (int i = 0; i <= HashTable::maximalDifferenceBetweenAdjacentPrimes; ++i)
        if (isPrime(size + i))
        {
            size += i;
            break;
        }
}

HashElement HashTable::compareHash(const QString &currentString) const
{
    HashElement hashElement = HashElement();
    switch (hashType)
    {
    case 1:
    {
        hashElement = HashElement(currentString, Hash::hashH37(currentString));
        break;
    }
    case 2:
    {
        hashElement = HashElement(currentString, Hash::hashFAQ6(currentString));
        break;
    }
    case 3:
    {
        hashElement = HashElement(currentString, Hash::hashLy(currentString));
        break;
    }
    default:
        break;
    }
    return hashElement;
}

void HashTable::recalcHashTable()
{
    numberOfCells = 0;
    for (int i = 0; i < size; ++i)
    {
        for (QList<HashElement>::iterator it = hashTableCells[i].begin(); it != hashTableCells[i].end(); ++it)
        {
            *it = compareHash(it->string);

            if (i != int(it->hash % size))
            {
                HashElement removedElement = *it;
                hashTableCells[i].erase(it);
                add(removedElement.string);
            }
        }
    }
}

void HashTable::changeHash(const int &newHashType)
{
    hashType = newHashType;
    recalcHashTable();
}

void HashTable::rebuildHashTable()
{
    findPrime(size);
    HashTable::recalcHashTable();
}

void HashTable::add(const QString &currentString)
{

    HashElement hashElement = compareHash(currentString);
    const int index = hashElement.hash % size;
    hashTableCells[index].push_back(hashElement);
    ++numberOfCells;
    if (haveLoadFactor() > maxLoadFactor)
        rebuildHashTable();
}

HashElement HashTable::remove(const QString &currentString)
{
    HashElement removedElement = HashElement();
    HashElement hashElement = compareHash(currentString);
    const int index = hashElement.hash % size;
    for (QList<HashElement>::iterator it = hashTableCells[index].begin(); it != hashTableCells[index].end(); ++it)
        if (*it == hashElement)
        {
            removedElement = *it;
            hashTableCells[index].erase(it);
            --numberOfCells;
            break;
        }
    return removedElement;
}

bool HashTable::find(const QString &currentString)
{
    HashElement hashElement = compareHash(currentString);
    const int index = hashElement.hash % size;
    for (QList<HashElement>::iterator it = hashTableCells[index].begin(); it != hashTableCells[index].end(); ++it)
        if (*it == hashElement)
            return true;
    return false;
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

void HashTable::haveStatisctics() const
{
    std::cout << "number of cells: " << haveNumberOfCells() << std::endl
              << "load factor: " << haveLoadFactor() << std::endl
              << "number of conflicts: " << haveNumberOfConflicts() << std::endl
              << "maximal size of list in conflict cells: " << haveMaxSizeOfConflictList() << std::endl;
}
