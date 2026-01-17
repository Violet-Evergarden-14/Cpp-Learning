#include <iostream>
using namespace std;

void reverse(int list[], int lo, int hi)
{
	if (lo < hi)
	{
		swap(list[lo], list[hi]);
		reverse(list, lo + 1, hi + 1);
	}
}

void reverse_another(int list[], int lo, int hi)
{
next:
	if (lo < hi)
	{
		swap(list[lo], list[hi]);
		lo++;
		hi--;
		goto next;
	}
}

void reverse__another(int list[], int lo, int hi)
{
	while (lo < hi)
	{
		swap(list[lo++], list[hi++]);
	}
}