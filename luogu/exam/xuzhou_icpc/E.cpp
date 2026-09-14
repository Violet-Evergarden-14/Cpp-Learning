#include <iostream>
#include <vector>
using namespace std;

int t, n, m;
int tag, l, r, k;
vector<int> numbers;

void case1() {
	for (int i = l; i <= r; i++) numbers[i] += k;
}

void case2() {
	for (int i = l; i <= r; i++) numbers[i] = k;
}

void case3() {
	int m_all = 0;
	int m_2;
	int cnt = 0;
	if (k < l) {
		for (int i = k; i < l; i++) m_all = max(m_all, numbers[i]);
		for (int i = l; i <= r; i++) {
			m_all = max(m_all, numbers[i]);
			m_2 = max(numbers[i], numbers[k]);
			if (m_all == m_2) cnt++;
		}
	} else if (k > r) {
		for (int i = k; i > r; i--) m_all = max(m_all, numbers[i]);
		for (int i = r; i >= l; i--) {
			m_all = max(m_all, numbers[i]);
			m_2 = max(numbers[i], numbers[k]);
			if (m_all == m_2) cnt++;
		}
	} else {
		cnt++;
		for (int i = k; i < k + 1; i++) m_all = max(m_all, numbers[i]);
		for (int i = k + 1; i <= r; i++) {
			m_all = max(m_all, numbers[i]);
			m_2 = max(numbers[i], numbers[k]);
			if (m_all == m_2) cnt++;
		}
		m_all = 0;
		for (int i = k; i > k - 1; i--) m_all = max(m_all, numbers[i]);
		for (int i = k - 1; i >= l; i--) {
			m_all = max(m_all, numbers[i]);
			m_2 = max(numbers[i], numbers[k]);
			if (m_all == m_2) cnt++;
		}
	}
	cout << cnt << endl;
}

void turn() {
	for (int i = 0; i < m; i++) {
		cin >> tag >> l >> r >> k;
		switch (tag) {
		case 1:
			case1();
			break;
		case 2:
			case2();
			break;
		case 3:
			case3();
			break;
		default:
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while (t-- > 0) {
		cin >> n >> m;
		numbers = vector<int>(n + 2, 0);
		for (int i = 0; i < n; i++) cin >> numbers[i + 1];
		turn();
	}
}