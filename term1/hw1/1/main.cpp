#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int x = 0;
    cout << "¬ведите x: ";
    cin >> x;
    long long x2 = x * x;
    long long result = (x2 + x) * (x2 + 1) + 1;
    cout << "x^4 + x^3 + x^2 + x + 1 = " << result << endl;
    return 0;
}
