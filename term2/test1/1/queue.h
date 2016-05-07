#pragma once

#include <iostream>

const int initValue = -1;
const int initSize = 0;

template <typename Type>
class Queue
{
public:
    Queue(){}
    ~Queue(){}

    class QueueElement
    {
    public:
        QueueElement(Type currentValue)
        {
            key = currentValue % 10;
            value = currentValue;

        }
        Type key = initValue;
        Type value = initValue;
        QueueElement *next = nullptr;
    };

    void enqueue(const Type value)
    {
        QueueElement *newElement = new QueueElement(value);
        ++size;
        if (size == 1)
        {
            head = tail = newElement;
            debugOutput();
            return;
        }
        if (size == 2)
        {
            if (head->key >= newElement->key)
            {
                head->next = tail->next = newElement;
                tail = tail->next;
            }
            else
            {
                head = newElement;
                head->next = tail;
            }
            debugOutput();
            return;
        }
        QueueElement *currentElement = head;
        QueueElement *precurrentElement = nullptr;
        while (currentElement != nullptr)
        {
            if (newElement->key >= currentElement->key)
            {
                newElement->next = currentElement;
                (precurrentElement == nullptr) ? head = newElement
                                               : precurrentElement->next = newElement;
                debugOutput();
                return;
            }
            else
            {
                precurrentElement = currentElement;
                currentElement = currentElement->next;
            }
        }
        tail->next = newElement;
        tail = tail->next;

    }

    QueueElement degueue()
    {
        QueueElement removedElement = *head;
        std::cout << "( " << removedElement.key << " )" << std::endl;
        QueueElement *temp = head->next;
        delete head;
        head = temp;
        --size;
        return removedElement;
    }

    void debugOutput()
    {
        std::cout << "afdaf" << std::endl;
        QueueElement *currentElement = head;
        while (currentElement != nullptr)
        {
            std::cout << currentElement->key << " " << currentElement->value << std::endl;
            currentElement = currentElement->next;
        }
    }

    int size = initSize;

private:
    QueueElement *head = nullptr;
    QueueElement *tail = nullptr;

};
