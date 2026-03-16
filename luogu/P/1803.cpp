#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Range
{
public:
	int l, r;
	friend bool operator<(const Range& a, const Range& b) {
		if (a.r < b.r) return true;
		if (a.r > b.r) return false;
		if (a.l > b.l) return true;
		return false;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<Range> time_table(n);
	for (int i = 0; i < n; i++) {
		cin >> time_table[i].l >> time_table[i].r;
	}
	sort(time_table.begin(), time_table.end());
	int j = time_table[0].r;
	int count = 1;
	int k = 0;
	while (k < n) {
		while (k < n && time_table[k].l < j) {
			k++;
		}
		if (k == n) break;
		count++;
		j = time_table[k].r;
	}
	cout << count;
}