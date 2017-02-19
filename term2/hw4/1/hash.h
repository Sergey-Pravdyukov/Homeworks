#pragma once

#include <QString>

/*!
 * \brief The Hash class for calculate any hash function
 */
class Hash
{
public:
    /*!
     * \brief calculate hash for current string
     * \param string
     * \return
     */
    virtual unsigned int calculateHash(const QString &string) = 0;
};
