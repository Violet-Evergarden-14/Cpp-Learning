#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long merge_and_count(vector<long long>& list, long long left, long long mid, long long right) {
	long long i = left;
	long long j = mid + 1;
	long long count = 0;
	long long k = 0;
	vector<long long> temp(right - left + 1);
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) {
			temp[k++] = list[i++];
		} else {
			while (j <= right && list[i] > list[j]) {
				temp[k++] = list[j++];
				count += mid - i + 1;
			}
		}
	}
	while (i <= mid) temp[k++] = list[i++];
	while (j <= right) temp[k++] = list[j++];
	for (long long in = 0; in < temp.size(); in++) list[left + in] = temp[in];
	return count;
}

long long find_reverse_number(vector<long long>& list, long long left, long long right) {
	if (left >= right) return 0;
	long long mid = (left + right) / 2;
	long long res = 0;
	res += find_reverse_number(list, left, mid);
	res += find_reverse_number(list, mid + 1, right);
	res += merge_and_count(list, left, mid, right);
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	long long n;
	cin >> n;
	vector<long long> list(n);
	for (long long i = 0; i < n; i++) {
		cin >> list[i];
	}
	cout << find_reverse_number(list, 0, n - 1);
}