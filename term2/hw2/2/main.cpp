#include <iostream>
#include <fstream>
#include <cstdio>
#include <QtTest/QtTest>

#include "fileoutput.h"
#include "consoleoutput.h"
#include "testprinter.h"

using namespace std;

enum
{
    typeOfOutputInit,
    fileOutput,
    consoleOutput
};

int main()
{
    ifstream in("input.txt");
    const int maxSize = 100;
    const int sizeInit = 0;
    int size = sizeInit;
    in >> size;
    int **array = new int*[maxSize];
    for (int i = 0; i < size; ++i)
    {
        array[i] = new int[maxSize];
        for (int j = 0; j < size; ++j)
            in >> array[i][j];
    }
    int typeOfOutput = typeOfOutputInit;
    in >> typeOfOutput;
    Output *output;
    (typeOfOutput == fileOutput) ? output = new FileOutput(array, size)
                                 : output = new ConsoleOutput(array, size);
    output->print();

    cout << endl;
    TestPrinter test;
    QTest::qExec(&test);

    delete output;
    delete[] array;
    return 0;
}
