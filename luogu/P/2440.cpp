#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool judge(vector<long long>& list, vector<long long>& sum_up, long long k, long long end_place, long long length) {
	if (length == 1) return true;
	if (sum_up[end_place] < length * k) return false;
	long long amount = 0;
	for (long long i = 1; i <= end_place; i++) {
		amount += list[i] / length;
	}
	if (amount >= k) return true;
	return false;
}

long long find_(vector<long long>& list, vector<long long>& sum_up, long long k, long long left, long long right) {
	if (right == left + 1) {
		long long a = list[left];
		long long b = list[right];
		while (a > b + 1) {
			long long mid = (a + b) / 2;
			if (judge(list, sum_up, k, right, mid) == false) a = mid;
			else b = mid;
		}
		if (judge(list, sum_up, k, right, a) == true) return a;
		return b;
	}
	long long mid = (left + right) / 2;
	if (judge(list, sum_up, k, mid, list[mid]) == false) return find_(list, sum_up, k, mid, right);
	return find_(list, sum_up, k, left, mid);
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	long long n, k;
	cin >> n >> k;
	vector<long long> list(n + 2, 0); list[n + 1] = 1;
	vector<long long> sum_up(n + 2, 0);
	for (long long i = 0; i < n; i++) cin >> list[i + 1];
	sort(list.begin() + 1, list.end(), greater<long long>());
	for (long long i = 0; i < n; i++) sum_up[i + 1] = sum_up[i] + list[i + 1];
	sum_up[n + 1] = sum_up[n] + 1;
	if (k > sum_up[n]) {cout << 0; return 0;}
	cout << find_(list, sum_up, k, 1, n + 1);
}