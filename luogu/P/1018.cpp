#include <iostream>
#include <vector>
using namespace std;

class HighPrecisionNumber {
public:
	int length;
	int number[41];

	HighPrecisionNumber(int t) {
		for (int i = 0; i < 41; i++) number[i] = 0;
		length = 0;
		if (t == 0) {length = 1; return;}
		while (t != 0) {
			number[length++] = t % 10;
			t /= 10;
		}
	}

	HighPrecisionNumber(vector<int>& source, int i, int j) {
		for (int i = 0; i < 41; i++) number[i] = 0;
		length = j - i + 1;
		for (int k = 0; k < length; k++) number[k] = source[j - k];
		while (length > 0 && number[length - 1] == 0) length--;
		if (length == 0) length = 1;
	}

	HighPrecisionNumber operator*(HighPrecisionNumber const& s) const {
		HighPrecisionNumber res(0);
		if (s.length == 1 && s.number[0] == 0) return res;
		if (this->length == 1 && this->number[0] == 0) return res;
		for (int i = 0; i < this->length + s.length - 1; i++) {
			int sum = 0;
			for (int j = max(0, i + 1 - s.length); j <= min(i, this->length - 1); j++) {
				sum += this->number[j] * s.number[i - j];
			}
			res.number[i] += sum;
			res.number[i + 1] += res.number[i] / 10;
			res.number[i] %= 10;
		}
		if (res.number[this->length + s.length - 1] > 0) res.length = this->length + s.length;
		else res.length = this->length + s.length - 1;
		return res;
	}

	bool operator<(HighPrecisionNumber const& s) const {
		if (this->length < s.length) return true;
		if (this->length > s.length) return false;
		for (int i = s.length - 1; i >= 0; i--) {
			if (this->number[i] < s.number[i]) return true;
			if (this->number[i] > s.number[i]) return false;
		}
		return false;
	}

	void print() const {
		for (int i = length - 1; i >= 0; i--) cout << number[i];
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> nums(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		char a; cin >> a;
		nums[i] = a - '0';
	}
	vector<vector<HighPrecisionNumber>> f(n + 1, vector<HighPrecisionNumber>(k + 1, HighPrecisionNumber(0)));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(k, i - 1); j++) {
			if (j == 0) f[i][j] = HighPrecisionNumber(nums, 1, i);
			else {
				HighPrecisionNumber res = f[j][j - 1] * HighPrecisionNumber(nums, j + 1, i);
				for (int t = j + 1; t <= i - 1; t++) {
					HighPrecisionNumber now = f[t][j - 1] * HighPrecisionNumber(nums, t + 1, i);
					if (res < now) res = now;
				}
				f[i][j] = res;
			}
		}
	}

	f[n][k].print();
}