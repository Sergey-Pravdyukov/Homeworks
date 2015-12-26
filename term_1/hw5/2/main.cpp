#include <iostream>
#include <iomanip>

using namespace std;

void haveSignOfNumber(long double &x)
{
    if (x > 0.0)
    {
        cout << "+";
    }
    else
    {
        x = -x;
        cout << "-";
    }
}

void havePositivePowerOfNumber(long double &x, int &power)
{
    long double radix = 2.0;
    while (x >= radix)
    {
        x /= radix;
        ++power;
    }
}

void haveNegativePowerOfNumber(long double &x, int &power)
{
    long double radix = 2.0;
    while (x * radix <= radix)
    {
        x *= radix;
        --power;
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << fixed << setprecision(16);
    cout << "Представление числа в экспоненциальной форме" << endl;
    cout << "Enter a number: ";
    long double x = 0.0;
    cin >> x;
    cout << "Result: ";
    if (x == 0.0)
    {
        cout << "+0.0000000000000000*2^(1)";
        return 0;
    }
    haveSignOfNumber(x);
    int power = 0;
    (x >= 1.0) ? havePositivePowerOfNumber(x, power) : haveNegativePowerOfNumber(x, power);
    cout << x << "*2^(" << power << ")" << endl;
    return 0;
}
