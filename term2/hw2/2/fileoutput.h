#pragma once

#include <iostream>
#include <stdio.h>

#include "output.h"

/*!
 * \brief This class for output 2D array to file
 */
class FileOutput : public Output
{
public:
    FileOutput(int **currentArray, const int &currentSize);
    ~FileOutput();
};
