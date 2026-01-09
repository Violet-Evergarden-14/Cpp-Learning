#include <iostream>
using namespace std;

bool judge(int* list, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (list[i] == list[index])
		{
			return false;
		}
	}
	
	return true;
}

void pailie(int* list, int n, int count)
{
	if (count == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << list[i] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		list[count] = i + 1;
		if (judge(list, count))
		{
			pailie(list, n, count + 1);
		}
	}

	return;
}

int main()
{
	int list[4];
	pailie(list, 4, 0);
}