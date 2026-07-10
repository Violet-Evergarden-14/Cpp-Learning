#include <iostream>
#include <vector>
using namespace std;

vector<int> dx = {0, 1};
vector<int> dy = {1, 0};

int find(int n, vector<vector<int>>& grid) {
	vector<int> dp(n + 1, 0);
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			dp[i] = grid[k][i] + max(dp[i - 1], dp[i]);
		}
	}
	return dp[n];
}

int find(int x0, int y0, int n, vector<vector<int>>& grid) {
	if (x0 == n && y0 == n) {
		return find(n, grid);
	}
	vector<int> poss(2, 0);
	int m = grid[x0][y0];
	for (int i = 0; i < 2; i++) {
		int x = x0 + dx[i];
		int y = y0 + dy[i];
		if (x > n || y > n) {
			poss[i] = 0;
			continue;
		}
		grid[x0][y0] = 0;
		poss[i] = find(x, y, n, grid);
		grid[x0][y0] = m;
	}
	return grid[x0][y0] + max(poss[0], poss[1]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
	int x, y, num;
	while (cin >> x >> y >> num) {
		if (x == 0 && y == 0 && num == 0) break;
		grid[x][y] = num;
	}
	cout << find(1, 1, n, grid);
}