#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Factor {public:
	int num = 0;
	int count = 0;
};

int m1, m2;
vector<Factor> factor_for_m1;
int s;

void find_factor(int m, vector<Factor>& factor_for_m) {
	int i = 2;
	int idx = -1;
	int t = m;
	while (i <= sqrt(t)) {
		if (t % i == 0) {
			factor_for_m.push_back({i, 0});
			idx++;
			while (t % i == 0) {
				factor_for_m[idx].count++;
				t /= i;
			}
		}
		i++;
	}
	if (t != 1) {
		factor_for_m.push_back({t, 1});
	}
}

int least_time(int a) {
	if (a == 1) return -1;
	vector<Factor> factor_for_a;
	find_factor(a, factor_for_a);
	int idx = 0;
	int res = -1;
	for (int i = 0; i < s; i++) {
		int p = factor_for_m1[i].num;
		int q = factor_for_m1[i].count;
		while (idx < factor_for_a.size() && factor_for_a[idx].num != p) {
			idx++;
		}
		if (idx >= factor_for_a.size()) {return -1;}
		res = max(res, (q * m2 - 1) / factor_for_a[idx].count + 1);
	}
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n >> m1 >> m2;
	if (m1 == 1) {cout << 0; return 0;}
	find_factor(m1, factor_for_m1);
	s = factor_for_m1.size();

	vector<int> cell(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cell[i] = least_time(a);
	}
	int res = 2000000000;
	for (int i = 0; i < n; i++) {
		if (cell[i] != -1) {
			res = min(res, cell[i]);
		}
	}
	if (res == 2000000000) res = -1;
	cout << res;
}