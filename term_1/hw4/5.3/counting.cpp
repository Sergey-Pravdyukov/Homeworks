#include "counting.h"
#include "list.h"
#include <cstddef>

int haveCounting(int n, int k)
{
	List currentList;
	currentList.head = currentList.tail = nullptr;
	currentList.size = 0;
	for (int i = 1; i <= n; ++i)
    {
        add(&currentList, i);
    }
    remove(&currentList, k);
    return topOfList(&currentList);
}
