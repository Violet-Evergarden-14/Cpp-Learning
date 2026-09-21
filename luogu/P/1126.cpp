#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int sx, sy;
int ex, ey;
int d[4] = {0,2,1,3};

inline int get_turn_time(int a, int b) {
	if (a == b) return 0;
	if (abs(a - b) == 2) return 2;
	return 1;
}

class Pos {
public:
	int x, y;
	int dire;
	int t;

	Pos(int _x, int _y, int _dire, int _t): x(_x), y(_y), dire(_dire), t(_t) {}
	bool operator<(const Pos& s) const {return t > s.t;}
};

int main() {
	priority_queue<Pos> pq;
	int n, m; cin >> n >> m;
	vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				grid[i - 1][j] = 1;
				grid[i - 1][j - 1] = 1;
				grid[i][j - 1] = 1;
			}
		}
	}
	char a;
	cin >> sx >> sy >> ex >> ey >> a;
	int dire;
	switch (a) {
		case 'E': dire = 0; break;
		case 'S': dire = 1; break;
		case 'W': dire = 2; break;
		case 'N': dire = 3; break;
		default: break;
	}
	Pos start(sx, sy, dire, 0);
	pq.push(start);
	while (!pq.empty()) {
		Pos cur = pq.top();
		pq.pop();
		vis[cur.x][cur.y] = 1;
		if (cur.x == ex && cur.y == ey) {
			cout << cur.t;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= 3; j++) {
				int nx = cur.x + dx[i] * j;
				int ny = cur.y + dy[i] * j;
				if (nx <= 0 || nx >= n || ny <= 0 || ny >= m || grid[nx][ny] == 1) break;
				if (vis[nx][ny] == 1) continue;
				int ndire = d[i];
				int nt = cur.t + 1 + get_turn_time(ndire, cur.dire);
				pq.push(Pos(nx, ny, ndire, nt));
			}
		}
	}
	cout << -1;
}