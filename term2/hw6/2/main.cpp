#include "arraylisttest.h"
#include "testuniquelist.h"

#include <cstdio>

using namespace std;

int main()
{
    ArrayListTest arrayListTest;
    QTest::qExec(&arrayListTest);

    TestUniqueList testUniqueList;
    QTest::qExec(&testUniqueList);

    return 0;
}
