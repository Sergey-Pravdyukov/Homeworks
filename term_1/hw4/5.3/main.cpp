
#include "counting.h"
#include "list.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n = 0;
    int k = 0;
    cout << "¬ведите количество воинов: ";
    cin >> n;
    cout << "¬ведите пор€док воина, которого должны убить: ";
    cin >> k;
    List currentList = {nullptr, nullptr, 0};
	cout << haveCounting(n, k) << "-й воин выживет." << endl;
    return 0;
}
