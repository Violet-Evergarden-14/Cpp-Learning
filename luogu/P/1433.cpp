#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

double dis[16][16] = {0.0};
double x[16] = {0};
double y[16] = {0};
int vis[16] = {0};
int n;
const double INF = 1000000000.0;

inline double dist(double a, double b) {return sqrt(1.0 * a * a + b * b);}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dis[i][j] = dist(x[i] - x[j], y[i] - y[j]);
			dis[j][i] = dist(x[i] - x[j], y[i] - y[j]);
		}
	}
	int full = 1 << (n + 1);     // pos i: 1 << i
	vector<vector<double>> dp(full, vector<double>(n + 1, INF));
	dp[1][0] = 0;
	for (int mask = 1; mask < full; mask++) {
		for (int i = 0; i < n + 1; i++) {
			if (!(mask & (1 << i))) continue;
			if (dp[mask][i] == INF) continue;
			for (int j = 1; j < n + 1; j++) {
				if (mask & (1 << j)) continue;
				dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dis[i][j]);
			}
		}
	}
	double res = INF;
	for (int i = 1; i <= n; i++) res = min(res, dp[full - 1][i]);
	cout << fixed << setprecision(2) << res;
}