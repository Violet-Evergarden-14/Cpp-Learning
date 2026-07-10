#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> face;
	vector<string> career;
	for (int i = 0; i < n; i++) {
		int f;
		string c;
		cin >> f >> c;
		face.push_back(f);
		career.push_back(c);
	}
	int pos = 0;
	for (int i = 0; i < m; i++) {
		int f;
		int move;
		cin >> f >> move;
		if (f == face[pos]) pos -= move;
		else pos += move;
		if (pos >= n) pos -= n;
		if (pos < 0) pos += n;
	}
	cout << career[pos];
}