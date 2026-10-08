#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const long long MOD = 998244353;

class Node {
public:
	int father;
	int now_son_number = 0;         //
	int son_number = 0;
	int cut = 0;                    //
	long long multiple = 1;         //
	vector<int> node_list_size;     //
};

long long calculate(int k) {
	if (k <= 1) return 1;
	long long res = 1;
	for (int i = 1; i <= k; i++) res = res * i % MOD;
	return res;
}

void solve() {
	int n; cin >> n;
	vector<Node> node_list(n + 1);
	for (int i = 2; i <= n; i++) {
		int a; cin >> a;
		node_list[i].father = a;
		node_list[a].son_number++;
	}
	queue<int> q;
	for (int i = 2; i <= n; i++) {
		if (node_list[i].now_son_number == node_list[i].son_number) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		Node* now = &node_list[cur];
		Node* father = &node_list[now->father];
		father->now_son_number++;
		if (now->son_number == 0) {
			father->node_list_size.push_back(1);
		} else {
			sort(now->node_list_size.begin(), now->node_list_size.end());
			int _size = now->node_list_size.size();
			int sum = 0;
			for (int i = 0; i < _size - 1; i++) {
				sum += now->node_list_size[i];
			}
			father->cut += now->cut + sum;
			sum += now->node_list_size[_size - 1];
			father->node_list_size.push_back(sum + 1);

			int max_num = 0;
			int k = _size - 1;
			while (k >= 0) {
				if (now->node_list_size[k] == now->node_list_size[_size - 1]) max_num++;
				else break;
				k--;
			}
			now->multiple = (now->multiple * calculate(_size - 1) % MOD) * max_num % MOD;
			father->multiple = father->multiple * now->multiple % MOD;
		}
		if (now->father != 1 && father->now_son_number == father->son_number) q.push(now->father);
	}
	Node* now = &node_list[1];
	int _size = now->node_list_size.size();
	sort(now->node_list_size.begin(), now->node_list_size.end());
	for (int i = 0; i < _size - 2; i++) now->cut += now->node_list_size[i];
	cout << now->cut << " ";
	long long res = now->multiple;
	res = res * calculate(_size - 1) % MOD;
	if (_size <= 2) {cout << res << endl; return;}
	int k = _size - 1;
	int max_num = 0;
	while (k >= 0) {
		if (now->node_list_size[k] == now->node_list_size[_size - 1]) max_num++;
			else break;
			k--;
	}
	if (max_num > 1) {
		res = ((res * max_num) % MOD) * (max_num - 1) % MOD;
	} else {
		int k = _size - 2;
		int max_num = 0;
		while (k >= 0) {
			if (now->node_list_size[k] == now->node_list_size[_size - 2]) max_num++;
				else break;
				k--;
		}
		res = res * max_num % MOD;
	}
	cout << res << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t-- > 0) {solve();}
}