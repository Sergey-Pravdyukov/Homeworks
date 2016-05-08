#include <iostream>

#include "consoleoutput.h"

ConsoleOutput::ConsoleOutput(int **currentArray, int currentSize)
{
    array = currentArray;
    size = currentSize;
}

void ConsoleOutput::print()
{
    Outputer::snakePrint(size, array, std::cout);
}
