#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, r;
	cin >> n >> r;
	cout << n << "=";
	vector<char> s;
	while (n != 0) {
		int m = n % r;
		n /= r;
		if (m < 0) {
			m -= r;
			n += 1;
		}
		if (m < 10) m += '0';
		else m = m - 10 + 'A';
		s.push_back(m);
	}
	int l = s.size();
	for (int i = 0; i < l; i++) {
		cout << s[l - 1 - i];
	}
	cout << "(base" << r << ")";
}