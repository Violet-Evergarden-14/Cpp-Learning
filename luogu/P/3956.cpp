#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

vector<vector<int>> gold;

class Dot {
public:
	int x, y;

	friend bool operator<(const Dot& a , const Dot& b) {
		if (gold[a.x][a.y] > gold[b.x][b.y]) return true;
		return false;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, m;
	cin >> m >> n;
	vector<vector<int>> color(m, vector<int>(m, -1));
	vector<vector<int>> color_dye(m, vector<int>(m, -1));
	gold = vector<vector<int>>(m, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		color[x - 1][y - 1] = c;
		color_dye[x - 1][y - 1] = c;
	}

	priority_queue<Dot> q;
	gold[0][0] = 0;
	q.push({0, 0});
	while (!q.empty()) {
		auto [x, y] = q.top();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int g = gold[x][y];
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= m || ny < 0 || ny >= m) continue;
			if (color[nx][ny] == -1) {
				if (color[x][y] == -1) continue;
				g += 2;
			} else if (color[nx][ny] != color_dye[x][y]) g++;
			if (gold[nx][ny] == -1) {
				q.push({nx, ny});
				gold[nx][ny] = g;
				if (color[nx][ny] == -1) color_dye[nx][ny] = color[x][y];
				continue;
			}
			if (g < gold[nx][ny]) {
				q.push({nx, ny});
				if (color[nx][ny] == -1) color_dye[nx][ny] = color[x][y];
				gold[nx][ny] = g;
			}
		}
	}
	cout << gold[m - 1][m - 1];
}