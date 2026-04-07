#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, m;
	int id = 0;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++) {
			grid[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (grid[i][j] != 0) {
				id++;
				grid[i][j] = 0;
				queue<pair<int, int>> q;
				q.push({i, j});
				while (!q.empty()) {
					auto [x, y] = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 0) {
							grid[nx][ny] = 0;
							q.push({nx, ny});
						}
					}
				}
			}
		}
	}

	cout << id;
}