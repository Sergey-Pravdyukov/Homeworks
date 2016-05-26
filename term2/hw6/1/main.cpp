#include <iostream>
#include <string>

using namespace std;

class MyError
{
public:
    MyError(const char *msg = 0):mData(msg) {}

private:
    const char *mData;
};

class A
{
public:
    ~A()
    {
        cout << "Destructor for class A" << endl;
    }
};

class B : public A
{
public:
    ~B()
    {
        cout << "Destructor for class B" << endl;
    }
};

void f()
{
    B b;
    throw MyError();
}

int main()
{
    try
    {
        f();
    }
    catch (MyError)
    {
        cout << "Catch exception!!!" << endl;
    }
    return 0;
}
