#include "testbubblesort.h"

using namespace std;

int main()
{
    TestBubbleSort testBubbleSort;
    QTest::qExec(&testBubbleSort);
    return 0;
}
