
#include "counting.h"
#include "list.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n = 0;
    int k = 0;
    cout << "������� ���������� ������: ";
    cin >> n;
    cout << "������� ������� �����, �������� ������ �����: ";
    cin >> k;
    List currentList = {nullptr, nullptr, 0};
	cout << haveCounting(n, k) << "-� ���� �������." << endl;
    return 0;
}
