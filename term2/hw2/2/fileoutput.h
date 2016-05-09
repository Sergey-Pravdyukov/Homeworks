#pragma once

#include <fstream>
#include <iostream>
#include <stdio.h>

#include "outputer.h"

class FileOutput
{
public:
    FileOutput(int **currentArray, int currentSize);
    ~FileOutput();

    void print();
private:
    const int initSize = 0;

    int size = initSize;
    int **array = nullptr;
};
