#include <iostream>
using namespace std;

void bubble_sort(int list[], int n)
{
	bool sorted = true;
	for (int i = 0; i < n; i++)
	{
		if (list[i] > list[i + 1])
		{
			sorted = false;
			swap(list[i], list[i + 1]);
		}
	}

	if (sorted == false)
	{
		bubble_sort(list, n - 1);
	}

/* another way:
	bool sorted = true;
	while (!sorted)
	{
		for (int i = 0; i < n; i++)
		{
			if (list[i] > list[i + 1])
			{
				sorted = false;
				swap(list[i], list[i + 1]);
			}
		}
		n--;
	}
*/
}

int main()
{
	int list[5] = {1, 18, 5, 98, -1};
	bubble_sort(list, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << list[i] << endl;
	}
	
}