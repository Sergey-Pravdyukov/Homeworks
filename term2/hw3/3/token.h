#pragma once

#include <QString>

class Token
{
public:
    Token(){}

    static bool isOperation(const QString &token);
    static bool isHighPriorityOperation(const QString &token);
    static bool isNumber(const QString &token);
    static bool isBracket(const QString &token);
};
