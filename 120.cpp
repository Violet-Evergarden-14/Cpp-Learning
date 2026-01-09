#include <iostream>
using namespace std;

int paixu(int list[], int n, int m);
void swap(int list[], int i, int j, int n);

int main()
{
	int n;
	cin >> n;

	int list[n];

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	int a = paixu(list, n, 0);
	cout << "Total steps:" << a << endl;
	cout << "Right order:";
	for (int i = 0; i < n; i++)
	{
		cout << list[i] << " ";
	}
}

void swap(int list[], int i, int j, int n)
{
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;

	cout << i + 1 << "<->" << j + 1 << ":";
	for (int m = 0; m < n; m++)
	{
		cout << list[m] << " ";
	}
	cout << endl;
}

int paixu(int list[], int n, int m)
{
	int count = 0;
	if (m == n - 1)
	{
		return 0;
	}
	
	int min = list[m];
	int index_min = m;
	for (int i = m; i < n; i++)
	{
		if (list[i] < min)
		{
			index_min = i;
			min = list[i];
		}
	}

	if (index_min != m)
	{
		swap(list, m, index_min, n);
		return 1 + paixu(list, n, m + 1);
	} else {
		return paixu(list, n, m + 1);    //这里使用return会导致函数提前结束，而不进行paixu操作
	}
	
	
}



//从最后一个往开头来，完全就是有病
/*
#include <iostream>
using namespace std;

int paixu(int list[], int n, int m, int shunxu[100][2], int count);
void swap(int list[], int i, int j, int n);

int main()
{
	int n;
	cin >> n;

	int list[n];
	int shunxu[100][2] = {0};

	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	int a = paixu(list, n, 0, shunxu, 0);

	int right[n];
	for (int i = 0; i < n; i++)
	{
		right[i] = list[i];
	}
	
	
	for (int i = 99; i >= 0; i--)
	{
		if (shunxu[i][0] || shunxu[i][1])
		{
			cout << shunxu[i][0] + 1 << "<->" << shunxu[i][1] + 1 << ":";
			for (int m = 0; m < n; m++)
			{
				cout << list[m] << " ";
			}
			cout << endl;
			
			swap(list, shunxu[i][0], shunxu[i][1], n);
		}
	}

	cout << "Total steps:" << a << endl;
	cout << "Right order:";
	for (int i = 0; i < n; i++)
	{
		cout << right[i] << " ";
	}
}

void swap(int list[], int i, int j, int n)
{
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

int paixu(int list[], int n, int m, int shunxu[100][2], int count)
{
	if (m == n - 1)
	{
		return 0;
	}
	
	int min = list[m];
	int index_min = m;
	for (int i = m; i < n; i++)
	{
		if (list[i] < min)
		{
			index_min = i;
			min = list[i];
		}
	}

	if (index_min != m)
	{
		swap(list, m, index_min, n);
		shunxu[count][0] = m;
		shunxu[count][1] = index_min;
		return 1 + paixu(list, n, m + 1, shunxu, count + 1);
	} else {
		return paixu(list, n, m + 1, shunxu, count + 1);
	}
	
}
*/