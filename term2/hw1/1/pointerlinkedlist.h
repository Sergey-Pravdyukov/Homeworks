#pragma once

#include <iostream>

#include "list.h"

const int init = -1;

template <typename Type>
class PointerLinkedList : public List <Type>
{
public:
    PointerLinkedList(){}
    ~PointerLinkedList()
    {
        while (head != nullptr)
        {
            ListElement *temp = head->next;
            delete head;
            head = temp;
        }
    }
private:
    class ListElement
    {
    public:
        ListElement(const Type currentValue)
        {
            value = currentValue;
        }
        Type value = init;
        ListElement *next = nullptr;
    };
    void add(const Type value)
    {
        ListElement *newElement = new ListElement(value);
        List<Type>::size += 1;
        if (List<Type>::size == 1)
        {
            head = tail = newElement;
            std::cout << value << " added" << std::endl;
            return;
        }
        if (List<Type>::size == 2)
        {
            head->next = newElement;
        }
        tail->next = newElement;
        tail = tail->next;
        std::cout << value << " added" << std::endl;
    }

    void remove(const Type value)
    {
        ListElement *currentElement = head;
        if (currentElement->value == value)
        {
            ListElement *newElement = new ListElement(head->value);
            newElement->next = head->next;
            delete head;
            head = newElement->next;
            std::cout << value << " founded" << std::endl;
            delete newElement;
            List<Type>::size -= 1;
            return;
        }
        ListElement *previousElement = currentElement;
        currentElement = currentElement->next;
        for (int i = 1; i < List<Type>::size; ++i)
        {
            if (currentElement->value == value)
            {
                previousElement->next = currentElement->next;
                std::cout << value << " founded" << std::endl;
                List<Type>::size -= 1;
                return;
            }
        }
        std::cout << value << " not founded" << std::endl;
    }

    void debugOutput()
    {
        if (head == nullptr)
        {
            std::cout << "Pointer linked list is empty" << std::endl;
            return;
        }
        std::cout << "Debug output: ";
        ListElement *currentElement = head;
        while (currentElement != nullptr)
        {
            std::cout << currentElement->value << " ";
            currentElement = currentElement->next;
        }
        std::cout << std::endl;
    }

    int lenght()
    {
        return List<Type>::size;
    }

    ListElement *head = nullptr;
    ListElement *tail = nullptr;
};
