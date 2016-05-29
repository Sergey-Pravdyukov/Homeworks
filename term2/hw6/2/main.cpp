#include "arraylisttest.h"
#include "testuniquelist.h"

#include <cstdio>

using namespace std;

int main()
{
    cout << "Please press Enter =)";
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 50; ++i)
    {
    ArrayListTest arrayListTest;
    QTest::qExec(&arrayListTest);

    TestUniqueList testUniqueList;
    QTest::qExec(&testUniqueList);
    }
    fclose(stdout);
    return 0;
}
