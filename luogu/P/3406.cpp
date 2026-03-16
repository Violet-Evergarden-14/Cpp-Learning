#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;
	vector<long long> cities(m + 2, 1);
	vector<long long> diff(n + 2, 0);
	for (long long i = 1; i <= m; i++) {
		cin >> cities[i];
		if (i == 1) continue;
		if (cities[i] > cities[i - 1]) {
			diff[cities[i - 1]]++;
			diff[cities[i]]--;
		} else {
			diff[cities[i]]++;
			diff[cities[i - 1]]--;
		}
	}
	vector<long long> total_times(n + 1, 0);
	for (long long i = 1; i <= n; i++) {
		total_times[i] = total_times[i - 1] + diff[i];
	}

	long long budget = 0;
	for (long long i = 1; i <= n - 1; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		long long p1 = a * total_times[i];
		long long p2 = c + b * total_times[i];
		budget += min(p1, p2);
	}
	
	cout << budget;
}