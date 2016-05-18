#include "hashh37.h"

unsigned int HashH37::calculateHash(const QString &string)
{
    unsigned int hash = 2139062143;
    for (int i = 0; i < string.size(); ++i)
        hash = 37 * hash + string[i].toLatin1();
    return hash;
}
