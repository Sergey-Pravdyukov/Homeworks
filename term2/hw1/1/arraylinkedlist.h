#pragma once

#include <iostream>

#include "list.h"

template <typename Type>
class ArrayLinkedList : public List <Type>
{
public:
    ArrayLinkedList(){}

    ~ArrayLinkedList()
    {
        delete []array;
    }

private:

    void add(const Type value)
    {
        if (List<Type>::size < maxSize)
        {
            array[List<Type>::size] = value;
            List<Type>::size += 1;
        }
        std::cout << value << " added" << std::endl;
    }

    void remove(const Type value)
    {
        const int init = -1;
        int index = init;
        for (int i = 0; i < List<Type>::size; ++i)
        {
            if (array[i] == value)
            {
                index = i;
                break;
            }
        }
        if (index == init)
        {
            std::cout << value << " not founded" << std::endl;
            return;
        }
        for (int i = index + 1; i < List<Type>::size; ++i)
        {
            array[i - 1] = array[i];
        }
        List<Type>::size -= 1;
        std::cout << value << " founded" << std::endl;
    }

    void debugOutput()
    {
        if (List<Type>::size == 0)
        {
            std::cout << "Array linked list is empty" << std::endl;
            return;
        }
        std::cout << "Debug output: ";
        for (int i = 0; i < List<Type>::size; ++i)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    int lenght()
    {
        return List<Type>::size;
    }

    const int maxSize = int(1e3);
    Type *array = new Type[maxSize];
};
