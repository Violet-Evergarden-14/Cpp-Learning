#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool dfs(int i, int j, int num, vector<vector<int>>& grid, vector<vector<int>>& vis) {
	if ()
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int right = 1000;
	vector<vector<int>> grid(n, vector<int>(m));
	vector<vector<int>> vis(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			right = min(right, grid[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		if (dfs(0, i, 0, grid, vis) == true) {
			cout << 0;
			return 0;
		}
	}
	int left = 0;
	while (right - left >= 2) {
		int mid = (left + right) / 2;
		bool judge = false;
		for (int i = 0; i < m; i++) {
			if (dfs(0, i, mid, grid, vis) == true) {
				judge = true;
				break;
			}
		}
		if (judge == true) right = mid;
		else left = mid;
	}
	cout << right;
}