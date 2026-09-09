#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; cin >> n;
	vector<int> v1(n + 1);
	vector<int> v2(n + 1);
	int temp;
	for (int i = 0; i < n; i++) {cin >> temp; v1[temp] = i + 1;}          // think of it
	for (int i = 0; i < n; i++) {cin >> temp; v2[i + 1] = v1[temp];}      // think of it
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		int it = lower_bound(v.begin(), v.end(), v2[i]) - v.begin();
		if (it < v.size()) v[it] = v2[i];
		else v.push_back(v2[i]);
	}
	cout << v.size();
}