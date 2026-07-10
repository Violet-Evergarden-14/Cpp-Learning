#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, k;
int count = 0;
vector<int> list;
vector<int> chosen;

bool is_prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return false;
	}
	return true;
}

bool judge() {
	int res = 0;
	for (int i = 0; i < k; i++) res += chosen[i];
	return is_prime(res);
}

void dfs(int chosen_idx, int list_idx, vector<int>& list, vector<int>& chosen) {
	if (chosen_idx == k) {
		if (judge() == true) {
			count++;
		}
	} else {
		for (int i = list_idx; i <= n - k + chosen_idx; i++) {
			chosen[chosen_idx] = list[i];
			dfs(chosen_idx + 1, i + 1, list, chosen);
		}
	}
}



int main()
{
	cin >> n >> k;
	list = vector<int>(n);
	chosen = vector<int>(k);
	for (int i = 0; i < n; i++) cin >> list[i];
	dfs(0, 0, list, chosen);
	cout << count;
}