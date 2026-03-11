#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	long long n, k;
	cin >> n >> k;
	if (k >= n - 1) {cout << 0; return 0;}
	vector<long long> s(n);
	s[0] = 0;
	for (long long i = 1; i <= n - 1; i++)
	{
		long long a;
		cin >> a;
		s[i] = s[i - 1] + a;
	}
	long long m = s[k] - s[0];
	for (long long i = 1; i < n - k; i++)
	{
		if (m < s[k + i] - s[i]) m = s[k + i] - s[i];
	}
	cout << s[n - 1] - m;
	
}
