#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long find_first_lower(vector<long long>& list, long long target) {
	long long l = list.size();
	if (target <= list[l - 1]) return l;
	if (target > list[0]) return 0;
	long long left = 0;
	long long right = l - 1;
	while (right - left >= 2) {
		long long mid = (left + right) / 2;
		if (list[mid] >= target) left = mid;
		else right = mid;
	}
	return right;
}

long long find_last_greater(vector<long long>& list, long long target) {
	long long l = list.size();
	if (target < list[l - 1]) return l - 1;
	if (target >= list[0]) return -1;
	long long left = 0;
	long long right = l - 1;
	while (right - left >= 2) {
		long long mid = (left + right) / 2;
		if (list[mid] > target) left = mid;
		else right = mid;
	}
	return left;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long n, c;
	long long count = 0;
	cin >> n >> c;
	vector<long long> list(n);
	for (long long i = 0; i < n; i++) cin >> list[i];
	sort(list.begin(), list.end(), greater<long long>());
	for (long long i = 0; i < n; i++) {
		long long target = list[i] - c;
		long long lower = find_first_lower(list, target);
		long long greater = find_last_greater(list, target);
		count += lower - greater - 1;
	}
	cout << count;
}