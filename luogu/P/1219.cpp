#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int c = 3;

bool check(vector<int>& col, int m) {
	for (int i = 0; i < m; i++) {
		if (col[m] == col[i]) return false;
		if (col[m] + m == col[i] + i) return false;
		if (col[m] - m == col[i] - i) return false;
	}
	return true;
}

int count(vector<int>& col, int m) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		col[m] = i;
		if (check(col, m) == false) continue;
		if (m == n - 1) {
			if (c > 0) {
				c--;
				for (int j = 0; j < n; j++) {
					cout << col[j] + 1 << " ";
				}
				cout << endl;
			}
			res += 1;
			continue;
		}
		res += count(col, m + 1);
	}
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
	
	cin >> n;
	vector<int> col(n);
	cout << count(col, 0);
}