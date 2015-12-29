#include "qsort.h"

struct Data {
	String* word;
	int quantity;
};

void qsortWords(Data* a, int primordialLeft, int primordialRight)
{
	int left = primordialLeft;
	int right = primordialRight;
	String* median = a[(left + right) / 2].word;
	while (left < right)
	{
		while (compareString(a[left].word, median) == smaller && left <= right)
			left++;
		while (compareString(a[right].word, median) == bigger && right >= left)
			right--;
		if (left <= right)
		{
			swap(a[left], a[right]);
			left++;
			right--;
		}
	}
	if (right > primordialLeft)
		qsortWords(a, primordialLeft, right);
	if (left < primordialRight)
		qsortWords(a, left, primordialRight);
}

