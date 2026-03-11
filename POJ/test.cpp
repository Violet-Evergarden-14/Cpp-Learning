#include <iostream>
using namespace std;

int times(int m) {
	int result = 1;
	for (int i = 0; i < m; i++) result *= 10;
	return result;
}

int pos(int i, int k, int* list) {
	return i * k - list[i];
}

int main()
{
	int count = 0;
	int x = 0, y = 0;
	int list[6];
	list[1] = 0;
	cout << "0, 0, ";
	for (int i = 2; i <= 5; i++) {
		list[i] = i * (times(i - 1) - 1) - ((i - 1) * (times(i - 1) - 1) - list[i - 1]);
		cout << list[i] << ", ";
	}
	cout << endl;
	int abc[11];
	abc[1] = 45;
	cout << "45, ";
	for (int i = 2; i <= 4; i++) {
		abc[i] = abc[i - 1] + i * 9 * times(i - 1) * (11 * times(i - 1) - 1) / 2 - list[i] * 9 * times(i - 1);
		cout << abc[i] << ", ";
	}
}