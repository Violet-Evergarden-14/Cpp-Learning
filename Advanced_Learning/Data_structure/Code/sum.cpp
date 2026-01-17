#include <iostream>
using namespace std;

int sum1(int list[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += list[i];
	}
	
	return sum;
}

int sum2(int list[], int lo, int hi)
{
	if (lo == hi)
	{
		return list[lo];
	}

	int mid = (lo + hi) >> 1;
	return sum2(list, lo, mid) + sum2(list, mid + 1, hi);
}

int sum3(int list[], int lo, int hi)
{
	if (lo == hi)
	{
		return list[lo];
	}
	
	return list[lo] + sum3(list, lo + 1, hi);
}

int main()
{
	int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << sum2(list, 0, 8);
}