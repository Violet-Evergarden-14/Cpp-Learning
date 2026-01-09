#include <iostream>
using namespace std;

void sort_list(int* list, int n);

int main()
{
	int n, m;
	cin >> n >> m;
	int t = n;

	int list[n];
	for (int i = 0; i < n; i++)
	{
		list[i] = i + 1;
	}
	
	int a;
	int former = 0;
	for (int i = 0; i < t - 1; i++)
	{
		a = (m + former) % n;
		if (a)
		{
			former = a - 1;
			list[a - 1] = 0;
			sort_list(list, n);
		} else {
			former = 0;
			list[n - 1] = 0;
		}
		n--;
	}
	
	cout << *list;
}

void sort_list(int* list, int n)
{
	int index;
	for (int i = 0; i < n; i++)
	{
		if (*(list + i) == 0)
		{
			index = 0;
			for (int j = i + 1; j < n; j++)
			{
				if (*(list + j))
				{
					*(list + i) = *(list + j);
					*(list + j) = 0;
					index = 1;
					break;
				}
			}
			
			if (index == 0)
			{
				break;
			}
		}
	}
}