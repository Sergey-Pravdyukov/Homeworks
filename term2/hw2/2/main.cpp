#include <iostream>
#include <fstream>
#include <cstdio>
#include <QtTest/QtTest>

#include "outputer.h"
#include "fileoutput.h"
#include "consoleoutput.h"
#include "testoutputer.h"

using namespace std;

enum {
    typeOfOutputInit,
    fileOutput,
    consoleOutput};

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
    switch (typeOfOutput)
    {
    case fileOutput:
    {
        FileOutput *output = new FileOutput(array, size);
        output->print();
        break;
    }
    case consoleOutput:
    {
        ConsoleOutput *output = new ConsoleOutput(array, size);
        output->print();
        break;
    }
    }

    cout << endl;
    TestOutputer test;
    QTest::qExec(&test);
    return 0;
}
