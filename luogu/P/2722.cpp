#include <iostream>
#include <vector>
using namespace std;

class Problem { public:
	int point, t;
};

int main()
{
	int total_time, n;
	cin >> total_time >> n;
	vector<Problem> list(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i].point >> list[i].t;
	}
	vector<int> dp(total_time + 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = list[i].t; j <= total_time; j++) {
			dp[j] = max(dp[j], dp[j - list[i].t] + list[i].point);
		}
	}
	cout << dp[total_time];
}