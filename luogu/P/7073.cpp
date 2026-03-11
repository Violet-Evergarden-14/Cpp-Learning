#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	string s;
	getline(cin, s);
	int n;
	cin >> n;
	int list[n + 1] = {0};
	int i = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == ' ' || s[i] == 'x') s.erase(i, 1);
	}
	
	

	return 0;
}