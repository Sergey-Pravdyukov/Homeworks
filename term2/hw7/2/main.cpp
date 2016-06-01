#include <testvector.h>

int main()
{

  TestVector testVector;
  QTest::qExec(&testVector);

  return 0;
}

