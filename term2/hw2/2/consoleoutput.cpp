#include <iostream>

#include "consoleoutput.h"

ConsoleOutput::ConsoleOutput(int **currentArray, int currentSize)
{
    array = currentArray;
    size = currentSize;
}

void ConsoleOutput::print()
{
    const bool isOutput = true;
    Outputer::snakePrint(size, array, isOutput);
}
