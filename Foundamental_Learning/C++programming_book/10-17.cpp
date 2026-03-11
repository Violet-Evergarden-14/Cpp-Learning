#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace placeholders;

int main()
{
	int int_arr[] = {30, 90, 10, 40, 70, 50, 20, 80};
	const int N = sizeof(int_arr) / sizeof(int);
	vector<int> a(int_arr, int_arr + N);
	auto p = find_if(a.begin(), a.end(), bind(greater<>(), 20, _1));
	if (p == a.end()) {
		cout << "Not match!" << endl;
	} else {
		cout << "The first one is " << *p << endl;
	}
}