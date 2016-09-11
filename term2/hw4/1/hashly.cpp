#include "hashly.h"

unsigned int HashLy::calculateHash(const QString &string)
{
    unsigned int hash = 0;
    for (int i = 0; i < string.size(); ++i)
        hash = (hash * 1664525) + (unsigned char)(string[i].toLatin1()) + 1013904223;
    return hash;
}
