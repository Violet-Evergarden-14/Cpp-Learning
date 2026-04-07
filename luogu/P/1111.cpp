#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Road {public:
	int x, y, t;
	friend bool operator<(const Road& a, const Road& b) {
		return a.t < b.t;
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

	int n, m;
	cin >> n >> m;
	vector<Road> road(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> road[i].x >> road[i].y >> road[i].t;
	}
	sort(road.begin() + 1, road.end());
	vector<int> set(n + 1);
	for (int i = 0; i <= n; i++) set[i] = i;
	int max_time = 0;
	for (int i = 1; i <= m; i++) {
		if (find_head(road[i].x, set) != find_head(road[i].y, set)) {
			max_time = road[i].t;
			merge(road[i].x, road[i].y, set);
		}
	}
	int t = find_head(1, set);
	bool judge = true;
	for (int i = 1; i <= n; i++) {
		if (find_head(i, set) != t) {
			judge = false;
			break;
		}
	}
	if (judge == true) cout << max_time;
	else cout << -1;
}