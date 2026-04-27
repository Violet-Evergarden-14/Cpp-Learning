#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

class Dot {public:
	long long x, y;
};

class Way {public:
	long long u, v;
	long long dis_square = 0;
	friend bool operator<(const Way& a, const Way& b) {
		return a.dis_square < b.dis_square;
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
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;
	vector<long long> set(n + 1);
	vector<Dot> dots(n + 1);
	for (long long i = 1; i <= n; i++) set[i] = i;
	for (long long i = 1; i <= n; i++) {
		cin >> dots[i].x >> dots[i].y;
	}
	for (long long i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		merge(a, b, set);
	}
	vector<Way> ways;
	ways.push_back({0, 0, 0});
	for (long long i = 1; i <= n; i++) {
		for (long long j = i + 1; j <= n; j++) {
			if (find(i, set) != find(j, set)) {
				ways.push_back({i, j, (dots[i].x - dots[j].x) * (dots[i].x - dots[j].x) + (dots[i].y - dots[j].y) * (dots[i].y - dots[j].y)});
			}
		}
	}
	sort(ways.begin() + 1, ways.end());
	long long l = ways.size();
	double len = 0;
	for (long long i = 1; i < l; i++) {
		if (find(ways[i].u, set) != find(ways[i].v, set)) {
			len += sqrt(ways[i].dis_square);
			merge(ways[i].u, ways[i].v, set);
		}
	}
	cout << fixed << setprecision(2) << len;
}