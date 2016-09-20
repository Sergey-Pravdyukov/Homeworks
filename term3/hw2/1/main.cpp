#include <iostream>
#include <ctime>

using namespace std;

enum OS : double
{
    a = 0.9,
    b = 0.4,
    c = 0.2
};

int main()
{
    time(NULL);
    int type = rand() % 3;
    OS a = OS::Windows;
    cout << a.getValue() << " " << a.InternalName() << endl;
    return 0;
}
