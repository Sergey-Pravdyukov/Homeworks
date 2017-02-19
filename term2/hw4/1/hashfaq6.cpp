#include "hashfaq6.h"

unsigned int HashFAQ6::calculateHash(const QString &string)
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
