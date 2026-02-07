#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<double> arr(5);
	double sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	cout << sum / arr.size();
}