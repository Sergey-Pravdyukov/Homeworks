#include "consoleoutput.h"

ConsoleOutput::ConsoleOutput(int **currentArray, const int &currentSize)
{
    array = currentArray;
    size = currentSize;
}

void ConsoleOutput::print(const QVector<int> &recordSnakeCrawling)
{
    std::cout << "Output of array bypass snake: ";
    for (int i = 0; i < recordSnakeCrawling.size(); ++i)
        std::cout << recordSnakeCrawling[i] << " ";
}
