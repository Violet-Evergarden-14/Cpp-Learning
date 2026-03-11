#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> ori(5003, vector<int>(5003, 0));
	for (int i = 0; i < n; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		ori[x + 1][y + 1] += v;
	}
	vector<vector<int>> res(5002, vector<int>(5002, 0));
	for (int x = 1; x <= 5001; x++) {
		for (int y = 1; y <= 5001; y++) {
			res[x][y] = res[x][y - 1] + res[x - 1][y] - res[x - 1][y - 1] + ori[x][y];
		}
	}
	
	int max = res[m][m];
	for (int x = m; x <= 5001; x++) {
		for (int y = m; y <= 5001; y++) {
			int another = res[x][y] - res[x - m][y] - res[x][y - m] + res[x - m][y - m];
			if (another > max) max = another;
		}
	}
	cout << max;
}