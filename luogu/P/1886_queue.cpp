#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b(n - k + 1);
	for (int i = 0; i < n; i++) cin >> a[i];
	deque<int> min;
	for (int i = 0; i < n; i++) {
		while (!min.empty() && a[min.back()] >= a[i]) min.pop_back();
		min.push_back(i);
		while (min.front() <= i - k) min.pop_front();
		if (i >= k - 1) b[i - k + 1] = a[min.front()];
	}
	for (int i = 0; i < n - k + 1; i++) cout << b[i] << " ";
}