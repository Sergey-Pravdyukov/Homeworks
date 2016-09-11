#include <QtTest/QtTest>
#include <QtCore/QObject>

#include "testtree.h"

using namespace std;

int main()
{
    TestTree testTree;
    QTest::qExec(&testTree);
    return 0;
}

