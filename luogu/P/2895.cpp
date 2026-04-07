#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {0, -1, 0, 1, 0};
int dy[] = {-1, 0, 1, 0, 0};

class Position {
public:
	int x, y, t;
};

bool check(vector<vector<int>>& farm, int x, int y, int t) {
	for (int k = 0; k < 5; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx <= 300 && ny >= 0 && ny <= 300 && farm[nx][ny] != -1 && farm[nx][ny] <= t) return false;
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int m;
	cin >> m;
	vector<vector<int>> farm(301, vector<int>(301, -1));
	vector<vector<int>> visited(301, vector<int>(301, 0));
	for (int i = 0; i < m; i++) {
		int t, x, y;
		cin >> x >> y >> t;
		if (farm[x][y] == -1) farm[x][y] = t;
		else if (farm[x][y] > t) farm[x][y] = t;
	}

	queue<Position> q;
	q.push({0, 0, 0});
	visited[0][0] = 1;
	while (!q.empty()) {
		auto [x, y, t] = q.front();
		q.pop();
		if (check(farm, x, y, 1001) == true) {
			cout << t;
			return 0;
		} else {
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx <= 300 && ny >= 0 && ny <= 300 && visited[nx][ny] == 0 && check(farm, nx, ny, t + 1) == true) {
					q.push({nx, ny, t + 1});
					visited[nx][ny] = 1;
				}
				if (nx > 300 && ny >= 0) {cout << t + 1; return 0;}
				if (ny > 300 && nx >= 0) {cout << t + 1; return 0;}
			}
		}
	}
	cout << -1;
}