/*#include <iostream>
using namespace std;

unsigned long long c(unsigned long long n, unsigned long long m) {
	unsigned long long res = 1;
	for (unsigned long long i = 1; i <= m; i++) {
		res *= (n + 1 - i);
		res /= i;
	}
	return res;
}

int main()
{ 
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	unsigned long long a, b, n;
	cin >> n >> a >> b;
	cout << c(n + a, a) * c(n + b, b);
}*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mul(vector<int>& M, int b) {
	vector<int> A = M;
	for (int i = 0; i < A.size(); i++) A[i] *= b;
	for (int i = 0; i < A.size() - 1; i++) {
		A[i + 1] += A[i] / 10;
		A[i] %= 10;
	}
	while (A[A.size() - 1] >= 10) {
		A.push_back(A[A.size() - 1] / 10);
		A[A.size() - 2] %= 10;
	}
	return A;
}

vector<int> div(vector<int>& M, int b) {
	vector<int> A = M;
	reverse(A.begin(), A.end());
	vector<int> res;
	int rig = 0;
	for (int i = 0; i < A.size(); i++) {
		rig = rig * 10 + A[i];
		res.push_back(rig / b);
		rig %= b;
	}
	reverse(res.begin(), res.end());
	while (res[res.size() - 1] == 0) {
		res.pop_back();
	}
	if (res.size() == 0) res.push_back(0);
	return res;
}

vector<int> mul(vector<int>& A, vector<int>& B) {
	int n = A.size() - 1;
	int m = B.size() - 1;
	int sum = 0;
	vector<int> res;
	for (int i = 0; i <= n + m; i++) {
		for (int j = max(0, i - m); j <= min(i, n); j++) {
			sum += A[j] * B[i - j];
		}
		res.push_back(sum);
		sum = 0;
	}
	for (int i = 0; i < res.size() - 1; i++) {
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
	while (res[res.size() - 1] >= 10) {
		res.push_back(res[res.size() - 1] / 10);
		res[res.size() - 2] %= 10;
	}
	return res;
}

vector<int> c(int n, int a) {
	a = min(a, n - a);
	vector<int> res = vector<int>(1, 1);
	for (int i = 1; i <= a; i++) {
		res = mul(res, n + 1 - i);
		res = div(res, i);
	}
	return res;
}

int main()
{ 
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int a, b, n;
	cin >> n >> a >> b;
	vector<int> c1 = c(n + a, a);
	vector<int> c2 = c(n + b, b);
	vector<int> res = mul(c1, c2);
	for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
}