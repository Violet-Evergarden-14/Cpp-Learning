#include <iostream>
#include <vector>
using namespace std;

class Student { public:
	int m, t;
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

	int n, money_total, time_total;
	cin >> n >> money_total >> time_total;
	vector<Student> students(n);
	for (int i = 0; i < n; i++) {
		cin >> students[i].m >> students[i].t;
	}
	vector<vector<int>> dp(money_total + 1, vector<int>(time_total + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j1 = money_total; j1 >= students[i].m; j1--) {
			for (int j2 = time_total; j2 >= students[i].t; j2--) {
				dp[j1][j2] = max(dp[j1][j2], dp[j1 - students[i].m][j2 - students[i].t] + 1);
			}
		}
	}
	cout << dp[money_total][time_total];
}