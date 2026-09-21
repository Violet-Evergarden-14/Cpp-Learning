#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int s[50000];

int find(int x) {
	if (x != s[x]) s[x] = find(s[x]);
	return s[x];
}

 inline void merge(int x, int y) {
	s[find(x)] = find(y);
}

struct Pair {
	int a, b;
	Pair(int _a, int _b): a(_a), b(_b) {}
};

void solve() {
	for (int i = 0; i < 50000; i++) s[i] = i;
	int n; cin >> n;
	int idx = 0;
	bool res = true;
	vector<Pair> check;
	map<int, int> um;
	for (int i = 0; i < n; i++) {
		int m, n, e;
		cin >> m >> n >> e;
		if (m == n) {
			if (e == 0) res = false;
		} else {
			if (e == 0) {check.push_back(Pair(m, n));}
			else {
				int it1 = um.count(m);
				int it2 = um.count(n);
				if (it1 == 0) {
					if (it2 == 0) {
						um[m] = idx;
						um[n] = idx;
						idx++;
					} else {
						um[m] = um[n];
					}
				} else {
					if (it2 == 0) {
						um[n] = um[m];
					} else {
						int mr = um[m], nr = um[n];
						if (mr > nr) merge(mr, nr);
						else merge(nr, mr);
					}
				}
			}
		}
	}
	for (int i = 0; i < check.size(); i++) {
		Pair cur = check[i];
		if (um.count(cur.a) == 1 && um.count(cur.b) == 1 && find(um[cur.a]) == find(um[cur.b])) {
			res = false;
			break;
		}
	}
	if (res == true) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int t; cin >> t;
	while (t-- > 0) {solve();}
}