#include <iostream>
using namespace std;

int main() {
	int n;
	int a; cin >> n >> a;
	int s;
	int idx1 = 1;
	for (int i = 2; i <= (1 << (n - 1)); i++) {
		cin >> s;
		if (a < s) {a = s; idx1 = i;}
	}
	int s1 = a;
	cin >> a;
	int idx2 = (1 << (n - 1)) + 1;
	for (int i = idx2 + 1; i <= (1 << n); i++) {
		cin >> s;
		if (a < s) {a = s; idx2 = i;}
	}
	if (s1 > a) cout << idx2;
	else cout << idx1;
}