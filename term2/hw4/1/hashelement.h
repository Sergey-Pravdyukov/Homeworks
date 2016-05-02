#pragma once

#include <QString>

class HashElement
{
public:
    HashElement(){}
    HashElement(QString currentString, int currentHash)
    {
        string = currentString;
        hash = currentHash;
    }

    friend bool operator ==(HashElement &left, HashElement &right)
    {
        return (left.hash == right.hash && left.string == right.string);
    }
    HashElement &operator =(const HashElement &right)
    {
        string = right.string;
        hash = right.hash;
        return *this;
    }

    const unsigned int initForHash = 0;
    const QString initForString = "";

    QString string = initForString;
    unsigned int hash = initForHash;
};
