#include <iostream>
#include <vector>
#include <set>
using namespace std;

int find(int x, vector<int>& set_) {
	if (set_[x] != x) {
		set_[x] = find(set_[x], set_);
	}
	return set_[x];
}

void merge(int x, int y, vector<int>& set_) {
	set_[find(y, set_)] = find(x, set_);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	char r;
	int x, y;
	vector<int> set_(n * 2);
	for (int i = 0; i < n * 2; i++) set_[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> r >> x >> y;
		x--;
		y--;
		if (r == 'E') {
			merge(x, y + n, set_);
			merge(x + n, y, set_);
		} else {
			merge(x, y, set_);
		}
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		int head = find(i, set_);
		if (s.count(head) == 0) s.insert(head);
	}
	cout << s.size();
}