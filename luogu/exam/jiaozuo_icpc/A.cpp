#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t-- > 0) {
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int temp; cin >> temp;
			if (temp) cnt++;
		}
		switch (cnt) {
		case 0: cout << "Typically Otaku" << endl; break;
		case 1: cout << "Eye-opener" << endl; break;
		case 2: cout << "Young Traveller" << endl; break;
		case 3: cout << "Excellent Traveller" << endl; break;
		default: cout << "Contemporary Xu Xiake" << endl; break;
		}
	}
}