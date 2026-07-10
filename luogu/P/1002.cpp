#include <iostream>
#include <vector>
using namespace std;

vector<int> dx = {0, -2, -1, 1, 2, 2, 1, -1, -2};
vector<int> dy = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int x0, y0;

vector<int> hx;
vector<int> hy;

void get_h() {
	for (int i = 0; i < 9; i++) {
		hx.push_back(x0 + dx[i]);
		hy.push_back(y0 + dy[i]);
	}
}

bool judge_in(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (x == hx[i] && y == hy[i]) return true;
	}
	return false;
}

int main()
{
	int bx, by;
	cin >> bx >> by >> x0 >> y0;
	get_h();
	vector<long long> dp(by + 1, 0);
	for (int x = 0; x <= bx; x++) {
		for (int y = 0; y <= by; y++) {
			if (!judge_in(x, y)) {
				if (x == 0) {
					if (y == 0) dp[y] = 1;
					else dp[y] = dp[y - 1];
				}
				else if (y > 0) dp[y] += dp[y - 1];
			} else dp[y] = 0;
		}
	}
	cout << dp[by];
}