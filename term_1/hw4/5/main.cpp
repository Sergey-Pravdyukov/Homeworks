#include <iostream>
#include "counting.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n = 0;
    int k = 0;
    cout << "������� ���������� ������: ";
    cin >> n;
    cout << "������� ������� �����, �������� ������ �����: ";
    cin >> k;
    cout << counting(n, k);
    return 0;
}
