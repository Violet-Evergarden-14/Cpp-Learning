#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef int matrix[3][3];

struct Matrix {
	int data[3][3];
	Matrix(matrix m) {
		for (int j = 0; j < 9; j++) {
			data[j / 3][j % 3] = m[j / 3][j % 3];
		}
	}
	bool operator==(const Matrix& a) const {
		for (int i = 0; i < 9; i++) {
			if (a.data[i / 3][i % 3] != data[i / 3][i % 3]) return false;
		}
		return true;
	}
	bool operator<(const Matrix& a) const {
		for (int i = 0; i < 9; i++) {
			if (a.data[i / 3][i % 3] > data[i / 3][i % 3]) return false;
			if (a.data[i / 3][i % 3] < data[i / 3][i % 3]) return true;
		}
		return false;
	}
	bool operator>(const Matrix& a) const {
		if ((*this == a) || (*this < a)) return false;
		return true;
	}
};

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

matrix attr = {{3, 2, 4}, {1, 0, 5}, {8, 7, 6}};
set<Matrix> s;

bool dfs(int i, int j, int cnt) {
	if (cnt < 0) return false;
	if (i == 1 && j == 1) {
		if (attr[0][0] == 1 && attr[0][1] == 2 && attr[0][2] == 3 && attr[1][0] == 8 && 
			attr[1][2] == 4 && attr[2][0] == 7 && attr[2][1] == 6 && attr[2][2] == 5) {
				return true;
		}
	}
	for (int t = 0; t < 4; t++) {
		int x = i + dx[t];
		int y = j + dy[t];
		if (x < 0 || y < 0 || x > 2 || y > 2) continue;
		swap(attr[i][j], attr[x][y]);
		if (s.count(Matrix(attr)) != 0) {
			swap(attr[i][j], attr[x][y]);
			continue;
		} else {
			s.insert(Matrix(attr));
			if (dfs(x, y, cnt - 1) == true) return true;
			else {
				s.erase(Matrix(attr));
				swap(attr[i][j], attr[x][y]);
				continue;
			}
		}
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int res;
	for (int i = 0; i < 9; i++) {
		char a; cin >> a;
		attr[i / 3][i % 3] = a - '0';
		if (a == '0') res = i;
	}
	s.insert(Matrix(attr));
	int cnt = 0;
	while (dfs(res / 3, res % 3, cnt) == false) {
		cnt++;
	}
	cout << cnt;
}