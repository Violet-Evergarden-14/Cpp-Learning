#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	vector<int> a = {1, 2, 3, 2, 1, 2, 3, 4};
	int l = a.size();
	vector<int> res(l, 0);
	stack<int> st;
	for (int i = 0; i < l; i++) {
		while (!st.empty()) {
			int t = st.top();
			if (a[t] < a[i]) {
				st.pop();
				res[t] = i - t;
			} else break;
		}
		st.push(i);
	}
	for (int i = 0; i < l; i++) {
		cout << res[i] << " ";
	}
}