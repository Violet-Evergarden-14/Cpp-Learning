#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;


	int sum = 0;
	int matrix[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
			{
				sum += matrix[i][j];
			}
		}
	}
	
	cout << sum;
}