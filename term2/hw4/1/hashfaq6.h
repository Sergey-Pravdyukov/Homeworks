#pragma once

#include "hash.h"

/*!
 * \brief This class calculates FAQ6 hash
 */
class HashFAQ6 : public Hash
{
public:
    /*!
     * \brief calculate hash for current string
     * \param string
     * \return
     */
    unsigned int calculateHash(const QString &string);
};
