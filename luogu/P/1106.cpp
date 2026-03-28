#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	string ori;
	cin >> ori;
	int k0;
	cin >> k0;
	int k = k0;
	int len = ori.size();
	vector<int> number(len);
	vector<int> res(len - k);
	stack<int> st;
	for (int i = 0; i < len; i++) number[i] = ori[i] - '0';
	for (int i = 0; i < len; i++) {
		int a = number[i];
		while (!st.empty() && k > 0 && st.top() > a) {
			st.pop();
			k--;
		}
		st.push(a);
	}
	while (st.size() > len - k0) st.pop();
	for (int i = 0; i < len - k0; i++) {
		res[len - k0 - 1 - i] = st.top();
		st.pop();
	}
	bool judge = false;
	for (int i = 0; i < len - k0; i++) {
		if (res[i] != 0) {
			judge = true;
			cout << res[i];
		} else if (judge == true) {
			cout << 0;
		}
	}
	if (judge == false) cout << 0;
}