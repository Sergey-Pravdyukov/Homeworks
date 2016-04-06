#pragma once

#include <QString>
#include <QVector>

class Parser
{
public:
    Parser(){}

    static QVector<QString> haveParse(const QString &displayText);

};


