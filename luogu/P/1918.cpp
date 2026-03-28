#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Balls {
public:
	int pos;
	int nums;

	friend bool operator<(const Balls& a, const Balls& b) {
		if (a.nums < b.nums) return true;
		return false;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<Balls> list(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i].nums;
		list[i].pos = i + 1;
	}
	sort(list.begin(), list.end());
	int q;
	cin >> q;
	for (int k = 0; k < q; k++) {
		int m;
		cin >> m;
		if (m > list[n - 1].nums || m < list[0].nums) {
			cout << 0 << endl;
			continue;
		}
		int left = 0;
		int right = n - 1;
		while (right - left > 1) {
			int mid = (left + right) / 2;
			if (list[mid].nums < m) left = mid;
			else right = mid;
		}
		if (m == list[right].nums) cout << list[right].pos << endl;
		else if (m == list[left].nums) cout << list[left].pos << endl;
		else cout << 0 << endl;
	}
}