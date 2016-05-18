#include "mainwindow.h"
#include <QApplication>

#include <testparser.h>
#include <teststack.h>
#include <testsortingfacility.h>
#include <testtoken.h>

int main(int argc, char *argv[])
{
    TestParser testParser;
    QTest::qExec(&testParser);
    TestSortingFacility testSortingFacility;
    QTest::qExec(&testSortingFacility);
    TestStack testStack;
    QTest::qExec(&testStack);
    TestToken testToken;
    QTest::qExec(&testToken);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
