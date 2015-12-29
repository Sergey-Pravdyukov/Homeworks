#include <iostream>

using namespace std;

int haveSumOfDigits(int current)
{
    int result = 0;
    while (current != 0)
    {
        result += current % 10;
        current /= 10;
    }
    return result;
}

int isSlowSolve1()
{
    int result = 0;
    int l = 0;
    int r = (int)1e6;
    for (int i = l; i < r; ++i)
    {
        int lNumber = i / 1000;
        int rNumber = i % 1000;
        int lSum = haveSumOfDigits(lNumber);
        int rSum = haveSumOfDigits(rNumber);
        result += (lSum == rSum);
    }
    return result;
}

int isSlowSolve2() {
    int result = 0;
    const int digits = 10;
    for (int i = 0; i < digits; ++i)
    {
        for (int j = 0; j < digits; ++j)
        {
            for (int k = 0; k < digits; ++k)
            {
                for (int l = 0; l < digits; ++l)
                {
                    for (int r = 0; r < digits; ++r)
                    {
                        for (int q = 0; q < digits; ++q)
                        {
                            result += (i + j + k == l + r + q);
                        }
                    }
                }
            }
        }
    }
    return result;
}

int isFastSolve()
{
    int result = 0;
    const int maxSize = 27;
    const int digits = 10;
    int sum[maxSize];
    for (int i = 0; i <= maxSize; ++i)
    {
        sum[i] = 0;
    }
    for (int i = 0; i < digits; ++i)
    {
        for (int j = 0; j < digits; ++j)
        {
            for (int k = 0; k < digits; ++k)
            {
                ++sum[i + j + k];
            }
        }
    }
    for (int i = 0; i <= maxSize; ++i)
    {
        result += sum[i] * sum[i];
    }
    return result;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << " оличество счастливых билетов равно ";
    //cout << isSlowSolve1() << endl;
    //cout << isSlowSolve2() << endl;
    cout << isFastSolve() << endl;
    return 0;
}
