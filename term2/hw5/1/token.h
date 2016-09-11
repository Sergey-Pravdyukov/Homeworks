#pragma once

#include <QString>

/*!
 * \brief This class determine type of token
 */
class Token
{
public:
    /*!
     * \brief determine that token is operation or not
     * \param token
     * \return
     */
    static bool isOperation(const QString &token);
    /*!
     * \brief determine that token is bracket or not
     * \param token
     * \return
     */
    static bool isBracket(const QChar &token);
    /*!
     * \brief determine that token is space or not
     * \param token
     * \return
     */
    static bool isSpace(const QChar &token);
    /*!
     * \brief determine that token is component of number or not
     * \param token
     * \return
     */
    static bool isDigit(const QChar &token);
};
