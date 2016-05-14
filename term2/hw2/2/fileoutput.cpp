#include "fileoutput.h"

FileOutput::FileOutput(int **currentArray, const int &currentSize)
{
    std::cout << "Please press Enter" << std::endl;
    freopen("output.txt", "w", stdout);
    array = currentArray;
    size = currentSize;
}

void FileOutput::print(const QVector<int> &recordSnakeCrawling)
{
    std::cout << "Output of array bypass snake: ";
    for (int i = 0; i < recordSnakeCrawling.size(); ++i)
        std::cout << recordSnakeCrawling[i] << " ";
}

FileOutput::~FileOutput()
{
    fclose(stdout);
}
