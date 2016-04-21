#include <iostream>
#include <fstream>
#include <cstdio>
#include "outputer.h"
#include "fileoutput.h"
#include "consoleoutput.h"

using namespace std;

const int maxSize = int(1e3);

enum
{
    init,
    fileOutput,
    consoleOutput
};

int main()
{
    ifstream in("input.txt");
    int size = 0;
    in >> size;
    int **array = new int*[maxSize];
    for (int i = 0; i < size; ++i)
    {
        array[i] = new int[maxSize];
        for (int j = 0; j < size; ++j)
        {
            in >> array[i][j];
        }
    }
    int typeOfOutput = init;
    in >> typeOfOutput;
    switch (typeOfOutput)
    {
    case fileOutput:
    {
        FileOutput *output = new FileOutput(array, size);
        output->snake();
        break;
    }
    case consoleOutput:
    {
        ConsoleOutput *output = new ConsoleOutput(array, size);
        output->snake();
        break;
    }
    }
    return 0;
}
