#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    const int maxSize = 1e3;
    long long fibonacci[maxSize];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    fibonacci[1] = 1;
    for (int i = 2; i < 93; ++i)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    cout << "Введите индекс: ";
    int n = 0;
    cin >> n;
    cout << n << "-е число Фибоначчи: " << fibonacci[n] << endl;
    return 0;
}
