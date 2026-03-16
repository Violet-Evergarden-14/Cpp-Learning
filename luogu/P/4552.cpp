#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	long long n;
	cin >> n;
	vector<long long> ori(n + 1, 0);
	vector<long long> diff(n + 2, 0);
	for (long long i = 1; i <= n; i++) {
		cin >> ori[i];
		diff[i] = ori[i] - ori[i - 1];
	}
	long long a, b = 0;
	for (long long i = 2; i <= n; i++) {b += abs(diff[i]);}
	a = abs(ori[n] - ori[1]);
	cout << (a + b) / 2 << endl;
	cout << a + 1 << endl;
}