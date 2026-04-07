#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;

bool judge(vector<string>& list, int x, int y, int dx, int dy) {
	string ori = "yizhong";
	for (int i = 0; i < 7; i++) {
		int nx = x + i * dx;
		int ny = y + i * dy;
		if (nx >= n || nx < 0 || ny >= n || ny < 0 || list[nx][ny] != ori[i]) return false;
	}
	return true;
}

void change_mask(vector<vector<int>>& mask, int x, int y, int dx, int dy) {
	for (int i = 0; i < 7; i++) {
		mask[x + i * dx][y + i * dy] = 1;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	cin >> n;
	vector<string> list(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}
	vector<vector<int>> mask(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (judge(list, i, j, 0, 1) == true) change_mask(mask, i, j, 0, 1);
			if (judge(list, i, n - 1 - j, 0, -1) == true) change_mask(mask, i, n - 1 - j, 0, -1);
			if (judge(list, j, i, 1, 0) == true) change_mask(mask, j, i, 1, 0);
			if (judge(list, n - 1 - j, i, -1, 0) == true) change_mask(mask, n - 1 - j, i, -1, 0);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (judge(list, i, j, 1, 1) == true) change_mask(mask, i, j, 1, 1);
			if (judge(list, i, n - 1 - j, 1, -1) == true) change_mask(mask, i, n - 1 - j, 1, -1);
			if (judge(list, n - 1 - i, j, -1, 1) == true) change_mask(mask, n - 1 - i, j, -1, 1);
			if (judge(list, n - 1 - i, n - 1 - j, -1, -1) == true) change_mask(mask, n - 1 - i, n - 1 - j, -1, -1);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mask[i][j] == 0) cout << '*';
			else cout << list[i][j];
		}
		cout << endl;
	}
}