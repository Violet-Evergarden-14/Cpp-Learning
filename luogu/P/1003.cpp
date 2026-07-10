#include <iostream>
#include <vector>
using namespace std;

vector<int> x_list;
vector<int> y_list;
vector<int> x_length;
vector<int> y_length;

bool check(int i, int x, int y) {
	return x >= x_list[i] && x <= x_list[i] + x_length[i] && y >= y_list[i] && y <= y_length[i] + y_list[i];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		x_list.push_back(x);
		y_list.push_back(y);
		x_length.push_back(a);
		y_length.push_back(b);
	}
	int x, y;
	cin >> x >> y;
	for (int i = n - 1; i >= 0; i--) {
		if (check(i, x, y) == true) {
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;
}