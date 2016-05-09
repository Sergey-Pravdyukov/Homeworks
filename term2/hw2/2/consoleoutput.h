#pragma once

#include "outputer.h"

class ConsoleOutput : public Outputer
{
public:
    ConsoleOutput(int **currentArray, int currentSize);
    /*!
     * \brief print 2D array bypass snake
     *
     * Printing begining from center
     */
    void print();
private:
    int size;
    int **array;
};

