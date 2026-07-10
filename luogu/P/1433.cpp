#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
vector<double> xl;
vector<double> yl;
vector<int> vis;
vector<vector<double>> d;

double dfs(int idx, int count) {
	if (count == 0) return 0;
	vector<double> res;
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			res.push_back(d[idx][i] + dfs(i, count - 1));
			vis[i] = 0;
		}
	}
	double r = 2000000000;
	for (int i = 0; i < count; i++) r = min(r, res[i]);
	return r;
}

int main()
{
	cin >> n;
	vis = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		xl.push_back(x);
		yl.push_back(y);
	}
	xl.push_back(0);
	yl.push_back(0);
	d = vector<vector<double>>(n + 1, vector<double>(n + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			d[i][j] = sqrt(pow(xl[i] - xl[j], 2) + pow(yl[i] - yl[j], 2));
		}
	}
	cout << fixed << setprecision(2) << dfs(n, n);
}