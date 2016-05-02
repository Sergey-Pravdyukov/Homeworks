#include "hash.h"

unsigned int Hash::hashH37(const QString &string)
{
    unsigned int hash = 2139062143;
    for (int i = 0; i < string.size(); ++i)
        hash = 37 * hash + string[i].toLatin1();
    return hash;
}

unsigned int Hash::hashFAQ6(const QString &string)
{
    unsigned int hash = 0;
    for (int i = 0; i < string.size(); ++i)
    {
        hash += (unsigned char)(string[i].toLatin1());
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

unsigned int Hash::hashLy(const QString &string)
{
    unsigned int hash = 0;
    for (int i = 0; i < string.size(); ++i)
        hash = (hash * 1664525) + (unsigned char)(string[i].toLatin1()) + 1013904223;
    return hash;
}
