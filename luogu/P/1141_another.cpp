#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(n));
	vector<vector<int>> block_id(n, vector<int>(n, -1));
	vector<int> block_size;
	int id = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			grid[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (block_id[i][j] == -1) {
				queue<pair<int, int>> q;
				q.push({i, j});
				block_id[i][j] = id;
				int cnt = 1;

				while (!q.empty()) {
					auto [x, y] = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n && block_id[nx][ny] == -1 && grid[nx][ny] != grid[x][y]) {
							cnt++;
							block_id[nx][ny] = block_id[x][y];
							q.push({nx, ny});
						}
					}
				}

				block_size.push_back(cnt);
				id++;
			}
		}
	}

	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		cout << block_size[block_id[i - 1][j - 1]] << endl;
	}
}