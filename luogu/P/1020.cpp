#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	vector<int> height;
	int a;
	while (cin >> a) {
		if (a == 1) break;
		height.push_back(a);
	}
	vector<int> t1;
	for (int i = 0; i < height.size(); i++) {
		if (i == 0) {t1.push_back(height[0]); continue;}
		int z = height[i];
		if (t1.back() >= z) t1.push_back(z);
		else {
			int pos = upper_bound(t1.begin(), t1.end(), z, greater<int>()) - t1.begin();
			t1[pos] = z;
		}
	}
	vector<int> t2;
	for (int i = 0; i < height.size(); i++) {
		if (i == 0) {t2.push_back(height[0]); continue;}
		int z = height[i];
		if (t2.back() <= z) t2.push_back(z);
		else {
			int pos = upper_bound(t2.begin(), t2.end(), z) - t2.begin();
			t2[pos] = z;
		}
	}
	cout << t1.size() << endl << t2.size();
}