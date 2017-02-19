#include "list.h"

int counting(int n, int k)
{
    List currentList = {nullptr, nullptr, 0};
    for (int i = 1; i <= n; ++i)
    {
        add(&currentList, i);
    }
    remove(&currentList, k);
    return topOfList(&currentList);
}
