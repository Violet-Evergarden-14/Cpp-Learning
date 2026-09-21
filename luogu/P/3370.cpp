#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const long long MOD = 1e9 + 9;
const long long T = 1e5 + 3;

long long hasht(string& s) {
	long long res = 0;
	for (long long i = 0; i < s.size(); i++) {
		res = ((res * T % MOD) + s[i]) % MOD;
	}
	return res;
}

int main() {
	long long n; cin >> n;
	string s;
	long long res = n;
	vector<long long> v(n + 1, 0);
	for (long long i = 1; i <= n; i++) {
		cin >> s;
		v[i] = hasht(s);
	}
	sort(v.begin() + 1, v.begin() + n + 1);
	for (long long i = 1; i <= n - 1; i++) {
		if (v[i] == v[i + 1]) res--;
	}
	cout << res;
}