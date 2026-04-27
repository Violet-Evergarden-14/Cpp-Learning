#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

class Home {public:
	int x, y;
	int idx;
};

class Dis {public:
	int p1, p2;
	double distance;

	friend bool operator<(const Dis& a, const Dis& b) {
		return a.distance < b.distance;
	}
};

int find(int x, vector<int>& set) {
	if (set[x] != x) {
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

	int n, k;
	cin >> n >> k;
	vector<Home> home(n);
	vector<int> set(n);
	for (int i = 0; i < n; i++) {
		cin >> home[i].x >> home[i].y;
		home[i].idx = i;
		set[i] = i;
	}
	vector<Dis> dis;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double l = sqrt((home[i].x - home[j].x) * (home[i].x - home[j].x) + (home[i].y - home[j].y) * (home[i].y - home[j].y));
			dis.push_back({i, j, l});
		}
	}
	sort(dis.begin(), dis.end());
	int count = 0;
	int idx = 0;
	while (count < n - k) {
		int a = dis[idx].p1;
		int b = dis[idx].p2;
		if (find(a, set) != find(b, set)) {
			merge(a, b, set);
			count++;
		}
		idx++;
	}
	while (idx < dis.size()) {
		int a = dis[idx].p1;
		int b = dis[idx].p2;
		if (find(a, set) != find(b, set)) {
			cout << fixed << setprecision(2) << dis[idx].distance;
			break;
		}
		idx++;
	}
}