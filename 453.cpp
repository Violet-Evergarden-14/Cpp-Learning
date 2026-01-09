#include <iostream>
using namespace std;

void exchange(int* list, int a, int b)
{
	int temp = list[a];
	list[a] = list[b];
	list[b] = temp;
}

int merge_sort(int* list, int start, int end, int sort_index)
{
	if (start >= end)
	{
		return sort_index;
	}
	
	int a;
	int s = 0;
	if (sort_index == start)
	{
		int index = list[start];
		for (int i = end; i > start; i--)
		{
			if (list[i] < index)
			{
				s = 1;
				exchange(list, start, i);
				a = merge_sort(list, start, i, i);
				break;
			}
		}

		if (s == 0)
		{
			a = merge_sort(list, start + 1, end, start + 1);
		}
		
	} else {
		int index = list[end];
		for (int i = start; i < end; i++)
		{
			if (list[i] > index)
			{
				s = 1;
				exchange(list, end, i);
				a = merge_sort(list, i, end, i);
				break;
			}
		}

		if (s == 0)
		{
			a = merge_sort(list, start, end - 1, start);
		}
		
	}

	merge_sort(list, start, a - 1, start);
	merge_sort(list, a + 1, end, a + 1);

	return a;
}



int main()
{
	int n;
	cin >> n;

	int list[n];
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	
	merge_sort(list, 0, n - 1, 0);

	for (int i = 0; i < n; i++)
	{
		cout << list[i] << " ";
	}
}