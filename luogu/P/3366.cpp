#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Branch {public:
	int x, y, l;
	friend bool operator<(const Branch& a, const Branch& b) {
		return a.l < b.l;
	}
};

int find(int x, vector<int>& set) {
	if (x != set[x]) {
		set[x] = find(set[x], set);
	}
	return set[x];
}

void merge(int x, int y, vector<int>& set) {
	set[find(x, set)] = find(y, set);
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<int> set(n + 1);
	for (int i = 0; i <= n; i++) set[i] = i;
	vector<Branch> branches(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> branches[i].x >> branches[i].y >> branches[i].l;
	}
	sort(branches.begin() + 1, branches.end());
	int min_length = 0;
	for (int i = 1; i <= m; i++) {
		if (find(branches[i].x, set) != find(branches[i].y, set)) {
			min_length += branches[i].l;
			merge(branches[i].x, branches[i].y, set);
		}
	}
	int t = find(1, set);
	bool judge = true;
	for (int i = 2; i <= n; i++) {
		if (find(i, set) != t) {
			judge = false;
			break;
		}
	}
	if (judge == true) cout << min_length;
	else cout << "orz";
}