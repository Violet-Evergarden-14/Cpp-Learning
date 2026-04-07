#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Wire {public:
	long long x, y, l;
	friend bool operator<(const Wire& a, const Wire& b) {
		return a.l < b.l;
	}
};

long long find(long long x, vector<long long>& set) {
	if (x != set[x]) {
		set[x] = find(set[x], set);
	}
	return set[x];
}

void merge(long long x, long long y, vector<long long>& set) {
	set[find(x, set)] = find(y, set);
}

int main()
{
	long long n, len = 0;
	cin >> n;
	vector<long long> set(n + 1);
	for (long long i = 1; i <= n; i++) set[i] = i;
	vector<Wire> wire;
	wire.push_back({0, 0, 0});  // very important, or not consistant
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			long long l;
			cin >> l;
			if (i > j) {
				wire.push_back({i, j, l});
			}
		}
	}
	sort(wire.begin() + 1, wire.end());
	long long count = 0;
	for (long long i = 1; i <= n * (n - 1) / 2; i++) {
		if (count > n) break;
		if (find(wire[i].x, set) != find(wire[i].y, set)) {
			count++;
			merge(wire[i].x, wire[i].y, set);
			len += wire[i].l;
		}
	}
	cout << len;
}