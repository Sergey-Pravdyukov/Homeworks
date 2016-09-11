#pragma once

#include "hash.h"

/*!
 * \brief This class calculates Ly hash
 */
class HashLy : public Hash
{
public:
    /*!
     * \brief calculate hash for current string
     * \param string
     * \return
     */
    unsigned int calculateHash(const QString &string);
};
