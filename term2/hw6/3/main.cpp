#include <testsharedpointer.h>

using namespace std;

int main()
{
    for (int i = 0; i < 50; ++i)
    {
        TestSharedPointer testSharedPointer;
        QTest::qExec(&testSharedPointer);
    }
    return 0;
}
