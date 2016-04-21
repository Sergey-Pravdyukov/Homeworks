#pragma once

#include "outputer.h"

class FileOutput : public Outputer
{
public:
    FileOutput(int **currentArray, int currentSize);
    /*!
     * \brief print 2D array bypass snake
     *
     * Printing begining from center
     */
    void snake();
protected:
    int size;
    int **array;
};
