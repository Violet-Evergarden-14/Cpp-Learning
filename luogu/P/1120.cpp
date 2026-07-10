/*
这个方案速度已经非常快了，其实没什么比较好的剪枝方案，把这个方案的vector容器换成普通数组其实就过了

另外，s[i] + cur_len <= l这里可以用二分来操作找到最小的i，优化较大
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int cur_pos, int cur_len, int l, int count, int total, vector<int>& s, vector<int>& vis) {
	if (count == total) return true;
	if (cur_len == l) return dfs(0, 0, l, count + 1, total, s, vis);
	int fail = 0;
	for (int i = cur_pos; i < s.size(); i++) {
		if (vis[i] == 0 && s[i] != fail && s[i] + cur_len <= l) {
			vis[i] = 1;
			if (dfs(i + 1, cur_len + s[i], l, count, total, s, vis) == true) return true;
			vis[i] = 0;
			if (cur_len == 0) return false;
			if (cur_len + s[i] == l) return false;
			fail = s[i];
		}
	}
	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> s(n);
	int sum = 0;
	int m = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		m = max(m, a);
		sum += a;
		s[i] = a;
	}
	sort(s.begin(), s.end(), greater<int>());
	vector<int> vis(n, 0);
	for (int i = sum / m; i > 0; i--) {
		if (sum % i == 0) {
			int l = sum / i;
			if (dfs(0, 0, l, 0, i, s, vis) == true) {
				cout << l;
				return 0;
			}
		}
	}
}