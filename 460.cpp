#include <iostream>
using namespace std;

int sum_p(int* list, int m)
{
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += list[i];
	}
	
	return sum;
}

int sum_q(int* list, int m, int n)
{
	int sum = 0;
	for (int i = m; i < n; i++)
	{
		sum += list[i];
	}
	
	return sum;
}

int abs(int a, int b)
{
	if (a > b)
	{
		return a - b;
	}

	return b - a;
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
	
	int p = sum_p(list, 0), q = sum_q(list, 0, n);
	int p_result = p, q_result = q;
	int a = abs(p, q);
	int temp;
	int index;
	if (p >= q)
	{
		index = 1;
	} else {
		index = 0;
	}
	
	for (int i = 1; i <= n; i++)
	{
		p = sum_p(list, i);
		q = sum_q(list, i, n);
		temp = abs(p, q);
		if (temp < a || (temp == a && index == 0 && p >= q))
		{
			a = temp;
			p_result = p;
			q_result = q;
			if (p >= q)
			{
				index = 1;
			} else {
				index = 0;
			}
		}
	}

	cout << p_result << " " << q_result;
}