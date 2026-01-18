#include <iostream>
using namespace std;

void reverse(int list[], int lo, int hi)
{
	if (lo < hi)
	{
		swap(list[lo], list[hi]);
		reverse(list, lo + 1, hi - 1);
	}
}

void shift(int list[], int n, int k)
{
	k %= n;
	reverse(list, 0, n - 1);
	reverse(list, 0, n - k - 1);
	reverse(list, n - k, n - 1);
}

int main()
{
	int list[6] = {1, 2, 3, 4, 5, 6};
	shift(list, 6, 4);
	for (int i = 0; i < 6; i++)
	{
		cout << list[i] << endl;
	}
	
}