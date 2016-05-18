#pragma once

#include "hash.h"

/*!
 * \brief This class calculates H37 hash
 */
class HashH37 : public Hash
{
public:
    /*!
     * \brief calculate hash for current string
     * \param string
     * \return
     */
    unsigned int calculateHash(const QString &string);
};
