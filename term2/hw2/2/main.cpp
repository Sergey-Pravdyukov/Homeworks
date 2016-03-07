#include <iostream>
#include <fstream>
#include <cstdio>
#include "outputer.h"
#include "fileoutput.h"
#include "consoleoutput.h"

using namespace std;

const int maxSize = int(1e3);

/// set of avaliable status for output

enum
{
    init, ///< initialized type of output
    fileOutput, ///< output in file
    consoleOutput ///< output in console
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
        FileOutput();
        break;
    }
    case consoleOutput:
    {
        ConsoleOutput();
        break;
    }
    }
    Outputer *output = new Outputer(array, size);
    output->snake();
    return 0;
}
