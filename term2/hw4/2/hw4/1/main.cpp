#include "testhashtable.h"

using namespace std;

int main()
{
    TestHashTable testHashTable;
    QTest::qExec(&testHashTable);
    return 0;
}
