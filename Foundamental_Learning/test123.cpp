#include <iostream>
using namespace std;

void q(int list[], int n, int count);

int main()
{
	int n;
	cin >> n;

	int list[n];
	q(list, n, 0);

}

void q(int list[], int n, int count)
{
	if (count == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << list[i] + 1 << " ";
		}
		cout << endl;
		return;
	}
	

	for (int i = 0; i < n; i++)
	{
		list[count] = i;
		q(list, n, count + 1);
	}
	
	return;
}