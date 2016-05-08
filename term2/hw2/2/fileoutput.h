#pragma once

#include <fstream>

#include "outputer.h"

class FileOutput
{
public:
    FileOutput(int **currentArray, int currentSize);
    ~FileOutput();

    void print();
protected:
    const int initSize = 0;

    int size = initSize;
    int **array = nullptr;
private:
    std::ofstream fout;
};
