#include <iostream>
#include <vector>
using namespace std;

int count(vector<vector<bool>>& list, int x, int y, int ex, int ey) {
	if (x == ex && y == ey) return 1;
	int res = 0;
	list[x][y] = false;
	for (int ix = -1; ix <= 1; ix += 2) {
		if (list[x + ix][y] == true) {
			res += count(list, x + ix, y, ex, ey);
		}
	}
	for (int iy = -1; iy <= 1; iy += 2) {
		if (list[x][y + iy] == true) {
			res += count(list, x, y + iy, ex, ey);
		}
	}
	list[x][y] = true;
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

	int n, m, t;
	cin >> n >> m >> t;
	vector<vector<bool>> list(n + 2, vector<bool>(m + 2, false));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			list[i][j] = true;
		}
	}
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		list[a][b] = false;
	}
	cout << count(list, sx, sy, ex, ey);
}