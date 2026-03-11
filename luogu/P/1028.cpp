#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int list[501];
	list[1] = 1;
	for (int i = 2; i <= n / 2; i++) {
		int a = 1;
		for (int j = 1; j <= i / 2; j++) {
			a += list[j];
		}
		list[i] = a;
	}

	int result = 1;
	for (int j = 1; j <= n / 2; j++) {
		result += list[j];
	}
	cout << result;
}