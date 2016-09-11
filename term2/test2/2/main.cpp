#include "testavltree.h"
#include "testiterator.h"

using namespace std;

int main()
{
    TestAVLTree testAVLTree;
    QTest::qExec(&testAVLTree);

    TestIterator testIterator;
    QTest::qExec(&testIterator);
    return 0;
}
