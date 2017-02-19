#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Hash
{
    unsigned long long value;
    int indexOfString;
};

Hash haveHash(char currentString[], int counter)
{
    Hash result = {int(1e9 + 7), counter};
    const int primeNumber = 37;
    for (int i = 0; i < strlen(currentString); ++i)
    {
        result.value += result.value * primeNumber + currentString[i];
    }
    return result;
}

void input(char file[][100], Hash hashInCurrentFile[], int &numberOfStringInFile)
{
    char currentChar = '?';
    int currentLenghtOfString = 0;
    while ((currentChar = getc(stdin)) != EOF)
    {
        if (currentChar == '\n')
        {
            hashInCurrentFile[numberOfStringInFile] = haveHash(file[numberOfStringInFile],
                                                               numberOfStringInFile);
            ++numberOfStringInFile;
            currentLenghtOfString = 0;
            continue;
        }
        file[numberOfStringInFile][currentLenghtOfString++] = currentChar;
    }
}

void quicksort(Hash HashInCurrentFile[], int left, int right)
{
    int i = left;
    int j = right;
    unsigned long long middle = HashInCurrentFile[(i + j) / 2].value;
    while (i < j)
    {
        while (HashInCurrentFile[i].value < middle)
        {
            i++;
        }
        while (HashInCurrentFile[j].value > middle)
        {
            j--;
        }
        if (i <= j)
        {
            Hash current = HashInCurrentFile[i];
            HashInCurrentFile[i] = HashInCurrentFile[j];
            HashInCurrentFile[j] = current;
            i++;
            j--;
        }
    }
    if (left < j)
    {
        quicksort(HashInCurrentFile, left, j);
    }
    if (i < right)
    {
        quicksort(HashInCurrentFile, i, right);
    }
}

bool haveFindHash(Hash hashInSecondFile[], unsigned long long value, int left, int right)
{
    while (left < right - 1)
    {
        int middle = (left + right) / 2;
        (hashInSecondFile[middle].value >= value) ? right = middle : left = middle;
    }
    return (hashInSecondFile[right].value == value);
}

void output(char firstFile[][100], int index)
{
    for (int i = 0; i < strlen(firstFile[index]); ++i)
    {
        cout << firstFile[index][i];
    }
    cout << endl;
}

int main()
{
    const int maxSize = 1e2;
    freopen("firstInput.txt", "r", stdin);
    char firstFile[maxSize][maxSize];
    int numberOfStringsInFirstFile = 0;
    Hash hashInFirstFile[maxSize];
    input(firstFile, hashInFirstFile, numberOfStringsInFirstFile);
    freopen("secondInput.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char secondFile[maxSize][maxSize];
    int numberOfStringsInSecondFile = 0;
    Hash hashInSecondFile[maxSize];
    input(secondFile, hashInSecondFile, numberOfStringsInSecondFile);
    quicksort(hashInFirstFile, 0, numberOfStringsInFirstFile - 1);
    quicksort(hashInSecondFile, 0, numberOfStringsInSecondFile - 1);
    cout << "Строки, которые встречаются и в первом, и во втором файлах: " << endl;
    for (int i = 0; i < numberOfStringsInFirstFile; ++i)
    {
        if(haveFindHash(hashInSecondFile, hashInFirstFile[i].value, 0, numberOfStringsInSecondFile))
        {
            output(firstFile, hashInFirstFile[i].indexOfString);
        }
    }
    return 0;
}
