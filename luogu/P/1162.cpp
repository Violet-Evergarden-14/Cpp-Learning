#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n;

class Dot {
public:
	int x, y;
};

void dye(vector<vector<int>>& board, int x, int y, int numb) {
	board[x][y] = numb;
	queue<Dot> q;
	q.push((Dot){x, y});
	while (!q.empty()) {
		Dot now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = now.x + dx[i];
			int ty = now.y + dy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
			if (board[tx][ty] != 1 && board[tx][ty] != numb) {
				board[tx][ty] = numb;
				q.push((Dot){tx, ty});
			}
		}
	}
}

bool judge(vector<vector<int>>& board, int x, int y) {
	if (board[x][y] != 0) return false;
	board[x][y] = -1;
	queue<Dot> q;
	q.push((Dot){x, y});
	while (!q.empty()) {
		Dot now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = now.x + dx[i];
			int ty = now.y + dy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= n) return false;
			if (board[tx][ty] == 0) {
				board[tx][ty] = -1;
				q.push((Dot){tx, ty});
			}
		}
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	cin >> n;
	vector<vector<int>> board(n, vector<int>(n, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i - 1][j - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (judge(board, i, j) == true) {
				dye(board, i, j, 2);
			} else if (board[i][j] == -1) {
				dye(board, i, j, -1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == -1) {
				board[i][j] = 0;
			}
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}