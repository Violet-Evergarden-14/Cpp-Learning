#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	int int_arr[] = {30, 90, 10, 40, 70, 50, 20, 80};
	const int N = 8;
	vector<int> a(int_arr, int_arr + N);

	cout << "Before sorting:\t";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	sort(a.begin(), a.end(), greater<int>());

	cout << "After sorting:\t";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
}