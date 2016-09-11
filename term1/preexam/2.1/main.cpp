#include <iostream>
#include <cstdio>

using namespace std;

void output(int x, int i, int j)
{
    cout << x << " - седловая точка " << i + 1 << " строки и " << j + 1 << " столбца." << endl;
}

void haveFindMinimum(long long arrayOfNumbers[][100], int numberOfStrings, int indexOfString,
                     long long &minimum, int &indexOfMinimum)
{
    for (int k = 0; k < numberOfStrings; ++k)
    {
        if (minimum > arrayOfNumbers[indexOfString][k])
        {
            minimum = arrayOfNumbers[indexOfString][k];
            indexOfMinimum = k;
        }
    }
}

void haveFindMaximum(long long arrayOfNumbers[][100], int numberOfCollumns, int indexOfCollumn,
                     long long &maximum, int &indexOfMaximum)
{
    for (int k = 0; k < numberOfCollumns; ++k)
    {
        if (maximum < arrayOfNumbers[k][indexOfCollumn])
        {
            maximum = arrayOfNumbers[k][indexOfCollumn];
            indexOfMaximum = k;
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    freopen("input.txt", "r", stdin);
    int numberOfStrings = 0;
    int numberOfCollumns = 0;
    const int maxSize = 1e2;
    long long arrayOfNumbers[maxSize][maxSize];
    cin >> numberOfStrings >> numberOfCollumns;
    for (int i = 0; i < numberOfStrings; ++i)
    {
        for (int j = 0; j < numberOfCollumns; ++j)
        {
            cin >> arrayOfNumbers[i][j];
        }
    }
    bool isFind = false;
    const long long infinity = 1e17;
    for (int i = 0; i < numberOfStrings; ++i)
    {
        for (int j = 0; j < numberOfCollumns; ++j)
        {
            long long minimum = infinity;
            int indexOfMinimum = -1;
            haveFindMinimum(arrayOfNumbers, numberOfStrings, i, minimum, indexOfMinimum);
            long long maximum = -infinity;
            int indexOfMaximum = -1;
            haveFindMaximum(arrayOfNumbers, numberOfCollumns, j, maximum, indexOfMaximum);
            if (indexOfMaximum == i && indexOfMinimum == j)
            {
                isFind = true;
                output(arrayOfNumbers[i][j], i, j);
            }
        }
    }
    if (!isFind)
    {
        cout << "Седловых точек не найдено." << endl;
    }
    return 0;
}

/*

5 5
3 3 3 1 1
5 5 4 8 7
3 2 3 3 3
1 1 1 2 1
1 1 1 1 1

*/
