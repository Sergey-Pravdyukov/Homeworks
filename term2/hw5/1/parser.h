#pragma once

#include <QString>
#include <QChar>
#include <QVector>

#include "token.h"

/*!
 * \brief This class parse expression
 *
 * This class parse expression to tokens
 */
class Parser
{
public:
    /*!
     * \brief parse expression to tokens
     * \param expression
     * \return set of tokens for expression
     */
    static QVector<QString> parseExpressionToTokens(const QString &expression);
};
