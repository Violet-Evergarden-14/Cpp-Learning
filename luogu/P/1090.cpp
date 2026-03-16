#include <iostream>
#include <queue>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	long long n; 
	long long a, b, c;
	cin >> n;
	long long force = 0;
	vector<long long> ori;
	for (long long i = 0; i < n; i++) {
		long long a;
		cin >> a;
		ori.push_back(a);
	}
	priority_queue<long long, vector<long long>, greater<long long>> q(ori.begin(), ori.end());
	while (q.size() > 1) {
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		c = a + b;
		force += c;
		q.push(c);
	}
	cout << force;
}