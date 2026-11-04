#include <iostream>
using namespace std;

int main() {
	long t; cin >> t;
	while (t-- > 0) {
		long a, b, c;
		cin >> a >> b >> c;
		cout << max(a - b, a + c - b) << endl;
	}
}