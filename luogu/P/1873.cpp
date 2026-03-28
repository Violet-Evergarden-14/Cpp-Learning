#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long find_(vector<long long>& list, vector<long long>& sum_up, long long m, long long left, long long right) {
	if (right == left + 1) {
		long long a = sum_up[right] - (right + 1) * list[right];
		long long delta = a - m;
		return list[right] + delta / right;
	}
	long long mid = (left + right) / 2;
	long long a = sum_up[mid] - (mid + 1) * list[mid];
	if (a > m) return find_(list, sum_up, m, left, mid);
	if (a == m) return list[mid];
	return find_(list, sum_up, m, mid, right);
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;
	if (n == 1) {cout << m; return 0;}
	vector<long long> list(n);
	for (long long i = 0; i < n; i++) {cin >> list[i];}
	sort(list.begin(), list.end(), greater<long long>());
	vector<long long> sum_up(n);
	sum_up[0] = list[0];
	for (long long i = 1; i < n; i++) {sum_up[i] = sum_up[i - 1] + list[i];}
	cout << find_(list, sum_up, m, 0, n - 1);
}