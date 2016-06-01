#include "testavltree.h"
#include "testbag.h"

using namespace std;

int main()
{

    TestAVLTree testAVLTree;
    QTest::qExec(&testAVLTree);

    TestBag testBag;
    QTest::qExec(&testBag);

    return 0;
}
