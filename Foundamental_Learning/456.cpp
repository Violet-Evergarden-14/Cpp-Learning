#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int a;
	int max;
	int min_max = 2100000000;
	int count_out = 0;
	int count_in;
	do
	{
		cin >> a;
		max = a;
		for (int i = 1; i < m; i++)
		{
			cin >> a;
			if (a > max)
			{
				max = a;
			}
		}
		
		
		if (max < min_max)
		{
			min_max = max;
		}
		count_out++;
		if (count_out >= n)
		{
			break;
		}
	} while (1);
	
	cout << min_max;
}