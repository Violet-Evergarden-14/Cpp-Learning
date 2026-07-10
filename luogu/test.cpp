#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<int>>> cube = vector<vector<vector<int>>>(6, vector<vector<int>>(8, vector<int>(10, 0)));
vector<vector<vector<int>>> vis = vector<vector<vector<int>>>(6, vector<vector<int>>(8, vector<int>(10, 0)));

vector<int> dx = {1, 2, 3, 0, 0, 0, 0, 0, 0};
vector<int> dy = {0, 0, 0, 1, 2, 3, 0, 0, 0};
vector<int> dz = {0, 0, 0, 0, 0, 0, 1, 2, 3};

void find(int x, int y, int z) {
	vis[x][y][z] = 1;
	for (int i = 0; i < 9; i++) {
		int x1 = x - dx[i];
		int y1 = y - dy[i];
		int z1 = z - dz[i];
		if (x1 >= 0 && y1 >= 0 && z1 >= 0) {
			if (vis[x1][y1][z1] == 0) find(x1, y1, z1);
			if (cube[x1][y1][z1] == 0) {
				cube[x][y][z] = 1;
				return;
			}
		}
	}
}

int main()
{
	vis[0][0][0] = 1;
	find(5, 7, 9);
	cout << cube[5][7][9];
}