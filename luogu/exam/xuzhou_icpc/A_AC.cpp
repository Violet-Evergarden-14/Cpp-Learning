#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const int MOD = 1e9 + 7;
const int MAXN = 100001;
const int MAXM = 500000;

struct Edge {
	int u, v;
	ull w;
	bool operator<(const Edge& e) {return w < e.w;}
} e[MAXM];

int n, m, s[MAXN];
ull k1, k2;
int total;

unsigned long long xorShift128Plus() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

void init() {
	for (int i = 1; i <= n; i++) s[i] = i;
	total = 0;
	for (int i = 1; i <= m; i++) {
		int u, v; ull w;
		u = xorShift128Plus() % n + 1;
        v = xorShift128Plus() % n + 1;
        w = xorShift128Plus();
		if (u == v) continue;
		e[++total] = {u, v, w};
	}
}

int find(int x) {
	if (x != s[x]) s[x] = find(s[x]);
	return s[x];
}

void solve() {
	init();
	sort(e + 1, e + total + 1);
	ull ans = 0;
	int cnt = 0;
	for (int i = 1; i <= total && cnt < n - 1; i++) {
		int su = find(e[i].u);
		int sv = find(e[i].v);
		if (su != sv) {
			s[su] = sv;
			ans += e[i].w % MOD;
			ans %= MOD;
			cnt++;
		}
	}

	if (cnt == n - 1) cout << ans << endl;
	else cout << 0 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t-- > 0) {
		cin >> n >> m >> k1 >> k2;
		solve();
	}

}