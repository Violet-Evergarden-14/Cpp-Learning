#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int n;

void diffusion(vector<vector<int>>& table, vector<vector<int>>& table_count, int x, int y) {
	queue<int> qx;
	queue<int> qy;
	qx.push(x);
	qy.push(y);
	while (!qx.empty()) {
		int xn = qx.front();
		int yn = qy.front();
		qx.pop();
		qy.pop();
		for (int i = 0; i < 4; i++) {
			int xt = xn + dx[i];
			int yt = yn + dy[i];
			if (xt < 0 || xt >= n || yt < 0 || yt >= n) continue;
			if (table_count[xt][yt] == 0 && table[xn][yn] + table[xt][yt] == 1) {
				table_count[xt][yt] = table_count[xn][yn];
				qx.push(xt);
				qy.push(yt);
			}
		}
	}
}

int count(vector<vector<int>>& table, vector<vector<int>>& visited, vector<vector<int>>& table_count, int x, int y) {
	if (table_count[x][y] != 0) return table_count[x][y];
	int res = 1;
	queue<int> qx;
	queue<int> qy;
	qx.push(x);
	qy.push(y);
	while (!qx.empty()) {
		int xn = qx.front();
		int yn = qy.front();
		qx.pop();
		qy.pop();
		visited[xn][yn] = 1;
		for (int i = 0; i < 4; i++) {
			int xt = xn + dx[i];
			int yt = yn + dy[i];
			if (xt < 0 || xt >= n || yt < 0 || yt >= n) continue;
			if (table_count[xt][yt] != 0 && table[xn][yn] + table[xt][yt] == 1) {
				table_count[xn][yn] = table_count[xt][yt];
				return table_count[xt][yt];
			}
			if (visited[xt][yt] == 0 && table[xn][yn] + table[xt][yt] == 1) {
				qx.push(xt);
				qy.push(yt);
				visited[xt][yt] = 1;
				res++;
			}
		}
	}
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int m;
	cin >> n >> m;
	vector<vector<int>> table(n, vector<int>(n));
	vector<vector<int>> visited(n, vector<int>(n, 0));
	vector<vector<int>> table_count(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < n; j++) {
			table[i][j] = a[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			table_count[i][j] = count(table, visited, table_count, i, j);
			diffusion(table, table_count, i, j);
		}
	}
	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		cout << table_count[i - 1][j - 1] << endl;
	}
}