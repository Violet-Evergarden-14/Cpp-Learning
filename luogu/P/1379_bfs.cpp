#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

typedef int matrix[3][3];

class Matrix {
public:
	int data[3][3];
	int depth;
	int i, j;
	Matrix(matrix m, int _depth): depth(_depth) {
		for (int _j = 0; _j < 9; _j++) {
			data[_j / 3][_j % 3] = m[_j / 3][_j % 3];
			if (data[_j / 3][_j % 3] == 0) {i = _j / 3; j = _j % 3;}
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
queue<Matrix> q;
set<Matrix> s;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int res;
	for (int i = 0; i < 9; i++) {
		char a; cin >> a;
		attr[i / 3][i % 3] = a - '0';
		if (a == '0') res = i;
	}
	q.push(Matrix(attr, 0));
	s.insert(Matrix(attr, 0));
	while (!q.empty()) {
		Matrix temp = q.front();
		q.pop();
		if (temp.data[0][0] == 1 && temp.data[0][1] == 2 && temp.data[0][2] == 3 && temp.data[1][0] == 8 && 
			temp.data[1][2] == 4 && temp.data[2][0] == 7 && temp.data[2][1] == 6 && temp.data[2][2] == 5 && temp.data[1][1] == 0) {
				cout << temp.depth;
				break;
			}
		for (int t = 0; t < 4; t++) {
			int x = temp.i + dx[t];
			int y = temp.j + dy[t];
			if (x < 0 || y < 0 || x > 2 || y > 2) continue;
			Matrix temp2 = temp;
			temp2.depth++;
			temp2.data[temp2.i][temp2.j] = temp2.data[x][y];
			temp2.data[x][y] = 0;
			temp2.i = x;
			temp2.j = y;
			if (s.count(temp2) != 0) continue;
			q.push(temp2);
			s.insert(temp2);
		}
	}
}