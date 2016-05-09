#include "fileoutput.h"

FileOutput::FileOutput(int **currentArray, int currentSize)
{
    std::cout << "Please press Enter" << std::endl;
    freopen("output.txt", "w", stdout);
    array = currentArray;
    size = currentSize;
}

void FileOutput::print()
{
    Outputer *output = new Outputer();
    const bool isOutput = true;
    output->snakePrint(size, array, isOutput);
}

FileOutput::~FileOutput()
{
    fclose(stdout);
}
