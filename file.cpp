#include <iostream>
using namespace std;

void paixu(int list[], int start, int end, int x);
void swap(int* a, int* b);
int fan_swap(int list[], int start, int end, int x);
int zheng_swap(int list[], int start, int end, int x);

int main()
{
	int n;
	cin >> n;

	int list[n];
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	paixu(list, 0, n - 1, 0);
	
	for (int i = 0; i < n; i++)
	{
		cout << list[i] << endl;
	}
	
}

void paixu(int list[], int start, int end, int x)
{
	if (end - start <= 0) return;

	if (end - start == 1) {
		if (list[start] > list[end]) swap(&list[start], &list[end]);
		return;
	}

	int a = start;
	int b = end;
	int m = x;
	while (b >= a)
	{
		b = fan_swap(list, a, b, m);
		m = b;
		a = zheng_swap(list, a, b, m);
		m = a;
	}
	
	paixu(list, start, m - 1, start);
	paixu(list, m + 1, end, m + 1);

	return;
}

void swap(int *a, int *b)
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  


int fan_swap(int list[], int start, int end, int x)
{
	for (int i = end; i >= start; i--)
	{
		if (list[i] < list[x])
		{
			swap(&list[i], &list[x]);
			return i;
		}
	}

	return start - 1;
}

int zheng_swap(int list[], int start, int end, int x)
{
	for (int i = start; i <= end; i++)
	{
		if (list[i] > list[x])
		{
			swap(&list[i], &list[x]);
			return i;
		}
	}
	
	return end + 1;
}