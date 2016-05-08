#include "fileoutput.h"

FileOutput::FileOutput(int **currentArray, int currentSize)
{
    std::cout << "Please press Enter" << std::endl;
    fout.open("output.txt");
    array = currentArray;
    size = currentSize;
}

void FileOutput::print()
{
    Outputer::snakePrint(size, array, fout);
}

FileOutput::~FileOutput()
{
    fout.close();
}
