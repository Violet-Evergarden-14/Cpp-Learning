#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long n, x, a, count = 0;
	cin >> n >> x;
	vector<long long> list(n);
	for (long long i = 0; i < n; i++) {
		cin >> a;
		if (a > x) {
			count += a - x;
			a = x;
		}
		list[i] = a;
	}
	for (long long i = 0; i < n - 1; i++) {
		long long p = list[i], q = list[i + 1];
		if (p + q > x) {
			count += p + q - x;
			if (q >= p + q - x) {
				list[i + 1] -= p + q - x;
			} else {
				list[i + 1] = 0;
			}
		}
	}
	cout << count;
}