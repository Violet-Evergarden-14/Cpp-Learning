#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prime;
const int MAX = 100000;

int find(int x, vector<int>& set) {
	if (x != set[x]) {
		set[x] = find(set[x], set);
	}
	return set[x];
}

void merge(int x, int y, vector<int>& set) {
	set[find(x, set)] = find(y, set);
}

void generate_primes(vector<int>& prime, int b) {
    const int MAX = b;
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= MAX; ++i) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int a, b, p;
	cin >> a >> b >> p;
	generate_primes(prime, b);
	vector<int> set(b + 1);
	for (int i = a; i <= b; i++) set[i] = i;
	vector<int>::iterator idx = lower_bound(prime.begin(), prime.end(), p);
	int pos = idx - prime.begin();
	while (prime[pos] <= b / 2) {
		int m = prime[pos];
		int i = ((a - 1) / m + 1) * m;
		while (i + m <= b) {
			merge(i, i + m, set);
			i += m;
		}
		pos++;
	}
	int count = 0;
	for (int i = a; i <= b; i++) {
		if (i == find(i, set)) count++;
	}
	cout << count;
}