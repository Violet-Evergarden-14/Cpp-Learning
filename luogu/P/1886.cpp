#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int left = 0;
	int right = k - 1;
	int max = nums[0], min = nums[0];
	int id_max = 0, id_min = 0;
	for (int i = 0; i < k; i++) {
		if (max <= nums[i]) {
			max = nums[i];
			id_max = i;
		}
		if (min >= nums[i]) {
			min = nums[i];
			id_min = i;
		}
	}
	vector<int> great(n - k + 1);
	vector<int> small(n - k + 1);
	for (; right <= n - 1; left++, right++) {
		if (id_max < left) {
			id_max = left;
			max = nums[left];
			for (int i = left + 1; i <= right; i++) {
				if (max <= nums[i]) {
					max = nums[i];
					id_max = i;
				}
			}
		}
		if (id_min < left) {
			id_min = left;
			min = nums[left];
			for (int i = left + 1; i <= right; i++) {
				if (min >= nums[i]) {
					min = nums[i];
					id_min = i;
				}
			}
		}
		if (max <= nums[right]) {max = nums[right]; id_max = right;}
		if (min >= nums[right]) {min = nums[right]; id_min = right;}
		great[left] = max;
		small[left] = min;
	}
	for (int i = 0; i < n - k + 1; i++) {cout << small[i] << " ";} cout << endl;
	for (int i = 0; i < n - k + 1; i++) {cout << great[i] << " ";} cout << endl;
}