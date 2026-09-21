#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	int t; cin >> t;
	while (t-- > 0) {
		unordered_map<int, int> s;
		vector<int> v;
		int n; cin >> n;
		while (n-- > 0) {
			int k; cin >> k;
			if (s.count(k) == 0) {
				s[k] = 1;
				v.push_back(k);
			}
		}
		for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
		cout << endl;
	}
}