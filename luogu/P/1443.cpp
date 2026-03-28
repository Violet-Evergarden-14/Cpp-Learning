#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Dot {
public:
	int x = 0, y = 0;
	int step = -1;

	bool operator==(Dot& s) {
		if (this->x == s.x && this->y == s.y) return true;
		return false;
	}
};



int main()
{
	int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
	int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
	int n, m, x, y;
	vector<vector<Dot>> board(401, vector<Dot>(401));
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	cin >> n >> m >> x >> y;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			board[i][j].x = i;
			board[i][j].y = j;
		}
	}
	board[x][y].step = 0;

	queue<Dot> q;
	q.push((Dot){x, y, 0});
	while (!q.empty()) {
		Dot now = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int tx = now.x + dx[i];
			int ty = now.y + dy[i];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && board[tx][ty].step == -1) {
				board[tx][ty].step = now.step + 1;
				q.push((Dot){tx, ty, now.step + 1});
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << board[i][j].step << " ";
		}
		cout << endl;
	}
}