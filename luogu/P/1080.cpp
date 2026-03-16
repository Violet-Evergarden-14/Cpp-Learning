#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long max(long long a, long long b) {
	if (a >= b) return a;
	return b;
}

class Official {
public:
	long long left, right;

	friend bool operator>(const Official& a, const Official& b) {
		if (max(b.right, a.left * a.right) < max(a.right, b.left * b.right)) return true;
		return false;
	}
};

int main()
{
	long long n;
	cin >> n;
	vector<Official> list(n + 1);
	cin >> list[0].left >> list[0].right;
	for (long long i = 1; i <= n; i++) {
		cin >> list[i].left >> list[i].right;
	}
	
	sort(list.begin() + 1, list.end(), greater<Official>());
	
	long long M = 0;
	long long mul = 1;
	for (long long i = 1; i <= n; i++) {
		mul *= list[i - 1].left;
		long long m = mul / list[i].right;
		if (m > M) M = m;
	}
	cout << M;
}