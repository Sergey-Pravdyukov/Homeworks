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
    HashElement(QString currentString, int currentHash)
    {
        string = currentString;
        hash = currentHash;
    }

    friend bool operator ==(HashElement &left, HashElement &right)
    {
        return (left.hash == right.hash && left.string == right.string);
    }
    HashElement &operator =(const HashElement &rightValue)
    {
        string = rightValue.string;
        hash = rightValue.hash;
        return *this;
    }
private:
    /*!
     * \brief initForHash - special constant for init hash
     */
    const unsigned int hashInit = 0;
    /*!
     * \brief initForString - special constant for init string
     */
    const QString stringInit = "/0";

    QString string = stringInit;
    unsigned int hash = hashInit;
};
