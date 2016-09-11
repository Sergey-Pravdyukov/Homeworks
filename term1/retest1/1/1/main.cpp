#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void haveConsoleInput(int n, int a[])
{
    cout << "¬ведите массив: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
}

void haveRandomInput(int n, int a[])
{
    cout << "—генерированный массив: ";
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        a[i] = rand() % 32 + 11;
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "¬ведите размер массива: ";
    int n = 0;
    cin >> n;
    int a[n];
    haveConsoleInput(n, a);
    //haveRandomInput(n, a);
    for (int i = 1; i < n; i += 2)
    {
        for (int j = i - 2; j >= 0; j -= 2)
        {
            if (a[j] > a[j + 2])
            {
                swap(a[j], a[j + 2]);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}
