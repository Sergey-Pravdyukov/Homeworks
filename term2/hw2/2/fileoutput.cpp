#include "fileoutput.h"

FileOutput::FileOutput(int **currentArray, const int &currentSize)
{
    std::cout << "Please press Enter" << std::endl;
    freopen("output.txt", "w", stdout);
    array = currentArray;
    size = currentSize;
}

FileOutput::~FileOutput()
{
    fclose(stdout);
}
