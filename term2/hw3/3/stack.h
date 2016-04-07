#pragma once

#include <QString>

class Stack
{
public:
    Stack(){}

    class StackElement
    {
    public:
        StackElement(const QString &currentValue)
        {
            value = currentValue;
        }
        const QString notAStackElement = "?";
        QString value = notAStackElement;
        StackElement *next = nullptr;
    };

    StackElement *head = nullptr;
    void push(const QString &value);
    QString pop();
    QString top();

    int size = 0;
};
