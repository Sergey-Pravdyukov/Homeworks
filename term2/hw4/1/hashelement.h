#pragma once

#include <QString>

/*!
 * \brief The HashElement class equal cell of HashTable
 *
 * contains string and its hash
 */
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

    /*!
     * \brief initForHash - special constant for init hash
     */
    const unsigned int initForHash = 0;
    /*!
     * \brief initForString - special constant for init string
     */
    const QString initForString = "";

    QString string = initForString;
    unsigned int hash = initForHash;
};
