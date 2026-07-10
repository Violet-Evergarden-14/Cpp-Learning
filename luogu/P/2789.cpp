#include <iostream>
#include <vector>
using namespace std;

vector<int> s;
vector<int> sq;
int count = 0;

int sum_square() {
	int res = 0;
	for (int i : s) {
		res += i * i;
	}
	return res;
}

bool in_sq(int a) {
	for (int i : sq) {
		if (i == a) return true;
	}
	return false;
}

void dfs(int n, int m) {
	if (n == 0) {
		int a = sum_square();
		if (!in_sq(a)) sq.push_back(a);
		return;
	}
	if (m > n) return;
	for (int i = m; i <= n; i++) {
		s.push_back(i);
		dfs(n - i, i);
		s.pop_back();
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	dfs(n, 1);
	cout << sq.size();
}