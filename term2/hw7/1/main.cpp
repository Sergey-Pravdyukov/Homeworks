#include "testavltree.h"

using namespace std;

int main()
{
    for (int i = 0; i < 100; ++i)
    {
        TestAVLTree testAVLTree;
        QTest::qExec(&testAVLTree);
    }
    return 0;
}
