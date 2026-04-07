#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Connect {public:
	int x, y, l;
	friend bool operator<(const Connect& a, const Connect& b) {
		return a.l < b.l;
	}
};

int find_head(int x, vector<int>& set) {
	if (x != set[x]) {
		set[x] = find_head(set[x], set);
	}
	return set[x];
}

void merge(int a, int b, vector<int>& set) {
	set[find_head(a, set)] = find_head(b, set);
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

	int n, m, k;
	cin >> n >> m >> k;
	int cost = 0;
	int t = n;
	vector<Connect> connection(m + 1);
	vector<int> set(n + 1);
	for (int i = 0; i <= n; i++) set[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> connection[i].x >> connection[i].y >> connection[i].l;
	}
	sort(connection.begin() + 1, connection.end());
	for (int i = 1; i <= m; i++) {
		if (t == k) break;
		if (find_head(connection[i].x, set) != find_head(connection[i].y, set)) {
			t--;
			merge(connection[i].x, connection[i].y, set);
			cost += connection[i].l;
		}
	}
	if (t == k) cout << cost;
	else cout << "No Answer";
}