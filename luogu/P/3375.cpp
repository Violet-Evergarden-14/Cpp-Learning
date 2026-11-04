#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s1 = "abcacababcab";
	string s2 = "abcab";
	vector<int> next = {-1, 0, 0, 0, 1};

	int i = 0, j = 0;
	while (true) {
		if (i >= s2.size()) {cout << 1; return 0;}
		if (j >= s1.size()) {cout << 0; return 0;}
		if (s2[i] == s1[j]) {i++; j++;}
		else {
			i = next[i];
			if (i == -1) {i++; j++;}
		}
	}
}