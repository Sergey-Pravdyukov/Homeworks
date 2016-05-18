#pragma once

#include <QString>

enum OperationPriopity
{
    notAnOperation,
    highPriorityOperation,
    lowPriorityOperation
};

/*!
 * \brief The Token class for check type of Token
 */
class Token
{
public:
    /*!
     * \brief determine priority of arithmentic operation
     * \param token
     * \return 0 if it is not arithmetic operation,
     * 1 if it is sum or difference,
     * 2 if it is multiplication or division
     */
    static int operationPriority(const QString &token);
    /*!
     * \brief check that token is number
     * \param token
     * \return
     */
    static bool isNumber(const QString &token);
    /*!
     * \brief check that token is bracket
     * \param token
     * \return
     */
    static bool isBracket(const QString &token);
};
