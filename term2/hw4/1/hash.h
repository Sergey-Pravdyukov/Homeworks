#pragma once

#include <QString>

class Hash
{
public:
    Hash(){}

    static unsigned int hashH37(const QString &string);
    static unsigned int hashFAQ6(const QString &string);
    static unsigned int hashLy(const QString &string);
};