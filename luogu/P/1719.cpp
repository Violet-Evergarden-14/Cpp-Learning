#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
	
	int n;
	cin >> n;
	vector<vector<int>> ori(n + 2, vector<int>(n + 2, 0));
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			cin >> ori[x][y];
		}
	}
	vector<vector<int>> res(n + 1, vector<int>(n + 1, 0));
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			res[x][y] = res[x][y - 1] + res[x - 1][y] - res[x - 1][y - 1] + ori[x][y];
		}
	}

	int max = res[1][1];
	int temp;
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= n; y1++) {
			for (int x2 = x1; x2 <= n; x2++) {
				for (int y2 = y1; y2 <= n; y2++) {
					temp = res[x2][y2] - res[x1 - 1][y2] - res[x2][y1 - 1] + res[x1 - 1][y1 - 1];
					if (temp > max) max = temp;
				}
			}
		}
	}
	cout << max;
}