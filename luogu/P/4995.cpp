#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long square(long long x) {return x * x;}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long n;
	cin >> n;
	vector<long long> stones(n + 1, 0);
	for (long long i = 0; i < n; i++) cin >> stones[i];
	sort(stones.begin(), stones.end());
	long long s = 0;
	long long i = 0, j = n;
	while (i < j) {
		s += square(stones[i] - stones[j]) + square(stones[i + 1] - stones[j]);
		i++;
		j--;
	}
	cout << s;
}