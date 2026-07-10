#include <iostream>
#include <vector>
using namespace std;

vector<int> s;

void split(int n, int m) {
	if (n == 0) {
		if (s.size() == 1) return;
		for (int i = 0; i < s.size() - 1; i++) cout << s[i] << "+";
		cout << s[s.size() - 1] << endl;
		return;
	}
	if (m > n) return;
	if (n == 1) {
		s.push_back(1);
		if (s.size() == 1) return;
		for (int i = 0; i < s.size() - 1; i++) cout << s[i] << "+";
		cout << s[s.size() - 1] << endl;
		s.pop_back();
		return;
	}
	for (int i = m; i <= n; i++) {
		s.push_back(i);
		split(n - i, i);
		s.pop_back();
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	split(n, 1);
}