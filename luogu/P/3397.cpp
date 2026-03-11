#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int diff[n + 2][n + 2] = {0};
	for (int i = 1; i <= m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		diff[x1][y1]++;
		diff[x2 + 1][y2 + 1]++;
		diff[x1][y2 + 1]--;
		diff[x2 + 1][y1]--;
	}
	int res[n + 2][n + 2];
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			res[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			res[i][j] = diff[i][j] - res[i - 1][j - 1] + res[i][j - 1] + res[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
	
}