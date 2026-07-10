#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	int a;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ans ^= a;
	}
	cout << ans;
}