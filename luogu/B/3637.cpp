#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; cin >> n;
	int temp;
	vector<int> longest_list;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		int it = upper_bound(longest_list.begin(), longest_list.end(), temp) - longest_list.begin();
		if (it < longest_list.size()) longest_list[it] = temp;
		else longest_list.push_back(temp);
	}
	cout << longest_list.size();
}