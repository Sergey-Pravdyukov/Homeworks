#pragma once

#include <QChar>

class Stack
{
public:
    Stack(){}

    class StackElement
    {
    public:
        StackElement(const QChar currentValue)
        {
            value = currentValue;
        }
        const QChar notAStackElement = '?';
        QChar value = notAStackElement;
        StackElement *next = nullptr;
    };

    StackElement *head = nullptr;
    void push(const QChar value);
    QChar pop();
    QChar top();

    int size = 0;
};
