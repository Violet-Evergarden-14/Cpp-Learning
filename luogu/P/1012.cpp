#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Number {public:
	int x, len = 0;
	vector<int> num;

	friend bool operator<(const Number& a, const Number& b) {
		int count = 0;
		while (count < min(a.len, b.len)) {
			if (a.num[count] > b.num[count]) return true;
			if (a.num[count] < b.num[count]) return false;
			count++;
		}
		if (a.len == b.len) return true;
		if (a.len > b.len) {
			int t = a.len - b.len;
			vector<int> _num(t);
			for (int i = 0; i < t; i++) {
				_num[i] = a.num[i + b.len];
			}
			Number c(_num);
			return c < b;
		} else {
			int t = -a.len + b.len;
			vector<int> _num(t);
			for (int i = 0; i < t; i++) {
				_num[i] = b.num[i + a.len];
			}
			Number c(_num);
			return a < c;
		}
	};

	void show() {cout << x;}

	Number(vector<int>& _num): num(_num) {
		x = 0;
		len = _num.size();
	}
	Number(int _x): x(_x) {
		while (_x > 0) {
			num.push_back(_x % 10);
			_x /= 10;
			len++;
		}
		reverse(num.begin(), num.end());
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<Number> nums;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		nums.push_back(Number(m));
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; i++) nums[i].show();
}