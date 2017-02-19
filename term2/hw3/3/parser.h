#pragma once

#include <QString>
#include <QVector>

/*!
 * \brief This class parse deisplay text
 *
 * This class parse display text to tokens for arithmetic expressions
 */
class Parser
{
public:
    /*!
     * \brief parse display text to arithmetic expressions
     * \param displayText
     * \return set of tokens for expression
     */
    static QVector<QString> haveParseDisplayTextToExpressions(const QString &displayText);
};
