#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int s = 0;
	int v[n];
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (v[j] > v[j + 1]) {
				s++; swap(v[j], v[j + 1]);
			}
		}
	}
	cout << s;
}