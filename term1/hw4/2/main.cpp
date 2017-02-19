#include <iostream>

using namespace std;

bool check(int currentX, int currentY, int n)
{
    return (0 <= currentX && currentX < n && 0 <= currentY && currentY < n);
}

void output(int &step, int &index, int &currentX, int &currentY, int a[][100], int x[], int y[], int n)
{
    for (int i = 0; i < step; ++i)
    {
        currentX += x[index];
        currentY += y[index];
        if (check(currentX, currentY, n))
        {
            cout << a[currentX][currentY] << " ";
        }
        else
        {
            return;
        }
    }
    step += (index % 2);
    index = (index + 1) % 4;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "¬ведите размер измерений массива: ";
    int n = 0;
    cin >> n;
    const int maxSize = int(1e2);
    int a[maxSize][maxSize];
    cout << "¬ведите элементы массива: " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    int currentX = n / 2;
    int currentY = n / 2;
    int step = 1;
    int index = 0;
    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};
    cout << a[currentX][currentY] << " ";
    while (check(currentX, currentY, n))
    {
        output(step, index, currentX, currentY, a, x, y, n);
    }
    return 0;
}
/*
1  2  3  4  5
6  7  8  9  10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
*/
