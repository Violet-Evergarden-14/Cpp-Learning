#include <iostream>
using namespace std;

bool find_sum(int list[], int n, int m ,int sum)
{
	if (sum == list[m])
	{
		return true;
	} else if (m == n - 1)
	{
		return false;
	} else if(find_sum(list, n, m + 1, sum) || find_sum(list, n, m + 1, sum - list[m]))
	{
		return true;
	} else {
		return false;
	}
}

int main()
{
	int list[5] = {1, 3, 2, 4, 89};
	cout << find_sum(list, 5, 0, 11);
}