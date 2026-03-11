#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Integers
{
public:
	int left;
	int right;
	int number;

	friend bool operator>(const Integers& a, const Integers& b) {
		if (a.right < b.right) return true;
		if (a.right > b.right) return false;
		if (a.left < b.left) return true;
		return false;
	} 
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<Integers> list(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i].left >> list[i].right >> list[i].number;
	}
	sort(list.begin(), list.end(), greater<Integers>());
	int numbers[1001] = {0};

	for (int i = 0; i < n; i++) {
		int count = list[i].number;
		for (int j = list[i].left; j <= list[i].right; j++) {
			if (numbers[j] == 1) count--;
		}
		if (count <= 0) continue;
		for (int j = list[i].right; j >= list[i].left; j--) {
			if (numbers[j] == 0) {
				count--;
				numbers[j] = 1;
				if (count <= 0) break;
			}
		}
	}
	
	int count = 0;
	for (int i = 0; i <= 1000; i++)
	{
		if (numbers[i] == 1) count++;
	}
	cout << count << endl;
}
